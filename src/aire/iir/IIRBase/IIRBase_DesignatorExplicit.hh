
#ifndef IIRBASE_DESIGNATOR_EXPLICIT_HH
#define IIRBASE_DESIGNATOR_EXPLICIT_HH

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
#include "IIRBase_Designator.hh"
#include "IIR_DesignatorExplicit.hh"

class IIR_Signature;

class IIRBase_DesignatorExplicit : public virtual IIRBase_Designator, public virtual IIR_DesignatorExplicit{

public:
  IIR_Kind get_kind() const override { return IIR_DESIGNATOR_EXPLICIT; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_DesignatorExplicit"); }

  void set_name( IIRRef name );
  IIRRef get_name();

  void set_signature( IIR_SignatureRef signature );
  IIR_SignatureRef get_signature( );

  IIRRef convert_tree(plugin_class_factoryRef factory);

  IIR_Boolean is_resolved();
  IIR_Boolean is_signal();
  IIR_Boolean is_locally_static();
  IIR_Boolean is_above_attribute_found();

  IIR_SignalKind get_signal_kind();

  ostream &print( ostream &os );
  void publish_vhdl(ostream &);
protected:
  IIRBase_DesignatorExplicit();
  virtual ~IIRBase_DesignatorExplicit() = 0;
    
private:
  IIRRef name;
  IIR_SignatureRef signature;
};

typedef refcount<IIRBase_DesignatorExplicit> IIRBase_DesignatorExplicitRef;

#endif
