#ifndef IIRSCRAM_STATEMENT_HH
#define IIRSCRAM_STATEMENT_HH

// Copyright (c) 1996-2001 The University of Cincinnati.  
// All rights reserved.

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF
// THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE, OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES
// SUFFERED BY LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING
// OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the
// U.S., and the terms of this license.

// You may modify, distribute, and use the software contained in this
// package under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE"
// version 2, June 1991. A copy of this license agreement can be found
// in the file "LGPL", distributed with this archive.

// Authors: Philip A. Wilsey	philip.wilsey@ieee.org
//          Dale E. Martin	dmartin@cliftonlabs.com
//          Timothy J. McBrayer
//          Malolan Chetlur    
//          Umesh Kumar V. Rajasekaran

//---------------------------------------------------------------------------

#include "IIRScram.hh"
#include "IIRBase_Statement.hh"

template <class type> class dl_list;

class IIRScram_CaseStatementAlternativeList;
class IIRScram_Label;
class IIR_LibraryUnit;
class IIRScram_Name;
class IIRScram_SimpleName;
class IIRScram_Statement;
class IIRScram_StatementList;
class IIRScram_SubprogramDeclaration;
class IIRScram_TextLiteral;
class IIRScram_TypeDefinition;
class IIRScram_WaitStatement;
class IIRScram_WaveformList;

class IIRScram_Statement : public virtual IIRBase_Statement {
public:
  virtual ~IIRScram_Statement() = 0;
  virtual IIRScram_Statement *_clone();
  virtual void _clone( IIRScram_Statement *);
  virtual void _type_check();
  virtual void _type_check( IIRScram_TypeDefinition * );
  virtual void _type_check( savant::set<IIRScram_TypeDefinition> * );
  void _report_undefined_scram_fn(const char *);
  IIRScram_DesignFile *_get_design_file() const;
  virtual IIRScram_Statement *_rval_to_decl( IIRScram_TypeDefinition * );
  virtual IIR_Boolean _is_readable();
  virtual IIR_Boolean _is_writable();
  virtual IIR_Boolean _is_iir_name() { return false; }
  virtual IIR_Boolean _is_iir_declaration(){ return false; }
  virtual IIR_Boolean _is_iir_attribute(){ return false; }
  virtual savant::set<IIRScram_TypeDefinition> *_get_rval_set(constraint_functor *functor = 0);

  virtual savant::set<IIRScram_Declaration> *_symbol_lookup();
  symbol_table *_get_symbol_table( );
  virtual IIRScram_TypeDefinition *_get_subtype();

  // This method does the type checking and resolution for a boolean
  // condition.  Pass in a conditional, and it will return it
  // resolved.  It will report any errors it finds (like that value
  // not being boolean).  This method is called by IIR_IfStatement,
  // IIR_ElsifStatement, and IIR_WhileLoopStatement...  (For it to be called 
  // from IIR_Elsif, this must be public!
  static IIRScram_Statement *_type_check_and_resolve_boolean_condition( IIRScram_Statement * );
	
  /** This method calculates the locally static value of the expression
      it's called on.  If this is impossible (i.e. the expression isn't
      static, or it's not integer valued, it will return NULL.)  If
      possible, it _allocates_ an IIRScram_IntegerLiteral with the result
      represented in it. */
  virtual IIRScram_IntegerLiteral *_get_integer_static_value();

  // These virtual methods are needed to support the type checking functions in the
  // protected section
  virtual IIRScram *_get_target();
  virtual IIR_DelayMechanism _get_delay_mechanism();
  virtual IIRScram *_get_reject_time_expression();
	
  // These methods are needed for the type checking of case statements that occurs in
  // IIRScram_CaseStatement, and IIRScram_ConcurrentSelectedSignalAssignment.
  virtual IIRScram *_get_case_statement_expression();
  virtual void _set_case_statement_expression( IIRScram * );

  /** For assertion statements this method is overloaded to return the
      assertion condtion.  For anything else it returns 0. */
  virtual IIRScram_Statement *_get_assertion_condition(){ return 0; }
  
  /** For report and assertion statements this method is overloaded to
      return the report expression.  For anything else it returns 0. */
  virtual IIRScram_Statement *_get_report_expression(){ return 0; }

  /** For report and assertion statements this method is overloaded to
      return the report expression. For anything else it returns 0. */
  virtual IIRScram_Statement *_get_severity_expression(){ return 0; }

  virtual IIRScram_Statement *_decl_to_decl( IIRScram_Declaration * ) {return nullptr;};
  
  virtual IIRScram_Label *_find_instantiate_label( IIRScram_SimpleName * );

  virtual void _make_interface_visible( symbol_table * );

  IIRScram_Label *_get_label() const;

  virtual IIRScram_Statement *_semantic_transform( IIRScram_TypeDefinition * );
  virtual IIRScram_Statement *_semantic_transform( savant::set<IIRScram_TypeDefinition> * );

  IIRScram_Label *_lookup_label( IIR_Boolean complain_on_error );
  
  /**
     Returns the library unit that contains this statement.
  */
  IIR_LibraryUnit *_get_design_unit();

  /** Returns the design unit name that this statement is associated
      with. */
  const string _get_design_unit_name();

  IIRScram_Identifier* _get_declarator() { return nullptr; };

protected:

  // These methods are used in the type checking of signal assignment statements,
  // and concurrent selected signal assignment statements.
  void _type_check_target_and_waveform( IIRScram_WaveformList * );
  void _type_check_mechanism_and_time( IIRScram_WaveformList * );

  // This method handles the type checking of case statement expressions and their 
  // alternatives.  The return value is the resolved expression (if there is no error),
  // and NULL if there is an error.  The list is type checked in place.
  void _type_check_case_statement_expression( IIRScram_CaseStatementAlternativeList * );

  // The following methods apply to assertion statements, concurrent assertion
  // statements, and report statements.
  void _type_check_assertion_condition();
  void _type_check_report_expression();
  void _type_check_severity_expression();

  // This method prints the statement label for all statements.

  // This method prints the delay mechanism
  // (transport/reject...inertial) for all statements. 
};

#endif
