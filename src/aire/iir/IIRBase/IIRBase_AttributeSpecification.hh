
#ifndef IIRBASE_ATTRIBUTE_SPECIFICATION_HH
#define IIRBASE_ATTRIBUTE_SPECIFICATION_HH

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
//          Timothy J. McBrayer tmcrbaye@ece.uc.edu

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIRBase_Declaration.hh"
#include "IIR_AttributeSpecification.hh"

//REF_FORWARD_DECL(IIR_DesignatorList);
class IIR_Identifier;
class IIR_Declaration;

class IIRBase_AttributeSpecification : public virtual IIRBase_Declaration, public virtual IIR_AttributeSpecification{

public:
  // List Accessor(s)
  IIR_DesignatorListRef get_entity_name_list();
  void               set_entity_name_list(IIR_DesignatorListRef new_entity_name_list);

  IIR_Kind get_kind() const override { return IIR_ATTRIBUTE_SPECIFICATION; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_AttributeSpecification"); }

  void set_value(IIRRef);
  IIRRef get_value();

  void set_entity_class(IIR_IdentifierRef );
  IIR_IdentifierRef get_entity_class();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  /** This holds the declaration of the attribute that is being
      specified... */
  void set_declaration( IIR_DeclarationRef );
  IIR_DeclarationRef get_declaration();

  IIR_TypeDefinitionRef get_subtype();

  declaration_type get_declaration_type();
  void publish_vhdl_decl(ostream &);
protected:
  IIRBase_AttributeSpecification();
  virtual ~IIRBase_AttributeSpecification() = 0;
    
private:
  // List Variable(s)
  IIR_DesignatorListRef entity_name_list;

  IIRRef value;
  IIR_IdentifierRef entity_class;
  IIR_DeclarationRef attribute_declaration;
};

typedef refcount<IIRBase_AttributeSpecification> IIRBase_AttributeSpecificationRef;

#endif
