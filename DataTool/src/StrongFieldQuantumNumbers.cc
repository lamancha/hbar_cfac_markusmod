#include "StrongFieldQuantumNumbers.hh"

ClassImp(StrongFieldQuantumNumbers)

StrongFieldQuantumNumbers::StrongFieldQuantumNumbers(unsigned short _n, unsigned short _l, short _ml, short _twoms)
  :n(_n), l(_l), ml(_ml), twoms(_twoms)
{ 

}

StrongFieldQuantumNumbers::StrongFieldQuantumNumbers(const StrongFieldQuantumNumbers & toCopy)
{
  SetStrongFieldQuantumNumbers(toCopy);
}

StrongFieldQuantumNumbers::~StrongFieldQuantumNumbers()
{

}

void StrongFieldQuantumNumbers::SetStrongFieldQuantumNumbers(const StrongFieldQuantumNumbers & toSet)
{
  n=toSet.n;
  l=toSet.l;
  ml = toSet.ml;
  twoms = toSet.twoms;
}

unsigned short StrongFieldQuantumNumbers::GetN() const
{
  return n;
}
  
unsigned short StrongFieldQuantumNumbers::GetL() const
{
  return l;
}

short StrongFieldQuantumNumbers::GetML() const
{
  return ml;
}

short StrongFieldQuantumNumbers::GetTwoMS() const
{
  return twoms;
}

void StrongFieldQuantumNumbers::SetN(unsigned short value)
{
  n = value;
}
  
void StrongFieldQuantumNumbers::SetL(unsigned short value)
{
  l = value;
}
  
void StrongFieldQuantumNumbers::SetML(short value)
{
  ml = value;
}

void StrongFieldQuantumNumbers::SetTwoMS(short value)
{
  twoms = value;
}


StrongFieldQuantumNumbers & StrongFieldQuantumNumbers::operator++()
{
  ///Can we increase ms?
  if( twoms == -1 )
	{
	  twoms = 1;
	  return *this;
	}


  ///Can we increase ml?
  if( abs(ml + 1) <= l )
	{
	  ++ml;
	  twoms = -1;
	  return *this;
	}

  ///Can we increase l?

  if(l<n-1)
    {
      l=l+1;
	  ml = -1*l;
	  twoms = -1;
      return *this;
    }

  ///If nothing else, increase n.
  n=n+1;
  l=0;
  twoms = -1;
  ml = 0;
  return *this;
}



bool StrongFieldQuantumNumbers::operator == (const StrongFieldQuantumNumbers & b) const
{
  return (b.n == n && b.l == l && b.ml == ml && b.twoms == twoms);
}

bool StrongFieldQuantumNumbers::operator < (const StrongFieldQuantumNumbers & b) const
{
  if(b.n<n)
    return false;
  else if(b.n>n)
    return true;
  if(b.l<l)
    return false;
  else if(b.l > l)
    return true;
  if(b.ml < ml)
    return false;
  else if(b.ml > ml)
    return true;
  if(b.twoms < twoms)
    return false;
  else if(b.twoms > twoms)
    return true;
  return false;
}

bool StrongFieldQuantumNumbers::operator > (const StrongFieldQuantumNumbers & b) const
{
  if(b.n>n)
    return true;
  else if(b.n<n)
    return false;
  if(b.l>l)
    return true;
  else if(b.l < l)
    return false;
  if(b.ml > ml)
    return true;
  else if(b.ml < ml)
    return false;
  if(b.twoms > twoms)
    return true;
  else if(b.twoms < twoms)
    return false;
  return false;
}

bool StrongFieldQuantumNumbers::operator >= (const StrongFieldQuantumNumbers & b) const
{
  return *this>b || *this==b;
}


bool StrongFieldQuantumNumbers::operator <= (const StrongFieldQuantumNumbers & b) const
{
  return *this<b || *this==b;
}


bool StrongFieldQuantumNumbers::operator != (const StrongFieldQuantumNumbers & b) const
{
  return !((*this)==b);
}


bool StrongFieldQuantumNumbers::ValidateConsistency() const
{
  if(l>=n)
    return false;
  if(abs(ml) > l)
	return false;
  if(twoms != 1 && twoms != -1)
    return false;
  return true;
}

ostream& operator<<(ostream& os, const StrongFieldQuantumNumbers& val)
{
  os << "n=" << val.n << " l=" << val.l << " ml=" << val.ml << " m_s=" << val.twoms << "/2 ";
  if(val.ValidateConsistency())
    os << "[OK] ";
  else
    os << "[ERR]";
  return os;
}

string StrongFieldQuantumNumbers::ToString() const
{
  stringstream ss;
  ss << *this;
  return ss.str();
}


GeneralQuantumNumbers * StrongFieldQuantumNumbers::CreateCopy() const
{
  return new StrongFieldQuantumNumbers(*this);
}


bool StrongFieldQuantumNumbers::Equals(const GeneralQuantumNumbers * value) const
{
  if(const StrongFieldQuantumNumbers * other = dynamic_cast<const StrongFieldQuantumNumbers *>(value))
	{
	  return *other == *this;
	}
  return false;
}

