#include <TFile.h>
#include <TTree.h>
#include <TGraph.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TAxis.h>
#include <TString.h>
#include <TH1F.h>
#include <vector>


#include "include/rfacInterpolation.hh"
#include "include/QuantumNumbers.hh"

#define EV_TO_HZ 2.417989E14

void plotdecay(int n = 4, int l = 2, int twoj = 5)
{
  rfacInterpolation * myInterpolation = new rfacInterpolation("/home/rikard/CERN13/hbar_gshfs/hstates.root");
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
	  target.push_back(new QuantumNumbers(n, l, twoj, p*twomj));
	}

    }
  leg->SetHeader("Quantum numbers");
  double MaxY = -100000;
  double MinY = 100000;
  int linecolor = 1;
  for(vector<QuantumNumbers *>::const_iterator it = target.begin(); it!=target.end(); ++it)
    {
      myInterpolation->SetState(*(*it));

      int N = 100;
      vector<Double_t> vx;
      vector<Double_t> vy;
      for(int j = 0; j<N; ++j)
	{
	  double Bfield = 4.0/N*j;
	  vx.push_back(Bfield);
	  vy.push_back((myInterpolation->GetDecayRates(0,Bfield,0))[QuantumNumbers(1,0,1,1)]); ///
	}

      gr.push_back(new TGraph(N,&vx[0], &vy[0]));

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
    }
  for(vector<TGraph *>::iterator it = gr.begin(); it!=gr.end(); ++it)
    {
      double diff = MaxY-MinY;
      (*it)->GetHistogram()->SetMaximum(MaxY + 0.03*diff);
      (*it)->GetHistogram()->SetMinimum(MinY - 0.03*diff);

      if(it == gr.begin())
	{
	  (*it)->Draw("AC");
	  (*it)->GetXaxis()->SetTitle("Magnetic field B /[T]");
	  (*it)->GetXaxis()->CenterTitle();
	  (*it)->GetYaxis()->SetTitle("Energy splitting /[GHz]");
	  (*it)->GetYaxis()->CenterTitle();
	  (*it)->SetTitle("Magnetic field splitting using interpolation.");
	}
      else
	{
	  (*it)->Draw("PC");
	}
    }
  leg->Draw();
}
