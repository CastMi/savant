#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE SETBASICFUN

#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>
#include <set.hh>
#include <string>

#define BLA "black"
#define BLUE "blue"
#define GRE "gre"
#define ORA "orange"
#define RED "red"
#define VIO "violet"
#define WHI "white"
#define YEL "yellow"

struct SetFixture{
   savant::set<std::string> myset;
   
   SetFixture()
   {
      myset.insert(BLUE);
      myset.insert(GRE); 
      myset.insert(RED);
      myset.insert(YEL);
      BOOST_TEST_MESSAGE( "Set with 4 elements: green, blue, red, yellow" );
   }
   ~SetFixture() {}
};

BOOST_FIXTURE_TEST_SUITE( SetTestSuite, SetFixture )

BOOST_AUTO_TEST_CASE( CheckFixtureAnd )
{
   BOOST_CHECK( myset.size() == 4 );
   BOOST_CHECK( myset.contains(BLUE) == true );
   BOOST_CHECK( myset.contains(GRE) == true );
   BOOST_CHECK( myset.contains(RED) == true );
   BOOST_CHECK( myset.contains(YEL) == true );
   BOOST_CHECK( myset.contains(BLA) == false );
   BOOST_CHECK( myset.contains(ORA) == false );
   BOOST_CHECK( myset.contains(VIO) == false );
   BOOST_CHECK( myset.contains(WHI) == false );
}

BOOST_AUTO_TEST_CASE( Erase )
{
   BOOST_CHECK( myset.erase(BLA) == 0 );
   BOOST_CHECK( myset.size() == 4 );
   BOOST_CHECK( myset.erase(ORA) == 0 );
   BOOST_CHECK( myset.size() == 4 );
   BOOST_CHECK( myset.erase(VIO) == 0 );
   BOOST_CHECK( myset.size() == 4 );
   BOOST_CHECK( myset.erase(WHI) == 0 );
   BOOST_CHECK( myset.size() == 4 );

   BOOST_CHECK( myset.erase(BLUE) == 1 );
   BOOST_CHECK( myset.size() == 3 );
   BOOST_CHECK( myset.erase(GRE) == 1 );
   BOOST_CHECK( myset.size() == 2 );
   BOOST_CHECK( myset.erase(RED) == 1 );
   BOOST_CHECK( myset.size() == 1 );
   BOOST_CHECK( myset.erase(YEL) == 1 );
   BOOST_CHECK( myset.size() == 0 );
   BOOST_CHECK( myset.empty() );
}

BOOST_AUTO_TEST_CASE( InsertSingleElement )
{
   myset.insert(BLUE);
   BOOST_CHECK( myset.size() == 4 );
   myset.insert(GRE);
   BOOST_CHECK( myset.size() == 4 );
   myset.insert(RED);
   BOOST_CHECK( myset.size() == 4 );
   myset.insert(YEL);
   BOOST_CHECK( myset.size() == 4 );

   myset.insert(BLA);
   BOOST_CHECK( myset.size() == 5 );
   myset.insert(ORA);
   BOOST_CHECK( myset.size() == 6 );
   myset.insert(VIO);
   BOOST_CHECK( myset.size() == 7 );
   myset.insert(WHI);
   BOOST_CHECK( myset.size() == 8 );
}

BOOST_AUTO_TEST_CASE( Intersect )
{
   savant::set<std::string> settoinsert;
   settoinsert.insert(GRE);
   settoinsert.insert(ORA);
   settoinsert.insert(VIO);
   settoinsert.insert(RED);
   BOOST_CHECK( settoinsert.size() == 4 );
   
   myset.intersect( &settoinsert );
   BOOST_CHECK( settoinsert.size() == 4 );
   BOOST_CHECK( myset.size() == 2 );
   BOOST_CHECK( myset.contains(GRE) == true );
   BOOST_CHECK( myset.contains(RED) == true );
   BOOST_CHECK( myset.contains(VIO) == false );
   BOOST_CHECK( myset.contains(ORA) == false );
   BOOST_CHECK( myset.contains(BLUE) == false );
   BOOST_CHECK( myset.contains(BLA) == false );
   BOOST_CHECK( myset.contains(WHI) == false );
   BOOST_CHECK( myset.contains(YEL) == false );
}

BOOST_AUTO_TEST_CASE( InsertSet )
{
   savant::set<std::string> settoinsert;
   settoinsert.insert(GRE);
   settoinsert.insert(ORA);
   settoinsert.insert(VIO);
   settoinsert.insert(RED);
   BOOST_CHECK( settoinsert.size() == 4 );
   
   myset.insert(&settoinsert);
   BOOST_CHECK( settoinsert.size() == 4 );
   BOOST_CHECK( myset.size() == 6 );
}

BOOST_AUTO_TEST_SUITE_END()
