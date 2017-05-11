#ifndef rfacInterpolation_hh
#define rfacInterpolation_hh 1

#include <string>
#include <cmath>
#include <map>
#include <utility>
#include <iostream>
#include <vector>

#include "TString.h"
#include "TMultiDimFit.h"
#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TString.h"

#include "QuantumNumbers.hh"
#include "rfacInterpolatorContainer.hh"
#include "RLException.hh"
#include "rfacInterpolatorPicker.hh"
#include "rfacLinearInterpolation.hh"
#include "rfac3DInterpolation.hh"
#include "rfacQuantumNumberLister.hh"
#include "CGTranslator.hh"
#include "StrongFieldQuantumNumbers.hh"
#include "GeneralQuantumNumbers.hh"

#include <iostream>

using namespace std;

#define MAX(a, b) ((a>b)?a:b)

/** Used to interpolate:
Given any E-field, B-field and the angle between them, and the appropriate root file, this
class will read the root file and can then be used to obtain desirable interpolated quantities.

 */
class rfacInterpolation: public TObject
{
public:
  rfacInterpolation(TString rootFileName = "hstates.root", /// The name of the root file to use.
		    TString TTreeName = "T", /// The name of the TTree to use.
		    TString TBranchName = "InterpolatorBranch"/// The name of the TBranch to use.
		    ); /// Constructor, construct the object.
  ~rfacInterpolation(); /// Destructor.

  void SetState(QuantumNumbers state /// The state to set the current state to.
		      ); ///Set the current state to the one inputted.

  void SetState(GeneralQuantumNumbers * state
				);

  void SetStrongFieldState(StrongFieldQuantumNumbers state
						   );

  QuantumNumbers GetState(); /// Get the current state.

  StrongFieldQuantumNumbers GetStrongState();

  map<QuantumNumbers, Double_t> GetDecayRates(Double_t Bfield, Double_t Efield, Double_t Angle  ///Magnetic field
					      ); ///Returns the interpolated decay rates for the current state, given the fields.

  map<StrongFieldQuantumNumbers, Double_t> GetStrongFieldDecayRates(Double_t Bfield, Double_t Efield, Double_t Angle
																	);

  void PrintThisObject(); ///Print content to stdout.

  void PreloadStates(); ///Preload states into memory to speed up execution.


private:
  TChain * myTChain; //! Pointer to current tChain.
  QuantumNumbers currentState; /// Quantum numbers of the current state.
  StrongFieldQuantumNumbers currentStrongState; ///Current strong state.

  rfacInterpolatorPicker * myInterpolatorPicker; ///Interpolator picker.
  rfacInterpolatorContainer * myContainer; ///Current interpolator container.


  TString rootFileName, TTreeName, TBranchName; ///File name of root file.

  map<QuantumNumbers, rfacInterpolatorContainer *> * preloaded; ///preloaded stuff.

  friend ostream& operator<<(ostream& os, ///Stream.
			     const rfacInterpolation& val ///constant object.
			     ); ///This stuff is used to stream the object to a stream. Quite useful.

  ClassDef(rfacInterpolation, 1)
};


#endif
