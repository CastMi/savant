
#ifndef IIRBASE_PHYSICAL_LITERAL_HH
#define IIRBASE_PHYSICAL_LITERAL_HH

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
#include "IIRBase_Expression.hh"
#include "IIR_PhysicalLiteral.hh"

class IIR_PhysicalUnit;

class IIRBase_PhysicalLiteral : public virtual IIRBase_Expression,
				public virtual IIR_PhysicalLiteral{

public:

  IIR_Kind get_kind() const override { return IIR_PHYSICAL_LITERAL; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_PhysicalLiteral"); }

  void set_abstract_literal( IIRRef abstract_literal );
  IIRRef get_abstract_literal();
  void set_unit_name( IIR_PhysicalUnitRef unit );
  IIR_PhysicalUnitRef get_unit_name();
  IIR_Boolean is_locally_static();

  IIRRef convert_tree(plugin_class_factoryRef factory);
  
  IIR_Boolean is_resolved( );

  IIR_TypeDefinitionRef get_subtype();

  ostream &print( ostream & );
  void publish_vhdl(ostream &);
protected:
  
  IIRBase_PhysicalLiteral();
  virtual ~IIRBase_PhysicalLiteral() = 0;
    
private:
  IIRRef abstract_literal;
  IIR_PhysicalUnitRef unit_name;
};

typedef refcount<IIRBase_PhysicalLiteral> IIRBase_PhysicalLiteralRef;

#endif
