
#ifndef IIR_PHYSICAL_TYPE_DEFINITION_HH
#define IIR_PHYSICAL_TYPE_DEFINITION_HH

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
#include "IIR_ScalarTypeDefinition.hh"

REF_FORWARD_DECL(IIR_UnitList);
REF_FORWARD_DECL(IIR_PhysicalUnit);

class IIR_PhysicalTypeDefinition : public virtual IIR_ScalarTypeDefinition{

public:
  virtual ~IIR_PhysicalTypeDefinition() {}

  // List accessor(s)
  virtual IIR_UnitListRef get_units() = 0;
  virtual void            set_units(IIR_UnitListRef ) = 0;

  virtual void set_primary_unit( IIR_PhysicalUnitRef ) = 0;
  virtual IIR_PhysicalUnitRef get_primary_unit() = 0;

};

typedef refcount<IIR_PhysicalTypeDefinition> IIR_PhysicalTypeDefinitionRef;

#endif
