%{
    #include <iostream>
    #include "../include/compiler.hpp"
    using namespace std;

    extern "C" FILE *yyin;
    extern "C" char *yytext;
    extern "C" int yylex();
    extern "C" int yyparse();

    extern "C" int lineas;
    extern "C" FunctionDirectory functionDirectory;
     
    void yyerror(const char *s);
%}

%union {
    char *sval;
    int ival;
    float fval;
    struct IDNode *nodeID;
    int chType; // 0 int, 1 float, 2 string, 3 void, 4 prog, 5 int arr, 6 float arr, 7 temp, -1 err
    int ivar;
    int iparam;
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
%token FOR
%token DO
%token WHILE
%token TO
%token FUNCTION
%token RETURN
%token VOID

%token ADDITION
%token SUBSTRACTION
%token MULTI
%token DIV
%token LESS_THAN
%token MORE_THAN
%token NOT_EQUAL
%token EQUAL
%token EQUAL_TO
%token AND
%token OR

%token LEFT_PAR
%token RIGHT_PAR
%token LEFT_CURLY
%token RIGHT_CURLY
%token LEFT_BRACK
%token RIGHT_BRACK
%token COLON
%token SEMICOLON
%token COMMA

%type <nodeID> var_list
%type <chType> type function_type
%type <ivar> vars
%type <iparam> params

%%

program : 
    PROGRAM ID {
        declareMainFunction($2, lineas, &functionDirectory);
    } SEMICOLON vars functions {
        fillMain();
    } block {
        printf("Valid syntax.\n");
        printQuads();
    } ;

vars :
    VAR var SEMICOLON vars {
        $$ = $4 + 1;
    }
    | {
        $$ = 0;
    } ;

var :
    var_list COLON type {
        declareVariables($1, $3, lineas);
    }
    | var_list COLON type LEFT_BRACK CTE_INT RIGHT_BRACK {
        declareArrays($1, $3, $5, lineas);
    } ;

var_list :
    ID {
        IDNode *node = new IDNode($1);
        $$ = node;
    }
    | ID COMMA var_list {
        IDNode *node = new IDNode($1, $3);
        $$ = node;
    } ;

functions :
    function functions
    | ;

function :
    FUNCTION ID {
        declareFunction($2, 7, lineas);
    } LEFT_PAR params RIGHT_PAR COLON {
        setCurrentParamCount($5);
    } function_type LEFT_CURLY vars {
        setCurrentLocalVarCount($11);
        setCurrentCurrQuad();
        setCurrentFuncType($9);
        setCurrentFunc($2);
    } function_statements RIGHT_CURLY {
        generateEndFunc();
        functionDirectory.removeVariableTable($2);
    } ;

function_type :
    type {
        functionDirectory.currentFunction()->type = $1;
    }
    | VOID {
        functionDirectory.currentFunction()->type = VOID_;
    } ;

return :
    RETURN {
        pushOperator(RETURN_);
    } LEFT_PAR expression RIGHT_PAR SEMICOLON {
        checkIfShouldDoOperation(vector<int>({RETURN_}));
        setFunctionReturn();
        verifyReturnType(getCurrentFuncType());
    }
    | RETURN SEMICOLON ;

block :
    LEFT_CURLY statements RIGHT_CURLY ;

type :
    INT
    | FLOAT;

params :
    ID COLON type COMMA params {
        declareParameter($1, $3, lineas, declareVariable($1, $3, lineas)->address);
        $$ = $5 + 1;
    }
    | ID COLON type {
        declareParameter($1, $3, lineas, declareVariable($1, $3, lineas)->address);
        $$ = 1;
    }
    | {
        $$ = 0;
    } ;

expression :
    comp {
        checkIfShouldDoOperation(vector<int>({9, 10}));
    } expression2 comp 
    | comp ;

expression2 : 
    AND {
        pushOperator(AND_);
    }
    | OR {
        pushOperator(OR_);
    }
    | ;

comp :
    exp {
        checkIfShouldDoOperation(vector<int>({5, 6, 7, 8}));
    } comp2 exp 
    | exp ;

comp2 :
    MORE_THAN {
        pushOperator(GREATER_);
    }
    | LESS_THAN {
        pushOperator(LESS_);
    }
    | EQUAL_TO {
        pushOperator(EQUALTO_);
    }
    | NOT_EQUAL {
        pushOperator(NOTEQUAL_);
    } ;

exp :
    term {
        checkIfShouldDoOperation(vector<int>({1, 2}));
    } exp2 ;

exp2 :
    ADDITION {
        pushOperator(ADD_);
    } exp
    | SUBSTRACTION {
        pushOperator(SUB_);
    } exp
    | ;

term :
    factor {
        checkIfShouldDoOperation(vector<int>({3, 4}));
    } term2 ;

term2 :
    MULTI {
        pushOperator(MULTI_);
    } term
    | DIV {
        pushOperator(DIV_);
    } term
    | ;

factor :
    ID {
        handleIDExpression($1);
    } array_or_func
    | LEFT_PAR {
        pushOperator(LEFTPAR_);
    } expression RIGHT_PAR {
        pushOperator(RIGHTPAR_);
    }
    | ADDITION {
        pushOperator(ADD_);
    } var_cte
    | SUBSTRACTION {
        pushOperator(SUB_);
    } var_cte
    | var_cte ;

index :
    expression
    | CTE_INT

var_cte :
    CTE_FLOAT {
        pushOperandOfType(declareCte(FLOAT_), FLOAT_);
    }
    | CTE_INT {
        pushOperandOfType(declareCte(INT_), INT_);
    } ;

array_or_func :
    {
        verifyFunctionExists(getIDExpression(), lineas);
        setCurrentCall(getIDExpression());
    } LEFT_PAR {
        generateEra(getCurrentCall());
        resetParameterCount(getCurrentCall());
    } arguments RIGHT_PAR {
        verifyParameters(getCurrentCall());
        generateGosub(getCurrentCall());
        pushOperandResult(getCurrentCall());
        setCurrentCall("");
    }
    | LEFT_BRACK index RIGHT_BRACK 
    | {
        pushOperandByID(getIDExpression());
    } ;

arguments :
    expression {
        generateParam();
    } arguments2
    | ;

arguments2 :
    COMMA expression {
        generateParam();
    } arguments2
    | ;

statements :
    statement statements
    | ;

statement :
    assignment
    | call
    | printing
    | conditional
    | repetition ;

function_statements :
    function_statement function_statements
    | ;

function_statement :
    statement
    | return ;

assignment :
    assignee EQUAL {
        pushOperator(EQUALS_);
    } expression SEMICOLON {
        checkIfShouldDoOperation(vector<int>({0}));
    } ;

assignee :
    ID {
        pushOperandByID($1);
    }
    | ID LEFT_BRACK index RIGHT_BRACK ;

call :
    ID {
        verifyFunctionExists($1, lineas);
    } LEFT_PAR {
        generateEra($1);
        setCurrentCall($1);
        resetParameterCount($1);
    } call2 RIGHT_PAR {
        verifyParameters($1);
        generateGosub($1);
        setCurrentCall("");
    } SEMICOLON ;

call2 :
    expression {
        generateParam();
    } call3
    | ;

call3 :
    COMMA expression {
        generateParam();
    } call3
    | ;

printing :
    PRINT {
        pushOperator(PRINT_);
    } LEFT_PAR printing_2 RIGHT_PAR SEMICOLON {
        checkIfShouldDoOperation(vector<int>({PRINT_}));
    } ;

printing_2 :
    printing_3 COMMA printing_2
    | printing_3 ;

printing_3 :
    expression
    | CTE_STRING ;

conditional :
    conditional_if ELSE {
        generateElse();
    } block
    | conditional_if ;

conditional_if :
    IF LEFT_PAR expression RIGHT_PAR {
        generateIf();
    } block {
        fillJumpIf();
    } ;

repetition :
    rep_cond
    | rep_no_cond ;

rep_cond :
    WHILE {
        pushJumpCurrent();
    } LEFT_PAR expression RIGHT_PAR {
        generateWhile();
    } DO block {
        fillJumpWhile();
    } ;

rep_no_cond :
    FOR LEFT_PAR ID EQUAL expression TO expression RIGHT_PAR block ;

%%

int main() {
    FILE *myfile = fopen("./src/code.txt", "r");
    if (!myfile) {
        cout << "No 'code.txt' file found in src/." << endl;
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