
#ifndef IIRBASE_LTF_ATTRIBUTE_HH
#define IIRBASE_LTF_ATTRIBUTE_HH

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

// Authors: Prashanth Cherukuri cherukps@ececs.uc.edu

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIRBase_Attribute.hh"
#include "IIR_LTFAttribute.hh"
#include "IRBasicDataTypes.hh"

/** This class describes the 'ltf attribute.  For a scalar quantity Q, the
    attribute Q'ltf(num, den) yields a quantity whose type is the base type
    of Q and value is the Laplace transform of Q.num and den are the
    numerator and denominator polynomials, specified as real_vector
    arrays. */
class IIRBase_LTFAttribute  : public virtual IIR_LTFAttribute, public virtual IIRBase_Attribute {

public:
  /** Returns the IIR_Kind of this node. */
  IIR_Kind get_kind() const override {
    return IIR_LTF_ATTRIBUTE;
  }
  /** Returns the kind of this node in text form. */
  IIR_CharConstRef get_kind_text() const override {
    return IIR_CharConstRef("IIR_LTFAttribute");
  }
  /** Set the numerator coefficients from the static expression.  */
  void set_num(IIRRef numerator);
  /** Return the numerator coefficients.  */
  IIRRef get_num();
  /* Set the denominator coefficients from the static expression.  */
  void set_den(IIRRef denominator);
  /* Return the denominator coefficients.  */
  IIRRef get_den();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  /** This returns an IIR_TextLiteral when the LTF attribute is  instantiated. */
  IIR_TextLiteralRef build_attribute_name();

  void publish_vhdl(ostream&);
protected:
  IIRBase_LTFAttribute();
  virtual ~IIRBase_LTFAttribute() = 0;

private:
  IIRRef numerator;
  IIRRef denominator;
};

typedef refcount<IIRBase_LTFAttribute> IIRBase_LTFAttributeRef;

#endif
