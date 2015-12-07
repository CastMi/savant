
#ifndef IIRBASE_SCALAR_NATURE_DEFINITION_HH
#define IIRBASE_SCALAR_NATURE_DEFINITION_HH

// Copyright (c) 2002 The University of Cincinnati.
// All rights reserved.
 
// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
// SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR
// NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
// LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING OR DISTRIBUTING
// THIS SOFTWARE OR ITS DERIVATIVES.
 
// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the U.S., and
// the terms of this license.

// You may modify, distribute, and use the software contained in this package
// under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE" version 2, June
// 1991. A copy of this license agreement can be found in the file "LGPL",
// distributed with this archive.
 
// Authors: Sivakumar Gowrisankar             gowriss@ececs.uc.edu
//          Vinod Chamarty                    chamarv@ececs.uc.edu
//          Vasudevan Shanmugasundaram
//          Kathiresan Nellayappan
 
//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIR_ScalarNatureDefinition.hh"
#include "IRBasicDataTypes.hh"
#include "IIR_TerminalDeclaration.hh"
#include "IIRBase_NatureDefinition.hh"
 
class IIR_TypeDefinition;
class IIR_TerminalDeclaration;
class IIR;
 
class IIRBase_ScalarNatureDefinition : public virtual IIRBase_NatureDefinition, public virtual IIR_ScalarNatureDefinition {
 
public:
  IIR_Kind get_kind() const override { return IIR_SCALAR_NATURE_DEFINITION; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_ScalarNatureDefinition"); }
 
  /** Set the across type of the nature */
  void set_across(IIR_TypeDefinitionRef across);
 
  /** Returns the across type of the nature */
  IIR_TypeDefinitionRef get_across();
 
  /** Set the though type of nature */
  void set_through(IIR_TypeDefinitionRef through);
 
  /** Returns the through type of nature */
  IIR_TypeDefinitionRef get_through();
 
  /** Set the reference terminal of the nature */
  void set_reference_terminal( IIR_TerminalDeclarationRef );
 
  /** Returns the reference terminal of the nature */
  IIR_TerminalDeclarationRef get_reference_terminal();

  IIRRef convert_tree(plugin_class_factoryRef factory);
 
  void publish_vhdl_decl(ostream &);
protected:

  IIRBase_ScalarNatureDefinition();
  virtual ~IIRBase_ScalarNatureDefinition() = 0;
 
private:

  IIR_TypeDefinitionRef across;
  IIR_TypeDefinitionRef through;
  IIR_TerminalDeclarationRef reference_terminal;
  IIRRef across_tolerance;
  IIRRef through_tolerance;

};

typedef refcount<IIRBase_ScalarNatureDefinition> IIRBase_ScalarNatureDefinitionRef;

#endif
