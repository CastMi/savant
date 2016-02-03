/**
  * Copyright CERN 2016 Michele Castellana <michele.castellana@cern.ch>
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

#ifndef VERILOG_PARSER_DRIVER_HPP
#define VERILOG_PARSER_DRIVER_HPP

#include <string>
#include <vector>
#include "StandardPackage.hh"
class IIR_DesignFileList;
class plugin_class_factory;

class VeriParser {
   public:
      VeriParser(const std::string &, plugin_class_factory*, StandardPackage* );
      IIR_DesignFileList* parse_verilog(const std::vector<std::string> & c_trace_filename);
   private:
IIR_LibraryDeclaration* work_library;
plugin_class_factory* my_factory;
StandardPackage* my_package;

};

#endif //VERILOG_PARSER_DRIVER_HPP
