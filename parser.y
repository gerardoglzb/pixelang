%{
    #include <iostream>
    #include <unordered_map>
    #include <stack>
    #include "table.hh"
    using namespace std;

    extern "C" FILE *yyin;
    extern "C" char *yytext;
    extern "C" int yylex();
    extern "C" int yyparse();

    extern "C" int lineas;
    extern "C" unordered_map<string, VariableTable> functionDirectory;
    extern "C" stack<string> currentFunction;
     
    void yyerror(const char *s);
%}

%union {
    char *sval;
    int ival;
    float fval;
    struct IDNode *nodeID;
    char chType;
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

%type <nodeID> id_list
%type <chType> type

%%

program : 
    PROGRAM program_1 SEMICOLON vars functions block {
        printf("Valid syntax.\n");
    } ;

program_1 :
    ID {
            VariableTable table;
            table.parent = NULL;
            functionDirectory[$1] = table;
            currentFunction.push($1);
    } ;

vars :
    VAR var SEMICOLON vars
    | ;

var :
    id_list COLON type {
        IDNode *variable = $1;
        cout << "Declarando ";
        do {
            VariableEntry entry;
            entry.name = variable->name;
            entry.type = $3;
            functionDirectory[currentFunction.top()].table[variable->name] = entry;
            variable = variable->next;
            cout << entry.name << ", ";
        }
        while (variable);
        cout << "." << endl;
    }
    | id_list COLON type LEFT_BRACK CTE_INT RIGHT_BRACK ;

id_list :
    ID {
        IDNode *node = new IDNode();
        node->name = $1;
        node->next = NULL;
        $$ = node;
    }
    | ID COMMA id_list {
        IDNode *node = new IDNode();
        node->name = $1;
        node->next = $3;
        $$ = node;
    };

functions :
    function functions
    | ;

function :
    FUNCTION ID LEFT_PAR params RIGHT_PAR COLON function_2 LEFT_CURLY vars statements returns RIGHT_CURLY ;

function_2 :
    type
    | VOID ;

returns :
    RETURN LEFT_PAR expression RIGHT_PAR SEMICOLON
    | RETURN SEMICOLON ;

block :
    LEFT_CURLY statements RIGHT_CURLY ;

type :
    INT
    | FLOAT;

params :
    ID COLON type LEFT_BRACK RIGHT_BRACK COMMA params
    | ID COLON type COMMA params
    | ID COLON type LEFT_BRACK RIGHT_BRACK
    | ID COLON type
    | ;

expression :
    comp expression2 comp 
    | comp ;

expression2 : 
    AND
    | OR
    | ;

comp :
    exp comp2 exp 
    | exp ;

comp2 :
    MORE_THAN
    | LESS_THAN
    | EQUAL_TO
    | NOT_EQUAL ;

exp :
    term exp2 ;

exp2 :
    ADDITION exp
    | SUBSTRACTION exp
    | ;

term :
    factor term2 ;

term2 :
    MULTI term
    | DIV term
    | ;

factor :
    LEFT_PAR expression RIGHT_PAR
    | ADDITION var_cte
    | SUBSTRACTION var_cte 
    | var_cte
    | ID factor2 ;

factor2 : 
    LEFT_PAR factor3 RIGHT_PAR
    | LEFT_BRACK index RIGHT_BRACK
    | ;

factor3 :
    exp COMMA factor3
    | exp ;

index :
    expression
    | CTE_INT

var_cte :
    ID
    | CTE_FLOAT
    | CTE_INT ;

statements :
    statement statements
    | ;

statement :
    assignment
    | call
    | printing
    | decision
    | repetition 
    | ;

assignment :
    ID EQUAL call
    | ID LEFT_BRACK index RIGHT_BRACK EQUAL call
    | ID EQUAL expression SEMICOLON ;
    | ID LEFT_BRACK index RIGHT_BRACK EQUAL expression SEMICOLON ;

call :
    ID LEFT_PAR call2 RIGHT_PAR SEMICOLON ;

call2 :
    ID
    | ID COMMA call2 
    | expression 
    | expression COMMA call2 
    | ;

printing :
    PRINT LEFT_PAR printing_2 RIGHT_PAR SEMICOLON ;

printing_2 :
    printing_3 COMMA printing_2
    | printing_3 ;

printing_3 :
    expression
    | CTE_STRING ;

decision :
    IF LEFT_PAR expression RIGHT_PAR block ELSE block
    | IF LEFT_PAR expression RIGHT_PAR block ;

repetition :
    rep_cond
    | rep_no_cond ;

rep_cond :
    WHILE LEFT_PAR expression RIGHT_PAR DO block ;

rep_no_cond :
    FOR LEFT_PAR ID EQUAL expression TO expression RIGHT_PAR block ;

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