#ifndef IIRBASE_LIST_HH
#define IIRBASE_LIST_HH

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

#include "IIR_List.hh"

template <class type>
class IIRBase_List : public virtual IIR_List<type> {
public:
  ostream &print( ostream &os );

  void publish_vhdl_decl(ostream & os, const char* = nullptr) {
    publish_vhdl_decl( os );
  }
  
  void publish_vhdl( ostream &os, const char* = nullptr );

protected:
  IIRBase_List();
  virtual ~IIRBase_List() = 0;

};
#endif
