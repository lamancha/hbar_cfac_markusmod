#include "TChain.h"
#include "TProof.h"
#include "TCollection.h"
#include "include/rfacQuantumNumberLister.hh"
#include "include/rfacQuantumNumberContainer.hh"
#include "include/rfacFieldGridPicker.hh"
#include "include/rfacFieldGridContainer.hh"
#include <iostream>
using namespace std;


void prooftest()
{
  TProof * h = TProof::Open("");
   gProof->Exec("gSystem->Load(\"/home/rikard/fac/Work/hbar_cfac_rikard/DataTool/Dictionary.so\")"); 
   gProof->SetLogLevel(3);


   TChain * myChain = new TChain("T");
   myChain->Add("output_small.root");
   myChain->SetProof();
   
   rfacQuantumNumberLister * myQuantumNumberLister = new rfacQuantumNumberLister();
   gProof->AddInput(new TNamed("TreeBranchAddress", "SFACbranch"));
   myQuantumNumberLister->SetInputList(new TList());
   myQuantumNumberLister->GetInputList()->Add(new TNamed("TreeBranchAddress", "SFACbranch"));

   myChain->Process(myQuantumNumberLister);
   rfacQuantumNumberContainer * myQMContainer = NULL;
   myQMContainer = dynamic_cast<rfacQuantumNumberContainer *>(myQuantumNumberLister->GetOutputList()->FindObject("rfacQuantumNumberContainer"));
   cout << "Found :" << myQMContainer->size() << " quantum numbers." << endl ;

   rfacFieldGridPicker * myFieldGridPicker = new rfacFieldGridPicker();
   myFieldGridPicker->SetInputList(new TList());
   myFieldGridPicker->GetInputList()->Add(new TNamed("TreeBranchAddress", "SFACbranch"));
   myChain->Process(myFieldGridPicker);
   rfacFieldGridContainer * myFGContainer = NULL;
   myFGContainer = dynamic_cast<rfacFieldGridContainer *>(myFieldGridPicker->GetOutputList()->FindObject("rfacFieldGridContainer"));
   cout << "Found : " << myFGContainer->size() << " field grid point." << endl;


   delete myQuantumNumberLister;
   delete myFieldGridPicker;
   delete myChain;
   h->Close("");
}
