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

#include "IIRBase_AssociationList.hh"
#include "IIRScram_List.hh"

class IIRScram_AssociationElement;
class IIRScram_ComponentInstantiationStatement;
class IIRScram_Declaration;
class IIRScram_DeclarationList;
class IIRScram_IndexedName;
class IIRScram_InterfaceDeclaration;
class IIRScram_InterfaceList;
class IIRScram_Name;
class IIRScram;
class IIRScram_TypeDefinition;
namespace savant {
  template <class type> class set;
}

class IIRScram_AssociationList : public virtual IIRScram_List<IIR_AssociationElement>, public virtual IIRBase_AssociationList {

public:
  IIRScram_AssociationList() {}

  void _replace( IIRScram_AssociationElement *to_replace, IIRScram_AssociationElement *replace_with );

  void _resolve_and_order( IIRScram_InterfaceList *formal_list,
			   IIRScram_InterfaceList *local_list,
			   IIRScram               *line_info = nullptr );
  
  IIR_Boolean _check_valid_arguments( IIRScram_InterfaceList    *formal_list,
				      IIRScram_InterfaceList    *local_list);

  /** This method takes an interface list, and fills in all of the default
      values for associations that weren't specified.  It will generate
      error messages when errors occur. */
  void _fill_in_defaults( IIRScram *line_info, IIRScram_InterfaceList *formal_list );

  /**
     Used by
     IIRScram_ComponentInstantiationStatement#_build_default_entity_aspect
     to build the default maps, as per the rules on pg 80 of the '93 LRM.
  */
  void _build_default_map( IIRScram_ComponentInstantiationStatement *err_info,
			   IIRScram_InterfaceList *formal_list,
			   IIRScram_InterfaceList *actual_list );
  
  IIRScram_AssociationList *_clone();
  IIRScram_Declaration * _find_declaration( IIRScram_Name *to_find, IIRScram_DeclarationList *list );
  void copy_location( IIRScram_Statement* , IIRScram* );
  void copy_location( IIRScram* , IIRScram* );
  
  virtual ~IIRScram_AssociationList();
    
private:
  /** This method is responsible for checking to see if this list matches the
      interface list passed in, OR, for resolving a mathing list.  If this
      method is called with an incorrect interface list and the boolean argument
      is true, it should abort. */
  IIR_Boolean _check_or_resolve( IIRScram_InterfaceList         *formal_list,
				 IIRScram_InterfaceList         *local_list,
				 IIR_Boolean                    resolve = true );  
  
  /** This method checks the positional part of an argument list.  It only
      blows up on errors if the second parameter is true.  It returns -1 if
      an argument didn't match. */
  IIR_Int32 _process_positional_part( IIRScram_InterfaceList *, IIR_Boolean resolve = true );

  IIRScram_InterfaceDeclaration *_find_declaration_in_formal( IIRScram_AssociationElement * );
  IIRScram_Declaration *_find_declaration( IIRScram_Name *to_find, IIRScram_InterfaceList *list );
  IIRScram_Statement *_find_formal_designator( IIRScram *formal_part );
  IIRScram_Declaration *_find_formal_declaration( IIRScram_Statement *formal_designator,
                                                  IIRScram_InterfaceList *formal_list  );
  IIRScram_Statement *_find_actual_designator( IIRScram_Statement *actual_part );

  bool _find_formal_types( IIRScram_AssociationElement *current_association,		  
			   IIRScram_Statement   *actual_part, 
			   IIRScram_Statement   *actual_designator,
			   IIRScram             *formal_part,
			   IIRScram_Statement   *formal_designator,
			   IIRScram_Declaration *formal_declaration,
			   savant::set<IIRScram_TypeDefinition> *add_types_to_me );

  IIRScram_Name *_get_formal_designator_from_indexed_name( IIRScram_IndexedName * );
  IIRScram_Statement *_get_actual_designator_from_indexed_name( IIRScram_IndexedName * );
};

#endif
