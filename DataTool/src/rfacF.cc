#include "rfacF.hh"

rfacF::rfacF(FILE * f)
{
  readHeader(f);
}

rfacF::~rfacF()
{
  delete myHeader;
}

 void rfacF::readHeader(FILE * f)
 {
   myHeader = new F_HEADER();
   ReadFHeader(f, myHeader, &mySwp);
   return;
}

const void rfacF::Print()
{
  printf("-----------------------------\n");
  printf("Header information:\n");
  printf("FAC version: \t% d.%d R%d\n",myHeader->version, 
	 myHeader->sversion, myHeader->ssversion);
  printf("Data file type: \t %d\n",myHeader->type);
  printf("Atom: \t\t %f\n", myHeader->atom);
  printf("Symbol:\t\t %s\n", myHeader->symbol);
  printf("Data blocks in file: \t %d\n", myHeader->nblocks);
  printf("-----------------------------\n");
}

const int rfacF::getMajorVersion()
{ 
  return myHeader->version;
}
const int rfacF::getMinorVersion()
{ 
  return myHeader->sversion;
}
const int rfacF::getReleaseVersion()
{ 
  return myHeader->ssversion;
}
const int rfacF::getType()
{ 
  return myHeader->type;
}
const string rfacF::getSymbol()
{ 
  return myHeader->symbol;
}
const int rfacF::getNBlocks()
{ 
  return myHeader->nblocks;
}

const int rfacF::getSwp()
{ 
  return mySwp;
}
