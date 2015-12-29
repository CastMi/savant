
#ifndef IIRBASE_IDENTITY_OPERATOR_HH
#define IIRBASE_IDENTITY_OPERATOR_HH

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
#include "IIRBase_MonadicOperator.hh"
#include "IIR_IdentityOperator.hh"

class IIR_TypeDefinition;

class IIRBase_IdentityOperator : public virtual IIRBase_MonadicOperator,
				 public virtual IIR_IdentityOperator{

public:
  IIR_Kind get_kind() const override { return IIR_IDENTITY_OPERATOR; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_IdentityOperator"); }

  IIR_TypeDefinitionRef get_subtype();
  const string &get_operator_string() const;

  Precedence  get_precedence();
protected:
  IIRBase_IdentityOperator();
  virtual ~IIRBase_IdentityOperator() = 0;
    
private:
};

typedef refcount<IIRBase_IdentityOperator> IIRBase_IdentityOperatorRef;

#endif
