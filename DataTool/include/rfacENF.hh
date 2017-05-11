#ifndef rfacENF_hh
#define rfacENF_hh 1


#include "globaldef.hh"

#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>


#include "cfacP.h"
#include "cfac.h"
#include "dbase.h"
#include "consts.h"

#include "facFile.hh"
#include "rfacException.hh"


using namespace std;

//! Contains the records for energy levels.
class rfacENF : public facFile
{
public:
  //!Constructor, used for constructing this file record
  rfacENF(FILE * f, //! Pointer to the file which is opened in binary read mode; where the file contains the appropriate data and the pointer is at the correct position. The pointer will NOT be closed by this method.
	 int swp //! Information about whether we should make an Endian header swap (stored in the file header and should be passed on to this class).
	 );
  ~rfacENF(); //! Destructor.

  const virtual void Print(); //! Print infor about this object.

  const void PrintRecord(unsigned int recordNumber //! Print the record indexed by recordNumber.
		   ); //! Prints the record.
  
  const void PrintHeader(); //! Prints the header.
  
  const long int getPosition(); //! Returns the position in the file.
  const long int getLength(); //! Returns the length of the record (in the file).
  const int getNumberOfElectrons(); //! Returns the number of electrons in this record.
  const int getNumberOfLevels(); //! Returns the number of levels in this record.

  const double getBField(); //Return the B field.

  const double getEField(); //!Returns the E field.

  const double getFieldAngle(); //Returns the angle between the E-field and B-field

  const int getLevelIndex(unsigned int recordNumber //! The number of the record.
				     ); //!Returns the initial level.

  const double getEnergy(unsigned int recordNumber //! The record number.
			       ); //! //!Returns the energy in eV.
  
  const int getPBasis(unsigned int recordNumber //! The record number.
			       ); //!Returns the pbasis.

  const int getM(unsigned int recordNumber //! The record number.
		 );///Return M (quantum number.)

  const int getParity(unsigned int recordNumber //! The parity.
		      ); ///Returns the parity.

  const int getInitialLevel(unsigned int recordNumber //! The record number.
			    ); /// Return initial level.
  
  
private:
  void readHeader(FILE * f, //! The file pointer.
		  int swp //! Information about whether we should swap Endian header.
		  ); //! Reads the header from the file.
  void readRecords(FILE * f, //! The file pointer.
		   int swp //! Information about whether we should swap Endian header.
		   ); //! Reads the records from the file.

  void OutOfBoundsCheck(unsigned int recordNumber //!The record number.
			); //! Throws an exception if the recordNumber is out of bounds.

  ENF_HEADER * myHeader; //! The header for these records.

  vector<ENF_RECORD *> myRecords; //! The records themselves.

};

#endif
