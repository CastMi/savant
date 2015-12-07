
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

#include "IIRBase_EnumerationTypeDefinition.hh"
#include "IIRBase_EnumerationLiteralList.hh"

IIRBase_EnumerationTypeDefinition::IIRBase_EnumerationTypeDefinition() {}
IIRBase_EnumerationTypeDefinition::~IIRBase_EnumerationTypeDefinition() {}

// List Accessor(s)
IIR_EnumerationLiteralListRef
IIRBase_EnumerationTypeDefinition::get_enumeration_literals() {
  if( is_subtype() ){
    ASSERT(get_base_type() != 0);
    ASSERT(enumeration_literals == nullptr);
    ASSERT( my_dynamic_pointer_cast<IIR_EnumerationTypeDefinition>(get_base_type()) != nullptr );
    return my_dynamic_pointer_cast<IIR_EnumerationTypeDefinition>(get_base_type())->get_enumeration_literals();
  }
  else{
    ASSERT(enumeration_literals != nullptr);
    return enumeration_literals;
  }
}


void
IIRBase_EnumerationTypeDefinition::set_enumeration_literals(IIR_EnumerationLiteralListRef new_enumeration_literals) {
  ASSERT(new_enumeration_literals != nullptr);
  enumeration_literals = new_enumeration_literals;
}

IIRRef
IIRBase_EnumerationTypeDefinition::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_EnumerationTypeDefinitionRef new_node =
    my_dynamic_pointer_cast<IIRBase_EnumerationTypeDefinition>(IIRBase_ScalarTypeDefinition::convert_tree(factory));

  // Process the variables
  if( !is_subtype() ){
    ASSERT( !new_node->is_subtype() );
    ASSERT( new_node->enumeration_literals == nullptr );
    ASSERT( enumeration_literals != nullptr );
    new_node->enumeration_literals =
      my_dynamic_pointer_cast<IIR_EnumerationLiteralList>(convert_node(enumeration_literals, factory));
    ASSERT( new_node->enumeration_literals != nullptr );
    ASSERT( new_node->enumeration_literals->num_elements() == enumeration_literals->num_elements() );
  }

  return new_node;
}

savant::set<IIR_DeclarationRef>
IIRBase_EnumerationTypeDefinition::find_declarations( IIR_TextLiteralRef to_find ){
  // This is a little ugly, but we need to get the type's enum list, and not the subtype
  return my_dynamic_pointer_cast<IIR_EnumerationLiteralList>((IIRBase_EnumerationTypeDefinition::get_enumeration_literals()))->find_declarations( to_find );
}

savant::set<IIR_DeclarationRef>
IIRBase_EnumerationTypeDefinition::find_declarations( IIR_NameRef to_find ){
  // This is a little ugly, but we need to get the type's enum list, and not the subtype
  return my_dynamic_pointer_cast<IIR_EnumerationLiteralList>((IIRBase_EnumerationTypeDefinition::get_enumeration_literals()))->find_declarations( to_find );
}

// LRM defnies an enumeration type as a character type thus (Section 3.1.1):
//   An enumeration type is said to be a character type if at least one of
//   its enumeration literals is a character literal.
IIR_Boolean
IIRBase_EnumerationTypeDefinition::is_character_type() {
  IIR_Boolean retval = FALSE;

  if( get_base_type() != nullptr ){
    retval = get_base_type()->is_character_type();
  }
  else{

    IIR_EnumerationLiteralRef literal = my_dynamic_pointer_cast<IIR_EnumerationLiteral>(get_enumeration_literals()->first());
    while( literal != nullptr ) {
      if(literal->is_character_literal() == TRUE) {
	retval = TRUE;
	break;
      }
      literal = my_dynamic_pointer_cast<IIR_EnumerationLiteral>(get_enumeration_literals()->successor(literal));
    }
  }

  return retval;
}

ostream&
IIRBase_EnumerationTypeDefinition::print(ostream& os) {
  if( get_enumeration_literals()->num_elements() > 0 ){
    get_enumeration_literals()->print(os);
  }
  else{
    IIRBase_ScalarTypeDefinition::print( os );
  }
  return os;
}

void 
IIRBase_EnumerationTypeDefinition::publish_vhdl_type_decl(ostream &vhdl_out) {
  // This is a little ugly, but we need to get the type's enum list, and not the subtype
   my_dynamic_pointer_cast<IIRBase_EnumerationLiteralList>((get_enumeration_literals()))->publish_vhdl(vhdl_out);
}
