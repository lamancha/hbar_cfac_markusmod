#ifndef QuantumNumbers_hh
#define QuantumNumbers_hh 1

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <cstdlib>

#include "TObject.h"
#include "GeneralQuantumNumbers.hh"



using namespace std;

/** Represents four quantum numbers (the unique specifier for an energy level, in the zero field limit).
    Also equals operator of this, etc.
	Note: In strong fields this is no longer valid, and StrongFieldQuantumNumbers has to be used instead. 
	There is a translator class to convert between QuantumNumbers and StrongFieldQuantumNumbers in a stochastic way.
 */
class QuantumNumbers
  : public GeneralQuantumNumbers
{
public:

  QuantumNumbers(unsigned short _n = 1, ///n quantum number.
		 unsigned short _l = 0, ///l quantum number.
		 unsigned short _twoj = 1, ///twoj quantum number.
		 short _twomj = -1///mj quantum number.
		 ); ///Constructor for setting all parameters.

  QuantumNumbers(const QuantumNumbers & toCopy ///toCopy object.
		 ); ///Copy constructor

  ~QuantumNumbers(); /// Destructor.

  void SetQuantumNumbers(const QuantumNumbers & toSet ///the object with quantum numbers to copy.
	   ); ///Copy all quantum numbers from another object into this one.


  unsigned short GetN() const; ///Returns the quantum number n.
  
  unsigned short GetL() const; ///Returns the quantum number l.

  unsigned short GetTwoJ() const; /// Returns the quantum number twoj.

  short GetTwoMJ() const; ///Returns the quantum number m.

  void SetN(unsigned short value ///Value
	    ); ///Setter
  
  void SetL(unsigned short value ///Value
	    ); ///Setter

  void SetTwoJ(unsigned short value ///Value
	       ); ///Setter

  void SetTwoMJ(short value ///Value
	    ); ///Setter

  
  bool ValidateConsistency() const; /// Returns true if the quantum numbers are internally consistent, otherwise false.

  bool operator == (const QuantumNumbers & b ///Standard.
		    ) const; ///Standard comparision operator overloading.
  bool operator < (const QuantumNumbers & b ///Standard.
		   ) const;///Standard comparision operator overloading.
  bool operator > (const QuantumNumbers & b ///Standard.
		   ) const;///Standard comparision operator overloading.
  bool operator <= (const QuantumNumbers & b ///Standard.
		    ) const;///Standard comparision operator overloading.
  bool operator >= (const QuantumNumbers & b ///Standard.
		    ) const;///Standard comparision operator overloading.
  bool operator != (const QuantumNumbers & b ///Standard.
		    ) const;///Standard comparision operator overloading.

  QuantumNumbers & operator++(); ///Standard.

  friend ostream& operator<<(ostream& os, ///Stream.
			     const QuantumNumbers& val ///constant object.
			     ); ///This stuff is used to stream the object to a stream. Quite useful.

  string ToString() const;

  GeneralQuantumNumbers * CreateCopy() const;

  bool Equals(const GeneralQuantumNumbers * value) const;

protected:
  unsigned short n, l, twoj; ///The actual quantum numbers. Unique for a state. Here we consider only s=1/2.
  short twomj;
  ClassDef(QuantumNumbers, 2)
};


#endif
