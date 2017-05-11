{
  TFile * tin = new TFile("ut.root");
  rfacQuantumNumberLister * myQuantumNumberLister = new rfacQuantumNumberLister();
  myQuantumNumberLister->SetBranchName("SFACbranch");
  rfacLevelPicker * myLevelPicker = new rfacLevelPicker();
  myLevelPicker->SetBranchName("SFACbranch");
  T->Process(myQuantumNumberLister);
  for(set<QuantumNumbers>::iterator it = myQuantumNumberLister->found.begin(); it!= myQuantumNumberLister->found.end(); ++ it)
    {
      ++it;
      T->Process(myLevelPicker);
      rfacInterpolatorContainer * tempContainer = new rfacInterpolatorContainer(*it, myQuantumNumberLister->found, myLevelPicker->found);
    }
  


  tin->Close();
  delete tin;
}
