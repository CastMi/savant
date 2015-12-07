
// Copyright (c) 2003 The University of Cincinnati.
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

// Authors: Sivakumar Gowrisankar             gowriss@ececs.uc.edu
//          Kathiresan Nellayappan
//          Vasudevan Shanmugasundaram

//---------------------------------------------------------------------------

#include "savant.hh"
#include "IIRBase_SimpleSimultaneousStatement.hh"
#include "IIR_Label.hh"

IIRBase_SimpleSimultaneousStatement::IIRBase_SimpleSimultaneousStatement() :
  purity(IIR_PURE_FUNCTION) {}

IIRBase_SimpleSimultaneousStatement::~IIRBase_SimpleSimultaneousStatement() {}

void
IIRBase_SimpleSimultaneousStatement::set_left_expression(IIRRef my_left_expression){
  left_expression = my_left_expression;
}

void
IIRBase_SimpleSimultaneousStatement::set_right_expression(IIRRef my_right_expression){
  right_expression = my_right_expression;
}

IIRRef
IIRBase_SimpleSimultaneousStatement::get_left_expression(){
  return left_expression;
}

IIRRef
IIRBase_SimpleSimultaneousStatement::get_right_expression(){
  return right_expression;
}

void
IIRBase_SimpleSimultaneousStatement::set_pure(IIR_Pure my_purity) {
  purity = my_purity;
}

IIR_Pure
IIRBase_SimpleSimultaneousStatement::get_pure() {
  return purity;
}

void 
IIRBase_SimpleSimultaneousStatement::set_tolerance_aspect(IIRRef my_tolerance) {
  tolerance_aspect = my_tolerance;
}

IIRRef
IIRBase_SimpleSimultaneousStatement::get_tolerance_aspect() {
  return tolerance_aspect;
}

IIRRef
IIRBase_SimpleSimultaneousStatement::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_SimpleSimultaneousStatementRef new_node = my_dynamic_pointer_cast<IIRBase_SimpleSimultaneousStatement>(IIRBase_SimultaneousStatement::convert_tree(factory));

  // Process the variables
  new_node->purity = purity;
  new_node->left_expression = convert_node(left_expression, factory);
  new_node->right_expression = convert_node(right_expression, factory);
  new_node->tolerance_aspect = convert_node(tolerance_aspect, factory);

  return new_node;
}

void
IIRBase_SimpleSimultaneousStatement::publish_vhdl(ostream &vhdl_out) {
  if( get_label() != NULL ){
    get_label()->publish_vhdl(vhdl_out);
    vhdl_out << " : ";
  }
  get_left_expression()->publish_vhdl(vhdl_out);
  vhdl_out << " == ";
  get_right_expression()->publish_vhdl(vhdl_out);
  vhdl_out << " ;\n";
}
