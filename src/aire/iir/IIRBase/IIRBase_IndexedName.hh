
#ifndef IIRBASE_INDEXED_NAME_HH
#define IIRBASE_INDEXED_NAME_HH

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

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIRBase_Name.hh"
#include "IIR_IndexedName.hh"

class IIRBase_IndexedName : public virtual IIRBase_Name, public virtual IIR_IndexedName{

public:
  IIR_Kind get_kind() const override { return IIR_INDEXED_NAME; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_IndexedName"); }

  void set_suffix( IIRRef suffix);
  IIRRef get_suffix();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  IIR_Boolean is_resolved();
  IIR_Boolean is_signal();
  IIR_Boolean is_entity_declaration() { return TRUE; }
  IIR_Boolean is_interface();
  IIR_Boolean is_variable();

  // Override the IIR_Name default
  void set_subtype(IIR_TypeDefinitionRef type) { IIRBase::set_subtype(type); }

  IIRRef get_index( int index_num );
  void set_index( int index_num, IIRRef new_index );

  IIR_Int32 get_num_indexes();

  ostream &print( ostream & );

  IIRRef get_declarative_region();

  /** This method returns the declaration of the indexed name.  If the
      prefix is a declaration, returns it, or else, gets the declaration of
      the prefix recursively. */
  IIR_DeclarationRef get_prefix_declaration();
  void publish_vhdl(ostream &);
protected:
  IIRBase_IndexedName();
  virtual ~IIRBase_IndexedName() = 0;
    
private:
  IIRRef suffix;
};

typedef refcount<IIRBase_IndexedName> IIRBase_IndexedNameRef;

#endif
