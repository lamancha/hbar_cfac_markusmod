#ifndef rootfitmake_hh
#define rootfitmake_hh 1

#include <string>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include <set>
#include <queue>

#include "TProof.h"
#include "TApplication.h"


#include "rfacLevelPicker.hh"
#include "rfacQuantumNumberLister.hh"
#include "CommandLineInterpreter.hh"
#include "CommandLineArgument.hh"
#include "VerbosePrinter.hh"
#include "rfacException.hh"
#include "rfacInterpolatorContainer.hh"
#include "QuantumNumbers.hh"
#include "rfacException.hh"
#include "rfacFieldGridPoint.hh"
#include "rfacFieldGridContainer.hh"
#include "rfacFieldGridPicker.hh"
#include "rfacQuantumNumberContainer.hh"
#include "rfacLevelContainer.hh"
#include "MultiTasker.hpp"
#include "rfac3DInterpolation.hh"


using namespace std;


int main (int argc, char * argv[]); /// Main method of program.

void PrintHelp(); /// Prints help message.

CommandLineInterpreter * InitInterpreter(int argc, /// Same as arguments to main
					 char * argv[] /// Same as arguments to main
					 );/// Initialize the command line interpreter.
void ProcessFile(CommandLineInterpreter * myInterpreter /// Command line interpreter to read settings from.
		 ); /// Process the file.

string get_selfpath(); ///From the internet. Used since PROOF is stupid. But don't use PROOF anyway.

vector<rfacInterpolatorContainer *> readObject(set<QuantumNumbers> toLocate, VerbosePrinter * toUse = NULL);

int fieldGridSize; ///self descriptive

rfacEssentialData * myEssentialData;
TFile * infile;
TTree * inTree;


#endif
