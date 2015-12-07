
#ifndef IIRBASE_CONCURRENT_PROCEDURE_CALL_STATEMENT_HH
#define IIRBASE_CONCURRENT_PROCEDURE_CALL_STATEMENT_HH

// Copyright (c) 1996-2003 The University of Cincinnati.  
// All rights reserved.

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
// SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
// OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
// LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING OR
// DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the U.S.,
// and the terms of this license.

// You may modify, distribute, and use the software contained in this
// package under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE"
// version 2, June 1991. A copy of this license agreement can be found in
// the file "LGPL", distributed with this archive.

// Authors: Philip A. Wilsey	philip.wilsey@ieee.org
//          Dale E. Martin	dmartin@cliftonlabs.com

//---------------------------------------------------------------------------
#include "savant_config.hh"
#include "IIRBase_ConcurrentStatement.hh"
#include "IIR_ConcurrentProcedureCallStatement.hh"

class IIR_AssociationList;
class IIR_ArchitectureStatementList;

class IIRBase_ConcurrentProcedureCallStatement : public virtual IIRBase_ConcurrentStatement, public virtual IIR_ConcurrentProcedureCallStatement{

public:
  // List Accessor(s)
  IIR_AssociationListRef           get_actual_parameter_part();
  IIR_ArchitectureStatementListRef get_process_statement_part();
  void                             set_actual_parameter_part(IIR_AssociationListRef new_actual_parameter_part);
  void                             set_process_statement_part(IIR_ArchitectureStatementListRef new_process_statement_part);

  IIR_Kind get_kind() const override { return IIR_CONCURRENT_PROCEDURE_CALL_STATEMENT; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_ConcurrentProcedureCallStatement"); }

  void set_postponed( IIR_Boolean postponed );
  IIR_Boolean get_postponed();

  void set_procedure_name( IIRRef procedure_name );
  IIRRef get_procedure_name();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  void publish_vhdl(ostream &);
protected:
  IIRBase_ConcurrentProcedureCallStatement();
  virtual ~IIRBase_ConcurrentProcedureCallStatement() = 0;
    
private:
  // List Variable(s)
  IIR_AssociationListRef           actual_parameter_part;
  IIR_ArchitectureStatementListRef process_statement_part;

  IIR_Boolean                   postponed;
  IIRRef                        procedure_name;
};

typedef refcount<IIRBase_ConcurrentProcedureCallStatement> IIRBase_ConcurrentProcedureCallStatementRef;

#endif
