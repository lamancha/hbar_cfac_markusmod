#include <utility>
#include <map>
#include <vector>
#include <set>

#include "TMultiDimFit.h"
#include "TVectorD.h"

#include "TObject.h"

#include "TMatrixT.h"

#include "TSelector.h"

#include "rfacSpecificLevelData.hh"
#include "QuantumNumbers.hh"
#include "EnergyLevel.hh"
#include "rfacEssentialData.hh"
#include "rfacQuantumNumberLister.hh"
#include "rfacInterpolatorContainer.hh"
#include "rfacLevelPicker.hh"
#include "rfacException.hh"
#include "rfacFieldGridPicker.hh"
#include "rfacFieldGridPoint.hh"
#include "rfacFieldGridContainer.hh"
#include "rfacQuantumNumberContainer.hh"
#include "StrongFieldQuantumNumbers.hh"
#include "rfacFieldRegimeTranslator.hh"
#include "GeneralQuantumNumbers.hh"
#include "Quadruple.hh"
#include "rfac3DInterpolation.hh"


#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclasses;

#pragma link C++ class EnergyLevel+;
#pragma link C++ class QuantumNumbers+;
#pragma link C++ class StrongFieldQuantumNumbers+;
#pragma link C++ class rfacEssentialData+;
#pragma link C++ class rfacSpecificLevelData+;
#pragma link C++ class rfacQuantumNumberLister+;
#pragma link C++ class rfacLevelPicker+;
#pragma link C++ class rfacException+;
#pragma link C++ class rfacInterpolation+;
#pragma link C++ class rfac3DInterpolation+;
#pragma link C++ class Quadruple+;
#pragma link C++ class rfacInterpolatorContainer+;
#pragma link C++ class rfacInterpolatorPicker+;
#pragma link C++ class rfacLinearInterpolation+;
#pragma link C++ class rfacFieldGridPicker+;
#pragma link C++ class rfacFieldGridPoint+;
#pragma link C++ class rfacFieldGridContainer+;
#pragma link C++ class rfacQuantumNumberContainer+;
#pragma link C++ class rfacLevelContainer+;
#pragma link C++ class rfacDecayableObject+;
#pragma link C++ class rfacFieldRegimeTranslator+;
#pragma link C++ class CGTranslator+;
#pragma link C++ class GeneralQuantumNumbers+;
#pragma link C++ class std::vector<Quadruple>+;
#pragma link C++ class std::vector<rfacSpecificLevelData>+;
#pragma link C++ class std::set<rfacFieldGridPoint>+;
#pragma link C++ class std::set<rfacFieldGridPoint>::iterator+;
#pragma link C++ class std::map<QuantumNumbers, Double_t>+;
#pragma link C++ class std::map<QuantumNumbers, EnergyLevel>+;
#pragma link C++ class std::map<QuantumNumbers, rfacLinearInterpolation>+;
#pragma link C++ class std::pair<QuantumNumbers, Double_t>+;
#pragma link C++ class std::pair<QuantumNumbers, EnergyLevel>+;
#pragma link C++ class std::pair<QuantumNumbers, rfacLinearInterpolation>+;
#pragma link C++ class std::vector<rfacSpecificLevelData>+;
#pragma link C++ class std::set<QuantumNumbers>+;
#pragma link C++ class std::set<QuantumNumbers>::iterator+;
#pragma link C++ class std::vector<QuantumNumbers>+;
#pragma link C++ class std::vector<QuantumNumbers>::iterator+;
#pragma link C++ class std::vector<TVectorD>+;
#pragma link C++ class std::vector<Double_t>+;
#pragma link C++ class std::pair<Double_t, vector<Double_t> >+;
#pragma link C++ class std::vector<vector<Double_t> >+;

#endif
