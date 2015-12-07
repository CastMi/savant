

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
//          Malolan Chetlur     mal@ece.uc.edu

//---------------------------------------------------------------------------

#include "savant.hh"
#include "IIRBase_GroupDeclaration.hh"
#include "IIR_AttributeSpecificationList.hh"
#include "IIR_DesignatorList.hh"
#include "IIRBase_Name.hh"
#include "IIR_TextLiteral.hh"

IIRBase_GroupDeclaration::IIRBase_GroupDeclaration() {}
IIRBase_GroupDeclaration::~IIRBase_GroupDeclaration() {}

void
IIRBase_GroupDeclaration:: set_group_template( IIR_NameRef group_template_name ){
  this->group_template_name = group_template_name;
}

IIR_NameRef
IIRBase_GroupDeclaration::get_group_template_name() {
  return group_template_name;
}


// List Accessor(s)
IIR_DesignatorListRef
IIRBase_GroupDeclaration::get_group_constituent_list() {
  ASSERT(group_constituent_list != NULL);
  return group_constituent_list;
}

IIR_AttributeSpecificationListRef
IIRBase_GroupDeclaration::get_attributes() {
  ASSERT(attributes != NULL);
  return attributes;
}


void
IIRBase_GroupDeclaration::set_group_constituent_list(IIR_DesignatorListRef new_group_constituent_list) {
  ASSERT(new_group_constituent_list != NULL);
  group_constituent_list = new_group_constituent_list;
}

void
IIRBase_GroupDeclaration::set_attributes(IIR_AttributeSpecificationListRef new_attributes) {
  ASSERT(new_attributes != NULL);
  attributes = new_attributes;
}

IIRRef
IIRBase_GroupDeclaration::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_GroupDeclarationRef new_node = my_dynamic_pointer_cast<IIRBase_GroupDeclaration>(IIRBase_Declaration::convert_tree(factory));

  // Process the variables
  new_node->group_constituent_list = my_dynamic_pointer_cast<IIR_DesignatorList>(convert_node(group_constituent_list, factory));
  new_node->attributes = my_dynamic_pointer_cast<IIR_AttributeSpecificationList>(convert_node(attributes, factory));
  new_node->group_template_name = my_dynamic_pointer_cast<IIR_Name>(convert_node(group_template_name, factory));

  return new_node;
}

IIR_Declaration::declaration_type
IIRBase_GroupDeclaration::get_declaration_type(){
  return GROUP;
}

void 
IIRBase_GroupDeclaration::publish_vhdl_decl(ostream &vhdl_out) {
  vhdl_out << " group ";
  get_declarator()->publish_vhdl(vhdl_out);
  vhdl_out << " : ";
  my_dynamic_pointer_cast<IIRBase_Name>(get_group_template_name())->publish_vhdl(vhdl_out);
  vhdl_out << " ( ";
  // XXX till it is fixed in aire spec let this be commented
  //  get_group_constituent_list()->publish_vhdl(vhdl_out);
  vhdl_out << " );\n";
}
