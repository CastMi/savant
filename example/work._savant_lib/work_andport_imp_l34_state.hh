// This file was automatically generated - don't edit it by hand
#ifndef work_andport_imp_l34_state_hh
#define work_andport_imp_l34_state_hh
#include "work_andport_imp_l34_decls.hh"
#include "tyvis/Signal.hh"
#include "tyvis/VHDLKernel_state.hh"
#include "tyvis/Wait.hh"
#include "tyvis/AccessObject.hh"
// This file was published as the result of processing the IIR 
// node IIR_ProcessStatement
// from the VHDL file AndPort.vhd
// , line 34 .  
// It's probably best not to be editing this file by hand since
// it was automatically generated.



class work_andport_imp_l34;
class work_andport_imp_l34_state : public VHDLKernel_state {
  public:
  work_andport_imp_l34_state(work_andport_imp_l34*);
  ~work_andport_imp_l34_state(){}
  void initState(_savant_entity_elab *, VHDLKernel * );
  void cleanState();
  work_andport_imp_l34_state& operator=(const work_andport_imp_l34_state&);
  void copyState(const State *rhs){
    *this = *(static_cast<const work_andport_imp_l34_state *>(rhs));
  }
  SignalBase* locateSig(int);
  unsigned int getStateSize() const {
    return sizeof(work_andport_imp_l34_state);
  }
  Signal work_andport__a;
  Signal work_andport__b;
  Signal work_andport__f;
  
  const int numWaits;
  
};



#endif
