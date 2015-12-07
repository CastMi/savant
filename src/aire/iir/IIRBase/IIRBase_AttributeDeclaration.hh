
#ifndef IIRBASE_ATTRIBUTE_DECLARATION_HH
#define IIRBASE_ATTRIBUTE_DECLARATION_HH

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

#include "savant_config.hh"
#include "IIRBase_Declaration.hh"
#include "IIR_AttributeDeclaration.hh"

class IIR_TypeDefinition;

class IIRBase_AttributeDeclaration : public virtual IIRBase_Declaration,
				     public virtual IIR_AttributeDeclaration{

public:
  IIR_Kind get_kind() const override {return IIR_ATTRIBUTE_DECLARATION;}
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_AttributeDeclaration"); }

  /** An attribute declaration can refer to more than one instance of an
   attribute.  These methods refer to the FIRST instance of an attribute
   that caused this declaration to be created (if scram created it -
   user defined get_attributes() are a different matter) These methods are so
   the parser gan easily determine things like if this is a signal
   valued attribute and so forth. */
  IIR_AttributeRef get_attribute();
  void set_attribute(  IIR_AttributeRef );

  IIRRef convert_tree(plugin_class_factoryRef factory);

  IIR_Boolean is_signal();

  IIR_TypeDefinitionRef get_subtype();

  declaration_type get_declaration_type();

  savant::set<IIR_DeclarationRef> find_declarations( IIR_NameRef  );

  IIR_Boolean is_attribute_declaration(){ return TRUE; }

  void publish_vhdl(ostream &);
  void publish_vhdl_decl(ostream &);
protected:
  IIRBase_AttributeDeclaration();
  virtual ~IIRBase_AttributeDeclaration() = 0;
    
  // (See the notes about get and set attribute above)  This is called "one
  // attribute" this declaration might refer to several instances of the
  // attribute - we just have a single pointer so we can easily get info
  // about the type.
  IIR_AttributeRef one_attribute;
private:

};

typedef refcount<IIRBase_AttributeDeclaration> IIRBase_AttributeDeclarationRef;

#endif
