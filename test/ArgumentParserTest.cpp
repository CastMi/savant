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
#define BOOST_TEST_MODULE ARGUMENTPARSER

#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>
#include <string>
#include <algorithm>
#include "ArgumentParser.hpp"

#define VHDLFILENUM 24
#define VERILOGFILENUM 2

#define initialize( VAR, STRING ) do { \
   VAR = new char [strlen( STRING ) + 1](); \
   strncpy(VAR, STRING, strlen(STRING) ); \
   } while(0)

extern bool parse_error;
extern std::string design_library_name;
extern bool capture_comments;
extern std::string work_lib_name;
extern bool debug_symbol_table;
extern bool no_file_output;
extern bool verbose_output;
extern language_processing_control *lang_proc;

struct ArgumentParserFixture {
   ArgumentParser ap;
   char *ieee;
   char *progname;
   char *vhdl93_flag;
   char *vhdl2001_flag;
   char *vhdlams_flag;
   char *help_short_flag;
   char *help_long_flag;
   char *design_library_name_flag;
   char *vhdl_file_names[VHDLFILENUM];
   char *verilog_file_names[VERILOGFILENUM];

   ArgumentParserFixture() {
      // some command line params
      initialize(ieee, "ieee");
      initialize(progname, "progname");
      initialize(vhdl93_flag, "--vhdl-93");
      initialize(vhdl2001_flag, "--vhdl-2001");
      initialize(vhdlams_flag, "--vhdl-ams");
      initialize(help_short_flag, "-h");
      initialize(help_long_flag, "--help");
      initialize(design_library_name_flag, "--design-library-name");

      // VHDL file names
      // only lower cases
      initialize(vhdl_file_names[0], "test.vhdl");
      // 1 upper case
      initialize(vhdl_file_names[1], "test.Vhdl");
      initialize(vhdl_file_names[2], "test.vHdl");
      initialize(vhdl_file_names[3], "test.vhDl");
      initialize(vhdl_file_names[4], "test.vhdL");
      // 2 upper cases
      initialize(vhdl_file_names[5], "test.VHdl");
      initialize(vhdl_file_names[6], "test.VhDl");
      initialize(vhdl_file_names[7], "test.VhdL");
      initialize(vhdl_file_names[8], "test.vHDl");
      initialize(vhdl_file_names[9], "test.vHdL");
      initialize(vhdl_file_names[10], "test.vhDL");
      // 3 upper cases
      initialize(vhdl_file_names[11], "test.VHDl");
      initialize(vhdl_file_names[12], "test.VHdL");
      initialize(vhdl_file_names[13], "test.VhDL");
      initialize(vhdl_file_names[14], "test.vHDL");
      // 4 upper cases
      initialize(vhdl_file_names[15], "test.VHDL");

      // vhd file names
      // only lower cases
      initialize(vhdl_file_names[16], "test.vhd");
      // 1 upper case
      initialize(vhdl_file_names[17], "test.Vhd");
      initialize(vhdl_file_names[18], "test.vHd");
      initialize(vhdl_file_names[19], "test.vhD");
      // 2 upper cases
      initialize(vhdl_file_names[20], "test.VHd");
      initialize(vhdl_file_names[21], "test.VhD");
      initialize(vhdl_file_names[22], "test.vHD");
      // 3 upper cases
      initialize(vhdl_file_names[23], "test.VHD");

      // Verilog file names
      initialize(verilog_file_names[0], "test.v");
      initialize(verilog_file_names[1], "test.V");
   }
   ~ArgumentParserFixture() {
      delete[] ieee;
      delete[] progname;
      delete[] vhdl93_flag;
      delete[] vhdl2001_flag;
      delete[] vhdlams_flag;
      delete[] help_short_flag;
      delete[] help_long_flag;
      delete[] design_library_name_flag;
      for(int i = 0; i < VHDLFILENUM; ++i) {
         delete[] vhdl_file_names[i];
      }
      for(int i = 0; i < VERILOGFILENUM; ++i) {
         delete[] verilog_file_names[i];
      }
   }
};

BOOST_FIXTURE_TEST_SUITE( ArgumentParserTestSuite, ArgumentParserFixture )

