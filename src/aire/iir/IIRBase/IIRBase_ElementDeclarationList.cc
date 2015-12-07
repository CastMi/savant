
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

#include "IIRBase_ElementDeclarationList.hh"
#include "IIR_ElementDeclaration.hh"

IIRBase_ElementDeclarationList::IIRBase_ElementDeclarationList(){}
IIRBase_ElementDeclarationList::~IIRBase_ElementDeclarationList(){}


void 
IIRBase_ElementDeclarationList::append( IIR_ElementDeclarationRef to_append ){
  IIRBase_List::append( to_append );
}

IIRRef
IIRBase_ElementDeclarationList::successor( IIR_ElementDeclarationRef succeed_me ){
  return IIRBase_List::successor( succeed_me );
}

IIRRef
IIRBase_ElementDeclarationList::first(){
  return IIRBase_List::first();
}


IIRRef
IIRBase_ElementDeclarationList::get_nth_element( int element ){
  return IIRBase_List::get_nth_element( element );
}

void 
IIRBase_ElementDeclarationList::publish_vhdl(ostream &vhdl_out) {
  publish_vhdl_decl( vhdl_out );
}
