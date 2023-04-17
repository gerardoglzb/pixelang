%{

#include <iostream>
using namespace std;

#include "parser.tab.h"
#define YY_DECL extern "C" int yylex()

int lineas = 1;

%}
%%

"program"                       { return PROGRAM; }
"var"                           { return VAR; }
"int"                           { return INT; }
"float"                         { return FLOAT; }
"if"                            { return IF; }
"else"                          { return ELSE; }
"print"                         { return PRINT; }
"for_each"                      { return FOREACH; } 
"in"                            { return IN; }
"for"                           { return FOR; }
"do"                            { return DO; }
"end"                           { return END; }
"function"                      { return FUNCTION; }
"return"                        { return RETURN; }

"+"                             { return SUMA; }
"-"                             { return RESTA; }
"*"                             { return MULTI; }
"/"                             { return DIV; }
"<"                             { return MENOR_QUE; }
">"                             { return MAYOR_QUE; }
"<>"                            { return NO_IGUAL; }
"="                             { return IGUAL; }
"+="                            { return PLUS; }
"-="                            { return MINUS; }
"("                             { return PAR_IZQ; }
")"                             { return PAR_DER; }
"{"                             { return LLAVE_IZQ; }
"}"                             { return LLAVE_DER; }
"["                             { return CORCH_IZQ; }
"]"                             { return CORCH_DER; }
":"                             { return DOS_PUNTOS; }
";"                             { return PUNTO_COMA; }
","                             { return COMA; }

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

