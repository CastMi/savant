
#ifndef IIR_GENERIC_LIST_HH
#define IIR_GENERIC_LIST_HH

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
#include "IIR_InterfaceList.hh"
#include "IIR_ConstantInterfaceDeclaration.hh"

class IIR_GenericList : public virtual IIR_InterfaceList{

public:
  virtual ~IIR_GenericList() {}
    
  virtual void prepend( IIR_ConstantInterfaceDeclarationRef element) = 0;

  virtual void append( IIR_ConstantInterfaceDeclarationRef element) = 0;

  virtual IIR_Boolean insert_after( IIR_ConstantInterfaceDeclarationRef existing_element,
				    IIR_ConstantInterfaceDeclarationRef new_element) = 0;

  virtual IIR_Boolean insert_before_element( IIR_ConstantInterfaceDeclarationRef existing_element, 
				     IIR_ConstantInterfaceDeclarationRef new_element) = 0;

  virtual IIRRef successor( IIR_ConstantInterfaceDeclarationRef existing_element) = 0;
  virtual IIRRef predecessor( IIR_ConstantInterfaceDeclarationRef element ) = 0;
  virtual IIRRef first( ) = 0;
  virtual IIRRef get_nth_element( IIR_Int32 ) = 0;
  virtual IIRRef last() = 0;

  virtual IIR_Int32 get_position( IIR_ConstantInterfaceDeclarationRef element ) = 0;
};

typedef refcount<IIR_GenericList> IIR_GenericListRef;

#endif
