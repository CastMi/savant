
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

#include "IIRBase_DesignFile.hh"
#include "IIRBase_Identifier.hh"
#include "IIRBase_ZTFAttribute.hh"
#include "savant.hh"

IIRBase_ZTFAttribute::IIRBase_ZTFAttribute() {}
IIRBase_ZTFAttribute::~IIRBase_ZTFAttribute() {}

void
IIRBase_ZTFAttribute::set_num( IIRRef new_numerator ){
  numerator = new_numerator;
}

IIRRef
IIRBase_ZTFAttribute::get_num() {
  return numerator;
}

void
IIRBase_ZTFAttribute::set_den( IIRRef new_denominator ){
  denominator = new_denominator;
}

IIRRef
IIRBase_ZTFAttribute::get_den() {
  return denominator;
}

void 
IIRBase_ZTFAttribute::set_t( IIRRef new_sampling_period ){
  period = new_sampling_period;
}

IIRRef
IIRBase_ZTFAttribute::get_t() {
  return period;
}

void
IIRBase_ZTFAttribute::set_initial_delay( IIRRef new_delay ){
  initial_delay = new_delay;
}

IIRRef
IIRBase_ZTFAttribute::get_initial_delay() {
  return initial_delay;
}

IIRRef
IIRBase_ZTFAttribute::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_ZTFAttributeRef new_node = my_dynamic_pointer_cast<IIRBase_ZTFAttribute>(IIRBase_Attribute::convert_tree(factory));

  // Process the variables
  new_node->numerator = convert_node(numerator, factory);
  new_node->denominator = convert_node(denominator, factory);
  new_node->period = convert_node(period, factory);
  new_node->initial_delay = convert_node(initial_delay, factory);

  return new_node;
}

IIR_TextLiteralRef
IIRBase_ZTFAttribute::build_attribute_name() {
   std::string name = "ztf";
   return IIRBase_Identifier::get(name, get_design_file()->get_class_factory());
}

void
IIRBase_ZTFAttribute::publish_vhdl(ostream& vhdl_out) {
  get_prefix()->publish_vhdl(vhdl_out);
  vhdl_out << "'ZTF ( " ;
  get_num()->publish_vhdl(vhdl_out);
  vhdl_out << " , ";
  get_den()->publish_vhdl(vhdl_out);
  vhdl_out << " , ";
  get_t()->publish_vhdl(vhdl_out);
  vhdl_out << " , ";
  get_initial_delay()->publish_vhdl(vhdl_out);
  vhdl_out << " ) ";
}
