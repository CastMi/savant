
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

#include "IIRBase_LibraryUnit.hh"
#include "IIR_DeclarationList.hh"
#include "IIR_AttributeSpecificationList.hh"
#include "IIR_LibraryDeclaration.hh"
#include "plugin_class_factory.hh"

IIRBase_LibraryUnit::IIRBase_LibraryUnit() {}

IIRBase_LibraryUnit::~IIRBase_LibraryUnit() {}

// List Accessor(s)
IIR_DeclarationListRef
IIRBase_LibraryUnit::get_context_items() {
  if( context_items == nullptr ){
    context_items = get_class_factory()->new_IIR_DeclarationList();
  }
  return context_items;
}

IIR_AttributeSpecificationListRef
IIRBase_LibraryUnit::get_attributes() {
  if( attributes == nullptr ){
    attributes = get_class_factory()->new_IIR_AttributeSpecificationList();
  }
  return attributes;
}

void
IIRBase_LibraryUnit::set_context_items(IIR_DeclarationListRef new_context_items) {
  context_items = new_context_items;
}

void
IIRBase_LibraryUnit::set_attributes(IIR_AttributeSpecificationListRef new_attributes) {
  attributes = new_attributes;
}

IIRRef
IIRBase_LibraryUnit::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_LibraryUnitRef new_node =
    my_dynamic_pointer_cast<IIRBase_LibraryUnit>(IIRBase_Declaration::convert_tree(factory));
  // Process the variables
  new_node->context_items =
    my_dynamic_pointer_cast<IIR_DeclarationList>(convert_node(context_items, factory));
  new_node->attributes =
    my_dynamic_pointer_cast<IIR_AttributeSpecificationList>(convert_node(attributes, factory));

  return new_node;
}

IIR_LibraryDeclarationRef
IIRBase_LibraryUnit::get_library(){
  ASSERT( get_declarative_region() != nullptr );
  ASSERT( get_declarative_region()->get_kind() == IIR_LIBRARY_DECLARATION );
  return my_dynamic_pointer_cast<IIR_LibraryDeclaration>(get_declarative_region());
}

IIR_Boolean
IIRBase_LibraryUnit::is_primary_unit(){
  return false;
}

IIR_Boolean
IIRBase_LibraryUnit::is_secondary_unit(){
  return false;
}

void
IIRBase_LibraryUnit::publish_vhdl_binding_name( ostream & ){
  _report_undefined_fn("publish_vhdl_binding_name");
}

void
IIRBase_LibraryUnit::publish_vhdl_with_library_name( ostream & ){
  _report_undefined_fn("publish_vhdl_with_library_name");
}
