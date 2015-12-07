#ifndef IIRBASE_STRING_LITERAL_HH
#define IIRBASE_STRING_LITERAL_HH

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
#include "IIRBase_TextLiteral.hh"
#include "IIR_StringLiteral.hh"

class IIRBase_StringLiteral : public virtual IIRBase_TextLiteral, public virtual IIR_StringLiteral{
public:

  IIR_Kind get_kind() const override { return IIR_STRING_LITERAL; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_StringLiteral"); }

  IIR_Boolean is_array_type(){ return TRUE; }

  static IIR_StringLiteralRef get( std::string value, plugin_class_factoryRef factory);
protected:
  
  IIRBase_StringLiteral();
  virtual ~IIRBase_StringLiteral() = 0;
    
private:

};

typedef refcount<IIRBase_StringLiteral> IIRBase_StringLiteralRef;

#endif
