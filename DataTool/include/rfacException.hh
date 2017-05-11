#include <exception>
#include <string>

#include "TObject.h"

#ifndef rfacException_hh
#define rfacException_hh 1

using namespace std;

class rfacException : public exception, public TObject
{
  
private:
  string msg; ///  The reason of the exception to be thrown.

public:
  rfacException(string m="exception!" /// The description of the reason for the exception to be thrown.
		    ); /// Constructor.

  ~rfacException() throw(); /// Destructor.
  const char* what() const throw(); /// Retrieves the reason of the exception.

  ClassDef(rfacException, 1)
};

#endif
