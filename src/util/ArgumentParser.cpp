/*
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file ArgumentParser.cpp
 *
 * @author Michele Castellana <blacklion727@gmail.com>
 */

#include "ArgumentParser.hpp"
#include "savant_config.hh"
#include "version.hh"
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <boost/program_options.hpp>

#define MAX_INPUT_FILE_NUM -1

extern bool publish_vhdl;
extern bool publish_cc;
extern std::string design_library_name;
extern std::string work_lib_name;
// If the command line switch to capture comments is turned on, this flag
// will be set to true; otherwise it will be set to false. 
bool capture_comments = false;
bool debug_symbol_table;
bool gen_cc_ref;
bool no_file_output;
bool verbose_output;

ArgumentParser::ArgumentParser(bool complainAndExitOnError)
   : complainAndExitOnError_(complainAndExitOnError),
   print_version_(false),
   print_help_(false),
   echo_library_dir_(false),
   print_warranty_(false),
   vhdl_93_(false),
   vhdl_ams_(false),
   vhdl_2001_(false) {}

   ArgumentParser::~ArgumentParser() {};

ParsingStatus
ArgumentParser::vectorifyArguments( int argc, char **argv ){
   std::vector<std::string> tmp_file_vec;
   namespace po = boost::program_options;
   po::options_description desc("Options");
   desc.add_options()
      ("capture-comments",       po::value<bool>(&capture_comments)->implicit_value(true)->default_value(false)->zero_tokens(),   "Capture comments and store them in the design file IIR node" )
#ifdef NDEBUG
      // In release mode all the output flags are not set by default. They are set if the user select them.
      ("debug-gen-cc-ref",       po::value<bool>(&gen_cc_ref)->implicit_value(true)->default_value(false)->zero_tokens(),         "Make code gen. and VHDL line references in c++ code" )
      ("verbose",                po::value<bool>(&verbose_output)->implicit_value(true)->default_value(false)->zero_tokens(),     "Verbose output" )
      ("debug-symbol-table",     po::value<bool>(&debug_symbol_table)->implicit_value(true)->default_value(false)->zero_tokens(), "Print out debugging info relating to symbol table" )
#else
      // In debug mode all the output flags are set by default. They are removed if the user select.
      ("debug-gen-cc-ref",       po::value<bool>(&gen_cc_ref)->implicit_value(false)->default_value(true)->zero_tokens(),         "Make code gen. and VHDL line references in c++ code" )
      ("verbose",                po::value<bool>(&verbose_output)->implicit_value(false)->default_value(true)->zero_tokens(),     "Verbose output" )
      ("debug-symbol-table",     po::value<bool>(&debug_symbol_table)->implicit_value(false)->default_value(true)->zero_tokens(), "Print out debugging info relating to symbol table" )
#endif
      ("echo-library-directory", po::value<bool>(&echo_library_dir_)->implicit_value(true)->default_value(false)->zero_tokens(),  "Show the builtin library path as was specified at build time" )
      ("publish-vhdl",           po::value<bool>(&publish_vhdl)->implicit_value(true)->default_value(false)->zero_tokens(),       "Publish VHDL" )
      ("publish-cc",             po::value<bool>(&publish_cc)->implicit_value(true)->default_value(false)->zero_tokens(),          "Publish C++" )
      ("no-file-output",         po::value<bool>(&no_file_output)->implicit_value(true)->default_value(false)->zero_tokens(),     "Send publish_cc output to stdout instead of files" )
      ("help,h",                 po::value<bool>(&print_help_)->implicit_value(true)->default_value(false)->zero_tokens(),        "Print the help message" )
      ("warranty-info",          po::value<bool>(&print_warranty_)->implicit_value(true)->default_value(false)->zero_tokens(),    "Print information about (lack of) warranty" )
      ("vhdl-93",                po::value<bool>(&vhdl_93_)->implicit_value(true)->default_value(false)->zero_tokens(),           "Setup the analyzer to process the VHDL 93 language standard (default)" )
      ("vhdl-ams",               po::value<bool>(&vhdl_ams_)->implicit_value(true)->default_value(false)->zero_tokens(),          "Setup the analyzer to process the VHDL AMS language standard" )
      ("vhdl-2001",              po::value<bool>(&vhdl_2001_)->implicit_value(true)->default_value(false)->zero_tokens(),         "Setup the analyzer to process the VHDL 2001 language standard" )
      ("version",                po::value<bool>(&print_version_)->implicit_value(true)->default_value(false)->zero_tokens(),     "Print version number and exit." )
      // the only option that does take parameters
      ("design-library-name",    po::value<std::string>(&design_library_name)->default_value("work"),                             "Design library name" )
      ;
   po::options_description hidden;
   hidden.add_options()
      ("files",                  po::value<std::vector<std::string>>(&tmp_file_vec),                                              "Design files to compile" )
      ;

   po::options_description all_options;
   all_options.add(desc).add(hidden);
   po::positional_options_description positional;
   positional.add("files", MAX_INPUT_FILE_NUM);
   po::variables_map vm;
   try {
      po::store( po::command_line_parser(argc, argv).options(all_options).positional(positional).run(), vm);
      po::notify(vm);
   } catch (po::error& e) {
      std::cerr << "Error in argument parsing: " << e.what() << std::endl;
      std::cerr << desc << std::endl;
      return ParsingStatus::ERROR;
   }
   
   if(print_version_) {
      std::cout << VERSION << std::endl;
      return ParsingStatus::EXIT_OK;
   }

   if( echo_library_dir_ ){
      std::cout << BUILD_SAVANTROOT << "/savant/lib" << std::endl;
      return ParsingStatus::EXIT_OK;
   }

   if(print_help_) {
      std::cout << desc << std::endl;
      return ParsingStatus::EXIT_OK;
   }

   if( print_warranty_ ){
      std::cerr << SAVANT_VERSION << std::endl;
      std::cerr <<"THE UNIVERSITY OF CINCINNATI (UC) MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT\nTHE SUITABILITY OF THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT\nNOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A\nPARTICULAR PURPOSE, OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY\nDAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING RESULT OF USING, MODIFYING\nOR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.\n";
      std::cerr << "\nReport problems, comments, etc. to the savant mailing list \"savant-users@cliftonlabs.com\"." << std::endl;
      return ParsingStatus::EXIT_OK;
   }

   if( tmp_file_vec.empty() ) {
      std::cerr << "No input files" << std::endl;
      return ParsingStatus::ERROR;
   }
   assert( vhdl_93_ + vhdl_ams_ + vhdl_2001_ <= 1 );
   return checkFiles(tmp_file_vec);
}

