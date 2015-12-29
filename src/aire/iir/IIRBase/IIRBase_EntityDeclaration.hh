
#ifndef IIRBASE_ENTITY_DECLARATION_HH
#define IIRBASE_ENTITY_DECLARATION_HH

// Copyright (c) 1996-2003 The University of Cincinnati.  
// All rights reserved.

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
// SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
// OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
// LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING OR
// DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the U.S.,
// and the terms of this license.

// You may modify, distribute, and use the software contained in this
// package under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE"
// version 2, June 1991. A copy of this license agreement can be found in
// the file "LGPL", distributed with this archive.

// Authors: Philip A. Wilsey	philip.wilsey@ieee.org
//          Dale E. Martin	dmartin@cliftonlabs.com

//---------------------------------------------------------------------------
#include "savant_config.hh"
#include "IIRBase_LibraryUnit.hh"
#include "IIR_EntityDeclaration.hh"

class IIR_GenericList;
class IIR_PortList;
class IIR_DeclarationList;
class IIR_ArchitectureStatementList;
class IIR_DesignUnitList;

class IIRBase_EntityDeclaration : public virtual IIRBase_LibraryUnit, public virtual IIR_EntityDeclaration{

public:
  // List Accessor(s)
  IIR_GenericListRef               get_generic_clause();
  IIR_PortListRef                  get_port_clause();
  IIR_DeclarationListRef           get_entity_declarative_part();
  IIR_ArchitectureStatementListRef get_entity_statement_part();
  IIR_DesignUnitListRef            get_architectures();

  void                          set_generic_clause(IIR_GenericListRef new_generic_clause);
  void                          set_port_clause(IIR_PortListRef new_port_clause);
  void                          set_entity_declarative_part(IIR_DeclarationListRef new_entity_declarative_part);
  void                          set_entity_statement_part(IIR_ArchitectureStatementListRef new_entity_statement_part);
  void                          set_architectures(IIR_DesignUnitListRef new_architectures);

  IIR_Kind get_kind() const override { return IIR_ENTITY_DECLARATION; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_EntityDeclaration"); }

  IIRRef convert_tree(plugin_class_factoryRef factory);

  IIR_Boolean is_entity_declaration() { return TRUE; }
  IIR_Boolean is_primary_unit() { return TRUE; }

  declaration_type                      get_declaration_type();

  savant::set<IIR_DeclarationRef> find_declarations( IIR_NameRef );
  void publish_vhdl(ostream &);
  void publish_vhdl_decl(ostream &);
  void publish_vhdl_binding_name(ostream &);
  void publish_vhdl_with_library_name(ostream &);
protected:
  IIRBase_EntityDeclaration();
  virtual ~IIRBase_EntityDeclaration() = 0;
    
private:
  // List Variable(s)
  IIR_GenericListRef               generic_clause;
  IIR_PortListRef                  port_clause;
  IIR_DeclarationListRef           entity_declarative_part;
  IIR_ArchitectureStatementListRef entity_statement_part;
  IIR_DesignUnitListRef            architectures;

};

typedef refcount<IIRBase_EntityDeclaration> IIRBase_EntityDeclarationRef;

#endif
