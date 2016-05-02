
// Copyright (c) 1995-2001 The University of Cincinnati.
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

// Author: Dale E. Martin      dmartin@cliftonlabs.com
//         Timothy J. McBrayer tmcbraye@ece.uc.edu
//         Michele Castellana blacklion727@gmail.com

//---------------------------------------------------------------------------

// This file contains the declaration of the class defining the symbol
// table for the SAVANT VHDL analyzer.  The symbol_table type is based
// off of a hash table functionality.  

#include "symbol_lookup.hh"
#include "savant.hh"
#include "set.hh"
#include "error_func.hh"
#include "IIR_Identifier.hh"
#include "IIRScram_Declaration.hh"
#include "IIRScram_DesignFile.hh"
#include "IIRScram_Identifier.hh"
#include "IIRScram_TextLiteral.hh"
#include "IIR_CharacterLiteral.hh"
#include "IIR_SimpleName.hh"
#include "scram_plugin_class_factory.hh"

#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sstream>

using std::cerr;
using std::endl;
using std::ofstream;
using std::ostringstream;

declaration_chain *
symbol_lookup::find_chain( IIR_TextLiteral *to_find ){
   ASSERT(to_find);
   return find_chain(to_find->get_text());
}

declaration_chain *
symbol_lookup::find_chain( char *to_find ){
   ASSERT( to_find );
   if( ht.find( std::string(to_find) ) != ht.end()  )
      return ht.find( std::string(to_find) )->second;
   declaration_chain *retval = new declaration_chain;
   retval->name = IIRScram_Identifier::get( to_find,
                                          strlen(to_find),
                                          scram_plugin_class_factory::instance());
   ht.insert( std::pair<std::string, declaration_chain*>(std::string(to_find), retval) );
   ASSERT( ht.find( std::string(to_find) ) != ht.end()  );
   return retval;
}

savant::set<IIR_Declaration> *
symbol_lookup::find_set( IIR_TextLiteral *text ) {
   ASSERT(text);
   return find_set(text->get_text());
}

savant::set<IIR_Declaration> *
symbol_lookup::find_set( char *text ) {
   ASSERT(text);
   declaration_chain *chain_ptr = find_chain( text );
   return &chain_ptr->declarations;
}

savant::set<IIR_Declaration> *
symbol_lookup::build_hidden_declaration_set( IIR_Declaration *about_to_add ){
  savant::set<IIR_Declaration> *retval = NULL;

  IIR_TextLiteral *name = about_to_add->get_declarator();  
  declaration_chain *decl_chain = find_chain( name );
  savant::set<IIR_Declaration> *current_declarations = &decl_chain->declarations;

  // TODO: Remove Scram
  IIRScram_Declaration *about_to_add_scram = dynamic_cast<IIRScram_Declaration *>(about_to_add);
  ASSERT(about_to_add_scram != NULL);
  IIRScram_Declaration *current_declaration = dynamic_cast<IIRScram_Declaration *>(current_declarations->getElement());
  while( current_declaration != NULL ){
    // There is at least one declaration with the same name visible.
    IIR_Boolean are_homographs = TRUE;
    IIR_Boolean can_be_in_same_region = FALSE;
    if( current_declaration == about_to_add ){
      goto next;
    }
    // If the declaration we're adding can be overloaded, then it won't
    // hide other declarations that can't be.
    are_homographs = about_to_add_scram->_is_homograph_of( current_declaration );
    if( are_homographs == TRUE ){
      // There are special circumstances that two declarations that _are_
      // homographs can be in the same region.  For instance, a subprogram
      // declaration and a subprogram body, or an incomplete type
      // declaration and it's complete type.  These are mainly due to
      // implentation issues and AIRE specific quirks.
      can_be_in_same_region = about_to_add_scram->_can_be_in_same_region( current_declaration );
              
      if( can_be_in_same_region == FALSE &&
	  (about_to_add_scram->_get_declarative_region() == 
	   current_declaration->_get_declarative_region())){
	ostringstream err;
	err << "Homographs :\n";
        // TODO: Remove Scram
	about_to_add_scram->_get_declarator()->publish_vhdl( err );
	err << " : " << about_to_add->get_kind_text();
	if( about_to_add->get_file_name() != NULL ){
	  err << " : " << *about_to_add_scram->get_file_name();
	}
	if( about_to_add->get_line_number() != -1 ){
	  err << " : " << about_to_add->get_line_number();
	}
	err << "\nand:\n";	  
	current_declaration->_get_declarator()->publish_vhdl( err );
	err << " : " << current_declaration->get_kind_text();
	if( current_declaration->get_file_name() != NULL ){
	  err << " : " << *current_declaration->get_file_name();
	}
	if( current_declaration->get_line_number() != -1 ){
	  err << " : " << current_declaration->get_line_number();
	}
	err << "\nare not allowed to be declared in the same declarative region.";
	report_error( about_to_add, err.str() );
      }

      if( retval == NULL ){
	retval = new savant::set<IIR_Declaration>();
      }
      retval->add( current_declaration );
    }
      
  next:
    current_declaration = dynamic_cast<IIRScram_Declaration *>(current_declarations->getNextElement());
  } // end searching for homographs...

  return retval;
}

