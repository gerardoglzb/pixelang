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

%token ADDITION
%token SUBSTRACTION
%token MULTI
%token DIV
%token LESS_THAN
%token MORE_THAN
%token NOT_EQUAL
%token EQUAL
%token PLUS
%token MINUS

%token LEFT_PAR
%token RIGHT_PAR
%token LEFT_CURLY
%token RIGHT_CURLY
%token LEFT_BRACK
%token RIGHT_BRACK
%token COLON
%token SEMICOLON
%token COMMA

%%

program : 
    PROGRAM ID SEMICOLON program_1 block {printf("Valid syntax.\n");} ;
program_1 :
    vars
    | ;

vars :
    VAR vars_1;
vars_1 :
    vars_2 COLON type SEMICOLON vars3;
vars_2 :
    ID vars_4;
vars3 :
    vars_1
    | ;
vars_4 :
    COMMA vars_2
    | ;

type : 
    INT 
    | FLOAT;

block :
    LEFT_CURLY block_1 RIGHT_CURLY;
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
    ID EQUAL expression SEMICOLON;

expression :
    exp expression_1;
expression_1 :
    MORE_THAN exp
    | LESS_THAN exp
    | NOT_EQUAL exp
    | ;

printing :
    PRINT LEFT_PAR printing_1 RIGHT_PAR SEMICOLON;
printing_1 :
    expression printing_2
    | CTE_STRING printing_2;
printing_2 :
    COMMA printing_1
    | ;

condition :
    IF LEFT_PAR expression RIGHT_PAR block condition_1 SEMICOLON;
condition_1 :
    ELSE block
    | ;

exp :
    term exp_1;
exp_1 :
    ADDITION exp
    | SUBSTRACTION exp
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
    LEFT_PAR expression RIGHT_PAR
    | factor_2 var_cte;
factor_2 :
    ADDITION
    | SUBSTRACTION
    | ;

var_cte :
    ID
    | CTE_INT
    | CTE_FLOAT;

for_each :
    FOREACH LEFT_PAR ID IN ID RIGHT_PAR;

for_loop :
    FOR LEFT_PAR for_loop_2 LESS_THAN for_loop_2 RIGHT_PAR;
for_loop_2 :
    CTE_INT
    | ID;

cycle :
    cycle_2 DO statement END;
cycle_2 :
    for_loop
    | for_each;

params :
    ID COLON params_2 params_3;
params_2 :
    type
    | LEFT_CURLY type RIGHT_CURLY;
params_3 :
    COMMA params
    | ;

function :
    FUNCTION ID LEFT_PAR function_2 RIGHT_PAR block SEMICOLON;
function_2 :
    params
    | ;

increment :
    ID increment_2 exp SEMICOLON;
increment_2 :
    PLUS
    | MINUS;

returns :
    RETURN returns_1 SEMICOLON;
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