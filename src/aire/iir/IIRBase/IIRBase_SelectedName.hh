#ifndef IIRBASE_SELECTED_NAME_HH
#define IIRBASE_SELECTED_NAME_HH

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

#include "IIRBase_Name.hh"
#include "IIR_SelectedName.hh"

class IIRBase_SelectedName : public virtual IIRBase_Name, public virtual IIR_SelectedName{
public:

  IIR_Kind get_kind() const {return IIR_SELECTED_NAME;}

  const IIR_Char *get_kind_text() const {return "IIR_SelectedName";}

  void set_suffix( IIR_Statement *suffix );
  IIR_Statement *get_suffix() const;

  IIR_SelectedName *convert_tree(plugin_class_factory *factory);

  IIR_Boolean is_resolved() const;
  IIR_Boolean is_signal() const;
  IIR_Boolean is_entity_declaration() const;
  IIR_Boolean is_object() const;
  IIR_Boolean is_type() const;
  IIR_Boolean is_variable() const;
  
  IIR_SignalKind get_signal_kind() const;
  IIR_TypeDefinition *get_subtype();

  ostream &print( ostream & );
  
  IIR_Declaration *get_prefix_declaration();
  void publish_vhdl(ostream &);
protected:
  
  IIRBase_SelectedName();
  virtual ~IIRBase_SelectedName() = 0;
    
private:
  IIR_Statement *suffix;
};

#endif
