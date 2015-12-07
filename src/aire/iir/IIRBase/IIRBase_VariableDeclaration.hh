
#ifndef IIRBASE_VARIABLE_DECLARATION_HH
#define IIRBASE_VARIABLE_DECLARATION_HH

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
#include "IIRBase_ObjectDeclaration.hh"
#include "IIR_VariableDeclaration.hh"

class IIRBase_VariableDeclaration : public virtual IIRBase_ObjectDeclaration, public virtual IIR_VariableDeclaration{
public:
  IIR_Kind get_kind() const override { return IIR_VARIABLE_DECLARATION; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_VariableDeclaration"); }

  void set_value(IIRRef value);
  IIRRef get_value();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  declaration_type get_declaration_type();

  IIR_Boolean is_variable(){ return TRUE; }
  void publish_vhdl_decl(ostream &);
protected:
  
  IIRBase_VariableDeclaration();
  virtual ~IIRBase_VariableDeclaration() = 0;
    
private:
  
  IIRRef value;

};

typedef refcount<IIRBase_VariableDeclaration> IIRBase_VariableDeclarationRef;

#endif
