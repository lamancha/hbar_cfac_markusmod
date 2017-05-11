#include "rfacENF.hh"

rfacENF::rfacENF(FILE * f, int swp)
{
  readHeader(f, swp);
  readRecords(f, swp);
}

rfacENF::~rfacENF()
{
  if(myHeader!=NULL)
    {
      delete myHeader;
      myHeader = NULL;
    }
  for(vector<ENF_RECORD *>::iterator it = myRecords.begin(); it!=myRecords.end(); it++)
    {
      if(*it!=NULL)
		{
		  delete *it;
		  *it = NULL;
		}
    }
}

void rfacENF::readHeader(FILE * f, int swp)
{
  myHeader = new ENF_HEADER();

  ReadENFHeader(f, myHeader, swp);
}

void rfacENF::readRecords(FILE * f, int swp)
{
  for(int i = 0; i < myHeader->nlevels; i++)
    {
      ENF_RECORD * myRecord = new ENF_RECORD();
      ReadENFRecord(f, myRecord,swp);
      myRecords.push_back(myRecord);
    }
}

const void rfacENF::PrintHeader()
{  
  printf("Energy header information:--------\n");
  printf("Number of electrons: \t %d\n",myHeader->nele);
  printf("Number of levels: \t %d\n",myHeader->nlevels);
  printf("E-field: \t \t %+.10e V/m\n", myHeader->efield/VM_TO_VCM);
  printf("B-field: \t \t %+.10e T\n", myHeader->bfield/TESLA_TO_GAUSS);
  printf("Angle: \t \t \t %+.10e degrees\n", myHeader->fangle);
  printf("----------------------------------\n");
}

const void rfacENF::PrintRecord(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  ENF_RECORD * current = myRecords[recordNumber];
  if(current == NULL)
    {
      throw rfacException("Energy level was null.");
    }
  printf("Energy record %d: ------------------\n",recordNumber);
  printf("Initial level: \t \t %d\n",current->ilev);
  printf("Energy: \t \t %+.10e eV\n",current->energy * HARTREE_EV);
  printf("Pbasis: \t \t %d\n",current->pbasis);
  printf("----------------------------------\n");
}

const void rfacENF::Print()
{
  PrintHeader();
  for(unsigned int i = 0; i<myRecords.size(); i++)
    {
      PrintRecord(i);
    }
}



const long int rfacENF::getPosition()
{
  return myHeader->position;
}

const long int rfacENF::getLength()
{
  return myHeader->length;
}

const int rfacENF::getNumberOfElectrons()
{
  return myHeader->nele;
}

const int rfacENF::getNumberOfLevels()
{
  return myHeader->nlevels;
}

void rfacENF::OutOfBoundsCheck(unsigned int recordNumber)
{
  if(recordNumber >= myRecords.size())
      throw rfacException("Error: Attempted to access an ENF record which does not exist.");
}

const int rfacENF::getLevelIndex(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return myRecords[recordNumber]->ilev;
}

const double rfacENF::getEnergy(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return myRecords[recordNumber]->energy * HARTREE_EV;
}

const int rfacENF::getPBasis(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return myRecords[recordNumber]->pbasis;
}

const int rfacENF::getInitialLevel(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return ((int)abs(myRecords[recordNumber]->pbasis))%MAXLEVEB;
}

const int rfacENF::getM(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return ((int)abs(myRecords[recordNumber]->pbasis))/MAXLEVEB;
}

const int rfacENF::getParity(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return 2*((myRecords[recordNumber]->pbasis)>0)-1;
}

const double rfacENF::getEField()
{
  return myHeader->efield/VM_TO_VCM;
}

const double rfacENF::getBField()
{
  return myHeader->bfield/TESLA_TO_GAUSS;
}

const double rfacENF::getFieldAngle()
{
  return myHeader->fangle;
}
