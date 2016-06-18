#ifndef IIR_STATEMENT_HH
#define IIR_STATEMENT_HH

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

#include "IIR.hh"

class IIR_Name;
class IIRScram_Declaration;
class IIR_Label;
namespace savant {
  template <class type> class set;
}

class IIR_Statement {
public:
  virtual ~IIR_Statement() {}
    
  virtual void set_label( IIR_Label *label) = 0;
  virtual IIR_Label *get_label() const = 0;
  virtual const IIR_Char *get_kind_text() const = 0;
  virtual IIR_Kind get_kind() const = 0;
  virtual IIR_DesignFile *get_design_file() const = 0;

  virtual void _report_undefined_fn(const char *) = 0;
  virtual plugin_class_factory *get_class_factory();
  virtual IIR_Boolean is_above_attribute_found() const = 0;
  virtual savant::set<IIR_Declaration> *find_declarations( IIR_Name * ) = 0;

  virtual IIR_TypeDefinition *get_subtype() = 0;
  /** For assertion statements this method is overloaded to return the
      assertion condtion.  For anything else it returns 0. */
  virtual IIR_Statement *get_assertion_condition() = 0;
  virtual IIR_Boolean is_locally_static() = 0;
  virtual IIR_Boolean is_scalar_type() const = 0;
  virtual IIR_Boolean is_array_type() const = 0;
  virtual IIR_Boolean is_signal() const = 0;
  virtual IIR_Boolean is_interface() const = 0;
  virtual IIR_Boolean is_variable() const = 0;
  virtual IIR_Boolean is_object() const = 0;
  virtual IIR_Boolean is_logical_operator() const = 0;
  virtual IIR_Boolean is_relational_operator() const = 0;
  virtual IIR_Boolean is_entity_declaration() const = 0;
  virtual IIR_Boolean is_type() const = 0;
  virtual IIR_Boolean is_name() const = 0;
  virtual IIR_Boolean is_label() const = 0;
  virtual IIR_Boolean _is_iir_attribute() const = 0;
  virtual IIR_Boolean is_text_literal() const = 0;
  virtual IIR_Declaration *_find_formal_declaration();
  virtual IIR_SignalKind get_signal_kind() const = 0;
  virtual IIR_Identifier *get_declarator() = 0;
  /// Is this node a configuration declaration?
  virtual IIR_Boolean is_configuration_declaration() const = 0;
  /// Is this node a component declaration?
  virtual IIR_Boolean is_component_declaration() const = 0;

  virtual ostream &print( ostream & ) = 0;
  
  virtual IIR_Declaration* get_prefix_declaration() = 0;
  virtual IIR_TextLiteral *get_prefix_string() = 0;
  /**
     Republish the VHDL that this node represents.  Called on a expression,
     it would republish just the expression.  Called on a design file, the whole
     file worth of vhdl would be republished.     
  */
  virtual void publish_vhdl( ostream &os ) = 0;
  virtual IIR_Boolean is_resolved() = 0;
  
  virtual IIR_Statement *convert_tree(plugin_class_factory *factory);
  virtual IIR_Statement *convert_node(IIR_Statement *node, plugin_class_factory *factory);
  /** For report and assertion statements this method is overloaded to
      return the report expression.  For anything else it returns 0. */
  virtual IIR_Statement *get_report_expression() = 0;

  virtual void copy_location( const IIR_Statement *, IIR_Statement *) = 0;
  /** For report and assertion statements this method is overloaded to
      return the report expression. For anything else it returns 0. */
  virtual IIR_Statement *get_severity_expression() = 0;
  
  /** This method will return precedence levels for any operator and
      literals.  The precedence levels are given in the LRM.  There are 8
      levels of precedence level 8 are the integer literals and all
      function calls which return value. All others take precedence values
      according to LRM. The higher the number , the higher the
      precedence. 
  */
  virtual Precedence get_precedence() const = 0;

  /**  This is overloaded for assertion and report statements.  Generate
      runtime error for anything else.  */
  virtual void set_assertion_condition( IIR_Statement * ) = 0;

  /**  This is overloaded for assertion and report statements.  Generate
      runtime error for anything else.  */
  virtual void set_report_expression( IIR_Statement * ) = 0;

  /**  This is overloaded for assertion and report statements.  Generate
      runtime error for anything else.  */
  virtual void set_severity_expression( IIR_Statement * ) = 0;

  virtual void set_reject_time_expression( IIR_Statement * ) = 0 ;
  virtual void set_target( IIR * ) = 0;
};

#endif
