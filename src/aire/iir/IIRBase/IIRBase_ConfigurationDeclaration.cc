
// Copyright (c) The University of Cincinnati.  
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

#include "savant.hh"
#include "IIR_BlockConfiguration.hh"
#include "IIRBase_DeclarationList.hh"
#include "IIR_EntityDeclaration.hh"
#include "IIR_TextLiteral.hh"
#include "IIRBase_ConfigurationDeclaration.hh"

IIRBase_ConfigurationDeclaration::IIRBase_ConfigurationDeclaration() {}

IIRBase_ConfigurationDeclaration::~IIRBase_ConfigurationDeclaration() {}

void 
IIRBase_ConfigurationDeclaration::set_block_configuration(IIR_BlockConfigurationRef block_configuration ){
  this->block_configuration = block_configuration;
}

IIR_BlockConfigurationRef
IIRBase_ConfigurationDeclaration::get_block_configuration(){
  return block_configuration;
}

void 
IIRBase_ConfigurationDeclaration::set_entity( IIR_EntityDeclarationRef entity ){
  this->entity = entity;
}

IIR_EntityDeclarationRef
IIRBase_ConfigurationDeclaration::get_entity(){
  return entity;
}


// List Accessor(s)
IIR_DeclarationListRef
IIRBase_ConfigurationDeclaration::get_configuration_declarative_part() {
  ASSERT(configuration_declarative_part != nullptr);
  return configuration_declarative_part;
}


void
IIRBase_ConfigurationDeclaration::set_configuration_declarative_part(IIR_DeclarationListRef new_configuration_declarative_part) {
  ASSERT(new_configuration_declarative_part != nullptr);
  configuration_declarative_part = new_configuration_declarative_part;
}

IIRRef
IIRBase_ConfigurationDeclaration::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_ConfigurationDeclarationRef new_node = my_dynamic_pointer_cast<IIRBase_ConfigurationDeclaration>(IIRBase_LibraryUnit::convert_tree(factory));

  // Process the variables
  new_node->configuration_declarative_part = my_dynamic_pointer_cast<IIR_DeclarationList>(configuration_declarative_part->convert_tree(factory));
  new_node->block_configuration = my_dynamic_pointer_cast<IIR_BlockConfiguration>(convert_node(block_configuration, factory));
  new_node->entity = my_dynamic_pointer_cast<IIR_EntityDeclaration>(convert_node(entity, factory));

  return new_node;
}

IIR_Declaration::declaration_type 
IIRBase_ConfigurationDeclaration::get_declaration_type(){
   return CONFIGURATION;
}

void 
IIRBase_ConfigurationDeclaration::publish_vhdl_decl(ostream &vhdl_out) {
  get_context_items()->publish_vhdl(vhdl_out);

  vhdl_out << " configuration ";
  get_declarator()->publish_vhdl(vhdl_out);
  vhdl_out << " of ";
  get_entity()->get_declarator()->publish_vhdl(vhdl_out);
  vhdl_out << " is\n";
  my_dynamic_pointer_cast<IIRBase_DeclarationList>(get_configuration_declarative_part())->publish_vhdl_decl(vhdl_out);
  get_block_configuration()->publish_vhdl(vhdl_out);
  vhdl_out << " end configuration ";
  get_declarator()->publish_vhdl(vhdl_out);
  vhdl_out << " ;\n";
}

void
IIRBase_ConfigurationDeclaration::publish_vhdl_binding_name(ostream &vhdl_out){
  vhdl_out << " configuration ";
  get_declarator()->publish_vhdl(vhdl_out);
}

void
IIRBase_ConfigurationDeclaration::publish_vhdl_with_library_name(ostream &vhdl_out){
  vhdl_out << " configuration ";
  ASSERT(get_declarative_region() != NULL);
  ASSERT(get_declarative_region()->get_kind() == IIR_LIBRARY_DECLARATION);
  get_declarative_region()->publish_vhdl(vhdl_out);
  vhdl_out << ".";
  get_declarator()->publish_vhdl(vhdl_out);
}
