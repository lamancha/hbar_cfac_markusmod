#ifndef rfacInterpolatorPicker_hh
#define rfacInterpolatorPicker_hh 1

#include <set>



#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TSelector.h"
#include "TObject.h"

#include "QuantumNumbers.hh"

#include "rfacEssentialData.hh"
#include "rfacSpecificLevelData.hh"
#include "EnergyLevel.hh"
#include "rfacInterpolatorContainer.hh"
#include "rfacException.hh"

#include <iostream>

/**
   Searches through the output of a tree created by rootfitmake and returns the single data point that corresponds to the given quantum number.
 */
class rfacInterpolatorPicker: public TSelector
{
public :
  rfacInterpolatorPicker(TTree * myTree = 0 ///The tree to search in.
			  ); ///Constructor.
  virtual ~rfacInterpolatorPicker(); /// Destructor.
  
  virtual void    Init(TTree *tree
		       ); ///Default function, @see ROOT help.

  virtual void    SlaveBegin(TTree *tree
			     );///Default function, @see ROOT help.

  virtual Bool_t  Process(Long64_t entry
			  );///Default function, @see ROOT help.

  virtual void    Terminate();///Default function, @see ROOT help.

  virtual Int_t   Version() const { return 2; }///Default function, @see ROOT help. NOTE: Must return at least 2.

  virtual void    SlaveTerminate();///Default, se ROOT documentation.

private:
  rfacInterpolatorContainer * found;
  TString myBranchName; ///The branch name to use.
  rfacInterpolatorContainer * myInterpolatorContainer; ///Interpolator container to use.
  TBranch     * dataBranch;   ///The branch to use (a pointer to it).
  QuantumNumbers target; /// Target quantum number.
  ClassDef(rfacInterpolatorPicker,1)
};


#endif
