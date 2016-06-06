// Copyright (c) The University of Cincinnati.  
// All rights reserved.

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
// SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
// OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
// LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING OR
// DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the U.S.,
// and the terms of this license.

// You may modify, distribute, and use the software contained in this
// package under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE"
// version 2, June 1991. A copy of this license agreement can be found in
// the file "LGPL", distributed with this archive.

#include "savant.hh"
#include "IIRBase_ConcurrentSelectedSignalAssignment.hh"
#include "IIR_CaseStatementAlternative.hh"
#include "IIR_CaseStatementAlternativeList.hh"
#include "IIR_DesignFile.hh"
#include "IIR_SelectedWaveform.hh"
#include "IIR_SelectedWaveformList.hh"
#include "IIR_SequentialStatementList.hh"
#include "IIR_SignalAssignmentStatement.hh"
#include "IIR_SignalDeclaration.hh"
#include "IIR_Choice.hh"
#include "plugin_class_factory.hh"
#include "IIRBase_SelectedWaveformList.hh"

IIRBase_ConcurrentSelectedSignalAssignment::IIRBase_ConcurrentSelectedSignalAssignment() :
  selected_waveforms(0) {
  set_postponed( false );
  set_target( NULL );
  set_expression( NULL );
  set_guarded( false );
  set_delay_mechanism( IIR_INERTIAL_DELAY );
  set_reject_time_expression( NULL );
  set_guard_signal(NULL);
}

IIRBase_ConcurrentSelectedSignalAssignment::~IIRBase_ConcurrentSelectedSignalAssignment() {}

void 
IIRBase_ConcurrentSelectedSignalAssignment::set_postponed( IIR_Boolean postponed ){
  this->postponed = postponed;
}

IIR_Boolean   
IIRBase_ConcurrentSelectedSignalAssignment::get_postponed(){
  return postponed;
}

void 
IIRBase_ConcurrentSelectedSignalAssignment::set_target(IIR *target ){
  this->target = target;
}

IIR * 
IIRBase_ConcurrentSelectedSignalAssignment::get_target(){
  return target;
}

void 
IIRBase_ConcurrentSelectedSignalAssignment::set_expression(IIR *expr ){
  expression = expr;
}

IIR * 
IIRBase_ConcurrentSelectedSignalAssignment::get_expression(){
  return expression;
}

void 
IIRBase_ConcurrentSelectedSignalAssignment::set_guarded( IIR_Boolean guarded ){
  this->guarded = guarded;
}

IIR_Boolean 
IIRBase_ConcurrentSelectedSignalAssignment::get_guarded(){
  return guarded;
}

void  
IIRBase_ConcurrentSelectedSignalAssignment::set_delay_mechanism( IIR_DelayMechanism delay_mechanism ){
  this->delay_mechanism = delay_mechanism;
}

IIR_DelayMechanism  
IIRBase_ConcurrentSelectedSignalAssignment::get_delay_mechanism(){
  return delay_mechanism;
}

void 
IIRBase_ConcurrentSelectedSignalAssignment::set_reject_time_expression( IIR *reject_time_expression ){
  this->reject_time_expression = reject_time_expression;
}

IIR *
IIRBase_ConcurrentSelectedSignalAssignment::get_reject_time_expression(){
  return reject_time_expression;
}

// List Accessor(s)
IIR_SelectedWaveformList *
IIRBase_ConcurrentSelectedSignalAssignment::get_selected_waveforms() {
  ASSERT(selected_waveforms != NULL);
  return selected_waveforms;
}

void
IIRBase_ConcurrentSelectedSignalAssignment::set_selected_waveforms(IIR_SelectedWaveformList *new_selected_waveforms) {
  ASSERT(new_selected_waveforms != NULL);
  delete selected_waveforms;
  selected_waveforms = new_selected_waveforms;
}

