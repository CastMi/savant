
#ifndef IIRBASE_ELSIF_HH
#define IIRBASE_ELSIF_HH

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
#include "IIRBase_Tuple.hh"
#include "IIR_Elsif.hh"

class IIR_SequentialStatementList;

class IIRBase_Elsif : public virtual IIRBase_Tuple, public virtual IIR_Elsif{

public:
  // List Accessor(s)
  IIR_SequentialStatementListRef get_then_sequence_of_statements();
  void                        set_then_sequence_of_statements(IIR_SequentialStatementListRef new_then_sequence_of_statements);

  IIR_Kind get_kind() const override { return IIR_ELSIF; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_Elsif"); }

  void set_condition(IIRRef);
  IIRRef get_condition();

  void set_else_clause(IIR_ElsifRef);
  IIR_ElsifRef get_else_clause();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  void publish_vhdl(ostream &);
protected:
  IIRBase_Elsif();
  virtual ~IIRBase_Elsif() = 0;
    
private:
  // List Variable(s)
  IIR_SequentialStatementListRef then_sequence_of_statements;

  IIRRef condition;  
  IIR_ElsifRef else_clause;
};

typedef refcount<IIRBase_Elsif> IIRBase_ElsifRef;

#endif
