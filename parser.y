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

%start program

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
%token FOREACH
%token IN
%token FOR
%token DO
%token END
%token FUNCTION
%token RETURN

%token SUMA
%token RESTA
%token MULTI
%token DIV
%token MENOR_QUE
%token MAYOR_QUE
%token NO_IGUAL
%token IGUAL
%token PLUS
%token MINUS

%token PAR_IZQ
%token PAR_DER
%token LLAVE_IZQ
%token LLAVE_DER
%token CORCH_IZQ
%token CORCH_DER
%token DOS_PUNTOS
%token PUNTO_COMA
%token COMA

%%

program : 
    PROGRAM ID PUNTO_COMA program_1 block {printf("Valid syntax.\n");} ;
program_1 :
    vars
    | ;

vars :
    VAR vars_1;
vars_1 :
    vars_2 DOS_PUNTOS type PUNTO_COMA vars3;
vars_2 :
    ID vars_4;
vars3 :
    vars_1
    | ;
vars_4 :
    COMA vars_2
    | ;

type : 
    INT 
    | FLOAT;

block :
    LLAVE_IZQ block_1 LLAVE_DER;
block_1 :
    statement block_1
    | ;

statement :
    assignment
    | condition
    | printing
    | function
    | cycle
    | increment
    | returns;

assignment :
    ID IGUAL expression PUNTO_COMA;

expression :
    exp expression_1;
expression_1 :
    MAYOR_QUE exp
    | MENOR_QUE exp
    | NO_IGUAL exp
    | ;

printing :
    PRINT PAR_IZQ printing_1 PAR_DER PUNTO_COMA;
printing_1 :
    expression printing_2
    | CTE_STRING printing_2;
printing_2 :
    COMA printing_1
    | ;

condition :
    IF PAR_IZQ expression PAR_DER block condition_1 PUNTO_COMA;
condition_1 :
    ELSE block
    | ;

exp :
    term exp_1;
exp_1 :
    SUMA exp
    | RESTA exp
    | ;

term :
    factor term_1;
term_1 :
    MULTI term
    | DIV term
    | ;

factor :
    factor_1;
factor_1 :
    PAR_IZQ expression PAR_DER
    | factor_2 var_cte;
factor_2 :
    SUMA
    | RESTA
    | ;

var_cte :
    ID
    | CTE_INT
    | CTE_FLOAT;

for_each :
    FOREACH PAR_IZQ ID IN ID PAR_DER;

for_loop :
    FOR PAR_IZQ for_loop_2 MENOR_QUE for_loop_2 PAR_DER;
for_loop_2 :
    CTE_INT
    | ID;

cycle :
    cycle_2 DO statement END;
cycle_2 :
    for_loop
    | for_each;

params :
    ID DOS_PUNTOS params_2 params_3;
params_2 :
    type
    | CORCH_IZQ type CORCH_DER;
params_3 :
    COMA params
    | ;

function :
    FUNCTION ID PAR_IZQ function_2 PAR_DER block PUNTO_COMA;
function_2 :
    params
    | ;

increment :
    ID increment_2 exp PUNTO_COMA;
increment_2 :
    PLUS
    | MINUS;

returns :
    RETURN returns_1 PUNTO_COMA;
returns_1 :
    exp
    | ;

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