#include "rfacFieldGridContainer.hh"

ClassImp(rfacFieldGridContainer)

rfacFieldGridContainer::rfacFieldGridContainer()
{

}

rfacFieldGridContainer::rfacFieldGridContainer(const rfacFieldGridContainer & toCopy)
{
  insert(toCopy.begin(), toCopy.end());
}

rfacFieldGridContainer::~rfacFieldGridContainer()
{

}

int rfacFieldGridContainer::Merge(TCollection *hlist)
{
  if (hlist) 
     {
       TIter nxh(hlist);
       while(TObject * tmp = nxh())
	 {
	   if (rfacFieldGridContainer * rfh = dynamic_cast<rfacFieldGridContainer *> (tmp) )
	     {
	       insert(rfh->begin(), rfh->end());
	     }
	 }
     }
  return 0; ///strange return value policy here by root.
}


void rfacFieldGridContainer::Print(Option_t* option) const
{
  cout << GetName() << " size=" << size() << endl;
}

const char * rfacFieldGridContainer::GetName() const
{
  return "rfacFieldGridContainer";
}