IIR_Statement *
IIRBase_ConcurrentSelectedSignalAssignment::convert_tree(plugin_class_factory *factory) {
  // Get the node itself
  IIRBase_ConcurrentSelectedSignalAssignment *new_node = dynamic_cast<IIRBase_ConcurrentSelectedSignalAssignment *>(IIRBase_ConcurrentStatement::convert_tree(factory));

  // Process the variables
  new_node->selected_waveforms = selected_waveforms->convert_node(factory);
  new_node->my_guard_signal = dynamic_cast<IIR_SignalDeclaration *>(my_guard_signal->convert_tree(factory));

  new_node->postponed = postponed;
  new_node->guarded = guarded;
  new_node->delay_mechanism = delay_mechanism;
  new_node->target = target->convert_tree(factory);
  new_node->expression = expression->convert_tree(factory);
  new_node->reject_time_expression = reject_time_expression->convert_tree(factory);

  return new_node;
}

IIR_Boolean 
IIRBase_ConcurrentSelectedSignalAssignment::is_resolved(){
  IIR_Boolean retval = TRUE;

  if( get_target()->is_resolved() == false ){
    retval = false;
  }
  
  if( get_reject_time_expression() != NULL &&
      get_reject_time_expression()->is_resolved() == false ){
    retval = false;
  }

  if( get_selected_waveforms()->is_resolved() == false ){
    retval = false;
  }

  return retval;
}

IIR_CaseStatementAlternativeList *
IIRBase_ConcurrentSelectedSignalAssignment::build_alternative_list(IIR_Boolean bPublishingVhdl){
  IIR_SelectedWaveform *current_waveform = NULL;
  // FIXME
  IIR_CaseStatementAlternativeList *retval = NULL;//get_design_file()->get_class_factory()->new_IIR_CaseStatementAlternativeList();
  IIR_SignalAssignmentStatement *sastmt = NULL;
  
  //  copy_location( this, retval );
  current_waveform = get_selected_waveforms()->first();
  while( current_waveform != NULL ){
    ASSERT( dynamic_cast<IIR_CaseStatementAlternative *>(current_waveform->get_choice()) );
    IIR_CaseStatementAlternative *current_choice = dynamic_cast<IIR_CaseStatementAlternative *>(current_waveform->get_choice());
   
    if (bPublishingVhdl) {
       // FIXME
      sastmt = NULL; //get_design_file()->get_class_factory()->new_IIR_SignalAssignmentStatement();
      copy_location (this, sastmt);
      ASSERT ( get_target()->is_resolved() == TRUE );
      
      sastmt->set_target(get_target());
      sastmt->set_delay_mechanism(get_delay_mechanism());
      sastmt->set_reject_time_expression(get_reject_time_expression());
      sastmt->set_waveform(current_waveform->get_waveform());
      
      dynamic_cast<IIR_CaseStatementAlternative *>(current_choice)->get_sequence_of_statements()->append(sastmt);
    }
    retval->append(current_choice);
    current_waveform = get_selected_waveforms()->successor( current_waveform );    
  }
  ASSERT( retval->num_elements() == get_selected_waveforms()->num_elements() );
  return retval;
}

void 
IIRBase_ConcurrentSelectedSignalAssignment::publish_vhdl(ostream &vhdl_out) {

  publish_vhdl_stmt_label(vhdl_out);

  if (get_postponed() == true) {
    vhdl_out << "postponed ";
  }
  vhdl_out << " with ";
  
  get_expression()->publish_vhdl(vhdl_out);
  
  vhdl_out << " select\n";
  
  get_target()->publish_vhdl(vhdl_out);
  vhdl_out << " <= ";

  publish_vhdl_delay_mechanism(vhdl_out, get_delay_mechanism(), get_reject_time_expression());
  dynamic_cast<IIRBase_SelectedWaveformList*>(get_selected_waveforms())->publish_vhdl(vhdl_out, ",\n");
  vhdl_out << ";\n";
}
