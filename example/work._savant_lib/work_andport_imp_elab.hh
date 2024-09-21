// This file was automatically generated - don't edit it by hand
#ifndef work_andport_imp_elab_hh
#define work_andport_imp_elab_hh
#include "tyvis/STDTypes.hh"
#include "work_andport_elab.hh"
#include "tyvis/Hierarchy.hh"
#include "work_andport_imp.hh"
// This file was published as the result of processing the IIR 
// node IIR_ArchitectureDeclaration
// from the VHDL file AndPort.vhd
// , line 32 .  
// It's probably best not to be editing this file by hand since
// it was automatically generated.



class work_andport_imp_l34;
class work_andport_imp_elab : public work_andport_elab{
  public:
  work_andport_imp_elab();
  ~work_andport_imp_elab();
  
  void instantiate(Hierarchy *, const string parent_base, const char *local_name);
  std::string _base;
  std::string get_base() {return(_base);}
  void createNetInfo();
  void connect(int, int, ...);
  void partition() {}
  _savant_entity_elab *getArchitecture(){ return this; }
  work_andport_imp_l34 *work_andport_imp_l34_elab_obj;
  
};



#endif
