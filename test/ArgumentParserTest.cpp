#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ARGUMENTPARSER

#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>
#include <string>
#include <ArgumentParser.hpp>

#define vhdlfile1 "test.vhdl"
#define vhdlfile2 "test.vhd"
#define vhdlfile3 "abc.vhdl"
#define vhdlfile4 "abc.vhd"
#define vhdlfile5 "name.vhdl"
#define vhdlfile6 "name.vhd"
#define verilogfile1 "test.v"
#define verilogfile2 "abc.v"
#define verilogfile3 "name.v"

// The following code comes from the main.cc
bool publish_vhdl;
bool publish_cc;
bool print_warranty;
std::string design_library_name;

struct ArgumentParserFixture{
   ArgumentParser ap;

   ArgumentParserFixture() {
      publish_vhdl = false;
      print_warranty = false;
      design_library_name.erase();
   }
   ~ArgumentParserFixture() {}
};

BOOST_FIXTURE_TEST_SUITE( ArgumentParserTestSuite, ArgumentParserFixture )

BOOST_AUTO_TEST_CASE( CheckError )
{
   char* ieee = "ieee";
   // simulate an argument passing
   int argc = 0;
   char *argv[] = { "progname", "--vhdl-93", "--design-library-name", ieee, vhdlfile1, vhdlfile2, vhdlfile3, vhdlfile4, vhdlfile5, vhdlfile6, 0 };
   for(char ** tmp = argv; *tmp != NULL; tmp++)
      argc++;

   // parse arguments
   BOOST_CHECK( ap.vectorifyArguments( argc, argv ) == ParsingStatus::CONTINUE_OK );
   BOOST_CHECK( ap.getLanguage() == language_processing_control::VHDL_93 );
   BOOST_CHECK( ap.getLanguage() == language_processing_control::VHDL_93 );
   BOOST_CHECK( design_library_name.compare(ieee) == 0 );

}

BOOST_AUTO_TEST_CASE( CheckHelp1 )
{
   char* ieee = "ieee";
   // simulate an argument passing
   int argc = 0;
   char *argv[] = { "progname", "--vhdl-ams", "--design-library-name", ieee, vhdlfile1, vhdlfile2, vhdlfile3, vhdlfile4, vhdlfile5, vhdlfile6, "-h", 0 };
   for(char ** tmp = argv; *tmp != NULL; tmp++)
      argc++;

   BOOST_CHECK( ap.vectorifyArguments( argc, argv ) == ParsingStatus::EXIT_OK );
   BOOST_CHECK( ap.getLanguage() == language_processing_control::VHDL_AMS );
   BOOST_CHECK( ap.getVHDLFiles().empty() );
   BOOST_CHECK( ap.getVerilogFiles().empty() );
   BOOST_CHECK( design_library_name.compare(ieee) == 0 );

}

BOOST_AUTO_TEST_CASE( CheckHelp2 )
{
   // simulate an argument passing
   int argc = 0;
   char *argv[] = { "progname", "--vhdl-2001", vhdlfile1, vhdlfile2, vhdlfile3, vhdlfile4, vhdlfile5, vhdlfile6, "--help", 0 };
   for(char ** tmp = argv; *tmp != NULL; tmp++)
      argc++;

   BOOST_CHECK( ap.vectorifyArguments( argc, argv ) == ParsingStatus::EXIT_OK );
   BOOST_CHECK( ap.getVHDLFiles().empty() );
   BOOST_CHECK( ap.getVerilogFiles().empty() );
   BOOST_CHECK( design_library_name.compare("work") == 0 );

}

BOOST_AUTO_TEST_CASE( CheckCommonCase )
{
   // simulate an argument passing
   int argc = 0;
   char *argv[] = { "progname", "--vhdl-2001", vhdlfile1, vhdlfile2, vhdlfile3, vhdlfile4, vhdlfile5, vhdlfile6, verilogfile1, verilogfile2, verilogfile3, 0 };
   for(char ** tmp = argv; *tmp != NULL; tmp++)
      argc++;

   // parse arguments
   BOOST_CHECK( ap.vectorifyArguments( argc, argv ) == ParsingStatus::CONTINUE_OK );

   BOOST_CHECK( ap.getLanguage() == language_processing_control::VHDL_2001 );
   BOOST_CHECK( ap.getVHDLFiles().size() == 6 );
   BOOST_CHECK( ap.getVerilogFiles().size() == 3 );
   BOOST_CHECK( design_library_name.compare("work") == 0 );
   for(auto it = ap.getVHDLFiles().begin(); it != ap.getVHDLFiles().end(); it++) {
      const std::string current = *it;
      if( current.compare(vhdlfile1) &&
          current.compare(vhdlfile2) &&
          current.compare(vhdlfile3) &&
          current.compare(vhdlfile4) &&
          current.compare(vhdlfile5) &&
          current.compare(vhdlfile6) )
         BOOST_ERROR("There is at least one VHDL file that is not recognized");
   }
   for(auto it = ap.getVerilogFiles().begin(); it != ap.getVerilogFiles().end(); it++) {
      const std::string current = *it;
      if( current.compare(verilogfile1) &&
          current.compare(verilogfile2) &&
          current.compare(verilogfile3) )
         BOOST_ERROR("There is at least one Verilog file that is not recognized");
   }
}

BOOST_AUTO_TEST_SUITE_END()
