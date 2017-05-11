#ifndef rfacF_h
#define rfacF_h 1

#include <stdio.h>
#include <string>

#include "cfacP.h"
#include "cfac.h"
#include "dbase.h"
#include "consts.h"
#include "facFile.hh"

using namespace std;


//! Contains the file record for the Flexible Atomic Code binary output.
class rfacF : public facFile
{
public:
  //! Constructor, used for constructing the file record.
  rfacF(FILE * f //! Pointer to file opened in binary read mode; where the file contains the appropriate data and the pointer is at the correct position. The pointer will NOT be closed by this method.
	);
  virtual ~rfacF(); //!Destructor.
  const virtual void Print(); //!Print the header to standard output.
  
  const int getMajorVersion(); //! Returns the major version.
  const int getMinorVersion(); //! Returns the minor version.
  const int getReleaseVersion(); //! Returns the release version.
  const int getType(); //! Returns the type.
  const string getSymbol(); //! Returns the symbol.
  const int getNBlocks(); //! Returns the number of blocks (in the data file).
  const int getSwp(); //! Returns a number indicating whether we should swap Endian headers when reading stuff.

private:
  void readHeader(FILE * f //! File pointer.
			); //Reads the header and stores it.

  F_HEADER * myHeader; //The header, for internal storage.
  
  int mySwp ; //! Info about if we should swap Endian headers.
};

#endif
