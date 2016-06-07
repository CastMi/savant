#ifndef IIRSCRAM_PHYSICAL_UNIT_HH
#define IIRSCRAM_PHYSICAL_UNIT_HH

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
//          Malolan Chetlur     mal@ece.uc.edu
//          Krishnan Subramani  skrish@ece.uc.edu
//          Umesh Kumar V. Rajasekaran urajasek@ece.uc.edu
//          Narayanan Thondugulam nthondug@ece.uc.edu
//          Radharamanan Radhakrishnan  ramanan@ece.uc.edu
//          Timothy J. McBrayer tmcbraye@ececs.uc.edu

//---------------------------------------------------------------------------

#include "IIRScram_Declaration.hh"
#include "IIRBase_PhysicalUnit.hh"

class IIRScram_AttributeSpecificationList;
class IIRScram_List;
class IIRScram_PhysicalTypeDefinition;
class IIRScram_TypeDefinition;

class IIRScram_PhysicalUnit : public virtual IIRScram_Declaration, public virtual IIRBase_PhysicalUnit {

public:
  IIRScram_PhysicalUnit();
  virtual ~IIRScram_PhysicalUnit();

  IIRScram_AttributeSpecificationList *_get_attribute_specification_list();

  savant::set<IIRScram_TypeDefinition> *_get_rval_set(constraint_functor *functor = 0);

  IIR_Boolean _is_readable(){ return TRUE; }
  IIR_Boolean _is_writable(){ return FALSE; }

  IIRScram* _clone() { return this; }

  // Wrappers for IIRBase functions
  IIRScram_AttributeSpecificationList   *_get_attributes();
  IIRScram *                            _get_multiplier();
  IIRScram_PhysicalTypeDefinition       *_get_physical_type();
};

#endif
