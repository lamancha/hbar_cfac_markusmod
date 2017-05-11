#include "rfacTRF.hh"

rfacTRF::rfacTRF(FILE * f, int swp, rfacENF * levels)
{
  readHeader(f,swp);
  readRecords(f,swp);
  myLevels = levels;
}

rfacTRF::~rfacTRF()
{
  if(myHeader != NULL)
    {
      delete myHeader;
      myHeader =NULL;
    }
  for(vector<TRF_RECORD *>::iterator it = myRecords.begin(); it!=myRecords.end(); it++)
    {
      if(*it != NULL)
	{
	  delete *it;
	  *it = NULL;
	}
    }
}

void rfacTRF::readHeader(FILE * f, int swp)
{
  myHeader = new TRF_HEADER();
  ReadTRFHeader(f, myHeader, swp);
}

void rfacTRF::readRecords(FILE * f, int swp)
{
  for(int i = 0; i<myHeader->ntransitions; ++i)
    {
      TRF_RECORD * myRecord = new TRF_RECORD();
      ReadTRFRecord(f, myRecord, swp, myHeader);

      myRecords.push_back(myRecord);
      myFieldStrengths.push_back(vector<float>());
      for(int i = 0; i<2*abs(myHeader->multipole)+1; i++)
		{
		  myFieldStrengths.back().push_back(myRecord->strength[i]);
		}
    }
}

const void rfacTRF::PrintHeader()
{
  printf("Transition header information:----\n");
  printf("Number of electrons: \t %d\n",myHeader->nele);
  printf("Number of transitions: \t %d\n",myHeader->ntransitions);
  printf("Gauge: \t \t \t %d\n",myHeader->gauge);
  printf("Mode: \t \t \t %d\n",myHeader->mode);
  printf("Multipole: \t \t %d\n",myHeader->multipole);
  printf("E-field: \t \t %+.10e V/m\n", myHeader->efield/VM_TO_VCM);
  printf("B-field: \t \t %+.10e T\n", myHeader->bfield/TESLA_TO_GAUSS);
  printf("Field angle: \t \t %+.10e degrees\n", myHeader->fangle);
  printf("----------------------------------\n");
}

const void rfacTRF::PrintRecord(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  printf("Transition record %d: ------------\n",recordNumber);
  printf("Lower level: \t \t %d\n", myRecords[recordNumber]->lower);
  printf("Upper level: \t \t %d\n", myRecords[recordNumber]->upper);
  for(vector<float>::iterator it = myFieldStrengths[recordNumber].begin(); it!=myFieldStrengths[recordNumber].end(); it++)
    {
      printf("Transition strength: \t %+.10e\n",*it);
    }
  printf("----------------------------------\n");
}

const int rfacTRF::getLowerLevel(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return myRecords[recordNumber]->lower;
}

const int rfacTRF::getUpperLevel(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return myRecords[recordNumber]->upper;
}

const vector<float> rfacTRF::getTransitionStrength(unsigned int recordNumber)
{
  OutOfBoundsCheck(recordNumber);
  return myFieldStrengths[recordNumber];
}

const void rfacTRF::Print()
{
  PrintHeader();
  for(unsigned int i = 0; i<myRecords.size(); i++)
    {
      PrintRecord(i);
    }
}


void rfacTRF::OutOfBoundsCheck(unsigned int recordNumber)
{
  if(recordNumber >= myRecords.size())
    {
      throw rfacException("Error: Attempted to access a transition (field) record which does not exist.");
    }
}

const int rfacTRF::getNumberOfElectrons()
{
  return myHeader-> nele;
}

const int rfacTRF::getNumberOfTransitions()
{
  return myHeader->ntransitions;
}

const int rfacTRF::getGauge()
{
  return myHeader->gauge;
}

const int rfacTRF::getMode()
{
  return myHeader->mode;
}

const int rfacTRF::getMultipole()
{
  return myHeader->multipole;
}

const double rfacTRF::getEField()
{
  return myHeader->efield/VM_TO_VCM;
}

const double rfacTRF::getBField()
{
  return myHeader->bfield/TESLA_TO_GAUSS;
}

const double rfacTRF::getFieldAngle()
{
  return myHeader->fangle;
}
