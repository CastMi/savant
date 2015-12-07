#ifndef IIRBASE_FLOATING_POINT_LITERAL_HH
#define IIRBASE_FLOATING_POINT_LITERAL_HH

// Copyright (c) The University of Cincinnati.  
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

#include "savant_config.hh"
#include "IIRBase_Literal.hh"
#include "IIR_FloatingPointLiteral.hh"

class IIR_FloatingPointLiteral;

class IIRBase_FloatingPointLiteral : public virtual IIRBase_Literal, public virtual IIR_FloatingPointLiteral{
  friend class VHDLParser;

public:
  IIR_Kind get_kind() const override { return IIR_FLOATING_POINT_LITERAL; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_FloatingPointLiteral"); }

  static IIR_FloatingPointLiteralRef get(IIR_Int32, IIR_CharRef,  IIR_Int32,
				       IIR_CharRef, IIR_Int32);

  const string print_value(IIR_Int32);

  void set_base(IIR_Int32);
  IIR_Int32 get_base();
  void set_mantissa(IIR_CharRef, IIR_Int32);
  IIR_CharRef get_mantissa();
  IIR_Int32 get_mantissa_length();
  void set_exponent(IIR_CharRef, IIR_Int32);
  IIR_CharRef get_exponent();
  IIR_Int32 get_exponent_length();
  IIR_FP64 get_floating_point_value();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  ostream &print( ostream & );
  void publish_vhdl(ostream &);

  IIR_Boolean is_negative();

protected:
  IIRBase_FloatingPointLiteral();
  virtual ~IIRBase_FloatingPointLiteral() = 0;
    
private:
  IIR_Int32 base;
  IIR_CharRef mantissa;
  IIR_Int32 mantissa_length;
  IIR_CharRef exponent;
  IIR_Int32 exponent_length;
};

typedef refcount<IIRBase_FloatingPointLiteral> IIRBase_FloatingPointLiteralRef;

#endif
