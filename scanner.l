%{

#include <iostream>
using namespace std;

#include "parser.tab.h"
#define YY_DECL extern "C" int yylex()

int lineas = 1;

%}
%%

"program"                       { return PROGRAM; }
"main"                          { return MAIN; }
"var"                           { return VAR; }
"int"                           { return INT; }
"float"                         { return FLOAT; }
"if"                            { return IF; }
"else"                          { return ELSE; }
"print"                         { return PRINT; }
"while"                         { return WHILE; }
"do"                            { return DO; }
"for"                           { return FOR; }
"to"                            { return TO; }
"function"                      { return FUNCTION; }
"return"                        { return RETURN; }
"void"                          { return VOID; }

"+"                             { return ADDITION; }
"-"                             { return SUBSTRACTION; }
"*"                             { return MULTI; }
"/"                             { return DIV; }
"<"                             { return LESS_THAN; }
">"                             { return MORE_THAN; }
"!="                            { return NOT_EQUAL; }
"=="                            { return EQUAL_TO; }
"&&"                            { return AND; }
"||"                            { return OR; }
"="                             { return EQUAL; }
"("                             { return LEFT_PAR; }
")"                             { return RIGHT_PAR; }
"{"                             { return LEFT_CURLY; }
"}"                             { return RIGHT_CURLY; }
"["                             { return LEFT_BRACK; }
"]"                             { return RIGHT_BRACK; }
":"                             { return COLON; }
";"                             { return SEMICOLON; }
","                             { return COMMA; }

[\n]                            { lineas++; }
[ \t\r]                         { ; }
[a-zA-Z](_?([a-zA-Z]|[0-9]))*   { yylval.sval = strdup(yytext); return ID; }
[0-9]+                          { yylval.ival = atoi(yytext); return CTE_INT; }
[0-9]+\.[0-9]+                  { yylval.fval = atof(yytext); return CTE_FLOAT; }
\"(\\.|[^\\"])*\"               { yylval.sval = strdup(yytext); return CTE_STRING; }
#.*                             { ; }


.                               { printf("Invalid token found on line %d. '%s'\n", lineas, yytext); exit(-1); }

%%

int yywrap(){ return 1; }

