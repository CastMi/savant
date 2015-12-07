
#ifndef IIRBASE_FUNCTION_CALL_HH
#define IIRBASE_FUNCTION_CALL_HH

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
#include "IIR_FunctionCall.hh"

class IIR_SubprogramDeclaration;
class IIR_AssociationList;

class IIRBase_FunctionCall : public virtual IIRBase_Expression,
			     public virtual IIR_FunctionCall{
public:
  // List Accessor(s)
  IIR_AssociationListRef get_parameter_association_list();
  void                set_parameter_association_list(IIR_AssociationListRef new_parameter_association_list);

  IIR_Kind get_kind() const override { return IIR_FUNCTION_CALL; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_FunctionCall"); }

  void set_implementation( IIR_SubprogramDeclarationRef implementation );
  IIR_SubprogramDeclarationRef get_implementation();

  IIRRef convert_tree(plugin_class_factoryRef factory);
  IIR_Boolean is_resolved(){ return TRUE; }
  
  IIR_Boolean is_locally_static();
  
  IIR_TypeDefinitionRef get_subtype();

  ostream &print( ostream & );
  void publish_vhdl(ostream &);
protected:
  IIRBase_FunctionCall();
  virtual ~IIRBase_FunctionCall() = 0;
    
private:
  // List Variable(s)
  IIR_AssociationListRef parameter_association_list;

  IIR_SubprogramDeclarationRef implementation;

};

typedef refcount<IIRBase_FunctionCall> IIRBase_FunctionCallRef;

#endif
