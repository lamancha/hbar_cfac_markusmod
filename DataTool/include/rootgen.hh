#ifndef rootgen_hh
#define rootgen_hh 1

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sys/types.h>
#include <sstream>
#include <list>

#include <dirent.h>

#include <iomanip>


#include "TFile.h"
#include "TTree.h"
#include "TClonesArray.h"
#include "TROOT.h"

#include "rfacENF.hh"
#include "rfacTRF.hh"
#include "rfacException.hh"
#include "rfacDB.hh"
#include "facFile.hh"
#include "rfacEssentialData.hh"
#include "VerbosePrinter.hh"
#include "VerbosePrinterEventEnabled.hh"
#include "rfacEssentialDataReader.hh"

#include "dbase.h"
#include "consts.h"

#include "CommandLineArgument.hh"
#include "CommandLineInterpreter.hh"


/// Rootgen, generates root trees.

using namespace std;

int main (int argc, char * argv[]); /// Main method of program.


list<rfacEssentialData *> GetAllData(string directoryName /// The directory (with subdirectories) to load data from.
			       ); /// Loads all and returns it as a list.

void DoProcessing(CommandLineInterpreter * myInterpreter /// The root file name.
			 ); /// Writes data to a root file.

CommandLineInterpreter * InitInterpreter(int argc, /// Same as arguments to main
					 char * argv[] /// Same as arguments to main
					 );/// Initialize the command line interpreter.

void PrintHelp(); /// Prints help message.


#endif
