
#ifndef IIRBASE_PROCEDURE_CALL_STATEMENT_HH
#define IIRBASE_PROCEDURE_CALL_STATEMENT_HH

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
#include "IIRBase_SequentialStatement.hh"
#include "IIR_ProcedureCallStatement.hh"

class IIR_AssociationList;
class IIRBase_ProcedureCallStatement : public virtual IIRBase_SequentialStatement, public virtual IIR_ProcedureCallStatement{

public:
  // List Accessor(s)
  IIR_AssociationListRef get_actual_parameter_part();
  void                set_actual_parameter_part(IIR_AssociationListRef new_actual_parameter_part);


  IIR_Kind get_kind() const override { return IIR_PROCEDURE_CALL_STATEMENT; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_ProcedureCallStatement"); }

  void set_procedure_name( IIRRef procedure_name);
  IIRRef get_procedure_name();

  IIR_Boolean is_above_attribute_found();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  void publish_vhdl(ostream &);
protected:
  
  IIRBase_ProcedureCallStatement();
  virtual ~IIRBase_ProcedureCallStatement() = 0;
    
private:
  // List Variable(s)
  IIR_AssociationListRef actual_parameter_part;
  
  IIRRef procedure_name; 

};

typedef refcount<IIRBase_ProcedureCallStatement> IIRBase_ProcedureCallStatementRef;

#endif
