
#ifndef IIRBASE_REMAINDER_OPERATOR_HH
#define IIRBASE_REMAINDER_OPERATOR_HH

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
#include "IIR_RemainderOperator.hh"
#include "IIRBase_DyadicOperator.hh"

class IIRBase_RemainderOperator : public virtual IIRBase_DyadicOperator, public virtual IIR_RemainderOperator{
public:

  IIR_Kind get_kind() const override { return IIR_REMAINDER_OPERATOR; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_RemainderOperator"); }
  const string &get_operator_string() const;

  Precedence  get_precedence();
  bool is_associative(IIR_Kind);

protected:
  
  IIRBase_RemainderOperator();
  virtual ~IIRBase_RemainderOperator() = 0;
    
private:

};

typedef refcount<IIRBase_RemainderOperator> IIRBase_RemainderOperatorRef;

#endif
