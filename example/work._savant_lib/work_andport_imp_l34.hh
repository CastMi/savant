// This file was automatically generated - don't edit it by hand
#ifndef work_andport_imp_l34_hh
#define work_andport_imp_l34_hh
#include "tyvis/VHDLProcess.hh"
#include "tyvis/STDTypes.hh"
#include "work_andport_imp_l34_state.hh"
// This file was published as the result of processing the IIR 
// node IIR_ProcessStatement
// from the VHDL file AndPort.vhd
// , line 34 .  
// It's probably best not to be editing this file by hand since
// it was automatically generated.



#ifdef savantnow
#undef savantnow
#define savantnow PhysicalLiteral(std_standard_timeTypeInfo(), getTimeNow().getMajor() )
#endif
class work_andport_imp_elab;
class work_andport_imp_l34 : public VHDLProcess {
  public:
  work_andport_imp_l34( _savant_entity_elab *proc );
  ~work_andport_imp_l34();
  void executeVHDL();
  State *allocateState();
  void initialize();
  // type_info structures for types declared within this process
  RValue *getGuard();
  RValue *getGuardExpression();
  
};



#endif
