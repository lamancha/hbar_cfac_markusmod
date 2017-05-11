#include "rfacFieldRegimeTranslatorTest.hh"


int rfacFieldRegimeTranslatorTest::TestCase1() const
{
  rfacFieldRegimeTranslatorExposer myExposer;
  unsigned int n = 1;
  unsigned int twoj = 1;
  int l = 0;
  int ml = 0;
  int twoms = 1;
  int twomj = 1;
  double B = 0;

  if(!DBL_EQUAL(myExposer.ZGetWeakFineSplitting(n, twoj), myExposer.ZGetStrongFineSplitting(n, l, ml, twoms)))
	return 1;
  
  if(!DBL_EQUAL(myExposer.ZGetWeakZeemanSplitting(l, twoj, twomj, B), 0))
	return 2;
  if(!DBL_EQUAL( myExposer.ZGetStrongZeemanSplitting(ml, twoms, B), 0))
	return 3;

  return 0; 
}

int rfacFieldRegimeTranslatorTest::RunTests() const
{
  int retVal1 = TestCase1();
  if(retVal1)
	return retVal1;
  /*
  rfacFieldRegimeTranslatorExposer myExposer;

  cout << myExposer.ZGetWeakFineSplitting(25, 49) << " " << myExposer.ZGetStrongFineSplitting(25, 24, 24, 1) << " " << myExposer.ZGetWeakZeemanSplitting(24, 49, 49, 1E-3) << " " <<  myExposer.ZGetStrongZeemanSplitting(24, 1, 1E-3) << endl;
  */

  return 0;
}


string rfacFieldRegimeTranslatorTest::ToString() const
{
  return "rfacFieldRegimeTranslator";
}
