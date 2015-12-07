
#ifndef IIR_BLOCK_CONFIGURATION_HH
#define IIR_BLOCK_CONFIGURATION_HH

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
#include "IIR_ConfigurationItem.hh"

REF_FORWARD_DECL(IIR_DeclarationList);
REF_FORWARD_DECL(IIR_ConfigurationItemList);

class IIR_BlockConfiguration : public virtual IIR_ConfigurationItem{

public:
  virtual ~IIR_BlockConfiguration() {}
    
  // List accessor(s)
  virtual IIR_DeclarationListRef        get_use_clause_list() = 0;
  virtual IIR_ConfigurationItemListRef  get_configuration_item_list() = 0;
  virtual void                          set_use_clause_list( IIR_DeclarationListRef ) = 0;
  virtual void                          set_configuration_item_list( IIR_ConfigurationItemListRef ) = 0;

  virtual void set_block_specification( IIRRef block_specification ) = 0;
  virtual IIRRef get_block_specification() = 0;
};

typedef refcount<IIR_BlockConfiguration> IIR_BlockConfigurationRef;

#endif
