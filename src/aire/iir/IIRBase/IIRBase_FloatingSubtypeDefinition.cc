
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

#include "IIRBase_FloatingSubtypeDefinition.hh"
#include "savant.hh"
#include "IIR_FloatingSubtypeDefinition.hh"
#include "IIR_FunctionDeclaration.hh"

IIRBase_FloatingSubtypeDefinition::IIRBase_FloatingSubtypeDefinition() {}
IIRBase_FloatingSubtypeDefinition::~IIRBase_FloatingSubtypeDefinition(){}

void 
IIRBase_FloatingSubtypeDefinition::set_resolution_function( IIR_FunctionDeclarationRef resolution_function ){
  my_resolution_function = resolution_function;
}


IIR_FunctionDeclarationRef
IIRBase_FloatingSubtypeDefinition::get_resolution_function(){
  return my_resolution_function;
}

IIRRef
IIRBase_FloatingSubtypeDefinition::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_FloatingSubtypeDefinitionRef new_node = my_dynamic_pointer_cast<IIRBase_FloatingSubtypeDefinition>(IIRBase_FloatingTypeDefinition::convert_tree(factory));

  // Process the variables
  new_node->my_resolution_function = my_dynamic_pointer_cast<IIR_FunctionDeclaration>(convert_node(my_resolution_function, factory));

  return new_node;
}

IIR_Boolean
IIRBase_FloatingSubtypeDefinition::is_subtype() {
  return TRUE;
}
