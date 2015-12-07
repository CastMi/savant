
#ifndef IIRBASE_SLICE_NAME_HH
#define IIRBASE_SLICE_NAME_HH

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
#include "IIRBase_Name.hh"
#include "IIR_SliceName.hh"

class IIRBase_SliceName : public virtual IIRBase_Name, public virtual IIR_SliceName{

public:

  IIR_Kind get_kind() const override { return IIR_SLICE_NAME; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_SliceName"); }

  void set_suffix( IIRRef suffix);
  IIRRef get_suffix();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  IIR_Boolean is_resolved();
  IIR_Boolean is_variable();

  // Override the undefined definition in IIRBase_Name
  void set_subtype(IIR_TypeDefinitionRef type) { IIRBase::set_subtype(type); }
  
  ostream &print( ostream &os );

  IIR_DeclarationRef get_prefix_declaration();
  void publish_vhdl(ostream &);
protected:
  
  IIRBase_SliceName();
  virtual ~IIRBase_SliceName() = 0;
    
private:
  
  IIRRef    suffix;

};

typedef refcount<IIRBase_SliceName> IIRBase_SliceNameRef;

#endif
