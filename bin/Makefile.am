# Process this file with automake to produce Makefile.in

# Copyright (c) 1999-2002 The University of Cincinnati.  
# All rights reserved.

# UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
# SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
# IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
# OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
# LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING OR DISTRIBUTING
# THIS SOFTWARE OR ITS DERIVATIVES.

# By using or copying this Software, Licensee agrees to abide by the
# intellectual property laws, and all other applicable laws of the U.S.,
# and the terms of this license.

# You may modify, distribute, and use the software contained in this
# package under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE"
# version 2, June 1991. A copy of this license agreement can be found in
# the file "LGPL", distributed with this archive.

# Authors: Philip A. Wilsey	philip.wilsey@ieee.org
# 	    Dale E. Martin	dmartin@cliftonlabs.com
#	    Magnus Danielson	cfmd@swipnet.se

#---------------------------------------------------------------------------

include $(top_srcdir)/Makefile.am.common

bin_PROGRAMS = scram

scram_CPPFLAGS = \
   -I$(top_srcdir)/src \
   -I$(top_srcdir)/src/analyzer \
   -I$(top_srcdir)/src/verianalyzer \
   -I$(top_srcdir)/src/aire/iir/IIR \
   -I$(top_srcdir)/src/aire \
   -I$(top_srcdir)/src/aire/iir/IIRScram \
   -I$(top_srcdir)/src/aire/iir/IIRBase \
   -I$(top_srcdir)/src/aire/iir/visitor \
   -I$(top_srcdir)/src/util

scram_SOURCES = main.cc

# This will ask libtool to statically link scram, which is convenient
# during development.  It eases debugging quite a bit.
scram_LDFLAGS = -export-dynamic -static

scram_LDADD = \
	$(top_builddir)/src/aire/libaire.la \
	$(top_builddir)/src/util/libsavantutils.la \
	$(top_builddir)/src/verianalyzer/lib_verilog_parser.la \
	$(top_builddir)/src/analyzer/libscram.la \
	$(top_builddir)/src/libpccts.la \
	-lclutils \
	-lltdl

