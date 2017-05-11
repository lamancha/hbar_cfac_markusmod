#include <TFile.h>
#include <TTree.h>
#include <TGraph.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TAxis.h>
#include <TString.h>


void plot(TString val = "profile.tsv", TString output = "speed.pdf")
{
  TTree * myTTree = new TTree();
  myTTree->ReadFile(val,"shell/I:level/I:time/l");
  TGraph * gr[4];
  TCanvas * myCanvas = new TCanvas("c1","Computing times",200,10,1500,1000);
  TLegend * leg = new TLegend(0.12, 0.7, 0.22, 0.89);
  leg->SetHeader("Legend");
  for(int i = 4; i>0; --i)
    {
      myTTree->Draw("time:level",Form("shell==%d",i), "goff");
      gr[i] = new TGraph(myTTree->GetSelectedRows(),myTTree->GetV2(),myTTree->GetV1());

      gr[i]->SetLineColor(i); gr[i]->SetLineWidth(1);
      leg->AddEntry(gr[i],Form("0#leq #it{l} #leq %d",i),"l");
      if(i==4)
	{
	  gr[i]->Draw("AC*");
	  gr[i]->GetXaxis()->SetTitle("Number of principal quantum numbers #it{n}.");
	  gr[i]->GetXaxis()->CenterTitle();
	  gr[i]->GetYaxis()->SetTitle("Execution time /[ms]");
	  gr[i]->GetYaxis()->CenterTitle();
	  gr[i]->SetTitle("Execution time as function of energy levels, 8 CPU:s @ 3.6 GHz");
	}
      else
	{
	  gr[i]->Draw("PC*");
	}
    }
  leg->Draw();
  myCanvas->SetLogy();
  if(output!="")
    myCanvas->SaveAs(output);
}
