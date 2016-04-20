#ifndef IIR_SIGNATURE_HH
#define IIR_SIGNATURE_HH

// Copyright (c) 1996-2003 The University of Cincinnati.  
// All rights reserved.

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
// SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR
// NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
// LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING OR DISTRIBUTING
// THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the U.S., and
// the terms of this license.

// You may modify, distribute, and use the software contained in this package
// under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE" version 2, June
// 1991. A copy of this license agreement can be found in the file "LGPL",
// distributed with this archive.

// Authors: Philip A. Wilsey	philip.wilsey@ieee.org
//          Dale E. Martin	dmartin@cliftonlabs.com

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIR_TypeDefinition.hh"

class IIR_DesignatorList;
class IIR_TypeDefinition;

class IIR_Signature : public virtual IIR_TypeDefinition{

public:
  virtual ~IIR_Signature() {}    

  // List accessor(s)
  virtual IIR_DesignatorList    *get_argument_type_list() = 0;
  virtual void                  set_argument_type_list(IIR_DesignatorList *) = 0;

  virtual void set_return_type( IIR_TypeDefinition *return_type ) = 0;
  virtual IIR_TypeDefinition *get_return_type() = 0;
};
#endif
