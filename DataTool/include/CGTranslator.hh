#ifndef CGTranslator_hh
#define CGTranslator_hh 1

#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <list>
#include "RLException.hh"
#include "QuantumNumbers.hh"
#include "StrongFieldQuantumNumbers.hh"
#include <iostream>
#include "TObject.h"

using namespace std;

#define MAX_FACTORIALS 300 ///Maximum factorials to use exact formula for, for higher ones use Stirling's approximation.

#define MIN3(a1, a2, a3) (std::min(a1,std::min(a2,a3))) ///Min of three numbers.
#define MAX2(a1,a2) (std::max(a1,a2)) ///Max of two numbers.

#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628 ///Constant

///Contain some static methods used for Clebsch-Gordan computation.
class CGTranslator : public TObject
{
public:
  static double GetCoefficient(short twoj1, ///2 * J1 
							   short twoj2, ///2 * J2
							   short twoj, /// 2 * J
							   short twom1, ///2 * M1
							   short twom2, ///2 * M2
							   short twom /// 2 * M
						); ///Returns the CG coefficient corresponding to this. NOTE: Coefficient is computed with a general purpose formula, might be inefficient! Consider using memoization for speed.

  static bool IsInitialized(); ///Check if the class is initialized or not.

  static void Initialize(); ///Initialize the class (basically precompute some factorials). Called automatically when needed.

  static list<pair<StrongFieldQuantumNumbers, double> > * 
  GetAllPossibleTranslatedStates(const QuantumNumbers & toTranslate ///The quantum number to translate.
								 ); ///Returns all possible strong field quantum numbers corresponding to a quantum number, together with their CG coefficients. Note: the caller takes the ownership of the returned object.

  static list<pair<QuantumNumbers, double> > * 
  GetAllPossibleTranslatedStates(const StrongFieldQuantumNumbers & toTranslate ///The quantum number to translate.
								 );///Returns all weak field quantum numbers corresponding to a quantum number, together with their CG coefficients. Note: the caller takes the ownership of the returned object.

  static StrongFieldQuantumNumbers * StochasticTranslate(const QuantumNumbers * toTranslate, ///The quantum number to translate.
													   double randomNumber ///A random number between 0 and 1 used to determine which quantum number to translate to.
													   ); ///Returns a strong field quantum number corresponding to a QuantumNumbers object, using randomNumber to determine which. Guaranteed to return the same result for the same input.

  static QuantumNumbers * StochasticTranslate(const StrongFieldQuantumNumbers * toTranslate, ///The quantum number to translate.
													   double randomNumber ///A random number between 0 and 1 used to determine which quantum nuber to translate to.
													   );///Returns a weak field quantum number corresponding to a StrongFieldQuantumNumbers object, using randomNumber to determine which. Guaranteed to return the same result for the same input.
  

private:
  CGTranslator() {} ///Thou shall not instantiate this class.

  static double GetTwoIntegerLogFactorial(int value
										  ); ///If value is even and >= 0, returns log((value/2)!). Otherwise, throws exception.

  static void AssertPositiveTwoInteger(int toAssert
									   ); ///Quality assurance function, throws an exception if toAsset is negative or odd.

  static double GetLogFactorial(unsigned int value
								);///Returns log(value!)

  static bool initialized; ///Keeps track of if we have already computed the factorials or not.

  static double factorials[MAX_FACTORIALS]; ///Precomputed factorials. 

  ClassDef(CGTranslator, 1)
};
#endif
