///Test of multidim fit. Not in use since electric fields were discarded.

#include "TMultiDimFit.h"

#include <iostream>
using namespace std;


int multidim();


int main()
{
  (void)multidim();
  return 0;
}

int multidim()
{
  TMultiDimFit * fit = new TMultiDimFit(3, TMultiDimFit::kLegendre,"");
  Int_t mPowers[]   = { 3, 3, 3}; /// Not sure what all these parameters do, might need to revise it.
  fit->SetMaxPowers(mPowers);
  fit->SetMaxFunctions(1000);
  fit->SetMaxStudy(1000);
  fit->SetMaxTerms(30);
  fit->SetPowerLimit(2);
  fit->SetMinAngle(10);
  fit->SetMaxAngle(10);
  fit->SetMinRelativeError(.01);
  for(int a = 0; a<5; ++a)
    {
      for(int b = 0; b<5; ++b)
	{
	  for(int c = 0; c<5; ++c)
	    {
	      Double_t temp[3];
	      temp[0]=a;
	      temp[1]=b;
	      temp[2]=c;
	      fit->AddRow(temp, 1*a+2*b+3*c);
	    }
	}
    }
  // Find the parameterization
  fit->FindParameterization();

  Double_t tempq[3] = {122,200,400};
  cout << fit->Eval(tempq) << endl;
}
