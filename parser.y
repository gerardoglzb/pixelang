%{
    #include <iostream>
    using namespace std;

    extern "C" FILE *yyin;
    extern "C" char *yytext;
    extern "C" int yylex();
    extern "C" int yyparse();

    extern "C" int lineas;
     
    void yyerror(const char *s);
%}

%union {
    char *sval;
    int ival;
    float fval;
}

%start programa

%token <ival> CTE_INT
%token <fval> CTE_FLOAT
%token <sval> CTE_STRING
%token <sval> ID

%token PROGRAM
%token VAR
%token INT
%token FLOAT
%token IF
%token ELSE
%token PRINT

%token SUMA
%token RESTA
%token MULTI
%token DIV
%token MENOR_QUE
%token MAYOR_QUE
%token NO_IGUAL
%token IGUAL

%token PAR_IZQ
%token PAR_DER
%token LLAVE_IZQ
%token LLAVE_DER
%token DOS_PUNTOS
%token PUNTO_COMA
%token COMA

%%

programa : 
    PROGRAM ID PUNTO_COMA programa_1 bloque {printf("Valid syntax.\n");} ;
programa_1 : 
    vars
    | ;

vars : 
    VAR vars_1;
vars_1 : 
    vars_2 DOS_PUNTOS tipo PUNTO_COMA vars3;
vars_2 :
    ID vars_4;
vars3 :
    vars_1
    | ;
vars_4 :
    COMA vars_2
    | ;

tipo : 
    INT 
    | FLOAT;

bloque :
    LLAVE_IZQ bloque_1 LLAVE_DER;
bloque_1 :
    estatuto bloque_1
    | ;

estatuto :
    asignacion
    | condicion
    | escritura;

asignacion :
    ID IGUAL expresion PUNTO_COMA;

expresion :
    exp expresion_1;
expresion_1 :
    MAYOR_QUE exp
    | MENOR_QUE exp
    | NO_IGUAL exp
    | ;

escritura :
    PRINT PAR_IZQ escritura_1 PAR_DER PUNTO_COMA;
escritura_1 :
    expresion escritura_2
    | CTE_STRING escritura_2;
escritura_2 :
    COMA escritura_1
    | ;

condicion :
    IF PAR_IZQ expresion PAR_DER bloque condicion_1 PUNTO_COMA;
condicion_1 :
    ELSE bloque
    | ;

exp :
    termino exp_1;
exp_1 :
    SUMA exp
    | RESTA exp
    | ;

termino :
    factor termino_1;
termino_1 :
    MULTI termino
    | DIV termino
    | ;

factor :
    factor_1;
factor_1 :
    PAR_IZQ expresion PAR_DER
    | factor_2 var_cte;
factor_2 :
    SUMA
    | RESTA
    | ;

var_cte :
    ID
    | CTE_INT
    | CTE_FLOAT;

%%

int main() {
    FILE *myfile = fopen("code.txt", "r");
    if (!myfile) {
        cout << "No 'code.txt' file found." << endl;
        return -1;
    }

    yyin = myfile;
    do {
        yyparse();
    }
    while (!feof(yyin));

    return 0;
}

void yyerror(const char *s) {
    printf("SyntaxError: Invalid token on line %d. '%s'\n", lineas, yytext);
    exit(-1);
}