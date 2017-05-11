#include "rfacInterpolatorContainer.hh"

ClassImp(rfacInterpolatorContainer)

rfacInterpolatorContainer::rfacInterpolatorContainer()
{

}

bool rfacInterpolatorContainer::Flag3D = 0;

rfacInterpolatorContainer::rfacInterpolatorContainer(const QuantumNumbers & k, vector<rfacSpecificLevelData> & values, int fieldGridSize, VerbosePrinter * toUse)
 :key(k)
{ ///Attention: k is the target QN picked by the InterpolatorPicker, QN in DecayRate is from where the decay is happening
  if(Flag3D == 0)
  {
    if(values.size() < 2)
      throw rfacException("Too little data to be able to do a linear fit.");
      ///construct the interpolators.

    map<QuantumNumbers, vector<pair<Double_t, Double_t> > > dRate;

    ///map<QuantumNumbers, rfacFieldGridContainer> containing; ///used to speed up point assurance (later).

    ///The inner for-loop iterates the map<QuantumNumbers, Double_t> DecayRates-Type. To this QN decay to all other
    /// with this Einsteincoefficient Double_t
    for(vector<rfacSpecificLevelData>::iterator it = values.begin(); it!=values.end(); ++it)
      {
        ///Loop order change in progress here.
        for(map<QuantumNumbers, Double_t>::iterator ip = it->Level.DecayRates.begin(); ip!=it->Level.DecayRates.end(); ++ip)
	  {
	    dRate[ip->first].push_back(make_pair(it->BField,ip->second));
	  }
      }

    for(map<QuantumNumbers, vector<pair<Double_t, Double_t> > >::iterator it = dRate.begin(); it!=dRate.end(); ++it)
    {
      if(it->second.size() < 2) ///VERY bad, interpolation is going to fail. Zero everything out instead.
	  {
	    if(toUse)
		  toUse->Print(1, "WARNING: not enough decay rates (%d), this decay channel (%s ===>>> %s) will now be discarded!\n",
		  it->second.size(), key.ToString().c_str(),it->first.ToString().c_str());
	  }
      else
	  {
	    decayRates.insert(make_pair(it->first,rfacLinearInterpolation(it->second)));
	  }
    }
  }
  else
  {

  if(values.size() < 6)
    throw rfacException("Too little data to be able to do a 3D-fit.");

   map<QuantumNumbers, vector<Quadruple> > d3DRate;

  for(vector<rfacSpecificLevelData>::iterator it = values.begin(); it!=values.end(); ++it)
    {
      ///Loop order change in progress here.
      for(map<QuantumNumbers, Double_t>::iterator ip = it->Level.DecayRates.begin(); ip!=it->Level.DecayRates.end(); ++ip)
	{
      Quadruple* myQuadruple = new Quadruple();
      myQuadruple->SetBField(it->BField);
      myQuadruple->SetEField(it->EField);
      myQuadruple->SetFieldAngle(it->FieldAngle);
      myQuadruple->SetDecayRate(ip->second);

      d3DRate[ip->first].push_back(*myQuadruple);
	}
    }

  for(map<QuantumNumbers, vector<Quadruple> >::iterator it = d3DRate.begin(); it!=d3DRate.end(); ++it)
    {
      if(it->second.size() < 1) ///VERY bad, interpolation is going to fail.
	  {
	    if(toUse)
		  toUse->Print(1, "WARNING: not enough decay rates (%d), this decay channel (%s ===>>> %s) will now be discarded!\n",
		  it->second.size(), key.ToString().c_str(),it->first.ToString().c_str());
	  }
      else
	  {
	    decayRates3D.insert(make_pair(it->first,rfac3DInterpolation(it->second)));
	  }
    }
  }
}


rfacInterpolatorContainer::~rfacInterpolatorContainer()
{

}
