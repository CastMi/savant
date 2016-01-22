/**
 * @author Michele Castellana <michele.castelalna@cern.ch>
 */

#ifndef VERILOG_PARSER_DRIVER_HPP
#define VERILOG_PARSER_DRIVER_HPP

#include <string>
class IIR_DesignFileList;
class plugin_class_factory;

void parse_verilog(const std::string & c_trace_filename, IIR_DesignFileList& res, plugin_class_factory* fac);

#endif //VERILOG_PARSER_DRIVER_HPP
