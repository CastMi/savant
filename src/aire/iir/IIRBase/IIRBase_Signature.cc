
// Copyright (c) 1996-2003 The University of Cincinnati.  
// All rights reserved.

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
// SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR
// NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
// LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING OR DISTRIBUTING
// THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the U.S., and
// the terms of this license.

// You may modify, distribute, and use the software contained in this package
// under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE" version 2, June
// 1991. A copy of this license agreement can be found in the file "LGPL",
// distributed with this archive.

// Authors: Philip A. Wilsey	philip.wilsey@ieee.org
//          Dale E. Martin	dmartin@cliftonlabs.com
//          Malolan Chetlur     

//---------------------------------------------------------------------------

#include "savant.hh"
#include "IIRBase_Signature.hh"
#include "IIR_DesignatorList.hh"

IIRBase_Signature::IIRBase_Signature() {}
IIRBase_Signature::~IIRBase_Signature() {}

void
IIRBase_Signature:: set_return_type( IIR_TypeDefinitionRef return_type) {
  this->return_type = return_type;
}

IIR_TypeDefinitionRef
IIRBase_Signature::get_return_type() {
  return return_type;
}

// List Accessor(s)
IIR_DesignatorListRef
IIRBase_Signature::get_argument_type_list() {
  ASSERT(argument_type_list != NULL);
  return argument_type_list;
}


void
IIRBase_Signature::set_argument_type_list(IIR_DesignatorListRef new_argument_type_list) {
  ASSERT(new_argument_type_list != NULL);
  argument_type_list = new_argument_type_list;
}

IIRRef
IIRBase_Signature::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_SignatureRef new_node = my_dynamic_pointer_cast<IIRBase_Signature>(IIRBase_TypeDefinition::convert_tree(factory));

  // Process the variables
  new_node->argument_type_list = my_dynamic_pointer_cast<IIR_DesignatorList>(convert_node(argument_type_list, factory));
  new_node->return_type = my_dynamic_pointer_cast<IIR_TypeDefinition>(convert_node(return_type, factory));

  return new_node;
}

void 
IIRBase_Signature::publish_vhdl(ostream &vhdl_out) {
  get_argument_type_list()->publish_vhdl(vhdl_out);
  vhdl_out << " return ";
  my_dynamic_pointer_cast<IIRBase_TypeDefinition>(get_return_type())->publish_vhdl(vhdl_out);
}
