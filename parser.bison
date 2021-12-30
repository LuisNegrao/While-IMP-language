
// Tokens
%token
  INT TRUE FALSE
  PLUS MULT SUB
  EQUALS BIGGERTHAN SMALLERTHAN BIGGEREQUALS SMALLEREQUALS AND OR
  ATTRIB IF THEN ELSE WHILE VAR DO SKIP
  CE CD



// Operator associativity & precedence

%left EQUALS NOTEQUALS BIGGERTHAN SMALLERTHAN BIGGEREQUALS SMALLEREQUALS AND OR
%left SUB PLUS
%left MULT
%left ATTRIB IF THEN ELSE WHILE SKIP

// Root-level grammar symbol
%start program;

// Types/values in association to grammar symbols.
%union {
  int intValue;
  struct Expression* expression;
  char* Var;
  char* False;
  char* True;
  struct BooleanOperation* booleanOperation;
  struct CommandList* cmdList;
  struct Command* command;
}

%type <intValue> INT
%type <expression> expr
%type <Var> VAR
%type <True> TRUE
%type <False> FALSE
%type <booleanOperation> bExpr
%type <cmdList> commandList
%type <command> command



// Use "%code requires" to make declarations go
// into both parser.c and parser.h
%code requires {

#include <stdio.h>
#include <stdlib.h>
#include "language.h"

extern int yylex();
extern int yyline;
extern char* yytext;
extern FILE* yyin;
extern void yyerror(const char* msg);
//extern struct CommandList* root;
}

%%
program: commandList {buildProgram($1);}

expr:
  INT {
    $$ = buildInteger($1);
  }
  |
  expr PLUS expr {
    $$ = buildOperation(PLUS, $1, $3);
  }
  |
  expr MULT expr {
    $$ = buildOperation(MULT, $1, $3);
  }
  |
  expr SUB expr {
    $$ = buildOperation(SUB, $1, $3);
  }
  |
  VAR {
    $$ = buildVariable($1);
  }

;
bExpr:
  TRUE {
    $$ = buildBoolean($1);
  }
  |
  FALSE {
    $$ = buildBoolean($1);
  }
  |
  expr EQUALS expr{
    $$ = buildBooleanOperation(EQUALS, $1, $3);
  }
  |
  expr NOTEQUALS expr{
    $$ = buildBooleanOperation(NOTEQUALS, $1, $3);
  }
  |
  expr BIGGERTHAN expr{
    $$ = buildBooleanOperation(BIGGERTHAN, $1, $3);
  }
  |
  expr SMALLERTHAN expr{
    $$ = buildBooleanOperation(SMALLERTHAN, $1, $3);
  }
  |
  expr BIGGEREQUALS expr{
    $$ = buildBooleanOperation(BIGGEREQUALS, $1, $3);
  }
  |
  expr SMALLEREQUALS expr{
    $$ = buildBooleanOperation(SMALLEREQUALS, $1, $3);
  }
  |
  bExpr AND bExpr{
    $$ = buildAndOrOperation(AND, $1, $3);
  }
  |
  bExpr OR bExpr{
    $$ = buildAndOrOperation(OR, $1, $3);
  }
  |
   VAR {
      $$ = buildBooleanVariable($1);
    }
  ;

command:
   VAR ATTRIB expr{
     $$ = buildAttrib($1,$3);
   }
   |
   VAR ATTRIB bExpr{
     $$ = buildBooleanAttrib($1,$3);
   }
   |
  WHILE bExpr DO CE commandList CD {
    $$ = buildWhile($2,$5);
   }
   |
  IF  bExpr THEN CE commandList CD {
    $$ = buildIf($2,$5);
   }
   |
  IF  bExpr THEN CE commandList CD ELSE CE commandList CD {
    $$ = buildIfElse($2,$5,$9);
  }
  |
  SKIP {
    $$ = buildSkip();
  }


commandList:
  {
    $$ =NULL;
  }
  |
  command commandList {
    $$ = buildCommandList($1, $2);
  }
    ;
%%

void yyerror(const char* err) {
  printf("Line %d: %s - '%s'\n", yyline, err, yytext  );
}