BOOST_AUTO_TEST_CASE( CheckError )
{
   int argc = 0;
   char *argv[] = { progname, vhdl93_flag, design_library_name_flag, ieee, vhdl_file_names[0], vhdl_file_names[1], vhdl_file_names[2], vhdl_file_names[3], vhdl_file_names[4], vhdl_file_names[5], 0 };
   for(char ** tmp = argv; *tmp != NULL; ++tmp)
      ++argc;

   // parse arguments
   BOOST_CHECK( ap.vectorifyArguments( argc, argv ) == ParsingStatus::CONTINUE_OK );

   BOOST_CHECK( ap.getLanguage() == language_processing_control::VHDL_93 );
   BOOST_CHECK( design_library_name.compare(ieee) == 0 );
   BOOST_CHECK( capture_comments == false );
#ifdef NDEBUG
   BOOST_CHECK( gen_cc_ref == false );
   BOOST_CHECK( verbose_output == false );
   BOOST_CHECK( debug_symbol_table == false );
#else
   BOOST_CHECK( gen_cc_ref == true );
   BOOST_CHECK( verbose_output == true );
   BOOST_CHECK( debug_symbol_table == true );
#endif
   BOOST_CHECK( ap.getPublishHDL() == false );
   BOOST_CHECK( ap.getPublishCC() == false );
   BOOST_CHECK( no_file_output == false );
   BOOST_CHECK( lang_proc );
   BOOST_CHECK( !parse_error );

   BOOST_CHECK( ap.getVHDLFiles().size() == 6 );
   BOOST_CHECK( ap.getVerilogFiles().size() == 0 );
}

BOOST_AUTO_TEST_CASE( CheckHelp1 )
{
   int argc = 0;
   char *argv[] = { progname, vhdlams_flag, design_library_name_flag, ieee, vhdl_file_names[0], vhdl_file_names[1], vhdl_file_names[2], vhdl_file_names[3], vhdl_file_names[4], vhdl_file_names[5], help_short_flag, 0 };
   for(char ** tmp = argv; *tmp != NULL; ++tmp)
      ++argc;

   // parse arguments
   BOOST_CHECK( ap.vectorifyArguments( argc, argv ) == ParsingStatus::EXIT_OK );

   BOOST_CHECK( ap.getLanguage() == language_processing_control::VHDL_AMS );
   BOOST_CHECK( design_library_name.compare(ieee) == 0 );
   BOOST_CHECK( capture_comments == false );
#ifdef NDEBUG
   BOOST_CHECK( gen_cc_ref == false );
   BOOST_CHECK( verbose_output == false );
   BOOST_CHECK( debug_symbol_table == false );
#else
   BOOST_CHECK( gen_cc_ref == true );
   BOOST_CHECK( verbose_output == true );
   BOOST_CHECK( debug_symbol_table == true );
#endif
   BOOST_CHECK( ap.getPublishHDL() == false );
   BOOST_CHECK( ap.getPublishCC() == false );
   BOOST_CHECK( no_file_output == false );
   BOOST_CHECK( lang_proc == nullptr );
   BOOST_CHECK( !parse_error );

   BOOST_CHECK( ap.getVHDLFiles().empty() );
   BOOST_CHECK( ap.getVerilogFiles().empty() );
}

BOOST_AUTO_TEST_CASE( CheckHelp2 )
{
   int argc = 0;
   char *argv[] = { progname, vhdl2001_flag, vhdl_file_names[0], vhdl_file_names[1], vhdl_file_names[2], vhdl_file_names[3], vhdl_file_names[4], vhdl_file_names[5], help_long_flag, 0 };
   for(char ** tmp = argv; *tmp != NULL; ++tmp)
      ++argc;

   // parse arguments
   BOOST_CHECK( ap.vectorifyArguments( argc, argv ) == ParsingStatus::EXIT_OK );

   BOOST_CHECK( ap.getLanguage() == language_processing_control::VHDL_2001 );
   BOOST_CHECK( design_library_name.compare("work") == 0 );
   BOOST_CHECK( capture_comments == false );
#ifdef NDEBUG
   BOOST_CHECK( gen_cc_ref == false );
   BOOST_CHECK( verbose_output == false );
   BOOST_CHECK( debug_symbol_table == false );
#else
   BOOST_CHECK( gen_cc_ref == true );
   BOOST_CHECK( verbose_output == true );
   BOOST_CHECK( debug_symbol_table == true );
#endif
   BOOST_CHECK( ap.getPublishHDL() == false );
   BOOST_CHECK( ap.getPublishCC() == false );
   BOOST_CHECK( no_file_output == false );
   BOOST_CHECK( lang_proc == nullptr );
   BOOST_CHECK( !parse_error );

   BOOST_CHECK( ap.getVHDLFiles().empty() );
   BOOST_CHECK( ap.getVerilogFiles().empty() );
}

