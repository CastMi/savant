#ifndef IIRSCRAM_LIST_HH
#define IIRSCRAM_LIST_HH

// Copyright (c) 1996-2000 The University of Cincinnati.  
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
//          Radharamanan Radhakrishnan  ramanan@ece.uc.edu
//          Krishnan Subramani  skrish@ece.uc.edu

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIRScram.hh"
#include "IIRBase_List.hh"

REF_FORWARD_DECL(IIRScram_Label);
REF_FORWARD_DECL(IIRScram_SimpleName);

class IIRScram_List;

class IIRScram_List : public virtual IIRScram, public virtual IIRBase_List{

public:
  IIRScram_List() {};

  static IIRScram_ListRef _listcopy( IIRScram_ListRef source, plugin_class_factoryRef factory );
  
  IIR_Boolean _is_iir_list(){ return TRUE; }

  virtual IIRScramRef _clone(  );
  virtual void _clone( IIRScramRef );

  virtual IIRScram_LabelRef _find_instantiate_label( IIRScram_SimpleNameRef );
  
  /** Append all elements in this non-NULL list. */
  virtual void _append( IIR_ListRef );
  
  void _make_interface_visible( symbol_table * );

  /** This is a dangerous method - it calls delete on every member of this
      list!  Make sure you know that it's safe to delete the elements in the
      list before you call it! */
  void _destroy_list();
  
  /**
     Call _publish_cc_rvalue on every element.  Put the separator between
     the elements (except the last).
  */
  void _publish_cc_rvalues( published_file &_cc_out, const string &separator );  

  /**
     Publish any TypeInfos defined in our members.
  */
  void _publish_cc_type_info( published_file &_cc_out );

protected:  
  virtual ~IIRScram_List() = 0;
    
private:

};

typedef refcount<IIRScram_List> IIRScram_ListRef;

#endif
