#include "bingen.hh"

int main (int argc, char * argv[]) 
{
  CommandLineInterpreter * myInterpreter = InitInterpreter(argc, argv); 
  if(myInterpreter->readFlaglessCommands().size() != 1 || !myInterpreter->readFlaggedCommand("help").empty() ||
     myInterpreter->readFlaggedCommand("Bfield").size()!=1 || myInterpreter->readFlaggedCommand("Efield").size()!=1 || myInterpreter->readFlaggedCommand("Angle").size()!=1 || myInterpreter->readFlaggedCommand("directory").size()!=1)
    {
      PrintHelp();
      return !myInterpreter->readFlaggedCommand("help").empty();
    }

  int verbosityLevel = 0;
  if(myInterpreter->readFlaggedCommand("verbose").size()==1)
    verbosityLevel = atoi((myInterpreter->readFlaggedCommand("verbose").front()).c_str());

  unsigned int threads = 10;
  if(!myInterpreter->readFlaggedCommand("threads").empty())
      threads = atoi(myInterpreter->readFlaggedCommand("threads").front().c_str());

  bool onlyAllowed = !myInterpreter->readFlaggedCommand("OnlyAllowed").empty();

  VerbosePrinter * myVerbosePrinter = new VerbosePrinter(verbosityLevel);
  
  rfacBinaryGenerator * myGenerator = new rfacBinaryGenerator(threads, onlyAllowed);
  myGenerator->RegisterListener(myVerbosePrinter);

  double Ei, Bi, Ai;
  Ei = strtod(myInterpreter->readFlaggedCommand("Efield").front().c_str(),NULL);
  Bi = strtod(myInterpreter->readFlaggedCommand("Bfield").front().c_str(),NULL);
  Ai = strtod(myInterpreter->readFlaggedCommand("Angle").front().c_str(),NULL);
  //! \note: Unit conversion maybe needed! !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1

  double Ef = Ei, Bf = Bi, Af = Ai;
  double Es = 1, Bs = 1, As = 1;
  if(myInterpreter->readFlaggedCommand("EfieldFinal").size() != 0 ||
     myInterpreter->readFlaggedCommand("BfieldFinal").size() != 0 ||
     myInterpreter->readFlaggedCommand("AngleFinal").size() != 0 ||
     myInterpreter->readFlaggedCommand("EfieldStep").size() != 0 ||
     myInterpreter->readFlaggedCommand("BfieldStep").size() != 0 ||
     myInterpreter->readFlaggedCommand("AngleStep").size() != 0)
    {
      if(myInterpreter->readFlaggedCommand("EfieldFinal").size() != 0 &&
	 myInterpreter->readFlaggedCommand("BfieldFinal").size() != 0 &&
	 myInterpreter->readFlaggedCommand("AngleFinal").size() != 0 &&
	 myInterpreter->readFlaggedCommand("EfieldStep").size() != 0 &&
	 myInterpreter->readFlaggedCommand("BfieldStep").size() != 0 &&
	 myInterpreter->readFlaggedCommand("AngleStep").size() != 0)
	 {
	   Ef = strtod(myInterpreter->readFlaggedCommand("EfieldFinal").front().c_str(),NULL);
	   Bf = strtod(myInterpreter->readFlaggedCommand("BfieldFinal").front().c_str(),NULL);
	   Af = strtod(myInterpreter->readFlaggedCommand("AngleFinal").front().c_str(),NULL);
	   Es = strtod(myInterpreter->readFlaggedCommand("EfieldStep").front().c_str(),NULL);
	   Bs = strtod(myInterpreter->readFlaggedCommand("BfieldStep").front().c_str(),NULL);
	   As = strtod(myInterpreter->readFlaggedCommand("AngleStep").front().c_str(),NULL);
	   if( Es <= 0 || As <= 0 || Bs <= 0)
	     {
	       cerr << "Step size must be greater than zero." << endl;
	       return 2;
	     }

	 } 
      else
	{
	  cerr << "All the final fields and step sizes need to be specified for this to be used. Exiting." << endl;
	  return 1;
	}
    }
  
  if(!myInterpreter->readFlaggedCommand("shells").empty())
    {
      myGenerator->SetShells(atoi(myInterpreter->readFlaggedCommand("shells").front().c_str()));
    }
  if(!myInterpreter->readFlaggedCommand("levels").empty())
    {
      myGenerator->SetLevels(atoi(myInterpreter->readFlaggedCommand("levels").front().c_str()));
    }
  if(!myInterpreter->readFlaggedCommand("multipole").empty())
    {
      myGenerator->SetMultipole(atoi(myInterpreter->readFlaggedCommand("multipole").front().c_str()));
    }


  if(!myInterpreter->readFlaggedCommand("MinShells").empty())
    {
      myGenerator->SetMinShells(atoi(myInterpreter->readFlaggedCommand("MinShells").front().c_str()));
    }
  if(!myInterpreter->readFlaggedCommand("MinLevels").empty())
    {
      myGenerator->SetMinLevels(atoi(myInterpreter->readFlaggedCommand("MinLevels").front().c_str()));
    }

  if(!myInterpreter->readFlaggedCommand("rmdir").empty())
    {
      myVerbosePrinter->Print(10,"Removing previous output directory.\n");
      rmrf(myInterpreter->readFlaggedCommand("directory").front().c_str());
    }

  unsigned long loops = 0;
  for(double A = Ai; A<=Af; A+=As)
      for(double B = Bi; B<=Bf; B+=Bs)
	  for(double E = Ei; E<=Ef; E+=Es)
	    ++loops;

  myVerbosePrinter->Print(1,"Will generate %ld data points.\n", loops);
  unsigned long loopcount = 0;
  for(double A = Ai; A<=Af; A+=As)
    {
      for(double B = Bi; B<=Bf; B+=Bs)
	{
	  for(double E = Ei; E<=Ef; E+=Es)
	    {
	      myVerbosePrinter->Print(2, "Now queueing E=%.10e, B=%.10e, A=%.10e for generation (%3.2f %% done).\n",E,B,A, 100*(float)loopcount++/((float)loops));
	      myGenerator->SetFields(E,B,A);
	      
	      string levelFile = myInterpreter->readFlaggedCommand("directory").front();
	      

	      char buffer[100];
	      sprintf(buffer,"/E%.10eB%.10eA%.10e/",E,B,A);
	      levelFile.append(buffer);
	      _mkdir(levelFile.c_str());

	      string transitionPattern = levelFile;
	      string levelEBFile = levelFile;
	      string subDirectory = levelFile;

	      subDirectory.append("%d%c-to-%d%c");
	      levelFile.append("%d%c-to-%d%c/lvl.b");
	      levelEBFile.append("%d%c-to-%d%c/lvlEB.b");
	      transitionPattern.append("%d%c-to-%d%c/trans.b");

	      myGenerator->DoGeneration(subDirectory, levelFile, levelEBFile, transitionPattern);
	      
	      bool message = false;
	      while(myGenerator->GetWorkQueueSize()>10*threads)
		{
		  if(!message)
		    {
		      myVerbosePrinter->Print(8, "Suspending thread work queuing.\n");
		      message=true;
		    }

		  int retries = 0; //apparently usleep can fail, it seems.
		  while(usleep(10000)!=0 && retries++<3); 
		  if(retries>=3)
		    throw rfacException("Failed to suspend thread.");
		}
	      if(message)
		{
		  myVerbosePrinter->Print(8, "Adding some more thread work.\n");
		}
	    }
	}
    }
  myVerbosePrinter->Print(3, "No more work to queue up, waiting for workers to finish.\n");
  while(!myGenerator->IsFinished())
    usleep(10000);
  myVerbosePrinter->Print(2, "Finished, terminating.\n");

  delete myGenerator; 
  delete myVerbosePrinter;
  delete myInterpreter;

  return 0;
}

