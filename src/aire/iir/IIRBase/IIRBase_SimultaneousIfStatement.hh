
#ifndef IIRBASE_SIMULTANEOUS_IF_STATEMENT_HH
#define IIRBASE_SIMULTANEOUS_IF_STATEMENT_HH

// Copyright (c) 2002-2003 The University of Cincinnati.
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

// Authors: Harish Venkataramani venkath@ececs.uc.edu

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIRBase_SimultaneousStatement.hh"
#include "IIR_SimultaneousIfStatement.hh"
#include "IRBasicDataTypes.hh"

class IIR;
class IIR_ArchitectureStatementList;

/** This class selects for evaluation one of the enclosed simultaneous
    statement parts depending on the value of one or more conditions. */
class IIRBase_SimultaneousIfStatement : public virtual IIRBase_SimultaneousStatement, public virtual IIR_SimultaneousIfStatement {
public:
  // List Accessors
  IIR_ArchitectureStatementListRef get_then_statement_list();
  IIR_ArchitectureStatementListRef get_else_statement_list();
  void                          set_then_statement_list(IIR_ArchitectureStatementListRef );
  void                          set_else_statement_list(IIR_ArchitectureStatementListRef );

  IIR_Kind get_kind() const override { return IIR_SIMULTANEOUS_IF_STATEMENT; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_SimultaneousIfStatement"); }
  
  /** Sets Elsif condition. */
  void set_elsif(IIR_SimultaneousElsifRef elsif_clause);
  IIR_SimultaneousElsifRef get_elsif();

  /** The condition specified after if and elsif (if any) are evaluated in
      succession until one evaluates to TRUE or all conditions are
      evaluated and yield FALSE. LRM [ 15.2 - 75 ] */
  void set_condition(IIRRef );
  IIRRef get_condition();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  void publish_vhdl(ostream &);
protected:
  IIRBase_SimultaneousIfStatement();
  virtual ~IIRBase_SimultaneousIfStatement()=0;
  
private:
  /** The simultaneous statement part whose condition evaluates to TRUE is
      evaluated. LRM [ $ 15.2 - 75 ] */
  IIR_ArchitectureStatementListRef then_statement_list;
  IIR_ArchitectureStatementListRef else_statement_list;

  IIRRef  condition;
  IIR_SimultaneousElsifRef elsif_clause;

};

typedef refcount<IIRBase_SimultaneousIfStatement> IIRBase_SimultaneousIfStatementRef;

#endif
