
// Copyright (c) 2003 The University of Cincinnati.
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

// Author: Harish Venkataramani venkath@ececs.uc.edu

//---------------------------------------------------------------------------

#include "IIRBase_BreakList.hh"
#include "IIRBase_BreakElement.hh"
  
IIRBase_BreakList::IIRBase_BreakList() {}

IIRBase_BreakList::~IIRBase_BreakList() {}

void
IIRBase_BreakList::append(IIR_BreakElementRef to_append) {
  append( to_append );
}

IIR_BreakElementRef
IIRBase_BreakList::successor(IIR_BreakElementRef succeed_me) {
  return my_dynamic_pointer_cast<IIR_BreakElement>(successor(succeed_me));
}
  
IIR_BreakElementRef
IIRBase_BreakList::first() {
  return my_dynamic_pointer_cast<IIR_BreakElement>(first());
}

void
IIRBase_BreakList::publish_vhdl(ostream &vhdl_out) {
  IIRBase_BreakElementRef placeholder = my_dynamic_pointer_cast<IIRBase_BreakElement>(first());
  for( IIRBase_BreakElementRef temp = my_dynamic_pointer_cast<IIRBase_BreakElement>(first());
        temp != nullptr;
        temp = my_dynamic_pointer_cast<IIRBase_BreakElement>(successor(temp))) {
     if(temp != placeholder)
        vhdl_out << " , ";
     temp->publish_vhdl(vhdl_out);
  }
}
