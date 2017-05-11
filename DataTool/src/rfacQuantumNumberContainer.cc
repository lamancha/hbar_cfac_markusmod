#include "rfacQuantumNumberContainer.hh"

ClassImp(rfacQuantumNumberContainer)

rfacQuantumNumberContainer::rfacQuantumNumberContainer()
{

}

rfacQuantumNumberContainer::rfacQuantumNumberContainer(const rfacQuantumNumberContainer & toCopy)
{
  insert(toCopy.begin(), toCopy.end());
}

rfacQuantumNumberContainer::~rfacQuantumNumberContainer()
{

}

int rfacQuantumNumberContainer::Merge(TCollection *hlist)
{
  if (hlist) 
     {
       TIter nxh(hlist);
       while(TObject * tmp = nxh())
	 {
	   if (rfacQuantumNumberContainer * rfh = dynamic_cast<rfacQuantumNumberContainer *> (tmp) )
	     {
	       insert(rfh->begin(), rfh->end());
	     }
	 }
     }
  return 0;
}

void rfacQuantumNumberContainer::Print(Option_t* option) const
{
  cout << GetName() << " size=" << size() << endl;
}

const char * rfacQuantumNumberContainer::GetName() const
{
  return "rfacQuantumNumberContainer";
}
