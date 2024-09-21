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
#define BOOST_TEST_MODULE SCOPEINTRY

#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>
#include <string>
#include "symbol_table.hh"

struct ScopeEntryFixture {

   ScopeEntryFixture() {
   }
   ~ScopeEntryFixture() {
   }
};

BOOST_FIXTURE_TEST_SUITE( ScopenEntryTestSuite, ScopeEntryFixture )


BOOST_AUTO_TEST_CASE( CheckCaseSensitivityCase )
{
   scope_entry* global = new scope_entry( nullptr, nullptr );
   BOOT_CHECK( !global->is_closed() );
   BOOT_CHECK( !global->get_previous_scope() );
   BOOT_CHECK( !global->get_owner() );
   BOOT_CHECK( !global->get_scopes() );
}

BOOST_AUTO_TEST_SUITE_END()
