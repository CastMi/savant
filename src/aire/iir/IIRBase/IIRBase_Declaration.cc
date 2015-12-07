
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

#include "IIRBase_Declaration.hh"
#include "IIR_Declaration.hh"
#include "savant.hh"
#include "IIRBase_Attribute.hh"
#include "IIRBase_Identifier.hh"
#include "IIRBase_TextLiteral.hh"
#include "IIRBase_TypeDefinition.hh"

// FIXME: this is an error
IIR_DeclarationRef get_prefix_declaration() {
   // In theory it should return "this"
   return IIRBase_DeclarationRef();
}

IIRBase_Declaration::IIRBase_Declaration() : 
  implicit_flag(false),
  visible_flag(true) {}

IIRBase_Declaration::~IIRBase_Declaration() {}

void 
IIRBase_Declaration::set_declarator( IIR_TextLiteralRef new_declarator ){
  ASSERT ( new_declarator != nullptr );
  declarator = new_declarator;  
}

IIR_TextLiteralRef
IIRBase_Declaration::get_declarator(){
  return declarator;
}

IIRRef
IIRBase_Declaration::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_DeclarationRef new_node = my_dynamic_pointer_cast<IIRBase_Declaration>(IIRBase::convert_tree(factory));

  // Process the variables
  new_node->declarator = my_dynamic_pointer_cast<IIR_TextLiteral>(convert_node(declarator, factory));
  new_node->declarative_region = convert_node(declarative_region, factory);
  new_node->attribute_name = my_dynamic_pointer_cast<IIR_Attribute>(convert_node(attribute_name, factory));

  new_node->implicit_flag = implicit_flag;
  new_node->visible_flag = visible_flag;

  return new_node;
}

IIRRef
IIRBase_Declaration::get_declarative_region(){
  return declarative_region;
}

void 
IIRBase_Declaration::set_declarative_region( IIRRef new_declarative_region ){
  declarative_region = new_declarative_region;
}

IIR_Declaration::declaration_type 
IIRBase_Declaration::get_declaration_type(){
  return ERROR;
}

IIR_TextLiteralRef
IIRBase_Declaration::get_prefix_string(){
  return get_declarator();
}

ostream & 
IIRBase_Declaration::print( ostream &os ){
  if( get_declarator() != NULL ){
    os << *get_declarator();
  }
  else{
    os << "<ANONYMOUS>";
  }

  return os;
}

IIR_AttributeRef
IIRBase_Declaration::get_attribute_name(){
  return attribute_name;
}

void 
IIRBase_Declaration::set_attribute_name( IIR_AttributeRef new_name ){
  attribute_name = new_name;
}

void 
IIRBase_Declaration::publish_vhdl(ostream &vhdl_out) {
  // This takes care of the problem where an implicit declaration name
  // gets published instead of an actual attribute name.
  if( get_attribute_name() == NULL ){
    get_declarator()->publish_vhdl(vhdl_out);
  }
  else{
    get_attribute_name()->publish_vhdl(vhdl_out);
  }
}

void
IIRBase_Declaration::publish_vhdl_declarator_with_colon(ostream &vhdl_out){
  get_declarator()->publish_vhdl(vhdl_out);
  vhdl_out << " : ";
}
