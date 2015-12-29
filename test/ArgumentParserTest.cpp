#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ARGUMENTPARSER

#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>
#include <string>
#include <ArgumentParser.hh>

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
bool capture_comments        = false;
bool debug_symbol_table      = false;
bool gen_cc_ref              = false;
bool echo_library_dir        = false;
bool publish_vhdl            = false;
bool publish_cc              = false;
bool no_file_output          = false;
bool print_warranty          = false;
bool vhdl_93                 = false;
bool vhdl_ams                = false;
bool vhdl_2001               = false;
bool print_version           = false;
bool verbose_output          = false;
std::string design_library_name;
// Arguments recognized
std::vector<ArgumentParser::ArgRecord> arg_list = {
   {"--capture-comments","capture comments and store them in the design file IIR node", &capture_comments, ArgumentParser::BOOLEAN},
   {"--debug-symbol-table","print out debugging info relating to symbol table", &debug_symbol_table, ArgumentParser::BOOLEAN},
   {"--debug-gen-cc-ref","make code gen. and VHDL line references in c++ code", &gen_cc_ref, ArgumentParser::BOOLEAN},  
   {"--design-library-name", "design library name", &design_library_name, ArgumentParser::STRING},
   {"--echo-library-directory", "show the builtin library path as was specified at build time", &echo_library_dir, ArgumentParser::BOOLEAN},
   {"--publish-vhdl","publish VHDL", &publish_vhdl, ArgumentParser::BOOLEAN},
   {"--publish-cc","publish c++", &publish_cc, ArgumentParser::BOOLEAN},
   {"--no-file-output", "send publish_cc output to stdout instead of files", &no_file_output, ArgumentParser::BOOLEAN},
   {"--warranty-info", "print information about (lack of) warranty", &print_warranty, ArgumentParser::BOOLEAN},
   {"--vhdl-93", "setup the analyzer to process the VHDL 93 language standard (default)", &vhdl_93, ArgumentParser::BOOLEAN},
   {"--vhdl-ams", "setup the analyzer to process the VHDL AMS language standard", &vhdl_ams, ArgumentParser::BOOLEAN},
   {"--vhdl-2001", "setup the analyzer to process the VHDL 2001 language standard", &vhdl_2001, ArgumentParser::BOOLEAN},
   {"--version", "print version number and exit.", &print_version, ArgumentParser::BOOLEAN },
   {"--verbose", "verbose output", &verbose_output, ArgumentParser::BOOLEAN }
};

struct ArgumentParserFixture{
   ArgumentParser ap;

   ArgumentParserFixture() : ap(arg_list)
   {
      BOOST_TEST_MESSAGE( "The ArgumentParser arguments are correctly set" );
   }
   ~ArgumentParserFixture() {}
};

BOOST_FIXTURE_TEST_SUITE( ArgumentParserTestSuite, ArgumentParserFixture )

BOOST_AUTO_TEST_CASE( CheckCommonCase )
{
   char* ieee = "ieee";
   // simulate an argument passing
   int argc = 0;
   char *argv[] = { "progname", "--vhdl-2001", "--design-library-name", ieee, vhdlfile1, vhdlfile2, vhdlfile3, vhdlfile4, vhdlfile5, vhdlfile6, verilogfile1, verilogfile2, verilogfile3, 0 };
   for(char ** tmp = argv; *tmp != NULL; tmp++)
      argc++;

   // parse arguments
   ap.vectorifyArguments( argc, argv );

   BOOST_CHECK( vhdl_2001 == true );
   BOOST_CHECK( design_library_name.compare( std::string(ieee) ) == 0 );
   BOOST_CHECK( ap.getVHDLFiles().size() == 6 );
   BOOST_CHECK( ap.getVerilogFiles().size() == 3 );
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
