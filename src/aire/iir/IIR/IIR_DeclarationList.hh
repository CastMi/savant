
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

#include "savant_config.hh"
#include "IIR_List.hh"
#include "set.hh"

REF_FORWARD_DECL(IIR_Name);
class IIR_Declaration;
class IIR_TextLiteral;

class IIR_DeclarationList : public virtual IIR_List{

public:
  virtual ~IIR_DeclarationList() {}
  
  virtual void append( IIR_DeclarationRef ) = 0;
  virtual void prepend( IIR_DeclarationRef ) = 0;

  virtual IIRRef successor( IIR_DeclarationRef  ) = 0;
  virtual IIRRef predecessor( IIR_DeclarationRef  ) = 0;

  virtual IIRRef first() = 0;
  virtual IIRRef last() = 0;

  virtual IIRRef get_nth_element( IIR_Int32 ) = 0;

  virtual savant::set<IIR_DeclarationRef> find_declarations( IIR_NameRef  ) { return savant::set<IIR_DeclarationRef>(); }
  virtual savant::set<IIR_DeclarationRef> find_declarations( IIR_TextLiteralRef ) { return savant::set<IIR_DeclarationRef>(); }

  /**
     Makes the declarative region of all of the elements in this list point
     to the new region passed in.
  */
  virtual void set_declarative_region( IIRRef  ) = 0;
};

typedef refcount<IIR_DeclarationList> IIR_DeclarationListRef;

#endif
