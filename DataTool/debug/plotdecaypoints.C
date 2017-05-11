#include <TFile.h>
#include <TTree.h>
#include <TGraph.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TAxis.h>
#include <TString.h>
#include <TH1F.h>
#include <vector>


#include "include/QuantumNumbers.hh"
#include "include/rfacLevelPicker.hh"
#include "include/rfacLevelContainer.hh"

#define EV_TO_HZ 2.417989E14

void plotdecaypoints(int n = 2, int l = 1, int twoj = 3)
{
  TString LevelFile = "ny.root";
  TFile * myTFile = new TFile(LevelFile);
  if(myTFile->IsZombie())
    {
      cout << "File is zombie. Terminating." << endl;
      return;
    }
  vector<TGraph *> gr;
  TCanvas * myCanvas = dynamic_cast<TCanvas *>(gROOT->FindObject("plotlevel_canvas"));
  if(myCanvas == NULL)
    myCanvas = new TCanvas("plotlevel_canvas","Computing times",200,10,1500,1000);
  TLegend * leg = new TLegend(0.12, 0.6, 0.32, 0.89);
  vector<QuantumNumbers *> target;
  for(int twomj = 1; twomj <= twoj; twomj+=2)
    {
      for(int p = -1; p<=1; p+=2)
	{
	  target.push_back(new QuantumNumbers(n, l, twoj, twomj, p));
	  cout << target.back()->ToString() << endl;
	}

    }
  leg->SetHeader("Quantum numbers");

  TTree * T = (TTree*)myTFile->Get("T");



  double MaxY = -100000;
  double MinY = 100000;
  int linecolor = 1;
  rfacLevelPicker * myLevelPicker = new rfacLevelPicker();

  for(vector<QuantumNumbers *>::const_iterator it = target.begin(); it!=target.end(); ++it)
    {

      myLevelPicker->SetInputList(new TList());
      myLevelPicker->GetInputList()->Add(new TNamed("TreeBranchAddress","SFACbranch"));
      myLevelPicker->GetInputList()->Add(new QuantumNumbers(*(*it)));
      T->Process(myLevelPicker);
      
      rfacLevelContainer * myPickerOutput = dynamic_cast<rfacLevelContainer*>(myLevelPicker->GetOutputList()->FindObject("rfacLevelContainer"));

      vector<Double_t> vx;
      vector<Double_t> vy;
      for(vector<rfacSpecificLevelData>::const_iterator ig = myPickerOutput->begin(); ig!=myPickerOutput->end(); ++ig)
	{
	  QuantumNumbers temp(1,0,1,1,1);
	  if(ig->Level.DecayRates.find(temp)!=ig->Level.DecayRates.end())
	    {
	      if(ig->BField == 1 && ig->EField == 10000)
		{
		  vx.push_back(ig->FieldAngle);
		  vy.push_back(ig->Level.DecayRates.at(temp));
		}
	    }
	  else
	    {
	    }
	}

      gr.push_back(new TGraph(vx.size(),&vx[0], &vy[0]));

      gr.back()->SetMarkerColor(linecolor);
      gr.back()->SetLineColor(linecolor++); gr.back()->SetLineWidth(3);

      leg->AddEntry(gr.back(),(*it)->ToString().c_str(),"l");
      if(gr.back()->GetHistogram()->GetMinimum() < MinY)
	{
	  MinY = gr.back()->GetHistogram()->GetMinimum();
	}
      if(gr.back()->GetHistogram()->GetMaximum() > MaxY)
	{
	  MaxY = gr.back()->GetHistogram()->GetMaximum();
	}
      myLevelPicker->GetOutputList()->Clear();
    }
  for(vector<TGraph *>::iterator it = gr.begin(); it!=gr.end(); ++it)
    {
      double diff = MaxY-MinY;
      (*it)->GetHistogram()->SetMaximum(MaxY + 0.03*diff);
      (*it)->GetHistogram()->SetMinimum(MinY - 0.03*diff);

      if(it == gr.begin())
	{
	  (*it)->Draw("A*");
	  (*it)->GetXaxis()->SetTitle("Magnetic field B /[T]");
	  (*it)->GetXaxis()->CenterTitle();
	  (*it)->GetYaxis()->SetTitle("Decay rate /[s^{-1}]");
	  (*it)->GetYaxis()->CenterTitle();
	  (*it)->SetTitle("Decay rates.");
	}
      else
	{
	  (*it)->Draw("P*");
	}
    }
  leg->Draw();
}
