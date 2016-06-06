#ifndef IIRBASE_DECLARATION_HH
#define IIRBASE_DECLARATION_HH

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

#include "IIRBase.hh"
#include "IIR_Declaration.hh"

class IIRBase_Declaration : public virtual IIRBase, public virtual IIR_Declaration {
public:
  void set_declarator( IIR_Identifier *identifier );
  IIR_Identifier* get_declarator();

  IIR *convert_tree(plugin_class_factory *factory);

  /** These methods are referring to the region that this declaration is
      IN. */
  IIR *get_declarative_region();
  void set_declarative_region( IIR * );

  IIR_Boolean contains_body() const { return false; }

  IIR_Boolean is_incomplete_type_declaration() const { return false; }
  IIR_Boolean is_signal() const { return false; }
  bool is_work_library() const { return false; }

  /** This method tells us if a declaration is a an IIR_TypeDeclaration or
      IIR_SubtypeDeclaration. */
  IIR_Boolean is_type() { return false; }

  /** Tells us if this is a scalar type - or an object of a scalar type. */

  /** Tells us if this is a array type - or an object of a array type. */
  IIR_Boolean is_resolved() const { return true; }
  IIR_Boolean is_element() const { return false; }
  IIR_Boolean is_object() const { return false; }

  //ams additions
  /** This function tells if a quantity is an across-quantity */
  IIR_Boolean is_across_quantity() const { return false; }

  /** Sometimes implicit declarations need to be visible in the symbol table
      and sometimes they should.  deallocate( foo : some_access_type )
      should be visible.  foo'quiet will create "foo_quiet" which definitely
      shouldn't. */
  IIR_Boolean is_visible() const { return visible_flag; }
  void set_is_visible( IIR_Boolean new_flag ){ visible_flag = new_flag; }

  /** An implicit declaration is one that exists, but doesn't appear in the
      source. The two basic cases that this occurs in are declarations that
      represent the values of attributes, and implicit operators that go
      with their types. */
  void set_is_implicit( IIR_Boolean new_flag ){ implicit_flag = new_flag; }
  IIR_Boolean is_implicit_declaration(){ return implicit_flag; }

  IIR_TextLiteral *get_prefix_string();

  declaration_type get_declaration_type();
  
  /** This method looks in the declaration's declarative region for the
      declaration named by "look_for" */
  savant::set<IIR_Declaration> *find_declarations( IIR_Name * ){
    return NULL;
  }

  /** This method looks in the declaration's declarative region for the
      declaration named by "look_for". */
  savant::set<IIR_Declaration> *find_declarations( IIR_TextLiteral *){
    _report_undefined_fn("find_declarations( IIR_TextLiteral *)");
    return NULL;
  }

  ostream & print( ostream & );

  /** Since we can now have implicit declarations due to attributes, we
      need to be able to tell if THIS declaration is the result of an
      attribute. */
  IIR_Attribute *get_attribute_name();
  void set_attribute_name( IIR_Attribute * );

  IIR_Declaration *get_prefix_declaration() { return this; }
  virtual void publish_vhdl(ostream &);
  virtual void publish_vhdl_declarator_with_colon(ostream &);
protected:
  IIRBase_Declaration();
  virtual ~IIRBase_Declaration() = 0;
    
  IIR                   *declarative_region;
private:
  IIR_Boolean           implicit_flag;
  IIR_Boolean           visible_flag;
  IIR_Identifier       *declarator;

  IIR_Attribute         *attribute_name;

};
#endif
