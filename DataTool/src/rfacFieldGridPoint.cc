#include "rfacFieldGridPoint.hh"

ClassImp(rfacFieldGridPoint)

rfacFieldGridPoint::rfacFieldGridPoint(double _E, double _B, double _Angle)
  :E(_E), B(_B), Angle(_Angle)
{

}

rfacFieldGridPoint::~rfacFieldGridPoint()
{

}

bool rfacFieldGridPoint::double_equal(const double &d1, const double &d2)
{
  return ((TMath::Abs(d1-d2)/TMath::Abs(d1+d2)) < EPS);
}


bool rfacFieldGridPoint::operator == (const rfacFieldGridPoint & b) const
{
  return double_equal(E, b.E) && double_equal(B, b.B) && double_equal(Angle, b.Angle);
}

bool rfacFieldGridPoint::operator < (const rfacFieldGridPoint & b) const
{
  if(!double_equal(E, b.E))
    {
      if(E>b.E)
	return false;
      else if(E < b.E)
	return true;
    }
  if(!double_equal(B, b.B))
    {
      if(B>b.B)
	return false;
      else if(B < b.B)
	return true;
    }
  if(!double_equal(Angle, b.Angle))
    {
      if(Angle>b.Angle)
	return false;
      else if(Angle < b.Angle)
	return true;
    }
  return false;
}

bool rfacFieldGridPoint::operator > (const rfacFieldGridPoint & b) const
{
  return !((*this<b) || (*this==b));
}

bool rfacFieldGridPoint::operator >= (const rfacFieldGridPoint & b) const
{
  return *this>b || *this==b;
}


bool rfacFieldGridPoint::operator <= (const rfacFieldGridPoint & b) const
{
  return *this<b || *this==b;
}


bool rfacFieldGridPoint::operator != (const rfacFieldGridPoint & b) const
{
  return !((*this)==b);
}


ostream& operator<<(ostream& os, const rfacFieldGridPoint& val)
{
  os << "B= " << val.B << " E=" << val.E << " Angle=" << val.Angle << ".";
  return os;
}

string rfacFieldGridPoint::ToString() const
{
  stringstream ss;
  ss << *this;
  return ss.str();
}
