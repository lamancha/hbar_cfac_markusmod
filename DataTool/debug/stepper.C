/// Important test : time stepping.

#include "TH1D.h"
#include "TCanvas.h"
#ifndef vector_RL
#define vector_RL 1
#include <vector>
#endif
#include <utility>

#ifndef RLINCLUDE_Hx
#define RLINCLUDE_Hx 1
#include "RLlib/include/VerbosePrinter.hh"
#include "include/rfacDecayableObject.hh"
#endif

using namespace std;

void stepper()
{
  double startPos = 0; //meters
  double stepSize = 1E-4; //meters
  double velocity = 1000;//2500;
  double maxHistLim = 0.5;
  int histBins = 200;

  vector<double> BFields;
  vector<double> BBreak;
  BFields.push_back(0.0); BFields.push_back(0.5);
  BBreak.push_back(0.0); BBreak.push_back(0.1);

  bool VerboseTransitions = false;

  //QuantumNumbers initial(25,24,49,49,1);
  QuantumNumbers initial(20,10,21,11);
  //QuantumNumbers initial(15,14,29,29,1);


  TCanvas * myCanvas = new TCanvas("c1","Distance until ground state",100,10,1500,1000);
  (void)myCanvas;

  int nTries = 100000;

  TString title = "Distribution of distances until ground state starting from " + initial.ToString();
  TH1D * myTH1D = new TH1D("Hist", title, histBins,0,maxHistLim);
  rfacDecayableObject * myDecayable = new rfacDecayableObject();
  myDecayable->SetStateFile("/home/rikard/CERN13/hbar_gshfs/hstates.root");
  myDecayable->PreloadStates();
      
  for(int i = 0; i<nTries; ++i)
    {
	  if(100*i % nTries == 0)
		cout << "Progress : " << 100*i/nTries << "%" << endl;
      //cout << "Step " << i << endl;
	  myDecayable->ResetQuantumNumbers();
	  myDecayable->SetN(initial.GetN());
	  myDecayable->SetL(initial.GetL());
	  myDecayable->SetTwoJ(initial.GetTwoJ());
	  myDecayable->SetTwoMJ(initial.GetTwoMJ());
      myDecayable->InitializeDecay();
      double pos = startPos;
      //cout << "POS " << pos*1E6 << "µm : " << * myDecayable << endl;
      double finalPos = 0;

      while(myDecayable->GetN() != 1)
		{
		  GeneralQuantumNumbers * prev = myDecayable->GetQuantumNumbers()->CreateCopy();
		  double bestB = 0;
		  for(int k = 0; k<BFields.size(); ++k)
			{
			  if(BBreak[k] > pos)
				break;
			  bestB = BFields[k];
			}

		  if(myDecayable->SetField(bestB) && VerboseTransitions)
			{
			  cout << "Transition triggered: new " << myDecayable->GetQuantumNumbers()->ToString() << endl;
			}

		  myDecayable->DoStepTime(stepSize/velocity);
		  pos+=stepSize;
		  //cout << myDecayable->PeekAtTimeToNextDecay() << endl;
		  if(!myDecayable->GetQuantumNumbers()->Equals(prev))
			{
			  //cout << "POS " << pos << "m : " << * myDecayable << endl;
			  finalPos = pos;
			}
		  if(pos > maxHistLim * 1.5)
			{
			  break;
			}
		}
      //cout << "Final position: " << finalPos << "m." << endl;
      myTH1D->Fill(finalPos,1);
    }
  delete myDecayable;
  myTH1D->GetXaxis()->SetTitle("Distance from production [/m]");
  myTH1D->GetXaxis()->CenterTitle();
  myTH1D->GetYaxis()->SetTitle("Frequency");
  myTH1D->GetYaxis()->CenterTitle();
  TString saveName = Form("nq%d.pdf",initial.GetN());
  myTH1D->Draw();
  myCanvas->SaveAs(saveName);
}
