
#ifndef IIRSCRAM_ASSOCIATION_LIST_HH
#define IIRSCRAM_ASSOCIATION_LIST_HH

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

// You may modify, distribute, and use the software contained in this package
// under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE" version 2,
// June 1991. A copy of this license agreement can be found in the file
// "LGPL", distributed with this archive.

// Authors: Philip A. Wilsey	phil.wilsey@uc.edu
//          Dale E. Martin	dmartin@cliftonlabs.com
//          Timothy J. McBrayer tmcrbaye@ece.uc.edu
//          Malolan Chetlur     mal@ece.uc.edu
//          Narayanan Thondugulam nthondug@ece.uc.edu

//---------------------------------------------------------------------------
#include "savant_config.hh"
#include "IIRScram_List.hh"
#include "IIRBase_AssociationList.hh"

REF_FORWARD_DECL(IIRScram_InterfaceList);
REF_FORWARD_DECL(IIRScram_ComponentInstantiationStatement);
REF_FORWARD_DECL(IIRScram_IndexedName);
class IIRScram_AssociationElement;
class IIRScram_Declaration;
class IIRScram_DeclarationList;
class IIRScram_DesignatorList;
class IIRScram_InterfaceDeclaration;
class IIRScram_Name;

class IIRScram_AssociationList : public virtual IIRScram_List, public virtual IIRBase_AssociationList{

public:
  IIRScram_AssociationList() {}

  /// Accept visitations \Ref{_accept_visitor}.
  visitor_return_type* _accept_visitor(node_visitor *, visitor_argument_type *);

  void append( IIRScram_AssociationElementRef );
  void prepend( IIRScram_AssociationElementRef );

  IIRRef get_nth_element( int );
  void _replace( IIRScram_AssociationElementRef to_replace, IIRScram_AssociationElementRef replace_with );

  void _resolve_and_order( IIRScram_InterfaceListRef formal_list,
			   IIRScram_InterfaceListRef local_list,
			   IIRScramRef               line_info );
  
  IIR_Boolean _check_valid_arguments( IIRScram_InterfaceListRef    formal_list,
				      IIRScram_InterfaceListRef  local_list);

  /** This method takes an interface list, and fills in all of the default
      values for associations that weren't specified.  It will generate
      error messages when errors occur. */
  void _fill_in_defaults( IIRScramRef line_info, IIRScram_InterfaceListRef formal_list );

  /**
     Used by
     IIRScram_ComponentInstantiationStatement#_build_default_entity_aspect
     to build the default maps, as per the rules on pg 80 of the '93 LRM.
  */
  void _build_default_map( IIRScram_ComponentInstantiationStatementRef err_info,
			   IIRScram_InterfaceListRef formal_list,
			   IIRScram_InterfaceListRef actual_list );
  
  IIRScramRef _clone();
  
  virtual ~IIRScram_AssociationList();
    
private:
  /** This method is responsible for checking to see if this list matches the
      interface list passed in, OR, for resolving a mathing list.  If this
      method is called with an incorrect interface list and the boolean argument
      is TRUE, it should abort. */
  IIR_Boolean _check_or_resolve( IIRScram_InterfaceListRef formal_list,
				 IIRScram_InterfaceListRef                     local_list,
				 IIR_Boolean                                   resolve = TRUE );  
  
  /** This method checks the positional part of an argument list.  It only
      blows up on errors if the second parameter is TRUE.  It returns -1 if
      an argument didn't match. */
  IIR_Int32 _process_positional_part( IIRScram_InterfaceListRef , IIR_Boolean resolve = TRUE );

  IIRScram_InterfaceDeclarationRef _find_declaration_in_formal( IIRScram_AssociationElementRef  );
  IIRScram_DeclarationRef _find_declaration( IIRScram_NameRef to_find, IIRScram_DeclarationListRef list );
  IIRScramRef _find_formal_designator( IIRScramRef formal_part );
  IIRScram_DeclarationRef _find_formal_declaration( IIRScramRef formal_designator,
                                                  IIRScram_InterfaceListRef formal_list  );
  IIRScramRef _find_actual_designator( IIRScramRef actual_part );

  bool _find_formal_types( IIRScram_AssociationElementRef current_association,		  
			   IIRScramRef actual_part, 
			   IIRScramRef actual_designator,
			   IIRScramRef formal_part,
			   IIRScramRef formal_designator,
			   IIRScram_DeclarationRef formal_declaration,
			   savant::set<IIRScram_TypeDefinitionRef> add_types_to_me );

  IIRScram_NameRef _get_formal_designator_from_indexed_name( IIRScram_IndexedNameRef  );
  IIRScramRef _get_actual_designator_from_indexed_name( IIRScram_IndexedNameRef  );
};

typedef refcount<IIRScram_AssociationList> IIRScram_AssociationListRef;

#endif
