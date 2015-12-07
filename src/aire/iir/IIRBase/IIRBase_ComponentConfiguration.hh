
#ifndef IIRBASE_COMPONENT_CONFIGURATION_HH
#define IIRBASE_COMPONENT_CONFIGURATION_HH

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
#include "IIRBase_ConfigurationItem.hh"
#include "IIR_ComponentConfiguration.hh"
#include "IIR_AssociationList.hh"

class IIR_LibraryUnit;
class IIR_BlockConfiguration;
class IIR_DesignatorList;
class IIR_AssociationList;
class IIR_LibraryUnit;

class IIRBase_ComponentConfiguration : public virtual IIRBase_ConfigurationItem, public virtual IIR_ComponentConfiguration{

public:
  // List Accessor(s)
  IIR_DesignatorListRef  get_instantiation_list();
  IIR_AssociationListRef get_generic_map_aspect();
  IIR_AssociationListRef get_port_map_aspect();
  void                   set_instantiation_list(IIR_DesignatorListRef new_instantiation_list);
  void                   set_generic_map_aspect(IIR_AssociationListRef new_generic_map_aspect);
  void                   set_port_map_aspect(IIR_AssociationListRef new_port_map_aspect);

  IIR_Kind get_kind() const override { return IIR_COMPONENT_CONFIGURATION; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_ComponentConfiguration"); }

  /**
     Gets the component name that was specified for this configuration.
     Prior to type check, this node will contain a descendant of IIR_Name.
     After type checking, it will contain an IIR_ComponentDeclaration.
  */
  IIRRef get_component_name();
  void set_component_name( IIRRef component_name );
  
  /**
     Gets the entity aspect associated with the component specified.  This
     maps to the binding indication as specified by the LRM.  Will return
     NULL for "open" binding.

     If there was no binding indication specified explicitly, then the
     default rules specified in section 5.2.2 of the '93 LRM.
  */
  IIR_LibraryUnitRef get_entity_aspect();
  void set_entity_aspect( IIR_LibraryUnitRef entity_aspect );

  void set_block_configuration( IIR_BlockConfigurationRef block_configuration );
  IIR_BlockConfigurationRef get_block_configuration();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  IIR_Boolean is_resolved();
  void publish_vhdl(ostream &);
protected:
  IIRBase_ComponentConfiguration();
  virtual ~IIRBase_ComponentConfiguration() = 0;
    
private:
  // List Variable(s)
  /**
     Holds the list of component designators specified in the component configuration.
  */
  IIR_DesignatorListRef  instantiation_list;

  /**
     Holds the generic map specified for the component configuration.
  */
  IIR_AssociationListRef generic_map_aspect;

  /**
     Holds the port map specified for the component configuration.
  */
  IIR_AssociationListRef port_map_aspect;

  IIRRef my_component_name;
  IIR_LibraryUnitRef my_entity_aspect;
  IIR_BlockConfigurationRef my_block_configuration;
};

typedef refcount<IIRBase_ComponentConfiguration> IIRBase_ComponentConfigurationRef;

#endif
