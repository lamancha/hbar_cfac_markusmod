#include <TFile.h>
#include <TTree.h>
#include <TGraph.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TAxis.h>
#include <TString.h>

#include "include/rfacQuantumNumberLister.hh"
#include "include/rfacQuantumNumberContainer.hh"
#include "include/rfacLevelPicker.hh"
#include "include/rfacLevelContainer.hh"

void totaltime()
{
  TFile * myTFile = new TFile("output/output10.root");
  TTree * T = (TTree*)myTFile->Get("T");
  rfacQuantumNumberLister * myQuantumNumberLister = new rfacQuantumNumberLister();
  myQuantumNumberLister->SetInputList(new TList());
  myQuantumNumberLister->GetInputList()->Add(new TNamed("TreeBranchAddress", "SFACbranch"));
  T->Process(myQuantumNumberLister);
  rfacQuantumNumberContainer * myQMContainer = NULL;
  myQMContainer = dynamic_cast<rfacQuantumNumberContainer *>(myQuantumNumberLister->GetOutputList()->FindObject("rfacQuantumNumberContainer"));

  rfacLevelPicker * myLevelPicker = new rfacLevelPicker();

  for(set<QuantumNumbers>::iterator it = myQMContainer->begin(); it!=myQMContainer->end(); ++it)
    {
      myLevelPicker->SetInputList(new TList());
      myLevelPicker->GetInputList()->Add(new TNamed("TreeBranchAddress","SFACbranch"));
      myLevelPicker->GetInputList()->Add(new QuantumNumbers(*it));
      T->Process(myLevelPicker);
      
      rfacLevelContainer * myPickerOutput = dynamic_cast<rfacLevelContainer*>(myLevelPicker->GetOutputList()->FindObject("rfacLevelContainer"));
      
      double totalRate = 0;
      for(vector<rfacSpecificLevelData>::const_iterator ir = myPickerOutput->begin(); ir!=myPickerOutput->end(); ++ir)
	{
	  for(map<QuantumNumbers, Double_t>::const_iterator ip = ir->Level.DecayRates.begin(); ip!=ir->Level.DecayRates.end(); ++ip)
	    {
	      totalRate+=ip->second;
	      if(it->n==2 && it->l==1)
		{
		  cout << "FROM: " << (*it) << " TO " << ip->first << " RATE " << ip->second << endl;
		}
	    }
	}
      if(totalRate < 1E6)
	cout << "Total half-life of " << it->ToString() << " is " << "; " << 1.0E6*1/totalRate << " us" << endl;
      
      
      myLevelPicker->GetOutputList()->Clear();
    }
}
