#ifndef QUADRUPLE_H
#define QUADRUPLE_H

#include <TObject.h>

//#include "rfacInterpolatorContainer.hh"
//#include "rfac3DInterpolation.hh"


///My own 4-tupel for the 3D-Interpolation of EField, BField, FieldAngle and DecayRate.

class Quadruple
{
    public:
        Quadruple();
        virtual ~Quadruple();
        Double_t GetEField() { return EField; }
        void SetEField(Double_t val) { EField = val; }
        Double_t GetBField() { return BField; }
        void SetBField(Double_t val) { BField = val; }
        Double_t GetFieldAngle() { return FieldAngle; }
        void SetFieldAngle(Double_t val) { FieldAngle = val; }
        Double_t GetDecayRate() { return DecayRate; }
        void SetDecayRate(Double_t val) { DecayRate = val; }
    protected:
    private:
        Double_t EField;
        Double_t BField;
        Double_t FieldAngle;
        Double_t DecayRate;

   ClassDef(Quadruple, 1)
};

#endif // QUADRUPLE_H
