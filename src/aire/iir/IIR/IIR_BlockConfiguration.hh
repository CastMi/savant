
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

#include "IIR_ConfigurationItem.hh"

class IIR_DeclarationList;
class IIR_ConfigurationItemList;
class IIR_Statement;

class IIR_BlockConfiguration : public virtual IIR_ConfigurationItem{

public:
  virtual ~IIR_BlockConfiguration() {}
    
  // List accessor(s)
  virtual IIR_DeclarationList           *get_use_clause_list() = 0;
  virtual IIR_ConfigurationItemList     *get_configuration_item_list() = 0;
  virtual void                          set_use_clause_list(IIR_DeclarationList *) = 0;
  virtual void                          set_configuration_item_list(IIR_ConfigurationItemList *) = 0;

  virtual void set_block_specification( IIR_Statement *block_specification ) = 0;
  virtual IIR_Statement* get_block_specification() = 0;
};
#endif
