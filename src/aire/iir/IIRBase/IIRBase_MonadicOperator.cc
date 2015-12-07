
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


#include "IIRBase_MonadicOperator.hh"
#include "IIR_SubprogramDeclaration.hh"
#include "savant.hh"

IIRBase_MonadicOperator::IIRBase_MonadicOperator() {}
IIRBase_MonadicOperator::~IIRBase_MonadicOperator() {}

void 
IIRBase_MonadicOperator::set_implementation(IIR_SubprogramDeclarationRef implementation) {
  this->implementation = implementation;
}

IIR_SubprogramDeclarationRef
IIRBase_MonadicOperator::get_implementation() {
  return implementation;
}

void
IIRBase_MonadicOperator::set_operand( IIRRef operand) {
  this->operand = operand;
}

IIRRef
IIRBase_MonadicOperator::get_operand() {
  return operand;
}

IIRRef
IIRBase_MonadicOperator::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_MonadicOperatorRef new_node =
    my_dynamic_pointer_cast<IIRBase_MonadicOperator>(IIRBase_Operator::convert_tree(factory));

  // Process the variables
  new_node->operand = convert_node(operand, factory);
  new_node->implementation = my_dynamic_pointer_cast<IIR_SubprogramDeclaration>(convert_node(implementation, factory));

  return new_node;
}

IIR_Boolean 
IIRBase_MonadicOperator::is_resolved(){
  if( get_implementation() != NULL ){
    return get_implementation()->is_resolved();
  }
  else{
    return get_operand()->is_resolved();
  }
}

IIR_Boolean 
IIRBase_MonadicOperator::is_locally_static(){
  ASSERT( is_resolved() == TRUE );
  return get_operand()->is_locally_static();
}

IIR_Boolean
IIRBase_MonadicOperator::is_above_attribute_found() {
  return get_operand()->is_above_attribute_found();
}

void
IIRBase_MonadicOperator::publish_vhdl(ostream &vhdl_out){
  // Commented out since scram is not parsing it. need to be uncommented
  // out later.
  //vhdl_out << "(";
  publish_vhdl_operator(vhdl_out);
  vhdl_out << "(";
  get_operand()->publish_vhdl(vhdl_out);
  vhdl_out << ")";
  // Commented out since scram is not parsing it. Need to be uncommented
  // out later.
  //vhdl_out << "))";
}
