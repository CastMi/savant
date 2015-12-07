
#ifndef IIR_ENTITY_DECLARATION_HH
#define IIR_ENTITY_DECLARATION_HH

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
#include "IIR_LibraryUnit.hh"

REF_FORWARD_DECL(IIR_GenericList);
REF_FORWARD_DECL(IIR_PortList);
REF_FORWARD_DECL(IIR_ArchitectureStatementList);
REF_FORWARD_DECL(IIR_DesignUnitList);

class IIR_DeclarationList;

class IIR_EntityDeclaration : public virtual IIR_LibraryUnit{
public:
  virtual ~IIR_EntityDeclaration() {}    

  // List accessor(s)
  virtual IIR_GenericListRef get_generic_clause() = 0;
  virtual IIR_PortListRef get_port_clause() = 0;
  virtual IIR_DeclarationListRef get_entity_declarative_part() = 0;
  virtual IIR_ArchitectureStatementListRef get_entity_statement_part() = 0;
  virtual IIR_DesignUnitListRef get_architectures() = 0;

  virtual void                          set_generic_clause(IIR_GenericListRef new_generic_clause) = 0;
  virtual void                          set_port_clause(IIR_PortListRef new_port_clause) = 0;
  virtual void                          set_entity_declarative_part(IIR_DeclarationListRef new_entity_declarative_part) = 0;
  virtual void                          set_entity_statement_part(IIR_ArchitectureStatementListRef new_entity_statement_part) = 0;
  virtual void                          set_architectures(IIR_DesignUnitListRef new_architectures) = 0;
};

typedef refcount<IIR_EntityDeclaration> IIR_EntityDeclarationRef;

#endif