CommandLineInterpreter * InitInterpreter(int argc, char * argv[])
{
  list<CommandLineArgument> myArguments;
  myArguments.push_back(CommandLineArgument("Bfield",1));
  myArguments.push_back(CommandLineArgument("Efield",1));
  myArguments.push_back(CommandLineArgument("Angle",1));
  myArguments.push_back(CommandLineArgument("directory",1));

  myArguments.push_back(CommandLineArgument("EfieldFinal",1));
  myArguments.push_back(CommandLineArgument("BfieldFinal",1));
  myArguments.push_back(CommandLineArgument("AngleFinal",1));
  myArguments.push_back(CommandLineArgument("EfieldStep",1));
  myArguments.push_back(CommandLineArgument("BfieldStep",1));
  myArguments.push_back(CommandLineArgument("AngleStep",1));

  myArguments.push_back(CommandLineArgument("threads",1));
  myArguments.push_back(CommandLineArgument("rmdir",0));

  myArguments.push_back(CommandLineArgument("shells",1));
  myArguments.push_back(CommandLineArgument("levels",1));
  myArguments.push_back(CommandLineArgument("multipole",1));

  myArguments.push_back(CommandLineArgument("MinShells",1));
  myArguments.push_back(CommandLineArgument("MinLevels",1));

  myArguments.push_back(CommandLineArgument("OnlyAllowed",0));
  
  myArguments.push_back(CommandLineArgument("help",0));
  myArguments.push_back(CommandLineArgument("verbose",1));
  CommandLineInterpreter * myInterpreter = new CommandLineInterpreter(argc, argv, myArguments);

  return myInterpreter;
}

