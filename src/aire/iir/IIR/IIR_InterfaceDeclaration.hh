
#ifndef IIR_INTERFACE_DECLARATION_HH
#define IIR_INTERFACE_DECLARATION_HH

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
#include "IIR_ObjectDeclaration.hh"

class IIR_InterfaceDeclaration : public virtual IIR_ObjectDeclaration{

public:
  virtual ~IIR_InterfaceDeclaration() {}
    
  virtual void set_mode(IIR_Mode mode) = 0;
  virtual IIR_Mode get_mode() = 0;

  virtual void set_value(IIR* value) = 0;
  virtual IIR* get_value() = 0;

  // Used by the parser to give enough context to do proper
  // type checking on interface declarations. (For instance, a signal
  // PARAMETER can't have initialization, but a signal PORT can.)
  enum _InterfaceListType {
    PORT_INTERFACE_LIST, // entity port
    GENERIC_INTERFACE_LIST, // entity generic
    PARAMETER_INTERFACE_LIST // functions and procedures
  };
};

typedef refcount<IIR_InterfaceDeclaration> IIR_InterfaceDeclarationRef;

#endif
