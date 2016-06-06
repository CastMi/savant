
// Copyright (c) The University of Cincinnati.  
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

#include "error_func.hh"
#include "IIR_Name.hh"
#include "IIRBase_String.hh"
#include "IIRBase_TextLiteral.hh"

#include <sstream>

IIRBase_TextLiteral::IIRBase_TextLiteral() :
  text(0),
  our_string_table() {}

IIRBase_TextLiteral::~IIRBase_TextLiteral(){}

IIR_Char *
IIRBase_TextLiteral::get_text() const {
  return const_cast<char *>(text->get_text().c_str());
}

IIR_Int32 
IIRBase_TextLiteral::get_text_length() const {
  return text->get_text_length();
}

IIR_Char &
IIRBase_TextLiteral::operator[]( IIR_Int32 subscript ){
  check_bounds( subscript );
  return text->operator[]( subscript );
}

void 
IIRBase_TextLiteral::check_bounds( IIR_Int32 subscript ){
  if( subscript < 0 || subscript > (get_text_length() - 1) ){
    ostringstream err;
    err << "Error! IIRBase_TextLiteralLiteral array subscript out of bounds!";
    report_error( this, err.str() );
    abort();
  }  
}

const string
IIRBase_TextLiteral::convert_to_string(){
  return text->convert_to_string();
}

const string
IIRBase_TextLiteral::convert_to_library_name(){
  return convert_to_string();
}

IIR_Statement *
IIRBase_TextLiteral::convert_tree(plugin_class_factory *factory) {
  // Get the node itself
  IIRBase_TextLiteral *new_node = dynamic_cast<IIRBase_TextLiteral *>(IIRBase_Literal::convert_tree(factory));

  // Process the variables
  new_node->set_text(text->get_text().c_str(), text->get_text_length());

  return new_node;
}

int
IIRBase_TextLiteral::cmp(IIR_TextLiteral *a, IIR_TextLiteral *b) {
   ASSERT( a && b );
   return strcmp(a->get_text(), b->get_text());
}

int
IIRBase_TextLiteral::cmp( IIR_TextLiteral *a, const char *b ) {
   ASSERT( a && b );
   return strcmp(a->get_text(), b);
}

int
IIRBase_TextLiteral::cmp(IIR_TextLiteral *a, IIR_Name *b){
  int retval;

  if ( b->get_kind() != IIR_SIMPLE_NAME ){
    retval = -1;
  }
  else if ( b->get_prefix()->is_text_literal() == false ){
    retval = -1;
  }
  else {
    retval = IIRBase_TextLiteral::cmp( a, dynamic_cast<IIR_TextLiteral *>(b->get_prefix()) );
  }

  return retval;
}

void
IIRBase_TextLiteral::set_text( const IIR_Char *const new_text, const IIR_Int32 new_length ){
  ASSERT( new_length > 0 );
  ASSERT( new_text );

  text = our_string_table.hash_look( new_text, new_length );
}

ostream &
IIRBase_TextLiteral::print( ostream &os ){
  os.write( get_text(), get_text_length() );

  return os;
}

void 
IIRBase_TextLiteral::publish_vhdl(ostream &vhdl_out) {
  print( vhdl_out );
}
