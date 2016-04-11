#ifndef IIRBASE_SHARED_VARIABLE_DECLARATION_HH
#define IIRBASE_SHARED_VARIABLE_DECLARATION_HH

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
#include "IIR_SharedVariableDeclaration.hh"

class IIRBase_SharedVariableDeclaration : public virtual IIRBase_ObjectDeclaration, public virtual IIR_SharedVariableDeclaration{
public:

  IIR_Kind get_kind() const {return IIR_SHARED_VARIABLE_DECLARATION;}
  const IIR_Char *get_kind_text() const {return "IIR_SharedVariableDeclaration";}

  void set_value(IIR* value);
  IIR* get_value();

  IIR *convert_tree(plugin_class_factory *factory);

  declaration_type get_declaration_type();

  IIR_Boolean is_variable(){ return TRUE; }
  void publish_vhdl_decl(ostream &);
protected:
  
  IIRBase_SharedVariableDeclaration();
  virtual ~IIRBase_SharedVariableDeclaration() = 0;
    
private:
  
  IIR* value;

};

#endif
