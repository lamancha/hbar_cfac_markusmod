#include "rfacEssentialDataReader.hh"

long double rfacEssentialDataReader::decayCut; ///Warning: static. A bit ugly.

rfacEssentialDataReader::rfacEssentialDataReader(string directoryName, VerbosePrinter * myPrinter, unsigned int nThreads)
{
  RegisterListener(myPrinter);
  decayCut = 1E-300;


  myMultiTasker = new MultiTasker<string, rfacEssentialData *>(&ReadObject, nThreads);
  myMultiTasker->LimitOutputQueueSize(50);

  vector<string> directoryNames = getDirectoryContent(directoryName); //Should be a list of directories.
  totalCount = directoryNames.size();
  for(vector<string>::iterator it = directoryNames.begin(); it!=directoryNames.end(); ++it)
    {
      it->insert(0,"/");
      it->insert(0,directoryName);
      myMultiTasker->AddInput(*it);
    }
  myMultiTasker->LaunchThreads();
}

void rfacEssentialDataReader::SetDecayCut(long double value)
{
  decayCut = value;
}

rfacEssentialDataReader::~rfacEssentialDataReader()
{
  delete myMultiTasker;
}

unsigned long long rfacEssentialDataReader::GetOutputQueueSize()
{
  return myMultiTasker->GetOutputSize();
}


rfacEssentialData * rfacEssentialDataReader::ReadObject(string loopDirectoryName)
{
  rfacEssentialData * myData = NULL; //object to return.
  vector<string> subdirectories = getDirectoryContent(loopDirectoryName);
  for(vector<string>::iterator it = subdirectories.begin(); it!=subdirectories.end(); ++it)
    {
      it->insert(0,"/");
      it->insert(0,loopDirectoryName);
      vector<string> filenames = getDirectoryContent(*it);
      for(vector<string>::iterator ip = filenames.begin(); ip!=filenames.end(); ++ip)
		{
		  ip->insert(0,"/");
		  ip->insert(0,*it);
		}

      rfacDB myDb(filenames, false);
  
      vector<facFile *> myNonSplittedLevels = myDb.getSpecificData(DB_EN);
      if(myNonSplittedLevels.size()!=1)
		{
		  char buffer[400];
		  sprintf(buffer, "Invalid number of plain energy level files in directory %s", it->c_str());
		  throw rfacException(buffer);
		}
	  
      vector<facFile *> mySplittedLevels = myDb.getSpecificData(DB_ENF);
      if(mySplittedLevels.size()!=1)
		{
		  char buffer[400];
		  sprintf(buffer, "Invalid number of field energy level files in directory %s", it->c_str());
		  throw rfacException(buffer);
		}
      
      vector<facFile *> myDecays = myDb.getSpecificData(DB_TRF);
      if(myDecays.size()!=1)
		{
		  char buffer[400];
		  sprintf(buffer, "Invalid number of decay files in directory %s", it->c_str());
		  printf("%s\n",buffer);
		  continue;  ///Well, if you don't have the data, we have to skip this level.
		  //throw rfacException(buffer);
		}
	  
      rfacEN * myEn = dynamic_cast<rfacEN *>(myNonSplittedLevels.front()); 
      rfacENF * myEnf = dynamic_cast<rfacENF *>(mySplittedLevels.front()); 
      rfacTRF * myTrf = dynamic_cast<rfacTRF *>(myDecays.front());
	  
      if(it == subdirectories.begin())
		{
		  //Build the essential object.
		  myData = new rfacEssentialData();
		  myData->EField = myEnf->getEField();
		  myData->BField = myEnf->getBField();
		  myData->FieldAngle = myEnf->getFieldAngle();
		}
      else
		{
		  if(!double_equal(myData->EField, myEnf->getEField()))
			{
			  char buffer[400];
			  sprintf(buffer, "Invalid E-field for this directory. Was: %13.6E, expected: %13.6E", myEnf->getEField(), myData->EField);
			  throw rfacException(buffer);
			}
		  if(!double_equal(myData->BField, myEnf->getBField()))
			{
			  char buffer[400];
			  sprintf(buffer, "Invalid B-field for this directory. Was: %13.6E, expected: %13.6E", myEnf->getBField(), myData->BField);
			  throw rfacException(buffer);
			}
		  if(!double_equal(myData->FieldAngle, myEnf->getFieldAngle()))
			{
			  char buffer[400];
			  sprintf(buffer, "Invalid FieldAngle for this directory. Was: %13.6E, expected: %13.6E", myEnf->getFieldAngle(), myData->FieldAngle);
			  throw rfacException(buffer);
			  
			}
		}
	  
      
      double minEnergy = 1E99;
	  
      for(int i = 0; i<myEnf->getNumberOfLevels(); ++i)
		{
		  if(myEnf->getEnergy(i) < minEnergy)
			{
			  minEnergy = myEnf->getEnergy(i);
			}
		}
      
      for(int i = 0; i<myEnf->getNumberOfLevels(); ++i)
		{
		  QuantumNumbers myQuantumNumbers = EnfLevelToQuantumNumbers(myEn, myEnf, i);
		  myData->Levels[myQuantumNumbers].Energy = myEnf->getEnergy(i)-minEnergy; //We want the lowest level to be the ground state, right...?
		}
      
      for(int i = 0; i<myTrf->getNumberOfTransitions(); ++i)
		{
		  QuantumNumbers from = EnfLevelToQuantumNumbers(myEn, myEnf, myTrf->getUpperLevel(i));
		  QuantumNumbers to = EnfLevelToQuantumNumbers(myEn, myEnf, myTrf->getLowerLevel(i));
		  double energyDifference = (myData->Levels[from].Energy-myData->Levels[to].Energy);
		  int multipole = myTrf->getMultipole();
		  int nq = 2*abs(multipole)+1;
		  
		  double a = 0; //Decay rate for specific j branch.
		  double totalA = 0; //The total decay rate (what we want here).
		  for (int j = 0; j < nq; j++) 
			{
			  int gf = OscillatorStrength(multipole, energyDifference/HARTREE_EV, (double)((myTrf->getTransitionStrength(i))[j]), &a);///HERE WAS HUGE BUG, forgot to divide by HARTREE_EV.
			  a *= RATE_AU;

			  if(a>0) ///We only care about the positive ones since we only want spontaneous decay.
				totalA += a;

			  /*			  if((myData->BField == 2.34180 || myData->BField == 2.34183) && from == QuantumNumbers(2, 1, 3, 1, -1) && a > 0 && to.GetN() == 1)
			{
			  cout << "FIELD " << myData->BField << " FROM " << from << " TO " << to << " RATE " << totalA << " ED " << energyDifference << " lower " <<myTrf->getLowerLevel(i) << " upper " << myTrf->getUpperLevel(i) << " s " << ((myTrf->getTransitionStrength(i))[j]) << endl;

			  }*/



			  //cout << "FROM " << from << " TO " << to << " MPOLE: " << multipole << " EDIFF: " << energyDifference/HARTREE_EV << " TSTR: " << std::scientific << (double)((myTrf->getTransitionStrength(i))[j]) << " A: " << a << " " << endl;
			  (void)gf; ///Avoid compiler warning.
			}
		  if(totalA > decayCut) /// Used to remove negative or zero stuff.
			{
			  myData->Levels[from].DecayRates[to]=totalA;
			}
		  else
			{
			  ///Don't add it if it is zero. Further analysis software should assume no entry => zero.
			}
		}
    }
  //  myData->PrintStats();
  return myData;
}



