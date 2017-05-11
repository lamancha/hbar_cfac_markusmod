#ifndef rfacEssentialData_hh
#define rfacEssentialData_hh 1

#include <iostream>
#include <map>
#include <iomanip>

#include <TObject.h>

#include "EnergyLevel.hh"
#include "QuantumNumbers.hh"

using namespace std;


class rfacEssentialData : public TObject
{
public:
  rfacEssentialData(); /// Constructor.
  ~rfacEssentialData(); /// Destructor.
  void Set(const rfacEssentialData & toCopy /// Erases the values in this object and sets them equal to the values in toCopy.
      ); /// Method used due to stupid implementation of TClonesArray. 
  Double_t EField; /// Electric field.
  Double_t BField; /// Magnetic field.
  Double_t FieldAngle; /// Angle between field.
  map<QuantumNumbers, EnergyLevel> Levels; /// The availible energy levels. The quantum numbers obviously specify the levels, while the EnergyLevel specify the energy level of it and the decay rates.
  void PrintStats(); /// Prints some info about the object.
  ClassDef(rfacEssentialData, 1) /// Essential level data.
};

  

#endif


