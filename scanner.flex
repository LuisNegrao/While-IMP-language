%{
// HEADERS
#include <stdlib.h>
#include "parser.h"



// variables maintained by the lexical analyser
int yyline = 1;
%}

%option noyywrap



%%
[ \t]+ {  }
#.*\n { yyline++; }
\n { yyline++; }

\-?[0-9]+ {
   yylval.intValue = atoi(yytext);
   return INT;
}
"+" { return PLUS; }
"*" { return MULT; }
"-" { return SUB; }
"=" { return EQUALS; }
">" { return BIGGERTHAN; }
"<" { return SMALLERTHAN; }
"<=" { return SMALLEREQUALS; }
">=" { return BIGGEREQUALS; }
":=" { return ATTRIB; }
"WHILE" { return WHILE; }
"IF" { return IF; }
"ELSE" { return ELSE; }
"AND" { return AND; }
"OR" { return OR; }
"DO" {return DO;}
"true" {return TRUE;}
"false" {return FALSE;}
"THEN" {return THEN;}
"{" {return CE;}
"}" {return CD;}
"SKIP" {return SKIP;}
"!" {return NEG;}
[a-z][a-zA-Z0-9]* {
    yylval.Var = strdup(yytext);
    return VAR;
  }
.  { yyerror("unexpected character"); }
%%

