
#ifndef IIR_CONCURRENT_CONDITIONAL_SIGNAL_ASSIGNMENT_HH
#define IIR_CONCURRENT_CONDITIONAL_SIGNAL_ASSIGNMENT_HH

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
#include "IIR_ConcurrentStatement.hh"

REF_FORWARD_DECL(IIR_ConditionalWaveformList);

class IIR_ConcurrentConditionalSignalAssignment : public virtual IIR_ConcurrentStatement{

public:
  virtual ~IIR_ConcurrentConditionalSignalAssignment() {}
    
  // List accessor(s)
  virtual IIR_ConditionalWaveformListRef get_conditional_waveforms() = 0;
  virtual void                          set_conditional_waveforms(IIR_ConditionalWaveformListRef ) = 0;

  virtual void set_postponed( IIR_Boolean postponed ) = 0;
  virtual IIR_Boolean get_postponed() = 0;

  virtual void set_target( IIRRef target ) = 0;
  virtual IIRRef get_target() = 0;

  virtual void set_guarded( IIR_Boolean guarded ) = 0;
  virtual IIR_Boolean get_guarded() = 0;

  virtual void set_delay_mechanism( IIR_DelayMechanism delay_mechanism ) = 0;
  virtual IIR_DelayMechanism get_delay_mechanism() = 0;

  virtual void set_reject_time_expression( IIRRef reject_time_expression ) = 0;
  virtual IIRRef get_reject_time_expression() = 0;

  virtual IIR_SignalDeclarationRef get_guard_signal() = 0;

};

typedef refcount<IIR_ConcurrentConditionalSignalAssignment> IIR_ConcurrentConditionalSignalAssignmentRef;

#endif
