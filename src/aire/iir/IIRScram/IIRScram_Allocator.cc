// Copyright (c) 1996-2000 The University of Cincinnati.  
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
//          Timothy J. McBrayer tmcrbaye@ece.uc.edu
//          Umesh Kumar V. Rajasekaran urajasek@ece.uc.edu
//          Malolan Chetlur     mal@ece.uc.edu
//          Radharamanan Radhakrishnan  ramanan@ece.uc.edu
//	    Magnus Danielson	cfmd@swipnet.se

//---------------------------------------------------------------------------

#include "IIRScram.hh"
#include "IIRScram_Allocator.hh"
#include "IIRScram_TypeDefinition.hh"
#include "IIRScram_AccessTypeDefinition.hh"
#include "symbol_table.hh"
#include "set.hh"

IIRScram_Allocator::~IIRScram_Allocator() {}

savant::set<IIRScram_TypeDefinitionRef>
IIRScram_Allocator::_get_rval_set( constraint_functor * ){
  savant::set<IIRScram_TypeDefinitionRef> retval;
  
  savant::set<IIRScram_AccessTypeDefinitionRef>    access_types;
  access_types = _get_symbol_table()->get_in_scope_access_types().convert_set<IIRScram_AccessTypeDefinition>();
  
  for(auto it = access_types.begin(); it != access_types.end(); it++){
     ASSERT(*it != NULL);
     retval.insert( *it );
  }

  return retval;
}

void
IIRScram_Allocator::_type_check( savant::set<IIRScram_TypeDefinitionRef> ){
  // Don't need to do anything...
}

visitor_return_type *
IIRScram_Allocator::_accept_visitor( node_visitor *visitor,
				     visitor_argument_type *arg ){
  ASSERT(visitor != NULL);
  return visitor->visit_IIR_Allocator(this, arg);
}

IIRScramRef
IIRScram_Allocator::_get_value() {
  return my_dynamic_pointer_cast<IIRScram>(IIRBase_Allocator::get_value());
}

IIRScram_TypeDefinitionRef
IIRScram_Allocator::_get_type_mark() {
  return my_dynamic_pointer_cast<IIRScram_TypeDefinition>(get_type_mark());
}
