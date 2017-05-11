#include "rfacEssentialData.hh"

ClassImp(rfacEssentialData)
rfacEssentialData::rfacEssentialData()
{

}

rfacEssentialData::~rfacEssentialData()
{

}

void rfacEssentialData::Set(const rfacEssentialData & toCopy)
{
  Levels = toCopy.Levels;
  EField = toCopy.EField;
  BField = toCopy.BField;
  FieldAngle = toCopy.FieldAngle;
}

void rfacEssentialData::PrintStats()
{
  cout.precision(10);
  cout << setiosflags(ios::left);
  cout << "rfacEssentialData statistics:" << endl;
  cout << "Electric field: " << EField << " Magnetic field: " << BField << " Field angle: " << FieldAngle << endl;
  
  cout << "Energy levels: " << Levels.size() << endl;
  cout << setfill('*') << setw(70) << "*" << setfill(' ') << endl;
  for(map<QuantumNumbers, EnergyLevel>::iterator it = Levels.begin(); it!=Levels.end(); ++it)
    {
      cout << setw(5) << "Level: " << it->first << " Energy: " << setw(15) << it->second.Energy << "eV # Einstein coefficients: " << it->second.DecayRates.size() << endl;
    }
    cout << setfill('*') << setw(70) << "*" << setfill(' ') << endl;
}
