#include "rfac3DInterpolation.hh"

ClassImp(rfac3DInterpolation)

rfacFieldGridContainer* rfac3DInterpolation::myGridContainer = NULL;

rfac3DInterpolation::rfac3DInterpolation()
{

}

rfac3DInterpolation::~rfac3DInterpolation()
{

}

const double rfac3DInterpolation::Epsilon = 0.001;

rfac3DInterpolation::rfac3DInterpolation(vector<Quadruple> &data)
{

  CompleteData = CompleteGrid(data, myGridContainer);
/*
  cout << "-------------------------" << endl;
  cin.ignore();
*/

}

rfac3DInterpolation::rfac3DInterpolation(const rfac3DInterpolation& toCopy)
{
  CompleteData = toCopy.CompleteData;
}

double rfac3DInterpolation::Eval(Double_t EField, Double_t BField, Double_t FieldAngle)
{    ///http://en.wikipedia.org/wiki/Trilinear_interpolation

  vector<Quadruple>::iterator IndexDelta = CompleteData.end()-2;///At this Pos. the Grid Information is stored
  Double_t DeltaB     = IndexDelta->GetBField();  ///Grid discretization
  Double_t DeltaE     = IndexDelta->GetEField();
  Double_t DeltaAngle = IndexDelta->GetFieldAngle();

  vector<Quadruple>::iterator IndexDelta2 = CompleteData.end()-1;///At this Pos. the Grid Information is stored
  int NumberB     = IndexDelta2->GetBField()+Epsilon;  ///Number of grid points
  int NumberE     = IndexDelta2->GetEField()+Epsilon;  ///Attention in every double to int issue you need epsilon to avoid wrong rounding
  int NumberA     = IndexDelta2->GetFieldAngle()+Epsilon;

  int IndexEint = 0;
  int IndexBint = 0;
  int IndexAint = 0;

  while(DeltaE*IndexEint < (EField+Epsilon))
  {
      IndexEint++;
  }

  while(DeltaB*IndexBint < (BField+Epsilon))
  {
      IndexBint++;
  }

  while(DeltaAngle*IndexAint < (FieldAngle+Epsilon))
  {
      IndexAint++;
  }

  IndexEint=IndexEint-1;
  IndexBint=IndexBint-1;
  IndexAint=IndexAint-1;

  vector<Quadruple>::iterator StartInd = CompleteData.begin();///StartInd points to first element
  ///VXYZ with X for Angle, Y for BField, Z for EField
  vector<Quadruple>::iterator V000 = StartInd+IndexEint*NumberB*NumberE+IndexBint*NumberA+IndexAint; ///Cubic Corner 000 (Angle/BField/EField)
  vector<Quadruple>::iterator V100 = StartInd+IndexEint*NumberB*NumberE+IndexBint*NumberA+IndexAint+1; ///100
  vector<Quadruple>::iterator V010 = StartInd+IndexEint*NumberB*NumberE+IndexBint*NumberA+IndexAint+NumberA; ///010
  vector<Quadruple>::iterator V110 = StartInd+IndexEint*NumberB*NumberE+IndexBint*NumberA+IndexAint+NumberA+1; ///110
  vector<Quadruple>::iterator V001 = StartInd+IndexEint*NumberB*NumberE+IndexBint*NumberA+IndexAint+NumberA*NumberB; ///001
  vector<Quadruple>::iterator V101 = StartInd+IndexEint*NumberB*NumberE+IndexBint*NumberA+IndexAint+NumberA*NumberB+1; ///101
  vector<Quadruple>::iterator V011 = StartInd+IndexEint*NumberB*NumberE+IndexBint*NumberA+IndexAint+NumberA*NumberB+NumberA; ///011
  vector<Quadruple>::iterator V111 = StartInd+IndexEint*NumberB*NumberE+IndexBint*NumberA+IndexAint+NumberA*NumberB+NumberA+1; ///111

  Double_t Xd = (FieldAngle - V000->GetFieldAngle())/(V100->GetFieldAngle()-V000->GetFieldAngle());
  Double_t Yd = (BField - V000->GetBField())/(V010->GetBField() - V000->GetBField());
  Double_t Zd = (EField - V000->GetEField())/(V101->GetEField() - V000->GetEField());
/*
  cout << "Xd:" << Xd << " Yd:"<< Yd << " Zd:" << Zd << endl;

  cout << "V000_E: " << V000->GetEField() << "B: " << V000->GetBField() << "A: " << V000->GetFieldAngle() << "DR: " << V000->GetDecayRate() << endl;
  cout << "V100_E: " << V100->GetEField() << "B: " << V100->GetBField() << "A: " << V100->GetFieldAngle() << "DR: " << V100->GetDecayRate() << endl;
  cout << "V010_E: " << V010->GetEField() << "B: " << V010->GetBField() << "A: " << V010->GetFieldAngle() << "DR: " << V010->GetDecayRate() << endl;
  cout << "V110_E: " << V110->GetEField() << " B: " << V110->GetBField() << " A: " << V110->GetFieldAngle() << " DR: " << V110->GetDecayRate() << endl;
  cout << "V001_E: " << V001->GetEField() << " B: " << V001->GetBField() << " A: " << V001->GetFieldAngle() << " DR: " << V001->GetDecayRate() << endl;
  cout << "V101_E: " << V101->GetEField() << " B: " << V101->GetBField() << " A: " << V101->GetFieldAngle() << " DR: " << V101->GetDecayRate() << endl;
  cout << "V011_E: " << V011->GetEField() << " B: " << V011->GetBField() << " A: " << V011->GetFieldAngle() << " DR: " << V011->GetDecayRate() << endl;
  cout << "V111_E: " << V111->GetEField() << " B: " << V111->GetBField() << " A: " << V111->GetFieldAngle() << "DR: " << V111->GetDecayRate() << endl;
  cout << "-----------------------"; */
  ///cin.ignore();

  Double_t C00 = LinearInterpolator(V000->GetDecayRate(),V100->GetDecayRate(),Xd);
  Double_t C10 = LinearInterpolator(V010->GetDecayRate(),V110->GetDecayRate(),Xd);
  Double_t C01 = LinearInterpolator(V001->GetDecayRate(),V101->GetDecayRate(),Xd);
  Double_t C11 = LinearInterpolator(V011->GetDecayRate(),V111->GetDecayRate(),Xd);

  Double_t C0 = LinearInterpolator(C00,C10,Yd);
  Double_t C1 = LinearInterpolator(C01,C11,Yd);

  Double_t C = LinearInterpolator(C0,C1,Zd);

  return C;
}

