#ifndef IIRBASE_ATTRIBUTE_HH
#define IIRBASE_ATTRIBUTE_HH

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

#include "IIRBase_Name.hh"
#include "IIR_Attribute.hh"

class IIRBase_Attribute : public virtual IIRBase_Name,
			  public virtual IIR_Attribute{

public:

  virtual void set_suffix(IIR_Statement *);
  virtual IIR_Statement* get_suffix() const {return NULL;}

  IIR_Boolean is_locally_static();
  IIR_Boolean is_resolved() const;
  IIR_Boolean is_signal() const { return false; };
  IIR_Boolean is_value_attribute() const { return false; }
  IIR_Boolean is_function_attribute() const { return false; }
  IIR_Boolean is_above_attribute() const { return false; }
  IIR_Boolean has_suffix() { return false; }

  void set_subtype(IIR_TypeDefinition *type) {IIRBase_Statement::set_subtype(type);}
  
  ostream &print( ostream &os );

  /** This returns an IIR_TextLiteral with the name of whatever attribute
      was instantiated. */

  IIR_Identifier *get_attribute_name();
  IIR_Identifier *build_attribute_name();

  IIR_Attribute *convert_tree(plugin_class_factory *factory);
protected:
  IIRBase_Attribute();
  virtual ~IIRBase_Attribute() = 0;
    
private:

  IIR_Identifier *my_attribute_name;

};
#endif
