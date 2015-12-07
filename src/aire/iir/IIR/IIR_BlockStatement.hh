
#ifndef IIR_BLOCK_STATEMENT_HH
#define IIR_BLOCK_STATEMENT_HH

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
#include "IIR_ConcurrentStatement.hh"

REF_FORWARD_DECL(IIR_GenericList);
REF_FORWARD_DECL(IIR_PortList);
REF_FORWARD_DECL(IIR_AssociationList);
class IIR_ArchitectureStatementList;
class IIR_DeclarationList;
class IIR_SignalDeclaration;

class IIR_BlockStatement : public virtual IIR_ConcurrentStatement{

public:
  virtual ~IIR_BlockStatement() {}

  // List accessor(s)
  virtual IIR_GenericListRef get_generic_clause() = 0;
  virtual IIR_AssociationListRef get_generic_map_aspect() = 0;
  virtual IIR_PortListRef get_port_clause() = 0;
  virtual IIR_AssociationListRef get_port_map_aspect() = 0;
  virtual IIR_DeclarationListRef get_block_declarative_part() = 0;
  virtual IIR_ArchitectureStatementListRef get_block_statement_part() = 0;
  virtual void                                  set_generic_clause(IIR_GenericListRef ) = 0;
  virtual void                                  set_generic_map_aspect(IIR_AssociationListRef ) = 0;
  virtual void                                  set_port_clause(IIR_PortListRef ) = 0;
  virtual void                                  set_port_map_aspect(IIR_AssociationListRef ) = 0;
  virtual void                                  set_block_declarative_part(IIR_DeclarationListRef ) = 0;
  virtual void                                  set_block_statement_part(IIR_ArchitectureStatementListRef ) = 0;

  virtual void set_guard_expression( IIRRef guard_expression ) = 0;
  virtual IIRRef get_guard_expression() = 0;

  virtual IIR_SignalDeclarationRef get_implicit_guard_signal( ) = 0;
  virtual void                          set_implicit_guard_signal( IIR_SignalDeclarationRef  ) = 0;
};

typedef refcount<IIR_BlockStatement> IIR_BlockStatementRef;

#endif
