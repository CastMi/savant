#ifndef IIRSCRAM_DESIGNATORLIST_HH
#define IIRSCRAM_DESIGNATORLIST_HH

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
//          Narayanan Thondugulam nthondug@ece.uc.edu
//          Krishnan Subramani  skrish@ece.uc.edu

//---------------------------------------------------------------------------

#include "IIRBase_DesignatorList.hh"
#include "IIRScram_List.hh"
#include "IRBasicDataTypes.hh"

class IIRScram_Label;
class IIRScram_Statement;
class IIRScram_Declaration;
class IIRScram;
class IIR_Statement;

class IIRScram_DesignatorList : public virtual IIRBase_DesignatorList {
public:
  IIRScram_DesignatorList() {}
  virtual ~IIRScram_DesignatorList();
    
  void _type_check_as_instantiation_list( IIRScram_Statement *instantiated_unit, 
					  IIRScram_List<IIR_Statement> *,
					  IIRScram *configuration );

  // This method walks the designator list, looking for a label for an
  // instantiate statement that instantiates "instantiated_unit".  When
  // finding one, it returns the label.
  IIRScram_Label *_process_instantiate_statement( IIRScram_Declaration *instantiated_unit,
                                                  IIRScram *statement );

private:
  void _process_by_all_or_others( IIRScram_Declaration *instantiated_unit,
				  IIRScram_List<IIRScram> *,
				  IIR_Boolean by_all,
				  IIRScram *configuration );

  void _process_explicit_list( IIRScram_Declaration *instantiated_unit, 
			       IIRScram_List<IIRScram> *,
			       IIRScram *configuration );    
};

#endif
