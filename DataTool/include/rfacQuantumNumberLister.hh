#ifndef rfacQuantumNumberLister_hh
#define rfacQuantumNumberLister_hh 1

#include <set>


#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TSelector.h"

#include "QuantumNumbers.hh"

#include "rfacEssentialData.hh"
#include "rfacSpecificLevelData.hh"
#include "EnergyLevel.hh"
#include "rfacQuantumNumberContainer.hh"
#include "rfacException.hh"
#include <stdio.h>
#include <cstdlib>

/**
   Searches through the output of a tree created by rootgen and returns all data points corresponding to a specific target quantum number.
 */
class rfacQuantumNumberLister: public TSelector
{
public :
  rfacQuantumNumberLister(TTree * myTree = 0 ///The tree to search in.
			  ); ///Constructor.
  virtual ~rfacQuantumNumberLister(); /// Destructor.
  
  virtual void    Init(TTree *tree
		       ); ///Default function, @see ROOT help.

  virtual void    SlaveBegin(TTree *tree
			     );///Default function, @see ROOT help.

  virtual Bool_t  Process(Long64_t entry
			  );///Default function, @see ROOT help.

  virtual void    Terminate();///Default function, @see ROOT help.

  virtual void    SlaveTerminate();///Default, se ROOT documentation.

  virtual Int_t   Version() const { return 2; }///Default function, @see ROOT help. NOTE: Must return at least 2.

  
private:
  rfacQuantumNumberContainer * returnValues; //! Return values.
  TString myBranchName; //! The branch name to use.
  rfacEssentialData * myEssentialData; //! The essential data to use.
  TBranch     * dataBranch;   //! The branch to use (a pointer to it).
  ClassDef(rfacQuantumNumberLister,1)
};


#endif
