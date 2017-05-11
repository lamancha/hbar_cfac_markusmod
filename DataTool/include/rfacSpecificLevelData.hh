#ifndef rfacSpecificLevelData_hh
#define rfacSpecificLevelData_hh 1

#include <iostream>
#include <map>
#include <iomanip>

#include <TObject.h>

#include "EnergyLevel.hh"
#include "QuantumNumbers.hh"

using namespace std;


class rfacSpecificLevelData : public TObject
{
public:
  rfacSpecificLevelData(); /// Constructor.
  ~rfacSpecificLevelData(); /// Destructor.
  rfacSpecificLevelData(EnergyLevel _Level, float _EField, float _BField, float _FieldAngle);
  void Set(const rfacSpecificLevelData & toCopy /// Erases the values in this object and sets them equal to the values in toCopy.
      ); /// Method used due to stupid implementation of TClonesArray. 
  Double_t EField; /// Electric field.
  Double_t BField; /// Magnetic field.
  Double_t FieldAngle; /// Angle between field.
  EnergyLevel Level; ///Energy level.


  friend ostream& operator<<(ostream& os, ///Stream.
			     const rfacSpecificLevelData& val ///constant object.
			     ); ///This stuff is used to stream the object to a stream. Quite useful.

  string ToString();

  ClassDef(rfacSpecificLevelData, 1) /// Essential level data.
};

  

#endif


