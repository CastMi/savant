
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

#include "savant.hh"
#include "IIRBase_ProcedureCallStatement.hh"
#include "IIRBase_ProcedureDeclaration.hh"
#include "IIRBase_AssociationList.hh"
#include "IIR_InterfaceList.hh"

IIRBase_ProcedureCallStatement::IIRBase_ProcedureCallStatement() {}
IIRBase_ProcedureCallStatement::~IIRBase_ProcedureCallStatement() {}

void 
IIRBase_ProcedureCallStatement::set_procedure_name( IIRRef procedure_name) {
  this->procedure_name = procedure_name;
}

IIRRef
IIRBase_ProcedureCallStatement::get_procedure_name() {
  return procedure_name;
}

// List Accessor(s)
IIR_AssociationListRef
IIRBase_ProcedureCallStatement::get_actual_parameter_part() {
  ASSERT( actual_parameter_part != nullptr );
  return actual_parameter_part;
}


void
IIRBase_ProcedureCallStatement::set_actual_parameter_part(IIR_AssociationListRef new_actual_parameter_part) {
  ASSERT( new_actual_parameter_part != nullptr );
  actual_parameter_part = new_actual_parameter_part;
}

IIR_Boolean
IIRBase_ProcedureCallStatement::is_above_attribute_found() {
  IIR_Boolean retval = FALSE;
  retval = retval || get_actual_parameter_part()->is_above_attribute_found();
  return retval;
}

IIRRef
IIRBase_ProcedureCallStatement::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_ProcedureCallStatementRef new_node = my_dynamic_pointer_cast<IIRBase_ProcedureCallStatement>(IIRBase_SequentialStatement::convert_tree(factory));

  // Process the variables
  new_node->actual_parameter_part = my_dynamic_pointer_cast<IIR_AssociationList>(convert_node(actual_parameter_part, factory));
  new_node->procedure_name = convert_node(procedure_name, factory);

  return new_node;
}

void 
IIRBase_ProcedureCallStatement::publish_vhdl(ostream &vhdl_out) {

  int parameter_count = get_actual_parameter_part()->size();

  publish_vhdl_stmt_label(vhdl_out);

  get_procedure_name()->publish_vhdl(vhdl_out);
  
  if(get_actual_parameter_part()->size() != 0) {
    vhdl_out << "(";
    
    if (get_procedure_name()->get_kind() == IIR_PROCEDURE_DECLARATION) {
      IIRBase_ProcedureDeclarationRef procDecl = 
        my_dynamic_pointer_cast<IIRBase_ProcedureDeclaration>( get_procedure_name() );
      parameter_count = procDecl->get_interface_declarations()->size();
    }
    
    if (parameter_count != get_actual_parameter_part()->size()) {
      get_actual_parameter_part()->publish_vhdl(vhdl_out);
    }
    else {
       my_dynamic_pointer_cast<IIRBase_AssociationList>
	(get_actual_parameter_part())->publish_vhdl_without_formals(vhdl_out);
    }
    vhdl_out << ")";
  }
}
