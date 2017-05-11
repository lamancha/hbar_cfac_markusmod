#include "rfacBinaryGenerator.hh"

const string rfacBinaryGenerator::AllOrbitals = "spdfghiklmnoqrtuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

rfacBinaryGenerator::rfacBinaryGenerator(unsigned int threads, bool _onlyAllowed)
{
  if(threads<1)
    throw rfacException("Invalid number of threads");
  onlyAllowed = _onlyAllowed;
  myMultiTasker = new MultiTasker<rfacBinaryGenerationParallellData *, void *>(&RunBinaryGenerationTask, threads);
  RegisterChild(myMultiTasker); /// If we might want to print some verbose stuff...
  myMultiTasker->LaunchThreads();
  shells=4; threads=10; levels=10; multipole=-1;
  minShells = 0; minLevels = 1;
  Initialize();
}

rfacBinaryGenerator::~rfacBinaryGenerator()
{
  myMultiTasker->DestroyThreads();
  delete myMultiTasker;
}

unsigned int rfacBinaryGenerator::GetWorkQueueSize()
{
  return myMultiTasker->GetInputSize();
}


void rfacBinaryGenerator::SetShells(int value)
{
  shells = value;
  Initialize();
}

void rfacBinaryGenerator::SetLevels(int value)
{
  levels = value;
  Initialize();
}

void rfacBinaryGenerator::SetMultipole(int value)
{
  multipole = value;
  Initialize();
}

void rfacBinaryGenerator::SetMinLevels(int value)
{
  minLevels = value;
  Initialize();
}

void rfacBinaryGenerator::SetMinShells(int value)
{
  minShells = value;
  Initialize();
}


void rfacBinaryGenerator::Initialize()
{
  E=B=ANGLE=0;
}

char rfacBinaryGenerator::Orbital(unsigned short l)
{
  if(l>=AllOrbitals.size())
    {
	char buffer[20];
	sprintf(buffer,"%d",l);
	string exc = "Invalid orbital: ";
	exc.append(buffer);
	throw rfacException(exc);
    }
  return AllOrbitals[l];
}

FILE * rfacBinaryGenerator::LaunchSfacProcess(int fromN, int fromL, int toN, int toL)
{
  if(fromL >= fromN || toL >= toN)
    throw rfacException("Cannot launch sfac process with strange parameters.");
  if(fromN < toN )
    throw rfacException("Will not calculate decay upwards, thank you very much.");
  if(fromN == toN && fromL == toL)
    throw rfacException("Will not calculate decay to myself, thanks.");
  
  FILE * sfacProcess = popen("sfac 2>&1 > /dev/null", "w");
  if(sfacProcess == NULL)
    throw rfacException("Could not start sfac process.");
  if(fprintf(sfacProcess,"SetAtom('H')\n")<0)
    throw rfacException("Error while writing to sfac process.");

  if(!(fromN == 1 || toN == 1))
    {
      if(fprintf(sfacProcess,"Config('%d%c','%d%clev')\n",1,Orbital(0),1,Orbital(0))<0)
	throw rfacException("Error while writing to sfac process.");
    }

  
  if(fprintf(sfacProcess,"Config('%d%c','%d%clev')\n",toN,Orbital(toL),toN,Orbital(toL))<0)
    throw rfacException("Error while writing to sfac process.");
  if(fprintf(sfacProcess,"Config('%d%c','%d%clev')\n",fromN,Orbital(fromL),fromN,Orbital(fromL))<0)
    throw rfacException("Error while writing to sfac process.");

 
  if(fprintf(sfacProcess,"ConfigEnergy(0)\n")< 0)
    throw rfacException("Error while writing to sfac process.");
  if(fprintf(sfacProcess,"OptimizeRadial(['1s'])\n") < 0)
    throw rfacException("Error while writing to sfac process.");
  if(fprintf(sfacProcess,"ConfigEnergy(1)\n")< 0)
    throw rfacException("Error while writing to sfac process.");

  return sfacProcess;
}

void rfacBinaryGenerator::CloseSfacProcess(FILE * toClose)
{
  if(pclose(toClose)==-1)
    throw rfacException("Could not close pipe properly.");
}

void rfacBinaryGenerator::SetFields(double e, double b, double angle)
{
  E=e;
  B=b; 
  ANGLE=angle;
}


bool rfacBinaryGenerator::IsFinished()
{
  return !(myMultiTasker->GetInputMinusOutput() > 0);
}



