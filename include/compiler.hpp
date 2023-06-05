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

static string programName; // Name of the program

static stack<int> operators; // Stack of operators
static stack<int> types; // Stack of types
static stack<int> operands; // Stack of operands
static stack<int> jumps; // Stack of jumps

static stack<VariableEntry*> arrayAccesses; // Stores arrays that are being accessed
static stack<int> forVariables; // Stores control variables for for loops that are being used
static stack<int> returnAddresses; // Stores address that will receive the value returned by the next function

static string IDExpression; // Stores variable that is being used or function that is being called
static int lastResult; // Stores address of the last value that was returned by a function
static int lastResultType; // Stores value of the last value that was returned by a function
static int lastAssignmentType; // Stores type of the last value that was assigned a value
static int lastAssignment; // Stores address of the last value that was assigned a value

static int currentFuncType; // Stores the current function's type

static vector<Quadruple> quads; // Stores all the quads

static FunctionEntry *currentCall; // Stores the current function that is being called
static FunctionEntry *currentFunc; // Stores the current function that is being defined

static FunctionDirectory *funcDir; // Function directory


/*
This file contains all of the functions that are used by the parser.
*/

/*
Inserts a single variable into the current variable table (current scope).
Parameters:
    name: name of the variable.
    type: data type of the variable.
    arrayNodes: first ArrayNode in linked list of ArrayNode instances if the variable is an array. Otherwise, it's a nullptr.
    lineas: line number.
Returns:
    A pointer to the VariableEntry instance that was created.
Used by:
    declareVariables().
    Parser.
*/
VariableEntry *declareVariable(string name, int type, ArrayNode *arrayNodes, int lineas);

/*
Inserts multiple variables of the same type.
Parameters:
    variable: pointer to the first IDNode in a linked list of IDNode instances containing all the variables to be declared.
    type: data type of the variables.
    arrayNodes: first ArrayNode in linked list of ArrayNode instances if the variables are arrays. Otherwise, it's a nullptr.
    lineas: line number.
Used by:
    Parser.
*/
void declareVariables(IDNode *variable, int type, ArrayNode *arrayNodes, int lineas);

/*
Inserts a parameter into the parameter table for the current function that is being defined.
Parameters:
    name: name of the parameter.
    type: data type of the parameter.
    lineas: line number.
    address: address of the 'sibling' variable that is also declared in the variable table.
Returns:
    Pointer to the VariableEntry instance created.
Used by:
    Parser.
*/
VariableEntry *declareParameter(string name, int type, int lineas, int address);

/*
Gets the next parameter in the function's parameter table.
Parameters:
    function: FunctionEntry instance containing the parameter table.
Returns:
    Pointer to the VariableEntry instance of the next parameter.
Used by:
    generateParam().
*/
VariableEntry *nextParameter(FunctionEntry *function);

/*
Raises an error if not enough arguments have been passed to a function.
Parameters:
    name: name of the function.
Used by:
    Parser.
*/
void verifyParameters(string name);

/*
Resets currentParam to 0 in a FunctionEntry.
Parameters:
    name: name of the function.
Used by:
    Parser.
*/
void resetParameterCount(string name);

/*
Raises an error if variable isn't an array.
Parameters:
    id: name of the variable.
Used by:
    Parser.
*/
void verifyIsArray(string id);

/*
Generates code to calculate pointer to address of the value of the array that is being accessed.
Used by:
    Parser.
*/
void generateAccess();

/*
Sets currentArrayNode to whatever node is passed.
Parameters:
    node: ArrayNode instance that will be assigned to currentArrayNode.
Used by:
    Parser.
*/
void setCurrentArrayNode(ArrayNode *node);

/*
Gets currentArrayNode.
Returns:
    Value of currentArrayNode.
Used by:
    Parser.
*/
ArrayNode *getCurrentArrayNode();


/*
Raises an error if return type of current function that is being defined is not the same as the type that's being passed.
Parameters:
    type: data type of value that is being returned by the function.
Used by:
    Parser.
*/
void verifyReturnType(int type);

/*
Raises an error if return type of a function that is being defined is not the same as the type that's being passed.
This is specifically used by void functions.
Parameters:
    functionType: data type of the function.
    returnType: data type of value that is being returned by the function.
Used by:
    Parser.
*/
void verifyReturnType(int functionType, int returnType);

/*
Gets current function type.
Returns:
    currentFuncType
Used by:
    Parser.
*/
int getCurrentFuncType();

/*
Sets current function type.
Parameters:
    type: current function type.
Used by:
    Parser.
*/
void setCurrentFuncType(int type);

/*
Sets current function.
Parameters:
    name: current function.
Used by:
    Parser.
*/
void setCurrentFunc(string name);

/*
Sets current function's result address to the lastResult.
Used by:
    Parser.
*/
void setFunctionReturn();

