#ifndef rfacEN_h
#define rfacEN_h 1

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

#define SIGN(x) ( (x > 0) - (x < 0) ) ///Signum function (for parity)


using namespace std;

//! Contains the records for energy levels.
class rfacEN : public facFile
{
public:
  //!Constructor, used for constructing this file record
  rfacEN(FILE * f, //! Pointer to the file which is opened in binary read mode; where the file contains the appropriate data and the pointer is at the correct position. The pointer will NOT be closed by this method.
	 int swp //! Information about whether we should make an Endian header swap (stored in the file header and should be passed on to this class).
	 );
  ~rfacEN(); //! Destructor.

  const virtual void Print(); //! Print infor about this object.

  const void PrintRecord(unsigned int recordNumber //! Print the record indexed by recordNumber.
		   ); //! Prints the record.
  
  const void PrintHeader(); //! Prints the header.
  
  const long int getPosition(); //! Returns the position in the file.
  const long int getLength(); //! Returns the length of the record (in the file).
  const int getNumberOfElectrons(); //! Returns the number of electrons in this record.
  const int getNumberOfLevels(); //! Returns the number of levels in this record.

  const int getParity(unsigned int recordNumber //! The record number.
		      ); //! Returns the parity (±1)

  const short getN(unsigned int recordNumber ///The record number.
		   ); ///Returns the N.
  const short getL(unsigned int recordNumber /// The record number.
		   ); ///Returns the L.
  const short get2J(unsigned int recordNumber ///The record number.
		    ); ///Returns 2 times J.

  
  const int getAngularMomentumTimesTwo(unsigned int recordNumber //! The record number.
			       ); //! Returns the angular momentum x 2
  const int getIndexOfLevel(unsigned int recordNumber //! The record number.
			    ); //! Returns the index of the level.
  const int getIndexOfBaseLevel(unsigned int recordNumber //! The base level.
				); //! Returns he index of the base level.

  const double getEnergyOfLevel(unsigned int recordNumber //! The record number.
				); //! Returns the energy of the level, in eV.

  const string getComplexName(unsigned int recordNumber //! The record number.
			      ); //! Returns the complex name.

  const string getNonRelativisticConfigurationName(unsigned int recordNumber //! The record number.
						   ); //! Returns the nonrelativistic configuration name.
  const string getRelativisticConfigurationName(unsigned int recordNumber //! The record number.
						); //! Returns the relativistic configuration name.
  
  
  
private:
  void readHeader(FILE * f, //! The file pointer.
		  int swp //! Information about whether we should swap Endian header.
		  ); //! Reads the header from the file.
  void readRecords(FILE * f, //! The file pointer.
		   int swp //! Information about whether we should swap Endian header.
		   ); //! Reads the records from the file.

  void OutOfBoundsCheck(unsigned int recordNumber //!The record number.
			); //! Returns true if record number is within bounds, otherwise returns false AND writes an error message to stderr.

  EN_HEADER * myHeader; //! The header for these records.

  vector<EN_RECORD *> myRecords; //! The records themselves.

};

#endif
