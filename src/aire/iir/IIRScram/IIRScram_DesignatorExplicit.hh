
#ifndef IIRSCRAM_DESIGNATOR_EXPLICIT_HH
#define IIRSCRAM_DESIGNATOR_EXPLICIT_HH

// Copyright (c) 1996-2003 The University of Cincinnati.  
// All rights reserved.

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
// SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
// OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
// LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING OR
// DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the U.S.,
// and the terms of this license.

// You may modify, distribute, and use the software contained in this
// package under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE"
// version 2, June 1991. A copy of this license agreement can be found in
// the file "LGPL", distributed with this archive.

// Authors: Philip A. Wilsey	philip.wilsey@ieee.org
//          Dale E. Martin	dmartin@cliftonlabs.com
//          Malolan Chetlur     
//          Narayanan Thondugulam 
//          Umesh Kumar V. Rajasekaran 
//          Timothy J. McBrayer
//          Krishnan Subramani 

// You may modify, distribute, and use the software contained in this package
// under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE" version 2,
// June 1991. A copy of this license agreement can be found in the file
// "LGPL", distributed with this archive.

// Authors: Philip A. Wilsey	phil.wilsey@uc.edu
//          Dale E. Martin	dmartin@cliftonlabs.com
//          Malolan Chetlur     mal@ece.uc.edu
//          Narayanan Thondugulam nthondug@ece.uc.edu
//          Umesh Kumar V. Rajasekaran urajasek@ece.uc.edu
//          Timothy J. McBrayer tmcbraye@ece.uc.edu
//          Krishnan Subramani  skrish@ece.uc.edu

//---------------------------------------------------------------------------

#include "IIRScram_Designator.hh"
#include "IIRBase_DesignatorExplicit.hh"
class IIRScram_Declaration;
class IIRScram_List;
class IIRScram_TypeDefinition;

class IIRScram_DesignatorExplicit : public virtual IIRScram_Designator, public virtual IIRBase_DesignatorExplicit{

public:
  IIRScram_DesignatorExplicit() {}
  virtual ~IIRScram_DesignatorExplicit();

  /// Accept visitations \Ref{_accept_visitor}.
  visitor_return_type* _accept_visitor(node_visitor *, visitor_argument_type *);


  savant::set<IIRScram_TypeDefinition> *_get_rval_set(constraint_functor *functor = 0);

  IIRScram *_semantic_transform( savant::set<IIRScram_TypeDefinition> * );
  void _type_check( savant::set<IIRScram_TypeDefinition> * );
  IIRScram *_rval_to_decl( IIRScram_TypeDefinition * );

  IIRScram *_get_name();

  // This method looks up the name, and then eliminates declarations that
  // don't match the signature.
  savant::set<IIRScram_Declaration> *_symbol_lookup();

  IIRScram *_clone();

protected:    
private:
};
#endif
