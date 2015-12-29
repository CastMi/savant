
#ifndef IIRBASE_CONDITIONAL_WAVEFORM_HH
#define IIRBASE_CONDITIONAL_WAVEFORM_HH

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
#include "IIRBase_Tuple.hh"
#include "IIR_ConditionalWaveform.hh"

class IIR_WaveformList;
class IIRBase_ConditionalWaveform : public virtual IIRBase_Tuple, public virtual IIR_ConditionalWaveform{

public:
  // List Accessor(s)
  IIR_WaveformListRef get_waveform();
  void             set_waveform(IIR_WaveformListRef new_waveform);

  IIR_Kind get_kind() const override { return IIR_CONDITIONAL_WAVEFORM; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_ConditionalWaveform"); }

  void set_condition( IIRRef condition );
  IIRRef get_condition();

  IIRRef convert_tree(plugin_class_factoryRef factory);
 
  IIR_Boolean is_resolved();

  ostream &print( ostream & );
  void publish_vhdl(ostream &);
protected:
  IIRBase_ConditionalWaveform();
  virtual ~IIRBase_ConditionalWaveform() = 0;
    
private:
  // List Variable(s)
  IIR_WaveformListRef waveform;

  IIRRef condition;
};

typedef refcount<IIRBase_ConditionalWaveform> IIRBase_ConditionalWaveformRef;

#endif
