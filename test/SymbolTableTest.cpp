/**
  * Copyright (C) 2016 Michele Castellana <blacklion727@gmail.com>
  *
  * This source code is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This source code is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this code.  If not, see <http://www.gnu.org/licenses/>.
  **/
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE SYMBOLTABLE

#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>
#include "symbol_table.hh"
#include "scram.hh"
#include "scram_plugin_class_factory.hh"
#include "language_processing_control.hh"
#include "ScramStandardPackage.hh"
#include "IIRScram_InterfaceDeclaration.hh"
#include <string>
// to invoke the library manager
#include "library_manager.hh"
#include "IIR_LibraryDeclaration.hh"

bool debug_symbol_table;
bool parse_error;
language_processing_control* lang_proc = NULL;
bool publish_vhdl;
bool publish_cc;
std::string design_library_name;

struct SymbolTableFixture{
   symbol_table st;
   IIR_LibraryDeclaration * work_library;

   SymbolTableFixture() :
            st( ScramStandardPackage::instance() ) {
      work_library = library_manager::instance()->find_or_create_library( "work", scram_plugin_class_factory::instance() );
   }
   ~SymbolTableFixture() {}
};

BOOST_FIXTURE_TEST_SUITE( SymbolTableTestSuite, SymbolTableFixture )

BOOST_AUTO_TEST_CASE( CheckError )
{
    st.open_scope( work_library );
    IIR_DeclarationList* list;
    IIRScram_ConstantDeclaration* new_decl = new IIRScram_ConstantDeclaration();
    IIRScram_Identifier *id = IIRScram_Identifier::get( "mydecl", str, factory );
    new_decl->set_declarator( id );
    list->append(new_decl);
    st.add_declaration( list );
    st.close_scope( work_library );
}

BOOST_AUTO_TEST_CASE( CheckError )
{
    BOOST_CHECK( st.is_closed( ) == TRUE );
}

BOOST_AUTO_TEST_SUITE_END()
