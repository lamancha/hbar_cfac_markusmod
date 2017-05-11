/// This file is used to calculate decay rates in an intermediate file.
/// Used for verification purposes only.

#include <TFile.h>
#include <TTree.h>
#include <TGraph.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TAxis.h>
#include <TString.h>
#include <stdio.h>

#include "include/rfacEssentialData.hh"

void connectedDecayRates()
{
  TFile * myTFile = new TFile("tmp_out.root");
  TTree * T = (TTree*)myTFile->Get("T");
  rfacEssentialData * myEssentialData = new rfacEssentialData();
  T->SetBranchAddress("SFACbranch", &myEssentialData);
  map<QuantumNumbers, Double_t> totalDecayRate;
  FILE * fout = fopen("all.txt", "w");
  for(int i = 0; i<T->GetEntries(); ++i)
    {
      T->GetEntry(i); ///should only happen once for the target tree (20).
      cout << myEssentialData->EField << " " << myEssentialData->BField << " " << endl;
      for(map<QuantumNumbers, EnergyLevel>::iterator it = myEssentialData->Levels.begin(); it!=myEssentialData->Levels.end(); ++it)
	  {
	    totalDecayRate[it->first] = 0;
	    for(map<QuantumNumbers, Double_t>::iterator ip = it->second.DecayRates.begin(); ip!=it->second.DecayRates.end(); ++ip)
	      {
		if(ip->first!=it->first)
		  totalDecayRate[it->first]+=ip->second;
	      }
	    cout << "State " << it->first << " has a TOTAL Einstein coefficient of " << totalDecayRate[it->first] << endl;
	    fprintf(fout,"State %s has a TOTAL Einstein coefficient of %13.6E.\n", it->first.ToString().c_str(), totalDecayRate[it->first]);
	  }
    }
  fclose(fout);
  
  TGraph * gr;
  TCanvas * myCanvas = new TCanvas("c1","Decay rates",200,10,1500,1000);
  //TLegend * leg = new TLegend(0.12, 0.7, 0.22, 0.89);
  //  leg->SetHeader("Sven");

  T->Draw("SFACbranch.Levels.second.DecayRates.second:SFACbranch.Levels.second.DecayRates.first.n","SFACbranch.Levels.first.n==10","goff");
  gr = new TGraph(T->GetSelectedRows(),T->GetV2(),T->GetV1());
  
  gr->SetLineColor(1); gr->SetLineWidth(1);
  //leg->AddEntry(gr,"SSVEN","l");
  gr->Draw("A*");
  gr->GetXaxis()->SetTitle("Principal quantum number #it{n} of destination state");
  gr->GetXaxis()->CenterTitle();
  gr->GetYaxis()->SetTitle("Decay rate /[s^{-1}]");
  gr->GetYaxis()->CenterTitle();
  gr->SetTitle("Decay rates to different states from all states with #it{n}=10, m=1");
  
  //leg->Draw();
  myCanvas->SetLogy();
  myCanvas->SaveAs("InterDecayM1.pdf");
}
