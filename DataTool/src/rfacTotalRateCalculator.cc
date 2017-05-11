#include "rfacTotalRateCalculator.hh"


double TimeToGSdoIt(const QuantumNumbers current, Double_t fieldValue)
{
  if(calculated.find(current) != calculated.end())
	return calculated[current];
  if(current.GetN() == 1)
	return 0;
  
  calculated[current]=1E98; ///to prevent infinite loops...
  
  if(subEssential.find(current) == subEssential.end())
	{
	  cout << "Could not find " << current << endl;
	  return 1E99;
	}
  
  cout << calculated.size() << " calculated, total states " << subEssential.size() << " latest " << current << endl;
  
  
  Double_t thisLevelRate = 0;

  map<QuantumNumbers, double> rb = subEssential[current].DecayRates;
  

  for(map<QuantumNumbers, double>::const_iterator it = rb.begin(); it != rb.end(); ++it)
	{
	  thisLevelRate+=it->second;
	}

  Double_t averageSubLifetime = 0;
  
  for(map<QuantumNumbers, double>::const_iterator it = rb.begin(); it != rb.end(); ++it)
	{
	  Double_t subLife = TimeToGS(it->first, fieldValue);
	  if(subLife > 5E98)
		{
		  cout << current << " -> " << it->first << " returned " << subLife << endl;
		}
	  else
		{
		  subLife*= it->second / thisLevelRate;
		  averageSubLifetime += subLife;
		}
	}
  
  Double_t thisLifetime = 1./thisLevelRate + averageSubLifetime;
  if(thisLevelRate == 0)
	{
	  cout << "Long-lifed excited state " << current << " detected. Counting it as GS." << endl;
	  thisLifetime = 0;
	}
  
  calculated[current] = thisLifetime;
  
  
  return thisLifetime;

}

double TimeToGS(const QuantumNumbers current, Double_t fieldValue)
{
  for(unsigned int i = 0; i<T->GetEntries(); ++i)
    {
      T->GetEntry(i);
	  if(myEssentialData->EField != fieldValue)
		continue;

	  subEssential = myEssentialData->Levels;
	  /*	  for(map<QuantumNumbers, EnergyLevel>::iterator it = subEssential.begin(); it != subEssential.end(); ++it)
		{
		  if(!it->first.ValidateConsistency())
			cout << "Quantum number " << it->first << "is invalid." << endl;
		  for(map<QuantumNumbers, Double_t>::iterator ip = it->second.DecayRates.begin(); ip != it->second.DecayRates.end(); ++ip)
			{
			  if(!ip->first.ValidateConsistency())
				{
				  cout << "--->Quantum number " << it->first << "is invalid." << endl;
				}
			}
			}*/
	  return TimeToGSdoIt(current, fieldValue);
	}
  
  cout << "Field value not found." << endl;
  return -1;
}



int main()
{
  Double_t fieldValue1 = 0;
  Double_t fieldValue2 = 2000000;
  TFile * F = new TFile("Etest2.root");
  T = (TTree*)F->Get("T");
  myEssentialData = 0;
  T->SetBranchAddress("SFACbranch", &myEssentialData);

  QuantumNumbers toCheck(25,24,49,49);

  calculated.clear();
  Double_t ttg1 = TimeToGS(toCheck, fieldValue1);
  calculated.clear();
  Double_t ttg2 = TimeToGS(toCheck, fieldValue2);
  cout.precision(10);
  cout << "For field " << fieldValue1 << " average life " << ttg1 << " s and for field " << fieldValue2 << " average life is " << ttg2 << " ratio " << ttg2/ttg1 << endl;
  F->Close();
  
}
