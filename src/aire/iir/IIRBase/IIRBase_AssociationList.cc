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
//          Timothy J. McBrayer tmcrbaye@ece.uc.edu

//---------------------------------------------------------------------------

#include "IIRBase_AssociationList.hh"
#include "IIRBase_AssociationElement.hh"
#include <boost/pointer_cast.hpp>

IIRBase_AssociationList::IIRBase_AssociationList() {}
IIRBase_AssociationList::~IIRBase_AssociationList() {}

IIR_AssociationElementRef
IIRBase_AssociationList::first() {
  return my_dynamic_pointer_cast<IIR_AssociationElement>( IIRBase_List::first() );
}

IIR_AssociationElementRef
IIRBase_AssociationList::successor( IIR_AssociationElementRef node ) {
  return my_dynamic_pointer_cast<IIR_AssociationElement>(IIRBase_List::successor( node ));
}

IIR_Boolean
IIRBase_AssociationList::is_resolved(){
  IIR_Boolean retval = TRUE;

  IIR_AssociationElementRef current = my_dynamic_pointer_cast<IIR_AssociationElement>(first());
  while( current.get() != NULL ){
    if( current->is_resolved() == FALSE ){
      retval = FALSE;
    }

    current = my_dynamic_pointer_cast<IIR_AssociationElement>(successor( current ));
  }
  
  return retval;
}

IIR_Boolean 
IIRBase_AssociationList::is_above_attribute_found() {
  IIR_Boolean retval = FALSE;
  IIR_AssociationElementRef node = my_dynamic_pointer_cast<IIR_AssociationElement>(first());
  for (;node.get() != NULL; node = my_dynamic_pointer_cast<IIR_AssociationElement>(successor(node))) {
    retval = retval || node->is_above_attribute_found();
  }
  return retval;
}

IIR_Boolean
IIRBase_AssociationList::is_locally_static() {
  IIR_Boolean retval = true;

  IIR_AssociationElementRef current = first();
  while( current.get() != NULL ){
    if( !current->is_locally_static() ){
      retval = false;
      break;
    }
    current = successor( current );
  }
  return retval;
}

ostream &
IIRBase_AssociationList::print( ostream &os ){
  
  IIR_AssociationElementRef current = my_dynamic_pointer_cast<IIR_AssociationElement>(first());
  if( current != NULL ){
    os << *current;
  }
  while( current.get() != NULL ){
    current = my_dynamic_pointer_cast<IIR_AssociationElement>(successor( current ));
    if( current.get() != NULL ){
      os << ", " << *current;
    }
  }
  
  return os;
}

void 
IIRBase_AssociationList::publish_vhdl(ostream &vhdl_out) {
  IIRBase_AssociationElementRef node = my_dynamic_pointer_cast<IIRBase_AssociationElement>(first());

  if (node.get() != NULL) {
    node->publish_vhdl(vhdl_out);
    for (node = my_dynamic_pointer_cast<IIRBase_AssociationElement>(successor(node)); 
         node != NULL; node = my_dynamic_pointer_cast<IIRBase_AssociationElement>(successor(node))) {
      vhdl_out << ", ";
      node->publish_vhdl(vhdl_out);
    }
  }
}

void
IIRBase_AssociationList::publish_vhdl_without_formals(ostream &vhdl_out) {
  IIRBase_AssociationElementRef node = my_dynamic_pointer_cast<IIRBase_AssociationElement>(first());

  if (node.get() != NULL) {
    node->publish_vhdl_without_formals(vhdl_out);
    for (node = my_dynamic_pointer_cast<IIRBase_AssociationElement>(successor(node)); 
         node != NULL; node = my_dynamic_pointer_cast<IIRBase_AssociationElement>(successor(node))) {
      vhdl_out << ", ";
      node->publish_vhdl_without_formals(vhdl_out);
    }
  }
}
