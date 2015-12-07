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
//          Narayanan Thondugulam 

//---------------------------------------------------------------------------

#include "IIRBase_Comment.hh"
#include "error_func.hh"
#include <sstream>
using std::ostringstream;

IIRBase_Comment::IIRBase_Comment(){
}

IIRBase_Comment::~IIRBase_Comment(){
}

std::string
IIRBase_Comment::get_text(){
  return std::string(text.get());
}

IIR_Int32 
IIRBase_Comment::get_text_length(){
  return text_length;
}

void 
IIRBase_Comment::set_element( IIR_Int32 subscript, IIR_Char value ){
  _check_bounds( subscript );
  text.get()[ subscript ] = value;
}

void 
IIRBase_Comment::_check_bounds( IIR_Int32 subscript ){
  if( subscript < 0 || subscript > text_length ){
    ostringstream err;
    err << "Error! IIRBase_Comment array subscript out of bounds!";
    report_error( this, err.str() );
    abort();
  }  
}

void
IIRBase_Comment::set_text( IIR_CharRef txt, IIR_Int32 text_len ){
  text = txt;
  text_length = text_len;
}

IIRRef
IIRBase_Comment::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_CommentRef new_node = my_dynamic_pointer_cast<IIRBase_Comment>(IIRBase_Literal::convert_tree(factory));

  // Process the variables
  new_node->text = text;
  new_node->text_length = text_length;

  return new_node;
}

void 
IIRBase_Comment::publish_vhdl(ostream &vhdl_out) {
    vhdl_out << this->get_text();
}
