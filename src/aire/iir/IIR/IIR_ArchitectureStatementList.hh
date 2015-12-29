
#ifndef IIR_ARCHITECTURE_STATEMENT_LIST_HH
#define IIR_ARCHITECTURE_STATEMENT_LIST_HH

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
#include "IIR_List.hh"

REF_FORWARD_DECL(IIR_ArchitectureStatement);

class IIR_ArchitectureStatementList : public virtual IIR_List {
public:    
  IIR_ArchitectureStatementList() {};
  virtual ~IIR_ArchitectureStatementList() {};

  virtual IIRRef first() = 0;
  virtual IIRRef successor( IIR_ArchitectureStatementRef ) = 0;
  virtual void append_element( IIR_ArchitectureStatementRef ) = 0;
};

typedef refcount<IIR_ArchitectureStatementList> IIR_ArchitectureStatementListRef;

#endif
