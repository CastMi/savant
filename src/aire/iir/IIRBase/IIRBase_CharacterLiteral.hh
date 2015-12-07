
#ifndef IIRBASE_CHARACTER_LITERAL_HH
#define IIRBASE_CHARACTER_LITERAL_HH

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
#include "IIRBase_TextLiteral.hh"
#include "IIR_CharacterLiteral.hh"

class IIR_CharacterLiteral;

class IIRBase_CharacterLiteral : public virtual IIRBase_TextLiteral, public virtual IIR_CharacterLiteral{
  //friend ostream &operator<<( ostream &, IIR_CharacterLiteral & );

public:
  IIR_Kind get_kind() const override { return IIR_CHARACTER_LITERAL; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_CharacterLiteral"); }

  static IIR_CharacterLiteralRef get( IIR_CharRef new_text, IIR_Int32 new_length, plugin_class_factoryRef factory );
  static IIR_CharacterLiteralRef get( const string new_text, plugin_class_factoryRef factory );

  void release();

protected:
  IIRBase_CharacterLiteral();
  virtual ~IIRBase_CharacterLiteral() = 0;
    
private:
};

typedef refcount<IIRBase_CharacterLiteral> IIRBase_CharacterLiteralRef;

#endif
