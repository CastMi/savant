
#ifndef IIRBASE_SIGNAL_ASSIGNMENT_STATEMENT_HH
#define IIRBASE_SIGNAL_ASSIGNMENT_STATEMENT_HH

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
#include "IIRBase_SequentialStatement.hh"
#include "IIR_SignalAssignmentStatement.hh"

class IIR_WaveformList;
class IIRBase_SignalAssignmentStatement : public virtual IIRBase_SequentialStatement, public virtual IIR_SignalAssignmentStatement{

public:
  // List Accessor(s)
  IIR_WaveformListRef   get_waveform();
  void                  set_waveform(IIR_WaveformListRef new_waveform);

  IIR_Kind get_kind() const override { return IIR_SIGNAL_ASSIGNMENT_STATEMENT; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_SignalAssignmentStatement"); }

  void set_target(IIRRef target);
  IIRRef get_target();
  void set_delay_mechanism( IIR_DelayMechanism delay_mechanism);
  IIR_DelayMechanism get_delay_mechanism();
  void set_reject_time_expression( IIRRef reject_time_expression );
  IIRRef get_reject_time_expression();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  IIR_Boolean                   is_resolved();
  IIR_Boolean                   is_above_attribute_found();

  void publish_vhdl(ostream &);
protected:
  IIRBase_SignalAssignmentStatement();
  virtual ~IIRBase_SignalAssignmentStatement() = 0;
    
private:
  // List Variable(s)
  IIR_WaveformListRef waveform;  
  IIRRef target;
  IIR_DelayMechanism delay_mechanism;
  IIRRef reject_time_expression;
};

typedef refcount<IIRBase_SignalAssignmentStatement> IIRBase_SignalAssignmentStatementRef;

#endif
