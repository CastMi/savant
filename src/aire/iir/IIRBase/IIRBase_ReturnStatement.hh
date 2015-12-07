
#ifndef IIRBASE_RETURN_STATEMENT_HH
#define IIRBASE_RETURN_STATEMENT_HH

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
#include "IIRBase_SequentialStatement.hh"
#include "IIR_ReturnStatement.hh"

class IIR_SubprogramDeclaration;

class IIRBase_ReturnStatement : public virtual IIRBase_SequentialStatement, public virtual IIR_ReturnStatement{

public:

  IIR_Kind get_kind() const override { return IIR_RETURN_STATEMENT; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_ReturnStatement"); }

  void set_enclosing_subprogram( IIR_SubprogramDeclarationRef
				 enclosing_subprogram);
  IIR_SubprogramDeclarationRef get_enclosing_subprogram();

  void set_return_expression( IIRRef return_expression);
  IIRRef get_return_expression();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  IIR_Boolean is_resolved();

  void publish_vhdl(ostream &);
protected:
  
  IIRBase_ReturnStatement();
  virtual ~IIRBase_ReturnStatement() = 0;
    
private:
  
  IIR_SubprogramDeclarationRef enclosing_subprogram;
  IIRRef return_expression;

};

typedef refcount<IIRBase_ReturnStatement> IIRBase_ReturnStatementRef;

#endif
