
// Copyright (c) 2002-2003 The University of Cincinnati.
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

// Author: Sivakumar Gowrisankar             gowriss@ececs.uc.edu

//---------------------------------------------------------------------------

#include "IIRScram_ArrayNatureDefinition.hh"
#include "IIRScram_ArraySubnatureDefinition.hh"
#include "IIRScram_DesignFile.hh"
#include "IIRScram_NatureDeclaration.hh"
#include "IIRScram_RangeTypeDefinition.hh"
#include "IIRScram_ScalarNatureDefinition.hh"
#include "IIRScram_TextLiteral.hh"

#include "symbol_table.hh"
#include "StandardPackage.hh"

IIRScram_ArrayNatureDefinition::IIRScram_ArrayNatureDefinition(){}

IIRScram_ArrayNatureDefinition::~IIRScram_ArrayNatureDefinition(){}

IIRScram_ArrayNatureDefinitionRef
IIRScram_ArrayNatureDefinition::_construct_array_type( IIRScram_ScalarTypeDefinitionRef index_subtype,
                                                       IIRScram_NatureDefinitionRef     element_subtype,
                                                       IIRScram_NatureDeclarationRef    declaration){
  if( index_subtype->_get_base_type_left() == NULL ){
    return _construct_unconstrained( index_subtype, element_subtype, declaration );
  }
  else{
    return _construct_constrained( index_subtype, element_subtype, declaration );
  }
}

IIRScram_ArraySubnatureDefinitionRef
IIRScram_ArrayNatureDefinition::_construct_unconstrained( IIRScram_ScalarTypeDefinitionRef index_subtype,
                                                          IIRScram_NatureDefinitionRef     element_subtype,
                                                          IIRScram_NatureDeclarationRef    declaration){

  IIRScram_ArrayNatureDefinition *base_type = new IIRScram_ArrayNatureDefinition();
  index_subtype->copy_location( base_type );
 
  ASSERT( index_subtype->_get_base_type_left() == NULL );
  ASSERT( index_subtype->_get_direction() == NULL );
  ASSERT( index_subtype->_get_base_type_right() == NULL );
 
  base_type->set_index_subtype( index_subtype );
  base_type->set_element_subtype( element_subtype );
  base_type->set_declaration( declaration );
  base_type->_set_design_file( declaration->_get_design_file());

  IIRScram_TypeDefinitionRef temp =  base_type->_construct_new_subtype( 0, 0 );
  ASSERT( temp->get_kind() == IIR_ARRAY_SUBNATURE_DEFINITION );
 
  IIRScram_ArraySubnatureDefinitionRef retval = my_dynamic_pointer_cast<IIRScram_ArraySubnatureDefinition>(temp);
  retval->set_declaration( declaration );
  return retval;
}

IIRScram_ArraySubnatureDefinitionRef
IIRScram_ArrayNatureDefinition::_construct_constrained( IIRScram_ScalarTypeDefinitionRef index_subtype,
                                                        IIRScram_NatureDefinitionRef,
                                                        IIRScram_NatureDeclarationRef declaration){

  IIRScram_ArrayNatureDefinitionRef base_type(new IIRScram_ArrayNatureDefinition());
  index_subtype->copy_location( base_type.get() );

  IIRScram_TypeDefinitionRef base_index_type;
  base_index_type = index_subtype->_get_new_subtype();
  base_index_type->set_base_type( index_subtype->get_base_type() );
  base_index_type->_set_resolution_function( index_subtype->_get_resolution_function() );
  base_index_type->set_type_mark( index_subtype );
  base_index_type->set_declaration( index_subtype->_get_declaration() );
  ASSERT( base_index_type->is_scalar_type_definition() == TRUE );
  base_type->set_index_subtype( my_dynamic_pointer_cast<IIRScram_ScalarTypeDefinition>(base_index_type) );
  base_type->_get_resolved_index_subtype()->set_type_mark( index_subtype );
  base_type->_set_design_file( declaration->_get_design_file());  

  IIRScram_NatureDefinitionRef temp = my_dynamic_pointer_cast<IIRScram_NatureDefinition>(base_type->_construct_new_subtype( 0, index_subtype ));
  ASSERT( temp->get_kind() == IIR_ARRAY_SUBNATURE_DEFINITION );

  IIRScram_ArraySubnatureDefinitionRef retval = my_dynamic_pointer_cast<IIRScram_ArraySubnatureDefinition>(temp);
  base_type->set_type_mark( retval );
  base_type->set_declaration( declaration );
  retval->set_declaration( declaration );

  return retval;
}

