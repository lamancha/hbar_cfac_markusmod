#include "rfacFieldGridPicker.hh"

ClassImp(rfacFieldGridPicker)

rfacFieldGridPicker::rfacFieldGridPicker(TTree * myTree)
{
  dataBranch = NULL;
  returnValues = NULL;
  myBranchName = "SFACbranch";
}

rfacFieldGridPicker::~rfacFieldGridPicker()
{

}

void rfacFieldGridPicker::Init(TTree *tree)
{
  myEssentialData = new rfacEssentialData();
  if(GetInputList()->FindObject("TreeBranchAddress"))
    {
      myBranchName = GetInputList()->FindObject("TreeBranchAddress")->GetTitle();
    }
  tree->SetBranchAddress(myBranchName, &myEssentialData, &dataBranch);
}

void rfacFieldGridPicker::SlaveBegin(TTree *tree)
{
  returnValues = new rfacFieldGridContainer();
}

Bool_t rfacFieldGridPicker::Process(Long64_t entry)
{
  dataBranch->GetEntry(entry);
  returnValues->insert(rfacFieldGridPoint(myEssentialData->EField,
					      myEssentialData->BField,
					      myEssentialData->FieldAngle
					      ));
  return kTRUE;
}

void rfacFieldGridPicker::SlaveTerminate()
{
  fOutput->Add(returnValues);
}

void rfacFieldGridPicker::Terminate()
{

}
