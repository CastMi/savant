
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
//---------------------------------------------------------------------------

#include "savant.hh"
#include "IIRBase_CommentList.hh"
#include "IIRBase_Comment.hh"

IIRBase_CommentList::IIRBase_CommentList() {}
IIRBase_CommentList::~IIRBase_CommentList() {}

void
IIRBase_CommentList::append_element(IIR_Comment* to_append) {
  ASSERT( to_append->get_kind() == IIR_COMMENT );
  IIRBase_List<IIR_Comment>::append( to_append );
}

IIR_CommentList*
IIRBase_CommentList::convert_node(plugin_class_factory *) {
   return nullptr;
}

void 
IIRBase_CommentList::publish_vhdl(ostream &vhdl_out) {
  IIRBase_Comment *comment = dynamic_cast<IIRBase_Comment *>(first());
  while( comment != NULL ){
    comment->publish_vhdl(vhdl_out);
    vhdl_out << "\n";
    comment = dynamic_cast<IIRBase_Comment *>(successor(comment));
  }
}
