#ifndef IIRBASE_CHOICE_LIST_HH
#define IIRBASE_CHOICE_LIST_HH

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

// Authors: Timothy J. McBrayer tmcbraye@ece.uc.edu

//---------------------------------------------------------------------------

#include "IIRBase_List.hh"
#include "IIR_ChoiceList.hh"
#include "IRKind.hh"

class IIR_Choice;

class IIRBase_ChoiceList : public virtual IIRBase_List<IIR_Choice>, public virtual IIR_ChoiceList {

public:
  IIR_Kind get_kind() const {return IIR_CHOICE_LIST;};
  const IIR_Char *get_kind_text() const {return "IIR_ChoiceList";};

  void publish_vhdl(ostream &);
  IIRBase_ChoiceList* convert_node(plugin_class_factory *);
protected:
  IIRBase_ChoiceList();
  virtual ~IIRBase_ChoiceList() = 0;
};
#endif
