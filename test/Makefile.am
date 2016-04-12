# Copyright (C) 2016 Michele Castellana <blacklion727@gmail.com>
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

check_PROGRAMS =
TESTS = $(check_PROGRAMS)

####################
# ArgumentParserTest
####################
check_PROGRAMS += ArgumentParserTest
ArgumentParserTest_SOURCES = \
	ArgumentParserTest.cpp \
	../src/util/ArgumentParser.cpp

ArgumentParserTest_CPPFLAGS = \
   -I$(top_srcdir)/src/util/ \
   -I$(top_srcdir)/src/

ArgumentParserTest_LDADD = \
	-lboost_unit_test_framework \
	-lboost_program_options

####################
# StackTest
####################
check_PROGRAMS += StackTest
StackTest_SOURCES = \
	StackTest.cpp

StackTest_CPPFLAGS = \
   -I$(top_srcdir)/src/util/ \
   -I$(top_srcdir)/src/

StackTest_LDADD = \
	-lboost_unit_test_framework
