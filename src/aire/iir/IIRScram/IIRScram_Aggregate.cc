
// Copyright (c) 1996-2000 The University of Cincinnati.  
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
//          Krishnan Subramani  skrish@ece.uc.edu
//          Umesh Kumar V. Rajasekaran urajasek@ece.uc.edu
//	    Magnus Danielson	cfmd@swipnet.se

//---------------------------------------------------------------------------
#include "IIRScram_Aggregate.hh"
#include "IIRScram_AssociationElementByExpression.hh"
#include "IIRScram_AssociationList.hh"
#include "IIRScram_ArrayTypeDefinition.hh"
#include "IIRScram_DesignatorList.hh"
#include "IIRScram_DesignFile.hh"
#include "IIRScram_ElementDeclaration.hh"
#include "IIRScram_EnumerationTypeDefinition.hh"
#include "IIRScram_IntegerLiteral32.hh"
#include "IIRScram_Name.hh"
#include "IIRScram_RecordTypeDefinition.hh"
#include "IIRScram_ScalarTypeDefinition.hh"
#include "IIRScram_TextLiteral.hh"

#include "error_func.hh"
#include "symbol_table.hh"
#include <sstream>

IIRScram_Aggregate::IIRScram_Aggregate() {}
IIRScram_Aggregate::~IIRScram_Aggregate() {}

IIR_Boolean 
IIRScram_Aggregate::_is_readable( ){
  IIR_Boolean retval = TRUE;
  IIRScram_AssociationElementRef current_assoc;
  IIRScram_AssociationListRef list = my_dynamic_pointer_cast<IIRScram_AssociationList>(get_element_association_list());

  current_assoc = my_dynamic_pointer_cast<IIRScram_AssociationElement>(list->first());
  while( current_assoc != NULL ){
    if( current_assoc->_is_readable() == FALSE ){
      retval = FALSE;
    }
    current_assoc = my_dynamic_pointer_cast<IIRScram_AssociationElement>(list->successor( current_assoc ));
  }

  return retval;
}


IIR_Boolean 
IIRScram_Aggregate::_is_writable( ){
  IIR_Boolean retval = TRUE;
  IIRScram_AssociationElementRef current_assoc;
  IIRScram_AssociationListRef list = my_dynamic_pointer_cast<IIRScram_AssociationList>(get_element_association_list());

  current_assoc = my_dynamic_pointer_cast<IIRScram_AssociationElement>(list->first());
  while( current_assoc != NULL ){
    if( current_assoc->_is_writable() == FALSE ){
      retval = FALSE;
    }
    current_assoc = my_dynamic_pointer_cast<IIRScram_AssociationElement>(list->successor( current_assoc ));
  }

  return retval;
}

savant::set<IIRScram_TypeDefinitionRef>
IIRScram_Aggregate::_get_rval_set( constraint_functor * ){
  // This implements lines 390 - 395, page 103 of the '93 LRM
  savant::set<IIRScram_TypeDefinitionRef> retval;

  // Add all in scope array types.
  savant::set<IIRScram_ArrayTypeDefinitionRef> array_types = _get_symbol_table()->get_in_scope_array_types().convert_set<IIRScram_ArrayTypeDefinition>();
  for(auto it = array_types.begin(); it != array_types.end(); it++) {
    ASSERT( *it != NULL );
    ASSERT( (*it)->is_array_type() == TRUE );
    retval.insert( *it );
  }

  // Add all in scope record types.
  savant::set<IIRScram_RecordTypeDefinitionRef> record_types = _get_symbol_table()->get_in_scope_record_types().convert_set<IIRScram_RecordTypeDefinition>();
  
  for(auto it = record_types.begin(); it != record_types.end(); it++) {
    ASSERT( *it != NULL );
    ASSERT( (*it)->is_record_type() == TRUE );
    retval.insert( *it );
  }

  return retval;
}

void 
IIRScram_Aggregate::_type_check( savant::set<IIRScram_TypeDefinitionRef> ){
  // First set of type checks.
  IIR_Boolean           have_seen_named = false;
  IIR_Boolean           have_seen_others = false;
  IIRScram_AssociationListRef list = my_dynamic_pointer_cast<IIRScram_AssociationList>(get_element_association_list());

  IIRScram_AssociationElementRef current = my_dynamic_pointer_cast<IIRScram_AssociationElement>(list->first());

  while( current != NULL ){
    if( current->is_named() == TRUE ){
      have_seen_named = TRUE;
    }
    if( current->_is_positional() == TRUE && have_seen_named == TRUE ){
      ostringstream err;
      err << "Positional associations cannot follow named associations in an aggregate.";
      report_error( current.get(), err.str() );
    }

    if( have_seen_others == TRUE ){
      // That means (due to the order of these if statements) that there was something
      // after the others!
      ostringstream err;
      err << "No association can follow an \"others\" association in an aggregate.";
      report_error( current.get(), err.str() );      
    }

    if( current->is_by_others() == TRUE ){
      have_seen_others = TRUE;
    }
    current = my_dynamic_pointer_cast<IIRScram_AssociationElement>(list->successor( current ));
  }
}

