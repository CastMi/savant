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
#include "IIRBase_TypeDefinition.hh"
#include "IIR_AccessSubtypeDefinition.hh"
#include "IIR_Declaration.hh"
#include "IIR_DesignFile.hh"
#include "IIR_FloatingTypeDefinition.hh"
#include "IIR_TextLiteral.hh"
#include "IIR_TypeDefinition.hh"
#include "StandardPackage.hh"
#include "error_func.hh"
#include "savant.hh"
#include "set.hh"

IIRBase_TypeDefinition::IIRBase_TypeDefinition() {}
IIRBase_TypeDefinition::~IIRBase_TypeDefinition(){}

void
IIRBase_TypeDefinition::set_base_type( IIR_TypeDefinitionRef base_type ){
  //  ASSERT( base_type == NULL);
  ASSERT( my_base_type == 0 || my_base_type == base_type );
  ASSERT( base_type != 0 );

  my_base_type = base_type;
}

IIR_TypeDefinitionRef
IIRBase_TypeDefinition::get_base_type() {
  return my_base_type;
}

IIR_TypeDefinitionRef
IIRBase_TypeDefinition::get_resolved_base_type() {
  return get_base_type(); 
}

IIR_DeclarationRef
IIRBase_TypeDefinition::get_declaration() {
  return my_declaration;
}

void 
IIRBase_TypeDefinition::set_declaration( IIR_DeclarationRef declaration ) {
  my_declaration = declaration;
}

IIR_TypeDefinitionRef
IIRBase_TypeDefinition::get_type_mark() {
  return my_type_mark;
}

void 
IIRBase_TypeDefinition::set_type_mark( IIR_TypeDefinitionRef type_mark ) {
  my_type_mark = type_mark;
}

IIRRef
IIRBase_TypeDefinition::convert_tree(plugin_class_factoryRef factory) {
  IIRBase_TypeDefinitionRef new_node = my_dynamic_pointer_cast<IIRBase_TypeDefinition>(IIRBase::convert_tree(factory));

  // Process the variables
  new_node->my_base_type = my_dynamic_pointer_cast<IIR_TypeDefinition>(convert_node(my_base_type, factory));
  new_node->my_declaration = my_dynamic_pointer_cast<IIR_Declaration>(convert_node(my_declaration, factory));

  if( my_type_mark != 0 ){
    new_node->set_type_mark( my_dynamic_pointer_cast<IIR_TypeDefinition>(convert_node(my_type_mark,
									       factory)) );
  }

  return new_node;
}

IIR_Boolean
IIRBase_TypeDefinition::is_subtype() {
  return FALSE;
}

IIR_Boolean 
IIRBase_TypeDefinition::is_anonymous(){
  IIR_Boolean retval = true;
  if( get_declaration() && get_declaration()->is_type() ){
    retval = false;
  }
  return retval;
}

IIR_Boolean 
IIRBase_TypeDefinition::is_element(){
  ASSERT( is_access_type() == TRUE || is_array_type() == FALSE );
  return FALSE;
}

IIR_ScalarTypeDefinitionRef
IIRBase_TypeDefinition::get_resolved_index_subtype(){
  _report_undefined_fn("IIRBase_TypeDefinition::get_resolved_index_subtype()");
  return IIR_ScalarTypeDefinitionRef();
}

void
IIRBase_TypeDefinition::set_index_subtype(IIR_ScalarTypeDefinitionRef ) {
  abort();
}
//DRH
IIRBase_TypeDefinitionRef
IIRBase_TypeDefinition::_get_element_subtype(){
  _report_undefined_fn("IIRBase_TypeDefinition::_get_element_subtype()");
  return IIRBase_TypeDefinitionRef();
}

IIR_TypeDefinitionRef
IIRBase_TypeDefinition::get_element_subtype(){
  _report_undefined_fn("IIRBase_TypeDefinition::get_element_subtype()");  
  return IIR_TypeDefinitionRef();
}

void  
IIRBase_TypeDefinition::set_element_subtype(IIR_TypeDefinitionRef ) {
  _report_undefined_fn("IIRBase_TypeDefinition::_set_element_subtype()");  
  abort();
}

