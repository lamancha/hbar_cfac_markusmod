#include "rfacTR.hh"

rfacTR::rfacTR(FILE * f, int swp, rfacEN * levels)
{
  readHeader(f,swp);
  readRecords(f,swp);
  myLevels = levels;
}

rfacTR::~rfacTR()
{
  delete myHeader;
  for(vector<TR_RECORD *>::iterator it = myRecords.begin(); it!=myRecords.end(); it++)
    {
      delete *it;
    }
}

void rfacTR::readHeader(FILE * f, int swp)
{
  myHeader = new TR_HEADER();
  ReadTRHeader(f, myHeader, swp);
}

void rfacTR::readRecords(FILE * f, int swp)
{
  for(int i = 0; i<myHeader->ntransitions; ++i)
    {
      TR_RECORD * myRecord = new TR_RECORD();
      TR_EXTRA * myExtra = new TR_EXTRA();
      ReadTRRecord(f, myRecord, myExtra, swp); //Since the TR_EXTRA doesn't seem to be used, don't bother saving it...
      delete myExtra;

      myRecords.push_back(myRecord);

    }
}

const void rfacTR::PrintHeader()
{
  printf("Transition header information:----\n");
  printf("Number of electrons: \t %d\n",myHeader->nele);
  printf("Number of transitions: \t %d\n",myHeader->ntransitions);
  printf("Gauge: \t \t %d\n",myHeader->gauge);
  printf("Mode: \t \t %d\n",myHeader->mode);
  printf("Multipole: \t \t %d\n",myHeader->multipole);
  printf("----------------------------------\n");
}

const void rfacTR::PrintRecord(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  printf("Transition record %d: ------------\n",recordNumber);
  printf("Lower level: \t \t %d\n", myRecords[recordNumber]->lower);
  printf("Upper level: \t \t %d\n", myRecords[recordNumber]->upper);
  printf("Field strength: \t %f\n", myRecords[recordNumber]->strength);
}

const int rfacTR::getLowerLevel(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return myRecords[recordNumber]->lower;
}

const int rfacTR::getUpperLevel(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return myRecords[recordNumber]->upper;
}

const int rfacTR::getTransitionStrength(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return myRecords[recordNumber]->strength;
}


const void rfacTR::Print()
{
  PrintHeader();
  for(unsigned int i = 0; i<myRecords.size(); i++)
    {
      PrintRecord(i);
    }
}


void rfacTR::OutOfBoundsCheck(unsigned int recordNumber)
{
  if(recordNumber >= myRecords.size())
    throw rfacException("Error: Attempted to access a non-existent transition record.");
}

const int rfacTR::getNumberOfElectrons()
{
  return myHeader-> nele;
}

const int rfacTR::getNumberOfTransitions()
{
  return myHeader->ntransitions;
}

const int rfacTR::getGauge()
{
  return myHeader->gauge;
}

const int rfacTR::getMode()
{
  return myHeader->mode;
}

const int rfacTR::getMultipole()
{
  return myHeader->multipole;
}
