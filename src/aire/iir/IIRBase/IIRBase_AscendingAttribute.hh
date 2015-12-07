
#ifndef IIRBASE_ASCENDING_ATTRIBUTE_HH
#define IIRBASE_ASCENDING_ATTRIBUTE_HH

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
#include "IIR_AscendingAttribute.hh"

class IIRBase_AscendingAttribute : public virtual IIRBase_Attribute,
				   public virtual IIR_AscendingAttribute{

public:
  IIR_Kind get_kind() const override { return IIR_ASCENDING_ATTRIBUTE; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_AscendingAttribute");}

  void set_suffix(IIRRef suffix);
  IIRRef get_suffix();

  IIR_TypeDefinitionRef get_subtype();
  IIRRef convert_tree(plugin_class_factoryRef factory);

  IIR_Boolean is_value_attribute(){ return TRUE; }
  IIR_Boolean has_suffix(){ return TRUE; }
 
  IIR_TextLiteralRef build_attribute_name();
  void set_declaration( IIR_DeclarationRef	 );
  void publish_vhdl(ostream &);
protected:
  IIRBase_AscendingAttribute();
  virtual ~IIRBase_AscendingAttribute() = 0;
    
private:
  IIRRef suffix;
};

typedef refcount<IIRBase_AscendingAttribute> IIRBase_AscendingAttributeRef;

#endif