/*
Pushes to returnAddresses the type of the current function that is being defined.
Used by:
    Parser.
*/
void createReturnAddress();

/*
Pops returnAddresses.
Used by:
    Parser.
*/
void popReturnAddress();

/*
Verifies that a function exists in the function directory.
Parameters:
    name: name of the function.
    lineas: line number.
Used by:
    Parser.
*/
void verifyFunctionExists(string name, int lineas);

/*
Inserts a FunctionEntry instance with its own new VariableTable into the function directory.
Parameters:
    name: name of the function.
    type: data type of the function.
    lineas: line number.
Used by:
    Parser.
*/
void declareFunction(string name, int type, int lineas);

/*
Inserts the main function's FunctionEntry instance into the function directory.
Parameters:
    name: name of the program.
    lineas: line number.
    directory: function directory.
Used by:
    Parser.
*/
void declareMainFunction(string name, int lineas, FunctionDirectory *directory);

/*
Pops an operand from the operands stack and a type from the types stack.
Returns:
    Top operand of stack.
Used by:
    Parser.
*/
int popOperand();

/*
Pushes an address into the operands stack and a type into the types stack.
Parameters:
    operand: operand address
    type: type address
Used by:
    Parser.
    generateAccess()
    pushOperandResult()
    doOperation()
*/
void pushOperandOfType(int operand, int type);

/*
Pushes an ID into the operands stack and its type into the types stack.
Parameters:
    name: name of the variable
Used by:
    Parser.
*/
void pushOperandByID(string name);

/*
Pushes an operator into the operators stack.
Parameters:
    oper: operator
Used by:
    Parser.
*/
void pushOperator(string oper);

/*
Pops the operators stack if the top of it is the same as the operator that's passed.
Parameters:
    oper: operator
Used by:
Parser.
*/
void popOperator(int oper);

/*
Pushes the address of the return value of a function to the operands stack and its type to the types stack.
Parameters:
    name: name of the function.
Used by:
    Parser.
*/
void pushOperandResult(string name);

/*
Generates a quad by grabbing an operator from the operators stack and the necessary operands from the operands stack.
Used by:
    Parser.
    checkIfShouldDoOperation().
*/
void doOperation();

/*
Checks if the top of the operators stack is the same as either as the ones that are passed. If so, it calls doOperation().
Parameters:
    myOperators: vector of operators that are checked.
Used by:
    Parser.
*/
void checkIfShouldDoOperation(vector<int> myOperators);

/*
Pushes an operator into the operators stack.
Parameters:
    oper: operator.
Used by:
    Parser.
*/
void pushOperator(int oper);

/*
Generates GOTOF quad at the beginning of an if statement and pushes the quad number to the jumps stack for later so it can be accessed
later to have the correct quad to go to.
Used by:
    Parser.
*/
void generateIf();

/*
Generates a quad and pushes it to the quads vector.
Parameters:
    oper: operator.
    leftOperand: left operand address.
    rightOperand: right operand address.
    result: result address.
Used by:
    Parser.
    fillJumpWhile()
    fillJumpFor()
    pushOperandResult()
    doOperation()
    declareMainFunction()
    performImageCall()
*/
void generateQuad(int oper, int leftOperand, int rightOperand, int result);

/*
Generates empty RETURN quad.
Used by:
    Parser.
*/
void generateVoidReturn();

/*
Generates VERIFY quad.
Used by:
    Parser.
*/
void generateVerify();

/*
Fills the GOTOF quad at the beginning of a for loop with the current quad, generates a quad to increase the loop's control variable by 1
and generates a GOTO quad to return to the loop's condition.
Used by:
    Parser.
*/
void fillJumpFor();

/*
Fills the GOTOF quad at the beginning of an if statement with the current quad.
Used by:
    Parser.
*/
void fillJumpIf();

/*
Generates empty GOTO quad, fill if statement's GOTOF quad with the current quad and pushes current quad into jumps stack.
Used by:
    Parser.
*/
void generateElse();

/*
Pushes the current quad into the jumps stack.
Used by:
    Parser.
*/
void pushJumpCurrent();

/*
Pushes the current quad into the jumps stack, but adds a value to it.
Parameters:
    extra: value to be added to the current quad.
Used by:
    Parser.
*/
void pushJumpCurrent(int extra);

/*
Generates GOTOF quad at the start of a while loop and pushes the current quad size into jumps stack.
Used by:
    Parser.
*/
void generateWhile();

/*
Raises an error if the top of the types stack isn't the same as the type that's passed.
Parameters:
    type: data type to compare to.
Used by:
    Parser.
*/
void validateLastOperand(int type);

/*
Raises an error if lastAssignmentType isn't the same as the type passed.
Parameters:
    type: data type to compare to.
Used by:
    Parser.
*/
void validateLastAssignment(int type);

/*
Pushes lastAssignment to operands stack and lastAssignmentType to types stack.
Used by:
    Parser.
*/
void pushLastAssignment();

