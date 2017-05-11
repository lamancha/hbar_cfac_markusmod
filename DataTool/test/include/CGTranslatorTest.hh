#ifndef CGTranslatorTest_hh
#define CGTranslatorTest_hh 1

#include <iostream>
#include <assert.h>
#include <map>
#include <vector>
#include <cmath>

#include "GenericUnitTest.hh"
#include "CGTranslator.hh"
#include "rfacException.hh"
#include "QuantumNumbers.hh"
#include "StrongFieldQuantumNumbers.hh"

#ifndef EPSILON
#define EPSILON 1E-9
#endif
#define DBL_EQUAL(a, b) (abs(b-a) < EPSILON)

using namespace std;

class CGTranslatorTest : 
  public GenericUnitTest
{
 public:
  int RunTests() const; ///Main function.
  string ToString() const;
 protected:
  bool CanInitialize() const;
  bool ComputesVariousCoefficientsCorrectly() const;
  int TestCase3() const;
  int TestCase4() const;
};
#endif
