
#ifndef IIR_DESIGN_FILE_HH
#define IIR_DESIGN_FILE_HH

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

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIR.hh"

REF_FORWARD_DECL(IIR_CommentList);
REF_FORWARD_DECL(IIR_LibraryUnitList);
REF_FORWARD_DECL(StandardPackage);
REF_FORWARD_DECL(scram);
REF_FORWARD_DECL(IIR_LibraryDeclaration);
REF_FORWARD_DECL(IIR_Identifier);

class IIR_DesignFile : public virtual IIR {

public:
  virtual ~IIR_DesignFile() {}
    
  // List accessor(s)
  virtual IIR_CommentListRef get_comments() = 0;
  virtual IIR_LibraryUnitListRef get_library_units() = 0;
  virtual void                   set_comments(IIR_CommentListRef ) = 0;
  virtual void                   set_library_units(IIR_LibraryUnitListRef ) = 0;

  virtual IIR_IdentifierRef get_name() = 0;
  virtual void                   set_name( IIR_IdentifierRef  ) = 0;

  virtual StandardPackageRef get_standard_package() = 0;
  virtual void                   set_standard_package(StandardPackageRef ) = 0;

  virtual plugin_class_factoryRef get_class_factory() = 0;
  virtual void                   set_class_factory(plugin_class_factoryRef ) = 0;

  virtual void                   set_parser( scramRef new_parser ) = 0;

  /**
     Get the library declaration what was "work" when this file was analyzed.
  */
  virtual IIR_LibraryDeclarationRef get_work_library() = 0;
};

typedef refcount<IIR_DesignFile> IIR_DesignFileRef;

#endif
