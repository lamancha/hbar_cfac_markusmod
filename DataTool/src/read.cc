#include "read.hh"

int main (int argc, char * argv[]) 
{

  if(argc<2)
    {
      PrintHelp();
      return 1;
    }
  vector<string> filenames;
  for(int i = 1; i<argc; i++)
    {
      filenames.push_back(argv[i]);
    }
  rfacDB myDb(filenames,1);

  return 0;
}

void PrintHelp()
{
  cerr << endl;
  cerr << "READ: Read SFAC binary data files and print content to stdout." << endl;
  cerr << endl;
  cerr << "Synopsis: ./read input_files" << endl;
  cerr << setiosflags(ios::left);
  cerr << endl;
  cerr << setw(40) << "Command description:" << endl;;
  cerr << endl;
  cerr << setw(40) << "The following arguments are MANDATORY:" << endl;

  cerr << setw(5) << " " << setw(40) << "input_files" << "List of input files which are sfac binaries. Order is not important. " << endl;
  cerr << setw(5) << " " << setw(40) << " " << "Note: Some types of sfac files requires other corresponding types of sfac files to be specified too." << endl;

  cerr << endl;
  return;
}
