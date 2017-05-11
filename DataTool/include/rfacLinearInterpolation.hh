#ifndef rfacLinearInterpolation_hh
#define rfacLinearInterpolation_hh 1

#include "TObject.h"
#include "TMatrixD.h"
#include "TVectorD.h"
#include "TDecompSVD.h"


#include <vector>
#include "rfacException.hh"
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

/**This was once a linear interpolator. It still is, but now it actually retains all data points
   and does a fit between them "live". As optimal as possible for both size and other stuff.
   Nowadays, this interpolator only support one dimension, since locating the closest points in more than 1 dimension is a mess.
 */
class rfacLinearInterpolation: public TObject
{
public:
  rfacLinearInterpolation(); ///Default constructor (do not use this unless you make ABSOLUTELY SURE to call ReInitialize afterwards before attempting any other stuff.

  rfacLinearInterpolation(const vector<Double_t> &coordinates, ///Coordinates for the fit.
			  const vector<Double_t> &values ///Values for the fit.
			  ); ///Constructor, see class description for details.

  rfacLinearInterpolation(const vector<pair<Double_t, Double_t> > &data ///The data.
			  ); ///Constructor

  rfacLinearInterpolation(const rfacLinearInterpolation & toCopy
			  ); ///Copy constructor.

  //void PerformFit(vector<vector<Double_t> > coordinates, ///Coordinates for the fit.
  //						      vector<Double_t> values ///Values for the fit.
  //						      ); ///Called by the constructor to perform the actual fit. Uses singular value decomposition (most numerically stable algorithm I think) for this task. Note that no 

  ~rfacLinearInterpolation(); ///Destructor, destroys the object. 
  double Eval(Double_t coordinate ///Coordinates to evaluate at.
	      ) const; ///Evaluate the linear fit at a specific point. This function is O(1).

  vector<pair<Double_t, Double_t> > GetDataPoints() const; ///Returns the data points.

protected:

  vector<pair<Double_t, Double_t> > dataPoints; ///First one is x, second one is y.

  int findClosest(Double_t toFind ///The value to search for.
		  ) const; ///Finds the index of the closest (lower) point through binary search.


  ClassDef(rfacLinearInterpolation, 4)
};

#endif
