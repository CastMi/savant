
#ifndef IIRBASE_QUALIFIED_EXPRESSION_HH
#define IIRBASE_QUALIFIED_EXPRESSION_HH

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
#include "IIRBase_Expression.hh"
#include "IIR_QualifiedExpression.hh"

class IIR_TypeDefinition;

class IIRBase_QualifiedExpression : public virtual IIRBase_Expression, public virtual IIR_QualifiedExpression{

public:

  IIR_Kind get_kind() const override { return IIR_QUALIFIED_EXPRESSION; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_QualifiedExpression"); }

  void set_type_mark( IIR_TypeDefinitionRef type_mark);
  IIR_TypeDefinitionRef get_type_mark();
  void set_expression(IIRRef expression);
  IIRRef get_expression();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  IIR_Boolean is_locally_static();
  IIR_Boolean is_resolved();

  IIR_TypeDefinitionRef get_subtype();

  ostream &print( ostream &os );
  void publish_vhdl(ostream &);
protected:
  
  IIRBase_QualifiedExpression();
  virtual ~IIRBase_QualifiedExpression() = 0;
    
private:
  
  IIRRef expression;
  IIR_TypeDefinitionRef type_mark;

};

typedef refcount<IIRBase_QualifiedExpression> IIRBase_QualifiedExpressionRef;

#endif