IIRScram_TypeDefinitionRef
IIRScram_ArrayNatureDefinition::_index_constrain_array( IIRScram_ScalarTypeDefinitionRef constraint ){
  IIRScram_TypeDefinitionRef original_index_subtype = _get_resolved_index_subtype();

  IIRScram_ArraySubnatureDefinitionRef retval;
  IIRScram_TypeDefinitionRef current_index_type = _get_resolved_index_subtype();
  current_index_type = current_index_type->_construct_new_subtype( NULL, constraint);

  if( constraint->is_subtype() == FALSE && constraint->is_anonymous() == FALSE ){
    current_index_type->set_type_mark( constraint );
  }
  else{
    current_index_type->set_type_mark( constraint->_get_type_mark() );
  }
  current_index_type->set_declaration( constraint->_get_declaration() );
  retval = IIRScram_ArraySubnatureDefinitionRef(new IIRScram_ArraySubnatureDefinition());
  copy_location( constraint.get(), retval.get() );

  ASSERT( current_index_type->is_scalar_type() == TRUE );
  retval->set_index_subtype( my_dynamic_pointer_cast<IIRScram_ScalarTypeDefinition>(current_index_type) );

  if( is_subtype() == TRUE ){
    retval->set_base_type( get_base_type() );
  }
  else{
    // FIXME: 
    retval->set_base_type( IIR_TypeDefinitionRef() );
  }

  ASSERT( original_index_subtype == _get_resolved_index_subtype() );

  return retval;
}

IIRScram_TypeDefinitionRef
IIRScram_ArrayNatureDefinition::_construct_new_subtype( IIRScram_NameRef,
                                                        IIRScram_ScalarTypeDefinitionRef index_constraint ){
  IIRScram_TypeDefinitionRef retval;

  if( index_constraint != NULL ){
    retval = _index_constrain_array( index_constraint );
    retval->set_element_subtype( my_dynamic_pointer_cast<IIRScram_NatureDefinition>(_get_element_subtype()) );
    retval->set_declaration( index_constraint->get_declaration() );
  }

  if( retval == NULL ){
    retval = _get_new_subtype();
    ASSERT( retval->_is_iir_array_type_definition() == TRUE );
    _clone( my_dynamic_pointer_cast<IIRScram_ArrayNatureDefinition>(retval) );
    if( is_subtype() ){
      retval->set_base_type( get_base_type() );
    }
    else{
       //FIXME: this is an error
      retval->set_base_type( IIR_TypeDefinitionRef() );
    }
  }
  return retval;
}

IIRBase_TypeDefinitionRef
IIRScram_ArrayNatureDefinition::_get_element_subtype(){
  return my_dynamic_pointer_cast<IIRBase_TypeDefinition>(get_element_subtype());
}

IIRScram_ScalarTypeDefinitionRef
IIRScram_ArrayNatureDefinition::_get_index_subtype(){
  return my_dynamic_pointer_cast<IIRScram_ScalarTypeDefinition>(get_index_subtype());
}
 
IIRScram_TypeDefinitionRef
IIRScram_ArrayNatureDefinition::_get_new_subtype(){
  IIRScram_TypeDefinitionRef retval(new IIRScram_ArraySubnatureDefinition());
  copy_location( this, retval.get() );
  return retval;
}

IIRScramRef
IIRScram_ArrayNatureDefinition::_clone(){
  IIRScram_ArrayNatureDefinitionRef type_def(new IIRScram_ArrayNatureDefinition());
  _clone( type_def );

  return type_def;
}

void
IIRScram_ArrayNatureDefinition::_clone( IIRScramRef my_clone ){
  ASSERT( my_clone->_is_iir_array_type_definition() == TRUE );
  IIRScram_ArrayNatureDefinitionRef as_array_type = my_dynamic_pointer_cast<IIRScram_ArrayNatureDefinition>(my_clone);

  as_array_type->set_index_subtype( get_index_subtype() );
  as_array_type->set_element_subtype( get_element_subtype() );

  IIRScram_TypeDefinition::_clone( my_clone );
}

IIR_Int32
IIRScram_ArrayNatureDefinition::get_num_indexes() {
  IIR_Int32 num_indexes = 1;

  IIRBase_TypeDefinitionRef current_subtype = _get_element_subtype();
  ASSERT(current_subtype != NULL);
  while( current_subtype->is_array_type() == TRUE
         && current_subtype->is_element() == FALSE ){
    num_indexes++;
    current_subtype = current_subtype->_get_element_subtype();
    ASSERT(current_subtype != NULL);
  }

  return num_indexes;
}
