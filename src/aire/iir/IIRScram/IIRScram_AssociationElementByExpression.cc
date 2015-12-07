
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
//          Timothy J. McBrayer 
//          Krishnan Subramani  
//          Umesh Kumar V. Rajasekaran
//          Malolan Chetlur     
//          Narayanan Thondugulam
//          Swaminathan Subramanian
//	    Magnus Danielson	cfmd@swipnet.se
//---------------------------------------------------------------------------

#include "IIRScram.hh"
#include "IIRScram_AssociationElementByExpression.hh"
#include "IIRScram_ArrayTypeDefinition.hh"
#include "IIRScram_CaseStatementAlternativeByChoices.hh"
#include "IIRScram_Choice.hh"
#include "IIRScram_ChoiceList.hh"
#include "IIRScram_ConcurrentStatement.hh"
#include "IIRScram_DesignFile.hh"
#include "IIRScram_InterfaceDeclaration.hh"
#include "IIRScram_Label.hh"
#include "IIRScram_RangeAttribute.hh"
#include "IIRScram_TextLiteral.hh"
#include "error_func.hh"
#include "resolution_func.hh"
#include "symbol_table.hh"

IIRScram_AssociationElementByExpression::~IIRScram_AssociationElementByExpression() {}

IIR_Boolean 
IIRScram_AssociationElementByExpression::_is_readable(){
   ASSERT( is_resolved() == TRUE );

   return _get_actual()->_is_readable();
}

IIR_Boolean 
IIRScram_AssociationElementByExpression::_is_writable(){
   ASSERT( is_resolved() == TRUE );
   return _get_actual()->_is_writable();
}

savant::set<IIRScram_TypeDefinitionRef>
IIRScram_AssociationElementByExpression::_get_rval_set(constraint_functor *functor){
   savant::set<IIRScram_TypeDefinitionRef> retval;

   // the actual will be NULL if the VHDL says "open".
   savant::set<IIRScram_TypeDefinitionRef> actual_rvals;
   if( _get_actual() != NULL ){
      actual_rvals = _get_actual()->_get_rval_set( functor );
      if( actual_rvals == NULL ){
         return savant::set<IIRScram_TypeDefinitionRef>();
      }
   }

   if( _get_formal() == NULL ){
      retval = actual_rvals;
   }
   else{
      switch( _get_formal()->get_kind() ){
         case IIR_INTEGER_LITERAL:
         case IIR_OTHERS_INITIALIZATION:
            {
               // Then we need to return an list of the array types with elements that match
               // the actuals.

               // Get the set of array types...
               savant::set<IIRScram_ArrayTypeDefinition*> *array_types = _get_symbol_table()->get_in_scope_array_types()->convert_set<IIRScram_ArrayTypeDefinition*>();

               for(auto it = array_types->begin(); it != array_types->end(); it++) {
                  ASSERT( *it != NULL);
                  bool one_matched = false;
                  for(auto it_in = actual_rvals->begin(); it_in != actual_rvals->end(); it_in++) {
                     ASSERT( *it_in != NULL);
                     if( (*it_in)->is_compatible( (*it)->_get_element_subtype()) != NULL ){
                        one_matched = true;
                     }
                  }

                  if( one_matched == true ){
                     if( retval == NULL ){
                        retval = new savant::set<IIRScram_TypeDefinition*>;
                     }
                     retval->insert( *it );
                  }
               }

               delete actual_rvals;

               break;
            }
         default:
            {
               //       savant::set<IIRScram_TypeDefinition*> *formal_rvals = _get_formal()->_get_rval_set();
               if( actual_rvals == NULL ){
                  return NULL;
               }
               else{
                  return actual_rvals;
               }
            }
      }
   }

   return retval;
}

void 
IIRScram_AssociationElementByExpression::_type_check( savant::set<IIRScram_TypeDefinitionRef> context_set ){
   IIRScram *expr = _get_actual();

   ASSERT( expr != NULL );

   expr->_type_check( context_set );
}

IIRScramRef
IIRScram_AssociationElementByExpression::_semantic_transform( savant::set<IIRScram_TypeDefinitionRef> context_set ){
   IIRScram *expr = _get_actual();

   ASSERT( expr != NULL );

   set_actual( expr->_semantic_transform( context_set ) );

   return this;
}

IIRScramRef
IIRScram_AssociationElementByExpression::_rval_to_decl( IIRScram_TypeDefinitionRef my_rval){

   if( is_by_others() == TRUE &&
         my_rval->is_array_type() == TRUE ){
      // Actual is an element of the array.
      IIRScram_TypeDefinition *element_subtype = my_rval->_get_element_subtype();
      set_actual( _get_actual()->_rval_to_decl( element_subtype) );
   }
   else{    
      set_actual( _get_actual()->_semantic_transform( my_rval ) );
      _get_actual()->_type_check( my_rval );
      set_actual( _get_actual()->_rval_to_decl( my_rval ) );
   }


   return (IIRScram *)this;
}

IIRScramRef
IIRScram_AssociationElementByExpression::_clone() {
   IIRScram *elem;
   IIRScram_AssociationElementByExpression *assoc;

   assoc = new IIRScram_AssociationElementByExpression();
   IIRScram::_clone( assoc );

   if (_get_formal() != NULL) {
      elem = _get_formal()->_clone();
      assoc->set_formal(elem);
   }
   elem = _get_actual()->_clone();
   assoc->set_actual(elem);

   return assoc;
}

visitor_return_type *
IIRScram_AssociationElementByExpression::_accept_visitor( node_visitor *visitor,
      visitor_argument_type *arg ){
   ASSERT(visitor != NULL);
   return visitor->visit_IIR_AssociationElementByExpression(this, arg);
}
