#include "tyvis/Signal.hh"
#include "work_andport_imp_l34.hh"
#include "work_andport_imp_l34_state.hh"
// This file was published as the result of processing the IIR 
// node IIR_ProcessStatement
// from the VHDL file AndPort.vhd
// , line 34 .  
// It's probably best not to be editing this file by hand since
// it was automatically generated.



#ifdef savantnow
#undef savantnow
#define savantnow PhysicalLiteral(std_standard_timeTypeInfo(), processPtr->getTimeNow().getMajor() )
#endif
work_andport_imp_l34_state::work_andport_imp_l34_state(work_andport_imp_l34 *processPtr ):
  work_andport__a(
    std_standard_bitTypeInfo(),
    "a"
  )
  ,work_andport__b(
    std_standard_bitTypeInfo(),
    "b"
  )
  ,work_andport__f(
    std_standard_bitTypeInfo(),
    "f"
  )
  ,numWaits(1)

{
    wait = new Wait[1];
  
}
void
work_andport_imp_l34_state::initState(
  _savant_entity_elab *ptr,
  VHDLKernel *processPointer
)
{
  work_andport_imp_elab* proc = (work_andport_imp_elab *) ptr;
  work_andport_imp_l34 *processPtr = (work_andport_imp_l34 *) processPointer;
  VHDLKernel_state::initState(ptr, processPointer);
  {
    work_andport__a.setElaborationInfo(
      proc->work_andport__a
    );
    work_andport__a.resolveAndUpdate(processPointer);
    
  }
  {
    work_andport__b.setElaborationInfo(
      proc->work_andport__b
    );
    work_andport__b.resolveAndUpdate(processPointer);
    
  }
  {
    work_andport__f.setElaborationInfo(
      proc->work_andport__f
    );
    work_andport__f.resolveAndUpdate(processPointer);
    
  }
  wait[0].addSensitivityTo( dynamic_cast<SignalBase *>(&work_andport__a));
  wait[0].addSensitivityTo( dynamic_cast<SignalBase *>(&work_andport__b));
  
  
}
void
work_andport_imp_l34_state::cleanState() {
// Hey!!! cleanup is done in the signal's destructor
wait[0].destructSensitivityList();
}
SignalBase*
work_andport_imp_l34_state::locateSig(int sigId){
  SignalBase *ptr = NULL;
  ptr = work_andport__a.locateSig(sigId);
  if( ptr ) return ptr;
  ptr = work_andport__b.locateSig(sigId);
  if( ptr ) return ptr;
  ptr = work_andport__f.locateSig(sigId);
  if( ptr ) return ptr;
  return ptr;
  
}
work_andport_imp_l34_state &
work_andport_imp_l34_state::operator=( const work_andport_imp_l34_state &s ) {
  VHDLKernel_state::operator=(s);
  
  this->work_andport__a = s.work_andport__a;
  this->work_andport__b = s.work_andport__b;
  this->work_andport__f = s.work_andport__f;
  for( int i = 0; i < numWaits; i++) wait[i] = s.wait[i];
  return *this;
  
}



