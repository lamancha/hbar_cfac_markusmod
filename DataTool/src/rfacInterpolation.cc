#include "rfacInterpolation.hh"

ClassImp(rfacInterpolation)

rfacInterpolation::rfacInterpolation(TString _rootFileName, TString _TTreeName, TString _TBranchName)
:rootFileName(_rootFileName), TTreeName(_TTreeName), TBranchName(_TBranchName)
{
  TFile * myTFile = new TFile(rootFileName, "READ");
  if(myTFile->IsZombie())
    throw RLException("rfacInterpolation: Failed to open the specified input file.");
  delete myTFile;

  preloaded = NULL;

  myTChain = new TChain(TTreeName);
  myTChain->Add(rootFileName);

  myInterpolatorPicker = new rfacInterpolatorPicker();
  myInterpolatorPicker->SetInputList(new TList());
  myInterpolatorPicker->GetInputList()->SetOwner();
}

rfacInterpolation::~rfacInterpolation()
{
  if(myInterpolatorPicker != NULL)
    {
      delete myInterpolatorPicker;
    }
  if(myTChain != NULL)
    {
      delete myTChain;
    }
  if(preloaded != NULL)
    {
      for(map<QuantumNumbers, rfacInterpolatorContainer*>::iterator it = preloaded->begin(); it!=preloaded->end(); ++it)
	{
	  delete it->second;
	}
      delete preloaded;
    }
}

QuantumNumbers rfacInterpolation::GetState()
{
  return currentState;
}

void rfacInterpolation::PreloadStates()
{
  delete myTChain; delete myInterpolatorPicker;
  myTChain = NULL; myInterpolatorPicker = NULL;

  if(preloaded == NULL)
    {
	  preloaded = new map<QuantumNumbers, rfacInterpolatorContainer *>();
	  TFile * infile = new TFile(rootFileName, "READ");
	  if(infile->IsZombie())
		RLException("Failed to open the specified root file.");
	  TTree * inTree = (TTree*) infile->Get(TTreeName);
	  rfacInterpolatorContainer * myContainer = 0;

	  inTree->SetBranchAddress(TBranchName, &myContainer);
	  for(int i = 0; i<inTree->GetEntries(); ++i)
		{
		  inTree->GetEntry(i);
		  (*preloaded)[myContainer->key]= new rfacInterpolatorContainer(*myContainer);
		}

	  delete infile;
	}
}

void rfacInterpolation::SetStrongFieldState(StrongFieldQuantumNumbers state)
{
  currentStrongState = state;
}

StrongFieldQuantumNumbers rfacInterpolation::GetStrongState()
{
  return currentStrongState;
}

void rfacInterpolation::SetState(QuantumNumbers value)
{
  currentState = value;
  if(preloaded == NULL)
    {
      myInterpolatorPicker->GetInputList()->Clear();
      myInterpolatorPicker->GetInputList()->Add(new TObjString(TBranchName));
      myInterpolatorPicker->GetInputList()->Add(new QuantumNumbers(currentState));
      myTChain->Process(myInterpolatorPicker);
      TIter next(myInterpolatorPicker->GetOutputList());

      if(rfacInterpolatorContainer * obj = static_cast<rfacInterpolatorContainer*> ( next() ))
		{
		  myContainer = obj;
		}
      else
		{
		  char buffer[500];
		  sprintf(buffer, "Could not set state < %s > since it was not found in the file.", value.ToString().c_str());
		  throw RLException(buffer);
		}
    }
  else
    {
      if(preloaded->find(value) == preloaded->end())
		{
		  char buffer[500];
		  sprintf(buffer, "Could not set state < %s > since it was not found in the preloaded map.", value.ToString().c_str());
		  throw RLException(buffer);
		}
      myContainer = preloaded->find(value)->second;
    }
}

