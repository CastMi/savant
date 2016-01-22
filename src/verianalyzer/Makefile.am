# Process this file with automake to produce Makefile.in


# UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
# SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
# IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
# OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
# LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING OR
# DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

# By using or copying this Software, Licensee agrees to abide by the
# intellectual property laws, and all other applicable laws of the U.S.,
# and the terms of this license.

# You may modify, distribute, and use the software contained in this
# package under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE"
# version 2, June 1991. A copy of this license agreement can be found in
# the file "LGPL", distributed with this archive.

# Authors: Michele Castellana	michele.castellana@cern.ch

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
