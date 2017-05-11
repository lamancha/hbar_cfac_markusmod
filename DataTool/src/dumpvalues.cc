#include "dumpvalues.hh"

int main(int argc, char * argv[]) 
{
  CommandLineInterpreter * myInterpreter = InitInterpreter(argc, argv); 
  if(myInterpreter->readFlaglessCommands().size() != 3 || !myInterpreter->readFlaggedCommand("help").empty())
    {
      PrintHelp();
      return !myInterpreter->readFlaggedCommand("help").empty();
    }

  TString TTreeName = !(myInterpreter->readFlaggedCommand("TTreeName")).empty()?
    (myInterpreter->readFlaggedCommand("TTreeName"))[0]:"T";

  TString TBranchName = !(myInterpreter->readFlaggedCommand("BranchName")).empty()?
    (myInterpreter->readFlaggedCommand("BranchName"))[0]:"InterpolatorBranch";

  TString infile =   (myInterpreter->readFlaglessCommands())[1];
  string outfile = (myInterpreter->readFlaglessCommands())[2];

  int verbosityLevel = 0;
  if(myInterpreter->readFlaggedCommand("verbose").size()==1)
    verbosityLevel = atoi((myInterpreter->readFlaggedCommand("verbose").front()).c_str());

  int querySize = 1;
  if(myInterpreter->readFlaggedCommand("querySize").size()==1)
    querySize = atoi((myInterpreter->readFlaggedCommand("querySize").front()).c_str());

  VerbosePrinter * myPrinter = new VerbosePrinter(verbosityLevel);


  string table = !(myInterpreter->readFlaggedCommand("table")).empty()?
    (myInterpreter->readFlaggedCommand("DB"))[0]:"decayrates";

  FILE * fout = fopen(outfile.c_str(), "w");

  TFile * myTFile = new TFile(infile);

  if(myTFile->IsZombie())
    {
      cout << "File is zombie. Terminating." << endl;
      return 1;
    }
  TTree * T = (TTree*)myTFile->Get(TTreeName);
  rfacInterpolatorContainer * myContainer = 0;
  T->SetBranchAddress(TBranchName, &myContainer);
  
  if(T->GetEntries() < 1)
    {
      throw rfacException("Error: tree has no entries.");
    }

  myPrinter->Print(2,"Determining maximum number of data points in an interpolator...");
  unsigned int nPointsMax = 0;
  for(int i = 0; i<T->GetEntries(); ++i)
    {
      T->GetEntry(i);
      for(map<QuantumNumbers, rfacLinearInterpolation>::const_iterator it = myContainer->decayRates.begin(); it!=myContainer->decayRates.end(); ++it)
	{
	  if(it->second.GetDataPoints().size() > nPointsMax)
	    {
	      nPointsMax = it->second.GetDataPoints().size();
	    }
	}
    }
  myPrinter->Print(2, "%d\n",nPointsMax);
  myPrinter->Print(2, "Generating table creation query.\n");
  fprintf(fout, "CREATE TABLE IF NOT EXISTS %s ", table.c_str());
  fprintf(fout, "(id INT(8) NOT NULL AUTO_INCREMENT, ");
  fprintf(fout, "upperN TINYINT UNSIGNED NOT NULL, ");
  fprintf(fout, "upperL TINYINT UNSIGNED NOT NULL, ");
  fprintf(fout, "upperJ TINYINT UNSIGNED NOT NULL, ");
  fprintf(fout, "upperMJ TINYINT SIGNED NOT NULL, ");
  fprintf(fout, "lowerN TINYINT UNSIGNED NOT NULL, ");
  fprintf(fout, "lowerL TINYINT UNSIGNED NOT NULL, ");
  fprintf(fout, "lowerJ TINYINT UNSIGNED NOT NULL, ");
  fprintf(fout, "lowerMJ TINYINT SIGNED NOT NULL, ");
  for(unsigned int i = 0; i<nPointsMax; ++i)
    {
      fprintf(fout, "x%d DOUBLE, y%d DOUBLE, " ,i, i);
    }
  fprintf(fout, "PRIMARY KEY (id), UNIQUE id (id), KEY id_2 (id) );\n");


  myPrinter->Print(2, "Now generating the data insertion queries.");
	  
  long long flushCount = 0;
  for(int i = 0; i<T->GetEntries(); ++i)
    {
      T->GetEntry(i);
      myPrinter->Print(2, "Now processing quantum number %d out of %d.\n",i,T->GetEntries());
      for(map<QuantumNumbers, rfacLinearInterpolation>::const_iterator it = myContainer->decayRates.begin(); it!=myContainer->decayRates.end(); ++it)
	{
	  if(flushCount%querySize == 0)
	    {
	      fprintf(fout, "INSERT INTO %s VALUES ",table.c_str());
	    }
	  else
	    {
	      fprintf(fout, ", ");
	    }
	  fprintf(fout, 
		  "(null, %d, %d, %d, %d, %d, %d, %d, %d",
		  myContainer->key.GetN(),
		  myContainer->key.GetL(),
		  myContainer->key.GetTwoJ(),
		  myContainer->key.GetTwoMJ(),
		  it->first.GetN(),
		  it->first.GetL(),
		  it->first.GetTwoJ(),
		  it->first.GetTwoMJ()
		  );
	  vector<pair<Double_t, Double_t> > points = it->second.GetDataPoints();
	  for(unsigned int j = 0; j<nPointsMax; ++j)
	    {
	      if(j>=points.size())
			{
			  fprintf(fout, ", null, null");
			}
	      else
			{
			  fprintf(fout, ", %13.8E, %13.8E",points[j].first, points[j].second);
			}
	    }
	  fprintf(fout, ")");
	  if((flushCount+1)%querySize==0)
	    {
	      fprintf(fout,";\n");
	    }
	  ++flushCount;
	}
    }
  if(flushCount%querySize != 0)
    {
      fprintf(fout, ";\n");
    }
  myPrinter->Print(2,"Done, closing files.\n");
  delete myTFile;
  fclose(fout);
  delete myPrinter;
  delete myInterpreter;
  return 0;
}



