
// Copyright (c) 2004 The University of Cincinnati.  
 // All rights reserved.
 // 
 // UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
 // SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 // IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
 // OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
 // LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING OR
 // DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.
 // 
 // By using or copying this Software, Licensee agrees to abide by the
 // intellectual property laws, and all other applicable laws of the U.S.,
 // and the terms of this license.
 // 
 // You may modify, distribute, and use the software contained in this
 // package under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE"
 // version 2, June 1991. A copy of this license agreement can be found in
 // the file "LGPL", distributed with this archive.
 // 
 // --------------------------------------------------------------------------

#include "XmlFile.hh"
#include "XMLChoiceList.hh"
#include "XMLCaseStatementAlternativeByChoices.hh"
#include "XMLChoiceList.hh"

XMLCaseStatementAlternativeByChoices::XMLCaseStatementAlternativeByChoices() {}
XMLCaseStatementAlternativeByChoices::~XMLCaseStatementAlternativeByChoices() {}

XMLChoiceList *
XMLCaseStatementAlternativeByChoices::_get_choices() {
  return dynamic_cast<XMLChoiceList *>(get_choices());
}

void
XMLCaseStatementAlternativeByChoices::xmlGeneration(XmlFile &file) {
  if (!bVisited) {
    // Process the node itself
    XML::xmlGeneration(file);

    // Process the variables
    _get_choices()->xmlGeneration(file);
  }
}
