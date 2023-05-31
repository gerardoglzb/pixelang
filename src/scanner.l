%{

#include <iostream>
#include "../include/compiler.hpp"
using namespace std;

#include "../bin/parser.tab.h"
#define YY_DECL extern "C" int yylex()

int lineas = 1;

FunctionDirectory functionDirectory = FunctionDirectory();

%}
%%

"program"                       { return PROGRAM; }
"var"                           { return VAR; }
"int"                           { yylval.chType = INT_; return INT; }
"float"                         { yylval.chType = FLOAT_; return FLOAT; }
"bool"                          { yylval.chType = BOOL_; return BOOL; }
"image"                         { yylval.chType = IMAGE_; return IMAGE; }
"if"                            { return IF; }
"else"                          { return ELSE; }
"print"                         { return PRINT; }
"while"                         { return WHILE; }
"do"                            { return DO; }
"for"                           { return FOR; }
"to"                            { return TO; }
"function"                      { return FUNCTION; }
"return"                        { return RETURN; }
"void"                          { yylval.chType = 5; return VOID; }

"+"                             { return ADDITION; }
"-"                             { return SUBSTRACTION; }
"*"                             { return MULTI; }
"/"                             { return DIV; }
"%"                             { return MOD; }
"<"                             { return LESS_THAN; }
">"                             { return MORE_THAN; }
"!="                            { return NOT_EQUAL; }
"=="                            { return EQUAL_TO; }
">="                            { return GREATEREQ; }
"<="                            { return LESSEQ; }
"&&"                            { return AND; }
"||"                            { return OR; }
"!"                             { return NOT; }
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
"->"                            { return ARROW; }

"open"                          { return OPEN; }
"save"                          { return SAVE; }
"grayscale"                     { return GRAYSCALE; }

[\n]                            { lineas++; }
[ \t\r]                         { ; }
"false"                         { yylval.bval = FALSE_; return CTE_BOOL; }
"true"                          { yylval.bval = TRUE_; return CTE_BOOL; }
[a-zA-Z](_?([a-zA-Z]|[0-9]))*   { yylval.sval = strdup(yytext); return ID; }
[0-9]+                          { yylval.ival = atoi(yytext); return CTE_INT; }
[0-9]+\.[0-9]+                  { yylval.fval = atof(yytext); return CTE_FLOAT; }
\"(\\.|[^\\"])*\"               { yylval.strval = strdup(yytext); return CTE_STRING; }
#.*                             { ; }


.                               { printf("Invalid token found on line %d. '%s'\n", lineas, yytext); exit(-1); }

%%

int yywrap(){ return 1; }

