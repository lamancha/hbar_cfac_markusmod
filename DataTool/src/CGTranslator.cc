#include "CGTranslator.hh"

bool CGTranslator::initialized = false;

double CGTranslator::factorials[] = {0};

double CGTranslator::GetCoefficient(short twoj1, 
									short twoj2, 
									short twoj,
									short twom1,
									short twom2,
									short twom 
						)
{

  if(!initialized) ///Initialize factorial list, and such.
	Initialize();

  if( twom1+twom2 != twom )
	throw RLException("Invalid parameters: twom1 + twom2 != twom");
  if( (twoj1-twom1)%2 != 0)
	throw RLException("Invalid parameters: twoj1 and twom1 must have same parity.");
  if( (twoj2-twom2)%2 != 0)
	throw RLException("Invalid parameters: twoj2 and twom2 must have same parity.");
  if( (twoj-twom)%2 != 0)
	throw RLException("Invalid parameters: twoj and m must have same parity.");
  if( (twoj > twoj1 + twoj2) || (twoj < abs(twoj1-twoj2) ) )
	throw RLException("Invalid parameters: Must have abs(twoj1-twoj2) <= twoj <= twoj1+twoj2");
  if( abs(twom1) > twoj1 )
	throw RLException("Invalid parameters: Must have twom1 <= twoj1");
  if( abs(twom2) > twoj2 )
	throw RLException("Invalid parameters: Must have twom2 <= twoj2");
  if( abs(twom) > twoj )
	throw RLException("Invalid parameters: Must have m <= j");

  double preParFactor = 1;
  if( twoj1 < twoj2 )
	{
	  preParFactor *= pow(-1.0, (double)(twoj-twoj1-twoj2));
	  short intermed = twoj1;
	  twoj1 = twoj2;
	  twoj2 = intermed;
	  intermed = twom1;
	  twom1 = twom2;
	  twom2 = intermed;
	}
  if(twom < 0)
	{
	  preParFactor *= pow(-1.0, (double)(twoj-twoj1-twoj2));
	  twom *= -1;
	  twom1 *= -1;
	  twom2 *= -1;
	}


  ///We calculate using logarithms to avoid problems with big numbers

  double term1 = 0.5*(log((double)twoj+1)
					  +GetTwoIntegerLogFactorial(twoj+twoj1-twoj2)
					  +GetTwoIntegerLogFactorial(twoj-twoj1+twoj2)
					  +GetTwoIntegerLogFactorial(twoj1+twoj2-twoj)
					  -GetTwoIntegerLogFactorial(twoj1+twoj2+twoj+2));


  double term2 = 0.5*(GetTwoIntegerLogFactorial(twoj+twom)
					  +GetTwoIntegerLogFactorial(twoj-twom)
					  +GetTwoIntegerLogFactorial(twoj1-twom1)
					  +GetTwoIntegerLogFactorial(twoj1+twom1)
					  +GetTwoIntegerLogFactorial(twoj2-twom2)
					  +GetTwoIntegerLogFactorial(twoj2+twom2));
  ///Identify minimum and maximum k in formula from http://en.wikipedia.org/wiki/Table_of_Clebsch%E2%80%93Gordan_coefficients

  int maxK = MIN3(twoj1+twoj2-twoj, twoj1 - twom1, twoj2 + twom2);
  int minK = MAX2(-(twoj - twoj2 + twom1), -(twoj - twoj1 - twom2));

  if(minK < 0)
	minK = 0;
  if(maxK < 0)
	maxK = 0;

  if( minK % 2 != 0 || maxK % 2 != 0)
	throw RLException("minK or maxK did not meet assertions: even.");


  double result = 0;

  for(int k = minK; k<=maxK; k+=2)
	{
	  double term3 = -(GetTwoIntegerLogFactorial(k)
					   +GetTwoIntegerLogFactorial(twoj1 + twoj2 - twoj - k)
					   +GetTwoIntegerLogFactorial(twoj1 - twom1 - k)
					   +GetTwoIntegerLogFactorial(twoj2 + twom2 - k)
					   +GetTwoIntegerLogFactorial(twoj - twoj2 + twom1 + k)
					   +GetTwoIntegerLogFactorial(twoj - twoj1 - twom2 + k));
	  double final = term1 + term2 + term3;
	  result += pow(-1,k/2)*exp(final);
	}

  return result* preParFactor;
}

double CGTranslator::GetTwoIntegerLogFactorial(int value)
{
  AssertPositiveTwoInteger(value);
  return GetLogFactorial(value/2);
}

void CGTranslator::AssertPositiveTwoInteger(int toAssert)
{
  if(toAssert < 0)
	{
	  throw RLException("PositiveTwoIntegerAssertion failed: negative value.");
	}
  if(toAssert % 2)
	throw RLException("PositiveTwoIntegerAssertion failed: not mod 2.");
}

double CGTranslator::GetLogFactorial(unsigned int value)
{
  if( value > MAX_FACTORIALS ) ///Use Stirling's approximation here (it's probably good enough for the purpose...)
	{
	  double toReturn = ((double)value)*(log((double)value) - 1) + 0.5*log(2*PI*((double)value));
	  return toReturn;
	}
  return factorials[value];
}

bool CGTranslator::IsInitialized()
{
  return initialized;
}

void CGTranslator::Initialize()
{
  if(initialized)
	return;
  initialized = true;
  factorials[0]=0;
  for(int i = 1; i<MAX_FACTORIALS; ++i)
	{
	  factorials[i]=factorials[i-1] + log(i);
	}
}



