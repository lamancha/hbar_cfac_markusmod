#ifndef bingen_hh
#define bingen_hh 1

#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ftw.h>
#include <sys/dir.h>
#include <string.h>
#include <unistd.h>


#include "rfacException.hh"
#include "rfacBinaryGenerator.hh"

#include "CommandLineArgument.hh"
#include "CommandLineInterpreter.hh"
#include "VerbosePrinter.hh"
#include "VerbosePrinterEventEnabled.hh"



int main (int argc, char * argv[]); //! Main method of program.

CommandLineInterpreter * InitInterpreter(int argc, //! Same as arguments to main
					 char * argv[] //! Same as arguments to main
					 );//! Initialize the command line interpreter.

void PrintHelp(); //! Prints help message.

int unlink_cb(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf); //! To unlink (remove) files and directories.

int rmrf(const char *path); //! To remove directory recursively.

static void _mkdir(const char *dir); //! To create directory recursively.


#endif
