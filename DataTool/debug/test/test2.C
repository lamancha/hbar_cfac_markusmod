{
  TFile * tin = new TFile("sven.root");
  rfacInterpolatorContainer * myInterpolatorContainer = new rfacInterpolatorContainer();
  T->SetBranchAddress("InterpolatorBranch", &myInterpolatorContainer);
  T->GetEntry(10);
  TMultiDimFit * hej = myInterpolatorContainer->energy;
  cout << myInterpolatorContainer->decayRates << endl;
  cout << hej->Eval(new Double_t[]{1,0,0}) << endl;
  
  tin->Close();
  delete tin;
}
