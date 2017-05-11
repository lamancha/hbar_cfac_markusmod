#include "rfacDecayableObject.hh"

ClassImp(rfacDecayableObject)

TRandom1 * rfacDecayableObject::myFailsafeRandom = NULL;

rfacDecayableObject::rfacDecayableObject(double (*_U01Function)() )
  :decayChannel(NULL), currentFilename(""), B(0), E(-1), A(-1), TimeToNextDecay(0), totalDecayRate(0), enableFieldRegimeTranslations(true), myInterpolation(NULL)
{

  U01Function = _U01Function;
  if( U01Function == NULL)
    {
      U01Function = &uniform0to1Random;
    }

  myTranslator = new rfacFieldRegimeTranslator(U01Function);
  myQuantumNumbers = new QuantumNumbers();
}

rfacDecayableObject::~rfacDecayableObject()
{
  if(myInterpolation)
    delete myInterpolation;
  if(myFailsafeRandom)
    {
      delete myFailsafeRandom;
      myFailsafeRandom = NULL;
    }
  if(myQuantumNumbers)
	{
	  delete myQuantumNumbers;
	  myQuantumNumbers = NULL;
	}
  if(decayChannel)
	{
	  delete decayChannel;
	  decayChannel = NULL;
	}
  if(myTranslator)
	{
	  delete myTranslator;
	  myTranslator = NULL;
	}
}

void rfacDecayableObject::ResetQuantumNumbers(bool strong)
{
  delete myQuantumNumbers;
  if(strong)
	myQuantumNumbers = new StrongFieldQuantumNumbers();
  else
	myQuantumNumbers = new QuantumNumbers();
  B=0;
}

void rfacDecayableObject::InitializeDecay()
{
  if(myInterpolation == NULL)
    {
      throw rfacException("Cannot initialize decay since there is no database file associated with this object.");
    }

  myInterpolation->SetState(myQuantumNumbers);
  TimeToNextDecay = GetTimeToNextDecay();
}



double rfacDecayableObject::GetTimeToNextDecay()
{
  if(myInterpolation == NULL)
    {
      throw rfacException("Warning: Can not use this function if there is no interpolation object.");
    }
  totalDecayRate = 0;
  if(QuantumNumbers * nbr = dynamic_cast<QuantumNumbers*>(myQuantumNumbers))
	{
	  if(myInterpolation->GetState() != *nbr)
		myInterpolation->SetState(*nbr);
	  map<QuantumNumbers, double> myDecayRates = myInterpolation->GetDecayRates(B,E,A);
	  for(map<QuantumNumbers, double>::iterator it = myDecayRates.begin(); it!=myDecayRates.end(); ++it)
		{
		  if(it->second < 0)
			it->second = 0;

		  if(it->first != *nbr)
			{
			  totalDecayRate += it->second;
			}
		}

	  double temp = U01Function();
	  if(temp<1E-20)
		temp=1E-20; //small bias to avoid zero.
	  double timeToDecay = - log(U01Function())/totalDecayRate;

	  double channelSelector = U01Function()*totalDecayRate;
	  double sum = 0;

	  for(map<QuantumNumbers, double>::iterator it= myDecayRates.begin(); it!=myDecayRates.end(); ++it)
		{
		  if(it->first != *nbr)
			{
			  sum+=it->second;
			  if(sum>=channelSelector)
				{
				  if(decayChannel)
					delete decayChannel;
				  decayChannel = new QuantumNumbers(it->first);
				  break;
				}
			}
		}
	  return timeToDecay;

	}
  else if(StrongFieldQuantumNumbers * nbr = dynamic_cast<StrongFieldQuantumNumbers*>(myQuantumNumbers) )
	{
	  if(myInterpolation->GetStrongState() != *nbr)
		myInterpolation->SetStrongFieldState(*nbr);

	  map<StrongFieldQuantumNumbers, double> myDecayRates = myInterpolation->GetStrongFieldDecayRates(B,E,A);
	  for(map<StrongFieldQuantumNumbers, double>::iterator it = myDecayRates.begin(); it!=myDecayRates.end(); ++it)
		{
		  if(it->second < 0)
			it->second = 0;

		  if(it->first != *nbr)
			{
			  totalDecayRate += it->second;
			}
		}

	  double temp = U01Function();
	  if(temp<1E-20)
		temp=1E-20; //small bias to avoid zero.
	  double timeToDecay = - log(U01Function())/totalDecayRate;

	  double channelSelector = U01Function()*totalDecayRate;
	  double sum = 0;

	  for(map<StrongFieldQuantumNumbers, double>::iterator it= myDecayRates.begin(); it!=myDecayRates.end(); ++it)
		{
		  if(it->first != *nbr)
			{
			  sum+=it->second;
			  if(sum>=channelSelector)
				{
				  if(decayChannel)
					delete decayChannel;
				  decayChannel = new StrongFieldQuantumNumbers(it->first);
				  break;
				}
			}
		}
	  return timeToDecay;
	}
  throw rfacException("Invalid cast in rfacDecayableObject.");
}

