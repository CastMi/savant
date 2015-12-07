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
//          Timothy J. McBrayer tmcbraye@ece.uc.edu

//---------------------------------------------------------------------------

#include "IIRBase_ConditionalWaveform.hh"
#include "IIRBase_ConditionalWaveformList.hh"

IIRBase_ConditionalWaveformList::IIRBase_ConditionalWaveformList() {}
IIRBase_ConditionalWaveformList::~IIRBase_ConditionalWaveformList() {}

IIR_ConditionalWaveformRef
IIRBase_ConditionalWaveformList::first() {
  return my_dynamic_pointer_cast<IIR_ConditionalWaveform>(IIRBase_List::first());
}


IIR_ConditionalWaveformRef
IIRBase_ConditionalWaveformList::last() {
  return my_dynamic_pointer_cast<IIR_ConditionalWaveform>(IIRBase_List::last());
}


IIR_ConditionalWaveformRef
IIRBase_ConditionalWaveformList::successor(IIR_ConditionalWaveformRef node) {
  return my_dynamic_pointer_cast<IIR_ConditionalWaveform>(IIRBase_List::successor(node));
}

void 
IIRBase_ConditionalWaveformList::publish_vhdl(ostream &vhdl_out) {
  IIRBase_ConditionalWaveformRef waveform_condition;
  for(waveform_condition = my_dynamic_pointer_cast<IIRBase_ConditionalWaveform>(first()); 
      waveform_condition != nullptr; ) {
    waveform_condition->publish_vhdl(vhdl_out);
    waveform_condition = my_dynamic_pointer_cast<IIRBase_ConditionalWaveform>(successor(waveform_condition));
    if( waveform_condition != nullptr) {
      vhdl_out << " else\n";
    }
  }
}
