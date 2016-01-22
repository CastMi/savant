/**
 * @author Michele Castellana <michele.castellana@mail.polimi.it>
 */

#ifndef VERILOG_LEXER_HPP
#define VERILOG_LEXER_HPP

#undef yyFlexLexer
#define yyFlexLexer wwFlexLexer
#include <FlexLexer.h>

struct VerilogFlexLexer : public yyFlexLexer
{
   VerilogFlexLexer(std::istream& argin) : yyFlexLexer(0, 0) {};
   ~VerilogFlexLexer() {};

   void yyerror(const char * msg)
   {
      LexerError(msg);
   }

   void LexerError(const char * msg)
   {
      std::cout << msg << " at line number |" << lineno() << "|\t" ;
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