bool rfacDecayableObject::SetField(double _B, double _E, double _A)
{
  B=_B;
  E=_E;
  A=_A;
  if(myTranslator == NULL)
	throw rfacException("Invalid field regime translator.");
  myTranslator->SetField(B);
  if(!enableFieldRegimeTranslations)
	return false;
  bool toReturn = myTranslator->Translate(&myQuantumNumbers);
  return toReturn;
}

double rfacDecayableObject::PeekAtTimeToNextDecay()
{
  return TimeToNextDecay;
}

void rfacDecayableObject::SetEnableFieldRegimeTranslations(bool value)
{
  enableFieldRegimeTranslations = value;
}



void rfacDecayableObject::SetStateFile(string newFile)
{
  if(newFile != currentFilename)
    {
      currentFilename = newFile;
      if(myInterpolation)
		delete myInterpolation;
      myInterpolation = new rfacInterpolation(currentFilename);
    }
}

void rfacDecayableObject::PreloadStates()
{
  if(myInterpolation == NULL)
    {
      throw rfacException("No state file set.");
    }
  myInterpolation->PreloadStates();
}


void rfacDecayableObject::DoStepTime(double timeStep)
{
  if(myInterpolation == NULL)
    {
      throw rfacException("Tried to step time, but interpolation object is not initialized.");
    }

  if(QuantumNumbers * nbr = dynamic_cast<QuantumNumbers*>(myQuantumNumbers) )
	{
	  if(myInterpolation->GetState()!= *nbr) ///if someone changed the stuff since last call.
		{
		  myInterpolation->SetState(*nbr);
		  TimeToNextDecay = GetTimeToNextDecay();
		}
	}
  else if(StrongFieldQuantumNumbers * nbr = dynamic_cast<StrongFieldQuantumNumbers*>(myQuantumNumbers) )
	{
	  if(myInterpolation->GetStrongState()!= *nbr) ///if someone changed the stuff since last call.
		{
		  myInterpolation->SetStrongFieldState(*nbr);
		  TimeToNextDecay = GetTimeToNextDecay();
		}
	}
  else
	{
	  throw rfacException("Invalid dynamic cast in rfacDecayableObject.");
	}




  TimeToNextDecay -= timeStep;

  while(TimeToNextDecay < 0 && totalDecayRate > 1E-20)
    {
	  delete myQuantumNumbers;
	  myQuantumNumbers = decayChannel;
	  decayChannel = NULL;
	  if(myQuantumNumbers == NULL)
		{
		  throw rfacException("Decay channel fail.");
		}
      myInterpolation->SetState(myQuantumNumbers);
      TimeToNextDecay += GetTimeToNextDecay(); //Find new decay channel.
    }
}

double rfacDecayableObject::uniform0to1Random()
{
  if(myFailsafeRandom == NULL)
    {
      myFailsafeRandom = new TRandom1(std::time(NULL));
    }
  return myFailsafeRandom->Rndm();
}


GeneralQuantumNumbers * rfacDecayableObject::GetQuantumNumbers()
{
  return myQuantumNumbers;
}


bool rfacDecayableObject::IsWeakFieldRegime() const
{
  return dynamic_cast<const QuantumNumbers*>(myQuantumNumbers);
}

bool rfacDecayableObject::IsStrongFieldRegime() const
{
  return dynamic_cast<const StrongFieldQuantumNumbers*>(myQuantumNumbers);
}

unsigned short rfacDecayableObject::GetN() const
{
  if(myQuantumNumbers == NULL)
	{
	  throw rfacException("myQuantumNumbers was NULL.");
	}
  return myQuantumNumbers->GetN();
}

