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
#define BOOST_TEST_MODULE STATICFUNTEST

#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>
#include "library_manager.hh"
#include "scram_plugin_class_factory.hh"
#include "IIRScram_Identifier.hh"
#include "IIRBase_TextLiteral.hh"
#include "IIRScram_CharacterLiteral.hh"
#include "IIRScram_StringLiteral.hh"
#include "IIRScram_BitStringLiteral.hh"
#include "IIRScram_IntegerLiteral.hh"
#include <string>

struct StaticFunFixture{
   plugin_class_factory* factory;

   StaticFunFixture() {
      factory = scram_plugin_class_factory::instance();
   }
   ~StaticFunFixture() {}
};

BOOST_FIXTURE_TEST_SUITE( StaticFunTestSuite, StaticFunFixture )

BOOST_AUTO_TEST_CASE( LibraryManagerTest )
{
   BOOST_CHECK( library_manager::instance() );
   BOOST_CHECK( !library_manager::get_savant_root_directory().empty() );
   BOOST_CHECK( !library_manager::get_entity_suffix().empty() );
   BOOST_CHECK( !library_manager::get_configuration_suffix().empty() );
   BOOST_CHECK( !library_manager::get_package_suffix().empty() );
   BOOST_CHECK( !library_manager::get_package_body_suffix().empty() );
   BOOST_CHECK( !library_manager::get_secondary_units_suffix().empty() );
   BOOST_CHECK( !library_manager::get_library_suffix().empty() );
   BOOST_CHECK( !library_manager::get_package_body_suffix().empty() );
}

BOOST_AUTO_TEST_CASE( IIRBase_TextLiteralTest )
{
   const std::string arch("architecture");
   const std::string ent("entity");

   // IIRScram_Identifier
   IIR_Identifier* a = IIRScram_Identifier::get(ent, factory);
   IIR_Identifier* b = IIRScram_Identifier::get(arch, factory);
   BOOST_CHECK( IIRBase_TextLiteral::cmp( a, b ) != 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( a, "entity" ) == 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( a, "architecture" ) != 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( b, "entity" ) != 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( b, "architecture" ) == 0 );
   a = IIRScram_Identifier::get(ent.c_str(), ent.length(), factory);
   b = IIRScram_Identifier::get(arch.c_str(), arch.length(), factory);
   BOOST_CHECK( IIRBase_TextLiteral::cmp( a, b ) > 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( a, "entity" ) == 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( a, "architecture" ) != 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( b, "entity" ) != 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( b, "architecture" ) == 0 );
   // IIRScram_CharacterLiteral
   IIRScram_CharacterLiteral* c = IIRScram_CharacterLiteral::get( ent );
   IIRScram_CharacterLiteral* d = IIRScram_CharacterLiteral::get( arch );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( c, d ) != 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( c, "entity" ) == 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( c, "architecture" ) != 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( d, "entity" ) != 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( d, "architecture" ) == 0 );
   d = IIRScram_CharacterLiteral::get( arch.c_str(), arch.length() );
   c = IIRScram_CharacterLiteral::get( ent.c_str(), ent.length() );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( c, d ) != 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( c, "entity" ) == 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( c, "architecture" ) != 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( d, "entity" ) != 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( d, "architecture" ) == 0 );
   // IIRScram_StringLiteral
   IIR_StringLiteral* e = IIRScram_StringLiteral::get( ent.c_str(), ent.length(), factory );
   IIR_StringLiteral* f = IIRScram_StringLiteral::get( arch.c_str(), arch.length(), factory );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( e, f ) != 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( e, "entity" ) == 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( e, "architecture" ) != 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( f, "entity" ) != 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( f, "architecture" ) == 0 );
   // IIRScram_BitStringLiteral
   IIRScram_BitStringLiteral* g = IIRScram_BitStringLiteral::get( ent.c_str(), ent.length() );
   IIRScram_BitStringLiteral* h = IIRScram_BitStringLiteral::get( arch.c_str(), arch.length() );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( g, h ) != 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( g, "entity" ) == 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( g, "architecture" ) != 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( h, "entity" ) != 0 );
   BOOST_CHECK( IIRBase_TextLiteral::cmp( h, "architecture" ) == 0 );
   // IIRScram_IntegerLiteral
   //IIRScram_IntegerLiteral* i = IIRScram_IntegerLiteral::get(10, "33", 3, "2", 1);
   //IIRScram_IntegerLiteral* l = IIRScram_IntegerLiteral::get(10, "4", 2, "31", 2);
   //IIRScram_FloatingPointLiteral::get();
}

BOOST_AUTO_TEST_CASE( IIRBase_Name )
{
   //BOOST_CHECK( IIRBase_TextLiteral::cmp() );
}

BOOST_AUTO_TEST_CASE( IIRBase_AccessTypeDefinition )
{
   //BOOST_CHECK( IIRBase_TextLiteral::get() );
}

BOOST_AUTO_TEST_CASE( IIRBase_StringLiteral )
{
   //BOOST_CHECK( IIRBase_TextLiteral::get() );
}

BOOST_AUTO_TEST_SUITE_END()
