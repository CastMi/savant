
#ifndef IIRBASE_FILE_DECLARATION_HH
#define IIRBASE_FILE_DECLARATION_HH

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
#include "IIR_FileDeclaration.hh"

class IIRBase_FileDeclaration : public virtual IIRBase_ObjectDeclaration, public virtual IIR_FileDeclaration{

public:
  IIR_Kind get_kind() const override { return IIR_FILE_DECLARATION; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_FileDeclaration"); }

  void set_file_open_expression(IIRRef file_open_expression);
  IIRRef get_file_open_expression();
  void set_file_logical_name(IIRRef file_logical_name);
  IIRRef get_file_logical_name();

  IIRRef convert_tree(plugin_class_factoryRef factory);
  
  declaration_type get_declaration_type();

  IIR_Boolean is_file(){ return TRUE; }
  void publish_vhdl_decl(ostream &);
protected:
  IIRBase_FileDeclaration();
  virtual ~IIRBase_FileDeclaration() = 0;
    
private:
  IIRRef file_open_expression;
  IIRRef file_logical_name;
};

typedef refcount<IIRBase_FileDeclaration> IIRBase_FileDeclarationRef;

#endif
