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

#include "IIRScram_AccessSubtypeDefinition.hh"
#include "IIRScram_ArrayTypeDefinition.hh"
#include "IIRScram_ConstantInterfaceDeclaration.hh"
#include "IIRScram_Declaration.hh"
#include "IIRScram_DesignFile.hh"
#include "IIRScram_FunctionDeclaration.hh"
#include "IIRScram_Identifier.hh"
#include "IIRScram_InterfaceList.hh"
#include "IIRScram_ScalarTypeDefinition.hh"
#include "IIRScram_ProcedureDeclaration.hh"
#include "IIRScram_TypeDefinition.hh"
#include "error_func.hh"
#include "symbol_table.hh"
#include "set.hh"
#include <sstream>

IIRScram_AccessTypeDefinition::IIRScram_AccessTypeDefinition(){}
IIRScram_AccessTypeDefinition::~IIRScram_AccessTypeDefinition(){}

IIR_Boolean 
IIRScram_AccessTypeDefinition::_designates_incomplete_type() {
  IIRScram_TypeDefinitionRef type = _get_designated_type();
  if(  type != NULL && type->is_incomplete_type_definition() == TRUE ){
    return TRUE;
  } else {
    return FALSE;
  }
}

IIRBase_TypeDefinitionRef
IIRScram_AccessTypeDefinition::_get_element_subtype(){
  return my_dynamic_pointer_cast<IIRBase_TypeDefinition>(_get_designated_type()->_get_element_subtype());
}

void 
IIRScram_AccessTypeDefinition::_come_into_scope( symbol_table *sym_tab, 
						 IIRScram_TypeDeclarationRef type_declaration){
  
   //FIXME: this is an error
  sym_tab->get_in_scope_access_types().insert( IIR_AccessTypeDefinitionRef() );

  if( type_declaration->get_implicit_declarations().size() <= 0 ){
    IIRScram_TypeDefinition::_come_into_scope( sym_tab, type_declaration );
  
    std::string name = "deallocate";
    IIRScram_ProcedureDeclaration *new_procedure_declaration = new IIRScram_ProcedureDeclaration();
    copy_location( new_procedure_declaration );
    new_procedure_declaration->set_declarator( IIRScram_Identifier::get( name, get_design_file()->get_class_factory() ) );
    new_procedure_declaration->set_is_implicit( TRUE );
    
    IIR_InterfaceDeclarationRef new_interface_declaration(new IIRScram_ConstantInterfaceDeclaration());
    new_interface_declaration->set_is_implicit( TRUE );
    copy_location( new_interface_declaration.get() );
    
    name = "p";
    new_procedure_declaration->get_interface_declarations()->append( new_interface_declaration );
    
    new_interface_declaration->set_declarator(  IIRScram_Identifier::get( name, get_design_file()->get_class_factory() ) );
    // FIXME: this is an error
    new_interface_declaration->set_subtype( IIRScram_AccessTypeDefinitionRef() );
    new_interface_declaration->set_mode( IIR_INOUT_MODE );
    
    new_procedure_declaration->_add_declaration();
    
    type_declaration->get_implicit_declarations().insert( IIR_DeclarationRef(new_procedure_declaration) );    
  }
  else{
    sym_tab->add_declaration( type_declaration->get_implicit_declarations().convert_set<IIR_Declaration>());   
  }
}

void 
IIRScram_AccessTypeDefinition::set_is_element( IIR_Boolean new_is_element ){
  IIRScram_TypeDefinitionRef type = _get_designated_type();
  type->set_is_element( new_is_element );
}


IIRScramRef
IIRScram_AccessTypeDefinition::_clone(){
  IIRScramRef retval(new IIRScram_AccessTypeDefinition());
  _clone( retval );

  return retval;
}


void 
IIRScram_AccessTypeDefinition::_clone( IIRScramRef copy_into ){
  ASSERT( copy_into->_is_iir_access_type_definition() == TRUE );
  IIRScram_AccessTypeDefinitionRef as_access_type = my_dynamic_pointer_cast<IIRScram_AccessTypeDefinition>(copy_into);

  as_access_type->set_designated_type( get_designated_type() );

  IIRScram_TypeDefinition::_clone( copy_into );
}

