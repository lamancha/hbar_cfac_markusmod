#include "rfacLevelPicker.hh"

ClassImp(rfacLevelPicker)

rfacLevelPicker::rfacLevelPicker(TTree * myTree)
{
  dataBranch = NULL;
  returnValues = NULL;
  myBranchName = "SFACbranch";
}

rfacLevelPicker::~rfacLevelPicker()
{

}

void rfacLevelPicker::Init(TTree *tree)
{
  myEssentialData = new rfacEssentialData();
  if(GetInputList()->FindObject("TreeBranchAddress"))
    {
      myBranchName = GetInputList()->FindObject("TreeBranchAddress")->GetTitle();
    }
  if((target = dynamic_cast<QuantumNumbers *>(GetInputList()->FindObject("QuantumNumbers"))))
    {
      
    }
  else
    {
      throw rfacException("Could not retrieve TARGET object for the next quantum number.");
    }
  tree->SetBranchAddress(myBranchName, &myEssentialData, &dataBranch);
}

void rfacLevelPicker::SlaveBegin(TTree *tree)
{
  returnValues = new rfacLevelContainer();
}

Bool_t rfacLevelPicker::Process(Long64_t entry)
{
  dataBranch->GetEntry(entry);

  if(target == NULL)
    throw rfacException("TARGET was NULL, this should never happen here.");

  if(myEssentialData->Levels.find(*target)!=myEssentialData->Levels.end()) ///don't add a level which is not here.
    {

      returnValues->push_back(rfacSpecificLevelData(myEssentialData->Levels[*target], 
						    myEssentialData->EField,
						    myEssentialData->BField,
						    myEssentialData->FieldAngle
						    						));
    }
  return kTRUE;
}

void rfacLevelPicker::SlaveTerminate()
{
  fOutput->Add(returnValues);
}

void rfacLevelPicker::Terminate()
{

}
