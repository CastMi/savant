
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

#include "IIRBase_ModulusOperator.hh"

IIRBase_ModulusOperator::IIRBase_ModulusOperator() {}
IIRBase_ModulusOperator::~IIRBase_ModulusOperator() {}

const string &
IIRBase_ModulusOperator::get_operator_string() const {
  static const string retval( "mod" );
  return retval;
}

IIRBase_Operator::Precedence
IIRBase_ModulusOperator::get_precedence(){
  return MULTIPLYING_OPERATOR;
}

bool
IIRBase_ModulusOperator::is_associative(IIR_Kind oper_kind){
  switch (oper_kind){
  case IIR_MULTIPLICATION_OPERATOR:
  case IIR_DIVISION_OPERATOR:
  case IIR_REMAINDER_OPERATOR:
  case IIR_MODULUS_OPERATOR:
    return FALSE;
  default:
    return TRUE;
  }
}
