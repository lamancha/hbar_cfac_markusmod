#ifndef rfacFieldGridPicker_hh
#define rfacFieldGridPicker_hh 1

#include <vector>

#include <iostream>

#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TSelector.h"
#include "TObjString.h"

#include "QuantumNumbers.hh"

#include "rfacEssentialData.hh"
#include "rfacSpecificLevelData.hh"

#include "rfacFieldGridPoint.hh"
#include "rfacFieldGridContainer.hh"

/**
   Searches through the output of a tree created by rootgen and returns all data points corresponding to a specific target quantum number.
 */
class rfacFieldGridPicker: public TSelector
{
public :
   
  rfacFieldGridPicker(TTree * myTree = 0
		  ); ///Default, se ROOT documentation.
  virtual ~rfacFieldGridPicker(); ///Default, se ROOT documentation.
  
  virtual void    Init(TTree *tree
		       ); ///Default, se ROOT documentation.
  virtual void    SlaveBegin(TTree *tree
			     );///Default, se ROOT documentation.
  virtual Bool_t  Process(Long64_t entry
			  );///Default, se ROOT documentation.
  virtual void    Terminate();///Default, se ROOT documentation.
  virtual void    SlaveTerminate();///Default, se ROOT documentation.
  virtual Int_t   Version() const { return 2; }///Default, se ROOT documentation.

private:
  TBranch     * dataBranch;  //! The branch in question.
  QuantumNumbers target; //! Target quantum number.
  TString myBranchName; //! The branch name.
  rfacEssentialData * myEssentialData; //! The essential data object.
  rfacFieldGridContainer * returnValues; //! Return values.
  ClassDef(rfacFieldGridPicker,1)
};


#endif