void 
symbol_lookup::lookup_add( IIR_Declaration *decl_ptr) {
  savant::set<IIR_Declaration> *need_to_hide = build_hidden_declaration_set( decl_ptr );

  IIR_TextLiteral *name = decl_ptr->get_declarator();  
  declaration_chain *decl_chain = find_chain( name );
  savant::set<IIR_Declaration> *current_declarations = &decl_chain->declarations;
  hidden_symbol_entry *hidden_info = find_hidden_symbol_entry( decl_ptr, decl_chain );

  current_declarations->add(decl_ptr);

  if( need_to_hide != NULL ){
    // Add the old declaration to the list that is currently being
    // hidden by this declaration.
    if( debug_symbol_table ){
      cerr << this << " - ";
      // TODO: Remove Scram
      dynamic_cast<IIRBase_Declaration *>(decl_ptr)->publish_vhdl_decl( cerr );
      cerr << " (" << decl_ptr->get_kind_text() << " *)" << decl_ptr <<
	" - declared line - " << decl_ptr->get_line_number() << "\n";
      cerr << "is hiding" << endl;
      // TODO: Remove Scram
      IIRBase_Declaration *current =
	dynamic_cast<IIRBase_Declaration *>(need_to_hide->getElement());
      while( current != NULL ){
	current->publish_vhdl_decl( cerr );
	cerr << " (" << current->get_kind_text() << " *)" << current <<
	  " - declared line - " << current->get_line_number() << endl;
	current = dynamic_cast<IIRBase_Declaration *>(need_to_hide->getNextElement());
      }

      if( hidden_info != NULL ){
	cerr << "About to blow up - these are already hidden:\n";
        // TODO: Remove Scram
	IIRBase_Declaration *current =
	  dynamic_cast<IIRBase_Declaration*>(hidden_info->get_hidden_declarations()->getElement());
	while( current != NULL ){
	  current->publish_vhdl_decl( cerr );
	  cerr << " (" << current->get_kind_text() << " *)" << current <<
	    " - declared line - " << current->get_line_number() << endl;
	  current = dynamic_cast<IIRBase_Declaration *>
	    (hidden_info->get_hidden_declarations()->getNextElement());
	}
      }
    }
    
    ASSERT( hidden_info == NULL );
    update_hidden_symbol_entry( decl_ptr, need_to_hide, decl_chain );

    IIR_Declaration *current = dynamic_cast<IIRBase_Declaration *>(need_to_hide->getElement());
    while( current != NULL ){
      current_declarations->remove( current );
      current = dynamic_cast<IIRBase_Declaration *>(need_to_hide->getNextElement());
    }
  }
}

IIR_Boolean
symbol_lookup::is_visible( IIR_Declaration *decl_ptr ){
  ASSERT( decl_ptr != NULL );
  savant::set<IIR_Declaration> *decl_set = find_set( decl_ptr->get_declarator() );
  return decl_set->contains( decl_ptr );
}

void 
symbol_lookup::lookup_remove( IIR_Declaration *decl_ptr ){
   declaration_chain *decl_chain = find_chain( decl_ptr->get_declarator() );
   savant::set<IIR_Declaration> *decl_set = &decl_chain->declarations;
   hidden_symbol_entry *hidden_info = find_hidden_symbol_entry( decl_ptr, decl_chain );

  decl_set->remove( decl_ptr );

  if( hidden_info != NULL ){
    IIR_Declaration *current = hidden_info->get_hidden_declarations()->getElement();
    while( current != NULL ){
      if( debug_symbol_table ){
	cerr << this <<  " - Unhiding:\n";
	dynamic_cast<IIRBase_Declaration *>(current)->publish_vhdl_decl( cerr );
	cerr << " : ( " << current;
	cerr << " node type : " << current->get_kind_text() << ") " << endl;
      }
      
      decl_set->add( current );
      current = hidden_info->get_hidden_declarations()->getNextElement();
    }

    update_hidden_symbol_entry( decl_ptr, NULL, decl_chain );
  }    
}

hidden_symbol_entry *
symbol_lookup::find_hidden_symbol_entry( IIR_Declaration *to_find, 
					 declaration_chain *chain ){
  hidden_symbol_entry *retval = NULL;

  ASSERT( to_find != NULL );
  ASSERT( chain != NULL );

  hidden_symbol_entry *current = chain->hidden_declaration_info.getElement();
  while( current != NULL ){
    if( current->get_declaration() == to_find ){
      retval = current;
      break;
    }
    current = chain->hidden_declaration_info.getNextElement();
  }

  return retval;
}
  
void 
symbol_lookup::update_hidden_symbol_entry( IIR_Declaration *to_update, 
					   savant::set<IIR_Declaration> *hidden_decls,
					   declaration_chain *chain ){
  ASSERT( to_update != NULL );
  ASSERT( chain != NULL );
  // hidden decls _can_ be NULL 

  hidden_symbol_entry *hidden_entry = find_hidden_symbol_entry( to_update, chain );
  if( hidden_decls != NULL ){
    ASSERT( hidden_entry == NULL );
    hidden_symbol_entry *new_entry = new hidden_symbol_entry( to_update, hidden_decls );
    chain->hidden_declaration_info.add( new_entry );
  }
  else{
    // to_update has gone out of scope and we need to clear it's hidden info.
    chain->hidden_declaration_info.remove( hidden_entry );
    delete hidden_entry;
  }
}
