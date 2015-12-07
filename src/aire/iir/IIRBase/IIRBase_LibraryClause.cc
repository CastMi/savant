
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
//          Malolan Chetlur     mal@ece.uc.edu

//---------------------------------------------------------------------------


#include "IIRBase_LibraryClause.hh"
#include "IIR_Identifier.hh"
#include "IIR_LibraryDeclaration.hh"
#include "savant.hh"

IIRBase_LibraryClause::IIRBase_LibraryClause() {}
IIRBase_LibraryClause::~IIRBase_LibraryClause() {}

void
IIRBase_LibraryClause::set_logical_name(IIR_IdentifierRef logical_name) {
  this->logical_name = logical_name;
}

IIR_IdentifierRef
IIRBase_LibraryClause::get_logical_name() {
  return logical_name;
}

void
IIRBase_LibraryClause::set_library_declaration( IIR_LibraryDeclarationRef new_library_declaration ){
  library_declaration = new_library_declaration;
}

IIR_LibraryDeclarationRef
IIRBase_LibraryClause::get_library_declaration(){
  return library_declaration;
}

IIRRef
IIRBase_LibraryClause::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_LibraryClauseRef new_node =
    my_dynamic_pointer_cast<IIRBase_LibraryClause>(IIRBase_Declaration::convert_tree(factory));

  // Process the variables
  new_node->logical_name = my_dynamic_pointer_cast<IIR_Identifier>(convert_node(logical_name, factory));

  new_node->library_declaration =
    my_dynamic_pointer_cast<IIR_LibraryDeclaration>(convert_node(library_declaration, factory));
  
  return new_node;
}

bool
IIRBase_LibraryClause::is_work_library(){
  bool retval = false;
  if( library_declaration != nullptr ){
    retval = library_declaration->is_work_library();
  }
  return retval;
}

void 
IIRBase_LibraryClause::publish_vhdl(ostream &vhdl_out) {
  vhdl_out << "library ";
  get_logical_name()->publish_vhdl(vhdl_out);
  vhdl_out << ";\n";
}

void 
IIRBase_LibraryClause::publish_vhdl_decl(ostream &vhdl_out) {
  publish_vhdl( vhdl_out );
}
