#ifndef EnergyLevel_hh
#define EnergyLevel_hh 1

#include <map>

#include <TObject.h>

#include "QuantumNumbers.hh"

#include <sstream>

using namespace std;

class EnergyLevel: public TObject
{
public:
  EnergyLevel(); /// Constructor.
  ~EnergyLevel(); /// Destructor.
  Double_t Energy; /// Energy.
  map<QuantumNumbers, Double_t> DecayRates; /// Decay rates (Einstein coefficients) FROM this level TO all other levels.
  ///DecayRates[OtherLevel]=something.
  ///OtherLevel is the index of the other level contained in the rfacEssentialData Levels object map.

  friend ostream& operator<<(ostream& os, ///Stream.
			     const EnergyLevel& val ///constant object.
			     ); ///This stuff is used to stream the object to a stream. Quite useful.

  string ToString();


  ClassDef(EnergyLevel, 1) /// Energy levels.
};

#endif


