
// Copyright (c) 2002-2003 The University of Cincinnati.
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

// Authors: Harish Venkataramani venkath@ececs.uc.edu

//---------------------------------------------------------------------------




#include "IIRBase_SimultaneousIfStatement.hh"
#include "savant.hh"
#include "IIR_ArchitectureStatementList.hh"
#include "IIR_Label.hh"
#include "IIR_SimultaneousElsif.hh"

IIRBase_SimultaneousIfStatement::IIRBase_SimultaneousIfStatement() {}
IIRBase_SimultaneousIfStatement::~IIRBase_SimultaneousIfStatement(){}

void
IIRBase_SimultaneousIfStatement::set_condition( IIRRef new_condition ){
  condition = new_condition;
}

IIRRef
IIRBase_SimultaneousIfStatement::get_condition(){
  return condition;
}

void
IIRBase_SimultaneousIfStatement::set_elsif( IIR_SimultaneousElsifRef new_elsif_clause ){
  elsif_clause = new_elsif_clause;
}

IIR_SimultaneousElsifRef
IIRBase_SimultaneousIfStatement::get_elsif(){
  return elsif_clause;
}

// List Accessors
IIR_ArchitectureStatementListRef
IIRBase_SimultaneousIfStatement::get_then_statement_list() {
  ASSERT(then_statement_list != NULL);
  return then_statement_list;
}

IIR_ArchitectureStatementListRef
IIRBase_SimultaneousIfStatement::get_else_statement_list() {
  ASSERT(else_statement_list != NULL);
  return else_statement_list;
}

void                          
IIRBase_SimultaneousIfStatement::set_then_statement_list(IIR_ArchitectureStatementListRef new_list) {
  ASSERT(new_list != NULL);

  then_statement_list = new_list;
}

void                          
IIRBase_SimultaneousIfStatement::set_else_statement_list(IIR_ArchitectureStatementListRef new_list) {
  ASSERT(new_list != NULL);

  else_statement_list = new_list;
}

IIRRef
IIRBase_SimultaneousIfStatement::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_SimultaneousIfStatementRef new_node = my_dynamic_pointer_cast<IIRBase_SimultaneousIfStatement>(IIRBase_SimultaneousStatement::convert_tree(factory));

  // Process the variables
  new_node->then_statement_list = my_dynamic_pointer_cast<IIR_ArchitectureStatementList>(convert_node(then_statement_list, factory));
  new_node->else_statement_list = my_dynamic_pointer_cast<IIR_ArchitectureStatementList>(convert_node(else_statement_list, factory));
  new_node->condition = convert_node(condition, factory);
  new_node->elsif_clause = my_dynamic_pointer_cast<IIR_SimultaneousElsif>(convert_node(elsif_clause, factory));

  return new_node;
}

void
IIRBase_SimultaneousIfStatement::publish_vhdl(ostream &vhdl_out) { 
  publish_vhdl_stmt_label(vhdl_out);
  vhdl_out << " if ( ";
  get_condition()->publish_vhdl(vhdl_out);
  vhdl_out <<" )" ;
  vhdl_out << " use\n " ;
  if ( get_then_statement_list()->size() != 0 ) {
    get_then_statement_list()->publish_vhdl(vhdl_out);
  }
  if( get_elsif() != NULL ) {
    get_elsif()->publish_vhdl(vhdl_out);
  }
  if ( get_else_statement_list()->size() != 0 ) {
    vhdl_out << " else\n ";
    get_else_statement_list()->publish_vhdl(vhdl_out);
  }
  vhdl_out << " end use " ;
  vhdl_out << ";\n " ;
}
