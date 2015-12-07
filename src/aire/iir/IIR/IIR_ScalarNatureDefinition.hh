
#ifndef IIR_SCALAR_NATURE_DEFINITION_HH
#define IIR_SCALAR_NATURE_DEFINITION_HH

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
#include "IIR_NatureDefinition.hh"
#include "IRBasicDataTypes.hh"
#include "IIR_TerminalDeclaration.hh"
 
class IIR_TypeDefinition;
class IIR_TerminalDeclaration;
 
class IIR_ScalarNatureDefinition : public virtual IIR_NatureDefinition {
public:
  virtual ~IIR_ScalarNatureDefinition() {};
 
  /** Set the across type of the nature */
  virtual void set_across(IIR_TypeDefinitionRef across) = 0;
 
  /** Returns the across type of the nature */
  virtual IIR_TypeDefinitionRef get_across() = 0;
 
  /** Set the though type of nature */
  virtual void set_through(IIR_TypeDefinitionRef through) = 0;
 
  /** Returns the through type of nature */
  virtual IIR_TypeDefinitionRef get_through() = 0;
 
  /** Set the reference terminal of the nature */
  virtual void set_reference_terminal( IIR_TerminalDeclarationRef ) = 0;
 
  /** Returns the reference terminal of the nature */
  virtual IIR_TerminalDeclarationRef get_reference_terminal() = 0;
};

typedef refcount<IIR_ScalarNatureDefinition> IIR_ScalarNatureDefinitionRef;

#endif
