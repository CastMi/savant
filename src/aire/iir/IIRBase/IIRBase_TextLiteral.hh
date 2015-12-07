
#ifndef IIRBASE_TEXTLITERAL_HH
#define IIRBASE_TEXTLITERAL_HH

// Copyright (c) The University of Cincinnati.  
// All rights reserved.

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
// SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
// OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
// LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING OR
// DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the U.S.,
// and the terms of this license.

// You may modify, distribute, and use the software contained in this
// package under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE"
// version 2, June 1991. A copy of this license agreement can be found in
// the file "LGPL", distributed with this archive.

#include "savant_config.hh"
#include "IIRBase_Literal.hh"
#include "IIR_TextLiteral.hh"
#include "IIRBase_String.hh"
#include <map>

REF_FORWARD_DECL(IIR_Name);

class IIRBase_TextLiteral : public virtual IIRBase_Literal,
			    public virtual IIR_TextLiteral{

public:

  // FIXME: Constructor/Destructor should be protected
  IIRBase_TextLiteral();
  virtual ~IIRBase_TextLiteral() = 0;
  
  std::string get_text();
  IIR_Int32 get_text_length();

  /** Compares text literals. */
  static int cmp(IIR_TextLiteralRef, IIR_TextLiteralRef );
  static int cmp(IIR_TextLiteralRef, const IIR_Char * );
  static int cmp(IIR_TextLiteralRef, IIR_NameRef );

  IIRRef convert_tree(plugin_class_factoryRef factory);
 
  IIR_Boolean is_text_literal() { return TRUE; }

  // FIXME: this is an error
  IIR_TextLiteralRef get_prefix_string(){ return IIR_TextLiteralRef(this); }

  ostream &print( ostream & );

  void publish_vhdl(ostream &);
protected:

  IIRBase_StringRef text;
    
  void check_bounds( IIR_Int32 subscript );

  // This method is intended for use on NEW objects only...  (Otherwise,
  // it will leak - and an assertion will fail)
  void set_text( std::string );
private:  
  //FIXME: almost sure that this is pointless, use a simple list
  std::map<std::string, IIRBase_StringRef> mymap;
};

typedef refcount<IIRBase_TextLiteral> IIRBase_TextLiteralRef;

#endif
