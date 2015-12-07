
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

#include "IIRBase_Identifier.hh"
#include "IIRBase_QuietAttribute.hh"
#include "IIR_DesignFile.hh"
#include "IIR_EnumerationSubtypeDefinition.hh"
#include "IIR_TypeDefinition.hh"
#include "savant.hh"
#include "StandardPackage.hh"
#include <cstring>

IIRBase_QuietAttribute::IIRBase_QuietAttribute() {}
IIRBase_QuietAttribute::~IIRBase_QuietAttribute() {}

void 
IIRBase_QuietAttribute::set_suffix( IIRRef suffix) {
  this->suffix = suffix;
}

IIRRef IIRBase_QuietAttribute::get_suffix() {
  return suffix;
}

IIRRef
IIRBase_QuietAttribute::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_QuietAttributeRef new_node = my_dynamic_pointer_cast<IIRBase_QuietAttribute>(IIRBase_Attribute::convert_tree(factory));

  // Process the variables
  new_node->suffix = convert_node(suffix, factory);

  return new_node;
}

// The Quiet attribute is a boolean signal valued attribute...
IIR_TypeDefinitionRef
IIRBase_QuietAttribute::get_subtype(){
  return get_design_file()->get_standard_package()->get_boolean_type();
}

IIR_TextLiteralRef
IIRBase_QuietAttribute::build_attribute_name(){
   std::string name("quiet");
  return IIRBase_Identifier::get( name, get_design_file()->get_class_factory());
}


void 
IIRBase_QuietAttribute::publish_vhdl(ostream &vhdl_out) {
  ASSERT(get_prefix() != NULL);
  get_prefix()->publish_vhdl(vhdl_out);
  vhdl_out << "'QUIET";

  if (get_suffix() != NULL) {
    vhdl_out << "(";
    get_suffix()->publish_vhdl(vhdl_out);
    vhdl_out << ") ";
  }
}
