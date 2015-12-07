
#ifndef IIR_WAIT_STATEMENT_HH
#define IIR_WAIT_STATEMENT_HH

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

// Authors: Philip A. Wilsey	phil.wilsey@uc.edu
//          Dale E. Martin	dmartin@cliftonlabs.com
//          Malolan Chetlur     mal@ece.uc.edu

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIR_SequentialStatement.hh"

REF_FORWARD_DECL(IIR_DesignatorList);

class IIR_WaitStatement : public virtual IIR_SequentialStatement{
public:
  virtual ~IIR_WaitStatement() {}    

  // List accessor(s)
  virtual IIR_DesignatorListRef get_sensitivity_list() = 0;
  virtual void                  set_sensitivity_list(IIR_DesignatorListRef ) = 0;

  virtual void set_condition_clause( IIRRef condition_clause) = 0;
  virtual IIRRef get_condition_clause() = 0;
  virtual void set_timeout_clause( IIRRef timeout_clause) = 0;
  virtual IIRRef get_timeout_clause() = 0;
};

typedef refcount<IIR_WaitStatement> IIR_WaitStatementRef;

#endif
