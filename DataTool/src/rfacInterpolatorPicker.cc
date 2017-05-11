#include "rfacInterpolatorPicker.hh"

ClassImp(rfacInterpolatorPicker)

rfacInterpolatorPicker::rfacInterpolatorPicker(TTree * myTree)
{
  found = NULL;
  myInterpolatorContainer = NULL;
  myBranchName = "InterpolatorBranch";
}
rfacInterpolatorPicker::~rfacInterpolatorPicker()
{

}

void rfacInterpolatorPicker::Init(TTree *tree)
{
  fOutput->Clear();
  found = NULL;
  myInterpolatorContainer = new rfacInterpolatorContainer();

  tree->SetBranchAddress(myBranchName, &myInterpolatorContainer, &dataBranch);
}

void rfacInterpolatorPicker::SlaveBegin(TTree *tree)
{
  TIter next(GetInputList());

  if(TObjString * obj = static_cast<TObjString*> ( next() ))
    {
      myBranchName = obj->String();
    }

  if(QuantumNumbers * obj = static_cast<QuantumNumbers*> ( next() ))
    {
      target = *obj;
    }
  else
    {
      throw rfacException("Could not retrieve TARGET object for the next quantum number.");
    }
}

Bool_t rfacInterpolatorPicker::Process(Long64_t entry)
{

  dataBranch->GetEntry(entry);

  if(myInterpolatorContainer->key == target)
    {
      if(found==NULL)
	found = new rfacInterpolatorContainer(*myInterpolatorContainer);
      else
	throw rfacException("Found two quantum numbers with same value."); ///This should never happen.
    }

  return kTRUE;
}

void rfacInterpolatorPicker::Terminate()
{

}

void rfacInterpolatorPicker::SlaveTerminate()
{
  fOutput->AddLast(found);
}