map<QuantumNumbers, Double_t> rfacInterpolation::GetDecayRates( Double_t Bfield, Double_t Efield, Double_t Angle)
{
  if(myContainer == NULL)
    throw RLException("Interpolator object not initialized.");
  map<QuantumNumbers, Double_t> toReturn;
  if(Efield == -1 && Angle ==-1) ///Then only BField available -> Linear Interpolator
  {
    for(map<QuantumNumbers, rfacLinearInterpolation>::iterator it = myContainer->decayRates.begin(); it!=myContainer->decayRates.end(); ++it)
    { ///Attention: decayRates is a pair which returns <QN,InterpolationContainer> so the container is just holding the values and not necessarily Interpolating!!
      toReturn[it->first]=it->second.Eval(Bfield);
	  if(toReturn[it->first] < 0)
		toReturn[it->first] = 0;
    }
  }
  else
  {
    for(map<QuantumNumbers, rfac3DInterpolation>::iterator it = myContainer->decayRates3D.begin(); it!=myContainer->decayRates3D.end(); ++it)
    {
      toReturn[it->first]=it->second.Eval(Efield, Bfield, Angle);
	  if(toReturn[it->first] < 0)
		toReturn[it->first] = 0;
    }

  }

  return toReturn;
}

map<StrongFieldQuantumNumbers, Double_t> rfacInterpolation::GetStrongFieldDecayRates(Double_t Bfield, Double_t Efield, Double_t Angle)
{
  //\todo This method should ideally be buffered. This should be implemented when there is time.

  if(preloaded == NULL)
	throw RLException("Currently, non-preloaded interpolation objects is not supported for strong fields.");
  map<QuantumNumbers, Double_t> preToReturn;

  list<pair<QuantumNumbers, double> > * possibleBasis = CGTranslator::GetAllPossibleTranslatedStates(currentStrongState);

  for(list<pair<QuantumNumbers, double> >::const_iterator it = possibleBasis->begin(); it!=possibleBasis->end(); ++it)
	{
	  rfacInterpolatorContainer * localContainer = (*preloaded)[it->first];
	  if(localContainer == NULL)
		{
		  throw RLException("Quantum number '%s' was not in database.", it->first.ToString().c_str());
		}
      if(Efield == -1 && Angle ==-1) ///Then only BField available -> Linear Interpolator
      {
        for(map<QuantumNumbers, rfacLinearInterpolation>::iterator ip = localContainer->decayRates.begin(); ip!=localContainer->decayRates.end(); ++ip)
		{
		  if(preToReturn.find(ip->first) == preToReturn.end())
			preToReturn[ip->first] = 0;
		  preToReturn[ip->first] += MAX(ip->second.Eval(Bfield), 0.0);
		}
      }
      else
      {
        for(map<QuantumNumbers, rfac3DInterpolation>::iterator ip = localContainer->decayRates3D.begin(); ip!=localContainer->decayRates3D.end(); ++ip)
		{
		  if(preToReturn.find(ip->first) == preToReturn.end())
			preToReturn[ip->first] = 0;
		  preToReturn[ip->first] += MAX(ip->second.Eval(Efield, Bfield, Angle), 0.0);
		}
      }
	}
  delete possibleBasis;
  possibleBasis = NULL;

  map<StrongFieldQuantumNumbers, Double_t> toReturn;


  for(map<QuantumNumbers, Double_t>::const_iterator it = preToReturn.begin(); it!=preToReturn.end(); ++it)
	{
	  list<pair<StrongFieldQuantumNumbers, double> > * backTranslated = CGTranslator::GetAllPossibleTranslatedStates(it->first);
      for(list<pair<StrongFieldQuantumNumbers, double> >::const_iterator ip = backTranslated->begin(); ip!=backTranslated->end(); ++ip)
		{
		  if(toReturn.find(ip->first) == toReturn.end())
			{
			  toReturn[ip->first] = 0;
			}
		  toReturn[ip->first] += pow(abs(ip->second), 2) * it->second;
		}
	  delete backTranslated;
	  backTranslated = NULL;
    }

  return toReturn;
}


ostream& operator<<(ostream& os, const rfacInterpolation& val)
{
  os << "State: " << val.currentState;
  return os;
}

void rfacInterpolation::PrintThisObject()
{
  cout << *this << endl;
}


void rfacInterpolation::SetState(GeneralQuantumNumbers * state)
{
  if(QuantumNumbers * nbr = dynamic_cast<QuantumNumbers *>(state))
	{
	  SetState(*nbr);
	  return;
	}
  else if(StrongFieldQuantumNumbers * nbr = dynamic_cast<StrongFieldQuantumNumbers*>(state))
	{
	  SetStrongFieldState(*nbr);
	  return;
	}
  throw RLException("Invalid SetState(ptr) called.");
}
