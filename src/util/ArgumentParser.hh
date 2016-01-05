#ifndef ARGUMENT_PARSER_H
#define ARGUMENT_PARSER_H

// Copyright (c) Clifton Labs, Inc.
// All rights reserved.

// CLIFTON LABS MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE
// SUITABILITY OF THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY
// DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING, RESULT OF USING,
// MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the
// U.S., and the terms of this license.

// Authors: Dale E. Martin              dmartin@ececs.uc.edu
//          Michele Castellana          michele.castellana@cern.ch

//---------------------------------------------------------------------------
// 
// $Id: ArgumentParser.h
// 
//---------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

/** The ArgumentParser class.  

    This file contains the declarations for a class which accepts a
    list of arguments with addresses of the variables they affect, and
    parses argv and argc to check for them.  Errors are dealt with as
    well.  The variables can either be boolean, char*, or
    list<char*>; which type a variable is is determined by a value
    of the enumerated type ArgumentParser::ArgType.  The last value in
    the list is a boolean that indicates if this paramter is mandatory.
    Mandatory parameters are displayed with a "*" when they are listed

    Here is an example of the use of this class:
    bool boolArg;
    bool intArg;
    string stringArg;

    static ArgumentParser::ArgRecord argList[] = {
      { "-boolArg", "help for boolean argument", &boolArg, ArgumentParser::BOOLEAN, true }, 
      { "-intArg", "help for integer argument", &intArg, ArgumentParser::INTEGER, true }, 
      { "-stringArg", "help for string argument", &stringArg, ArgumentParser::STRING, false },
    };


    int main( int argc, char *argv[] ){
      arg1 = true;    // default initialization must occur before the
      arg2 = false;   // ArgParser is called!
      arg3 = NULL;
    
      ArgumentParser ap( argList );
      ap.vectorifyArguments( argc, argv );
    }
    
*/
class ArgumentParser {
   friend std::ostream &operator<<(std::ostream &, const ArgumentParser &);
public:
  enum ArgType {BOOLEAN, INTEGER, STRING};
   
  class ArgRecord {
  public:
    const std::string argText;
    const std::string argHelp;
    void *data;
    const ArgType type;
    bool mandatoryFlag;
  };
  ArgumentParser( std::vector<ArgumentParser::ArgRecord>& recordPtr ) :
     argRecordArray( recordPtr ) {};
  ~ArgumentParser() {};

  void vectorifyArguments( int argc, char **argv, bool skipFirst = true );
  
  std::vector<std::string>& getVerilogFiles();
  std::vector<std::string>& getVHDLFiles();

  void printUsage( const std::string &binaryName, std::ostream &stream ) const;
  
private:
  std::vector<ArgRecord> argRecordArray;
  std::vector<std::string> VHDLFiles;
  std::vector<std::string> verilogFiles;
  
  /**
      Check the arguments passed in.  Will take actions as per the argument
      records passed in.

      @param args A vector containing strings representing argv in a
      traditional system.
      @param complainOnError Whether to complain about unrecognized
      arguments or not.
  */
  void checkArgs( std::vector<std::string> &args, bool = true );

  /** This method checks the arguments passed in to see if there are any in
      the form "-blah" and complains, if the global var
      "complainAndExitOnError" is set to true. */
  void checkRemaining( std::vector<std::string> &args,
		       bool complainAndExitOnError);
};

std::ostream &operator<<(std::ostream &os, const ArgumentParser &ap);

#endif
