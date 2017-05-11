#include "rfacFieldRegimeTranslator.hh"


TRandom1 * rfacFieldRegimeTranslator::myFailsafeRandom = NULL;


rfacFieldRegimeTranslator::rfacFieldRegimeTranslator(double (*_U01Function)(), double _lowerHysteresisFactor, double _upperHysteresisFactor)
  :fieldStrength(0), lowerHysteresisFactor(_lowerHysteresisFactor), upperHysteresisFactor(_upperHysteresisFactor)
{
  U01Function = _U01Function;
  if( U01Function == NULL)
    {
      U01Function = &uniform0to1Random;
    }
}

rfacFieldRegimeTranslator::~rfacFieldRegimeTranslator()
{
  if(myFailsafeRandom != NULL)
    {
      delete myFailsafeRandom;
      myFailsafeRandom = NULL;
    }
}

void rfacFieldRegimeTranslator::SetField(double _fieldStrength)
{
  fieldStrength = _fieldStrength;
}

bool rfacFieldRegimeTranslator::WillTranslate(const GeneralQuantumNumbers * value ) const
{
  if(const QuantumNumbers * val = dynamic_cast<const QuantumNumbers * >(value))
	{
	  return WillTranslateSpec(val);
	}
  else if(const StrongFieldQuantumNumbers * val = dynamic_cast<const StrongFieldQuantumNumbers*>(value))
	{
	  return WillTranslateSpec(val);
	}
  throw RLException("rfacFieldRegimeTranslator quantum number type.");
}

bool rfacFieldRegimeTranslator::Translate(GeneralQuantumNumbers ** value) const
{
  if(value == NULL)
	throw RLException("Cannot use Translate with a NULL pointer.");
  
  GeneralQuantumNumbers * toCheck = *value;
  if(toCheck == NULL)
	throw RLException("Cannot use Translate with a pointer to a null pointer, either.");

  if( WillTranslate(toCheck) )
	{
	  if(const QuantumNumbers * val = dynamic_cast<const QuantumNumbers*>(toCheck))
		{
		  StrongFieldQuantumNumbers * nVal = DoTranslate(val);
		  delete toCheck;
		  *value = nVal;
		  return true;
		}
	  else if(const StrongFieldQuantumNumbers * val = dynamic_cast<const StrongFieldQuantumNumbers*>(toCheck))
		{
		  QuantumNumbers * nVal = DoTranslate(val);
		  delete toCheck;
		  *value = nVal;
		  return true;
		}
	  else
		{
		  throw RLException("rfacFieldRegimeTranslator quantum number type.");
		}
	}
  else
	{
	  return false;
	}
  throw RLException("rfacFieldRegimeTranslator : internal error.");
}

double rfacFieldRegimeTranslator::GetField() const
{
  return fieldStrength;
}

bool rfacFieldRegimeTranslator::WillTranslateSpec(const QuantumNumbers * val) const
{
  if(val == NULL)
	throw RLException("Tried to use WillTranslateSpec with argument NULL.");
  double finesplit = GetWeakFineSplitting(val->GetN(), val->GetTwoJ());
  double zeeman = GetWeakZeemanSplitting(val->GetL(), val->GetTwoJ(), val->GetTwoMJ(), fieldStrength);
  return (abs(zeeman) > upperHysteresisFactor * abs(finesplit));
	
}

bool rfacFieldRegimeTranslator::WillTranslateSpec(const StrongFieldQuantumNumbers * val) const
{
  if(val == NULL)
	throw RLException("Tried to use WillTranslateSpec with argument NULL.");
  double finesplit = GetStrongFineSplitting(val->GetN(), val->GetL(), val->GetML(), val->GetTwoMS());
  double zeeman = GetStrongZeemanSplitting(val->GetML(), val->GetTwoMS(), fieldStrength);

  return (abs(zeeman) < lowerHysteresisFactor * abs(finesplit));

}

QuantumNumbers * rfacFieldRegimeTranslator::DoTranslate(const StrongFieldQuantumNumbers * val) const
{
  QuantumNumbers * toReturn = CGTranslator::StochasticTranslate(val, U01Function());
  return toReturn;
}

