# Copyright CERN 2016 Michele Castellana <michele.castellana@cern.ch>
# 
# This source code is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This source code is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this code.  If not, see <http://www.gnu.org/licenses/>.

#---------------------------------------------------------------------------

include $(top_srcdir)/Makefile.am.common

noinst_LTLIBRARIES = lib_verilog_parser.la

lib_verilog_parser_la_CPPFLAGS = \
	-I$(top_srcdir)/src/verianalizer \
	-I$(top_srcdir)/src/analyzer \
	-I$(top_srcdir)/src/aire/iir/IIR \
	-I$(top_srcdir)/src/aire/iir/visitor \
	-I$(top_srcdir)/src/aire/iir/IIRScram \
	-I$(top_srcdir)/src/aire/iir/IIRBase \
	-I$(top_srcdir)/src \
	-I$(top_srcdir)/src/util \
	-I$(top_srcdir)/src/aire

AM_YFLAGS = -d -l --report=state,lookahead,itemset
AM_LFLAGS = -L -B -+ -olex.yy.c

noinst_HEADERS = \
   verilogLexer.hpp \
   verilogParserDriver.hpp

lib_verilog_parser_la_SOURCES = \
   verilogParser.ypp \
   verilogLexer.lpp \
   verilogParserDriver.cpp

BUILT_SOURCES = verilogParser.hpp verilogLexer.cpp verilogParser.cpp

CLEANFILES = $(BUILT_SOURCES) *.output
