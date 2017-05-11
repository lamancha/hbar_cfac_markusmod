#ifndef rfacDecayableObject_hh
#define rfacDecayableObject_hh 1

#include <string>
#include <cstdlib>
#include <map>
#include <ctime>

#include <TRandom1.h>

#include "QuantumNumbers.hh"
#include "rfacException.hh"
#include "rfacInterpolation.hh"
#include "GeneralQuantumNumbers.hh"
#include "StrongFieldQuantumNumbers.hh"
#include "rfacFieldRegimeTranslator.hh"
#include <iostream>

using namespace std;


/** As the name says, a decayable object.
    Used mainly as a base class for hbarHydrogenLike in the hbar_gshfs simulation, but also for testing purposes and maybe to produce some neat graphs etc.
 */
class rfacDecayableObject
{
public:
  rfacDecayableObject(double (*_U01Function)() = NULL); ///Constructor.
  virtual ~rfacDecayableObject(); ///Destructor.

  void InitializeDecay(); ///Call before we attempt to do anything decay-ish, but after the quantum numbers has been set.

  void DoStepTime(double timeStep ///The amount of stepping, in seconds, that should be performed.
		); ///Steps the time of the particle, in the particle's reference frame(!) with the amount timeStep seconds, and performs randomized deexcitations accordingly.

  bool SetField(double B = 0, double E = -1, double A = -1); ///New magnetic field
		 ///Sets the fields that the particle experiences. These fields will be valid for the deexcitation calculations until new fields are set. Also triggers field regime translations.

  double GetField() const;

  void SetEnableFieldRegimeTranslations(bool value ///value to set.
										); ///Use this to manually switch of field regime translations. Maybe for testing purpose.

  void SetStateFile(string value ///Value to set.
		    ); ///Sets the quantum state file to use.

  double PeekAtTimeToNextDecay(); ///Peek at the time to next decay.

  void PreloadStates(); ///Instruct the interpolation object to preload states rather than read them every time. Uses more RAM, but should be faster.

  GeneralQuantumNumbers * GetQuantumNumbers();

  void ResetQuantumNumbers(bool strong = false
						   ); ///Call to reset field and quantum numbers to zero. Use when generating a new primary particle without recreating the object.

protected:

  GeneralQuantumNumbers * myQuantumNumbers;

  GeneralQuantumNumbers * decayChannel;

  double GetTimeToNextDecay(); ///Causes a recomputation and returns the time to next decay.
  string currentFilename;

  double B; ///Magnetic field
  double E; ///Electric field
  double A; ///Angle between E- and B-Field
  double TimeToNextDecay; ///Used to keep track of when to decay next.
  double totalDecayRate; ///The total decay rate for the currently chosen decay channel.
  bool enableFieldRegimeTranslations; ///Enable field regime translations? default true.



public:
  bool IsWeakFieldRegime() const;
  bool IsStrongFieldRegime() const;

  unsigned short GetN() const; ///Returns the quantum number n.

  unsigned short GetL() const; ///Returns the quantum number l.

  short GetML() const; /// Returns the quantum number twoj.

  short GetTwoMS() const; ///Returns the quantum number m.

  void SetN(unsigned short value ///Value
	    ); ///Setter

  void SetL(unsigned short value ///Value
	    ); ///Setter

  void SetML(short value ///Value
	       ); ///Setter

  void SetTwoMS(short value ///Value
	    ); ///Setter

  unsigned short GetTwoJ() const; /// Returns the quantum number twoj.

  short GetTwoMJ() const; ///Returns the quantum number m.

  void SetTwoJ(unsigned short value ///Value
	       ); ///Setter

  void SetTwoMJ(short value ///Value
	    ); ///Setter


  void SetLowerHysteresisFactor(double value
								);

  void SetUpperHysteresisFactor(double value
								);

  double GetLowerHysteresisFactor() const;
  double GetUpperHysteresisFactor() const;



private:

  rfacFieldRegimeTranslator * myTranslator; ///Field grid translator.

  rfacInterpolation * myInterpolation; ///Interpolator to use.

  double (*U01Function) (); ///The random function to use to obtain our U01-distribution. MUST be a U01, and initialized.

  static double uniform0to1Random(); ///Failsafe random function. Should not be used...

  static TRandom1 * myFailsafeRandom; ///Failsafe random function, if none is specified.
  ClassDef(rfacDecayableObject, 1)
};


#endif
