/**
 * @author Michele Castellana <michele.castellana@mail.polimi.it>
 */

#ifndef VERILOG_LEXER_HPP
#define VERILOG_LEXER_HPP

#undef yyFlexLexer
#define yyFlexLexer wwFlexLexer
#define yyalloc wwyyalloc
#define yyrealloc wwrealloc
#define yyfree wwfree
#define YY_TYPEDEF_YY_SIZE_T
typedef size_t yy_size_t;
void yyfree ( void* ptr );
void *yyrealloc (void *, yy_size_t);
void *yyalloc (yy_size_t);
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
      std::cerr << msg << " at line number |" << lineno() << "|\t" ;
      std::cout << "text is |" << YYText() << "|" << std::endl ;
      throw "Parse Error";
   }
   YYSTYPE *lvalp;
   int yylex();
   int yywrap() { return 1; }

};

#endif // VERILOG_LEXER_HPP