/*
Pushes lastAssignment into forVariables stack.
Used by:
    Parser.
*/
void saveForVariable();

/*
Fills the GOTOF at the start of the loop with the current quad and generates a GOTO quad to the top of the jumps stack.
Used by:
    Parser.
*/
void fillJumpWhile();

/*
Generates an ENDFUNC quad.
Used by:
    Parser.
*/
void generateEndFunc();

/*
Generates an ERA quad to the ID of a function.
Parameters:
    name: name of the function.
Used by:
    Parser.
*/
void generateEra(string name);

/*
Generates a PARAM quad with the top of the operands stack and the next parameter in the current call.
Used by:
    Parser
*/
void generateParam();

/*
Generates GoSub quad to the ID of a function.
Parameters:
    name: name of the function.
Used by:
    Parser.
*/
void generateGosub(string name);

/*
Fills the result address of the first quad (which is always the GOTO main) with the current quad, which should be the start of the
main function.
Used by:
    Parser.
*/
void fillMain();


/*
Generates empty PRINT quad, which the VM interprets as a new line.
*/
void generateNewline();


/*
Stores an integer value into the constant memory space.
Parameters:
    type: INT_.
    value: value to be stored.
Returns:
    Address where the value was stored.
Used by:
    Parser.
    fillJumpFor()
    generateAccess()
    doOperation()
*/
int declareCte(int type, int value);

/*
Stores a string value into the constant memory space.
Parameters:
    type: STRING_.
    value: value to be stored.
Returns:
    Address where the value was stored.
Used by:
    Parser.
*/
int declareCte(int type, string value);

/*
Stores a float value into the constant memory space.
Parameters:
    type: FLOAT_.
    value: value to be stored.
Returns:
    Address where the value was stored.
Used by:
    Parser.
*/
int declareCte(int type, float value);


/*
Sets the current function's param count to a passed value.
Parameters:
    count: parameter count.
Used by:
    Parser.
*/
void setCurrentParamCount(int count);

/*
Sets the current function's local variable count to a passed value.
Parameters:
    count: local variable count.
Used by:
    Parser.
*/
void setCurrentLocalVarCount(int count);

/*
Sets the current function's temporary variable count to a passed value.
Parameters:
    count: temporary variable count.
Used by:
    Parser.
*/
void setCurrentTempVarCount(int count);

/*
Sets current function's currQuad to the current quad.
Used by:
    Parser.
*/
void setCurrentCurrQuad();

/*
Sets currentCall to a function.
Parameters:
    name: name of function.
Used by:
    Parser.
*/
void setCurrentCall(string name);

/*
Gets currentCall.
Returns:
    currentCall.
Used by:
    Parser.
*/
string getCurrentCall();

/*
Sets IDExpression to a variable name.
Parameters:
    name: name of the variable
Used by:
    Parser.
*/
void handleIDExpression(string name);

/*
Gets IDExpression.
Returns:
    IDExpression
Used by:
    Parser.
*/
string getIDExpression();


/*
Prints a quad's data to a file.
Parameters:
    quad: quad.
    idx: quad number.
    file: file to write to.
Used by:
    printQuads().
*/
void printQuad(Quadruple *quad, int idx, ofstream &file);


/*
Prints all the quads to a file.
Parameters:
    file: file to write to.
Used by:
    generateObject().
*/
void printQuads(ofstream &file);

/*
Prints the functions of a directory to a file.
Parameters:
    file: file to write to.
Used by:
    generateObject().
*/
void printFunctions(ofstream &file);

/*
Prints all constants to a file.
Parameters:
    file: file to write to.
Used by:
    generateObject().
*/
void printCtes(ofstream &file);

/*
Gets the name of an operator.
Parameters:
    _oper: operator value.
Returns:
    Name of the operator.
Used by:
    printQuad().
    printOperators().
*/
string operatorName(int _oper);

string operatorName(int _oper, bool longVersion);

/*
Creates the quads.txt object file.
Used by:
    Parser.
*/
void generateObject();

/*
Sets programName to a name.
Parameters:
    name: name of the program.
Used by:
    Parser.
*/
void setProgramName(string name);

/*
Prints operators in stack to the terminal.
*/
void printOperators();

/*
Prints operands in stack to the terminal.
*/
void printOperands();


void verifyImageParameterCount(int oper, int count);

/*
Generates quad of an image call and IPARAM quads.
Parameters:
    id: name of image variable.
    call: image function operator.
    node: first parameter in linked list with all ParamNode instances.
Used by:
    Parser.
*/
void performImageCall(string id, int call, ParamNode *node);

/*
Gets top of types stack.
Returns:
    Top of types stack.
Used by:
    Parser.
*/
int topOperandType();


/*
Generates an INPUT quad with a new address.
Parameters:
    type: type of new input value.
Used by:
    Parser.
*/
void generateInput(int type);