void 
IIRScram_Aggregate::_rval_to_decl_process_named_part( IIRScram_TypeDefinitionRef my_type, 
						      IIRScram_AssociationElementRef starting_with ){
  ASSERT( my_type->_is_iir_record_type_definition() == TRUE );

  IIRScram_AssociationElementRef current_association = starting_with;
  while( current_association != NULL ){
    if( current_association->get_formal() != NULL ){
      IIRScramRef current_formal = my_dynamic_pointer_cast<IIRScram>(current_association->get_formal());
      
      switch( current_formal->get_kind() ){
      case IIR_SIMPLE_NAME:{
	savant::set<IIRScram_DeclarationRef> element_decls;
        
        if ( my_type->find_declarations( my_dynamic_pointer_cast<IIRScram_Name>(current_formal) ).size() <= 0 ){
	  element_decls = my_type->find_declarations( my_dynamic_pointer_cast<IIRScram_Name>(current_formal) ).convert_set<IIRScram_Declaration>();
        }

	if( element_decls.size() <= 0 ){
	  ostringstream err;
	  err << "Internal error - |" << *current_formal << "| was not found in record type |"
	      << *my_type << "| in IIRScram_Aggregate::_rval_to_decl_process_named_part.";
	  report_error( this, err.str() );
	}
	else{
	  ASSERT( element_decls.size() == 1 );
	  IIRScram_DeclarationRef element_decl = *(element_decls.begin());
	  
	  current_association->set_formal( element_decl );
	  IIRScram_TypeDefinitionRef actual_type = element_decl->_get_subtype();
	  
	  ASSERT( current_association->get_kind() == IIR_ASSOCIATION_ELEMENT_BY_EXPRESSION );	
	  current_association->set_actual( current_association->_get_actual()->_semantic_transform( actual_type ) );
	  current_association->_get_actual()->_type_check( actual_type );
	  current_association->set_actual( current_association->_get_actual()->_rval_to_decl( actual_type ) );
	  
	}
	break;
      }
      case IIR_OTHERS_INITIALIZATION:{
	ostringstream err;
	err << "Internal error - others not supported in aggregate initialization of records, yet!";
	report_error( this, err.str() );
	break;
      }
      default:{
	if( current_formal->is_resolved() == TRUE ){
	  // OK, formal is already resolved; we need to deal with the actual.
	  IIRScram_TypeDefinitionRef actual_type = current_formal->_get_subtype();
	  ASSERT( current_association->get_kind() == IIR_ASSOCIATION_ELEMENT_BY_EXPRESSION );	
	  current_association->set_actual( current_association->_get_actual()->_semantic_transform( actual_type ) );
	  current_association->_get_actual()->_type_check( actual_type );
	  current_association->set_actual( current_association->_get_actual()->_rval_to_decl( actual_type ) );
	}
	else{
	  ostringstream err;
	  err << "Internal error - unexpected formal node type " << current_formal->get_kind_text()
	      << "(node == |" << *current_formal << "|)"
	      << " in IIRScram_Aggregate::_rval_to_decl_process_named_part.";
	  report_error( this, err.str() );
	}
      }
      }
    }
    else{
      ostringstream err;
      if( current_association->get_kind() == IIR_ASSOCIATION_ELEMENT_BY_EXPRESSION &&
	  current_association->_get_actual() != NULL &&
	  current_association->_get_actual()->get_kind() == IIR_OTHERS_INITIALIZATION ){
	err << "Others initialization isn't handled in this context yet.";
	report_error( this, err.str() );
      }
      else{
	err << "Internal error in IIRScram_Aggregate::_rval_to_decl_process_named_part - "
	    << "formal is null and actual is ";
	if( current_association->_get_actual() == NULL ){
	  err << "NULL";
	}
	else{
	  err << "an " << current_association->_get_actual()->get_kind_text()
	      << "(the node is |" << current_association->_get_actual() << "|),";
	}
      }
    }

    current_association = my_dynamic_pointer_cast<IIRScram_AssociationElement>(get_element_association_list()->successor( my_dynamic_pointer_cast<IIR_AssociationElement>(current_association) ));
  }
}

