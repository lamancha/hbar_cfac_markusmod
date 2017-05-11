#include "rfacLevelContainer.hh"

ClassImp(rfacLevelContainer)

rfacLevelContainer::rfacLevelContainer()
{

}

rfacLevelContainer::rfacLevelContainer(const rfacLevelContainer & toCopy)
  :vector<rfacSpecificLevelData>(toCopy)

{
}

rfacLevelContainer::~rfacLevelContainer()
{

}

int rfacLevelContainer::Merge(TCollection *hlist)
{
  if (hlist) 
     {
       TIter nxh(hlist);
       while(TObject * tmp = nxh())
	 {
	   if (rfacLevelContainer * rfh = dynamic_cast<rfacLevelContainer *> (tmp))
	     {
	       insert(this->end(), rfh->begin(), rfh->end());
	     }
	 }
     }
  return 0; ///strange return value policy here by root.
}


void rfacLevelContainer::Print(Option_t* option) const
{
  cout << GetName() << " size=" << size() << endl;
  if(strcmp(option, "v")==0)
    {
      int ptr = 0;
      for(vector<rfacSpecificLevelData>::const_iterator it = this->begin(); it!=this->end(); ++it)
	{
	  cout << "Item #" << (ptr++) << ": " << (*it) << endl;
	}
    }
}

const char * rfacLevelContainer::GetName() const
{
  return "rfacLevelContainer";
}
