
#ifndef IIRBASE_PACKAGE_DECLARATION_HH
#define IIRBASE_PACKAGE_DECLARATION_HH

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

#include "savant.hh"
#include "IRBasicDataTypes.hh"
#include "IIRBase_LibraryUnit.hh"
#include "IIR_PackageDeclaration.hh"
#include "set.hh"

class IIRBase_PackageDeclaration : public virtual IIRBase_LibraryUnit, public virtual IIR_PackageDeclaration {

public:
  // List Accessor(s)
  IIR_DeclarationListRef    get_package_declarative_part();
  void                      set_package_declarative_part(IIR_DeclarationListRef new_package_declarative_part);

  IIR_Kind get_kind() const {return IIR_PACKAGE_DECLARATION;}
  IIR_CharConstRef get_kind_text() const {return IIR_CharConstRef("IIR_PackageDeclaration");}

  IIR_PackageBodyDeclarationRef get_package_body();
  void set_package_body( IIR_PackageBodyDeclarationRef );

  IIRRef convert_tree(plugin_class_factoryRef factory);

  declaration_type get_declaration_type();

  savant::set<IIR_DeclarationRef> find_declarations( IIR_NameRef );

  IIR_Boolean is_package_declaration(){ return TRUE; }
  IIR_Boolean is_primary_unit(){ return TRUE; }

  void publish_vhdl_decl(ostream &);
  void publish_vhdl(ostream &);
protected:
  
  IIRBase_PackageDeclaration();
  virtual ~IIRBase_PackageDeclaration() = 0;
    
private:
  // List Variable(s)
  IIR_DeclarationListRef         package_declarative_part;
  
  IIR_PackageBodyDeclarationRef  my_package_body;

};

typedef refcount<IIRBase_PackageDeclaration> IIRBase_PackageDeclarationRef;

#endif
