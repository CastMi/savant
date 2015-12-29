#ifndef IIRSCRAM_STRING_LITERAL_HH
#define IIRSCRAM_STRING_LITERAL_HH

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
#include "IIRScram_TextLiteral.hh"
#include "IIRBase_StringLiteral.hh"

class IIRScram_StringLiteral : public virtual IIRScram_TextLiteral, public virtual IIRBase_StringLiteral{
public:
  /// Accept visitations \Ref{_accept_visitor}.
  visitor_return_type* _accept_visitor(node_visitor *, visitor_argument_type *);

  void _type_check( savant::set<IIRScram_TypeDefinition*> * );

  IIR_Boolean _is_string_literal(){ return TRUE; }

  savant::set<IIRScram_TypeDefinition*> *_get_rval_set(constraint_functor *functor = 0 );
  IIRScram *_clone();
protected:
private:
};
#endif
