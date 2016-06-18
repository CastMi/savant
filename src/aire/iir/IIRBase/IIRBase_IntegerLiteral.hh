#ifndef IIRBASE_INTEGER_LITERAL_HH
#define IIRBASE_INTEGER_LITERAL_HH

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

#include "IIRBase_Literal.hh"
#include "IIR_IntegerLiteral.hh"

class IIRBase_IntegerLiteral : public virtual IIRBase_Literal, public virtual IIR_IntegerLiteral{
  friend class VHDLParser;

public:
  IIR_Kind get_kind() const {return IIR_INTEGER_LITERAL;}
  const IIR_Char *get_kind_text() const {return "IIR_IntegerLiteral";}

  const string print(IIR_Int32);

  void set_base(IIR_Int32);
  IIR_Int32 get_base();
  void set_mantissa(IIR_Char*, IIR_Int32);
  IIR_Char* get_mantissa();
  IIR_Int32 get_mantissa_length();
  void set_exponent(IIR_Char*, IIR_Int32);
  IIR_Char* get_exponent();
  IIR_Int32 get_exponent_length();
  IIR_Int32 get_integer_value();

  IIR_IntegerLiteral *convert_tree(plugin_class_factory *factory);

  ostream &print( ostream & );
  const string print_value(IIR_Int32);
  void publish_vhdl(ostream &);
  void publish_vhdl_range(ostream &);
  
  IIR_Boolean is_negative();

protected:
  IIRBase_IntegerLiteral();
  virtual ~IIRBase_IntegerLiteral() = 0;
    
private:
  IIR_Int32 base;
  IIR_Char *mantissa;
  IIR_Int32 mantissa_length;
  IIR_Char *exponent;
  IIR_Int32 exponent_length;
};

#endif
