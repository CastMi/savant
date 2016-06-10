#ifndef IIR_DECLARATION_LIST_HH
#define IIR_DECLARATION_LIST_HH

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

#include "IIR_List.hh"
#include "IIR_Declaration.hh"
#include "set.hh"
#include <type_traits>
#include <typeinfo>
#include <string>

class IIR_Name;
class IIR_TextLiteral;

template <typename param = IIR_Declaration>
class IIR_DeclarationList : public virtual IIR_List<param> {
static_assert(std::is_base_of<IIR_Declaration, param>::value,
      "ERROR: not a subclass of IIR_Declaration");
public:
  virtual ~IIR_DeclarationList() {}
  
  virtual savant::set<IIR_Declaration> *find_declarations( IIR_Name *  ) { return NULL; }
  virtual savant::set<IIR_Declaration> *find_declarations( IIR_TextLiteral * ) { return NULL; }

  /**
     Makes the declarative region of all of the elements in this list point
     to the new region passed in.
  */
  virtual void set_declarative_region( IIR * ) = 0;
  virtual IIR_DeclarationList<param>* convert_node(plugin_class_factory *) = 0;
};
#endif
