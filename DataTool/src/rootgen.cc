#include "rootgen.hh"

int main (int argc, char * argv[]) 
{
  CommandLineInterpreter * myInterpreter = InitInterpreter(argc, argv); 
  if(myInterpreter->readFlaglessCommands().size() != 3 || !myInterpreter->readFlaggedCommand("help").empty())
    {
      PrintHelp();
      return !myInterpreter->readFlaggedCommand("help").empty();
    }
  
  DoProcessing(myInterpreter);

  delete myInterpreter;
  
  return 0;
}

CommandLineInterpreter * InitInterpreter(int argc, char * argv[])
{
  list<CommandLineArgument> myArguments;
  myArguments.push_back(CommandLineArgument("RootFileName",1));
  myArguments.push_back(CommandLineArgument("TTreeName",1));
  myArguments.push_back(CommandLineArgument("TTreeTitle",1));
  myArguments.push_back(CommandLineArgument("BranchName",1));
  myArguments.push_back(CommandLineArgument("DecayCut",1));
  myArguments.push_back(CommandLineArgument("verbose",1));
  myArguments.push_back(CommandLineArgument("threads",1));
  myArguments.push_back(CommandLineArgument("help",0));
  CommandLineInterpreter * myInterpreter = new CommandLineInterpreter(argc, argv, myArguments);

  return myInterpreter;
}

void PrintHelp()
{
  cerr << endl;
  cerr << "ROOTGEN: Generates rootfiles from binary SFAC output." << endl;
  cerr << endl;
  cerr << "Synopsis: ./rootgen arg1 arg2 [optional_args]" << endl;
  cerr << setiosflags(ios::left);
  cerr << endl;
  cerr << setw(40) << "Command description:" << endl;;
  cerr << endl;
  cerr << setw(40) << "The following arguments are MANDATORY:" << endl;

  cerr << setw(5) << " " << setw(40) << "arg1" << "Name of directory of directories binary files to read." << endl;
  cerr << setw(5) << " " << setw(40) << "arg2" << "Name of root file in file system to write results to.Magnetic field strength in Tesla." << endl;

  cerr << endl;
  cerr << "The following arguments are OPTIONAL:" << endl;

  cerr << setw(5) << " " << setw(40) << "--RootFileName <rootfile name>" << "Specifies internal name for root file [Default: Rootfile]." << endl;
  cerr << setw(5) << " " << setw(40) << "--TTreeName <ttree name>" << "Specifies internal name for TTree [Default: T]." << endl;
  cerr << setw(5) << " " << setw(40) << "--TTreeTitle <ttree title>" << "Specifies internal title for TTree [Default: SFACdata]." << endl;
  cerr << setw(5) << " " << setw(40) << "--BranchName <branch name>" << "Specifies branch name for data storage [Default: SFACbranch]." << endl;
  cerr << setw(5) << " " << setw(40) << "--DecayCut <branch name>" << "Specifies the minimum Einstein coefficient before a branch is ignored [Default: 1E-300]." << endl;
  cerr << setw(5) << " " << setw(40) << "--verbose <verbose level>" << "Specifies how verbose the output to stdout should be [Default: 0]." << endl;
  cerr << setw(5) << " " << setw(40) << "--threads <number of threads>" << "Specifies how many worker threads to use [Default: 10]." << endl;
  cerr << setw(5) << " " << setw(40) << "--help" << "Displays this message." << endl;

  cerr << endl << endl;

  return;
}


void DoProcessing(CommandLineInterpreter * myInterpreter)
{
  string fileName = (myInterpreter->readFlaglessCommands())[2];

  string rootFileName = !(myInterpreter->readFlaggedCommand("RootFileName")).empty()?
    (myInterpreter->readFlaggedCommand("RootFileName"))[0]:"Rootfile";

  string tTreeName = !(myInterpreter->readFlaggedCommand("TTreeName")).empty()?
    (myInterpreter->readFlaggedCommand("TTreeName"))[0]:"T";

  string tTreeTitle = !(myInterpreter->readFlaggedCommand("TTreeTitle")).empty()?
    (myInterpreter->readFlaggedCommand("TTreeTitle"))[0]:"SFACdata";

  string tBranchName = !(myInterpreter->readFlaggedCommand("BranchName")).empty()?
    (myInterpreter->readFlaggedCommand("BranchName"))[0]:"SFACbranch";

  int verbosityLevel = 0;
  if(myInterpreter->readFlaggedCommand("verbose").size()==1)
    verbosityLevel = atoi((myInterpreter->readFlaggedCommand("verbose").front()).c_str());

  unsigned int threads = 10;
  if(!myInterpreter->readFlaggedCommand("threads").empty())
    {
      threads = atoi(myInterpreter->readFlaggedCommand("threads").front().c_str());
    }

  Double_t DecayCut = 1E-300;
  if(!myInterpreter->readFlaggedCommand("DecayCut").empty())
    {
      DecayCut = atof(myInterpreter->readFlaggedCommand("DecayCut").front().c_str());
    }



  VerbosePrinter * myPrinter = new VerbosePrinter(verbosityLevel);

  TFile * myRootFile = new TFile(fileName.c_str(), "RECREATE", rootFileName.c_str());

  if(myRootFile->IsZombie())
    rfacException("Failed to open the specified root file.");

  TTree * myTTree = new TTree(tTreeName.c_str(), tTreeTitle.c_str());

  rfacEssentialData * myData = new rfacEssentialData();

  myTTree->Branch(tBranchName.c_str(), myData, 64000, 0);

  myTTree->SetAutoFlush(3);

  rfacEssentialDataReader * myDataReader = new rfacEssentialDataReader( (myInterpreter->readFlaglessCommands())[1], 
									myPrinter, 
									threads
									);

  myDataReader->RegisterListener(myPrinter);

  myDataReader->SetDecayCut(DecayCut);

  myPrinter->Print(5, "Total number of entries: %d\n", myDataReader->GetTotalCount());


  int ptr = 0;
  while(myDataReader->HasNext())
    {
      myPrinter->Print(6, "Processing entry %5d, %5.2f %% done, %5d objects in queue.\n", ptr, 100*(float)(ptr)/(float)myDataReader->GetTotalCount(), myDataReader->GetOutputQueueSize());
      ++ptr;
      rfacEssentialData * tempData = myDataReader->GetNext();
      if(tempData==NULL) //Only happens in lenient mode in some exceptional cases.
	continue;
      myTTree->SetBranchAddress(tBranchName.c_str(), &tempData); //Instead of set, maybe this is faster?
      //myData->Set(*tempData);
      myTTree->Fill();
      delete tempData;
    }


  myTTree->Write("", TObject::kOverwrite);

  /// Also save the decay cut, in case someone would like to know later on which setting was used.
  TTree * myDecayTree = new TTree("DecayCutUsed", "The decay cut used.");
  myDecayTree->Branch("DecayCut", &DecayCut, "Value/F");
  myDecayTree->Fill();
  myDecayTree->Write("", TObject::kOverwrite);

  


  delete myData;
  delete myDataReader;
  delete myPrinter;
  myRootFile->Close();

  //  delete myTTree;

  delete myRootFile;
  

}
