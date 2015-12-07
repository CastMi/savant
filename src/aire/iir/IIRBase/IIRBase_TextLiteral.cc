
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
#include <utility>
#include <cstring>

IIRBase_TextLiteral::IIRBase_TextLiteral() {}
IIRBase_TextLiteral::~IIRBase_TextLiteral() {}

std::string
IIRBase_TextLiteral::get_text(){
  return text->get_text();
}

IIR_Int32 
IIRBase_TextLiteral::get_text_length(){
  return text->get_text_length();
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

IIRRef
IIRBase_TextLiteral::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_TextLiteralRef new_node = my_dynamic_pointer_cast<IIRBase_TextLiteral>(IIRBase_Literal::convert_tree(factory));

  // Process the variables
  new_node->set_text(text->get_text());

  return new_node;
}

int 
IIRBase_TextLiteral::cmp(IIR_TextLiteralRef a, IIR_TextLiteralRef b) {
  if( a == b ){
    return 0;
  }
  int size_a, size_b;

  ASSERT( a != 0 );
  ASSERT( b != 0 );

  size_a = a->get_text_length();
  size_b = b->get_text_length();

  if ( size_a != size_b ){
    if ( size_a < size_b ){
      return -1;
    }
    else{
      return 1;
    }
  }

  std::string text_a = a->get_text();
  std::string text_b = b->get_text();
  
  return memcmp( text_a.c_str(), text_b.c_str(), size_a );
}

int 
IIRBase_TextLiteral::cmp( IIR_TextLiteralRef a, const IIR_Char *b ) {
  int size_a, size_b;
  size_a = a->get_text_length();
  size_b = strlen(b);

  if( size_a > size_b ){
    return 1;
  }
  if (size_b > size_a) {
    return -1;
  }

  const char *text_a = a->get_text().c_str();

  int i;
  for( i = 0; i < size_a; i++ ){
    if( text_a[i] != b[i] ){
      return text_a[i] - b[i];
    }
  }
  return 0;
}

int 
IIRBase_TextLiteral::cmp(IIR_TextLiteralRef a, IIR_NameRef b){
  int retval;

  if ( b->get_kind() != IIR_SIMPLE_NAME ){
    retval = -1;
  }
  else if ( b->get_prefix()->is_text_literal() == false ){
    retval = -1;
  }
  else {
    retval = IIRBase_TextLiteral::cmp( a, my_dynamic_pointer_cast<IIR_TextLiteral>(b->get_prefix()) );
  }

  return retval;
}

void 
IIRBase_TextLiteral::set_text( std::string new_text ){
  ASSERT( new_text.size() > 0 );

  if(mymap.find(new_text) == mymap.end()) {
      IIRBase_StringRef elem(new IIRBase_String());
      elem->set_key( new_text, new_text.size() );
      // FIXME: change the signature of set_text removing the const from the IIR_Char *
      // using string?!?
      mymap.insert( std::pair<std::string, IIRBase_StringRef>(new_text, elem) );
  }
  text = mymap.find(new_text)->second;
}

ostream &
IIRBase_TextLiteral::print( ostream &os ){
  os.write( get_text().c_str(), get_text_length() );

  return os;
}

void 
IIRBase_TextLiteral::publish_vhdl(ostream &vhdl_out) {
  print( vhdl_out );
}
