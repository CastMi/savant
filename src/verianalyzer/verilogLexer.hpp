/**
  * Copyright CERN 2016 Michele Castellana <michele.castellana@cern.ch>
  * Copyright (C) 2016 Michele Castellana <blacklion727@gmail.com>
  *
  * This source code is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This source code is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this code.  If not, see <http://www.gnu.org/licenses/>.
  **/

#ifndef VERILOG_LEXER_HPP
#define VERILOG_LEXER_HPP

#undef yyFlexLexer
#define yyFlexLexer wwFlexLexer
#undef YY_DECL
#define YY_DECL int VerilogFlexLexer::yylex()
//#define yywrap wwwrap
#define yyalloc wwalloc
#define yyrealloc wwrealloc
#define yyfree wwfree
#define YY_TYPEDEF_YY_SIZE_T
typedef size_t yy_size_t;
void yyfree( void* ptr );
void *yyrealloc( void*, yy_size_t );
void *yyalloc( yy_size_t );
#include <FlexLexer.h>

struct VerilogFlexLexer : public yyFlexLexer
{
   VerilogFlexLexer(std::istream* argin , std::ostream* argout = nullptr );
   VerilogFlexLexer();
   ~VerilogFlexLexer();

   void yyerror(const char * msg)
   {
      LexerError(msg);
   }

   void LexerError(const char * msg)
   {
      std::cout << "Error: " << msg << " at line number |" << lineno() << "|\t" ;
      std::cout << "text is |" << YYText() << "|" << std::endl ;
      throw "Parse Error";
   }

   int yywrap()
   {
      return 1;
   }
   YYSTYPE *lvalp;
   int  yylex();
};

#endif // VERILOG_LEXER_HPP