IIRScramRef
IIRScram_Aggregate::_rval_to_decl( IIRScram_TypeDefinitionRef my_type ){
  ASSERT( my_type->is_array_type() == TRUE || my_type->is_record_type() );
  
  enum processing_mode_t { ARRAY, RECORD, ERROR };

  processing_mode_t processing_mode = ERROR;
  if( my_type->is_array_type() == TRUE ){
    processing_mode = ARRAY;
  }
  else if( my_type->is_record_type() == TRUE ){
    processing_mode = RECORD;
  }

  ASSERT( processing_mode != ERROR );
  IIRScram_TypeDefinitionRef actual_type;
  IIRScram_TypeDefinitionRef formal_type;

  int i;
  for( i = 0; i < get_element_association_list()->size(); i++ ){
    IIRScram_AssociationElementRef current_association 
      = my_dynamic_pointer_cast<IIRScram_AssociationElement>(get_element_association_list()->get_nth_element( i ));
    
    if( processing_mode == ARRAY ){
      formal_type = my_type->_get_resolved_index_subtype();
      if( current_association->is_by_others() == TRUE ){
	actual_type = my_type;
      }
      else{
	actual_type = my_dynamic_pointer_cast<IIRScram_TypeDefinition>(my_type->_get_element_subtype());
      }
    }
    else{
      // This code isn't handling named associations, at the moment!
      IIRScram_RecordTypeDefinitionRef my_record_type = my_dynamic_pointer_cast<IIRScram_RecordTypeDefinition>(my_type);
      actual_type = my_dynamic_pointer_cast<IIRScram_TypeDefinition>(my_record_type->_get_element_subtype( i ));
      formal_type = my_dynamic_pointer_cast<IIRScram_TypeDefinition>(my_record_type->_get_element_subtype( i ));
    }
    
    ASSERT( actual_type != NULL );
    ASSERT( formal_type != NULL );

    if( current_association->get_formal() != NULL ){
      if( processing_mode == ARRAY ){
	IIRScramRef old_formal = my_dynamic_pointer_cast<IIRScram>(current_association->get_formal());

	IIRScramRef new_formal = old_formal->_semantic_transform( formal_type );
	new_formal->_type_check( formal_type );
	new_formal = new_formal->_rval_to_decl( formal_type );

	current_association->set_formal( new_formal );
      }
      else{
	_rval_to_decl_process_named_part( my_type, current_association );
	break;
      }
    }
    
    if( current_association->get_kind() == IIR_ASSOCIATION_ELEMENT_BY_EXPRESSION ){
      current_association->set_actual( current_association->_get_actual()->_semantic_transform( actual_type ) );
      current_association->_get_actual()->_type_check( actual_type );
      current_association->set_actual( current_association->_get_actual()->_rval_to_decl( actual_type ) );
    }
  }
    
  set_subtype( my_type );

  ASSERT( is_resolved() == TRUE );

  //FIXME: this is an error
  return IIRScramRef();
}


// This method publishes a default range to the aggregate.  The default range
// is not specified in the LRM.  I used (1, to, n) -- SK.

IIRScramRef
IIRScram_Aggregate::_clone(){
  IIRScram_AggregateRef retval(new IIRScram_Aggregate());
  IIRScram_Expression::_clone( retval );

  IIR_AssociationListRef new_list(new IIRScram_AssociationList());
  
  for (IIRScram_AssociationElementRef cur_elem = my_dynamic_pointer_cast<IIRScram_AssociationElement>(_get_element_association_list()->first());
       cur_elem != NULL; 
       cur_elem = my_dynamic_pointer_cast<IIRScram_AssociationElement>(_get_element_association_list()->successor(cur_elem))) {
    new_list->append(cur_elem);
  }
  retval->set_element_association_list(new_list);

  return retval;
}

IIRScram_AssociationListRef
IIRScram_Aggregate::_get_element_association_list() {
  return my_dynamic_pointer_cast<IIRScram_AssociationList>(get_element_association_list());
}

visitor_return_type *
IIRScram_Aggregate::_accept_visitor( node_visitor *visitor,
				     visitor_argument_type *arg ){
  ASSERT(visitor != NULL);
 
  return visitor->visit_IIR_Aggregate(this, arg);
}

