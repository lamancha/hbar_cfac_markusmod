#include "rfacDB.hh"

rfacDB::rfacDB(vector<string> filenames, bool printInfo)
{
  verbose = printInfo;
  vector<pair<FILE *, rfacF*> > filesAndHeaders;

  //Open files and read headers.
  for(vector<string>::iterator it = filenames.begin(); it!=filenames.end(); it++)
    {
      FILE * f = fopen(it->c_str(), "rb");
      if(f == NULL)
	throw rfacException("Could not open file '" + *it + "'.");
      headers.push_back(new rfacF(f));
      if(verbose)
	headers.back()->Print();
      filesAndHeaders.push_back(make_pair(f, headers.back()));
    }
  
  //Process the headers. Basically we need to read the files in a certain order:
  vector<int> order; OA(DB_EN); OA(DB_ENF); OA(DB_TR); OA(DB_TRF);

  //First check that all file types are supported.
  for(vector< pair< FILE *, rfacF* > >::iterator it = filesAndHeaders.begin(); it!=filesAndHeaders.end(); it++)
    {
      if(find(order.begin(), order.end(), it->second->getType())==order.end())
	{
	  char buffer[400];
	  sprintf(buffer, "Unsupported file type: %d.", it->second->getType());
	  throw rfacException(buffer);
	}
    }
   
   rfacEN * myEn = NULL;
   rfacENF * myEnf = NULL;

   for(vector<int>::iterator ip = order.begin(); ip!=order.end(); ip++)
     {	
       for(vector<pair<FILE *, rfacF*> >::iterator it = filesAndHeaders.begin(); it!=filesAndHeaders.end(); it++)
	 {
	   if(it->second->getType()==*ip)
	     {
	       switch(*ip)
		 {
		 case DB_EN:       //Energy levels without a field.
		   {
		     myEn = new rfacEN(it->first,it->second->getSwp());
		     constructed.push_back(myEn);
		     if(verbose)
		       myEn->Print();
		   }
		   break;
		case DB_TR: //Transitions without a field.
		  {
		    if(myEn == NULL)
		      {
			throw rfacException("Energy level file not specified.");
		      }
		    rfacTR * myTr = new rfacTR(it->first, it->second->getSwp(), myEn);
		    constructed.push_back(myTr);
		    if(verbose)
		      myTr->Print();
		  }
		  break;
		 case DB_ENF: //Energy levels under a field.
		   {
		     myEnf = new rfacENF(it->first, it->second->getSwp());
		     constructed.push_back(myEnf);
		     if(verbose)
		       myEnf->Print();
		   }
		   break;
		 case DB_TRF: //Transition under a field.
		   {
		     if(myEnf == NULL)
		       {
			 throw rfacException("Energy level (field) file not specified.");
		       }
		     rfacTRF * myTrf = new rfacTRF(it->first,it->second->getSwp(), myEnf);
		     constructed.push_back(myTrf);
		     if(verbose)
		       myTrf->Print();
		   }
		   break;
		 }	       
	     }
	 }
     }
       

  //Close file pointers.
  for(vector<pair<FILE *, rfacF*> >::iterator it = filesAndHeaders.begin(); it!=filesAndHeaders.end(); it++)
    {
      fclose(it->first);
    }
}

rfacDB::~rfacDB()
{
  for(vector<rfacF *>::iterator it = headers.begin(); it!=headers.end(); it++)
    {
      delete *it;
    }
  for(vector<facFile *>::iterator it = constructed.begin(); it!=constructed.end(); it++)
    {
      delete *it;
    }
}

vector <rfacF*> rfacDB::getHeaders()
{ 
  return headers;
}

vector <facFile *> rfacDB::getData()
{ 
  return constructed;
}
vector <facFile *> rfacDB::getSpecificData(int dataType)
{
  vector<facFile *> toReturn;
  for(vector<facFile *>::iterator it = constructed.begin(); it!=constructed.end(); ++it)
    {
      switch(dataType)
	{
	case DB_EN:
	  {
	    if(dynamic_cast<rfacEN *>(*it)!=NULL)
	      toReturn.push_back(*it);
	  }
	  break;
	case DB_TR:
	  {
	    if(dynamic_cast<rfacTR *>(*it)!=NULL)
	      toReturn.push_back(*it);	    
	  }
	  break;
	case DB_ENF:
	  {
	    if(dynamic_cast<rfacENF *>(*it)!=NULL)
	      toReturn.push_back(*it);
	  }
	  break;
	case DB_TRF:
	  {
	    if(dynamic_cast<rfacTRF *>(*it)!=NULL)
	      toReturn.push_back(*it);
	  }
	  break;
	default:
	  throw rfacException("Invalid data type");
	}
    }
  return toReturn;
}
