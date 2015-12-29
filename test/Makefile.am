# Alphabetical order
check_PROGRAMS = ArgumentParserTest
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
