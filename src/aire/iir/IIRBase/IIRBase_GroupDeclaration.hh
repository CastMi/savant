
#ifndef IIRBASE_GROUP_DECLARATION_HH
#define IIRBASE_GROUP_DECLARATION_HH

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

#include "savant_config.hh"
#include "IIRBase_Declaration.hh"
#include "IIR_GroupDeclaration.hh"

class IIR_Name;
class IIR_DesignatorList;
class IIR_AttributeSpecificationList;

class IIRBase_GroupDeclaration : public virtual IIRBase_Declaration, public virtual IIR_GroupDeclaration{

public:
  // List Accessor(s)
  IIR_DesignatorListRef               get_group_constituent_list();
  IIR_AttributeSpecificationListRef   get_attributes();
  void                                set_group_constituent_list(IIR_DesignatorListRef new_group_constituent_list);
  void                                set_attributes(IIR_AttributeSpecificationListRef new_attributes);

  IIR_Kind get_kind() const override { return IIR_GROUP_DECLARATION; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_GroupDeclaration"); }

  void set_group_template(IIR_NameRef group_template_name);
  IIR_NameRef get_group_template_name();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  declaration_type                      get_declaration_type();

  IIR_Boolean                           is_group_declaration(){ return TRUE; }
  void publish_vhdl_decl(ostream &);
protected:
  IIRBase_GroupDeclaration();
  virtual ~IIRBase_GroupDeclaration() = 0;
    
private:
  // List Variable(s)
  IIR_DesignatorListRef group_constituent_list;
  IIR_AttributeSpecificationListRef attributes;

  IIR_NameRef  group_template_name;  

};

typedef refcount<IIRBase_GroupDeclaration> IIRBase_GroupDeclarationRef;

#endif
