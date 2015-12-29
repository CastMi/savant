
#ifndef IIRBASE_CONCURRENT_ASSERTION_STATEMENT_HH
#define IIRBASE_CONCURRENT_ASSERTION_STATEMENT_HH

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
#include "IIRBase_ConcurrentStatement.hh"
#include "IIR_ConcurrentAssertionStatement.hh"

class IIRBase_ConcurrentAssertionStatement : public virtual IIRBase_ConcurrentStatement, public virtual IIR_ConcurrentAssertionStatement{

public:
  IIR_Kind get_kind() const override { return IIR_CONCURRENT_ASSERTION_STATEMENT; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_ConcurrentAssertionStatement"); }

  void set_postponed( IIR_Boolean predicate );
  IIR_Boolean get_postponed();

  void set_assertion_condition( IIRRef condition );
  IIRRef get_assertion_condition();

  void set_report_expression( IIRRef expression );
  IIRRef get_report_expression();

  void set_severity_expression(  IIRRef expression );
  IIRRef get_severity_expression();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  void publish_vhdl(ostream &);
protected:
  IIRBase_ConcurrentAssertionStatement();
  virtual ~IIRBase_ConcurrentAssertionStatement() = 0;
    
private:
  IIR_Boolean predicate;
  IIRRef      assertion_condition;
  IIRRef      report_expression;
  IIRRef      severity_expression;
};

typedef refcount<IIRBase_ConcurrentAssertionStatement> IIRBase_ConcurrentAssertionStatementRef;

#endif
