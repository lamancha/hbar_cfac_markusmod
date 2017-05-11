#include <TFile.h>
#include <TTree.h>
#include <TGraph.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TAxis.h>
#include <TString.h>
#include <iostream>
#include <TH1F.h>

#include "include/QuantumNumbers.hh"
#include "include/rfacLevelPicker.hh"
#include "include/rfacLevelContainer.hh"

using namespace std;


void plotlevelptr()
{
  TFile * myTFile = new TFile("output_small.root");
  if(myTFile->IsZombie())
    {
      cout << "File is zombie. Terminating." << endl;
      return;
    }

  TGraph * gr[6];
  TCanvas * myCanvas = new TCanvas("c1","Computing times",200,10,1500,1000);
  TLegend * leg = new TLegend(0.12, 0.7, 0.22, 0.89);
  QuantumNumbers * target[6];
  target[0] = new QuantumNumbers(4,2,5,5,1);
  target[1] = new QuantumNumbers(4,2,5,3,1);
  target[2] = new QuantumNumbers(4,2,5,5,-1);
  target[3] = new QuantumNumbers(4,2,5,3,-1);
  target[4] = new QuantumNumbers(4,2,5,1,1);
  target[5] = new QuantumNumbers(4,2,5,1,-1);

  leg->SetHeader("Legend");

  TTree * T = (TTree*)myTFile->Get("T");


  rfacLevelPicker * myLevelPicker = new rfacLevelPicker();
  for(int i = 0; i<1; ++i)
    {
      myLevelPicker->SetInputList(new TList());
      myLevelPicker->GetInputList()->Add(new TNamed("TreeBranchAddress","SFACbranch"));
      myLevelPicker->GetInputList()->Add(new QuantumNumbers(*target[i]));
      T->Process(myLevelPicker);

      rfacLevelContainer * myPickerOutput = dynamic_cast<rfacLevelContainer*>(myLevelPicker->GetOutputList()->FindObject("rfacLevelContainer"));

      vector<Double_t> vx;
      vector<Double_t> vy;
      int ptr = 0;
      for(vector<rfacSpecificLevelData>::const_iterator it = myPickerOutput->begin(); it!=myPickerOutput->end(); ++it)
	{
	  vx.push_back(it->BField);
	  vy.push_back(it->Level.Energy);
	  cout << (ptr++) << endl;
	}

      myPickerOutput->Print("v");
      
      gr[i] = new TGraph(myPickerOutput->size(),&vx[0], &vy[0]);
      
      gr[i]->SetLineColor(i+1); gr[i]->SetLineWidth(3);
      leg->AddEntry(gr[i],target[i]->ToString().c_str(),"l");
      gr[i]->GetHistogram()->SetMaximum(12.589); 
      gr[i]->GetHistogram()->SetMinimum(13.087);

      if(i==0)
	{
	  gr[i]->Draw("A*");
	  gr[i]->GetXaxis()->SetTitle("Magnetic field B /[T]");
	  gr[i]->GetXaxis()->CenterTitle();
	  gr[i]->GetYaxis()->SetTitle("Energy /[eV]");
	  gr[i]->GetYaxis()->CenterTitle();
	  gr[i]->SetTitle("Magnetic field splitting using interpolation.");
	}
      else
	{
	  gr[i]->Draw("P*");
	}
    }
  leg->Draw();
  myTFile->Close();
}
