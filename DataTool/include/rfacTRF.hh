#ifndef rfacTRF_hh
#define rfacTRF_hh 1

#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>

#include "cfacP.h"
#include "cfac.h"
#include "dbase.h"
#include "consts.h"
#include "facFile.hh"
#include "rfacENF.hh"
#include "globaldef.hh"

using namespace std;

class rfacTRF : public facFile
{
public:
  rfacTRF(FILE * f, //! Pointer to file opened in binary read mode; where the file contains the appropriate data and the pointer is at the correct position. The pointer will NOT be closed by this method and is not used after the constructor call (so you can close it).
	  int swp, //! Tells us if we should swap Endian headers.
	  rfacENF * levels //Levels.
	  );

  ~rfacTRF(); //! Destructor.
  
  const virtual void Print(); //! Print infor about this object.

  const void PrintRecord(unsigned int recordNumber //! Print the record indexed by recordNumber.
		   ); //! Prints the record.
  
  const void PrintHeader(); //! Prints the header.

  const int getNumberOfElectrons(); //! Returns the number of electrons.

  const int getNumberOfTransitions(); //! Returns the number of transitions
  
  const int getGauge(); //! Returns the gauge.
  
  const int getMode(); //! Returns the mode.

  const int getMultipole(); //! Returns the multipole
  
  const double getEField(); //! Returns the E field

  const double getBField(); //! Returns the B field

  const double getFieldAngle(); //! Returns the field angle.

  const int getLowerLevel(unsigned int recordNumber //! The corresponding record number.
			  ); //! The lower level.

  const int getUpperLevel(unsigned int recordNumber //! The corresponding record number.
			  ); //! The upper level.

  const vector<float> getTransitionStrength(unsigned int recordNumber ///! The corresponding record number.
				  ); //! The transition strength.
	  
private:

  void readHeader(FILE * f, //The file pointer.
		  int swp //! Tells us if we should swap Endian headers.
		  ); //! Reads the header from the file.
  void readRecords(FILE * f, //! The file pointer.
		   int swp //! Tells us if we should swap Endian headers.
		   ); //! Reads the records from the file.

  void OutOfBoundsCheck(unsigned int recordNumber //!The record number.
			); //! Throws an exception if recordNumber is out of bounds.

  TRF_HEADER * myHeader; //! The header.
  vector<TRF_RECORD *> myRecords; //! The records.
  vector< vector<float> > myFieldStrengths; //! Easier accessible form of field strengths in the records.
  rfacENF * myLevels; //! Levels associated with this transition.
};


#endif
