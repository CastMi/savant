#ifndef IIR_QUANTITY_DECLARATION_HH
#define IIR_QUANTITY_DECLARATION_HH

// Copyright (c) 2002 The University of Cincinnati.
// All rights reserved.
 
// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
// SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
// OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
// LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING OR
// DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the U.S.,
// and the terms of this license.

// You may modify, distribute, and use the software contained in this
// package under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE"
// version 2, June 1991. A copy of this license agreement can be found in
// the file "LGPL", distributed with this archive.
 
// Author: Harish Venkataramani venkath@ececs.uc.edu

//---------------------------------------------------------------------------

#include "IIR_ObjectDeclaration.hh"

class IIR_QuantityDeclaration : public virtual IIR_ObjectDeclaration {

public:
  virtual ~IIR_QuantityDeclaration() {};
};

#endif
