#ifndef IIR_NAME_HH
#define IIR_NAME_HH

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

#include "IIR_Statement.hh"

class IIR_Name : public virtual IIR_Statement {

public:
  virtual ~IIR_Name() {}

  //@{
  /// All names have a prefix.
  virtual void set_prefix( IIR_Statement *prefix ) = 0;
  virtual IIR_Statement *get_prefix() const = 0;
  //@}

  //@{
  // Selected names and indexed names can have a suffix.
  virtual void set_suffix( IIR_Statement *suffix ) = 0;
  virtual IIR_Statement *get_suffix() const = 0;
  //@}
};
#endif
