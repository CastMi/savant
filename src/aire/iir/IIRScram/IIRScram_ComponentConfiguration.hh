#ifndef IIRSCRAM_COMPONENT_CONFIGURATION_HH
#define IIRSCRAM_COMPONENT_CONFIGURATION_HH

// Copyright (c) 1996-2000 The University of Cincinnati.  
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
//          Umesh Kumar V. Rajasekaran urajasek@ece.uc.edu
//          Narayanan Thondugulam nthondug@ece.uc.edu

//---------------------------------------------------------------------------

#include "IIRScram_ConfigurationItem.hh"
#include "IIRBase_ComponentConfiguration.hh"

class IIRScram_BlockConfiguration;
class IIRScram_DesignatorList;
class IIRScram_LibraryUnit;

class IIRScram_ComponentConfiguration : public virtual IIRScram_ConfigurationItem, public virtual IIRBase_ComponentConfiguration {

public:
  IIRScram_ComponentConfiguration();  
  virtual ~IIRScram_ComponentConfiguration();

  void _type_check_configuration_item( IIRScram_List<IIRScram_Statement> *, IIRScram * );

  IIRScram *_get_component_name( );
  void _set_component_name( IIRScram * );
  IIRScram_LibraryUnit *_get_entity_aspect();

  IIRScram_DesignatorList *     _get_instantiation_list();
  IIRScram_AssociationList *    _get_generic_map_aspect();
  IIRScram_AssociationList *    _get_port_map_aspect();
  IIRScram_BlockConfiguration * _get_block_configuration();
};

#endif
