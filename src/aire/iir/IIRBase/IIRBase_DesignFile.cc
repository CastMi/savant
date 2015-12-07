
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

#include "IIRBase_DesignFile.hh"
#include "IIR_CommentList.hh"
#include "IIR_Identifier.hh"
#include "IIR_LibraryUnitList.hh"

#include "StandardPackage.hh"
#include "scram.hh"

// Header for convert_tree
IIRBase_DesignFile::IIRBase_DesignFile() {
  // FIXME: this is an error
  _my_design_file = IIRBase_DesignFileRef();
}

IIRBase_DesignFile::~IIRBase_DesignFile() {}

// IIR_DesignFileList *
// IIRBase_DesignFile::get_design_files(){
//   static IIR_DesignFileList design_files;
//   return design_files;
// }

IIR_IdentifierRef
IIRBase_DesignFile::get_name(){
  return my_file_name;
}

void 
IIRBase_DesignFile::set_name( IIR_IdentifierRef new_file_name ){
  my_file_name = new_file_name;
}

// List Accessor(s)
IIR_CommentListRef
IIRBase_DesignFile::get_comments() {
  ASSERT(comments != nullptr);
  return comments;
}

IIR_LibraryUnitListRef
IIRBase_DesignFile::get_library_units() {
  ASSERT(library_units != nullptr);
  return library_units;
}

void
IIRBase_DesignFile::set_comments(IIR_CommentListRef new_comments) {
  ASSERT(new_comments != nullptr);
  comments = new_comments;
}

void
IIRBase_DesignFile::set_library_units(IIR_LibraryUnitListRef new_library_units) {
  ASSERT(new_library_units != nullptr);
  library_units = new_library_units;
}

IIRRef
IIRBase_DesignFile::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_DesignFileRef new_node = my_dynamic_pointer_cast<IIRBase_DesignFile>(IIRBase::convert_tree(factory));

  // Process the variables
  new_node->comments =
    my_dynamic_pointer_cast<IIR_CommentList>(convert_node(comments, factory));
  new_node->library_units =
    my_dynamic_pointer_cast<IIR_LibraryUnitList>(convert_node(library_units, factory));
  new_node->my_file_name =
    my_dynamic_pointer_cast<IIR_Identifier>(convert_node(my_file_name, factory));
  new_node->my_std_package =
    my_dynamic_pointer_cast<StandardPackage>(convert_node(my_std_package, factory));

  if (my_parser != nullptr)
    new_node->my_parser = my_parser->convert_node(factory);
  else
    new_node->my_parser = my_parser;

  new_node->my_factory = factory;

  return new_node;
}

StandardPackageRef
IIRBase_DesignFile::get_standard_package() {
  return my_std_package;
}

void                          
IIRBase_DesignFile::set_standard_package(StandardPackageRef pkg) {
  ASSERT(pkg != nullptr);
  my_std_package = pkg;
}

plugin_class_factoryRef
IIRBase_DesignFile::get_class_factory() {
  return my_factory;
}

void 
IIRBase_DesignFile::set_class_factory(plugin_class_factoryRef factory) {
  ASSERT(factory != nullptr);
  my_factory = factory;
}

void 
IIRBase_DesignFile::set_parser( scramRef new_parser ){
  ASSERT( my_parser == nullptr || my_parser == new_parser );
  my_parser = new_parser;
  my_factory = new_parser->get_class_factory();
}

IIR_LibraryDeclarationRef
IIRBase_DesignFile::get_work_library(){
  ASSERT( my_parser != 0 );
  return my_parser->get_work_library();
}

void 
IIRBase_DesignFile::publish_vhdl(ostream &vhdl_out) {
  get_comments()->publish_vhdl(vhdl_out);
  get_library_units()->publish_vhdl(vhdl_out);
}