list<pair<StrongFieldQuantumNumbers, double> > * CGTranslator::GetAllPossibleTranslatedStates(const QuantumNumbers & toTranslate )
{
  if(!toTranslate.ValidateConsistency())
	{
	  throw RLException("Non-consistent quantum number used.");
	}
  list<pair<StrongFieldQuantumNumbers, double> > * toReturn = new list<pair<StrongFieldQuantumNumbers, double> >();
  unsigned short n = toTranslate.GetN();
  unsigned short l = toTranslate.GetL();

  short twoj1 = 1; ///l is conserved.
  short twoj2 = 2*l; ///spin 1/2.
  short twoj = toTranslate.GetTwoJ(); ///Translate this.
  short twom = toTranslate.GetTwoMJ(); ///pre-m.

  ///so, now all we need to do is to find M1 and M2, and we are done. We know that 
  ///M = M1 + M2
  ///|Mi| <= Ji
  
  for(short twom1 = -1; twom1 <= 1; twom1 += 2)
	{
	  short twom2 = twom - twom1;
	  if( abs(twom2) > twoj2 || abs(twom1) > twoj1 )
		continue;
	  double coeff = GetCoefficient(twoj1, twoj2, twoj, twom1, twom2, twom);
	  if(abs(coeff) > 1E-9) ///we need some decent cutoff.
		{
		  if(twom2%2!=0)
			throw RLException("CG error: ml was not an integer.");
		  toReturn->push_back(make_pair(StrongFieldQuantumNumbers(n, l, twom2/2,twom1),coeff));
		}
	}

  ///Make sure we don't return garbage.
  double sum = 0;
  for(list<pair<StrongFieldQuantumNumbers, double> >::const_iterator it = toReturn->begin(); it!=toReturn->end(); ++it)
	{
	  sum += pow(abs(it->second),2);
	}
  if(abs(sum-1) > 1E-9)
	{
	  throw RLException("CG coefficients does not sum up to 1: sum is %f", sum);
	}


  return toReturn;
} 

list<pair<QuantumNumbers, double> > * CGTranslator::GetAllPossibleTranslatedStates(const StrongFieldQuantumNumbers & toTranslate)
{
  if(!toTranslate.ValidateConsistency())
	{
	  throw RLException("Non-consistent quantum number used.");
	}

  list<pair<QuantumNumbers, double> > * toReturn = new list<pair<QuantumNumbers, double> >();
  unsigned short n = toTranslate.GetN();
  unsigned short l = toTranslate.GetL();

  short twoj1 = 1; ///l is conserved.
  short twoj2 = 2*l; ///spin 1/2.
  short twom1 = toTranslate.GetTwoMS();
  short twom2 = 2*toTranslate.GetML();

  ///We need to find twoj and twom.
  ///M = M1 + M2

  short twom = twom1 + twom2;

  ///|Mi| <= Ji

  for(short twoj = abs(twoj1-twoj2); twoj <= twoj1 + twoj2; twoj += 2 )
	{
	  if(abs(twom) > twoj )
		continue;
	  double coeff = GetCoefficient(twoj1, twoj2, twoj, twom1, twom2, twom);
	  if(abs(coeff) > 1E-9) ///we need some decent cutoff.
		{
		  toReturn->push_back(make_pair(QuantumNumbers(n, l, twoj, twom), coeff));
		}
	}


  ///Internal consistency check.
  double sum = 0;
  for(list<pair<QuantumNumbers, double> >::const_iterator it = toReturn->begin(); it!=toReturn->end(); ++it)
	{
	  sum += pow(abs(it->second),2);
	}
  if(abs(sum-1) > 1E-9)
	{
	  throw RLException("CG coefficients does not sum up to 1: sum is %f", abs(sum-1));
	}

  return toReturn;
}

StrongFieldQuantumNumbers * CGTranslator::StochasticTranslate(const QuantumNumbers * toTranslate, double randomNumber)
{

  if(!toTranslate->ValidateConsistency())
	{
	  throw RLException("Non-consistent quantum number used.");
	}

  if(randomNumber < 0 || randomNumber > 1)
	throw RLException("randomNumber must be between 0 and 1.");
  list<pair<StrongFieldQuantumNumbers, double> > * myCGTable = GetAllPossibleTranslatedStates(*toTranslate);
  StrongFieldQuantumNumbers toReturn;
  double sum = 0;
  for(list<pair<StrongFieldQuantumNumbers, double> >::const_iterator it = myCGTable->begin(); it!=myCGTable->end(); ++it)
	{
	  sum += pow(abs(it->second),2);
	  if(sum >= randomNumber)
		{
		  toReturn = it->first;
		  break;
		}
	}
  delete myCGTable;
  myCGTable = NULL;
  return new StrongFieldQuantumNumbers(toReturn);
}

QuantumNumbers * CGTranslator::StochasticTranslate(const StrongFieldQuantumNumbers * toTranslate, double randomNumber)
{
  if(!toTranslate->ValidateConsistency())
	{
	  throw RLException("Non-consistent quantum number used.");
	}
  if(randomNumber < 0 || randomNumber > 1)
	throw RLException("randomNumber must be between 0 and 1.");
  list<pair<QuantumNumbers, double> > * myCGTable = GetAllPossibleTranslatedStates(*toTranslate);
  QuantumNumbers toReturn;
  double sum = 0;
  for(list<pair<QuantumNumbers, double> >::const_iterator it = myCGTable->begin(); it!=myCGTable->end(); ++it)
	{
	  sum += pow(abs(it->second),2);
	  if(sum >= randomNumber)
		{
		  toReturn = it->first;
		  break;
		}
	}
  delete myCGTable;
  myCGTable = NULL;
  return new QuantumNumbers(toReturn);
}
