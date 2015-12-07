
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

#include "savant.hh"
#include "IIRBase_DesignatorList.hh"
#include "IIRBase_Designator.hh"
#include "IIR_DesignatorExplicit.hh"

IIRBase_DesignatorList::IIRBase_DesignatorList() {}
IIRBase_DesignatorList::~IIRBase_DesignatorList() {}


IIRRef
IIRBase_DesignatorList::first(){
  IIRRef retval = IIRBase_List::first();
  return retval;
}


IIRRef
IIRBase_DesignatorList::successor(IIR_DesignatorRef to_succeed){
  IIRRef test = to_succeed;
  ASSERT( test != nullptr );

  IIRRef retval;
  retval = IIRBase_List::successor(to_succeed);

  return retval;
}

void 
IIRBase_DesignatorList::append( IIR_DesignatorRef to_append ){
  IIRRef test = to_append;
  ASSERT( test != nullptr );

  IIRBase_List::append( to_append );
}

IIR_Boolean
IIRBase_DesignatorList::is_above_attribute_found() {
  IIR_Boolean retval = FALSE;
  IIR_DesignatorRef element = my_dynamic_pointer_cast<IIR_Designator>(first());
  IIRRef current_name = NULL;
  while(element != NULL) {
    if(element->get_kind() == IIR_DESIGNATOR_EXPLICIT) {
      current_name =  (my_dynamic_pointer_cast<IIR_DesignatorExplicit>(element))->get_name();
      retval = retval || current_name->is_above_attribute_found();
    }
    else {
      retval = retval || element->is_above_attribute_found();
    }
    element = my_dynamic_pointer_cast<IIR_Designator>(successor(element));
  }
  return retval;
}


void 
IIRBase_DesignatorList::publish_vhdl(ostream &vhdl_out) {
  IIRBase_DesignatorRef list_element;

  list_element = my_dynamic_pointer_cast<IIRBase_Designator>(first());

  ASSERT ( list_element != nullptr );
  
  list_element->publish_vhdl(vhdl_out);

  list_element = my_dynamic_pointer_cast<IIRBase_Designator>(successor(list_element));
  while (list_element != nullptr) {
    vhdl_out << ", ";
    list_element->publish_vhdl(vhdl_out);
    list_element = my_dynamic_pointer_cast<IIRBase_Designator>(successor(list_element));
  }
}
