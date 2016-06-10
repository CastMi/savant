
// Copyright (c) 1996-2008 The University of Cincinnati.  
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

#include "IIRBase_CaseStatementAlternativeList.hh"
#include "IIR_CaseStatementAlternative.hh"

IIRBase_CaseStatementAlternativeList::IIRBase_CaseStatementAlternativeList() {}
IIRBase_CaseStatementAlternativeList::~IIRBase_CaseStatementAlternativeList() {}

IIR_CaseStatementAlternativeList*
IIRBase_CaseStatementAlternativeList::convert_node(plugin_class_factory*) {
   return nullptr;
}

IIR_Boolean
IIRBase_CaseStatementAlternativeList::is_above_attribute_found() {
  IIR_Boolean retval = false;

  IIR_CaseStatementAlternative *stmt = first();
  while (stmt != NULL) {
    retval = stmt->is_above_attribute_found() || retval;
    stmt = successor(stmt);
  }
  return retval;
}

IIR_Boolean
IIRBase_CaseStatementAlternativeList::is_resolved() {
  IIR_Boolean retval = true;

  IIR_CaseStatementAlternative* current_element = first();
  while( current_element != NULL ){
    if( current_element->is_resolved() == false ){
      retval = false;
      break;
    }
    current_element = successor( current_element );
  }

  return retval;
}
