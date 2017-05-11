#ifndef rfacQuantumNumberContainer_hh
#define rfacQuantumNumberContainer_hh 1


#include <set>
using namespace std;


#include "TObject.h"
#include "TCollection.h"
#include "TSeqCollection.h"
#include "TList.h"


#include "QuantumNumbers.hh"
#include "rfacException.hh"


///This class is just to let the set<QuantumNumbers> be a TObject. Stupid but necessary.
class rfacQuantumNumberContainer: public set<QuantumNumbers>, public TObject
{
public:
  rfacQuantumNumberContainer();
  ~rfacQuantumNumberContainer();
  rfacQuantumNumberContainer(const rfacQuantumNumberContainer & toCopy);
  int Merge(TCollection * hlist); ///Custom merger function

  virtual const char * GetName() const;

  virtual void	Print(Option_t* option = "") const;

  ClassDef(rfacQuantumNumberContainer, 1)
};

#endif
