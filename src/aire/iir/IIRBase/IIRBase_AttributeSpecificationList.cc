
// Copyright (c) 1996-1999 The University of Cincinnati.  
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

//---------------------------------------------------------------------------

#include "IIRBase_AttributeSpecificationList.hh"
#include "IIR_AttributeSpecification.hh"

IIRBase_AttributeSpecificationList::IIRBase_AttributeSpecificationList(){}
IIRBase_AttributeSpecificationList::~IIRBase_AttributeSpecificationList(){}

void 
IIRBase_AttributeSpecificationList::append( IIR_AttributeSpecificationRef to_append ){
    IIRBase_List::append( to_append );
}

IIR_AttributeSpecificationRef
IIRBase_AttributeSpecificationList::successor( IIR_AttributeSpecificationRef succeed_me ){
  return my_dynamic_pointer_cast<IIR_AttributeSpecification>(IIRBase_List::successor( succeed_me ));
}

IIR_AttributeSpecificationRef
IIRBase_AttributeSpecificationList::first(){
  return my_dynamic_pointer_cast<IIR_AttributeSpecification>(IIRBase_List::first());
}
