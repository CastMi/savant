
#ifndef IIR_PHYSICAL_UNIT_HH
#define IIR_PHYSICAL_UNIT_HH

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
//          Malolan Chetlur     mal@ece.uc.edu
//          Timothy J. McBrayer tmcbraye@ece.uc.edu

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIR_Declaration.hh"

REF_FORWARD_DECL(IIR_AttributeSpecificationList);
REF_FORWARD_DECL(IIR_PhysicalUnit);

class IIR_PhysicalUnit : public virtual IIR_Declaration{
public:
  virtual ~IIR_PhysicalUnit() {}    

  // List accessor(s)
  virtual IIR_AttributeSpecificationListRef get_attributes() = 0;
  virtual void                              set_attributes( IIR_AttributeSpecificationListRef ) = 0;

  virtual void set_multiplier( IIRRef ) = 0;
  virtual IIRRef get_multiplier() = 0;
  virtual void set_unit_name( IIR_PhysicalUnitRef ) = 0;
  virtual IIR_PhysicalUnitRef get_unit_name() = 0;
};

typedef refcount<IIR_PhysicalUnit> IIR_PhysicalUnitRef;

#endif
