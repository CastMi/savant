
#ifndef IIRBASE_BLOCK_STATEMENT_HH
#define IIRBASE_BLOCK_STATEMENT_HH

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
#include "IIR_BlockStatement.hh"
#include "IIRBase_ConcurrentStatement.hh"

class IIR_GenericList;
class IIR_AssociationList;
class IIR_PortList;
class IIR_DeclarationList;
class IIR_ArchitectureStatementList;
class IIR_SignalDeclaration;

class IIRBase_BlockStatement : public virtual IIRBase_ConcurrentStatement, public virtual IIR_BlockStatement{

public:
  // List Accessor(s)
  IIR_GenericListRef               get_generic_clause();
  IIR_AssociationListRef           get_generic_map_aspect();
  IIR_PortListRef                  get_port_clause();
  IIR_AssociationListRef           get_port_map_aspect();
  IIR_DeclarationListRef           get_block_declarative_part();
  IIR_ArchitectureStatementListRef get_block_statement_part();
  void                             set_generic_clause(IIR_GenericListRef new_generic_clause);
  void                             set_generic_map_aspect(IIR_AssociationListRef new_generic_map_aspect);
  void                             set_port_clause(IIR_PortListRef new_port_clause);
  void                             set_port_map_aspect(IIR_AssociationListRef new_port_map_aspect);
  void                             set_block_declarative_part(IIR_DeclarationListRef new_block_declarative_part);
  void                             set_block_statement_part(IIR_ArchitectureStatementListRef new_block_statement_part);

  IIR_Kind get_kind() const override { return IIR_BLOCK_STATEMENT; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_BlockStatement"); }
 
  void      set_guard_expression( IIRRef guard_expression );
  IIRRef    get_guard_expression();

  IIR_SignalDeclarationRef get_implicit_guard_signal( );
  void                     set_implicit_guard_signal( IIR_SignalDeclarationRef );

  IIRRef convert_tree(plugin_class_factoryRef factory);

  savant::set<IIR_DeclarationRef> find_declarations( IIR_NameRef );

  void publish_vhdl(ostream &);
protected:
  IIRBase_BlockStatement();
  virtual ~IIRBase_BlockStatement() = 0;
    
private:
  // List Variable(s)
  IIR_GenericListRef               generic_clause;
  IIR_AssociationListRef           generic_map_aspect;
  IIR_PortListRef                  port_clause;
  IIR_AssociationListRef           port_map_aspect;
  IIR_DeclarationListRef           block_declarative_part;
  IIR_ArchitectureStatementListRef block_statement_part;

  IIRRef                   guard_expression;
  IIR_SignalDeclarationRef implicit_guard_signal;

};

typedef refcount<IIRBase_BlockStatement> IIRBase_BlockStatementRef;

#endif
