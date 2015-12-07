
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

#include "IIRBase_AttributeSpecification.hh"
#include "IIR_Declaration.hh"
#include "IIR_DesignatorList.hh"
#include "IIR_Identifier.hh"
#include "savant.hh"

IIRBase_AttributeSpecification::IIRBase_AttributeSpecification() :
  entity_name_list(0),
  attribute_declaration(0)
{
  set_value( NULL );
  set_entity_class( NULL );
}

IIRBase_AttributeSpecification::~IIRBase_AttributeSpecification(){
}

void 
IIRBase_AttributeSpecification::set_value( IIRRef new_value ){
  value = new_value;
}

IIRRef
IIRBase_AttributeSpecification::get_value(){
  return value;
}

void
IIRBase_AttributeSpecification::set_entity_class( IIR_IdentifierRef new_entity_class ){
  entity_class = new_entity_class ;
}

IIR_IdentifierRef
IIRBase_AttributeSpecification::get_entity_class(){
  return entity_class ;
}

// List Accessor(s)
IIR_DesignatorListRef
IIRBase_AttributeSpecification::get_entity_name_list() {
  ASSERT(entity_name_list != NULL);
  return entity_name_list;
}

void
IIRBase_AttributeSpecification::set_entity_name_list(IIR_DesignatorListRef new_entity_name_list) {
  ASSERT(new_entity_name_list != nullptr);
  entity_name_list = new_entity_name_list;
}

IIRRef
IIRBase_AttributeSpecification::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_AttributeSpecificationRef new_node = my_dynamic_pointer_cast<IIRBase_AttributeSpecification>(IIRBase_Declaration::convert_tree(factory));

  // Process the variables
  new_node->entity_name_list = my_dynamic_pointer_cast<IIR_DesignatorList>(convert_node(entity_name_list, factory));
  new_node->value = convert_node(value, factory);
  new_node->entity_class = my_dynamic_pointer_cast<IIR_Identifier>(convert_node(entity_class, factory));
  new_node->attribute_declaration = my_dynamic_pointer_cast<IIR_Declaration>(convert_node(attribute_declaration, factory));

  return new_node;
}

void 
IIRBase_AttributeSpecification::set_declaration( IIR_DeclarationRef decl ){
  if( decl != nullptr ){
    ASSERT( decl->get_kind() == IIR_ATTRIBUTE_DECLARATION );
  }

  attribute_declaration = decl;
}

IIR_TypeDefinitionRef
IIRBase_AttributeSpecification::get_subtype() {
  return attribute_declaration->get_subtype();
}

IIR_DeclarationRef
IIRBase_AttributeSpecification::get_declaration(){
  return attribute_declaration;
}

IIR_Declaration::declaration_type 
IIRBase_AttributeSpecification::get_declaration_type(){
   return ATTRIBUTE;
}

void 
IIRBase_AttributeSpecification::publish_vhdl_decl(ostream &vhdl_out) {
  ASSERT(get_value() != NULL);
  ASSERT(get_value()->is_resolved() == TRUE);
  ASSERT(get_declaration() != NULL);
  ASSERT(get_declaration()->is_resolved() == TRUE);
  ASSERT(get_entity_class() != NULL);

  vhdl_out << "attribute ";
  get_declarator()->publish_vhdl(vhdl_out);
  vhdl_out << " of ";
  get_entity_name_list()->publish_vhdl(vhdl_out);
  vhdl_out << ": ";
  get_entity_class()->publish_vhdl(vhdl_out);
  vhdl_out << " is ";
  get_value()->publish_vhdl(vhdl_out);
  vhdl_out << ";\n";
}
