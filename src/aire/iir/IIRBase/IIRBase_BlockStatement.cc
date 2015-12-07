
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

#include "set.hh"
#include "IIR_ArchitectureStatementList.hh"
#include "IIR_GenericList.hh"
#include "IIR_AssociationList.hh"
#include "IIR_PortList.hh"
#include "IIRBase_DeclarationList.hh"
#include "IIR_Label.hh"
#include "IIR_SignalDeclaration.hh"
#include "IIRBase_BlockStatement.hh"

IIRBase_BlockStatement::IIRBase_BlockStatement() {}
IIRBase_BlockStatement::~IIRBase_BlockStatement() {}

void 
IIRBase_BlockStatement::set_guard_expression( IIRRef new_guard_expression ){
  guard_expression = new_guard_expression;
}

IIRRef
IIRBase_BlockStatement::get_guard_expression(){
  return guard_expression;
}

// List Accessor(s)
IIR_GenericListRef
IIRBase_BlockStatement::get_generic_clause() {
  ASSERT(generic_clause != nullptr);
  return generic_clause;
}

IIR_AssociationListRef
IIRBase_BlockStatement::get_generic_map_aspect() {
  ASSERT(generic_map_aspect != nullptr);
  return generic_map_aspect;
}

IIR_PortListRef
IIRBase_BlockStatement::get_port_clause() {
  ASSERT(port_clause != nullptr);
  return port_clause;
}

IIR_AssociationListRef
IIRBase_BlockStatement::get_port_map_aspect() {
  ASSERT(port_map_aspect != nullptr);
  return port_map_aspect;
}

IIR_DeclarationListRef
IIRBase_BlockStatement::get_block_declarative_part() {
  ASSERT(block_declarative_part != nullptr);
  return block_declarative_part;
}

IIR_ArchitectureStatementListRef
IIRBase_BlockStatement::get_block_statement_part() {
  ASSERT(block_statement_part != nullptr);
  return block_statement_part;
}

void
IIRBase_BlockStatement::set_generic_clause(IIR_GenericListRef new_generic_clause) {
  ASSERT(new_generic_clause != nullptr);
  generic_clause = new_generic_clause;
}

void
IIRBase_BlockStatement::set_generic_map_aspect(IIR_AssociationListRef new_generic_map_aspect) {
  ASSERT(new_generic_map_aspect != nullptr);
  generic_map_aspect = new_generic_map_aspect;
}

void
IIRBase_BlockStatement::set_port_clause(IIR_PortListRef new_port_clause) {
  ASSERT(new_port_clause != nullptr);
  port_clause = new_port_clause;
}

void
IIRBase_BlockStatement::set_port_map_aspect(IIR_AssociationListRef new_port_map_aspect) {
  ASSERT(new_port_map_aspect != nullptr);
  port_map_aspect = new_port_map_aspect;
}

void
IIRBase_BlockStatement::set_block_declarative_part(IIR_DeclarationListRef new_block_declarative_part) {
  ASSERT(new_block_declarative_part != nullptr);
  block_declarative_part = new_block_declarative_part;
}

void
IIRBase_BlockStatement::set_block_statement_part(IIR_ArchitectureStatementListRef new_block_statement_part) {
  ASSERT(new_block_statement_part != nullptr);
  block_statement_part = new_block_statement_part;
}

IIRRef
IIRBase_BlockStatement::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_BlockStatementRef new_node = my_dynamic_pointer_cast<IIRBase_BlockStatement>(IIRBase_ConcurrentStatement::convert_tree(factory));

  // Process the variables
  new_node->generic_clause =
    my_dynamic_pointer_cast<IIR_GenericList>(convert_node(generic_clause, factory));
  new_node->generic_map_aspect =
    my_dynamic_pointer_cast<IIR_AssociationList>(convert_node(generic_map_aspect, factory));
  new_node->port_clause =
    my_dynamic_pointer_cast<IIR_PortList>(convert_node(port_clause, factory));
  new_node->port_map_aspect =
    my_dynamic_pointer_cast<IIR_AssociationList>(convert_node(port_map_aspect, factory));
  new_node->block_declarative_part =
    my_dynamic_pointer_cast<IIR_DeclarationList>(convert_node(block_declarative_part, factory));
  new_node->block_statement_part =
    my_dynamic_pointer_cast<IIR_ArchitectureStatementList>(convert_node(block_statement_part, factory));
  new_node->guard_expression =
    convert_node(guard_expression, factory);
  new_node->implicit_guard_signal =
    my_dynamic_pointer_cast<IIR_SignalDeclaration>(convert_node(implicit_guard_signal, factory));

  return new_node;
}

void 
IIRBase_BlockStatement::set_implicit_guard_signal(IIR_SignalDeclarationRef new_implicit_guard_signal ){
  implicit_guard_signal = new_implicit_guard_signal;
}

IIR_SignalDeclarationRef
IIRBase_BlockStatement::get_implicit_guard_signal(  ){
  return implicit_guard_signal;
}

savant::set<IIR_DeclarationRef>
IIRBase_BlockStatement::find_declarations( IIR_NameRef to_find){
  savant::set<IIR_DeclarationRef> retval;
  
  savant::set<IIR_DeclarationRef> current_set = get_port_clause()->find_declarations(to_find );
  
  retval.insert( current_set );

  current_set = get_generic_clause()->find_declarations(to_find );
  retval.insert( current_set );

  current_set = get_block_declarative_part()->find_declarations(to_find );
  retval.insert( current_set );

  return retval;
}

void 
IIRBase_BlockStatement::publish_vhdl(ostream &vhdl_out) {

  publish_vhdl_stmt_label(vhdl_out);

  vhdl_out << "  block ";
  if( get_guard_expression() != NULL) {
    vhdl_out << "(";
    get_guard_expression()->publish_vhdl(vhdl_out);
    vhdl_out << ")";
    vhdl_out << " is\n";
  }

  if(get_generic_clause()->size() != 0) {
    vhdl_out << "   generic ( ";
    get_generic_clause()->publish_vhdl(vhdl_out);
    vhdl_out << " );\n";

    if(get_generic_map_aspect()->size() != 0) {
      vhdl_out << "   generic map ( ";
      get_generic_map_aspect()->publish_vhdl(vhdl_out);
      vhdl_out << " );\n";
    }
  }

  if(get_port_clause()->size() != 0) {
    vhdl_out << "   port ( ";
    get_port_clause()->publish_vhdl(vhdl_out);
    vhdl_out << " );\n";

    if(get_port_map_aspect()->size() != 0) {
      vhdl_out << "   port map ( ";
      get_port_map_aspect()->publish_vhdl(vhdl_out);
      vhdl_out << " );\n";
    }
  }

  my_dynamic_pointer_cast<IIRBase_DeclarationList>
    (get_block_declarative_part())->publish_vhdl_decl(vhdl_out);

  vhdl_out << " begin\n";
  get_block_statement_part()->publish_vhdl(vhdl_out);
  vhdl_out << " end block ";

  if (get_label() != NULL) {
    get_label()->publish_vhdl(vhdl_out);
  }  
  vhdl_out << ";\n";
}
