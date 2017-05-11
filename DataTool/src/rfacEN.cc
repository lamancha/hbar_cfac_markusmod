
#include "rfacEN.hh"

rfacEN::rfacEN(FILE * f, int swp)
{
  readHeader(f, swp);
  readRecords(f, swp);
}

rfacEN::~rfacEN()
{
  delete myHeader;
  for(vector<EN_RECORD *>::iterator it = myRecords.begin(); it!=myRecords.end(); it++)
    {
      delete *it;
    }
}

void rfacEN::readHeader(FILE * f, int swp)
{
  myHeader = new EN_HEADER();
  ReadENHeader(f, myHeader, swp);
}

    void rfacEN::readRecords(FILE * f, int swp)
{
  for(int i = 0; i < myHeader->nlevels; i++)
    {
      EN_RECORD * myRecord = new EN_RECORD();
      ReadENRecord(f, myRecord,swp);
      myRecords.push_back(myRecord);
    }
}

const void rfacEN::PrintHeader()
{  
  printf("Energy header information:---\n");
  printf("Number of electrons: \t %d\n",myHeader->nele);
  printf("Number of levels: \t %d\n",myHeader->nlevels);
  printf("-----------------------------\n");
}

const void rfacEN::PrintRecord(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  EN_RECORD * current = myRecords[recordNumber];
  if(current == NULL)
    {
      printf("Error: EN record was null: %d\n",recordNumber);
    }
  printf("Energy record %d: ------------\n",recordNumber);
  printf("Parity: \t %d\n", SIGN(current->p));
  printf("N: \t %d\n", (int)abs(current->p)/100);
  printf("L: \t %d\n", (int)abs(current->p)%100);
  printf("Angular momentum: \t %d/2\n",current->j);
  printf("Index of level: \t %d\n",current->ilev);
  printf("Index of base level: \t %d\n",current->ilev);
  printf("Energy of level: \t %.10f \n",current->energy*HARTREE_EV);
  printf("Complex name: \t \t %s\n",current->ncomplex);
  printf("Non-SR lvl cfg name: \t %s\n",current->sname);
  printf("SR lvl cfg: \t\t %s\n",current->name);

  printf("-----------------------------\n");
}

const void rfacEN::Print()
{
  PrintHeader();
  for(unsigned int i = 0; i<myRecords.size(); i++)
    {
      PrintRecord(i);
    }
}

const short rfacEN::getN(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return abs(myRecords[recordNumber]->p/100);
}

const short rfacEN::getL(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return abs(myRecords[recordNumber]->p%100);
}

const short rfacEN::get2J(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return myRecords[recordNumber]->j;
}

const long int rfacEN::getPosition()
{
  return myHeader->position;
}

const long int rfacEN::getLength()
{
  return myHeader->length;
}

const int rfacEN::getNumberOfElectrons()
{
  return myHeader->nele;
}

const int rfacEN::getNumberOfLevels()
{
  return myHeader->nlevels;
}

void rfacEN::OutOfBoundsCheck(unsigned int recordNumber)
{
  if(recordNumber >= myRecords.size())
    throw rfacException("Attempted to access an EN record which does not exist.");
}

const int rfacEN::getParity(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return SIGN(myRecords[recordNumber]->p);
}
  

const int rfacEN::getIndexOfLevel(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return myRecords[recordNumber]->ilev;
}
const int rfacEN::getIndexOfBaseLevel(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return myRecords[recordNumber]->ibase;
}

const double rfacEN::getEnergyOfLevel(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return myRecords[recordNumber]->energy*HARTREE_EV;
}

const string rfacEN::getComplexName(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return myRecords[recordNumber]->ncomplex;
}

const string rfacEN::getNonRelativisticConfigurationName(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return myRecords[recordNumber]->sname;
  
}
const string rfacEN::getRelativisticConfigurationName(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return myRecords[recordNumber]->name;
}