language_processing_control::languages
ArgumentParser::getLanguage() const {
   // Invoke the language processing  object.  If no other languages are
   // selected, then recognize VHDL 93.
   if (vhdl_ams_) {
      return language_processing_control::VHDL_AMS;
   } else if (vhdl_2001_) {
       return language_processing_control::VHDL_2001;
   } else {
      return language_processing_control::VHDL_93;
   }
}

bool isVHDLExtension(const std::string input) {
   static const std::set<std::string> vhdlexts = { std::string(".vhdl"), std::string(".vhd") };
   for(auto vhdl = vhdlexts.begin(); vhdl != vhdlexts.end(); vhdl++) {
      if( input.compare( input.length() - vhdl->length(), vhdl->length(), *vhdl ) == 0 ) {
         return true;
      }
   }
   return false;
}

bool isVerilogExtension(const std::string input) {
   static const std::string verilogext(".v");
   if( input.compare( input.length() - verilogext.length(), verilogext.length(), verilogext ) == 0 ) {
      return true;
   }
   return false;
}

ParsingStatus
ArgumentParser::checkFiles(std::vector<std::string>& files) {
   for( auto it = std::find_if(files.begin(), files.end(), isVHDLExtension);
         it != files.end(); 
         it = std::find_if(files.begin(), files.end(), isVHDLExtension) ) {
      VHDLFiles.push_back( std::move(*it) );
      it = files.erase(it);
   }

   for( auto it = std::find_if(files.begin(), files.end(), isVerilogExtension);
         it != files.end(); 
         it = std::find_if(it, files.end(), isVerilogExtension) ) {
      verilogFiles.push_back( std::move(*it) );
      files.erase(it);
   }

   if( files.size() > 0 ) {
      std::cerr << "There is at least one parameter which is not a Verilog or VHDL file." << std::endl
                << "Please, make sure that the extensions are correct:" << std::endl
                << ".v for Verilog files and either .vhdl or .vhd for VHDL files." << std::endl;
      return ParsingStatus::ERROR;
   }

   return ParsingStatus::CONTINUE_OK;
}

std::vector<std::string>&
ArgumentParser::getVerilogFiles() {
   return verilogFiles;
}

std::vector<std::string>&
ArgumentParser::getVHDLFiles() {
   return VHDLFiles;
}