Double_t rfac3DInterpolation::LinearInterpolator(Double_t func0, Double_t func1, Double_t weight)
{
    return func0*(1-weight)+func1*weight;
}

///Here we complete and sort complete DataSet, because grid points below the cutoff are missing completely and this is for
///trilinear interpolation very bad! Additionally the incoming data is unsorted.
vector<Quadruple> rfac3DInterpolation::CompleteGrid(vector<Quadruple> &data, rfacFieldGridContainer* myGridContainer)
{
  vector<Quadruple> Result;
  const double zero = 0;

  for(rfacFieldGridContainer::iterator it = (*myGridContainer).begin(); it != (*myGridContainer).end(); ++it)
  {
    bool   Flag = false;     ///Flag if Datapoint were found
    Double_t BFieldGrid     = it->B;
    Double_t EFieldGrid     = it->E;
    Double_t FieldAngleGrid = it->Angle;

    for(vector<Quadruple>::iterator ip = data.begin(); ip!=data.end(); ++ip)
    {
      Double_t BFielddata     = ip->GetBField();
      Double_t EFielddata     = ip->GetEField();
      Double_t FieldAngledata = ip->GetFieldAngle();

        if(Compare2(BFieldGrid,BFielddata)&&Compare2(EFieldGrid,EFielddata)&&Compare2(FieldAngleGrid,FieldAngledata))
        {                           ///if DataPoint was found -> Take it and build vector
          Result.push_back((*ip));
          Flag = true;
        }
    }
    if(Flag!=true) ///if DataPoint not found -> make DataPoint with DecayRate = 0
      {
      Quadruple* myQuadruple = new Quadruple();

      myQuadruple->SetBField(it->B);
      myQuadruple->SetEField(it->E);
      myQuadruple->SetFieldAngle(it->Angle);
      myQuadruple->SetDecayRate(zero);
      Result.push_back(*myQuadruple);

      delete myQuadruple;
      }
  }

/// ---------- Evaluate mesh size of the grid in each dimension (DeltaB, DeltaE, DeltaAngle) START--------------
  vector<Quadruple>::iterator it = Result.begin();

  DeltaB = 0;
  DeltaE = 0;
  DeltaAngle = 0;
  bool BFlag = false;
  bool EFlag = false;
  bool AFlag = false;

  while(it!=Result.end()&&BFlag==false) /// For this iterate and look if there is a direct change, if so then save Delta
  {                                     /// If delta found, break up and go to EField
    Double_t BField1 = 0;
    Double_t BField2 = 0;
    BField1 = it->GetBField();
    it++;
    BField2 = it->GetBField();
    if((BField2-BField1) > Epsilon)  /// To avoid rounding errors a limit of Epsilon is used (no grid will be that fine)
    {
      DeltaB = BField2-BField1;
      BFlag = true;
    }
  }

  while(it!=Result.end()&&EFlag==false) /// Evaluate Delta of EField Grid
  {
    Double_t EField1 = 0;
    Double_t EField2 = 0;
    EField1 = it->GetEField();
    it++;
    EField2 = it->GetEField();
    if((EField2-EField1) > Epsilon)
    {
      DeltaE = EField2-EField1;
      EFlag = true;
    }
  }

    while(it!=Result.end()&&AFlag==false) /// Evaluate Delta of Angle
  {
    Double_t Angle1 = 0;
    Double_t Angle2 = 0;
    Angle1 = it->GetFieldAngle();
    it++;
    Angle2 = it->GetFieldAngle();
    if((Angle2-Angle1) > Epsilon)
    {
      DeltaAngle = Angle2-Angle1;
      AFlag = true;
    }
  }

  Quadruple* myQuadruple = new Quadruple();
  myQuadruple->SetBField(DeltaB);
  myQuadruple->SetEField(DeltaE);
  myQuadruple->SetFieldAngle(DeltaAngle);
  myQuadruple->SetDecayRate(zero);
  Result.push_back(*myQuadruple);  ///Put the mesh size on the last position of the Result vector
  delete myQuadruple;

///-----------------------------Evaluate Deltas END ------------------///
///----------Evaluate the number of Grid Points for each value (E,B,Angle) START---------------//

  Double_t BMax = 0;
  Double_t EMax = 0;
  Double_t AMax = 0;
  for(vector<Quadruple>::iterator ip = Result.begin(); ip!=Result.end(); ++ip)
  {
      if (ip->GetBField() > BMax) BMax = ip->GetBField();
      if (ip->GetEField() > EMax) EMax = ip->GetEField();
      if (ip->GetFieldAngle() > AMax) AMax = ip->GetFieldAngle();
  }

  Double_t NumberB = BMax/DeltaB + 1;
  Double_t NumberE = EMax/DeltaE + 1;
  Double_t NumberA = AMax/DeltaAngle + 1;

  myQuadruple = new Quadruple();
  myQuadruple->SetBField(NumberB);
  myQuadruple->SetEField(NumberE);
  myQuadruple->SetFieldAngle(NumberA);
  myQuadruple->SetDecayRate(zero);
  Result.push_back(*myQuadruple);  ///Put the number of gridpoints of each variable on the last position of the Result vector
  delete myQuadruple;


///----------Evaluate the number of Grid Points for each value (E,B,Angle) START---------------//
///----------Error message if the minimum value is not zero------------------------------///
  Double_t BMin = 1;
  Double_t EMin = 1;
  Double_t AMin = 1;
  for(vector<Quadruple>::iterator ip = Result.begin(); ip!=Result.end(); ++ip)
  {
      if (ip->GetBField() < BMin) BMin = ip->GetBField();
      if (ip->GetEField() < EMin) EMin = ip->GetEField();
      if (ip->GetFieldAngle() < AMin) AMin = ip->GetFieldAngle();
  }
  if(BMin>0||EMin>0||AMin>0)
  {
    throw rfacException("EField,BField and FieldAngle have to start from 0. rfac3DInterpolation has to be modified if not!");
  }
  ///----------Error message if the minimum value is not zero------------------------------///

  return Result;
}

bool rfac3DInterpolation::Compare2(Double_t a, Double_t b) ///To compare two double values
{
   return fabs(a-b) < Epsilon;
}



