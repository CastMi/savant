
#ifndef IIRBASE_AGGREGATE_HH
#define IIRBASE_AGGREGATE_HH

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
#include "IIRBase_Expression.hh"
#include "IIR_Aggregate.hh"

class IIR_AssociationList;
class IIRBase_Aggregate : public virtual IIRBase_Expression,
			  public virtual IIR_Aggregate{
public:
  // List Accessor(s)
  IIR_AssociationListRef get_element_association_list();
  void                set_element_association_list(IIR_AssociationListRef new_element_association_list);

  IIR_Kind get_kind() const override { return IIR_AGGREGATE; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_Aggregate"); }

  IIRRef convert_tree(plugin_class_factoryRef factory);

  IIR_Boolean is_resolved( );
  IIR_Boolean is_signal( );
  IIR_Boolean is_aggregate_expression(){ return TRUE; }
  IIR_Boolean is_variable( );
  IIR_Boolean is_locally_static();

  ostream &print( ostream & );

  IIR_DeclarationRef get_prefix_declaration() { return NULL; }
  void publish_vhdl(ostream &);
protected:
  IIRBase_Aggregate();
  virtual ~IIRBase_Aggregate() = 0;    

private:
  // List Variable(s)
  IIR_AssociationListRef element_association_list;
};

typedef refcount<IIRBase_Aggregate> IIRBase_AggregateRef;

#endif
