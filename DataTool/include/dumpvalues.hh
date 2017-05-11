#include <stdio.h>

#include <TFile.h>
#include <TTree.h>
#include <TString.h>
#include <vector>
#include <map>


#include "QuantumNumbers.hh"
#include "rfacInterpolatorContainer.hh"
#include "rfacLinearInterpolation.hh"
#include "CommandLineInterpreter.hh"
#include "VerbosePrinter.hh"
#include "VerbosePrinterEventEnabled.hh"


using namespace std;

int main(int argc, char * argv[]) ;

CommandLineInterpreter * InitInterpreter(int argc, char * argv[]);

void PrintHelp();
