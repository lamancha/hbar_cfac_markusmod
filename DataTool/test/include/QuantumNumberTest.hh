#ifndef QuantumNumberTest_hh
#define QuantumNumberTest_hh 1

#include <iostream>
#include <assert.h>
#include <map>
#include <vector>
#include <cmath>

#include "GenericUnitTest.hh"
#include "rfacException.hh"
#include "QuantumNumbers.hh"

#include <iostream>

#ifndef EPSILON
#define EPSILON 1E-9
#endif

using namespace std;

class QuantumNumberTest 
  : public GenericUnitTest
{
 public:
  int RunTests() const; ///Main function.
  string ToString() const;
 protected:
  int TestCase1() const; /// Test case.

};
#endif