void rfacBinaryGenerator::DoGeneration(string dirPattern, string levelFilenamePattern, string levelEBFilenamePattern, string transitionFilenamePattern)
{
  vPrint(5,"Queueing up some work (level-file '%s').\n", levelFilenamePattern.c_str());

  long invocations = 0;
  for(int fromN = minLevels; fromN<=levels; ++fromN)
    {
      for(int fromL = minShells; fromL<shells && fromL < fromN; ++fromL)
	{
	  for(int toN = minLevels; toN<=fromN; ++toN)
	    {
	      for(int toL = minShells; toL < shells && toL < toN && !(toL>=fromL && toN == fromN); ++toL)
		{
		  if(!onlyAllowed || toL == fromL + 1 || toL == fromL - 1)
		    {
		      ++invocations;
		    }
		}
	    }
	}
    }


  vPrint(3,"Will invoke SFAC %ld times\n",invocations);

  for(int fromN = minLevels; fromN<=levels; ++fromN)
    {
      for(int fromL = minShells; fromL<shells && fromL < fromN; ++fromL)
	{
	  for(int toN = minLevels; toN<=fromN; ++toN)
	    {
	      for(int toL = minShells; toL < shells && toL < toN && !(toL>=fromL && toN == fromN); ++toL)
		{
		  if(!onlyAllowed || toL == fromL + 1 || toL == fromL - 1)
		    {
		      char dirName[400];
		      char levelFilename[400];
		      char levelEBFilename[400];
		      char transitionFilename[400];
		      sprintf(dirName, dirPattern.c_str(),fromN, Orbital(fromL), toN, Orbital(toL));
		      _mkdir(dirName);

		      sprintf(levelFilename,levelFilenamePattern.c_str(),fromN, Orbital(fromL), toN, Orbital(toL));
		      sprintf(levelEBFilename, levelEBFilenamePattern.c_str(),fromN, Orbital(fromL), toN, Orbital(toL));
		      sprintf(transitionFilename,transitionFilenamePattern.c_str(),fromN, Orbital(fromL), toN, Orbital(toL));
		      myMultiTasker->AddInput( new rfacBinaryGenerationParallellData 
					       (levelFilename, levelEBFilename, transitionFilename, 
						toN, toL, fromN, fromL, 
						E, B, ANGLE, 
						multipole
						));
		    }
		}
	    }
	}
    }
}


void * rfacBinaryGenerator::RunBinaryGenerationTask(rfacBinaryGenerationParallellData * myData)
{
  FILE * sfacProcess = LaunchSfacProcess(myData->fromN, myData->fromL, myData->toN, myData->toL);

  PrintFields(sfacProcess, myData->E, myData->B, myData->ANGLE);
  
  GenerateLevels(sfacProcess,myData->levelFilename, myData->levelEBFilename,myData->fromN, myData->fromL, myData->toN, myData->toL);
  
  GenerateTransitions(sfacProcess, myData->transitionFilename, myData->fromN, myData->fromL, myData->toN, myData->toL, myData->multipole);
  CloseSfacProcess(sfacProcess);

  return (void*)NULL;
}

void rfacBinaryGenerator::PrintFields(FILE * sfacProcess, double E, double B, double ANGLE)
{
  if(fprintf(sfacProcess,"SetFields(%6.6e,%6.6e,%6.6e)\n",B*TESLA_TO_GAUSS, E*VM_TO_VCM, ANGLE)<0)
    throw rfacException("Error while writing to sfac process (field setup).");
}

void rfacBinaryGenerator::GenerateLevels(FILE * sfacProcess, string filename, string EBfilename, int fromN, int fromL, int toN, int toL)
{
  if(fprintf(sfacProcess,"Structure('%s', ['%d%c', '%d%c'] )\n",
	     filename.c_str(),toN,Orbital(toL),fromN,Orbital(fromL))< 0)
  if(fprintf(sfacProcess,"Structure('%s', ['%d%c', '%d%c'] )\n",
	     filename.c_str(),toN,Orbital(toL),fromN,Orbital(fromL))< 0)
    throw rfacException("Could not generate levels properly.");
  if(fprintf(sfacProcess,"StructureEB('%s', ['%d%c', '%d%c'])\n",
	     EBfilename.c_str(),toN,Orbital(toL),fromN,Orbital(fromL))< 0)
    throw rfacException("Could not generate levels properly.");
}

void rfacBinaryGenerator::GenerateTransitions(FILE * sfacProcess, string filename, int fromN, int fromL, int toN, int toL, int multipole)
{
  if(fprintf(sfacProcess,"TRTableEB('%s', ['%d%c'], ['%d%c'], %d)\n",
	     filename.c_str(),toN, Orbital(toL),fromN, Orbital(fromL), multipole) < 0)
    throw rfacException("Error while writing to sfac process.");
}


void rfacBinaryGenerator::_mkdir(const char *dir) 
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
