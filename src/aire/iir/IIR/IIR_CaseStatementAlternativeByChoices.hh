
#ifndef IIR_CASE_STATEMENT_ALTERNATIVE_BY_CHOICES_HH
#define IIR_CASE_STATEMENT_ALTERNATIVE_BY_CHOICES_HH

// Copyright (c) 1996-1999 The University of Cincinnati.  
// All rights reserved.

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF 
// THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE
// FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
// RESULT OF USING, MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS
// DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the
// U.S., and the terms of this license.


// You may modify, distribute, and use the software contained in this package
// under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE" version 2,
// June 1991. A copy of this license agreement can be found in the file
// "LGPL", distributed with this archive.

// Authors: Timothy J. McBrayer tmcbraye@ece.uc.edu

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIR_CaseStatementAlternative.hh"

REF_FORWARD_DECL(IIR_ChoiceList);

/*
 * Element simple name
 */
class IIR_CaseStatementAlternativeByChoices : public virtual IIR_CaseStatementAlternative{

public:
  virtual ~IIR_CaseStatementAlternativeByChoices() {}
    
  // List accessor(s)
  virtual IIR_ChoiceListRef get_choices() = 0;
  virtual void                  set_choices(IIR_ChoiceListRef ) = 0;
};

typedef refcount<IIR_CaseStatementAlternativeByChoices> IIR_CaseStatementAlternativeByChoicesRef;

#endif
