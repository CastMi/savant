#ifndef IIRSCRAM_LIBRARY_UNIT_HH
#define IIRSCRAM_LIBRARY_UNIT_HH
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
//          Timothy J. McBrayer tmcbraye@ece.uc.edu
//          Narayanan Thondugulam nthondug@ece.uc.edu

//---------------------------------------------------------------------------
#include "savant_config.hh"
#include "IIRBase_LibraryUnit.hh"
#include "IIRScram_Declaration.hh"

REF_FORWARD_DECL(IIRScram_DeclarationList);
REF_FORWARD_DECL(IIRScram_EntityDeclaration);
class IIRScram_Declaration;
class IIRScram_LibraryDeclaration;
class IIRScram_TypeDefinition;

/*
 * Represents either an entity, achitecture, package or package body
 */
class IIRScram_LibraryUnit : public virtual IIRScram_Declaration,
			     public virtual IIRBase_LibraryUnit{

public:
  IIRScram_LibraryUnit();

  virtual IIRScram_EntityDeclarationRef _get_entity();

  IIR_Boolean _is_iir_library_unit(){ return TRUE; }
  IIR_Boolean _is_homograph_of( IIRScram_DeclarationRef );

  virtual void _clone( IIRScramRef  );

  IIRScram_AttributeSpecificationListRef _get_attribute_specification_list();

  // Wrappers for IIRBase functions
  IIRScram_DeclarationListRef             _get_context_items();

protected:
  virtual ~IIRScram_LibraryUnit();
  
private:

};

typedef refcount<IIRScram_LibraryUnit> IIRScram_LibraryUnitRef;

#endif

