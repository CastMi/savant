
#ifndef IIRBASE_DISCONNECT_SPECIFICATION_HH
#define IIRBASE_DISCONNECT_SPECIFICATION_HH

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
#include "IIRBase_Declaration.hh"
#include "IIR_DisconnectSpecification.hh"

class IIR_TypeDefinition;
class IIR_DesignatorList;
class IIR_TypeDefinition;

class IIRBase_DisconnectSpecification : public virtual IIRBase_Declaration, public virtual IIR_DisconnectSpecification{

public:
  // List Accessor(s)
  IIR_DesignatorListRef get_guarded_signal_list();
  void                  set_guarded_signal_list(IIR_DesignatorListRef new_guarded_signal_list);

  IIR_Kind get_kind() const override { return IIR_DISCONNECT_SPECIFICATION; }
  IIR_CharConstRef get_kind_text() const override {return IIR_CharConstRef("IIR_DisconnectSpecification"); }

  void set_type_mark( IIR_TypeDefinitionRef type_definition );
  IIR_TypeDefinitionRef get_type_mark();

  void set_time_expression( IIRRef time_expression);
  IIRRef get_time_expression();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  void publish_vhdl(ostream &);
  void publish_vhdl_decl(ostream &);
protected:
  IIRBase_DisconnectSpecification();
  virtual ~IIRBase_DisconnectSpecification() = 0;
    
private:
  // List Variable(s)
  IIR_DesignatorListRef guarded_signal_list;

  IIR_TypeDefinitionRef my_type_mark;
  IIRRef                my_time_expression;
};

typedef refcount<IIRBase_DisconnectSpecification> IIRBase_DisconnectSpecificationRef;

#endif
