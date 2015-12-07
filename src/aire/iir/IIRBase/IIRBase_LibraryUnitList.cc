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

#include "IIRBase_LibraryUnitList.hh"
#include "IIRBase_LibraryUnit.hh"
#include "library_manager.hh"

IIRBase_LibraryUnitList::IIRBase_LibraryUnitList() {}
IIRBase_LibraryUnitList::~IIRBase_LibraryUnitList() {}

void
IIRBase_LibraryUnitList::append( IIR_LibraryUnitRef to_append ){
  IIRBase_DeclarationList::append( to_append );
}

IIRRef 
IIRBase_LibraryUnitList::first() {
  return IIRBase_DeclarationList::first();
}

IIRRef
IIRBase_LibraryUnitList::last() {
  return IIRBase_DeclarationList::last();
}


IIRRef
IIRBase_LibraryUnitList::successor( IIR_LibraryUnitRef node ){
  return IIRBase_DeclarationList::successor(node);
}


void 
IIRBase_LibraryUnitList::publish_vhdl_in_design_library(){
  IIRBase_LibraryUnitRef lib_unit = my_dynamic_pointer_cast<IIRBase_LibraryUnit>(first());
  while (lib_unit != nullptr) {
    ostream *file_handle = library_manager::instance()->get_file_handle( lib_unit.get() );
    ASSERT( file_handle != 0 );
    lib_unit->publish_vhdl_decl( *file_handle );
    file_handle->flush();
    delete file_handle;

    lib_unit = my_dynamic_pointer_cast<IIRBase_LibraryUnit>(successor(lib_unit));
  }
}

void 
IIRBase_LibraryUnitList::publish_vhdl(ostream &vhdl_out) {
  IIRBase_LibraryUnitRef lib_unit = my_dynamic_pointer_cast<IIRBase_LibraryUnit>(first());

  while (lib_unit != nullptr) {
    lib_unit->publish_vhdl_decl(vhdl_out);
    lib_unit = my_dynamic_pointer_cast<IIRBase_LibraryUnit>(successor(lib_unit));
  }
}
