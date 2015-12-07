
#ifndef IIRBASE_WAVEFORM_ELEMENT_HH
#define IIRBASE_WAVEFORM_ELEMENT_HH

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
#include "IIRBase_Tuple.hh"
#include "IIR_WaveformElement.hh"

class IIR_WaveformElement;

class IIRBase_WaveformElement : public virtual IIRBase_Tuple, public virtual IIR_WaveformElement{
public:

  IIR_Kind get_kind() const override {
    return IIR_WAVEFORM_ELEMENT;
  }
  IIR_CharConstRef get_kind_text() const override {
    return IIR_CharConstRef("IIR_WaveformElement");
  }

  void set_value( IIRRef value);
  IIRRef get_value();
  void set_time( IIRRef time);
  IIRRef get_time();
  void set_next( IIR_WaveformElementRef next);
  IIR_WaveformElementRef get_next();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  IIR_Boolean is_resolved();
  IIR_Boolean is_above_attribute_found();

  ostream &print( ostream &os );

  void publish_vhdl(ostream &);
protected:
  
  IIRBase_WaveformElement();
  virtual ~IIRBase_WaveformElement() = 0;
    
private:
  
  IIRRef value;
  IIRRef time;
  IIR_WaveformElementRef next;

};

typedef refcount<IIRBase_WaveformElement> IIRBase_WaveformElementRef;

#endif
