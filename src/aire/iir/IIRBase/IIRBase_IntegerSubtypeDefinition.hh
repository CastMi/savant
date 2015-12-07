
#ifndef IIRBASE_INTEGER_SUBTYPE_DEFINITION_HH
#define IIRBASE_INTEGER_SUBTYPE_DEFINITION_HH

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
#include "IIRBase_IntegerTypeDefinition.hh"
#include "IIR_IntegerSubtypeDefinition.hh"

class IIR_FunctionDeclaration;
class IIR_IntegerSubtypeDefinition;

class IIRBase_IntegerSubtypeDefinition : public virtual IIRBase_IntegerTypeDefinition, public virtual IIR_IntegerSubtypeDefinition{

public:

  IIR_Kind get_kind() const override { return IIR_INTEGER_SUBTYPE_DEFINITION; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_IntegerSubtypeDefinition"); }

  void set_resolution_function( IIR_FunctionDeclarationRef );
  IIR_FunctionDeclarationRef get_resolution_function();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  IIR_Boolean is_subtype();

protected:
  
  IIRBase_IntegerSubtypeDefinition();
  virtual ~IIRBase_IntegerSubtypeDefinition() = 0;
    
private:
  IIR_FunctionDeclarationRef my_resolution_function;
};

typedef refcount<IIRBase_IntegerSubtypeDefinition> IIRBase_IntegerSubtypeDefinitionRef;

#endif
