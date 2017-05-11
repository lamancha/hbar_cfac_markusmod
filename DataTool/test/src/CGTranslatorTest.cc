#include "CGTranslatorTest.hh"

bool CGTranslatorTest::CanInitialize() const
{
  CGTranslator::Initialize();
  CGTranslator::Initialize();
  CGTranslator::Initialize();

  return true;
}

bool CGTranslatorTest::ComputesVariousCoefficientsCorrectly() const
{
  if(!DBL_EQUAL(CGTranslator::GetCoefficient(2, 1, 3, 0, 1, 1),sqrt(2./3.)))
	return false;
  if(!DBL_EQUAL(CGTranslator::GetCoefficient(2, 1, 3, 2, 1, 3),1.))
	return false;
  if(!DBL_EQUAL(CGTranslator::GetCoefficient(20,14,24,10,6,16),0.090819639389735310434))
	return false;
  if(!DBL_EQUAL(CGTranslator::GetCoefficient(2*20, 2*15, 2*25, 2*10, 2*13, 2*23),0.34419254061705495886))
	return false;
  if(!DBL_EQUAL(CGTranslator::GetCoefficient(40*2,60*2,50*2,40*2,-5*2,35*2),0.00041725430673980290302))
	return false;
  if(!DBL_EQUAL(CGTranslator::GetCoefficient(400,600,500,400,-50,350),2.0056894425775537795E-30))
	return false;
  return true;
}

int CGTranslatorTest::TestCase3() const
{
  list<pair<StrongFieldQuantumNumbers, double> > * myList = 
	CGTranslator::GetAllPossibleTranslatedStates(QuantumNumbers(5,1,3,3));
  if( myList->size() != 1 )
	return 1;
  if( myList->front().first != StrongFieldQuantumNumbers(5, 1, 1, 1) ||
	  ! DBL_EQUAL(myList->front().second, 1) )
	return 2;

  delete myList;
  myList = CGTranslator::GetAllPossibleTranslatedStates(QuantumNumbers(5, 1, 3, 1));

  for(list<pair<StrongFieldQuantumNumbers, double> >::const_iterator it = myList->begin(); it != myList->end(); ++it)
	{
	  if(it->first == StrongFieldQuantumNumbers(5, 1, 1, -1) )
		{
		  if(!DBL_EQUAL(it->second, sqrt(1./3.)))
			return 3;
		}
	  else if(it->first == StrongFieldQuantumNumbers(5, 1, 0, 1) )
		{
		  if(!DBL_EQUAL(it->second, sqrt(2./3.)))
			return 4;
		}
	  else
		return 5;
	}
  delete myList;

  return 0;
}

int CGTranslatorTest::TestCase4() const
{
  list<pair<QuantumNumbers, double> > * myList = 
	CGTranslator::GetAllPossibleTranslatedStates(StrongFieldQuantumNumbers(5, 1, 1, 1));

  if(myList->size() != 1)
	return 1;

  if(myList->front().first != QuantumNumbers(5, 1, 3, 3)  || !DBL_EQUAL(myList->front().second,1))
	return 2;
  delete myList;
  myList = CGTranslator::GetAllPossibleTranslatedStates(StrongFieldQuantumNumbers(5, 1, 0, 1) );

  /*  for(list<pair<QuantumNumbers, double > >::const_iterator it = myList->begin(); it!=myList->end(); ++it)
	{
	  cout << it->first << " " << it->second << endl;
	  }*/
  for(list<pair<QuantumNumbers, double > >::const_iterator it = myList->begin(); it!=myList->end(); ++it)
	{
	  if(it->first == QuantumNumbers(5, 1, 3, 1) )
		{
		  if(!DBL_EQUAL(it->second, sqrt(2./3.)))
			return 3;
		}
	  else if(it->first == QuantumNumbers(5, 1, 1, 1) )
		{
		  if(!DBL_EQUAL(it->second, -sqrt(1./3.)))
			return 4;
		}
	  else
		{
		  return 5;
		}
	}

  delete myList;
  return 0;
}


int CGTranslatorTest::RunTests() const
{
  if(!CanInitialize())
    return 1;
  if(!ComputesVariousCoefficientsCorrectly())
	return 2;
  int retVal1 = TestCase3();
  if(retVal1)
	return retVal1 + 10;
  int retVal2 = TestCase4();
  if(retVal2)
	return retVal2 + 20;
  return 0;
}

string CGTranslatorTest::ToString() const
{
  return "CGTranslator";
}