IIR_TypeDefinitionRef
IIRBase_TypeDefinition::is_compatible( IIR_TypeDefinitionRef to_check ){  
  ASSERT( this != NULL );

  StandardPackageRef package = get_design_file()->get_standard_package();
  // Check for NULL types.
  if( to_check == my_dynamic_pointer_cast<IIR_TypeDefinition>( package->get_savant_null_type_definition())  ){
     // FIXME: this is an error
    return IIR_TypeDefinitionRef();
  }
  else if( this == dynamic_cast<IIR_TypeDefinition*>( package->get_savant_null_type_definition().get() )  ){
    return my_dynamic_pointer_cast<IIR_TypeDefinition>(to_check);
  }

  IIR_TypeDefinitionRef base_type_left;
  IIR_TypeDefinitionRef base_type_right;
  // Check for "normal" compatibility.
  if( is_subtype() == TRUE ){
    base_type_left = get_base_type();
  }
  else{
     // FIXME: this is an error
    base_type_left = IIR_TypeDefinitionRef();
  }
  
  if( to_check->is_subtype() == TRUE ){
    base_type_right = to_check->get_base_type();
  }
  else{
    base_type_right = to_check;
  }

  if( base_type_left == base_type_right ){
    if( to_check->is_subtype() == TRUE && is_subtype() == FALSE ){
      return to_check;
    }
    else{
      // FIXME: this is an error
      return IIR_TypeDefinitionRef();
    }
  }

  // Check for special cases, like universal ints being compared with
  // other integer types.
  return check_special_compatible( to_check );
}

IIR_TypeDefinitionRef
IIRBase_TypeDefinition::check_special_compatible( IIR_TypeDefinitionRef ){
  return IIR_TypeDefinitionRef();
}

IIR_TypeDefinitionRef
IIRBase_TypeDefinition::get_bottom_base_type(){
  if( is_subtype() ){
    ASSERT( get_base_type() != 0 );
    return get_base_type();
  }
  else{
    ASSERT( get_base_type() == 0 );    
     // FIXME: this is an error
    return IIR_TypeDefinitionRef();
  }
}

IIRRef
IIRBase_TypeDefinition::get_base_type_left(){
  _report_undefined_fn("IIRBase_TypeDefinition::get_base_type_left()");  
  return IIRRef();
}

IIRRef
IIRBase_TypeDefinition::get_base_type_direction(){
  _report_undefined_fn("IIRBase_TypeDefinition::get_base_type_direction()");  
  return IIRRef();
}

IIRRef
IIRBase_TypeDefinition::get_base_type_right(){
  _report_undefined_fn("IIRBase_TypeDefinition::get_base_type_right()");  
  return IIRRef();
}

savant::set<IIR_DeclarationRef>
IIRBase_TypeDefinition::find_declarations( IIR_NameRef ) {
  return savant::set<IIR_DeclarationRef>();
}

savant::set<IIR_DeclarationRef>
IIRBase_TypeDefinition::find_declarations( IIR_TextLiteralRef ) {
  _report_undefined_fn("IIRBase_TypeDefinition::find_declarations( IIR_TextLiteral * )");  
  return savant::set<IIR_DeclarationRef>();
}

IIR_Boolean
IIRBase_TypeDefinition::is_subtype_decl() {
  IIR_DeclarationRef type_decl = get_declaration();
  if(type_decl != nullptr) {
    return type_decl->is_subtype_decl();
  }
  else {
    return FALSE;
  }
}

ostream &
IIRBase_TypeDefinition::print( ostream &os ){
  os << *get_declarator();
  return os;
}

IIR_TextLiteralRef
IIRBase_TypeDefinition::get_declarator(){
  if( get_declaration() != NULL ){
    return get_declaration()->get_declarator();
  }
  else{
     std::string string = "<ANONYMOUS>";
    return IIRBase_Identifier::get( string, get_design_file()->get_class_factory() );
  }
}

void
IIRBase_TypeDefinition::publish_vhdl(ostream &vhdl_out) {
  if( get_declaration() != NULL ){
    get_declaration()->publish_vhdl(vhdl_out);
  } 
  else {
    ASSERT(get_base_type() != NULL);
    get_base_type()->publish_vhdl(vhdl_out);
  }
}
