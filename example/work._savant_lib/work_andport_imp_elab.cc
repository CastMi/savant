#include "work_andport.hh"
#include "tyvis/SourceBase.hh"
#include "work_andport_imp_elab.hh"
#include "tyvis/Signal.hh"
#include "work_andport_imp_l34.hh"
#include <cstdarg>
// This file was published as the result of processing the IIR 
// node IIR_ArchitectureDeclaration
// from the VHDL file AndPort.vhd
// , line 32 .  
// It's probably best not to be editing this file by hand since
// it was automatically generated.



work_andport_imp_elab::work_andport_imp_elab( 
  
)

{
  // all of the global constants...
  // all of the file objects...
  // all of the object pointers...
  work_andport_imp_l34_elab_obj = NULL;
  
}
work_andport_imp_elab::~work_andport_imp_elab(){
}
void
work_andport_imp_elab::instantiate( Hierarchy *hier, const string parent_base, const char *local_name ){
    _base = hier->addFrame(parent_base, "imp", local_name);
    work_andport_imp_l34_elab_obj = new work_andport_imp_l34(getArchitecture());
    createNetInfo();
    
  }
  void
  work_andport_imp_elab::createNetInfo(){
    work_andport__a.addToFanOut( work_andport_imp_l34_elab_obj );
    work_andport__b.addToFanOut( work_andport_imp_l34_elab_obj );
    {
      Signal *sourceSignal = new Signal(
        std_standard_bitTypeInfo(),
        "f"
      )
      ;
      addChild(
        work_andport__f,
        *(sourceSignal), work_andport_imp_l34_elab_obj);
      
      
    }
    
  }
  void
  work_andport_imp_elab::connect( int inputSignals, int outputSignals, ... ){
    int noOfSignals = inputSignals + outputSignals;
    va_list ap;
    va_start(ap, outputSignals);
    for( int i=0; i < noOfSignals; i++ ){
      addToFanOut( va_arg(ap, RValue*) );
      
    }
    va_end(ap);
    if( inputSignals > 0 ){
      setSourceInfo(
        work_andport__a,
        *(fanOutInfo[0])
      );
      setSourceInfo(
        work_andport__b,
        *(fanOutInfo[1])
      );
      
    }
    if( outputSignals > 0 ){
      work_andport__f.addToFanOut(
        
        *(fanOutInfo[2])
      );
      
    }
    
  }
  extern "C"{
    void *allocatework_andport_imp(){
      return new work_andport_imp_elab;
      
    }
    
  }
  

