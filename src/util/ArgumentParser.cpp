// Copyright (c) The University of Cincinnati.  
// All rights reserved.

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF 
// THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE
// FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
// RESULT OF USING, MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS
// DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the
// U.S., and the terms of this license.

// Authors: Malolan Chetlur             mal@ececs.uc.edu
//          Jorgen Dahl                 dahlj@ececs.uc.edu
//          Dale E. Martin              dmartin@ececs.uc.edu
//          Radharamanan Radhakrishnan  ramanan@ececs.uc.edu
//          Dhananjai Madhava Rao       dmadhava@ececs.uc.edu
//          Philip A. Wilsey            phil.wilsey@uc.edu
//          Michele Castellana          michele.castellana@cern.ch

//---------------------------------------------------------------------------
// 
// $Id: ArgumentParser.cpp
// 
//---------------------------------------------------------------------------

#include "ArgumentParser.hh"
#include <set>

using std::endl;

bool
ArgumentParser::vectorifyArguments( int argc, char **argv, bool skipFirst ){
   std::vector<std::string> retval;
   int i;
   if( skipFirst ){
      i = 1;
   }
   else{
      i = 0;
   }
   for( ; i < argc; i++ ){
      retval.push_back( std::string( argv[i] ) );
   }
   return checkArgs( retval, true );
}


bool 
ArgumentParser::checkArgs( std::vector<std::string> &args, bool caxoe ){
   // complain_and_exit_on_error defaults to true...
   // This loop cycles through the arguments.
   for( std::vector<std::string>::iterator currentArgument = args.begin();
         currentArgument < args.end(); 
         currentArgument++ ) {
      // This loop compares the arguments passed in with those we're
      // checking them against
      bool matchedOne = false;
      for( std::vector<ArgRecord>::iterator currentRecord = argRecordArray.begin();
            currentRecord < argRecordArray.end() && currentArgument < args.end(); ) {
         // the first check is necessary because args.size() can change during
         // execution...
         if( *currentArgument == (*currentRecord).argText ){
            matchedOne = true;
            switch( (*currentRecord).type) {
               case BOOLEAN:{
                               // They matched - let's read in the data
                               *(reinterpret_cast<bool *>((*currentRecord).data)) = true;
                               args.erase( currentArgument );
                               break;
                            };
               case INTEGER:{
                               // Step to the next argument for the value
                               int endPos;
                               currentArgument++;
                               try {
                                  *(reinterpret_cast<int *>((*currentRecord).data)) = std::stol ( *currentArgument );
                               } catch (...) {
                                  std::cerr << "Invalid \"" << ((*currentRecord).argText) << "\" parameter\n";
                                  std::cerr << "Valid arguments: \n";
                                  std::cerr << *this << std::endl;
                                  exit( -1 );
                               }
                               // Step back to the flag
                               currentArgument--;
                               // Erase it
                               args.erase( currentArgument );
                               // Will step up to the value
                               // Erase it...
                               args.erase( currentArgument );
                               break;
                            }
               case STRING:{
                              // Advance to input string
                              currentArgument++;
                              *(reinterpret_cast<std::string *>((*currentRecord).data)) = (*currentArgument);
                              // Walk back to arg flag
                              currentArgument--;
                              // Erase it
                              args.erase( currentArgument );
                              // Erase the string.
                              args.erase( currentArgument );
                              break;
                           }
               default:{
                          // Do nothing...
                          break;
                       }
            }
         }
         if( matchedOne == true ){
            // Reset the args pointer and record pointer.
            currentArgument = args.begin();
            currentRecord = argRecordArray.begin();
            matchedOne = false;
         }
         else{
            currentRecord++;
         }
      } // currentRecord
   } // currentArg

   return checkRemaining( args, caxoe );
}

std::vector<std::string>&
ArgumentParser::getVerilogFiles() {
   return verilogFiles;
}

std::vector<std::string>&
ArgumentParser::getVHDLFiles() {
   return VHDLFiles;
}

bool 
ArgumentParser::checkRemaining( std::vector<std::string> &args,
      bool complainAndExitOnError ) {
   const std::set<std::string> vhdlext = { std::string(".vhdl"), std::string(".vhd") };
   const std::set<std::string> verilogext = { std::string(".v") };

   for( std::vector<std::string>::iterator it = args.begin();
         it != args.end();
         it++ ) {
      std::string currentArg = *it;
      if( !currentArg.compare("-help") || !currentArg.compare("--help") ){
         std::cout << "Valid arguments are:\n";
         std::cout << *this << std::endl;
         exit(EXIT_SUCCESS);
      }

      if( currentArg[0] == '-' ){
         std::cerr << "Invalid argument \"" << currentArg << "\"\n";
         // Then someone passed in an illegal argument!
         if(  complainAndExitOnError == true) {
            std::cerr << "Valid arguments: \n";
            std::cerr << *this << std::endl;
            return false;
         }
      }

      for( auto vhdl = vhdlext.begin(); vhdl != vhdlext.end(); vhdl++ ) {
         if ( currentArg.compare( currentArg.length() - (*vhdl).length(), (*vhdl).length(), *vhdl ) == 0 ) {
            VHDLFiles.push_back(currentArg);
            break;
         }
      }
      for( auto verilog = verilogext.begin(); verilog != verilogext.end(); verilog++ ) {
         if ( currentArg.compare( currentArg.length() - (*verilog).length(), (*verilog).length(), *verilog ) == 0 ) {
            verilogFiles.push_back(currentArg);
            break;
         }
      }

   }
   if(verilogFiles.size() + VHDLFiles.size() != args.size()) {
      std::cerr << "Invalid command line parameter\n";
      return false;
   }
   return true;
}

void
ArgumentParser::printUsage( const std::string &binaryName, std::ostream &stream ) const {
   stream << "Usage: " << binaryName << " <options>" << endl;
   stream << *this;
}


std::ostream &
operator<<( std::ostream &os, const ArgumentParser &ap ){
   const unsigned int numSpaces = 3;
   const unsigned int indentation = 2;

   // calculate the length of the longest argument
   unsigned int maxlen = 0;
   for( std::vector<ArgumentParser::ArgRecord>::const_iterator currentRecord =
         ap.argRecordArray.begin();
         currentRecord <  ap.argRecordArray.end();
         currentRecord++ ){
      if( (*currentRecord).argText.length() > maxlen ){
         maxlen = (*currentRecord).argText.length();
      }
   }

   // print the argument array
   for( std::vector<ArgumentParser::ArgRecord>::const_iterator currentRecord =
         ap.argRecordArray.begin();
         currentRecord <  ap.argRecordArray.end();
         currentRecord++ ){
      // indent the proper amount
      for( unsigned int j = 0; j < indentation; j++ ){
         os << " ";
      }

      // a note if this argument is mandatory...
      if ( (*currentRecord).mandatoryFlag == true) {
         os << "* ";
      }
      else {
         os << "  ";
      }

      // here is the argument
      os << (*currentRecord).argText;

      // print out the padding - leave num_spaces spaces between args and 
      // help text...
      for( unsigned int j = 0;
            j < (maxlen - (*currentRecord).argText.length()) + numSpaces;
            j++ ){
         os << " ";
      }

      // here is the help string.
      os << (*currentRecord).argHelp << std::endl;
   }

   for( unsigned int j = 0; j < indentation; j++ ){
      os << " ";
   }

   os << "  -help";
   for( unsigned int j = 0; j < maxlen - strlen("-help")  + numSpaces; j++ ){
      os << " ";
   }
   os << "print this message" << std::endl;

   return os;
}
