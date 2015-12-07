
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
#include "IIR_ArchitectureStatementList.hh"
#include "IIR_ConstantDeclaration.hh"
#include "IIR_Label.hh"
#include "IIRBase_DeclarationList.hh"
#include "IIRBase_TypeDefinition.hh"
#include "IIRBase_ConcurrentGenerateForStatement.hh"

IIRBase_ConcurrentGenerateForStatement::IIRBase_ConcurrentGenerateForStatement() {}

IIRBase_ConcurrentGenerateForStatement::~IIRBase_ConcurrentGenerateForStatement() {}

void 
IIRBase_ConcurrentGenerateForStatement::set_generate_parameter_specification(IIR_ConstantDeclarationRef new_parameter){
  parameter = new_parameter;
}

IIR_ConstantDeclarationRef
IIRBase_ConcurrentGenerateForStatement::get_generate_parameter_specification(){
  return parameter;
}

// List Accessor(s)
IIR_DeclarationListRef IIRBase_ConcurrentGenerateForStatement::get_block_declarative_part() {
  ASSERT(block_declarative_part != nullptr);
  return block_declarative_part;
}

IIR_ArchitectureStatementListRef IIRBase_ConcurrentGenerateForStatement::get_concurrent_statement_part() {
  ASSERT(concurrent_statement_part != nullptr);
  return concurrent_statement_part;
}


void
IIRBase_ConcurrentGenerateForStatement::set_block_declarative_part(IIR_DeclarationListRef new_block_declarative_part) {
  ASSERT(new_block_declarative_part != nullptr);
  block_declarative_part = new_block_declarative_part;
}

void
IIRBase_ConcurrentGenerateForStatement::set_concurrent_statement_part(IIR_ArchitectureStatementListRef new_concurrent_statement_part) {
  ASSERT(new_concurrent_statement_part != nullptr);
  concurrent_statement_part = new_concurrent_statement_part;
}

IIRRef
IIRBase_ConcurrentGenerateForStatement::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_ConcurrentGenerateForStatementRef new_node = my_dynamic_pointer_cast<IIRBase_ConcurrentGenerateForStatement>(IIRBase_ConcurrentStatement::convert_tree(factory));

  // Process the variables
  new_node->block_declarative_part = my_dynamic_pointer_cast<IIR_DeclarationList>(convert_node(block_declarative_part, factory));
  new_node->concurrent_statement_part = my_dynamic_pointer_cast<IIR_ArchitectureStatementList>(convert_node(concurrent_statement_part, factory));
  new_node->parameter = my_dynamic_pointer_cast<IIR_ConstantDeclaration>(convert_node(parameter, factory));

  return new_node;
}

void 
IIRBase_ConcurrentGenerateForStatement::publish_vhdl(ostream &vhdl_out) {

  publish_vhdl_stmt_label(vhdl_out);

  vhdl_out << " for ";
  get_generate_parameter_specification()->publish_vhdl(vhdl_out);
  vhdl_out << " in ";
  my_dynamic_pointer_cast<IIRBase_TypeDefinition>
    (get_generate_parameter_specification()->get_subtype())->publish_vhdl_range(vhdl_out);
  vhdl_out << " generate\n";

  if(get_block_declarative_part()->size() != 0) {
     my_dynamic_pointer_cast<IIRBase_DeclarationList>
      (get_block_declarative_part())->publish_vhdl_decl(vhdl_out);
  }

  vhdl_out << "   begin\n";
  get_concurrent_statement_part()->publish_vhdl(vhdl_out);
  vhdl_out << "   end generate ";
  if(get_label() != NULL) {
    get_label()->publish_vhdl(vhdl_out);
  }
  vhdl_out << ";\n";

}
