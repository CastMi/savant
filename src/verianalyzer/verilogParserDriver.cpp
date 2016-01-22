
/**
 * @author Michele Castellana <michele.castellana@cern.ch>
 */
#include "verilogParserDriver.hpp"
#include "verilogParser.hpp"
#include <IIR_DesignFileList.hh>

void parse_verilog(const std::string & c_trace_filename, IIR_DesignFileList& res, plugin_class_factory* fac)
{
   try
   {
      std::cerr << "starting verilog parse." << std::endl;
      verilog_parse(c_trace_filename, res, fac);
      return;
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
