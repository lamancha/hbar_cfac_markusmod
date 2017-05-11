#ifndef rfacEssentialDataReader_hh
#define rfacEssentialDataReader_hh 1

#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sys/types.h>
#include <sstream>
#include <list>
#include <queue>

#include <dirent.h>

#include "VerbosePrinter.hh"
#include "VerbosePrinterEventEnabled.hh"
#include "rfacEssentialData.hh"
#include "rfacException.hh"
#include "rfacDB.hh"
#include "facFile.hh"
#include "rfacTRF.hh"
#include "rfacENF.hh"
#include "rfacEN.hh"
#include "MultiTasker.hpp"
#include "QuantumNumbers.hh"

#include <iostream>
#include <cmath>


#define EPS 1E-7


using namespace std;

/** Used to read and return one rfacEssentialData object at a time, to avoid clogging up RAM.
 **/
class rfacEssentialDataReader: public VerbosePrinterEventEnabled
{
public:
  rfacEssentialDataReader(string directoryName, ///Name of parent directory for initialization.
			  VerbosePrinter * myPrinter, //& Verbose printer
			  unsigned int nThreads = 10 /// Number of threads.
			  ); /// Constructor
  ~rfacEssentialDataReader(); ///Destructor

  bool HasNext(); ///Check if we can retrieve more essential data objects or not.

  rfacEssentialData * GetNext(); /// Returns the next rfacEssentialData object. This is read from disk. \note that this needs to be destroyed by the caller.

  unsigned int GetTotalCount(); /// Returns total number of subdirectories that are going to or has been read.

  unsigned long long GetOutputQueueSize(); /// Calls the underlying object to obtain this quantity.

  static void SetDecayCut(long double value ///The value of the decay cut.
		   ); /// Sets a value of the decay cut. Warning: static.

private:

  static bool double_equal(const double & d1, const double & d2);


  unsigned int totalCount; /// Number of files in total.

  static long double decayCut; ///Warning: static

  MultiTasker<string, rfacEssentialData *> * myMultiTasker; ///The object which manages the multithreading.

  static rfacEssentialData * ReadObject(string loopDirectoryName ///Directory for this iteration.
					); ///Main work function.

  void ValidateDirectories(vector<string> directoryNames, /// Names of directories to validate.
			   bool lenient /// Should we be lenient or not?
			   ); //Check the file number in each directory.

  static vector<string> getDirectoryContent(const string directoryName /// The location of the directory.
				     ); /// Gets the content (list of files) of a directory.

  static int one(const struct dirent *unused  ///<Unused.
		 ){ return 1; } /// Used to when retrieving directory content.

  static QuantumNumbers EnfLevelToQuantumNumbers(rfacEN * myEn, ///The EN level file.
						 rfacENF * myEnf,  ///The ENF level file.
						 unsigned int enfLevel ///The index of the level in the ENF file to find quantum numbers for.
						 ); ///Convert an enf level to quantum numbers.

};


#endif
