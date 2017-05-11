#include "EnergyLevel.hh"

ClassImp(EnergyLevel)

EnergyLevel::EnergyLevel()
{
  Energy = 0;
}

EnergyLevel::~EnergyLevel()
{
  
}

ostream& operator<<(ostream& os, const EnergyLevel& val)
{
  os << "Energy: " << val.Energy << "eV, #DecayRates: " << val.DecayRates.size();
  return os;
}

string EnergyLevel::ToString()
{
  stringstream ss;
  ss << *this;
  return ss.str();
}
