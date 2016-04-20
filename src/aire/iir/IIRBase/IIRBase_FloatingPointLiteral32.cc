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
//          Malolan Chetlur     mal@ece.uc.edu
//          Timothy J. McBrayer tmcbraye@ece.uc.edu

//---------------------------------------------------------------------------

#include "IIRBase_FloatingPointLiteral32.hh"
#include "IIR_FloatingPointLiteral32.hh"

IIRBase_FloatingPointLiteral32::IIRBase_FloatingPointLiteral32() {}
IIRBase_FloatingPointLiteral32::~IIRBase_FloatingPointLiteral32() {}

IIR_FP32
IIRBase_FloatingPointLiteral32::value() {
  return val;
}


void
IIRBase_FloatingPointLiteral32::set_value(IIR_FP32 v) {
  val = v;
}

IIR *
IIRBase_FloatingPointLiteral32::convert_tree(plugin_class_factory *factory) {
  // Get the node itself
  IIRBase_FloatingPointLiteral32 *new_node = dynamic_cast<IIRBase_FloatingPointLiteral32 *>(IIRBase_Literal::convert_tree(factory));

  // Process the variables
  new_node->val = val;

  return new_node;
}

void 
IIRBase_FloatingPointLiteral32::publish_vhdl(ostream &vhdl_out) {
  vhdl_out << value();
}
