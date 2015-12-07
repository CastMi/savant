
#ifndef IIR_CONFIGURATION_SPECIFICATION_HH
#define IIR_CONFIGURATION_SPECIFICATION_HH

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
#include "IIR_Declaration.hh"

REF_FORWARD_DECL(IIR_DesignatorList);
REF_FORWARD_DECL(IIR_AssociationList);
REF_FORWARD_DECL(IIR_LibraryUnit);

class IIR_ConfigurationSpecification : public virtual IIR_Declaration{

public:
  virtual ~IIR_ConfigurationSpecification() {}    

  // List accessor(s)
  virtual IIR_DesignatorListRef  get_instantiation_list() = 0;
  virtual IIR_AssociationListRef get_generic_map_aspect() = 0;
  virtual IIR_AssociationListRef get_port_map_aspect() = 0;
  virtual void                   set_instantiation_list(IIR_DesignatorListRef new_instantiation_list) = 0;
  virtual void                   set_generic_map_aspect(IIR_AssociationListRef new_generic_map_aspect) = 0;
  virtual void                   set_port_map_aspect(IIR_AssociationListRef new_port_map_aspect) = 0;

  virtual void set_component_name(IIRRef component_name) = 0;
  virtual IIRRef get_component_name() = 0;

  /**
     Gets the entity aspect associated with the component specified.  This
     maps to the binding indication as specified by the LRM.  Will return
     NULL for "open" binding.
  */
  virtual IIR_LibraryUnitRef get_entity_aspect() = 0;
  virtual void set_entity_aspect(IIR_LibraryUnitRef entity_aspect) = 0;
};

typedef refcount<IIR_ConfigurationSpecification> IIR_ConfigurationSpecificationRef;

#endif
