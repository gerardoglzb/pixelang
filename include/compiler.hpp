#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>

#include "./Semantics/Operator.hpp"
#include "./Semantics/Type.hpp"
#include "./Semantics/SemanticCube.hpp"
#include "./Quadruples/Quadruple.hpp"
#include "./Memory/Memory.hpp"
#include "./VariableTable/VariableTable.hpp"
#include "./VariableTable/IDNode.hpp"
#include "./FunctionDirectory/FunctionDirectory.hpp"
#include "./ImageProcessing/ParamNode.hpp"

static string programName;

static stack<int> operators; // 0 equal, 1 add, 2 sub, 3 multi, 4 div, 5 greater, 6 less, 7 equal to, 8 not equal, 9 and, 10 or,
                            // 11 leftpar, 12 rightpar, 13 gotoF, 14 goto, 15 gosub, 16 era, 17 param, 18 endfunc, 19 print 20 return
static stack<int> types;
static stack<int> operands;
static stack<int> jumps;
static stack<VariableEntry*> arrayAccesses;

static string IDExpression;
static int lastResult;
static int lastResultType;
static int lastAssignmentType;
static int lastAssignment;
static stack<int> forVariables;
static stack<int> returnAddresses;
static int currentFuncType;

static vector<Quadruple> quads;

static FunctionEntry *currentCall;
static FunctionEntry *currentFunc;

static FunctionDirectory *funcDir;

static ArrayNode *currentArrayNode;


VariableEntry *declareVariable(string name, int type, ArrayNode *arrayNodes, int lineas);

void declareVariables(IDNode *variable, int type, ArrayNode *arrayNodes, int lineas);

VariableEntry *declareParameter(string name, int type, int lineas, int address);

VariableEntry *nextParameter(FunctionEntry *function);

void verifyParameters(string name);

void resetParameterCount(string name);

void verifyIsArray(string id);

void generateAccess();

void setCurrentArrayNode(ArrayNode *node);

ArrayNode *getCurrentArrayNode();


void verifyReturnType(int type);

int getCurrentFuncType();

void setCurrentFuncType(int type);

void setCurrentFunc(string name);

void setFunctionReturn();

void createReturnAddress();

void popReturnAddress();

void verifyFunctionExists(string name, int lineas);

void declareFunction(string name, int type, int lineas);

void declareMainFunction(string name, int lineas, FunctionDirectory *directory);


void pushOperand(int operand);

int popOperand();

void pushOperand(float operand);

void pushOperandOfType(int operand, int type);

void pushOperandByID(string name);

void pushOperator(string oper);

void popOperator(int oper);

void pushOperandResult(string name);

void doOperation();

void checkIfShouldDoOperation(vector<int> myOperators);

void pushOperator(int oper);

void generateIf();

void generateVerify();

void fillJumpFor();

void fillJumpIf();

void generateElse();

void pushJumpCurrent();

void pushJumpCurrent(int extra);

void generateWhile();

void validateLastOperand(int type);

void validateID(string name, int type);

void validateLastAssignment(int type);

void pushLastAssignment();

void saveForVariable();

void generateFor();

void fillJumpWhile();

void generateEndFunc();

void generateEra(string name);

void generateParam();

void generateGosub(string name);

void fillMain();


void generateNewline();



int declareCte(int type, int value);

int declareCte(int type, string value);

int declareCte(int type, float value);


void setCurrentParamCount(int count);

void setCurrentLocalVarCount(int count);

void setCurrentTempVarCount(int count);

void setCurrentCurrQuad();

void setCurrentCall(string name);

string getCurrentCall();

void handleIDExpression(string name);

string getIDExpression();


void printQuad(Quadruple *quad, int idx);

void printQuads(ofstream &file);

void printFunctions(ofstream &file);

void printCtes(ofstream &file);

string operatorName(int _oper);

void generateObject();


void setProgramName(string name);


void printOperators();

void printOperands();


void performImageCall(string id, int call, ParamNode *node);

int topOperandType();


void performInput();