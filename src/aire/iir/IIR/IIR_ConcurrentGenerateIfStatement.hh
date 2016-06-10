
#ifndef IIR_CONCURRENT_GENERATE_IF_STATEMENT_HH
#define IIR_CONCURRENT_GENERATE_IF_STATEMENT_HH

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

#include "IIR_ConcurrentStatement.hh"
#include "IIR_DeclarationList.hh"

class IIR_ArchitectureStatementList;

class IIR_ConcurrentGenerateIfStatement : public virtual IIR_ConcurrentStatement{

public:
  virtual ~IIR_ConcurrentGenerateIfStatement() {}
    
  // List accessor(s)
  virtual IIR_DeclarationList<>         *get_block_declarative_part() = 0;
  virtual IIR_ArchitectureStatementList *get_concurrent_statement_part() = 0;
  virtual void                          set_block_declarative_part(IIR_DeclarationList<> *) = 0;
  virtual void                          set_concurrent_statement_part(IIR_ArchitectureStatementList *) = 0;

  virtual void set_if_condition( IIR *condition ) = 0;
  virtual IIR *get_if_condition() = 0;
};
#endif
