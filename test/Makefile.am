# Alphabetical order
check_PROGRAMS = ArgumentParserTest SetTest
TESTS = $(check_PROGRAMS)

####################
# ArgumentParserTest
####################
ArgumentParserTest_SOURCES = \
	ArgumentParserTest.cpp \
	../src/util/ArgumentParser.cpp

ArgumentParserTest_CPPFLAGS = \
   -I$(top_srcdir)/src/util/
   
ArgumentParserTest_LDADD = \
	-lboost_unit_test_framework

####################
# SetTest
####################
SetTest_SOURCES = set.cpp

SetTest_CPPFLAGS = \
   -I$(top_srcdir)/src/util/ \
   -I$(top_srcdir)/src/aire/iir/IIR \
   -I$(top_srcdir)/src/aire \
   -I$(top_srcdir)/src/

SetTest_LDADD = \
   -lboost_unit_test_framework
