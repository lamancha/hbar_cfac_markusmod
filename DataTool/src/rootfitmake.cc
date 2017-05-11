#include "rootfitmake.hh"

int main (int argc, char * argv[])
{

  CommandLineInterpreter * myInterpreter = InitInterpreter(argc, argv);

  if(myInterpreter->readFlaglessCommands().size() != 3 || !myInterpreter->readFlaggedCommand("help").empty())
    {
      PrintHelp();
      return !myInterpreter->readFlaggedCommand("help").empty();
    }
  ProcessFile(myInterpreter);

  delete myInterpreter;
  return 0;
}

void ProcessFile(CommandLineInterpreter * myInterpreter)
{
  ///Initialize some variables from command line.
  int verbosityLevel = 0;
  if(myInterpreter->readFlaggedCommand("verbose").size()==1)
    verbosityLevel = atoi((myInterpreter->readFlaggedCommand("verbose").front()).c_str());

  string inFileName = (myInterpreter->readFlaglessCommands())[1];
  string outFileName = (myInterpreter->readFlaglessCommands())[2];

  string tiTreeName = !(myInterpreter->readFlaggedCommand("InputTTreeName")).empty()?
    (myInterpreter->readFlaggedCommand("InputTTreeName"))[0]:"T";

  string tiBranchName = !(myInterpreter->readFlaggedCommand("InputBranchName")).empty()?
    (myInterpreter->readFlaggedCommand("InputBranchName"))[0]:"SFACbranch";

  string toTreeName = !(myInterpreter->readFlaggedCommand("OutputTTreeName")).empty()?
    (myInterpreter->readFlaggedCommand("OutputTTreeName"))[0]:"T";

  string toBranchName = !(myInterpreter->readFlaggedCommand("OutputBranchName")).empty()?
    (myInterpreter->readFlaggedCommand("OutputBranchName"))[0]:"InterpolatorBranch";

  string toTreeTitle = !(myInterpreter->readFlaggedCommand("OutputTitle")).empty()?
    (myInterpreter->readFlaggedCommand("OutputTitle"))[0]:"InterpolatorBranchTitle";

  bool useProof = !(myInterpreter->readFlaggedCommand("PROOF")).empty()?
    ((myInterpreter->readFlaggedCommand("PROOF"))[0].compare("on")==0):false;

  bool useFieldGrid = !(myInterpreter->readFlaggedCommand("fieldGrid")).empty()?
    ((myInterpreter->readFlaggedCommand("fieldGrid"))[0].compare("on")==0):true;

  bool useGui = !(myInterpreter->readFlaggedCommand("GUI")).empty();

  unsigned int concurrentSelect = 1;
  if(!myInterpreter->readFlaggedCommand("concurrentSelect").empty())
      concurrentSelect = atoi(myInterpreter->readFlaggedCommand("concurrentSelect").front().c_str());
  if(concurrentSelect < 1)
    throw rfacException("Need to set concurrentSelect >= 1");


  VerbosePrinter * myPrinter = new VerbosePrinter(verbosityLevel);


  if(useGui)
    {
      new TApplication("myProg", 0, 0);
    }


  ///Open files and stuff.
  myPrinter->Print(10, "Opening files.\n");

  infile = new TFile(inFileName.c_str(), "READ");
  myPrinter->Print(10, "Input file has size %d Mb.\n",(int)(0.5+((float)infile->GetSize())/1024/1024));
  if(infile->IsZombie())
    throw rfacException("Failed to open the specified input file.");

  TFile * infile = new TFile(inFileName.c_str(), "READ");
  if(infile->IsZombie())
    rfacException("Failed to open the specified root file.");
  inTree = (TTree*) infile->Get(tiTreeName.c_str());
  myEssentialData = 0;

  inTree->SetBranchAddress(tiBranchName.c_str(), &myEssentialData);



  //infile->Close(); /// We just use infile to check if the file is there. No need for it any more, using TChain instead.


  TFile * outfile = new TFile(outFileName.c_str(), "RECREATE");
  if(outfile->IsZombie())
    throw rfacException("Failed to open the specified output file.");

  TChain * myTChain = new TChain(tiTreeName.c_str());
  myTChain->Add(inFileName.c_str());

  TProof * myProof = NULL;

  if(useProof)
    {
      TProof * myProof = TProof::Open("");//, "valgrind=workers");
      //myProof->SetLogLevel(verbosityLevel/1000);
      myProof->SetLogLevel(-1, TProofDebug::kNone);
      myProof->SetRealTimeLog(false);
      if(!useGui)
	{
	  myProof->SetProgressDialog(0);
	}
      myTChain->SetProof();
      char buffer[500];
      sprintf(buffer,"gSystem->Load(\"%s/Dictionary.so\")",
	      get_selfpath().erase(get_selfpath().size()-myInterpreter->readFlaglessCommands()[0].size()+1,myInterpreter->readFlaglessCommands()[0].size()).c_str());
      myProof->Exec(buffer);
    }


  myPrinter->Print(10, "Setting up important objects.\n");
  rfacQuantumNumberLister * myQuantumNumberLister = new rfacQuantumNumberLister();
  myQuantumNumberLister->SetInputList(new TList());
  myQuantumNumberLister->GetInputList()->Add(new TNamed("TreeBranchAddress",tiBranchName.c_str()));


  myPrinter->Print(10, "Processing input tree to obtain all occuring quantum numbers.\n");
  myTChain->Process(myQuantumNumberLister);


  rfacQuantumNumberContainer * myQMContainer = dynamic_cast<rfacQuantumNumberContainer *>(myQuantumNumberLister->GetOutputList()->FindObject("rfacQuantumNumberContainer"));
  if(myQMContainer == NULL)
    throw rfacException("Could not find QM container.");

  myPrinter->Print(8, "Found %d quantum numbers to loop over.\n", myQMContainer->size());

  if(useFieldGrid)
    {
      myPrinter->Print(10, "Obtaining field grid from input file.\n");

      rfacFieldGridPicker * myFieldGridPicker = new rfacFieldGridPicker();
      myFieldGridPicker->SetInputList(new TList());
      myFieldGridPicker->GetInputList()->SetOwner();
      myFieldGridPicker->GetInputList()->Add(new TNamed("TreeBranchAddress", tiBranchName.c_str()));
      myTChain->Process(myFieldGridPicker);
      rfacFieldGridContainer * myGridContainer = dynamic_cast<rfacFieldGridContainer *>(myFieldGridPicker->GetOutputList()->FindObject("rfacFieldGridContainer"));
      //set<rfacFieldGridPoint> * myGridPoints = dynamic_cast<set<rfacFieldGridPoint> *>(myFieldGridPicker->GetOutputList()->FindObject("rfacFieldGridContainer"));
      if(myGridContainer == NULL)
	throw rfacException("Could not find field grid container.");

      myPrinter->Print(8, "Found %d grid points.\n", myGridContainer->size());
      fieldGridSize = myGridContainer->size();

      if(myGridContainer->size() < 10)
	{
	  myPrinter->Print(1, "Warning: Suspiciously small number of field grid points (less than 10).\n");
	}


    for(rfacFieldGridContainer::iterator it = (*myGridContainer).begin(); it != (*myGridContainer).end(); ++it)
    { /*
        cout << "BField: " << it->B;
        cout << "EField: " << it->E;
        cout << "FieldAngle: " << it->Angle; */
    }


    rfac3DInterpolation::SetGridContainer(myGridContainer);

    }
  else
    {
      fieldGridSize = -1;
    }




  myPrinter->Print(10, "Creating output tree.\n");
  TTree * myOutputTree = new TTree(toTreeName.c_str(), toTreeTitle.c_str());

  rfacInterpolatorContainer* myContainer = new rfacInterpolatorContainer();

  myOutputTree->Branch(toBranchName.c_str(), myContainer, 64000, 0);

  myPrinter->Print(10, "Now looping over all sets of quantum numbers.\n");


  myOutputTree->SetAutoFlush(3);


  queue<set<QuantumNumbers> > inQueue;

  set<QuantumNumbers> input;
  for(set<QuantumNumbers>::iterator it = myQMContainer->begin(); it!= myQMContainer->end(); ++ it)
    {
      if(input.size() >= concurrentSelect)
	{
	  inQueue.push(input);
	  input.clear();
	}
      input.insert(*it);
    }
  if(input.size() > 0)
    {
      inQueue.push(input);
      input.clear();
    }

  myPrinter->Print(10, "Workers are launched.\n");

  unsigned int loopCount = 0;
  while(!inQueue.empty())
    {
      vector<rfacInterpolatorContainer *> containers = readObject(inQueue.front(), myPrinter);
      inQueue.pop();
      for(vector<rfacInterpolatorContainer*>::iterator it = containers.begin(); it!=containers.end(); ++it)
	  {
            ///---------------------------------------------------------------------------///
//        for(map<QuantumNumbers, rfac3DInterpolation>::iterator ip = (*it)->decayRates3D.begin(); ip!=(*it)->decayRates3D.end(); ++ip)
//        {
//          Double_t myE = 5500;//7000;
//          Double_t myB = 0.5;//2.5;
//          Double_t myA = 91;//190;
//
//          for(vector<Quadruple>::iterator iter = ip->second.CompleteData.begin(); iter!=ip->second.CompleteData.end(); ++iter)
//          {
//            cout << "EField:" << iter->GetEField() << "BField:" << iter->GetBField()
//            << "Angle:" << iter->GetFieldAngle() << "DecayRates:" << iter->GetDecayRate() << endl;
//          }
//
//        cout << "Predicted value="<<ip->second.Eval(myE, myB, myA) << endl;
//        }
//
//        cout << "-------------------------" << endl;
//        cin.ignore();

        ///----------------------------------------------------------------------------///
	    if((*it) != NULL)
        {
	      myPrinter->Print(10, "Now flushing quantum number < %s > (%d out of %d) to output file. Queue size: %d. \n", (*it)->key.ToString().c_str(), loopCount++, myQMContainer->size(), inQueue.size());
	      myOutputTree->SetBranchAddress(toBranchName.c_str(), &(*it));
	      myOutputTree->Fill();

	      delete (*it);
	    }
	    else
	    {
	      myPrinter->Print(1, "Warning: output from multitasker was null.\n");
	    }
      }
    }

  myPrinter->Print(10, "Done looping, cleaning up.\n");

  myOutputTree->Write("", TObject::kOverwrite);

  if(useProof && myProof)
    {
      myProof->Close();
      delete myProof;
    }

  delete myQuantumNumberLister;

  delete myPrinter;
  delete outfile;
  delete infile;

  if(useGui)
    gSystem->Exit(0);
}






