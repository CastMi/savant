
#ifndef IIRSCRAM_WAIT_STATEMENT_HH
#define IIRSCRAM_WAIT_STATEMENT_HH

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

// You may modify, distribute, and use the software contained in this package
// under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE" version 2,
// June 1991. A copy of this license agreement can be found in the file
// "LGPL", distributed with this archive.

// Authors: Philip A. Wilsey	phil.wilsey@uc.edu
//          Dale E. Martin	dmartin@cliftonlabs.com
//          Timothy J. McBrayer tmcbraye@ece.uc.edu
//          Malolan Chetlur     mal@ece.uc.edu
//          Umesh Kumar V. Rajasekaran urajasek@ece.uc.edu
//          Krishnan Subramani  skrish@ece.uc.edu
//          Narayanan Thondugulam nthondug@ece.uc.edu

//---------------------------------------------------------------------------

#include "IIRScram_SequentialStatement.hh"
#include "IIRBase_WaitStatement.hh"

class IIRScram_DesignatorList;

class IIRScram_WaitStatement : public virtual IIRScram_SequentialStatement, public virtual IIRBase_WaitStatement{

public:
  IIRScram_WaitStatement();
  ~IIRScram_WaitStatement();

  /// Accept visitations \Ref{_accept_visitor}.
  visitor_return_type* _accept_visitor(node_visitor *, visitor_argument_type *);

  void _type_check();
  IIRScram *_resolve_signal_name(IIRScram*);
  IIRScram_Statement *_clone();

  IIRScram_DesignatorList *     _get_sensitivity_list();
  IIRScram *                    _get_condition_clause();
  IIRScram *                    _get_timeout_clause();

protected:    
private:
};
#endif
