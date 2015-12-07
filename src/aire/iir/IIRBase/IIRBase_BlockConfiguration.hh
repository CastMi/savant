
#ifndef IIRBASE_BLOCK_CONFIGURATION_HH
#define IIRBASE_BLOCK_CONFIGURATION_HH

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
#include "IIR_BlockConfiguration.hh"

class IIR_DeclarationList;
class IIR_ConfigurationItemList;

class IIRBase_BlockConfiguration : public virtual IIRBase_ConfigurationItem,
				   public virtual IIR_BlockConfiguration{

public:
  // List Accessor(s)
  IIR_DeclarationListRef       get_use_clause_list();
  IIR_ConfigurationItemListRef get_configuration_item_list();
  void                         set_use_clause_list(IIR_DeclarationListRef new_use_clause_list);
  void                         set_configuration_item_list(IIR_ConfigurationItemListRef new_configuration_item_list);

  IIR_Kind get_kind() const override { return IIR_BLOCK_CONFIGURATION; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_BlockConfiguration"); }

  void set_block_specification( IIRRef block_specification );
  IIRRef get_block_specification();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  ostream &print( ostream &os );
  void publish_vhdl(ostream &);
protected:
  IIRBase_BlockConfiguration();
  virtual ~IIRBase_BlockConfiguration() = 0;
    
private:
  // List Variable(s)
  IIR_DeclarationListRef       use_clause_list;
  IIR_ConfigurationItemListRef configuration_item_list;
  IIRRef block_specification;
};

typedef refcount<IIRBase_BlockConfiguration> IIRBase_BlockConfigurationRef;

#endif