vector<rfacInterpolatorContainer *> readObject(set<QuantumNumbers> toLocate, VerbosePrinter * toUse)
{/// Attention: this set<QuantumNumbers> only holds one QuantumNumber Object. toLocate.size()=1 (misleading)
  float Sum_EField = 0;
  map<QuantumNumbers, vector<rfacSpecificLevelData> > processResults;
  ///Now process the tree. Should ideally be done in a selector, but since ROOT is buggy I do it here instead.

  for(unsigned int i = 0; i<inTree->GetEntries(); ++i) ///For each (EField,BField,Angle)-Triple this is
       { ///executed one time. So for each Triple there is one tree.
      inTree->GetEntry(i);
    /// quantumnumber in Levels, which is the QN decay TO
    /// in my EssentialData->Levels.EnergyLevel we store the QN decay TO (Decay-Channel)
      for(set<QuantumNumbers>::const_iterator it = toLocate.begin(); it!=toLocate.end(); ++it) ///Only executed
	{ ///once per readObject call, as the toLocate is only a map with one entry
	  if(myEssentialData->Levels.find(*it)!=myEssentialData->Levels.end()) ///don't add a level which is not here.
	    {

	      processResults[*it].push_back(rfacSpecificLevelData(myEssentialData->Levels[*it],
								  myEssentialData->EField,
								  myEssentialData->BField,
								  myEssentialData->FieldAngle
								  ));
	    }

	    Sum_EField = Sum_EField + myEssentialData->EField; ///look if EField is activated,
	                                                       ///if yes -> activate 3DInterpolator in InterpolatorContainer

	    //cout << "BField: " << myEssentialData->BField << endl;
	    //cout << "VectorSize: " << processResults[*it].size() << endl;
        //unsigned short N =  it->GetN();
        //cout << "N: " << N << endl;
        //unsigned short L =  it->GetL();
        //cout << "L: " << L << endl;
        //unsigned short TwoJ =  it->GetTwoJ();
        //cout << "N: " << TwoJ << endl;
        //short TwoMJ =  it->GetTwoMJ();
        //cout << "TwoMJ: " << TwoMJ << endl;
	}
    }

  if(Sum_EField == 0) rfacInterpolatorContainer::SetFlag3D(false);
  else rfacInterpolatorContainer::SetFlag3D(true);

///iterate through all quantumnumbers (decay TO QN)
  vector<rfacInterpolatorContainer *> returnContainers;
  for(map<QuantumNumbers, vector<rfacSpecificLevelData> >::iterator it = processResults.begin(); it!=processResults.end(); ++it)
    {
      if(it->second.size() >= 4) //good
	{ ///first = QN, second = SpecificLevelData (EField, Bfield, Angle, QN to decay FROM, Energy)
	  returnContainers.push_back(new rfacInterpolatorContainer(it->first, it->second, fieldGridSize, toUse));
	}
      else //bad
	{

	}
    }

  return returnContainers;
}

