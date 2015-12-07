
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

#include "savant.hh"
#include "IIRBase_EventAttribute.hh"
#include "IIRBase_Identifier.hh"
#include "IIR_DesignFile.hh"
#include "IIR_EnumerationSubtypeDefinition.hh"
#include "IIR_PhysicalSubtypeDefinition.hh"
#include "IIR_TypeDefinition.hh"
#include "IIR_VariableDeclaration.hh"
#include "StandardPackage.hh"
#include "plugin_class_factory.hh"
#include <cstring>

IIRBase_EventAttribute::IIRBase_EventAttribute(){}

IIRBase_EventAttribute::~IIRBase_EventAttribute(){}

// The Event attribute is a boolean function valued attribute...
IIR_TypeDefinitionRef
IIRBase_EventAttribute::get_subtype(){
  return get_design_file()->get_standard_package()->get_boolean_type();
}

IIR_TextLiteralRef
IIRBase_EventAttribute::build_attribute_name() {
   std::string name("event");
  return IIRBase_Identifier::get( name, get_design_file()->get_class_factory() );
}

IIR_VariableDeclarationRef
IIRBase_EventAttribute::build_implicit_variable( const string &declarator,
                                                 IIR_TypeDefinitionRef ){
  IIR_VariableDeclarationRef variable = get_design_file()->get_class_factory()->new_IIR_VariableDeclaration();
  variable->set_declarator( IIRBase_Identifier::get( declarator, get_design_file()->get_class_factory()) );
  variable->set_subtype( get_design_file()->get_standard_package()->get_time_type() );

  return variable;
}

void 
IIRBase_EventAttribute::publish_vhdl(ostream &vhdl_out) {
  ASSERT(get_prefix() != NULL);
  ASSERT( get_prefix()->is_resolved() == TRUE );
  get_prefix()->publish_vhdl(vhdl_out);
  vhdl_out << "'EVENT ";
}
