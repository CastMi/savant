
#ifndef IIR_CONCURRENT_PROCEDURE_CALL_STATEMENT_HH
#define IIR_CONCURRENT_PROCEDURE_CALL_STATEMENT_HH

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

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIR_ConcurrentStatement.hh"

REF_FORWARD_DECL(IIR_AssociationList);
REF_FORWARD_DECL(IIR_ArchitectureStatementList);

class IIR_ConcurrentProcedureCallStatement : public virtual IIR_ConcurrentStatement{

public:
  virtual ~IIR_ConcurrentProcedureCallStatement() {}
    
  // List accessor(s)
  virtual IIR_AssociationListRef get_actual_parameter_part() = 0;
  virtual IIR_ArchitectureStatementListRef get_process_statement_part() = 0;
  virtual void                          set_actual_parameter_part(IIR_AssociationListRef ) = 0;
  virtual void                          set_process_statement_part(IIR_ArchitectureStatementListRef ) = 0;

  virtual void set_postponed( IIR_Boolean postponed ) = 0;
  virtual IIR_Boolean get_postponed() = 0;

  virtual void set_procedure_name( IIRRef procedure_name ) = 0;
  virtual IIRRef get_procedure_name() = 0;
};

typedef refcount<IIR_ConcurrentProcedureCallStatement> IIR_ConcurrentProcedureCallStatementRef;

#endif