void 
IIRScram_AccessTypeDefinition::_come_out_of_scope( symbol_table *sym_tab ){
  sym_tab->get_in_scope_access_types().erase( IIRScram_AccessTypeDefinitionRef() );
}

IIRScram_TypeDefinitionRef
IIRScram_AccessTypeDefinition::_construct_new_subtype( IIRScram_NameRef resolution_function,
						       IIRScram_ScalarTypeDefinitionRef new_constraint){

  IIRScram_TypeDefinitionRef retval(new IIRScram_AccessSubtypeDefinition());
  IIRScram_TypeDefinitionRef new_designated_type;
  IIRScram_TypeDefinitionRef old_type = _get_designated_type();

  if( old_type != NULL && old_type->is_incomplete_type_definition() == FALSE ){
    new_designated_type = old_type->_construct_new_subtype( 0, new_constraint);
    my_dynamic_pointer_cast<IIRScram_AccessSubtypeDefinition>(retval)->set_designated_subtype( new_designated_type );
  }
  else{
    ASSERT( new_constraint == NULL );
  }

  if( is_subtype() == TRUE ){
    retval->set_base_type( get_base_type() );
  }
  else{
     //FIXME: this is an error
    my_dynamic_pointer_cast<IIRScram_AccessSubtypeDefinition>(retval)->set_base_type( IIRScram_TypeDefinitionRef() );
  }

  if( resolution_function != NULL ){
    my_dynamic_pointer_cast<IIRScram_AccessSubtypeDefinition>(retval)->set_resolution_function(  _resolve_resolution_function( resolution_function ));
  }

  if( new_constraint != 0 ){
    retval->set_declaration( new_constraint->get_declaration() );
  }

  return retval;
}

IIRScram_AccessSubtypeDefinitionRef
IIRScram_AccessTypeDefinition::_construct_new_type( IIRScram_TypeDefinitionRef designated_type,
						                           IIRScram_TypeDeclarationRef    type_decl,
                                             IIRScram_DesignFileRef         design_file){

  IIRScram_AccessTypeDefinition *base_type = new IIRScram_AccessTypeDefinition();
  base_type->set_designated_type( designated_type );
  base_type->set_declaration( type_decl );
  base_type->_set_design_file( design_file );

  IIRScram_TypeDefinitionRef temp =  base_type->_construct_new_subtype( 0, 0 );
  ASSERT( temp->get_kind() == IIR_ACCESS_SUBTYPE_DEFINITION );
  IIRScram_AccessSubtypeDefinitionRef retval = my_dynamic_pointer_cast<IIRScram_AccessSubtypeDefinition>(temp);
  retval->set_declaration( type_decl );
  retval->set_designated_subtype( designated_type );

  return retval;
}


void 
IIRScram_AccessTypeDefinition::_set_resolution_function( IIRScram_FunctionDeclarationRef ){
  ostringstream err;
  err << "Internal error - IIRScram_AccessTypeDefinition::_set_resolution_function was "
      << "called.  Resolution functions can't be associated with an access type and this "
      << "should have been caught earlier.";
  report_error( this, err.str() );
}

IIRScram_TypeDefinitionRef
IIRScram_AccessTypeDefinition::_index_constrain_array( IIRScram_ScalarTypeDefinitionRef constraint){
   //FIXME: this is an error
  IIRScram_TypeDefinitionRef retval;
  IIRScram_TypeDefinitionRef type = _get_designated_type();
  ASSERT( type != NULL && type->is_array_type() == true );
  type->_index_constrain_array( constraint);

  return retval;
}

visitor_return_type *
IIRScram_AccessTypeDefinition::_accept_visitor(node_visitor *visitor, visitor_argument_type *arg) {
  ASSERT(visitor != NULL);
  return visitor->visit_IIR_AccessTypeDefinition(this, arg);
}

IIRScram_TypeDefinitionRef
IIRScram_AccessTypeDefinition::_get_designated_type() {
  return my_dynamic_pointer_cast<IIRScram_TypeDefinition>(get_designated_type());
}

IIR_Int32
IIRScram_AccessTypeDefinition::get_num_indexes(){
  IIRScram_TypeDefinitionRef type = _get_designated_type();

  ASSERT(type != NULL);
  return type->get_num_indexes();
}
