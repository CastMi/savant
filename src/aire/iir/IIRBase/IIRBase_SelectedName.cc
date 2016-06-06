
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



#include "IIRBase_SelectedName.hh"
#include "IIRBase_Declaration.hh"
#include "IIR_AccessTypeDefinition.hh"
#include "IIR_TypeDefinition.hh"

#include "savant.hh"

IIRBase_SelectedName::IIRBase_SelectedName(){
  set_suffix( NULL );
}

IIRBase_SelectedName::~IIRBase_SelectedName() {}

void 
IIRBase_SelectedName::set_suffix( IIR_Statement *suffix ){
  this->suffix = suffix;
}

IIR_Statement *
IIRBase_SelectedName::get_suffix() const {
  return suffix;
}

IIR_Statement *
IIRBase_SelectedName::convert_tree(plugin_class_factory *factory) {
  // Get the node itself
  IIRBase_SelectedName *new_node = dynamic_cast<IIRBase_SelectedName *>(IIRBase_Name::convert_tree(factory));

  // Process the variables
  new_node->suffix = suffix->convert_tree(factory);

  return new_node;
}

IIR_Boolean
IIRBase_SelectedName::is_resolved() const {
  if( get_prefix()->is_resolved() == TRUE && get_suffix()->is_resolved() ){
    return TRUE;
  }
  else{
    return FALSE;
  }
}

IIR_Boolean
IIRBase_SelectedName::is_signal() const {
  ASSERT( is_resolved() == TRUE );
  if( get_prefix()->is_signal() == TRUE || get_suffix()->is_signal() == TRUE ){
    return TRUE;
  }
  else{
    return FALSE;
  }
}

IIR_Boolean
IIRBase_SelectedName::is_entity_declaration() const {
  ASSERT ( is_resolved() == TRUE );
  
  if ((get_suffix()->is_entity_declaration() == TRUE) ||
      (get_prefix()->is_entity_declaration() == TRUE)) {
    return TRUE;
  }
  
  return FALSE;
}

IIR_TypeDefinition *
IIRBase_SelectedName::get_subtype(){
  ASSERT( is_resolved() == TRUE );
  
  if (get_suffix()->get_kind() != IIR_DESIGNATOR_BY_ALL) {
    return get_suffix()->get_subtype();
  } else {
    IIR_AccessTypeDefinition *type = dynamic_cast<IIR_AccessTypeDefinition *>(get_prefix()->get_subtype());
    if (type != NULL) {
      return type->get_designated_type();
    } else {
      return NULL;
    }
  }
}

IIR_Boolean
IIRBase_SelectedName::is_object() const {
  ASSERT( is_resolved() == TRUE );
  if( get_prefix()->is_object() == TRUE || 
      get_suffix()->is_object() == TRUE ){
    return TRUE;
  }
  else{
    return FALSE;
  }
}

IIR_SignalKind
IIRBase_SelectedName::get_signal_kind() const {
  if( get_suffix()->is_signal() == TRUE ){
    return get_suffix()->get_signal_kind();
  }
  else if( get_prefix()->is_signal() == TRUE ){
    return get_suffix()->get_signal_kind();
  }
  else{
    return IIR_SignalKind::IIR_NO_SIGNAL_KIND;
  }
}

IIR_Boolean
IIRBase_SelectedName::is_type() const {
  ASSERT( is_resolved() == TRUE );
  return get_suffix()->is_type();
}

IIR_Boolean
IIRBase_SelectedName::is_variable() const {
  ASSERT( is_resolved() == TRUE );
  if( get_prefix()->is_variable() == TRUE || get_suffix()->is_variable() == TRUE ){
    return TRUE;
  }
  else{
    return FALSE;
  }
}

ostream &
IIRBase_SelectedName::print( ostream &os ){
  // FIXME overload operator<<
  //os << *get_prefix();
  os << ".";
  // FIXME overload operator<<
  // os << *get_suffix();
  
  return os;
}

IIR_Declaration*
IIRBase_SelectedName::get_prefix_declaration() {
  // Since we mangle names, we need not have a selected name.  We just
  // need the object declaration, so return the suffix.
  if(get_prefix()->is_label() == TRUE) {
    ASSERT(dynamic_cast<IIRBase_Declaration *>(get_prefix()) != NULL);
    return dynamic_cast<IIR_Declaration *>(get_prefix());
  } 
  else {
    return get_prefix()->get_prefix_declaration();
  }
}

void 
IIRBase_SelectedName::publish_vhdl(ostream &vhdl_out) {
  ASSERT(is_resolved() == TRUE);
  get_prefix()->publish_vhdl(vhdl_out);
  vhdl_out << ".";
  get_suffix()->publish_vhdl(vhdl_out);
}