string get_selfpath()
{
  char buff[1024];
  ssize_t len = ::readlink("/proc/self/exe", buff, sizeof(buff)-1);
  if (len != -1)
    {
      buff[len] = '\0';
      return std::string(buff);
    }
  throw rfacException("Could not find the program's execution path.");
}

CommandLineInterpreter * InitInterpreter(int argc, char * argv[])
{
  list<CommandLineArgument> myArguments;
  myArguments.push_back(CommandLineArgument("InputTTreeName",1));
  myArguments.push_back(CommandLineArgument("InputBranchName",1));
  myArguments.push_back(CommandLineArgument("OutputTTreeName",1));
  myArguments.push_back(CommandLineArgument("OutputBranchName",1));
  myArguments.push_back(CommandLineArgument("PROOF",1));
  myArguments.push_back(CommandLineArgument("GUI",0));
  myArguments.push_back(CommandLineArgument("fieldGrid",1));
  myArguments.push_back(CommandLineArgument("verbose",1));
  myArguments.push_back(CommandLineArgument("concurrentSelect",1));


  myArguments.push_back(CommandLineArgument("help",0));
  CommandLineInterpreter * myInterpreter = new CommandLineInterpreter(argc, argv, myArguments);

  return myInterpreter;
}


void PrintHelp()
{
  cerr << endl;
  cerr << "ROOTFITMAKE: Reads a root file with SFAC stuff and generates another root file with multidimensional interpolators." << endl;
  cerr << endl;
  cerr << "Synopsis: ./rootfitmake infile outfile [optional_args]" << endl;
  cerr << setiosflags(ios::left);
  cerr << endl;
  cerr << setw(40) << "Command description:" << endl;;
  cerr << endl;
  cerr << setw(40) << "The following arguments are MANDATORY:" << endl;

  cerr << setw(5) << " " << setw(40) << "infile" << "Name of the rootfile to read." << endl;
  cerr << setw(5) << " " << setw(40) << "outfile" << "Name of the rootfile to generate." << endl;

  cerr << endl;
  cerr << "The following arguments are OPTIONAL:" << endl;

  cerr << setw(5) << " " << setw(40) << "--InputTTreeName <ttree name>" << "Specifies internal name for TTree [Default: T]." << endl;
  cerr << setw(5) << " " << setw(40) << "--InputBranchName <branch name>" << "Specifies branch name for data storage [Default: SFACbranch]." << endl;
  cerr << setw(5) << " " << setw(40) << "--OutputTTreeName <ttree name>" << "Specifies internal name for TTree [Default: T]." << endl;
  cerr << setw(5) << " " << setw(40) << "--OutputBranchName <branch name>" << "Specifies branch name for data storage [Default: InterpolatorBranch]." << endl;
  cerr << setw(5) << " " << setw(40) << "--PROOF [on/off]" << "Specifies if PROOF should be used [Default: off]. Don't use this, PROOF is bad for you." << endl;
  cerr << setw(5) << " " << setw(40) << "--GUI" << "Specifies if PROOF should show a GUI. Only has effect if proof is on. So don't use this either." << endl;

  cerr << setw(5) << " " << setw(40) << "--verbose <verbose level>" << "Specifies how verbose the software should be [Default: 0]." << endl;
  cerr << setw(5) << " " << setw(40) << "--concurrentSelect <number>" << "Used to trade disk reads for RAM usage. Higher number -> more RAM usage and less disk usage. Number > 1. [Default: 1]." << endl;

  cerr << setw(5) << " " << setw(40) << "--fieldGrid [on/off]" << "Use to cross-check field grid size in each point. Disable to speed up init phase somewhat. [Default: on]." << endl;

  cerr << setw(5) << " " << setw(40) << "--help" << "Displays this message." << endl;

  cerr << endl;

  return;
}
