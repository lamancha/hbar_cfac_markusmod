///Used for checking the intermediate datafile.

#include <TFile.h>
#include <TTree.h>
#include <TGraph.h>
#include <TCanvas.h>
#include <TAxis.h>
#include <TString.h>
#include <TH1F.h>
#include <vector>

using namespace std;
#include "include/rfacInterpolation.hh"
#include "include/QuantumNumbers.hh"
#include "include/rfacLevelPicker.hh"

void intercomp()
{
  QuantumNumbers start(20,19,39,39);
  QuantumNumbers stop(19,18,37,37);


  TFile * myFile = new TFile("/home/rikard/CERN13/hbar_gshfs/hstates.root");
  TTree * T = (TTree*) myFile->Get("T");

  TGraph * gr;
  TCanvas * myCanvas = new TCanvas("c1","Computing times",200,10,1500,1000);
  (void)myCanvas;


  rfacLevelPicker * myLevelPicker = new rfacLevelPicker();
  myLevelPicker->SetInputList(new TList());
  myLevelPicker->GetInputList()->Add(new TNamed("TreeBranchAddress","SFACbranch"));
  myLevelPicker->GetInputList()->Add(new QuantumNumbers(start));
  T->Process(myLevelPicker);
  
  rfacLevelContainer * myPickerOutput = dynamic_cast<rfacLevelContainer*>(myLevelPicker->GetOutputList()->FindObject("rfacLevelContainer"));
  
  vector<Double_t> vx;
  vector<Double_t> vy;
  int ptr = 0;
  for(vector<rfacSpecificLevelData>::const_iterator it = myPickerOutput->begin(); it!=myPickerOutput->end(); ++it)
    {
      vx.push_back(it->BField);
      vy.push_back((it->Level.DecayRates.at(stop)));
      cout << (ptr++) << endl;
    }
  
  myPickerOutput->Print("v");
  
  gr = new TGraph(myPickerOutput->size(),&vx[0], &vy[0]);
  
  gr->SetLineColor(3); gr->SetLineWidth(3);
 
  
  gr->Draw("A*");
  gr->GetXaxis()->SetTitle("Magnetic field B /[T]");
  gr->GetXaxis()->CenterTitle();
  gr->GetYaxis()->SetTitle("Decay rate /[s]");
  gr->GetYaxis()->CenterTitle();
  gr->SetTitle("Magnetic field implications for decay rate.");


  delete myFile;

  rfacInterpolation * myInterpolation = new rfacInterpolation("/home/rikard/CERN13/hbar_gshfs/hstates.root");

  myInterpolation->SetState(start);

  int N = 100;
  vector<Double_t> vx2;
  vector<Double_t> vy2;
  for(int j = 0; j<N; ++j)
    {
      double Bfield = 4.0/N*j;
      vx2.push_back(Bfield);
      vy2.push_back((myInterpolation->GetDecayRates(Bfield))[stop]); ///
    }

  TGraph * gr2 = new TGraph(N,&vx2[0], &vy2[0]);

  gr2->Draw("PC");

  delete myInterpolation;
  
}
