#ifndef rfacFieldRegimeTranslator_hh
#define rfacFieldRegimeTranslator_hh 1

#include <TRandom1.h>
#include <TObject.h>
#include <ctime>
#include <cstdlib>


#include "QuantumNumbers.hh"
#include "GeneralQuantumNumbers.hh"
#include "StrongFieldQuantumNumbers.hh"
#include "CGTranslator.hh"
#include "RLException.hh"

#define MAX(a, b) ((a>b)?a:b)
#define MAXA(a, b) ((abs(a)>abs(b))?a:b)

#define LOWER_HYSTERESIS_FACTOR_DEFAULT 0.5
#define UPPER_HYSTERESIS_FACTOR_DEFAULT 5.0
#define FINE_STRUCTURE_CONSTANT 7.2973525698E-3
#define HYDROGEN_E0 13.6
#define BOHR_MAGNETON 5.7883818066E-5

using namespace std;

/**
   Used to translate quantum numbers between a field regime and another.
*/

class rfacFieldRegimeTranslator 
  : public TObject
{
public:
  rfacFieldRegimeTranslator(double (*_U01Function)() = NULL, ///Randomization function to use.
							double _lowerHysteresisFactor = LOWER_HYSTERESIS_FACTOR_DEFAULT, ///Hysteresis factor to construct with.
							double _upperHysteresisFactor = UPPER_HYSTERESIS_FACTOR_DEFAULT /// Hysteresis factor to construct with
							); ///Constructor.

  ~rfacFieldRegimeTranslator(); ///Destructor.

  void SetField(double _fieldStrength ///New field strength. UNIT: TESLA
				); ///Sets the current field. Imperative for correct translation.

  double GetField() const; ///Returns the current field.

  bool WillTranslate(const GeneralQuantumNumbers * value /// The general quantum numbers to check.
					 ) const; ///Returns true if a call to Translate will actually translate the object, false otherwise.

  bool Translate(GeneralQuantumNumbers ** value ///The quantum numbers to translate. Note: if a translate takes place, these WILL be DESTROYED and populated with new ones.
				 ) const; ///Destructive translation of GeneralQuantumNumbers from one type to another. Returns true if translation took place, false otherwise.

protected:
  bool WillTranslateSpec(const QuantumNumbers * val ///Q-number value.
						 ) const; ///Internal will-translate check.

  bool WillTranslateSpec(const StrongFieldQuantumNumbers * val ///Q-number value.
						 ) const; ///Internal will-translate check.

  QuantumNumbers * DoTranslate(const StrongFieldQuantumNumbers * val ///Q-number value.
							   ) const; ///Internal will-translate check.

  StrongFieldQuantumNumbers * DoTranslate( const QuantumNumbers * val ///Q-number value.
										   ) const; ///Internal will-translate check.

  double GetWeakFineSplitting(unsigned short n, ///Quantum number.
							  unsigned short twoj  ///Quantum number.
							  ) const; ///Calculates splitting.
  
  double GetStrongFineSplitting(unsigned short n,  ///Quantum number.
								unsigned short l, ///Quantum number. 
								int ml,  ///Quantum number.
								int twoms ///Quantum number.
								) const;///Calculates splitting.
  
  double GetWeakZeemanSplitting(unsigned short l,  ///Quantum number.
								unsigned short twoj,  ///Quantum number.
								int twomj,  ///Quantum number.
								double B /// Magnetic field.
								) const;///Calculates splitting.
  
  double GetStrongZeemanSplitting(int ml,  ///Quantum number.
								  int twoms,  ///Quantum number.
								  double B /// Magnetic field.
								  ) const;///Calculates splitting.

  static double GetLandeG(unsigned short twoj,
				   unsigned short l,
				   int twos
				   ) ;

public:
  void SetLowerHysteresisFactor(double value
								);
  
  void SetUpperHysteresisFactor(double value
								);
  
  double GetLowerHysteresisFactor() const;
  double GetUpperHysteresisFactor() const;

private:
  double fieldStrength; ///Contains the field strength to use for the computations.

  double lowerHysteresisFactor; ///Lower hysteresis factor.
  double upperHysteresisFactor; ///Upper hysteresis factor.

  double (*U01Function) (); ///The random function to use to obtain our U01-distribution. MUST be a U01, and initialized.


  static double uniform0to1Random(); ///Failsafe random function. Should not be used...

  static TRandom1 * myFailsafeRandom; ///Failsafe random function, if none is specified.
  ClassDef(rfacFieldRegimeTranslator, 1)
};

#endif
