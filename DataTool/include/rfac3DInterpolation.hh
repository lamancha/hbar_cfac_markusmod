#ifndef rfac3DInterpolation_hh
#define rfac3DInterpolation_hh 1

#include "TObject.h"
#include "TMatrixD.h"
#include "TVectorD.h"
#include "TDecompSVD.h"
#include "Quadruple.hh"

#include <vector>
#include "rfacException.hh"
#include <utility>
#include <iostream>
#include <algorithm>
#include "rfacFieldGridContainer.hh"

using namespace std;

/**Necessary 3D Interpolator for Radiative Decay Data with B-Field, E-Field and Angle.
 */

class rfac3DInterpolation: public TObject
{
public:
  rfac3DInterpolation(); ///Default constructor (do not use this unless you make ABSOLUTELY SURE to call ReInitialize afterwards before attempting any other stuff.
  rfac3DInterpolation(vector<Quadruple> &data); ///Constructor

  rfac3DInterpolation(const rfac3DInterpolation &toCopy); ///Copy constructor.

 ~rfac3DInterpolation(); ///Destructor, destroys the object.

  static void SetGridContainer(rfacFieldGridContainer* GridContainer){myGridContainer = GridContainer;} /// Whether all EField, BField and FieldAngle is used,
                                                         /// then 3DInterpolator

  double Eval(Double_t EField, Double_t BField, Double_t FieldAngle); ///Evaluate the decay Rate for arbitrary Grid Point in the
                                          ///(EField,BField,FieldAngle) grid via Trilinear Interpolation

  vector<Quadruple> CompleteData;

protected:

  vector<Quadruple> CompleteGrid(vector<Quadruple> &data, rfacFieldGridContainer* myGridContainer);

  static rfacFieldGridContainer* myGridContainer; ///we receive from this the whole grid, how it should be

  static const double Epsilon; ///static constant to compare double values for grid information, defined in .cc

private:
    double DeltaE;
    double DeltaB;
    double DeltaAngle;

    bool Compare2(Double_t a, Double_t b);   ///to compare if two doubles are the same

    Double_t LinearInterpolator(Double_t func0, Double_t func1, Double_t weight); ///http://en.wikipedia.org/wiki/Trilinear_interpolation

    ClassDef(rfac3DInterpolation, 4)
};

#endif
