#ifndef IIRSCRAM_ARCHITECTURE_DECLARATION_HH
#define IIRSCRAM_ARCHITECTURE_DECLARATION_HH

// Copyright (c) 1996-2003 The University of Cincinnati.  
// All rights reserved.

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF4 THE
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
//          Timothy J. McBrayer
//          Malolan Chetlur    
//          Narayanan Thondugulam
//          Krishnan Subramani

//---------------------------------------------------------------------------

#include "IIRScram_LibraryUnit.hh"
#include "IIRBase_ArchitectureDeclaration.hh"
#include "symbol_table.hh"

template <class type> class IIRScram_DeclarationList;

class IIRScram_ArchitectureDeclaration : public virtual IIRScram_LibraryUnit,
					 public virtual IIRBase_ArchitectureDeclaration {

public:
  IIRScram_ArchitectureDeclaration();
  ~IIRScram_ArchitectureDeclaration();

  IIRScram_EntityDeclaration* _get_entity();
  IIRScram_DeclarationList<IIR_Declaration>* _get_architecture_declarative_part();
  IIRScram_ArchitectureStatementList* _get_architecture_statement_part();

#ifdef PROCESS_COMBINATION
  void _static_elaborate(IIRScram_ArchitectureDeclaration*, IIRScram_DeclarationList<IIR_Declaration>*,
			 char*);
  void _combine();
#endif

  void _make_interface_visible(symbol_table * );

  void _type_check();
  IIRScram_PortList *_get_port_list();
  IIRScram_GenericList *_get_generic_list();
  IIRScram_List<IIR_Statement> *_get_statement_list();

  /** This list holds the component declarations in this architectures
      declarative region.  It will be used to post process configuration
      specficiations such that ALL and OTHERS can be resolved, and so that
      labels that are not declared until the statement part can be resolved
      as well. */
  IIRScram_DeclarationList<IIR_Declaration> *_get_component_declarations();
  void _set_component_declarations( IIRScram_DeclarationList<IIR_Declaration> * );

  void _set_configuration_specifications( IIRScram_DeclarationList<IIR_Declaration> * );
  IIRScram_DeclarationList<IIR_Declaration> *_get_configuration_specifications();

  IIRScram_DeclarationList<IIR_Declaration>* _get_declaration_list();
};

#endif
