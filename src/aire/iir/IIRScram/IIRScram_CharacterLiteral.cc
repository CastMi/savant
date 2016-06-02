// Copyright (c) 1996-2000 The University of Cincinnati.  
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
//          Krishnan Subramani  skrish@ece.uc.edu
//          Narayanan Thondugulam nthondug@ece.uc.edu

//---------------------------------------------------------------------------

#include "savant.hh"
#include "IIRScram_CharacterLiteral.hh"
#include <sstream>
#include <climits>
using std::ostringstream;

IIRScram_CharacterLiteral::~IIRScram_CharacterLiteral() {}

IIRScram_CharacterLiteral *
IIRScram_CharacterLiteral::_get_from_character( char my_char ){
  ostringstream os;
  os << "'" << my_char << "'";
  return dynamic_cast<IIRScram_CharacterLiteral *>(get( os.str() ));
}

IIRScram_CharacterLiteral *
IIRScram_CharacterLiteral::get( const string new_text ){
  IIRScram_CharacterLiteral *retval = new IIRScram_CharacterLiteral();
  retval->set_text( new_text.c_str(), new_text.length() );

  return retval;
}

IIRScram_CharacterLiteral *
IIRScram_CharacterLiteral::get( const IIR_Char *new_text, IIR_Int32 new_length ){
  ASSERT( strlen(new_text) < INT_MAX );
  ASSERT( new_length == static_cast<IIR_Int32>(strlen(new_text)) );
  IIRScram_CharacterLiteral *retval = new IIRScram_CharacterLiteral();
  retval->set_text( new_text, new_length );

  return retval;
}
