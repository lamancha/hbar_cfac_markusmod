#ifndef rfacDB_hh
#define rfacDB_hh 1

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <utility>
#include <algorithm>

#include "rfacEN.hh"
#include "rfacENF.hh"
#include "rfacTR.hh"
#include "rfacTRF.hh"
#include "rfacF.hh"
#include "rfacException.hh"
#include "facFile.hh"

#define OA order.push_back


using namespace std;

class rfacDB
{
public:
  rfacDB(vector<string> filenames, //! The file names of the database files.
	 bool printInfo = false
	 ); //! Constructor.
  ~rfacDB(); //! Destructor.
  vector <rfacF*> getHeaders(); //! Returns the headers.
  vector <facFile *> getData(); //! Returns the date.
  vector <facFile *> getSpecificData(int dataType); //! Returns the specific data.
private:
  vector<rfacF*> headers;
  vector<facFile *> constructed;
  bool verbose;
};

#endif
