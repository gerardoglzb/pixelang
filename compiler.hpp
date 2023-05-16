#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>

#include "./Semantics/Operator.hpp"
#include "./Semantics/Type.hpp"
#include "./Quadruples/Quadruple.hpp"
#include "./Memory/Memory.hpp"
#include "./VariableTable/VariableTable.hpp"
#include "./VariableTable/IDNode.hpp"
#include "./FunctionDirectory/FunctionDirectory.hpp"

static stack<int> operators; // 0 equal, 1 add, 2 sub, 3 multi, 4 div, 5 greater, 6 less, 7 equal to, 8 not equal, 9 and, 10 or,
                            // 11 leftpar, 12 rightpar, 13 gotoF, 14 goto, 15 gosub, 16 era, 17 param, 18 endfunc, 19 print 20 return
static stack<int> types;
static stack<int> operands;
static stack<int> jumps;

static string IDExpression;
static int lastResult;
static int lastResultType;
static int currentFuncType;

static vector<Quadruple> quads;

static FunctionEntry *currentCall;
static FunctionEntry *currentFunc;

static FunctionDirectory *funcDir;


VariableEntry *declareVariable(string name, int type, int lineas);

void declareArray(string name, int type, int size, int lineas);

void declareArrays(IDNode* variable, int type, int size, int lineas);

void declareVariables(IDNode *variable, int type, int lineas);

VariableEntry *declareParameter(string name, int type, int lineas, int address);

VariableEntry *nextParameter(FunctionEntry *function);

void verifyParameters(string name);

void resetParameterCount(string name);


void verifyReturnType(int type);

int getCurrentFuncType();

void setCurrentFuncType(int type);

void setCurrentFunc(string name);

void setFunctionReturn();

void verifyFunctionExists(string name, int lineas);

void declareFunction(string name, int type, int lineas);

void declareMainFunction(string name, int lineas, FunctionDirectory *directory);


int semanticCube(int oper, int type1, int type2);

void pushOperand(int operand);

void pushOperand(float operand);

void pushOperandOfType(int operand, int type);

void pushOperandByID(string name);

void pushOperator(string oper);

void pushOperandResult(string name);

void doOperation();

void checkIfShouldDoOperation(vector<int> myOperators);

void pushOperator(int oper);

void generateIf();

void fillJumpIf();

void generateElse();

void pushJumpCurrent();

void generateWhile();

void fillJumpWhile();

void generateEndFunc();

void generateEra(string name);

void generateParam();

void generateGosub();

void generateGosub(string name);

void fillMain();


int declareCte(int type);


void setCurrentParamCount(int count);

void setCurrentLocalVarCount(int count);

void setCurrentTempVarCount(int count);

void setCurrentCurrQuad();

void setCurrentCall(string name);

string getCurrentCall();

void handleIDExpression(string name);

string getIDExpression();


void printQuad(Quadruple *quad, int idx);

void printQuads();

string operatorName(int _oper);
