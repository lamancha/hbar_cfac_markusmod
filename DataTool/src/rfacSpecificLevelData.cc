#include "rfacSpecificLevelData.hh"

ClassImp(rfacSpecificLevelData)
rfacSpecificLevelData::rfacSpecificLevelData()
{

}

rfacSpecificLevelData::rfacSpecificLevelData(EnergyLevel _Level, float _EField, float _BField, float _FieldAngle)
{
  Level = _Level;
  EField = _EField;
  BField = _BField;
  FieldAngle = _FieldAngle;
}

rfacSpecificLevelData::~rfacSpecificLevelData()
{
  
}

void rfacSpecificLevelData::Set(const rfacSpecificLevelData & toCopy)
{
  Level = toCopy.Level;
  EField = toCopy.EField;
  BField = toCopy.BField;
  FieldAngle = toCopy.FieldAngle;
}


ostream& operator<<(ostream& os, const rfacSpecificLevelData& val)
{
  os << "E-field: " << val.EField << " B-field: " << val.BField << " FieldAngle: " << val.FieldAngle << " Level: " << val.Level;
  return os;
}

string rfacSpecificLevelData::ToString()
{
  stringstream ss;
  ss << *this;
  return ss.str();
}
