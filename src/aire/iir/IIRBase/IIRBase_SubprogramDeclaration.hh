
#ifndef IIRBASE_SUBPROGRAM_DECLARATION_HH
#define IIRBASE_SUBPROGRAM_DECLARATION_HH

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
#include "IIR_SubprogramDeclaration.hh"
#include "IIR_DeclarationList.hh"
#include "IIR_AttributeSpecificationList.hh"

class IIR_InterfaceList;
class IIR_DeclarationList;
class IIR_SequentialStatementList;
class IIR_AttributeSpecificationList;
class IIRBase_SubprogramDeclaration : public virtual IIRBase_Declaration, public virtual IIR_SubprogramDeclaration{

public:
  // List Accessor(s)
  IIR_InterfaceListRef                get_interface_declarations();
  IIR_DeclarationListRef              get_subprogram_declarations();
  IIR_SequentialStatementListRef      get_subprogram_body();
  IIR_AttributeSpecificationListRef   get_attributes();
  void                                set_interface_declarations(IIR_InterfaceListRef new_interface_declarations);
  void                                set_subprogram_declarations(IIR_DeclarationListRef new_subprogram_declarations); 
  void                                set_subprogram_body(IIR_SequentialStatementListRef new_subprogram_body);
  void                                set_attributes(IIR_AttributeSpecificationListRef new_attributes);

  IIR_Kind get_kind() const override { return IIR_SUBPROGRAM_DECLARATION; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_SubprogramDeclaration"); }

  IIRRef convert_tree(plugin_class_factoryRef factory);

  /** This method returns true if this method contained a body when it was parsed.
      We need this to differentiate between:
      procedure foo;
      and
      procedure foo is begin end foo;
      (Both are legal, and both could appear in a package body or entity's declarative
      region)
  */
  IIR_Boolean contains_body();
  void set_contains_body( IIR_Boolean );

  IIR_Boolean is_subprogram(){ return TRUE; }
  IIR_Boolean is_operator();
  IIR_Boolean has_statement_list() { return contains_body(); }

  ostream &print( ostream & );
protected:
  
  IIRBase_SubprogramDeclaration();
  virtual ~IIRBase_SubprogramDeclaration() = 0;
    
private:
  // List Variable(s)
  IIR_InterfaceListRef                interface_declarations;
  IIR_DeclarationListRef              subprogram_declarations;
  IIR_SequentialStatementListRef      subprogram_body;
  IIR_AttributeSpecificationListRef   attributes;

  IIR_Boolean                           my_contains_body;
};

typedef refcount<IIRBase_SubprogramDeclaration> IIRBase_SubprogramDeclarationRef;

#endif
