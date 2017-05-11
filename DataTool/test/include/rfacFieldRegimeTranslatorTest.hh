#ifndef rfacFieldRegimeTranslatorTest_hh
#define rfacFieldRegimeTranslatorTest_hh 1

#include <iostream>
#include <assert.h>
#include <map>
#include <vector>
#include <cmath>

#include "GenericUnitTest.hh"
#include "rfacFieldRegimeTranslator.hh"
#include "rfacException.hh"
#include "QuantumNumbers.hh"
#include "StrongFieldQuantumNumbers.hh"

#ifndef EPSILON
#define EPSILON 1E-9
#endif
#define DBL_EQUAL(a, b) (abs(b-a) < EPSILON)

using namespace std;

class rfacFieldRegimeTranslatorExposer
  : public rfacFieldRegimeTranslator
{
public:
  double ZGetWeakFineSplitting(unsigned int n, ///Quantum number.
							  unsigned int twoj  ///Quantum number.
							  ) const ///Calculates splitting.
  { return GetWeakFineSplitting(n, twoj);}
  
  double ZGetStrongFineSplitting(unsigned int n,  ///Quantum number.
								unsigned int l, ///Quantum number. 
								int ml,  ///Quantum number.
								int twoms ///Quantum number.
								) const ///Calculates splitting.
  { return GetStrongFineSplitting(n, l, ml, twoms);}
  
  double ZGetWeakZeemanSplitting(unsigned int l,  ///Quantum number.
								unsigned int twoj,  ///Quantum number.
								int twomj,  ///Quantum number.
								double B /// Magnetic field.
								) const///Calculates splitting.
  { return GetWeakZeemanSplitting(l, twoj, twomj, B); }
  
  double ZGetStrongZeemanSplitting(int ml,  ///Quantum number.
								  int twoms,  ///Quantum number.
								  double B /// Magnetic field.
								  ) const///Calculates splitting.
  { return GetStrongZeemanSplitting(ml, twoms, B); }
};


class rfacFieldRegimeTranslatorTest : public GenericUnitTest
{
 public:
  int RunTests() const; ///Main function.
  string ToString() const;
 protected:
  int TestCase1() const;
};
#endif
