#ifndef rfacLevelPicker_hh
#define rfacLevelPicker_hh 1

#include <vector>



#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TSelector.h"

#include "QuantumNumbers.hh"

#include "rfacEssentialData.hh"
#include "rfacSpecificLevelData.hh"
#include "rfacException.hh"
#include "rfacLevelContainer.hh"

/**
   Searches through the output of a tree created by rootgen and returns all data points corresponding to a specific target quantum number.
 */
class rfacLevelPicker: public TSelector
{
public :

   
  rfacLevelPicker(TTree * myTree = 0
		  ); ///Default, se ROOT documentation.
  virtual ~rfacLevelPicker(); ///Default, se ROOT documentation.
  
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
  QuantumNumbers * target; //! Target quantum number.
  TString myBranchName; //! The branch name.
  rfacEssentialData * myEssentialData; //! The essential data object.
  rfacLevelContainer * returnValues; //! Return values.
  ClassDef(rfacLevelPicker,1)
};


#endif
