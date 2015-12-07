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
//          Timothy J. McBrayer tmcbraye@ece.uc.edu

//---------------------------------------------------------------------------

#include "savant.hh"
#include "IIRBase_PhysicalUnit.hh"
#include "IIR_PhysicalUnit.hh"
#include "IIR_AttributeSpecificationList.hh"
#include "IIR_TextLiteral.hh"

IIRBase_PhysicalUnit::IIRBase_PhysicalUnit() {}
IIRBase_PhysicalUnit::~IIRBase_PhysicalUnit() {}


void 
IIRBase_PhysicalUnit::set_multiplier(IIRRef multiplier) {
  this->multiplier = multiplier;
}


IIRRef
IIRBase_PhysicalUnit::get_multiplier() {
  return multiplier;
}


void 
IIRBase_PhysicalUnit::set_unit_name(IIR_PhysicalUnitRef name) {
  unit_name = name;
}


IIR_PhysicalUnitRef
IIRBase_PhysicalUnit::get_unit_name() {
  return unit_name;
}

// List Accessor(s)
IIR_AttributeSpecificationListRef
IIRBase_PhysicalUnit::get_attributes() {
  ASSERT(attributes != NULL);
  return attributes;
}


void
IIRBase_PhysicalUnit::set_attributes(IIR_AttributeSpecificationListRef new_attributes) {
  ASSERT(new_attributes != NULL);
  attributes = new_attributes;
}

IIRRef
IIRBase_PhysicalUnit::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_PhysicalUnitRef new_node = my_dynamic_pointer_cast<IIRBase_PhysicalUnit>(IIRBase_Declaration::convert_tree(factory));

  // Process the variables
  new_node->attributes = my_dynamic_pointer_cast<IIR_AttributeSpecificationList>(convert_node(attributes, factory));
  new_node->multiplier = convert_node(multiplier, factory);
  new_node->unit_name = my_dynamic_pointer_cast<IIR_PhysicalUnit>(convert_node(unit_name, factory));

  return new_node;
}

IIR_Boolean
IIRBase_PhysicalUnit::is_locally_static(){
  return true;
}


IIR_Declaration::declaration_type 
IIRBase_PhysicalUnit::get_declaration_type(){
  return UNITS;
}

void 
IIRBase_PhysicalUnit::publish_vhdl_decl(ostream &vhdl_out) {
  vhdl_out << "    ";
  get_declarator()->publish_vhdl(vhdl_out);
  vhdl_out << " = ";
  get_multiplier()->publish_vhdl(vhdl_out);
  vhdl_out << ";\n";
}

void
IIRBase_PhysicalUnit::publish_vhdl(ostream &vhdl_out){
  get_declarator()->publish_vhdl(vhdl_out);
}
