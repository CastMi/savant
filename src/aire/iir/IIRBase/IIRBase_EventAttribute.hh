
#ifndef IIRBASE_EVENT_ATTRIBUTE_HH
#define IIRBASE_EVENT_ATTRIBUTE_HH

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

#include "savant_config.hh"
#include "IIRBase_Attribute.hh"
#include "IIR_EventAttribute.hh"

REF_FORWARD_DECL(IIR_VariableDeclaration);
class IIR_TypeDefinition;

class IIRBase_EventAttribute : public virtual IIRBase_Attribute,
			       public virtual IIR_EventAttribute{
public:
  IIR_Kind get_kind() const override { return IIR_EVENT_ATTRIBUTE; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_EventAttribute"); }

  IIR_TypeDefinitionRef get_subtype();
  IIR_Boolean is_function_attribute(){ return TRUE; }

  IIR_TextLiteralRef build_attribute_name();
  IIR_VariableDeclarationRef build_implicit_variable( const string &declarator,IIR_TypeDefinitionRef );

  void publish_vhdl(ostream &);
protected:
  IIRBase_EventAttribute();
  virtual ~IIRBase_EventAttribute() = 0;
    
private:
};

typedef refcount<IIRBase_EventAttribute> IIRBase_EventAttributeRef;

#endif