CommandLineInterpreter * InitInterpreter(int argc, char * argv[])
{
  list<CommandLineArgument> myArguments;
  myArguments.push_back(CommandLineArgument("TTreeName",1));
  myArguments.push_back(CommandLineArgument("TBranchName",1));

  myArguments.push_back(CommandLineArgument("DB",1));

  myArguments.push_back(CommandLineArgument("querySize",1));

  myArguments.push_back(CommandLineArgument("help",0));
  myArguments.push_back(CommandLineArgument("verbose",1));
  CommandLineInterpreter * myInterpreter = new CommandLineInterpreter(argc, argv, myArguments);

  return myInterpreter;
}


void PrintHelp()
{
  cerr << endl;
  cerr << "DUMPVALUES: Dump values from a root tree into SQL INSERT statements." << endl;
  cerr << endl;
  cerr << "Synopsis: ./dumpvalues infile outfile [optional_args]" << endl;
  cerr << setiosflags(ios::left);
  cerr << endl;
  cerr << setw(40) << "Command description:" << endl;
  cerr << endl;
  cerr << setw(40) << "The following arguments are MANDATORY:" << endl;

  cerr << setw(5) << " " << setw(40) << "infile" << "Input file (in root format)." << endl;
  cerr << setw(5) << " " << setw(40) << "outfile" << "Output file (in text format)." << endl;

  cerr << "The following arguments are OPTIONAL:" << endl;

  cerr << setw(5) << " " << setw(40) << "--TTreeName <name>" << "Name of TTree in the input file [default:T]." << endl;
  cerr << setw(5) << " " << setw(40) << "--TBranchName <name>" << "Name of TBranch in the input file [default:InterpolatorBranch]." << endl;
  cerr << setw(5) << " " << setw(40) << "--table <name>" << "Name of SQL table for y values [default:decayrates]." << endl;
  cerr << setw(5) << " " << setw(40) << "--querySize <int>" << "Number of posts to insert in each query [default:1]." << endl;
  cerr << setw(5) << " " << setw(40) << "--verbose <int>" << "Specify the verbosity level for the generating process [default: 0]." << endl;
  cerr << setw(5) << " " << setw(40) << "--help" << "Displays this message." << endl;


  cerr << endl << endl;
  return;
}
