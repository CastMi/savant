
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

//---------------------------------------------------------------------------

#include "savant.hh"
#include "IIRBase_DeclarationList.hh"
#include "set.hh"
#include "IIR.hh"
#include "IIR_Declaration.hh"
#include "IIR_Name.hh"
#include "IIR_SelectedName.hh"
#include "IIR_TypeDeclaration.hh"
#include "IIRBase_TextLiteral.hh"
#include "IIRBase_Declaration.hh"

IIRBase_DeclarationList::IIRBase_DeclarationList(){}
IIRBase_DeclarationList::~IIRBase_DeclarationList(){}

void 
IIRBase_DeclarationList::append( IIR_DeclarationRef to_append ){
   IIRBase_List::append( to_append );
}

IIRRef
IIRBase_DeclarationList::successor( IIR_DeclarationRef succeed_me ){
   IIRRef retval = IIRBase_List::successor( succeed_me );
   return my_dynamic_pointer_cast<IIR_Declaration>(retval);
}

IIRRef
IIRBase_DeclarationList::first(){
   IIRRef retval = IIRBase_List::first();

   return my_dynamic_pointer_cast<IIR_Declaration>(retval);
}


void
IIRBase_DeclarationList::prepend( IIR_DeclarationRef element ) {
   IIRBase_List::prepend( element );
}

IIRRef
IIRBase_DeclarationList::predecessor( IIR_DeclarationRef element ){
   IIRRef retval = IIRBase_List::predecessor( element );

   ASSERT( retval != nullptr );

   return my_dynamic_pointer_cast<IIR_Declaration>(retval);
}


IIRRef
IIRBase_DeclarationList::last() {
   IIRRef retval = IIRBase_List::last( );

   ASSERT( retval != nullptr );

   return my_dynamic_pointer_cast<IIR_Declaration>(retval);
}

IIRRef
IIRBase_DeclarationList::get_nth_element( IIR_Int32 to_get ){
   IIRRef retval = IIRBase_List::get_nth_element( to_get );

   ASSERT( retval != nullptr );

   return my_dynamic_pointer_cast<IIR_Declaration>(retval);
}

savant::set<IIR_DeclarationRef>
IIRBase_DeclarationList::find_declarations( IIR_NameRef to_find ){
   ASSERT( to_find != nullptr );
   savant::set<IIR_DeclarationRef> retval;
   // The following assertion holds true because an indexed name doesn't generally
   // map into a declaration.  So, we can't expect to look at a list of declarations,
   // searching for an indexed name, and really find anything.
   ASSERT( to_find->get_kind() != IIR_INDEXED_NAME );

   switch( to_find->get_kind() ){
      case IIR_SIMPLE_NAME:{
                              ASSERT( to_find->get_prefix() != nullptr );
                              IIR_TextLiteralRef prefix = my_dynamic_pointer_cast<IIR_TextLiteral>(to_find->get_prefix());
                              ASSERT( prefix != nullptr );
                              retval = find_declarations( prefix );
                              break;
                           }
      case IIR_SELECTED_NAME:{
                                IIR_SelectedNameRef as_selected_name = my_dynamic_pointer_cast<IIR_SelectedName>(to_find);
                                ASSERT( to_find->get_prefix() != nullptr );
                                ASSERT( my_dynamic_pointer_cast<IIR_Name>(to_find->get_prefix()) );

                                savant::set<IIR_DeclarationRef> found = find_declarations( my_dynamic_pointer_cast<IIR_Name>(to_find->get_prefix()) );
                                if( found.size() > 0 ) {
                                   ASSERT( as_selected_name->get_suffix() != nullptr );
                                   ASSERT( my_dynamic_pointer_cast<IIR_Name>(as_selected_name->get_suffix()) );
                                   savant::set<IIR_DeclarationRef> current_set;

                                   for(auto it = found.begin(); it != found.end(); it++) {
                                      ASSERT( *it != nullptr);
                                      current_set = 
                                         (*it)->find_declarations(my_dynamic_pointer_cast<IIR_Name>(as_selected_name->get_suffix()) );
                                      retval.insert( current_set );
                                   }
                                }
                                break;
                             }
      default:{
                 ASSERT(0);  // Internal error
              }
   }
   return retval;
}

savant::set<IIR_DeclarationRef>
IIRBase_DeclarationList::find_declarations( IIR_TextLiteralRef to_find ){
   savant::set<IIR_DeclarationRef> retval;
   ASSERT( to_find != nullptr );

   for (IIR_DeclarationRef current = my_dynamic_pointer_cast<IIR_Declaration>(first());
         current != nullptr;
         current = my_dynamic_pointer_cast<IIR_Declaration>(successor(current))) {
      if( IIRBase_TextLiteral::cmp( current->get_declarator(), to_find ) == 0 ){
         retval.insert( current );
      }
      else{
         if( current->get_kind() == IIR_TYPE_DECLARATION ){
            // We need to search the implicit declarations for whatever we're
            // looking for.
            IIR_TypeDeclarationRef as_type_decl = my_dynamic_pointer_cast<IIR_TypeDeclaration>(current);
            ASSERT( as_type_decl->get_implicit_declarations().size() > 0 );

            for(auto it = as_type_decl->get_implicit_declarations().begin(); 
                  it != as_type_decl->get_implicit_declarations().end();
                  it++) {
               ASSERT( *it != NULL);
               if( IIRBase_TextLiteral::cmp( (*it)->get_declarator(), to_find ) == 0 ){
                  retval.insert( *(it) );
               }
            }

            // If we have an enumeration type, we need to search for the our
            // culprit in the literal list.
            if( current->is_enumeration_type() == TRUE ){
               savant::set<IIR_DeclarationRef> enumeration_literals = current->find_declarations( to_find );
               if( enumeration_literals.size() > 0 ){
                  ASSERT( enumeration_literals.size() == 1 );
                  retval.insert( enumeration_literals );
               }
            }
         }
      }
   }
   return retval;
}

void
IIRBase_DeclarationList::set_declarative_region( IIRRef new_declarative_region ){
   IIR_DeclarationRef current = my_dynamic_pointer_cast<IIR_Declaration>(first());
   while( current != nullptr ){
      current->set_declarative_region( new_declarative_region );
      current = my_dynamic_pointer_cast<IIR_Declaration>(successor( current ));
   }
}

void
IIRBase_DeclarationList::publish_vhdl(ostream &vhdl_out) {
   for (IIRBase_DeclarationRef decl = my_dynamic_pointer_cast<IIRBase_Declaration>(first());
         decl != NULL;decl = my_dynamic_pointer_cast<IIRBase_Declaration>(successor(decl))) {
      decl->publish_vhdl(vhdl_out);
   }
}

void 
IIRBase_DeclarationList::publish_vhdl_decl(ostream &vhdl_out) {
   for (IIRBase_DeclarationRef decl = my_dynamic_pointer_cast<IIRBase_Declaration>(first());
         decl != NULL;decl = my_dynamic_pointer_cast<IIRBase_Declaration>(successor(decl))) {
      decl->publish_vhdl_decl(vhdl_out);
   }
}
