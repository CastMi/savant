
// Copyright (c) 1996-2003 The University of Cincinnati.  
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

// Authors: Philip A. Wilsey	philip.wilsey@ieee.org
//          Dale E. Martin	dmartin@cliftonlabs.com
//          Malolan Chetlur     
//          Timothy J. McBrayer 
//          Krishnan Subramani  
//          Narayanan Thondugulam
//          Radharamanan Radhakrishnan
//	    Magnus Danielson	cfmd@swipnet.se
//---------------------------------------------------------------------------

#include "IIRScram_DeclarationList.hh"
#include "IIRScram_AttributeSpecification.hh"
#include "IIRScram_ConfigurationSpecification.hh"
#include "IIRScram_DisconnectSpecification.hh"
#include "IIRScram_LibraryClause.hh"
#include "IIRScram_LibraryDeclaration.hh"
#include "IIRScram_UseClause.hh"
#include "IIRScram_Statement.hh"
#include "IIRScram_ArchitectureStatementList.hh"

template <class type>
IIRScram_DeclarationList<type>::~IIRScram_DeclarationList() {}

template <class type>
void 
IIRScram_DeclarationList<type>::_type_check_configuration_specifications( IIRScram_ArchitectureStatementList *statement_list ){
  for(IIRScram_Declaration *current_declaration = dynamic_cast<IIRScram_Declaration *>(this->first());
       current_declaration != NULL;
       current_declaration = dynamic_cast<IIRScram_Declaration *>(this->successor(current_declaration))) {
    if( current_declaration->_is_iir_configuration_specification() == true ){
      IIRScram_ConfigurationSpecification *as_specification = dynamic_cast<IIRScram_ConfigurationSpecification *>(current_declaration);
      ASSERT( as_specification );
      as_specification->_type_check( statement_list, 
				     IIRScram_ConfigurationSpecification::CONFIG_SPEC );
    }
  }
}

template <class type>
void 
IIRScram_DeclarationList<type>::_type_check_disconnection_specifications( ){
  for (IIRScram_Declaration *decl = dynamic_cast<IIRScram_Declaration *>(this->first());
       decl != NULL;decl = dynamic_cast<IIRScram_Declaration *>(this->successor(decl))) {
    if( decl->_is_iir_disconnect_specification() == true ){
      IIRScram_DisconnectSpecification *as_specification;
      as_specification = dynamic_cast<IIRScram_DisconnectSpecification *>(decl);
      as_specification->_type_check( this );
    }
  }
}

template <class type>
void 
IIRScram_DeclarationList<type>::_type_check_attribute_specifications() {
  for (IIRScram_Declaration *decl = dynamic_cast<IIRScram_Declaration *>(this->first());
       decl != NULL;decl = dynamic_cast<IIRScram_Declaration *>(this->successor(decl))) {
    if( decl->_is_iir_attribute_specification() == true ){
      IIRScram_AttributeSpecification *as_specification;
      as_specification = dynamic_cast<IIRScram_AttributeSpecification *>(decl);
      as_specification->_type_check( this );
    }
  }
}

template <class type>
void 
IIRScram_DeclarationList<type>::_make_visible_as_context_list( symbol_table *sym_tab ){
  for (IIRScram_Declaration *current = dynamic_cast<IIRScram_Declaration *>(this->first());
       current != NULL;current = dynamic_cast<IIRScram_Declaration *>(this->successor(current))) {
    ASSERT( current->get_kind() == IIR_LIBRARY_CLAUSE || 
	    current->get_kind() == IIR_USE_CLAUSE );
    // Don't do anything with library clauses, we don't need them in the
    // symbol table and putting them there causes homograph problems.
    
    if( current->get_kind() == IIR_USE_CLAUSE ){
      IIRScram_UseClause *as_use_clause = dynamic_cast<IIRScram_UseClause *>(current);
      ASSERT( as_use_clause->get_selected_name() != NULL );
      current->_make_interface_visible(  sym_tab );
    }
  }
}

template <class type>
IIRScram_DeclarationList<type> *
IIRScram_DeclarationList<type>::_build_constrained_list( IIR_Boolean (IIRScram::*constraint_function)() ){
  ASSERT ( constraint_function != 0 );
  
  // Not using clone because clone copies the elements in the list.
  // We want a new list that contains the exact same elements.
  IIRScram_DeclarationList<type> *cloned_list = new IIRScram_DeclarationList();
  for (IIRScram_Declaration *ptr = dynamic_cast<IIRScram_Declaration *>(this->first()); 
       ptr != NULL; ptr = dynamic_cast<IIRScram_Declaration *>(this->successor(ptr))) {
    cloned_list->append(ptr);
  }

  ASSERT( cloned_list->get_kind() == this->get_kind() );
  ASSERT( cloned_list->size() == this->num_elements() );

  IIRScram_Declaration *next = NULL;
  IIRScram_Declaration *current = dynamic_cast<IIRScram_Declaration *>(cloned_list->first());
  while( current != NULL ){
    next = dynamic_cast<IIRScram_Declaration *>(cloned_list->successor( current ));    
    if( (current->*constraint_function)() == false ){
      cloned_list->remove( current );
    }
    current = next;
  }
  return cloned_list;
}

template <class type>
IIRScram *
IIRScram_DeclarationList<type>::_clone(){
  IIRScram_DeclarationList *my_clone = new IIRScram_DeclarationList();
  //IIRScram_List::_clone( my_clone );

  //ASSERT( get_kind() == my_clone->get_kind() );
  ASSERT( false );
  
  return my_clone;
}
