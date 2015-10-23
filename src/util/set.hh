#ifndef SET_HH
#define SET_HH

// Copyright (c) 1996-1999 The University of Cincinnati.
// All rights reserved. 

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF 
// THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE
// FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
// MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the
// U.S., and the terms of this license.


// You may modify, distribute, and use the software contained in this package
// under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE" version 2,
// June 1991. A copy of this license agreement can be found in the file
// "LGPL", distributed with this archive.

// Author: Dale E. Martin          dmartin@cliftonlabs.com

//---------------------------------------------------------------------------
#include "savant_config.hh"
#include <set>
#include "IIRScram_Declaration.hh"
#include "IIRScram_TypeDefinition.hh"
#include "dl_list.hh"
#include "constraint_functors.hh"

namespace savant {

  /** This class maintains a distinct set of pointers to the objects it's
      templatized on.  Functions are provided to add and reome things from
      the set, to get the number of objects in the set, and walk the members
      of the set.  NOTE: Since only pointers are kept within the set, care
      must be taken when "delete"ing members of the of set and so forth. */
  
  template <class type>
  class set : public std::set<type> {
    // @BeginExternalProseDescription
    // @EndExternalProseDescription

  public:
    // "New" a list, and put the elements of the set into it.
    //dl_list<type> *make_list();
    
    void reduce_set( constraint_functor *functor );

    template <typename new_type> savant::set<new_type> *convert_set();
  };

//   template <class type>
//   inline
//   dl_list<type> *
//   set<type>::make_list(){
//     dl_list<type> *retval = new dl_list<type>;
    
//     int i;
//     for( i = 0; i < num; i++ ){
//       retval->append( data_array[i] );
//     }
    
//     return retval;
//   }
  
  template <class type>
  inline 
  void 
  set<type>::reduce_set( constraint_functor *functor ){
    if (functor != NULL) {
      for( typename std::set<type>::iterator it = this->begin(); it != this->end(); it++){
        if( (*functor)(*it) == FALSE ){
        remove( *it );
        }
      }
    }
  }

  template <typename type>
  template <typename new_type> 
  inline
  savant::set<new_type> *
  savant::set<type>::convert_set() {
    ASSERT(this != NULL);
    savant::set<new_type>               *retv = new savant::set<new_type>;
    type                                *cur_element = this->getElement();
    new_type                            *new_val = dynamic_cast<new_type *>(cur_element);
  
    while(cur_element != NULL) {
      ASSERT(new_val != NULL);
      retv->add(new_val);
      cur_element = this->getNextElement();
      new_val = dynamic_cast<new_type *>(cur_element);
    }
  
    //  delete this;
    return retv;
  } 
}
#endif
