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
#define BOOST_TEST_MODULE STACK

#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>
#include <vector>
#include "stack.hh"

struct StackFixture{
   savant::stack<const char*> mystack;

   StackFixture() {}
   ~StackFixture() {}
};

BOOST_FIXTURE_TEST_SUITE( StackTestSuite, StackFixture )

BOOST_AUTO_TEST_CASE( PushPop )
{
   BOOST_CHECK( mystack.get_top_of_stack() == nullptr );
   BOOST_CHECK( mystack.pop() == nullptr );
   std::vector<const char *> tmp{ "h", "e", "l", "l", "o", "!"};
   for(auto it = tmp.begin(); it != tmp.end(); ++it) {
      mystack.push(*(it));
   }
   for(auto it = tmp.rbegin(); it != tmp.rend(); ++it) {
      BOOST_CHECK( mystack.get_top_of_stack() == (*it) );
      BOOST_CHECK( mystack.pop() == (*it) );
   }
   BOOST_CHECK( mystack.get_top_of_stack() == nullptr );
   BOOST_CHECK( mystack.pop() == nullptr );
}

BOOST_AUTO_TEST_SUITE_END()
