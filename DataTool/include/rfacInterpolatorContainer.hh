#ifndef rfacInterpolatorContainer_hh
#define rfacInterpolatorContainer_hh 1

#include <set>
#include <vector>
#include <map>
#include <algorithm>


#include "TMultiDimFit.h"
#include "TObject.h"
#include "TROOT.h"

#include "Quadruple.hh"
#include "QuantumNumbers.hh"
#include "rfacSpecificLevelData.hh"
#include "rfacException.hh"
#include "rfacLinearInterpolation.hh"
#include "rfac3DInterpolation.hh"
#include "VerbosePrinter.hh"
#include "VerbosePrinterEventEnabled.hh"

#include <iostream>

using namespace std;

///Contains interpolator stuff.
class rfacInterpolatorContainer: public TObject
{
public:
  rfacInterpolatorContainer(); /// Constructor.
  rfacInterpolatorContainer(const QuantumNumbers & k, /// Quantum number.
			    vector<rfacSpecificLevelData> & values, ///Values. Electric field and angle will be DISCARDED and NOT USED. The energy will NOT BE USED EITHER. Live with it.
			    int fieldGridSize = -1, ///Field grid points.
			    VerbosePrinter * toUse = NULL ///Verbose printer to use (if applicable)
			    ); /// Constructor



  ~rfacInterpolatorContainer(); /// Destructor.

  QuantumNumbers key; ///the key (quantum number) to this object.
  map<QuantumNumbers, rfacLinearInterpolation> decayRates; /// The decay rate interpolators.

  map<QuantumNumbers, rfac3DInterpolation> decayRates3D; /// Decay Rate interpolator for 3D

  static void SetFlag3D(bool Flag){Flag3D = Flag;} /// Whether all EField, BField and FieldAngle is used,
                                                         /// then 3DInterpolator

protected:
  static bool Flag3D; ///This member shows wheter all data (BField, EField, Angle) is enabled and 3D Interpolator
                      ///is needed

private:

  ClassDef(rfacInterpolatorContainer, 5) /// Essential level data.
};

#endif