bool rfacEssentialDataReader::double_equal(const double &d1, const double &d2)
{
  return ((abs(d1-d2)/abs(d1+d2+1E-10)) < EPS);
}


QuantumNumbers rfacEssentialDataReader::EnfLevelToQuantumNumbers(rfacEN * myEn, rfacENF * myEnf, unsigned int enfLevel)
{
  QuantumNumbers toReturn;
  toReturn.SetN(myEn->getN(myEnf->getInitialLevel(enfLevel)));
  toReturn.SetL(myEn->getL(myEnf->getInitialLevel(enfLevel)));
  toReturn.SetTwoJ(myEn->get2J(myEnf->getInitialLevel(enfLevel)));
  toReturn.SetTwoMJ(myEnf->getM(enfLevel)*myEnf->getParity(enfLevel));
  return toReturn;
}


rfacEssentialData * rfacEssentialDataReader::GetNext()
{
  if(!HasNext())
    {
      throw rfacException("There are no more entries to read.");
    }
  return myMultiTasker->GetOutput();
}


bool rfacEssentialDataReader::HasNext()
{
  return myMultiTasker->GetInputMinusOutput() > 0;
}


//lists the content of a directory
vector<string> rfacEssentialDataReader::getDirectoryContent(const string directoryName)
{
  vector<string> toReturn;

  struct dirent **eps = NULL;
  int n;

  n = scandir (directoryName.c_str(), &eps, one, alphasort);
  if (n >= 0)
    {
      int cnt;
      for (cnt = 0; cnt < n; ++cnt)
	{
	  string tmp(eps[cnt]->d_name);
	  //Exclude some stuff that shouldn't be here.
	  if(!(tmp.compare(".")==0 || tmp.compare("..")==0 || tmp.compare(".svn")==0 || tmp.compare(".git")==0 || tmp.compare(".hg")==0))
	    toReturn.push_back(eps[cnt]->d_name);
	}
    }
  else
    {
      perror ("Couldn't open the directory");
    }
  return toReturn;
}

unsigned int rfacEssentialDataReader::GetTotalCount()
{
  return totalCount;
}
