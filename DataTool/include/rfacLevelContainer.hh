#ifndef rfacLevelContainer_hh
#define rfacLevelContainer_hh 1


#include <vector>
using namespace std;


#include "TObject.h"
#include "TCollection.h"

#include "rfacSpecificLevelData.hh"


///This class is just to let the vector<rfacSpecificLevelData> be a TObject. Stupid but necessary.
class rfacLevelContainer: public vector<rfacSpecificLevelData>, public TObject
{
public:
  rfacLevelContainer();
  ~rfacLevelContainer();
  rfacLevelContainer(const rfacLevelContainer & toCopy);
  int Merge(TCollection * hlist); ///Custom merger function.

  virtual const char * GetName() const;

  virtual void	Print(Option_t* option = "") const;

  ClassDef(rfacLevelContainer, 1)
};

#endif
