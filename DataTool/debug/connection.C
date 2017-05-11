///Checks for the intermediate root file.
#include <TFile.h>
#include <TTree.h>
#include <TGraph.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TAxis.h>
#include <TString.h>


void connection()
{
  TFile * myTFile = new TFile("tmp_out.root");
  TTree * T = (TTree*)myTFile->Get("T");
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
