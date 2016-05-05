
#ifndef IIRSCRAM_ADDITION_OPERATOR_HH
#define IIRSCRAM_ADDITION_OPERATOR_HH

// Copyright (c) 1996-2003 The University of Cincinnati.  
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

// Authors: Philip A. Wilsey	philip.wilsey@ieee.org
//          Dale E. Martin	dmartin@cliftonlabs.com
//          Timothy J. McBrayer 
//---------------------------------------------------------------------------

#include "IIRScram_DyadicOperator.hh"
#include "IIRBase_AdditionOperator.hh"

class IIRScram_AdditionOperator : public virtual IIRScram_DyadicOperator, public virtual IIRBase_AdditionOperator{

public:
  IIRScram_AdditionOperator() {}
  virtual ~IIRScram_AdditionOperator() {}

  /// Accept visitations \Ref{_accept_visitor}.
  visitor_return_type* _accept_visitor(node_visitor *, visitor_argument_type *);
 
  
  IIRScram *_clone();

protected:    
private:
};
#endif
