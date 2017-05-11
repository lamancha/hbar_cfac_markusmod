#ifndef rfacTR_hh
#define rfacTR_hh 1

#include <stdio.h>
#include <string>
#include <vector>

#include "cfacP.h"
#include "cfac.h"
#include "dbase.h"
#include "consts.h"
#include "facFile.hh"
#include "rfacEN.hh"

using namespace std;

class rfacTR : public facFile
{
public:
  rfacTR(FILE * f, //! Pointer to file opened in binary read mode; where the file contains the appropriate data and the pointer is at the correct position. The pointer will NOT be closed by this method and is not used after the constructor call (so you can close it).
	 int swp, //! Tells us if we should swap Endian headers.
	 rfacEN * levels //! Pointer to database of energy records which should correspond.
	  );
  ~rfacTR(); //! Destructor.
  
  const virtual void Print(); //! Print infor about this object.

  const void PrintRecord(unsigned int recordNumber //! Print the record indexed by recordNumber.
		   ); //! Prints the record.
  
  const void PrintHeader(); //! Prints the header.

  const int getLowerLevel(unsigned int recordNumber //! The corresponding record number.
			  ); //! The lower level.

  const int getUpperLevel(unsigned int recordNumber //! The corresponding record number.
			  ); //! The upper level.

  const int getTransitionStrength(unsigned int recordNumber ///! The corresponding record number.
				  ); //! The transition strength.

  const int getNumberOfElectrons(); //! Returns the number of electrons.

  const int getNumberOfTransitions(); //! Returns the number of transitions
  
  const int getGauge(); //! Returns the gauge.
  
  const int getMode(); //! Returns the mode.

  const int getMultipole(); //! Returns the multipole
	  
private:

  void readHeader(FILE * f, //The file pointer.
		  int swp //! Tells us if we should swap Endian headers.
		  ); //Reads the header from the file.
  void readRecords(FILE * f, //The file pointer.
		   int swp //Tells us if we should swap Endian headers.
		   ); //Reads the records from the file.

  void OutOfBoundsCheck(unsigned int recordNumber //!The record number.
			); //Throws exception if number if out of bounds.

  TR_HEADER * myHeader; //The header.
  vector<TR_RECORD *> myRecords; //The records.
  rfacEN * myLevels; //! Pointer to database with energy levels.
};


#endif
