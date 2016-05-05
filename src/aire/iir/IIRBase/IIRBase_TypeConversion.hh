#ifndef IIRBASE_TYPE_CONVERSION_HH
#define IIRBASE_TYPE_CONVERSION_HH

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

#include "IIRBase_Expression.hh"
#include "IIR_TypeConversion.hh"

class IIRBase_TypeConversion : public virtual IIRBase_Expression,
			       public virtual IIR_TypeConversion{
public:
  IIR_Kind get_kind() const {return IIR_TYPE_CONVERSION;}
  const IIR_Char *get_kind_text() const {return "IIR_TypeConversion";}

  void set_type_mark( IIR_TypeDefinition* type_mark);
  IIR_TypeDefinition* get_type_mark();
  void set_expression( IIR* expression);
  IIR* get_expression();

  IIR *convert_tree(plugin_class_factory *factory);

  IIR_Boolean is_locally_static();
  IIR_Boolean is_resolved();

  IIR_TypeDefinition *get_subtype();

  ostream &print( ostream & );
  void publish_vhdl(ostream &);
protected:
  
  IIRBase_TypeConversion();
  virtual ~IIRBase_TypeConversion() = 0;
    
private:
  IIR_TypeDefinition *type_mark;
  IIR *expression;
};

#endif
