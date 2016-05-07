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

//---------------------------------------------------------------------------

#include "IIRBase_IntegerSubtypeDefinition.hh"
#include "IIR_IntegerSubtypeDefinition.hh"
#include "IIR_FunctionDeclaration.hh"
#include "savant.hh"

IIRBase_IntegerSubtypeDefinition::IIRBase_IntegerSubtypeDefinition() {
  my_resolution_function = NULL;
}

IIRBase_IntegerSubtypeDefinition::~IIRBase_IntegerSubtypeDefinition() {}

void 
IIRBase_IntegerSubtypeDefinition::set_resolution_function( IIR_FunctionDeclaration *resolution_function ){
  my_resolution_function = resolution_function;
}


IIR_FunctionDeclaration *
IIRBase_IntegerSubtypeDefinition::get_resolution_function(){
  return my_resolution_function;
}

IIR *
IIRBase_IntegerSubtypeDefinition::convert_tree(plugin_class_factory *factory) {
  // Get the node itself
  IIRBase_IntegerSubtypeDefinition *new_node = dynamic_cast<IIRBase_IntegerSubtypeDefinition *>(IIRBase_IntegerTypeDefinition::convert_tree(factory));

  // Process the variables
  new_node->my_resolution_function = dynamic_cast<IIR_FunctionDeclaration *>(my_resolution_function->convert_tree(factory));

  return new_node;
}

IIR_Boolean
IIRBase_IntegerSubtypeDefinition::is_subtype() {
  return TRUE;
}