void PrintHelp()
{
  cerr << endl;
  cerr << "BINGEN: Generates SFAC binary output according to specifications." << endl;
  cerr << endl;
  cerr << "Synopsis: ./bingen mandatory_args [optional_args]" << endl;
  cerr << setiosflags(ios::left);
  cerr << endl;
  cerr << setw(40) << "Command description:" << endl;
  cerr << endl;
  cerr << setw(40) << "The following arguments are MANDATORY:" << endl;

  cerr << setw(5) << " " << setw(40) << "--directory <Name of directory>" << "Name of directory to print output and sub-directories to." << endl;
  cerr << setw(5) << " " << setw(40) << "--Bfield <strength>" << "Magnetic field strength in Tesla." << endl;
  cerr << setw(5) << " " << setw(40) << "--Efield <strength>" << "Electric field strength in V/m." << endl;
  cerr << setw(5) << " " << setw(40) << "--Angle <angle>" << "Angle between E field and B field in degrees." << endl;

  cerr << endl;

  cerr << setw(40) << "If any of the following is specified, ALL of them needs to be specified:" << endl;
  cerr << setw(5) << " " << setw(40) << "--BfieldFinal <strength>" << "Final magnetic field strength in Tesla." << endl;
  cerr << setw(5) << " " << setw(40) << "--EfieldFinal <strength>" << "Final electric field strength in V/m." << endl;
  cerr << setw(5) << " " << setw(40) << "--AngleFinal <angle>" << "Final angle between E field and B field in degrees." << endl;
  cerr << setw(5) << " " << setw(40) << "--BfieldStep <strength>" << "Magnetic field step size in Tesla." << endl;
  cerr << setw(5) << " " << setw(40) << "--EfieldStep <strength>" << "Electric field step size in V/m." << endl;
  cerr << setw(5) << " " << setw(40) << "--AngleStep <angle>" << "Angle step size in degrees." << endl;
  cerr << endl;



  cerr << "The following arguments are OPTIONAL:" << endl;

  cerr << setw(5) << " " << setw(40) << "--shells <shell number>" << "The maximum quantum number l to take into account." << endl;
  cerr << setw(5) << " " << setw(40) << "--levels <number of levels>" << "Maximum principal quantum number to take into account [default: 10]." << endl;

  cerr << setw(5) << " " << setw(40) << "--MinShells <shell number>" << "Minimum shell number [default: 0]." << endl;
  cerr << setw(5) << " " << setw(40) << "--MinLevels <level number>" << "Minimum level number [default: 1]." << endl;

  cerr << setw(5) << " " << setw(40) << "--OnlyAllowed" << "Only calculated allowed transitions (l=+-1). Will speed up computations greatly." << endl;

  cerr << setw(5) << " " << setw(40) << "--multipole <multipole number>" << "Value of multipole for transition type [default: -1]." << endl;



  cerr << setw(5) << " " << setw(40) << "--threads <number of threads>" << "Number of threads to use for processing [default: 10]." << endl;
  cerr << setw(5) << " " << setw(40) << "--rmdir" << "Specify this flag to remove any existing content in output directory. Use with caution." << endl;
  cerr << setw(5) << " " << setw(40) << "--verbose <int>" << "Specify the verbosity level for the generating process [default: 0]." << endl;
  cerr << setw(5) << " " << setw(40) << "--help" << "Displays this message." << endl;

  

  cerr << endl << endl;
  return;
}


int unlink_cb(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
{
  int rv = remove(fpath);
  
  if (rv)
    perror(fpath);
  
  return rv;
}

int rmrf(const char *path)
{
  return nftw(path, unlink_cb, 64, FTW_DEPTH | FTW_PHYS);
}

static void _mkdir(const char *dir) 
{
  char tmp[256];
  char *p = NULL;
  size_t len;
  
  snprintf(tmp, sizeof(tmp),"%s",dir);
  len = strlen(tmp);
  if(tmp[len - 1] == '/')
    tmp[len - 1] = 0;
  for(p = tmp + 1; *p; p++)
    if(*p == '/') {
      *p = 0;
      mkdir(tmp, S_IRWXU);
      *p = '/';
    }
  mkdir(tmp, S_IRWXU);
}
