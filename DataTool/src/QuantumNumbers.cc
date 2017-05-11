#include "QuantumNumbers.hh"

ClassImp(QuantumNumbers)

QuantumNumbers::QuantumNumbers(unsigned short _n, unsigned short _l, unsigned short _twoj, short _twomj)
:n(_n), l(_l), twoj(_twoj), twomj(_twomj)
{ 

}

QuantumNumbers::QuantumNumbers(const QuantumNumbers & toCopy)
{
  SetQuantumNumbers(toCopy);
}

QuantumNumbers::~QuantumNumbers()
{

}

void QuantumNumbers::SetQuantumNumbers(const QuantumNumbers & toSet)
{
  n=toSet.n;
  l=toSet.l;
  twomj=toSet.twomj;
  twoj=toSet.twoj;
}

unsigned short QuantumNumbers::GetN() const
{
  return n;
}
  
unsigned short QuantumNumbers::GetL() const
{
  return l;
}

unsigned short QuantumNumbers::GetTwoJ() const
{
  return twoj;
}

short QuantumNumbers::GetTwoMJ() const
{
  return twomj;
}

void QuantumNumbers::SetN(unsigned short value)
{
  n = value;
}
  
void QuantumNumbers::SetL(unsigned short value)
{
  l = value;
}

void QuantumNumbers::SetTwoJ(unsigned short value)
{
  twoj = value;
}

void QuantumNumbers::SetTwoMJ(short value)
{
  twomj = value;
}

QuantumNumbers & QuantumNumbers::operator++()
{
  ///Can we increase twomj?
  if(abs(twomj+2)<=twoj)
    {
      twomj = twomj + 2;
      return *this;
    }
  
  ///Can we increase twoj?
  if(twoj + 1 == 2*l )
    {
      twoj = 2*l + 1;
      twomj = -1*twoj;
      return *this;
    }
  ///Can we increase l?
  if(l<n-1)
    {
      ++l;
      twoj=2*l-1;
      twomj = -1*twoj;
      return *this;
    }

  ///If nothing else works, increase n.
  ++n;
  l=0;
  twoj=1;
  twomj=-1;
  return *this;
}



bool QuantumNumbers::operator == (const QuantumNumbers & b) const
{
  return (b.n==n && b.l==l && b.twoj == twoj && b.twomj == twomj);
}

bool QuantumNumbers::operator < (const QuantumNumbers & b) const
{
  if(b.n<n)
    return false;
  else if(b.n>n)
    return true;
  if(b.l<l)
    return false;
  else if(b.l > l)
    return true;
  if(b.twoj < twoj)
    return false;
  else if(b.twoj > twoj)
    return true;
  if(b.twomj < twomj)
    return false;
  else if(b.twomj > twomj)
    return true;
  return false;
}

bool QuantumNumbers::operator > (const QuantumNumbers & b) const
{
  if(b.n>n)
    return true;
  else if(b.n<n)
    return false;
  if(b.l>l)
    return true;
  else if(b.l < l)
    return false;
  if(b.twoj > twoj)
    return true;
  else if(b.twoj < twoj)
    return false;
  if(b.twomj > twomj)
    return true;
  else if(b.twomj < twomj)
    return false;
  return false;
}

bool QuantumNumbers::operator >= (const QuantumNumbers & b) const
{
  return *this>b || *this==b;
}


bool QuantumNumbers::operator <= (const QuantumNumbers & b) const
{
  return *this<b || *this==b;
}


bool QuantumNumbers::operator != (const QuantumNumbers & b) const
{
  return !((*this)==b);
}


bool QuantumNumbers::ValidateConsistency() const
{
  if(l>=n)
    return false;
  if(twoj%2==0)
    return false;
  if((twoj-1)/2!= l && (twoj+1)/2!=l)
    return false;
  if(abs(twomj)>twoj)
    return false;
  if(twomj%2==0)
    return false;
  return true;
}

ostream& operator<<(ostream& os, const QuantumNumbers& val)
{
  os << "n=" << val.n << " l=" << val.l << " j=" << val.twoj << "/2 m_j=" << val.twomj << "/2 ";
  if(val.ValidateConsistency())
    os << "[OK] ";
  else
    os << "[ERR]";
  return os;
}

string QuantumNumbers::ToString() const
{
  stringstream ss;
  ss << *this;
  return ss.str();
}

GeneralQuantumNumbers * QuantumNumbers::CreateCopy() const
{
  return new QuantumNumbers(*this);
}


bool QuantumNumbers::Equals(const GeneralQuantumNumbers * value) const
{
  if(const QuantumNumbers * other = dynamic_cast<const QuantumNumbers *>(value))
	{
	  return *other == *this;
	}
  return false;
}

