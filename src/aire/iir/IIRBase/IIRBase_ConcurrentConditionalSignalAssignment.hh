
#ifndef IIRBASE_CONCURRENT_CONDITIONAL_SIGNAL_ASSIGNMENT_HH
#define IIRBASE_CONCURRENT_CONDITIONAL_SIGNAL_ASSIGNMENT_HH

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
#include "IIRBase_ConcurrentStatement.hh"
#include "IIR_ConcurrentConditionalSignalAssignment.hh"

class IIR_ConditionalWaveformList;

class IIRBase_ConcurrentConditionalSignalAssignment : 
  public virtual IIRBase_ConcurrentStatement,
  public virtual IIR_ConcurrentConditionalSignalAssignment{

public:
  // List Accessor(s)
  IIR_ConditionalWaveformListRef get_conditional_waveforms();
  void                        set_conditional_waveforms(IIR_ConditionalWaveformListRef new_conditional_waveforms);

  IIR_Kind get_kind() const override { return IIR_CONCURRENT_CONDITIONAL_SIGNAL_ASSIGNMENT; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_ConcurrentConditionalSignalAssignment"); }

  void set_postponed( IIR_Boolean postponed );
  IIR_Boolean get_postponed();

  void set_target( IIRRef target );
  IIRRef get_target();

  void set_guarded( IIR_Boolean guarded );
  IIR_Boolean get_guarded();

  void set_delay_mechanism( IIR_DelayMechanism delay_mechanism );
  IIR_DelayMechanism get_delay_mechanism();

  void set_reject_time_expression( IIRRef reject_time_expression );
  IIRRef get_reject_time_expression();


  IIR_SignalDeclarationRef get_guard_signal(){ return my_guard_signal; }
  void set_guard_signal( IIR_SignalDeclarationRef gs ){ my_guard_signal =  gs; }

  IIRRef convert_tree(plugin_class_factoryRef factory);

  IIR_Boolean is_resolved();

  void publish_vhdl(ostream &);
protected:
  IIRBase_ConcurrentConditionalSignalAssignment();
  virtual ~IIRBase_ConcurrentConditionalSignalAssignment() = 0;
    
private:
  // List Variable(s)
  IIR_ConditionalWaveformListRef conditional_waveforms;

  IIR_Boolean                postponed;
  IIRRef                     target;
  IIR_Boolean                guarded;
  IIR_DelayMechanism         delay_mechanism;
  IIRRef                     reject_time_expression;

  IIR_SignalDeclarationRef my_guard_signal;
};

typedef refcount<IIRBase_ConcurrentConditionalSignalAssignment> IIRBase_ConcurrentConditionalSignalAssignmentRef;

#endif
