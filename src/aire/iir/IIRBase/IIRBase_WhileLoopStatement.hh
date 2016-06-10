#ifndef IIRBASE_WHILE_LOOP_STATEMENT_HH
#define IIRBASE_WHILE_LOOP_STATEMENT_HH

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

#include "IIRBase_SequentialStatement.hh"
#include "IIR_WhileLoopStatement.hh"

class IIR_SequentialStatementList;

class IIRBase_WhileLoopStatement : public virtual IIRBase_SequentialStatement, public virtual IIR_WhileLoopStatement{

public:
  // List Accessor(s)
  IIR_SequentialStatementList *get_sequence_of_statements();
  void                        set_sequence_of_statements(IIR_SequentialStatementList *new_sequence_of_statements);

  IIR_Kind get_kind() const {
    return IIR_WHILE_LOOP_STATEMENT;
  }
  const IIR_Char *get_kind_text() const {
    return "IIR_WhileLoopStatement";
  }

  void set_while_condition( IIR *while_condition);
  IIR *get_while_condition();

  IIR_Statement *convert_tree(plugin_class_factory *factory);

  IIR_Boolean has_statement_list() { return true; }
  IIR_Boolean is_above_attribute_found();

  void publish_vhdl(ostream &);
protected:
  IIRBase_WhileLoopStatement();
  virtual ~IIRBase_WhileLoopStatement() = 0;
    
private:
  // List Variable(s)
  IIR_SequentialStatementList *sequence_of_statements;
  
  IIR *while_condition;
};

#endif
