#include "tyvis/VCD.hh"
#include "work_andport_imp_l34.hh"
#include "tyvis/SignalBase.hh"
#include "tyvis/GlobalControl.hh"
// This file was published as the result of processing the IIR 
// node IIR_ProcessStatement
// from the VHDL file AndPort.vhd
// , line 34 .  
// It's probably best not to be editing this file by hand since
// it was automatically generated.



void work_andport_imp_l34::executeVHDL() {
  VHDLProcess *processPtr = this;
#ifdef VHDLDBG
  cout << getName() << " executing VHDL at " << getTimeNow() << endl;
#endif
  work_andport_imp_l34_state *currentState = static_cast<work_andport_imp_l34_state *>(getState());
  if (currentState->waitLabel == 0) goto wait0x372c490;
  if(currentState->waitLabel == WAITING_IN_PROC) {
    currentState->stack.setCurrentToTop();
    
  }
  while(true){
    // line 34  of file AndPort.vhd(IIR_SignalAssignmentStatement)
    assignSignal( 
      dynamic_cast<SignalBase &>((static_cast<work_andport_imp_l34_state *>(getState()))->work_andport__f),
      this,
      (((static_cast<work_andport_imp_l34_state *>(getState()))->work_andport__a == SAVANT_BOOLEAN_FALSE) ? SAVANT_BOOLEAN_FALSE : SAVANT_BOOLEAN_TRUE.vhdlAnd((static_cast<work_andport_imp_l34_state *>(getState()))->work_andport__b)),
      SAVANT_ZERO_TIME, 
      SAVANT_ZERO_TIME,
      defaultInfo(),
      defaultInfo()
    );
    // line 34  of file AndPort.vhd(IIR_WaitStatement)
    executeWait(
      0
    );
    
    return;
    wait0x372c490:
    if (!resumeWait(0)) return;
    
  } // end primary while loop
  
} // end execute_VHDL
work_andport_imp_l34::~work_andport_imp_l34() {}
work_andport_imp_l34::work_andport_imp_l34( _savant_entity_elab *ptr): VHDLProcess("work_andport_imp_l34", ptr ){
  
}
State *
work_andport_imp_l34::allocateState(){
  getProc()->copyGenericsToGlobals();
  return new work_andport_imp_l34_state(this);
  
}
void
work_andport_imp_l34::initialize(){
if (GlobalControl::getVCD()) GlobalControl::getVCD()->setBase(getProc()->get_base());
VHDLProcess::initialize();
}
RValue*
work_andport_imp_l34::getGuard(){
  return 0;
  
}
RValue*
work_andport_imp_l34::getGuardExpression(){
  return 0;
  
}


