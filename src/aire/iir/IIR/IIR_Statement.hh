
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

#include "savant_config.hh"
#include "IIR.hh"

REF_FORWARD_DECL(IIR_Label);
REF_FORWARD_DECL(IIR_Name);

namespace savant {
  template <class type> class set;
}

class IIR_Statement : public virtual IIR{
public:
  virtual ~IIR_Statement() {}
    
  virtual void set_label( IIR_LabelRef label) = 0;
  virtual IIR_LabelRef get_label() const = 0;

  virtual savant::set<IIR_DeclarationRef> find_declarations( IIR_NameRef ) = 0;

  /** For assertion statements this method is overloaded to return the
      assertion condtion.  For anything else it returns 0. */
  virtual IIRRef get_assertion_condition() = 0;
  
  /** For report and assertion statements this method is overloaded to
      return the report expression.  For anything else it returns 0. */
  virtual IIRRef get_report_expression() = 0;

  /** For report and assertion statements this method is overloaded to
      return the report expression. For anything else it returns 0. */
  virtual IIRRef get_severity_expression() = 0;

  /**  This is overloaded for assertion and report statements.  Generate
      runtime error for anything else.  */
  virtual void set_assertion_condition( IIRRef ) = 0;

  /**  This is overloaded for assertion and report statements.  Generate
      runtime error for anything else.  */
  virtual void set_report_expression( IIRRef ) = 0;

  /**  This is overloaded for assertion and report statements.  Generate
      runtime error for anything else.  */
  virtual void set_severity_expression( IIRRef ) = 0;

  virtual void set_reject_time_expression( IIRRef ) = 0 ;
  virtual void set_target( IIRRef ) = 0;
};

typedef refcount<IIR_Statement> IIR_StatementRef;

#endif