BOOST_AUTO_TEST_CASE( CheckCommonCase )
{
   int argc = 0;
   char *argv[] = { progname, vhdl2001_flag, vhdl_file_names[0], vhdl_file_names[16], verilog_file_names[0], 0 };
   for(char ** tmp = argv; *tmp != NULL; ++tmp)
      ++argc;

   // parse arguments
   BOOST_CHECK( ap.vectorifyArguments( argc, argv ) == ParsingStatus::CONTINUE_OK );

   BOOST_CHECK( ap.getLanguage() == language_processing_control::VHDL_2001 );
   BOOST_CHECK( design_library_name.compare("work") == 0 );
   BOOST_CHECK( capture_comments == false );
#ifdef NDEBUG
   BOOST_CHECK( gen_cc_ref == false );
   BOOST_CHECK( verbose_output == false );
   BOOST_CHECK( debug_symbol_table == false );
#else
   BOOST_CHECK( gen_cc_ref == true );
   BOOST_CHECK( verbose_output == true );
   BOOST_CHECK( debug_symbol_table == true );
#endif
   BOOST_CHECK( ap.getPublishHDL() == false );
   BOOST_CHECK( ap.getPublishCC() == false );
   BOOST_CHECK( no_file_output == false );
   BOOST_CHECK( lang_proc );
   BOOST_CHECK( !parse_error );

   BOOST_CHECK( ap.getVHDLFiles().size() == 2 );
   BOOST_CHECK( ap.getVerilogFiles().size() == 1 );

   for(auto it = ap.getVHDLFiles().begin(); it != ap.getVHDLFiles().end(); ++it) {
      std::string current = *it;
      if( current.compare( vhdl_file_names[0] ) &&
          current.compare( vhdl_file_names[16] ) )
         BOOST_ERROR("There is at least one VHDL file that is not recognized");
   }
   for(auto it = ap.getVerilogFiles().begin(); it != ap.getVerilogFiles().end(); ++it) {
      std::string current = *it;
      if( current.compare( verilog_file_names[0] ) )
         BOOST_ERROR("There is at least one Verilog file that is not recognized");
   }
}

BOOST_AUTO_TEST_CASE( CheckCaseSensitivityCase )
{
   int argc = 0;
   char *argv[VHDLFILENUM + VERILOGFILENUM + 2 + 1];
   int j = 0;
   argv[j++] = progname;
   argv[j++] = vhdl2001_flag;
   for(int i = 0; i < VHDLFILENUM; ++i, ++j) {
      argv[j] = vhdl_file_names[i];
   }
   for(int i = 0; i < VERILOGFILENUM; ++i, ++j) {
      argv[j] = verilog_file_names[i];
   }
   argv[j] = 0;
   for(char ** tmp = argv; *tmp != NULL; ++tmp)
      ++argc;

   // parse arguments
   BOOST_CHECK( ap.vectorifyArguments( argc, argv ) == ParsingStatus::CONTINUE_OK );

   BOOST_CHECK( ap.getLanguage() == language_processing_control::VHDL_2001 );
   BOOST_CHECK( design_library_name.compare("work") == 0 );
   BOOST_CHECK( capture_comments == false );
#ifdef NDEBUG
   BOOST_CHECK( gen_cc_ref == false );
   BOOST_CHECK( verbose_output == false );
   BOOST_CHECK( debug_symbol_table == false );
#else
   BOOST_CHECK( gen_cc_ref == true );
   BOOST_CHECK( verbose_output == true );
   BOOST_CHECK( debug_symbol_table == true );
#endif
   BOOST_CHECK( ap.getPublishHDL() == false );
   BOOST_CHECK( ap.getPublishCC() == false );
   BOOST_CHECK( no_file_output == false );
   BOOST_CHECK( lang_proc );
   BOOST_CHECK( !parse_error );

   BOOST_CHECK( ap.getVHDLFiles().size() == VHDLFILENUM );
   BOOST_CHECK( ap.getVerilogFiles().size() == 2 );

   for(auto it = ap.getVHDLFiles().begin(); it != ap.getVHDLFiles().end(); ++it) {
      std::string current = *it;
      std::transform(current.begin(), current.end(), current.begin(), ::tolower);
      if( current.compare( vhdl_file_names[0] ) &&
          current.compare( vhdl_file_names[16] ) )
         BOOST_ERROR("There is at least one VHDL file that is not recognized");
   }
   for(auto it = ap.getVerilogFiles().begin(); it != ap.getVerilogFiles().end(); ++it) {
      std::string current = *it;
      std::transform(current.begin(), current.end(), current.begin(), ::tolower);
      if( current.compare( verilog_file_names[0] ) )
         BOOST_ERROR("There is at least one Verilog file that is not recognized");
   }
}

BOOST_AUTO_TEST_SUITE_END()
