
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

#include "savant.hh"
#include "IIRBase_CaseStatement.hh"
#include "IIR_CaseStatementAlternativeList.hh"
#include "IIR_Label.hh"

IIRBase_CaseStatement::IIRBase_CaseStatement() {}

IIRBase_CaseStatement::~IIRBase_CaseStatement() {}

void 
IIRBase_CaseStatement::set_expression( IIRRef expression){
  my_expression = expression;
}

IIRRef
IIRBase_CaseStatement::get_expression(){
  return my_expression;
}


// List Accessor(s)
IIR_CaseStatementAlternativeListRef
IIRBase_CaseStatement::get_case_statement_alternatives() {
  ASSERT(case_statement_alternatives != NULL);
  return case_statement_alternatives;
}


void
IIRBase_CaseStatement::set_case_statement_alternatives(IIR_CaseStatementAlternativeListRef new_case_statement_alternatives) {
  ASSERT(new_case_statement_alternatives != nullptr);
  case_statement_alternatives = new_case_statement_alternatives;
}

IIRRef
IIRBase_CaseStatement::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_CaseStatementRef new_node = my_dynamic_pointer_cast<IIRBase_CaseStatement>(IIRBase_SequentialStatement::convert_tree(factory));

  // Process the variables
  new_node->case_statement_alternatives = my_dynamic_pointer_cast<IIR_CaseStatementAlternativeList>(convert_node(case_statement_alternatives, factory));
  new_node->my_expression = convert_node(my_expression, factory);

  return new_node;
}

IIR_Boolean
IIRBase_CaseStatement::is_resolved(){
  IIR_Boolean retval = TRUE;
  if( get_expression()->is_resolved() == FALSE ){
    retval = FALSE;
  }
  if( get_case_statement_alternatives()->is_resolved() == FALSE ){
    retval = FALSE;
  }
  return retval;
}

IIR_Boolean
IIRBase_CaseStatement::is_above_attribute_found() {
  IIR_Boolean retval = FALSE;
  retval = retval || get_expression()->is_above_attribute_found();
  retval = retval || get_case_statement_alternatives()->is_above_attribute_found();
  return retval;
}

void 
IIRBase_CaseStatement::publish_vhdl(ostream &vhdl_out) {
  ASSERT(get_expression() != NULL);

  publish_vhdl_stmt_label(vhdl_out);

  vhdl_out << "case ";
  ASSERT( get_expression()->is_resolved() == TRUE );
  get_expression()->publish_vhdl(vhdl_out);
  vhdl_out << " is\n";

  get_case_statement_alternatives()->publish_vhdl(vhdl_out);
  vhdl_out << "end case";

  if( get_label() != NULL ){
    vhdl_out << " ";
    get_label()->publish_vhdl(vhdl_out);
  }
}
