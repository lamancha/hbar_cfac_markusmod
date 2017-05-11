#ifndef rfacFieldGridContainer_hh
#define rfacFieldGridContainer_hh 1


#include <set>
using namespace std;


#include "TObject.h"
#include "TCollection.h"
#include "TList.h"


#include "rfacFieldGridPoint.hh"
#include "rfacException.hh"


///This class is just to let the set<rfacFieldGridPoint> be a TObject. Stupid but necessary.
class rfacFieldGridContainer: public set<rfacFieldGridPoint>, public TObject
{
public:
  rfacFieldGridContainer();
  ~rfacFieldGridContainer();
  rfacFieldGridContainer(const rfacFieldGridContainer & toCopy);
  int Merge(TCollection * hlist); ///Custom merger function.

  virtual const char * GetName() const;

  virtual void	Print(Option_t* option = "") const;

  ClassDef(rfacFieldGridContainer, 1)
};

#endif
