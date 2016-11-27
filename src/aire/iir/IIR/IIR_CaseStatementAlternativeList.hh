
#ifndef IIR_CASE_STATEMENT_ALTERNATIVE_LIST_HH
#define IIR_CASE_STATEMENT_ALTERNATIVE_LIST_HH

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

#include "IIR_List.hh"
#include "IRBasicDataTypes.hh"

class IIR_CaseStatementAlternative;
class plugin_class_factory;

class IIR_CaseStatementAlternativeList : public virtual IIR_List<IIR_CaseStatementAlternative> {

public:
  virtual ~IIR_CaseStatementAlternativeList() {}
    
  virtual IIR_Boolean is_resolved() = 0;
  virtual IIR_Boolean is_above_attribute_found() = 0;
  virtual IIR_CaseStatementAlternativeList* convert_node(plugin_class_factory *factory) = 0;
};

#endif
