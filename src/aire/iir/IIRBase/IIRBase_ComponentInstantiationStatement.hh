
#ifndef IIRBASE_COMPONENT_INSTANTIATION_STATEMENT_HH
#define IIRBASE_COMPONENT_INSTANTIATION_STATEMENT_HH

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

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIRBase_ConcurrentStatement.hh"
#include "IIR_ComponentInstantiationStatement.hh"

class IIR_AssociationList;

class IIRBase_ComponentInstantiationStatement : public virtual IIRBase_ConcurrentStatement, public virtual IIR_ComponentInstantiationStatement{

public:
  // List Accessor(s)
  IIR_AssociationListRef get_generic_map_aspect();
  IIR_AssociationListRef get_port_map_aspect();
  void                   set_generic_map_aspect(IIR_AssociationListRef new_generic_map_aspect);
  void                   set_port_map_aspect(IIR_AssociationListRef new_port_map_aspect);

  IIR_Kind get_kind() const override { return IIR_COMPONENT_INSTANTIATION_STATEMENT; }
  IIR_CharConstRef get_kind_text() const override {return IIR_CharConstRef("IIR_ComponentInstantiationStatement"); }

  void set_instantiated_unit( IIRRef instantiated_unit );
  IIRRef get_instantiated_unit();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  /** This returns the configuration for this component.  It can be an
      IIR_ConfigurationSpecification, or an IIR_ComponentConfiguration. */
  IIRRef get_configuration();
  void set_configuration( IIRRef new_config );

  void publish_vhdl(ostream &);
protected:
  IIRBase_ComponentInstantiationStatement();
  virtual ~IIRBase_ComponentInstantiationStatement() = 0;
    
private:
  // List Variable(s)
  IIR_AssociationListRef generic_map_aspect;
  IIR_AssociationListRef port_map_aspect;

  IIRRef my_instantiated_unit;
  IIRRef my_configuration;
};

typedef refcount<IIRBase_ComponentInstantiationStatement> IIRBase_ComponentInstantiationStatementRef;

#endif
