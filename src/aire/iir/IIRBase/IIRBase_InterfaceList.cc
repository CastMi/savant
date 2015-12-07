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
//          Timothy J. McBrayer tmcbraye@ece.uc.edu

//---------------------------------------------------------------------------

#include "IIRBase_InterfaceList.hh"
#include "IIRBase_InterfaceDeclaration.hh"

IIRBase_InterfaceList::IIRBase_InterfaceList() {}
IIRBase_InterfaceList::~IIRBase_InterfaceList() {}

IIRRef
IIRBase_InterfaceList::first() {
  IIRRef element = IIRBase_DeclarationList::first();

  return element;
}

IIRRef
IIRBase_InterfaceList::successor(IIR_InterfaceDeclarationRef node) {
  IIRRef element = IIRBase_DeclarationList::successor( node );
  return element;
}

IIRRef
IIRBase_InterfaceList::get_nth_element( IIR_Int32 position ){
  IIRRef element = IIRBase_DeclarationList::get_nth_element( position );

  ASSERT( element != NULL );

  return element;  
}


void
IIRBase_InterfaceList::prepend( IIR_InterfaceDeclarationRef element ) {
  IIRRef test = element;
  ASSERT( test != nullptr ); 

  IIRBase_DeclarationList::prepend( element );
}


void
IIRBase_InterfaceList::append( IIR_InterfaceDeclarationRef element ) {
  IIRRef test = element;
  ASSERT( test != nullptr );
  
  IIRBase_DeclarationList::append( element );
}


void 
IIRBase_InterfaceList::insert_after( IIR_InterfaceDeclarationRef existing_element,
				     IIR_InterfaceDeclarationRef new_element) {
  IIRRef new_element_test = new_element;
  ASSERT( new_element_test != nullptr );
  IIRRef existing_element_test = existing_element_test;
  ASSERT( existing_element_test != nullptr );
  
  IIRBase_DeclarationList::insert_after( existing_element, new_element );
}

IIRRef
IIRBase_InterfaceList::predecessor( IIR_InterfaceDeclarationRef element ){
  IIRRef test = element;
  ASSERT( test != nullptr );
  
  IIRRef retval = my_dynamic_pointer_cast<IIR_Declaration>(IIRBase_DeclarationList::predecessor( element ));

  test = retval;
  ASSERT( test != nullptr );
  
  return retval;
}

IIRRef
IIRBase_InterfaceList::last() {
  IIRRef retval = last( );
  ASSERT( retval != nullptr );

  return retval;
}


IIR_Int32
IIRBase_InterfaceList::get_position( IIR_InterfaceDeclarationRef element ) {
  IIRRef test = element;
  ASSERT( test != nullptr );

  return IIRBase_DeclarationList::get_position( element );
}

void 
IIRBase_InterfaceList::publish_vhdl(ostream &vhdl_out) {
  IIRBase_InterfaceDeclarationRef interface_element;

  interface_element = my_dynamic_pointer_cast<IIRBase_InterfaceDeclaration>(first());
  while (interface_element != NULL) {
    interface_element->publish_vhdl(vhdl_out);
    interface_element = my_dynamic_pointer_cast<IIRBase_InterfaceDeclaration>(successor(interface_element));
    if (interface_element != NULL) {
      vhdl_out << "; ";
    }
  }
}

void 
IIRBase_InterfaceList::publish_vhdl_decl(ostream &vhdl_out) {
  IIRBase_InterfaceDeclarationRef interface_element;

  interface_element = my_dynamic_pointer_cast<IIRBase_InterfaceDeclaration>(first());
  while (interface_element != nullptr) {
    interface_element->publish_vhdl_decl(vhdl_out);
    interface_element = my_dynamic_pointer_cast<IIRBase_InterfaceDeclaration>(successor(interface_element));
    if (interface_element != nullptr) {
      vhdl_out << "; ";
    }
  }
}
