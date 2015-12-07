
#ifndef IIRBASE_FLOATING_POINT_LITERAL32_HH
#define IIRBASE_FLOATING_POINT_LITERAL32_HH

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
#include "IIR_FloatingPointLiteral32.hh"

class  IIR_FloatingPointLiteral32;

class IIRBase_FloatingPointLiteral32 : public virtual IIRBase_Literal, public virtual IIR_FloatingPointLiteral32{

public:
  IIR_Kind get_kind() const override { return IIR_FLOATING_POINT_LITERAL32; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_FloatingPointLiteral32"); }

  static IIR_FloatingPointLiteral32Ref get_value(IIR_FP32);

  IIR_FP32 value();
  void set_value(IIR_FP32);

  IIRRef convert_tree(plugin_class_factoryRef factory);

  void publish_vhdl(ostream &);
protected:
  IIRBase_FloatingPointLiteral32();
  virtual ~IIRBase_FloatingPointLiteral32() = 0;
    
private:
  IIR_FP32 val;
};

typedef refcount<IIRBase_FloatingPointLiteral32> IIRBase_FloatingPointLiteral32Ref;

#endif