StrongFieldQuantumNumbers * rfacFieldRegimeTranslator::DoTranslate(const QuantumNumbers * val) const
{
  StrongFieldQuantumNumbers * toReturn = CGTranslator::StochasticTranslate(val, U01Function());
  return toReturn;
}


double rfacFieldRegimeTranslator::uniform0to1Random()
{
  if(myFailsafeRandom == NULL)
    {
      myFailsafeRandom = new TRandom1(std::time(NULL));
    }
  return myFailsafeRandom->Rndm();
}

double rfacFieldRegimeTranslator::GetWeakFineSplitting(unsigned short n, unsigned short twoj) const
{
  if(n == 0 || !(twoj & 1) )
	{
	  throw RLException("Invalid input for n or twoj in GetFineSplitting");
	}
  double j = (double)twoj / 2.0;
  double toReturn = HYDROGEN_E0*pow(FINE_STRUCTURE_CONSTANT, 2.0)/ pow((double)n, 3.0) *
	(0.75-((double)n/((double)j+0.5)));
  return toReturn;
}

double rfacFieldRegimeTranslator::GetStrongFineSplitting(unsigned short n, unsigned short l, int ml, int twoms) const
{
  if(n==0 || abs(twoms) != 1)
	throw RLException("Invalid input to GetStrongFineSplitting.");


  ///Strategy: take the maximum out of the strong-field and weak-field value here.

  double ms = (double)twoms/2.0;
  double braCket = 1;
  if(l != 0)
	braCket = ((double)(((double)l*((double)l+1) - (double)ml*ms)))/((double)l*((double)l+0.5)*((double)l+1));
  double toReturn1 = HYDROGEN_E0*pow(FINE_STRUCTURE_CONSTANT,2.0)/pow((double)n, 3.0) *
	(3.0/(4.0*(double)n) - braCket);

  double toReturn2 = GetWeakFineSplitting(n, abs((2*(short)l + twoms)) );


  return MAXA(toReturn1, toReturn2);
}

double rfacFieldRegimeTranslator::GetWeakZeemanSplitting(unsigned short l, unsigned short twoj, int twomj, double B) const
{
  if(!(twoj & 1) )
	throw RLException("Invalid twoj supplied to GetWeakZeemanSplitting.");
  if(!(twomj & 1) || abs(twomj) > abs(twoj))
	throw RLException("Invalid twomj supplied to GetWeakZeemanSplitting.");

  double mj = (double)twomj/2.0;
  int twos = (int)twoj - (int) 2*l;
  double gJ = (1.0 + GetLandeG(twoj, l, twos));
  double toReturn = BOHR_MAGNETON * gJ * B * mj;
  return toReturn;
}

double rfacFieldRegimeTranslator::GetStrongZeemanSplitting(int ml, int twoms, double B) const
{
  if(abs(twoms) != 1)
	throw RLException("Invalid twoms supplied to GetStrongZeemanSplitting.");
  double toReturn = BOHR_MAGNETON * (ml + twoms) * B;
  return toReturn;
}


double rfacFieldRegimeTranslator::GetLandeG(unsigned short twoj, unsigned short l, int twos)
{
  if( abs(twos) != 1 )
	{
	  throw RLException("Invalid s-parameter for Lande G factor.");
	}
  if( twos%2==0)
	{
	  throw RLException("Invalid j-parameter for Lande G factor.");
	}

  double j = (double)twoj/2;
  double s = (double)twos/2;
  double toReturn = (j*(j+1) + s*(s+1) - l*(l+1) )/(2*j*(j+1));
  return toReturn;
}


void rfacFieldRegimeTranslator::SetLowerHysteresisFactor(double value)
{
  lowerHysteresisFactor = value;
}


void rfacFieldRegimeTranslator::SetUpperHysteresisFactor(double value)
{
  upperHysteresisFactor = value;
}

double rfacFieldRegimeTranslator::GetLowerHysteresisFactor() const
{
  return lowerHysteresisFactor;
}

double rfacFieldRegimeTranslator::GetUpperHysteresisFactor() const
{
  return upperHysteresisFactor;
}
