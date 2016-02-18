#ifndef ARGUMENT_PARSER_H
#define ARGUMENT_PARSER_H

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
 * @file ArgumentParser.hpp
 *
 * @author Michele Castellana <blacklion727@gmail.com>
 */

#include "language_processing_control.hh"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

/*
 * CONTINUE_OK -> execution can continue
 * ERROR       -> execution must finish with EXIT_FAILURE
 * EXIT_OK     -> execution must finish with EXIT_SUCCESS (for example, help message)
 */
enum ParsingStatus { CONTINUE_OK, ERROR, EXIT_OK };

class ArgumentParser {
   public:

      ArgumentParser(bool complainAndExitOnError = true);
      ~ArgumentParser();

      ParsingStatus vectorifyArguments( int argc, char **argv );

      language_processing_control::languages getLanguage() const;

      std::vector<std::string>& getVerilogFiles();
      std::vector<std::string>& getVHDLFiles();

   private:
      std::vector<std::string> VHDLFiles;
      std::vector<std::string> verilogFiles;

      ParsingStatus checkFiles(std::vector<std::string>& files);

      bool complainAndExitOnError_;     
      bool print_version_;
      bool print_help_;
      bool echo_library_dir_;
      bool print_warranty_;
      bool vhdl_93_;
      bool vhdl_ams_;
      bool vhdl_2001_;

};

#endif
