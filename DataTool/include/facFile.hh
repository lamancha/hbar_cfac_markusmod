#ifndef facFile_hh
#define facFile_hh 1

//! Base class for all the file records in a fac file.
class facFile
{
public:
  //! Prints the content of the corresponding file chunk to stdout. 
  const virtual void Print() = 0;
  facFile();
  virtual ~facFile();
};


#endif