void rfacDecayableObject::SetN(unsigned short value)
{
  if(myQuantumNumbers == NULL)
	{
	  throw rfacException("myQuantumNumbers was NULL.");
	}
  myQuantumNumbers->SetN(value);
}


unsigned short rfacDecayableObject::GetL() const
{
  if(myQuantumNumbers == NULL)
	{
	  throw rfacException("myQuantumNumbers was NULL.");
	}
  return myQuantumNumbers->GetL();
}

void rfacDecayableObject::SetL(unsigned short value)
{
  if(myQuantumNumbers == NULL)
	{
	  throw rfacException("myQuantumNumbers was NULL.");
	}
  myQuantumNumbers->SetL(value);
}

short rfacDecayableObject::GetML() const
{
  const StrongFieldQuantumNumbers * qnbr = dynamic_cast<const StrongFieldQuantumNumbers *>(myQuantumNumbers);
  if(qnbr == NULL)
	{
	  throw rfacException("Dynamic casting to StrongFieldQuantumNumbers failed.");
	}
  return qnbr->GetML();
}

void rfacDecayableObject::SetML( short value)
{
  StrongFieldQuantumNumbers * qnbr = dynamic_cast<StrongFieldQuantumNumbers *>(myQuantumNumbers);
  if(qnbr == NULL)
	{
	  throw rfacException("Dynamic casting to StrongFieldQuantumNumbers failed.");
	}
  qnbr->SetML(value);
}



short rfacDecayableObject::GetTwoMS() const
{
  const StrongFieldQuantumNumbers * qnbr = dynamic_cast<const StrongFieldQuantumNumbers *>(myQuantumNumbers);
  if(qnbr == NULL)
	{
	  throw rfacException("Dynamic casting to StrongFieldQuantumNumbers failed.");
	}
  return qnbr->GetTwoMS();
}

void rfacDecayableObject::SetTwoMS( short value)
{
  StrongFieldQuantumNumbers * qnbr = dynamic_cast<StrongFieldQuantumNumbers *>(myQuantumNumbers);
  if(qnbr == NULL)
	{
	  throw rfacException("Dynamic casting to StrongFieldQuantumNumbers failed.");
	}
  qnbr->SetTwoMS(value);
}



unsigned short rfacDecayableObject::GetTwoJ() const
{
  const QuantumNumbers * qnbr = dynamic_cast<const QuantumNumbers *>(myQuantumNumbers);
  if(qnbr == NULL)
	{
	  throw rfacException("Dynamic casting to QuantumNumbers failed.");
	}
  return qnbr->GetTwoJ();
}

void rfacDecayableObject::SetTwoJ( unsigned short value)
{
  QuantumNumbers * qnbr = dynamic_cast<QuantumNumbers *>(myQuantumNumbers);
  if(qnbr == NULL)
	{
	  throw rfacException("Dynamic casting to QuantumNumbers failed.");
	}
  qnbr->SetTwoJ(value);
}



short rfacDecayableObject::GetTwoMJ() const
{
  const QuantumNumbers * qnbr = dynamic_cast<const QuantumNumbers *>(myQuantumNumbers);
  if(qnbr == NULL)
	{
	  throw rfacException("Dynamic casting to QuantumNumbers failed.");
	}
  return qnbr->GetTwoMJ();
}

void rfacDecayableObject::SetTwoMJ( short value)
{
  QuantumNumbers * qnbr = dynamic_cast<QuantumNumbers *>(myQuantumNumbers);
  if(qnbr == NULL)
	{
	  throw rfacException("Dynamic casting to QuantumNumbers failed.");
	}
  qnbr->SetTwoMJ(value);
}

double rfacDecayableObject::GetField() const
{
  return B;
}


void rfacDecayableObject::SetLowerHysteresisFactor(double value)
{
  myTranslator->SetLowerHysteresisFactor(value);
}


void rfacDecayableObject::SetUpperHysteresisFactor(double value)
{
  myTranslator->SetUpperHysteresisFactor(value);
}

double rfacDecayableObject::GetLowerHysteresisFactor() const
{
  return myTranslator->GetLowerHysteresisFactor();
}

double rfacDecayableObject::GetUpperHysteresisFactor() const
{
  return myTranslator->GetUpperHysteresisFactor();
}
