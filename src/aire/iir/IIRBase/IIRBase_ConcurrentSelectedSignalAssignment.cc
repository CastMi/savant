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
#include "plugin_class_factory.hh"
#include "IIRBase_SelectedWaveformList.hh"

IIRBase_ConcurrentSelectedSignalAssignment::IIRBase_ConcurrentSelectedSignalAssignment() {
  set_postponed( FALSE );
  set_guarded( FALSE );
  set_delay_mechanism( IIR_INERTIAL_DELAY );
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
IIRBase_ConcurrentSelectedSignalAssignment::set_target(IIRRef target ){
  this->target = target;
}

IIRRef
IIRBase_ConcurrentSelectedSignalAssignment::get_target(){
  return target;
}

void 
IIRBase_ConcurrentSelectedSignalAssignment::set_expression(IIRRef expr ){
  expression = expr;
}

IIRRef
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
IIRBase_ConcurrentSelectedSignalAssignment::set_reject_time_expression( IIRRef reject_time_expression ){
  this->reject_time_expression = reject_time_expression;
}

IIRRef
IIRBase_ConcurrentSelectedSignalAssignment::get_reject_time_expression(){
  return reject_time_expression;
}

// List Accessor(s)
IIR_SelectedWaveformListRef
IIRBase_ConcurrentSelectedSignalAssignment::get_selected_waveforms() {
  ASSERT(selected_waveforms != nullptr);
  return selected_waveforms;
}

void
IIRBase_ConcurrentSelectedSignalAssignment::set_selected_waveforms(IIR_SelectedWaveformListRef new_selected_waveforms) {
  ASSERT(new_selected_waveforms != nullptr);
  selected_waveforms = new_selected_waveforms;
}

IIRRef
IIRBase_ConcurrentSelectedSignalAssignment::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_ConcurrentSelectedSignalAssignmentRef new_node = my_dynamic_pointer_cast<IIRBase_ConcurrentSelectedSignalAssignment>(IIRBase_ConcurrentStatement::convert_tree(factory));

  // Process the variables
  new_node->selected_waveforms = my_dynamic_pointer_cast<IIR_SelectedWaveformList>(selected_waveforms->convert_tree(factory));
  new_node->my_guard_signal = my_dynamic_pointer_cast<IIR_SignalDeclaration>(convert_node(my_guard_signal, factory));

  new_node->postponed = postponed;
  new_node->guarded = guarded;
  new_node->delay_mechanism = delay_mechanism;
  new_node->target = convert_node(target, factory);
  new_node->expression = convert_node(expression, factory);
  new_node->reject_time_expression = convert_node(reject_time_expression, factory);

  return new_node;
}

IIR_Boolean 
IIRBase_ConcurrentSelectedSignalAssignment::is_resolved(){
  IIR_Boolean retval = TRUE;

  if( get_target()->is_resolved() == FALSE ){
    retval = FALSE;
  }
  
  if( get_reject_time_expression() != NULL &&
      get_reject_time_expression()->is_resolved() == FALSE ){
    retval = FALSE;
  }

  if( get_selected_waveforms()->is_resolved() == FALSE ){
    retval = FALSE;
  }

  return retval;
}

IIR_CaseStatementAlternativeListRef
IIRBase_ConcurrentSelectedSignalAssignment::build_alternative_list(IIR_Boolean bPublishingVhdl){
  IIR_SelectedWaveformRef current_waveform;
  IIR_CaseStatementAlternativeListRef retval = get_design_file()->get_class_factory()->new_IIR_CaseStatementAlternativeList();
  IIR_SignalAssignmentStatementRef sastmt;
  
  //  copy_location( this, retval );
  current_waveform = get_selected_waveforms()->first();
  while( current_waveform != NULL ){
    IIRRef current_choice = current_waveform->get_choice();
    ASSERT( my_dynamic_pointer_cast<IIR_CaseStatementAlternative>(current_choice) );
   
    if (bPublishingVhdl) {
      sastmt = get_design_file()->get_class_factory()->new_IIR_SignalAssignmentStatement();
      copy_location (sastmt.get());
      ASSERT ( get_target()->is_resolved() == TRUE );
      
      sastmt->set_target(get_target());
      sastmt->set_delay_mechanism(get_delay_mechanism());
      sastmt->set_reject_time_expression(get_reject_time_expression());
      sastmt->set_waveform(current_waveform->get_waveform());
      
      my_dynamic_pointer_cast<IIR_CaseStatementAlternative>(current_choice)->get_sequence_of_statements()->append(sastmt);
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
  my_dynamic_pointer_cast<IIRBase_SelectedWaveformList>(get_selected_waveforms())->publish_vhdl(vhdl_out, ",\n");
  vhdl_out << ";\n";
}
