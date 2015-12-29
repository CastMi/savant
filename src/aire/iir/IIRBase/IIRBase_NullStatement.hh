
#ifndef IIRBASE_NULL_STATEMENT_HH
#define IIRBASE_NULL_STATEMENT_HH

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
#include "IIRBase_SequentialStatement.hh"
#include "IIR_NullStatement.hh"

class IIRBase_NullStatement : public virtual IIRBase_SequentialStatement, public virtual IIR_NullStatement{

public:

  IIR_Kind get_kind() const {return IIR_NULL_STATEMENT;}
  const IIR_Char *get_kind_text() const {return "IIR_NullStatement";}

  void publish_vhdl(ostream &);
protected:
  
  IIRBase_NullStatement();
  virtual ~IIRBase_NullStatement() = 0;
    
private:

};

typedef refcount<IIRBase_NullStatement> IIRBase_NullStatementRef;

#endif
