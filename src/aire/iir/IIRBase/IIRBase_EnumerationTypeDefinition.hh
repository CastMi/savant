
#ifndef IIRBASE_ENUMERATION_TYPE_DEFINITION_HH
#define IIRBASE_ENUMERATION_TYPE_DEFINITION_HH

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
//          Timothy J. McBrayer tmcbraye@ece.uc.edu

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIRBase_ScalarTypeDefinition.hh"
#include "IIR_EnumerationTypeDefinition.hh"

class IIRBase_EnumerationTypeDefinition : public virtual IIRBase_ScalarTypeDefinition,
					  public virtual IIR_EnumerationTypeDefinition{

public:
  // List Accessor(s)
  IIR_EnumerationLiteralListRef get_enumeration_literals();
  void set_enumeration_literals(IIR_EnumerationLiteralListRef new_enumeration_literals);

  IIR_Kind get_kind() const override { return IIR_ENUMERATION_TYPE_DEFINITION; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_EnumerationTypeDefinition"); }
  IIR_FunctionDeclarationRef get_resolution_function() { return NULL; }

  IIRRef convert_tree(plugin_class_factoryRef factory);
  IIR_Boolean is_enumeration_type(){ return true; }

  savant::set<IIR_DeclarationRef> find_declarations( IIR_TextLiteralRef  );
  savant::set<IIR_DeclarationRef> find_declarations( IIR_NameRef   );

  IIR_Boolean is_character_type();
  IIR_Boolean is_discrete_type(){ return true;  }
  
  ostream& print(ostream&);
  void publish_vhdl_type_decl(ostream &);
protected:
  IIRBase_EnumerationTypeDefinition();
  virtual ~IIRBase_EnumerationTypeDefinition() = 0;
    
private:
  // List Variable(s)
  IIR_EnumerationLiteralListRef enumeration_literals;

};

typedef refcount<IIRBase_EnumerationTypeDefinition> IIRBase_EnumerationTypeDefinitionRef;

#endif
