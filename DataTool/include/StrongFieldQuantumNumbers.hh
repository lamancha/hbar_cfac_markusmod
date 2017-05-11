#ifndef StrongFieldQuantumNumbers_hh
#define StrongFieldQuantumNumbers_hh 1

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <cstdlib>

#include "TObject.h"
#include "GeneralQuantumNumbers.hh"


using namespace std;

/** Represents four quantum numbers (the unique specifier for an energy level, in the strong field limit).
    Also equals operator of this, etc.
	Note: only valid for strong (magnetic) fields, where the spin-orbit coupling can be assumed to be zero.
 */
class StrongFieldQuantumNumbers
  : public GeneralQuantumNumbers
{
public:

  StrongFieldQuantumNumbers(unsigned short _n = 1, ///n quantum number. Same as zero-field.
							unsigned short _l = 0, ///l quantum number. Same as zero-field.
							short _ml = 1,///ml quantum number.
							short _twoms = -1 ///ms quantum number. We know that 2*spin is 1 for hbar, so we don't have an s quantum number.
		 ); ///Constructor for setting all parameters.

  StrongFieldQuantumNumbers(const StrongFieldQuantumNumbers & toCopy ///toCopy object.
		 ); ///Copy constructor

  ~StrongFieldQuantumNumbers(); /// Destructor.

  void SetStrongFieldQuantumNumbers(const StrongFieldQuantumNumbers & toSet ///the object with quantum numbers to copy.
	   ); ///Copy all quantum numbers from another object into this one.


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

  
  bool ValidateConsistency() const; /// Returns true if the quantum numbers are internally consistent, otherwise false.

  bool operator == (const StrongFieldQuantumNumbers & b ///Standard.
		    ) const; ///Standard comparision operator overloading.
  bool operator < (const StrongFieldQuantumNumbers & b ///Standard.
		   ) const;///Standard comparision operator overloading.
  bool operator > (const StrongFieldQuantumNumbers & b ///Standard.
		   ) const;///Standard comparision operator overloading.
  bool operator <= (const StrongFieldQuantumNumbers & b ///Standard.
		    ) const;///Standard comparision operator overloading.
  bool operator >= (const StrongFieldQuantumNumbers & b ///Standard.
		    ) const;///Standard comparision operator overloading.
  bool operator != (const StrongFieldQuantumNumbers & b ///Standard.
		    ) const;///Standard comparision operator overloading.

  StrongFieldQuantumNumbers & operator++(); ///Standard.

  friend ostream& operator<<(ostream& os, ///Stream.
			     const StrongFieldQuantumNumbers& val ///constant object.
			     ); ///This stuff is used to stream the object to a stream. Quite useful.

  string ToString() const;

  GeneralQuantumNumbers * CreateCopy() const;

  bool Equals(const GeneralQuantumNumbers * value) const;



protected:
  unsigned short n, l; ///Quantum numbers.
  short ml, twoms; ///Quantum numbers. Here we consider only s=1/2.
  ClassDef(StrongFieldQuantumNumbers, 1)
};


#endif
