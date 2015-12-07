
#ifndef IIRBASE_PROCESS_STATEMENT_HH
#define IIRBASE_PROCESS_STATEMENT_HH

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
//          Malolan Chetlur     mal@ece.uc.edu

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIRBase_ConcurrentStatement.hh"
#include "IIR_ProcessStatement.hh"
#include "IIR_SequentialStatementList.hh"

class IIR_DeclarationList;
class IIRBase_ProcessStatement : public virtual IIRBase_ConcurrentStatement,
				 public virtual IIR_ProcessStatement{
public:
  // List Accessor(s)
  IIR_DeclarationListRef          get_process_declarative_part();
  IIR_SequentialStatementListRef  get_process_statement_part();
  void                            set_process_declarative_part(IIR_DeclarationListRef new_process_declarative_part);
  void                            set_process_statement_part(IIR_SequentialStatementListRef new_process_statement_part);

  IIR_Kind get_kind() const override { return IIR_PROCESS_STATEMENT; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_ProcessStatement"); }

  void set_postponed( IIR_Boolean postponed);
  IIR_Boolean get_postponed();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  savant::set<IIR_DeclarationRef> find_declarations( IIR_NameRef );
  void publish_vhdl(ostream &);
protected:
  
  IIRBase_ProcessStatement();
  virtual ~IIRBase_ProcessStatement() = 0;
    
private:
  // List Variable(s)
  IIR_DeclarationListRef process_declarative_part;
  IIR_SequentialStatementListRef process_statement_part;
  
  IIR_Boolean postponed;

};

typedef refcount<IIRBase_ProcessStatement> IIRBase_ProcessStatementRef;

#endif
