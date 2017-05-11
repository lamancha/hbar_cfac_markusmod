#ifndef rfacFieldGridPoint_hh
#define rfacFieldGridPoint_hh 1

#include <string>
#include <iostream>
#include <sstream>
#include "TMath.h"

#include "TObject.h"

#define EPS 1E-7

using namespace std;


///A parameter point in the field grid (E, B, Angle).
class rfacFieldGridPoint: public TObject
{
public:
  double E, B, Angle; ///Self-evident.
  rfacFieldGridPoint(double _E = 0, ///Electric field. 
		     double _B = 0, ///Magnetic field. 
		     double _Angle = 0 ///Field angle. 
		     ); ///Constructor.
  ~rfacFieldGridPoint(); ///Destructor.
  bool operator == (const rfacFieldGridPoint & b ///Standard.
		    ) const; ///Standard comparision operator overloading.
  bool operator < (const rfacFieldGridPoint & b ///Standard.
		   ) const;///Standard comparision operator overloading.
  bool operator > (const rfacFieldGridPoint & b ///Standard.
		   ) const;///Standard comparision operator overloading.
  bool operator <= (const rfacFieldGridPoint & b ///Standard.
		    ) const;///Standard comparision operator overloading.
  bool operator >= (const rfacFieldGridPoint & b ///Standard.
		    ) const;///Standard comparision operator overloading.
  bool operator != (const rfacFieldGridPoint & b ///Standard.
		    ) const;///Standard comparision operator overloading.

  friend ostream& operator<<(ostream& os, ///Stream.
			     const rfacFieldGridPoint& val ///constant object.
			     ); ///This stuff is used to stream the object to a stream. Quite useful.

  string ToString() const;
  static bool double_equal(const double & d1, const double & d2);

  ClassDef(rfacFieldGridPoint, 1)
};

#endif
