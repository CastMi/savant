
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



#include "IIRBase_SubprogramDeclaration.hh"
#include "IIR_AttributeSpecificationList.hh"
#include "IIR_DeclarationList.hh"
#include "IIR_InterfaceList.hh"
#include "IIR_SequentialStatementList.hh"
#include "IIR_TextLiteral.hh"

IIRBase_SubprogramDeclaration::IIRBase_SubprogramDeclaration()  :
  my_contains_body(FALSE) {}
IIRBase_SubprogramDeclaration::~IIRBase_SubprogramDeclaration() {}

// List Accessor(s)
IIR_InterfaceListRef
IIRBase_SubprogramDeclaration::get_interface_declarations() {
  ASSERT(interface_declarations != NULL);
  return interface_declarations;
}

IIR_DeclarationListRef
IIRBase_SubprogramDeclaration::get_subprogram_declarations() {
  ASSERT(subprogram_declarations != NULL);
  return subprogram_declarations;
}

IIR_SequentialStatementListRef
IIRBase_SubprogramDeclaration::get_subprogram_body() {
  ASSERT(subprogram_body != NULL);
  return subprogram_body;
}

IIR_AttributeSpecificationListRef
IIRBase_SubprogramDeclaration::get_attributes() {
  ASSERT(attributes != NULL);
  return attributes;
}

void
IIRBase_SubprogramDeclaration::set_interface_declarations(IIR_InterfaceListRef new_interface_declarations) {
  ASSERT(new_interface_declarations != NULL);
  interface_declarations = new_interface_declarations;
}

void
IIRBase_SubprogramDeclaration::set_subprogram_declarations(IIR_DeclarationListRef new_subprogram_declarations) {
  ASSERT(new_subprogram_declarations != NULL);
  subprogram_declarations = new_subprogram_declarations;
}

void
IIRBase_SubprogramDeclaration::set_subprogram_body(IIR_SequentialStatementListRef new_subprogram_body) {
  ASSERT(new_subprogram_body != NULL);
  subprogram_body = new_subprogram_body;
}

void
IIRBase_SubprogramDeclaration::set_attributes(IIR_AttributeSpecificationListRef new_attributes) {
  ASSERT(new_attributes != NULL);
  attributes = new_attributes;
}

IIRRef
IIRBase_SubprogramDeclaration::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_SubprogramDeclarationRef new_node = my_dynamic_pointer_cast<IIRBase_SubprogramDeclaration>(IIRBase_Declaration::convert_tree(factory));

  // Process the variables
  new_node->interface_declarations = my_dynamic_pointer_cast<IIR_InterfaceList>(convert_node(interface_declarations, factory));
  new_node->subprogram_declarations = my_dynamic_pointer_cast<IIR_DeclarationList>(convert_node(subprogram_declarations, factory));
  new_node->subprogram_body = my_dynamic_pointer_cast<IIR_SequentialStatementList>(convert_node(subprogram_body, factory));
  new_node->attributes = my_dynamic_pointer_cast<IIR_AttributeSpecificationList>(convert_node(attributes, factory));
  new_node->my_contains_body = my_contains_body;

  return new_node;
}

IIR_Boolean 
IIRBase_SubprogramDeclaration::contains_body(){
  return my_contains_body;
}

void
IIRBase_SubprogramDeclaration::set_contains_body( IIR_Boolean new_contains_body ){
  my_contains_body = new_contains_body;
}

IIR_Boolean 
IIRBase_SubprogramDeclaration::is_operator(){
  IIR_TextLiteralRef declarator = get_declarator();
  if( declarator->get_text()[0] == '"' &&
      declarator->get_text()[ declarator->get_text_length() ] == '"' ){
    ASSERT( get_interface_declarations()->num_elements() == 1 ||
	    get_interface_declarations()->num_elements() == 2 );
    
    return TRUE;
  }
  else{
    return FALSE;
  }
}

ostream &
IIRBase_SubprogramDeclaration::print( ostream &os ){
  os << *get_declarator();
  os << "(";

  IIR_InterfaceDeclarationRef current_param = 
    my_dynamic_pointer_cast<IIR_InterfaceDeclaration>(get_interface_declarations()->first());
  while( current_param != NULL ){
    os << *current_param;
    current_param = 
      my_dynamic_pointer_cast<IIR_InterfaceDeclaration>(get_interface_declarations()->successor( current_param ));
    if( current_param != NULL ){
      os << ", ";
    }
  }
  
  os << ")";

  return os;
}
