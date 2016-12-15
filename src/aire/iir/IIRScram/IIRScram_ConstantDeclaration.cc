
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
//          Timothy J. McBrayer 
//          Malolan Chetlur     
//          Krishnan Subramani  
//          Umesh Kumar V. Rajasekaran
//          Radharamanan Radhakrishnan
//          Narayanan Thondugulam 
//          Swaminathan Subramanian
//	    Magnus Danielson	cfmd@swipnet.se

//---------------------------------------------------------------------------

#include "IIRScram_ConstantDeclaration.hh"
#include "IIRScram_ScalarTypeDefinition.hh"
#include "IIRScram_Statement.hh"

IIRScram_ConstantDeclaration::~IIRScram_ConstantDeclaration() {}

IIRScram*
IIRScram_ConstantDeclaration::_clone() {
  return this;
}

IIRScram_Statement*
IIRScram_ConstantDeclaration::_get_value() {
  return dynamic_cast<IIRScram_Statement *>(get_value());
}

IIR_Boolean 
IIRScram_ConstantDeclaration::is_locally_static_primary(){
  IIR_Boolean retval = true;

  ASSERT( _get_subtype() != NULL );
  if( _get_subtype()->is_access_type() == true ){
    retval = false;
  }

  return retval;
}
