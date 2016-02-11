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
#include "generic_parser.hh"
class IIR_DesignFileList;
class symbol_table;
class plugin_class_factory;

class VeriParser : public generic_parser {
   public:
      VeriParser(const std::string &, plugin_class_factory*, StandardPackage* );
      ~VeriParser() {};

      IIR_DesignFileList* parse_verilog(const std::vector<std::string> & c_trace_filename);

      virtual IIR_LibraryDeclaration *get_work_library() const override { assert(work_library != NULL); return work_library; };

      virtual generic_parser* convert_node(plugin_class_factory *) override;

      virtual symbol_table* get_symbol_table() const override { assert(my_sym_table != NULL); return my_sym_table; };

      virtual plugin_class_factory* get_class_factory() const override { assert(my_factory != NULL); return my_factory; };
   private:
      IIR_LibraryDeclaration* work_library;

      plugin_class_factory* my_factory;

      StandardPackage* my_package;

      symbol_table* my_sym_table;

      IIR_DesignFileList* my_design_files;

      VeriParser* transmuted_node;
};

#endif //VERILOG_PARSER_DRIVER_HPP
