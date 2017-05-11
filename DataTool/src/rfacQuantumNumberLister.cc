#include "rfacQuantumNumberLister.hh"

rfacQuantumNumberLister::rfacQuantumNumberLister(TTree * myTree)
{
  returnValues = NULL;
  dataBranch = NULL;
  myBranchName = "SFACbranch";
}
rfacQuantumNumberLister::~rfacQuantumNumberLister()
{

}

void rfacQuantumNumberLister::Init(TTree *tree)
{
  myEssentialData = new rfacEssentialData();

  if(GetInputList()->FindObject("TreeBranchAddress"))
    {
      myBranchName = GetInputList()->FindObject("TreeBranchAddress")->GetTitle();
    }

  tree->SetBranchAddress(myBranchName, &myEssentialData, &dataBranch);
}

void rfacQuantumNumberLister::SlaveBegin(TTree *tree)
{
  returnValues = new rfacQuantumNumberContainer();
}

Bool_t rfacQuantumNumberLister::Process(Long64_t entry)
{
  dataBranch->GetEntry(entry);
  
  for(map<QuantumNumbers, EnergyLevel>::iterator it = myEssentialData->Levels.begin(); it!=myEssentialData->Levels.end(); ++it)
    {
      returnValues->insert(it->first);
    }
   return kTRUE;
}


void rfacQuantumNumberLister::SlaveTerminate()
{
  fOutput->Add(returnValues);
}

void rfacQuantumNumberLister::Terminate()
{

}
