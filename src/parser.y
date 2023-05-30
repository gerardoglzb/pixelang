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
    char *strval;
    int ival;
    float fval;
    struct IDNode *nodeID;
    struct ArrayNode *arrNode;
    int chType; // 0 int, 1 float, 2 string, 3 void, 4 prog, 5 int arr, 6 float arr, 7 temp, -1 err
    int ivar;
    int iparam;
    int iarray;
}

%start program

%token <ival> CTE_INT
%token <fval> CTE_FLOAT
%token <strval> CTE_STRING
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
%token MOD
%token LESS_THAN
%token MORE_THAN
%token NOT_EQUAL
%token EQUAL
%token EQUAL_TO
%token AND
%token OR
%token NOT

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
%type <arrNode> array_list
%type <chType> type function_type
%type <ivar> vars
%type <iparam> params
%type <iarray> array_declaration

%%

program : 
    PROGRAM ID {
        declareMainFunction($2, lineas, &functionDirectory);
        setProgramName($2);
    } SEMICOLON vars functions {
        fillMain();
    } block {
        printf("Valid syntax.\n");
        generateObject();
    } ;

vars :
    VAR var SEMICOLON vars {
        $$ = $4 + 1;
    }
    | {
        $$ = 0;
    } ;

var :
    var_list COLON type array_list {
        $4->calculateRs();
        declareVariables($1, $3, $4, lineas);
    } 
    | var_list COLON type {
        declareVariables($1, $3, nullptr, lineas);
    };

array_list :
    array_declaration {
        ArrayNode *node = new ArrayNode($1);
        $$ = node;
    }
    | array_declaration array_list {
        ArrayNode *node = new ArrayNode($1, $2);
        $$ = node;
    } ;

array_declaration :
    LEFT_BRACK CTE_INT RIGHT_BRACK {
        $$ = $2;
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
        createReturnAddress();
    } statements RIGHT_CURLY {
        popReturnAddress();
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
        declareParameter($1, $3, lineas, declareVariable($1, $3, nullptr, lineas)->address);
        $$ = $5 + 1;
    }
    | ID COLON type {
        declareParameter($1, $3, lineas, declareVariable($1, $3, nullptr, lineas)->address);
        $$ = 1;
    }
    | {
        $$ = 0;
    } ;

expression :
    not_expression {
        checkIfShouldDoOperation(vector<int>({AND_, OR_}));
    } expression2 ;

expression2 : 
    AND {
        pushOperator(AND_);
    } expression
    | OR {
        pushOperator(OR_);
    } expression
    | ;

not_expression :
    NOT {
        pushOperator(NOT_);
    } comp {
        checkIfShouldDoOperation(vector<int>({NOT_}));
    }
    | comp ;

comp :
    exp {
        checkIfShouldDoOperation(vector<int>({GREATER_, LESS_, EQUALTO_, NOTEQUAL_}));
    } comp2 ;

comp2 :
    MORE_THAN {
        pushOperator(GREATER_);
    } comp
    | LESS_THAN {
        pushOperator(LESS_);
    } comp
    | EQUAL_TO {
        pushOperator(EQUALTO_);
    } comp
    | NOT_EQUAL {
        pushOperator(NOTEQUAL_);
    } comp 
    | ;

exp :
    term {
        checkIfShouldDoOperation(vector<int>({ADD_, SUB_}));
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
        checkIfShouldDoOperation(vector<int>({MULTI_, DIV_, MOD_}));
    } term2 ;

term2 :
    MULTI {
        pushOperator(MULTI_);
    } term
    | DIV {
        pushOperator(DIV_);
    } term
    | MOD {
        pushOperator(MOD_);
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
    /* | ADDITION {
        pushOperator(ADD_);
    } var_cte
    | SUBSTRACTION {
        pushOperator(SUB_);
    } var_cte */
    | var_cte ;

var_cte :
    CTE_FLOAT {
        pushOperandOfType(declareCte(FLOAT_, $1), FLOAT_);
    }
    | CTE_INT {
        pushOperandOfType(declareCte(INT_, $1), INT_);
    } ;

array_or_func :
    {
        verifyFunctionExists(getIDExpression(), lineas);
        setCurrentCall(getIDExpression());
    } LEFT_PAR {
        generateEra(getCurrentCall());
        resetParameterCount(getCurrentCall());
        pushOperator(FAKEBOT_);
    } arguments RIGHT_PAR {
        verifyParameters(getCurrentCall());
        generateGosub(getCurrentCall());
        pushOperandResult(getCurrentCall());
        setCurrentCall("");
        popOperator(FAKEBOT_);
    }
    | {
        pushOperator(FAKEBOT_);
        verifyIsArray(getIDExpression());
    } arrays {
        popOperator(FAKEBOT_);
    }
    | {
        pushOperandByID(getIDExpression());
    } ;

arrays :
    array arrays
    | array ;

array :
    LEFT_BRACK expression {
        generateVerify();
    } RIGHT_BRACK {
        generateAccess();
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
    assignment SEMICOLON
    | call
    | printing
    | conditional
    | repetition
    | return ;

assignment :
    assignee EQUAL {
        pushOperator(EQUALS_);
    } expression {
        checkIfShouldDoOperation(vector<int>({EQUALS_}));
    } ;

assignee :
    ID {
        pushOperandByID($1);
    }
    | ID {
        handleIDExpression($1);
        pushOperator(FAKEBOT_);
        verifyIsArray(getIDExpression());
    } arrays {
        popOperator(FAKEBOT_);
    } ;

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
    } LEFT_PAR expression_or_str printing_2 RIGHT_PAR SEMICOLON {
        checkIfShouldDoOperation(vector<int>({PRINT_}));
        generateNewline();
    } ;

printing_2 :
    {
        checkIfShouldDoOperation(vector<int>({PRINT_}));
    }
    COMMA {
        pushOperator(PRINT_);
    } expression_or_str printing_2
    | ;

expression_or_str :
    expression
    | CTE_STRING {
        pushOperandOfType(declareCte(STRING_, $1), STRING_);
    } ;

conditional :
    conditional_if ELSE {
        generateElse();
    } block {
        fillJumpIf();
    }
    | conditional_if {
        fillJumpIf();
    } ;

conditional_if :
    IF LEFT_PAR expression RIGHT_PAR {
        generateIf();
    } block ;

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
    FOR {
        // pushJumpCurrent();
    } LEFT_PAR assignment {
        pushLastAssignment();
        saveForVariable();
        pushJumpCurrent(-1);
    } TO expression {
        validateLastAssignment(INT_);
        validateLastOperand(INT_);
        pushOperator(LESS_);
        doOperation();
    } RIGHT_PAR {
        generateWhile();
    } block {
        fillJumpFor();
    } ;

%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Need source code filename." << endl;
        exit(-1);
    }
    string filename = argv[1];
    filename = "./src/tests/" + filename + ".txt";
    FILE *myfile = fopen(filename.c_str(), "r");
    if (!myfile) {
        cout << "No file found for source code." << endl;
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