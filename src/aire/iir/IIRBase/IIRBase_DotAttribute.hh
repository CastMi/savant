#ifndef IIRBASE_DOT_ATTRIBUTE_HH
#define IIRBASE_DOT_ATTRIBUTE_HH

// Copyright (c) 2002-2003 The University of Cincinnati.
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

// Authors: Harish Venkataramani venkath@ececs.uc.edu

//---------------------------------------------------------------------------

#include "IIR_DotAttribute.hh"
#include "IIRBase_Attribute.hh"

/** The extension base for dot attribute of quantities (Q'Dot).  For a
    Quantity Q, the attribute Q'Dot yields a quantity of type as Q. */
class IIRBase_DotAttribute : public virtual IIR_DotAttribute, public virtual IIRBase_Attribute {

public:
  IIR_Kind get_kind() const {
    return IIR_DOT_ATTRIBUTE;
  }

  const IIR_Char *get_kind_text() const {
    return "IIR_DotAttribute";
  }

  /** This returns an IIR_TextLiteral when a Dot attribute is
      instantiated. */
  IIR_Identifier *build_attribute_name();
  void publish_vhdl(ostream &);
protected:
  IIRBase_DotAttribute();
  virtual ~IIRBase_DotAttribute() = 0;

private:
};
#endif

