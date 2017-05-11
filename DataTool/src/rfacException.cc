#include "rfacException.hh"

ClassImp(rfacException)

rfacException::rfacException(string m)
  :msg(m)
{

}

rfacException::~rfacException() throw()
{

}

const char* rfacException::what() const throw()
{
  return msg.c_str();
}
