#ifndef IIRSCRAM_INTEGER_TYPE_DEFINITION_HH
#define IIRSCRAM_INTEGER_TYPE_DEFINITION_HH
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
//          Krishnan Subramani  skrish@ece.uc.edu
//          Umesh Kumar V. Rajasekaran urajasek@ece.uc.edu
//          Narayanan Thondugulam nthondug@ece.uc.edu

//---------------------------------------------------------------------------

#include "IIRScram_ScalarTypeDefinition.hh"
#include "IIRBase_IntegerTypeDefinition.hh"

class IIRScram_FunctionDeclaration;
class IIRScram_IntegerSubtypeDefinition;
class IIRScram_TypeDefinition;

class IIRScram_IntegerTypeDefinition : public virtual IIRScram_ScalarTypeDefinition, public virtual IIRBase_IntegerTypeDefinition{

public:
  /// Accept visitations \Ref{_accept_visitor}.
  visitor_return_type* _accept_visitor(node_visitor *, visitor_argument_type *);

  IIR_Boolean _is_numeric_type(){ return true; }
  IIR_Boolean _is_iir_integer_type_definition(){ return true; }

  IIRScram_TypeDefinition *_get_new_subtype();

  void _set_resolution_function( IIRScram_FunctionDeclaration * );

  /**
     Given the left, direction, and right passed in, construct a new type/subtype for 
     this range.
   */
  static IIRScram_IntegerSubtypeDefinition *_construct_new_type( IIRScram_RangeTypeDefinition   *init_info,
                                                                 IIRScram_TypeDeclaration       *type_decl,
                                                                 IIRScram_DesignFile            *design_file);

protected:
  void _build_implicit_operators( savant::set<IIRScram_Declaration> * );
    
private:
};
#endif
