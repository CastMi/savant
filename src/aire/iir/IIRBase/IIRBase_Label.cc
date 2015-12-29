
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
#include "IIRBase_Label.hh"
#include "IIR_AttributeSpecificationList.hh"
#include "IIR_Statement.hh"
#include "IIR_TextLiteral.hh"

IIRBase_Label::IIRBase_Label() {}
IIRBase_Label::~IIRBase_Label() {}

void
IIRBase_Label::set_statement(IIR_StatementRef statement) {
  my_statement = statement;
}

IIR_StatementRef
IIRBase_Label::get_statement() {
  return my_statement;
}

// List Accessor(s)
IIR_AttributeSpecificationListRef
IIRBase_Label::get_attributes() {
  ASSERT(attributes != nullptr);
  return attributes;
}

void
IIRBase_Label::set_attributes(IIR_AttributeSpecificationListRef new_attributes) {
  ASSERT(new_attributes != nullptr);
  attributes = new_attributes;
}

IIRRef
IIRBase_Label::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_LabelRef new_node = my_dynamic_pointer_cast<IIRBase_Label>(IIRBase_Declaration::convert_tree(factory));

  // Process the variables
  new_node->attributes = my_dynamic_pointer_cast<IIR_AttributeSpecificationList>(convert_node(attributes, factory));
  new_node->my_statement = my_dynamic_pointer_cast<IIR_Statement>(convert_node(my_statement, factory));

  return new_node;
}

IIR_Declaration::declaration_type 
IIRBase_Label::get_declaration_type(){
  return LABEL;
}

savant::set<IIR_DeclarationRef>
IIRBase_Label::find_declarations( IIR_NameRef name ){
  ASSERT( get_statement() != nullptr );

  return get_statement()->find_declarations( name );
}

void 
IIRBase_Label::publish_vhdl(ostream &vhdl_out) {
  get_declarator()->publish_vhdl(vhdl_out);
}
