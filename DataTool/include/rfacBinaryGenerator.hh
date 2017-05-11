#ifndef rfacBinaryGenerator_hh
#define rfacBinaryGenerator_hh 1


#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <cstdlib>
#include <queue>
#include <utility>
#include <ftw.h>
#include <sys/dir.h>
#include <string.h>
#include <unistd.h>


#include "rfacException.hh"
#include "VerbosePrinter.hh"
#include "VerbosePrinterEventEnabled.hh"
#include "globaldef.hh"
#include "MultiTasker.hpp"


using namespace std;


/* Used for parallellalizing the process a bit.
*/
class rfacBinaryGenerationParallellData
{
public:
  string levelFilename, levelEBFilename, transitionFilename;
  int toN, toL;
  int fromN, fromL;
  double E, B, ANGLE;
  int multipole;
  rfacBinaryGenerationParallellData(string _levelFilename, string _levelEBFilename, string _transitionFilename, 
				    int _toN, int _toL,  int _fromN, int _fromL, 
				    double e, double b, double angle, 
				    int mpole)
  {
    levelFilename = _levelFilename; levelEBFilename = _levelEBFilename; transitionFilename = _transitionFilename;
    fromN=_fromN; fromL=_fromL;
    toN=_toN; toL=_toL;
    E=e, B=b, ANGLE=angle;
    multipole = mpole;
  }
};

/*! Generates binary files by invoking the SFAC software.
*/
class rfacBinaryGenerator: public VerbosePrinterEventEnabled
{
public:
  rfacBinaryGenerator(unsigned int threads = 10, /// Number of threads.
		      bool _onlyAllowed = false ///Only allowed transitions.
		      ); //! Constructor.
  ~rfacBinaryGenerator(); //! Destructor
  void SetFields(double e, //! The E field.
		 double b,  //! The B field.
		 double angle //! The angle between the E-field and the B-field.
		 );

  void SetShells(int value = 4 //! The value. 
		 ); //! Sets the number of shells. 
  void SetLevels(int value = 10  //! The value. 
		 ); //! Sets the number of levels. 

  void SetMinShells(int value = 0  //! The value. 
		 ); //! Sets the minimum number of shells. 

  void SetMinLevels(int value = 1  //! The value. 
		 ); //! Sets the minimum number of levels. 


  void SetMultipole(int value = -1  //! The value. 
		    ); //! Sets the multipole.

  void DoGeneration(string dirPattern, string levelFilenamePattern, string levelEBFilenamePattern, string transitionFilenamePattern); //Call this method to queue up generation.

  unsigned int GetWorkQueueSize(); /// Return the size of the queue with work to be done. Useful for estimating when to queue up more stuff. Thread safe.

  bool IsFinished(); /// Call when you don't intend to add more work, and want to know if all inputted work is finished.

private:

  static const string AllOrbitals; ///All availible orbitals (s, p, d, f, g, h, etc).

  static void * RunBinaryGenerationTask(rfacBinaryGenerationParallellData * myData ///The data.
				 ); ///Runs the actual generation task. Invokde by the multitasker object.

  MultiTasker<rfacBinaryGenerationParallellData *, void *> * myMultiTasker; ///The object which manages the multithreading.

  

  double E, B, ANGLE; //! Self-descriptive
  
  int shells, levels, multipole; /// Self-descriptive.
  
  int minShells, minLevels; ///Self-descriptive.

  unsigned int threads; ///Self-descriptive

  bool onlyAllowed; ///Self-descriptive.


  void Initialize(); //Called when some stuff needs to be renewed.

  static FILE * LaunchSfacProcess(int fromN, //! Number of shells.
				  int fromL, //! Number of levels.
				  int toN,
				  int toL
				  ); //! Starts the sfac process and inputs some basic stuff. Then returns it.

  static void CloseSfacProcess(FILE * toClose); //! Closes the sfac process specified by toClose.

  static void GenerateLevels(FILE * sfacProcess, //! The process to print to.
			     string filename, //! The file name to save to.
			     string EBfilename, /// EB filename
			     int fromN,
			     int fromL,
			     int toN, 
			     int toL
			     ); //! Generates a level file.

  static void GenerateTransitions(FILE * sfacProcess,//! The process to print to.
				  string filenamePattern, //Must contain a %c, a %d and no other printf formatters.
				  int fromN,
				  int fromL,
				  int toN, 
				  int toL,
				  int multipole //! multipole
				  ); //! Prepares to generate all the transition files, using the specified file pattern.

  static void PrintFields(FILE * sfacProcess, //! The process to print to.
			  double E, //! E
			  double B,  //! B
			  double ANGLE //! Angle
		 );


  static inline char Orbital(unsigned short l ///The orbital number.
			     ); /// Self-descriptive. Returns a character describing the orbital.

  
  static void _mkdir(const char *dir); //! To create directory recursively.


};


#endif

