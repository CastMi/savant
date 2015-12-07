
#ifndef IIRBASE_ALLOCATOR_HH
#define IIRBASE_ALLOCATOR_HH

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
//          Timothy J. McBrayer tmcbraye@ece.uc.edu

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIRBase_Expression.hh"
#include "IIR_Allocator.hh"

class IIR_TypeDefinition;

class IIRBase_Allocator : public virtual IIRBase_Expression, public virtual IIR_Allocator{

public:
  IIR_Kind get_kind() const { return IIR_ALLOCATOR; }
  IIR_CharConstRef get_kind_text() const { return IIR_CharConstRef("IIR_Allocator"); }

  void set_type_mark( IIR_TypeDefinitionRef );
  IIR_TypeDefinitionRef get_type_mark();

  void set_value( IIRRef );
  IIRRef get_value();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  virtual IIR_Boolean is_resolved();

  ostream &print( ostream &os );
  void publish_vhdl(ostream &);
protected:
  IIRBase_Allocator();
  virtual ~IIRBase_Allocator() = 0;
    
private:
  IIR_TypeDefinitionRef type_mark;
  IIRRef value;
};

typedef refcount<IIRBase_Allocator> IIRBase_AllocatorRef;

#endif
