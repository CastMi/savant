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

#include "verilogParserDriver.hpp"
#include "verilogParser.hpp"
#include <IIR_DesignFileList.hh>
#include "ScramStandardPackage.hh"
#include "IIRScram_DesignFile.hh"
#include "IIRBase_Identifier.hh"
#include "IIR_LibraryDeclaration.hh"
#include "library_manager.hh"

VeriParser::VeriParser(const std::string & name, plugin_class_factory* fact, StandardPackage* pack) :
   my_factory(fact),
   my_package(pack) {
   work_library = library_manager::instance()->find_or_create_library( name, fact );
   ASSERT(work_library);
   } 

IIR_DesignFileList*
VeriParser::parse_verilog(const std::vector<std::string> & c_trace_filename)
{
   try
   {
      IIR_DesignFileList* res = my_factory->new_IIR_DesignFileList();
      for (auto it = c_trace_filename.begin(); it != c_trace_filename.end(); it++) {
         std::cerr << "starting parsing file " << *it << std::endl;
         IIR_DesignFile* verilog_file = new IIRScram_DesignFile();
         verilog_file->set_standard_package( my_package );
         verilog_file->set_class_factory( my_factory );
         verilog_file->set_name( IIRBase_Identifier::get(*it, my_factory ));
         if(work_library->get_design_file() == 0)
            work_library->set_design_file(verilog_file);
         verilog_parse( *it, verilog_file, my_factory );
         res->append( verilog_file );
      }
      return res;
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
