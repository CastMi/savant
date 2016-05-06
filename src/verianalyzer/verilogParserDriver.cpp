/**
  * Copyright CERN 2016 Michele Castellana <michele.castellana@cern.ch>
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

#include "verilogParserDriver.hpp"
#include "verilogParser.hpp"
#include "IIR_DesignFileList.hh"
#include "IIRBase_DesignFileList.hh"
#include "ScramStandardPackage.hh"
#include "IIRScram_DesignFile.hh"
#include "IIRBase_Identifier.hh"
#include "IIR_LibraryDeclaration.hh"
#include "IIRBase_LibraryDeclaration.hh"
#include "library_manager.hh"
#include "symbol_table.hh"

VeriParser::VeriParser(const std::string & name, plugin_class_factory* fact, StandardPackage* pack) :
   my_factory(fact),
   my_package(pack),
   my_sym_table( new symbol_table(my_package) ),
   transmuted_node(NULL) {
   my_design_files = my_factory->new_IIR_DesignFileList();
   work_library = library_manager::instance()->find_or_create_library( name, fact );
   ASSERT(work_library);
   }

generic_parser *
VeriParser::convert_tre(plugin_class_factory *) {
  if (transmuted_node != NULL) {
    return transmuted_node;
  } else {
    // Transmute node
    VeriParser *result = new VeriParser(*this);
    
    if( work_library ){
      result->work_library = dynamic_cast<IIR_LibraryDeclaration *>(dynamic_cast<IIRBase_LibraryDeclaration *>(work_library)->convert_node(work_library, my_factory));
    }
    if( my_package ){
      result->my_package = 
	dynamic_cast<StandardPackage *>(my_package->convert_tree( my_factory));
    }

    if( my_design_files ){
      result->my_design_files = dynamic_cast<IIR_DesignFileList *>(dynamic_cast<IIRBase_DesignFileList *>(my_design_files)->convert_node(my_design_files, my_factory));
    }
    
    result->my_factory = my_factory;

    transmuted_node = result;
    return result;
  }
};

IIR_DesignFileList*
VeriParser::parse_verilog(const std::vector<std::string> & c_trace_filename)
{
   try
   {
      for (auto it = c_trace_filename.begin(); it != c_trace_filename.end(); it++) {
         std::cerr << "starting parsing file " << *it << std::endl;
         IIR_DesignFile* verilog_file = new IIRScram_DesignFile();
         verilog_file->set_parser( this );
         verilog_file->set_standard_package( my_package );
         verilog_file->set_class_factory( my_factory );
         verilog_file->set_name( IIRBase_Identifier::get(*it, my_factory ));
         if(work_library->get_design_file() == 0)
            work_library->set_design_file(verilog_file);
         verilog_parse( *it, work_library, my_sym_table, verilog_file, my_package, my_factory );
         my_design_files->append( verilog_file );
      }
      return my_design_files;
   }
   catch (const char * msg)
   {
      std::cerr << msg << std::endl;
   }
   catch (const std::string & msg)
   {
      std::cerr << msg << std::endl;
   }
   catch ( ... )
   {
      std::cerr << "unknown exception" << std::endl;
   }
   abort();
}
