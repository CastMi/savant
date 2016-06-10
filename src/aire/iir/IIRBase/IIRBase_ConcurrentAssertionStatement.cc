
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

#include "IIRBase_ConcurrentAssertionStatement.hh"
#include "savant.hh"

IIRBase_ConcurrentAssertionStatement::IIRBase_ConcurrentAssertionStatement(){
  set_postponed( false );
  set_assertion_condition( NULL );
  set_report_expression( NULL );
  set_severity_expression( NULL );
}

IIRBase_ConcurrentAssertionStatement::~IIRBase_ConcurrentAssertionStatement(){}

void 
IIRBase_ConcurrentAssertionStatement::set_postponed( IIR_Boolean predicate ){
  this->predicate = predicate;
}

IIR_Boolean 
IIRBase_ConcurrentAssertionStatement::get_postponed(){
  return predicate;
}

void 
IIRBase_ConcurrentAssertionStatement::set_assertion_condition( IIR_Statement *condition){
  assertion_condition = condition;
}

IIR_Statement *
IIRBase_ConcurrentAssertionStatement::get_assertion_condition(){
  return assertion_condition;
}

void 
IIRBase_ConcurrentAssertionStatement::set_report_expression( IIR_Statement *expression ){
  report_expression = expression;
}

IIR_Statement *
IIRBase_ConcurrentAssertionStatement::get_report_expression(){
  return report_expression;
}

void 
IIRBase_ConcurrentAssertionStatement::set_severity_expression(  IIR_Statement *expression ){
  severity_expression = expression;
}

IIR_Statement *
IIRBase_ConcurrentAssertionStatement::get_severity_expression(){
  return severity_expression;
}

IIR_Statement *
IIRBase_ConcurrentAssertionStatement::convert_tree(plugin_class_factory *factory) {
  // Get the node itself
  IIRBase_ConcurrentAssertionStatement *new_node = dynamic_cast<IIRBase_ConcurrentAssertionStatement *>(IIRBase_ConcurrentStatement::convert_tree(factory));

  // Process the variables
  new_node->predicate = predicate;
  new_node->assertion_condition = assertion_condition->convert_tree(factory);
  new_node->report_expression = report_expression->convert_tree(factory);
  new_node->severity_expression = severity_expression->convert_tree(factory);

  return new_node;
}

void 
IIRBase_ConcurrentAssertionStatement::publish_vhdl(ostream &vhdl_out) {

  publish_vhdl_stmt_label(vhdl_out);

  if (get_postponed() == true) {
    vhdl_out << "postponed ";
  }
  vhdl_out << " assert ";
  get_assertion_condition()->publish_vhdl(vhdl_out);

  if(get_report_expression() != NULL) {
    vhdl_out << "\n";
    vhdl_out << "   report ";
    get_report_expression()->publish_vhdl(vhdl_out);
  }

  if(get_severity_expression() != NULL) {
    vhdl_out << "\n";
    vhdl_out << "   severity ";
    get_severity_expression()->publish_vhdl(vhdl_out);
  }

  vhdl_out << ";\n";
}
