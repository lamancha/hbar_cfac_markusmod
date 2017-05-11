#ifndef rootread_hh
#define rootread_hh 1

#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TMath.h>
#include <TCanvas.h>

#include <TApplication.h>
#include <TROOT.h>

#include <iostream>
#include <map>
#include <cstdlib>

#include <TClonesArray.h>


#include "rfacEssentialData.hh"
#include "EnergyLevel.hh"
#include "rfacException.hh"

#include "CommandLineInterpreter.hh"



int main (int argc, char * argv[]); /// Main method of program.

void PrintHelp(); /// Prints help message.

CommandLineInterpreter * InitInterpreter(int argc, /// Same as arguments to main
					 char * argv[] /// Same as arguments to main
					 );/// Initialize the command line interpreter.
void ProcessFile(CommandLineInterpreter * myInterpreter /// Command line interpreter to read settings from.
		 ); /// Process the file.

#endif
