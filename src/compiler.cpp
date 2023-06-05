#include <utility>
#include <fstream>
#include "../include/compiler.hpp"

/*
This file contains all of the functions that are used by the parser.
*/

void raiseError(string msg) {
    cout << "ERROR: " << msg << endl;
    exit(-1);
}

string dataTypeName(int type) {
    string name = "";
    switch(type) {
        case INT_:
            name = "int";
            break;
        case FLOAT_:
            name = "float";
            break;
        case BOOL_:
            name = "bool";
            break;
        case STRING_:
            name = "string";
            break;
        case VOID_:
            name = "void";
            break;
        case IMAGE_:
            name = "image";
            break;
    }
    return name;
}

void verifyImageParameterCount(int oper, int count) {
    vector<vector<int>> counts = {{{1}, {1}, {0}, {0}, {3, 1}, {0}, {0}, {4}}};
    for (int i : counts[oper - OPEN_]) {
        if (count == i)
            return;
    }
    raiseError("Incorrect number of parameters provided for " + operatorName(oper, true) + " function.");
}

void verifyFunctionExists(string name, int lineas) {
    if (!funcDir->has(name)) {
        raiseError("Function " + name + " doesn't exist in line " + to_string(lineas) + ".");
    }
}

void verifyParameters(string name) {
    if (funcDir->find(name)->nextCurrentParameter()) {
        raiseError("Too few parameters for " + name + ".");
    }
}

void printOperators() {
    stack<int> temp;
    while (operators.size()) {
        temp.push(operators.top());
        operators.pop();
    }
    cout << "Operators: ";
    while (temp.size()) {
        operators.push(temp.top());
        cout << operatorName(temp.top()) << ", ";
        temp.pop();
    }
    cout << endl;
}

void printOperands() {
    stack<int> temp;
    while (operands.size()) {
        temp.push(operands.top());
        operands.pop();
    }
    cout << "Operands: ";
    while (temp.size()) {
        operands.push(temp.top());
        cout << temp.top() << ", ";
        temp.pop();
    }
    cout << endl;
}

void generateQuad(int oper, int leftOperand, int rightOperand, int result) {
    Quadruple quad = Quadruple(oper, leftOperand, rightOperand, result);
    quads.push_back(quad);
    // printOperators();
    // printOperands();
    // printf("%lu\t%s\t%i\t%i\t%i\n\n", quads.size(), operatorName(oper).c_str(), leftOperand, rightOperand, result);
}

void generateVoidReturn() {
    generateQuad(RETURN_, -1, -1, -1);
}

void generateGosub(string name) {
    generateQuad(GOSUB_, -1, -1, funcDir->getFunctionID(name));
}

VariableEntry *nextParameter(FunctionEntry *function) {
    VariableEntry *param = function->nextCurrentParameter();
    if (!param) {
        raiseError("Too many parameters for " + function->name + ".");
    }
    return param;
}

void verifyIsArray(string id) {
    VariableEntry *entry = funcDir->currentVariableTable()->fullFind(id);
    if (entry->arrNode == nullptr) {
        raiseError(id + " is not an array!");
    }
    entry->resetArrayNode();
    arrayAccesses.push(entry);
}

void generateVerify() {
    if (types.top() != INT_) {
        raiseError("You can only access arrays using integers.");
    }
    generateQuad(VERIFY_, operands.top(), 0, arrayAccesses.top()->currArrNode->size - 1);
}

void setCurrentCall(string name) {
    if (name == "")
        currentCall = nullptr;
    currentCall = funcDir->find(name);
}

string getCurrentCall() {
    return currentCall->name;
}

void handleIDExpression(string name) {
    IDExpression = name;
}

string getIDExpression() {
    return IDExpression;
}

void resetParameterCount(string name) {
    funcDir->find(name)->resetParamCount();
}

void generateParam() {
    int arg = operands.top(); operands.pop();
    int type = types.top(); types.pop();
    if (!currentCall) {
        exit(-1);
    }
    VariableEntry *param = nextParameter(currentCall);

    if (semanticCube(EQUALS_, param->type, type) == -1) {
        raiseError("Trying to pass " + dataTypeName(type) + " to parameter " + param->name + " of type " + dataTypeName(param->type) + ".");
    }

    generateQuad(PARAM_, arg, -1, param->address);
}

void generateEra(string name) {
    generateQuad(ERA_, -1, -1, funcDir->getFunctionID(funcDir->find(name)->name));
}

void generateEndFunc() {
    generateQuad(ENDFUNC_, -1, -1, -1);
}

string operatorName(int _oper) {
    string oper = "";
    switch(_oper) {
        case EQUALS_:
            oper = "EQUALS";
            break;
        case ADD_:
            oper = "ADD";
            break;
        case SUB_:
            oper = "SUB";
            break;
        case MULTI_:
            oper = "MULTI";
            break;
        case DIV_:
            oper = "DIV";
            break;
        case GREATER_:
            oper = "GREATER";
            break;
        case LESS_:
            oper = "LESS";
            break;
        case EQUALTO_:
            oper = "EQUALTO";
            break;
        case NOTEQUAL_:
            oper = "NOTEQ";
            break;
        case AND_:
            oper = "AND";
            break;
        case OR_:
            oper = "OR";
            break;
        case LEFTPAR_:
            oper = "LEFTP";
            break;
        case RIGHTPAR_:
            oper = "RIGHTP";
            break;
        case GOTOF_:
            oper = "GOTOF";
            break;
        case GOTO_:
            oper = "GOTO";
            break;
        case GOSUB_:
            oper = "GOSUB";
            break;
        case ERA_:
            oper = "ERA";
            break;
        case PARAM_:
            oper = "PARAM";
            break;
        case ENDFUNC_:
            oper = "ENDF";
            break;
        case PRINT_:
            oper = "PRINT";
            break;
        case RETURN_:
            oper = "RETURN";
            break;
        case END_:
            oper = "END";
            break;
        case VERIFY_:
            oper = "VERIFY";
            break;
        case FAKEBOT_:
            oper = "FAKEBOT";
            break;
        case NOT_:
            oper = "NOT";
            break;
        case MOD_:
            oper = "MOD";
            break;
        case GREATEREQ_:
            oper = "GREATEREQ";
            break;
        case LESSEQ_:
            oper = "LESSEQ";
            break;
        case EXPO_:
            oper = "EXPO";
            break;
        case INPUT_:
            oper = "INPUT";
            break;
        case IPARAM_:
            oper = "IPARAM";
            break;
        case OPEN_:
            oper = "OPEN";
            break;
        case SAVE_:
            oper = "SAVE";
            break;
        case GRAYSCALE_:
            oper = "GRAYSCALE";
            break;
        case CHANGECOLOR_:
            oper = "CCOLOR";
            break;
        case BANDW_:
            oper = "BANDW";
            break;
        case HFLIP_:
            oper = "HFLIP";
            break;
        case VFLIP_:
            oper = "VFLIP";
            break;
        case CROP_:
            oper = "CROP";
            break;
    }
    return oper;
}

string operatorName(int _oper, bool longVersion) {
    string oper = operatorName(_oper);
    if (!longVersion)
        return oper;
    
    switch(_oper) {
        case BANDW_:
            oper = "BLACK_AND_WHITE";
            break;
        case CHANGECOLOR_:
            oper = "CHANGE_COLOR";
            break;
    }
    return oper;
}

void printQuad(Quadruple *quad, int idx, ofstream &file) {
    printf("%i\t%s\t %i\t%i\t%i\n", idx, operatorName(quad->oper).c_str(), quad->leftOperand, quad->rightOperand, quad->result);
    file << quad->oper << "," << quad->leftOperand << "," << quad->rightOperand << "," << quad->result << endl;
}

void setProgramName(string name) {
    programName = name;
}

void generateObject() {
    generateQuad(END_, -1, -1, -1);
    ofstream file;
    file.open("./bin/quads.txt");
    file << programName << endl;
    printFunctions(file);
    printCtes(file);
    printQuads(file);
    if (operands.size()) {
        raiseError("(INTERNAL) Operands not empty.");
    }
    if (operators.size()) {
        raiseError("(INTERNAL) Operators not empty.");
    }
    file.close();
}

void setCurrentParamCount(int count) {
    funcDir->currentFunction()->paramCount = count;
}

void setCurrentLocalVarCount(int count) {
    funcDir->currentFunction()->localVarCount = count;
}

void setCurrentTempVarCount(int count) {
    funcDir->currentFunction()->tempVarCount = count;
}

void setCurrentCurrQuad() {
    funcDir->currentFunction()->currQuad = quads.size() + 1;
}

template<typename T>
void printCtes(ofstream &file, vector<T> &values, int offset) {
    for (T value : values) {
        file << value << "," << offset++ << endl;
    }
}

void printCtes(ofstream &file) {
    printCtes(file, funcDir->main->cteMemory->memoryInt->values, funcDir->main->cteMemory->memoryInt->offset);
    file << "%" << endl;
    printCtes(file, funcDir->main->cteMemory->memoryFloat->values, funcDir->main->cteMemory->memoryFloat->offset);
    file << "%" << endl;
    printCtes(file, funcDir->main->cteMemory->memoryBool->values, funcDir->main->cteMemory->memoryBool->offset);
    file << "%" << endl;
    printCtes(file, funcDir->main->cteMemory->memoryString->values, funcDir->main->cteMemory->memoryString->offset);
    file << "%%" << endl;
}

void printFunctions(ofstream &file) {
    funcDir->printFunctions(file);
    file << "%%" << endl;
}

void printQuads(ofstream &file) {
    // cout << "QUADS: " << endl;
    int idx = 1;
    while (!quads.empty()) {
        printQuad(&quads.front(), idx++, file);
        quads.erase(quads.begin());
    }
}

void generateWhile() {
    int type = types.top(); types.pop();
    if (type != INT_ && type != BOOL_) {
        raiseError("Expression in while loop not a boolean.");
    }
    int result = operands.top(); operands.pop();
    generateQuad(GOTOF_, result, -1, -1);
    jumps.push(quads.size() - 1);
}

void validateLastOperand(int type) {
    if (types.top() != type) {
        raiseError("Target value in for loop must be an integer!");
    }
}

void pushLastAssignment() {
    operands.push(lastAssignment);
    types.push(lastAssignmentType);
}

void saveForVariable() {
    forVariables.push(lastAssignment);
}

void validateLastAssignment(int type) {
    if (lastAssignmentType != type) {
        raiseError("Control variable in for loop must be an integer!");
    }
}

void fillMain() {
    quads[0].result = quads.size() + 1;
}

void fillJumpWhile() {
    int end = jumps.top(); jumps.pop();
    int ret = jumps.top(); jumps.pop();
    generateQuad(GOTO_, -1, -1, ret);
    quads[end].result = quads.size() + 1;
}

void fillJumpFor() {
    int end = jumps.top(); jumps.pop();
    int ret = jumps.top(); jumps.pop();
    generateQuad(ADD_, forVariables.top(), declareCte(INT_, 1), forVariables.top());
    forVariables.pop();
    generateQuad(GOTO_, -1, -1, ret + 1);
    quads[end].result = quads.size() + 1;
}

void pushJumpCurrent() {
    jumps.push(quads.size() + 1);
}

void pushJumpCurrent(int extra) {
    jumps.push(quads.size() + 1 + extra);
}

void generateElse() {
    generateQuad(GOTO_, -1, -1, -1);
    int isFalse = jumps.top(); jumps.pop();
    jumps.push(quads.size() -1);
    quads[isFalse].result = quads.size() + 1;
}

void fillJumpIf() {
    int end = jumps.top(); jumps.pop();
    quads[end].result = quads.size() + 1;
}

void generateIf() {
    int type = types.top(); types.pop();
    if (type != INT_) {
        raiseError("Expression in conditional not a boolean.");
    }
    int result = operands.top(); operands.pop();
    generateQuad(GOTOF_, result, -1, -1);
    jumps.push(quads.size() - 1);
}

void pushOperator(int oper) {
    operators.push(oper);
}

int declareTemp(int type) {
    return funcDir->currentFunction()->tempMemory->addValue(type);
}

int declareGlobalTemp(int type) {
    return funcDir->main->tempMemory->addValue(type);
}

int declareLocal(int type, int size) {
    return funcDir->currentFunction()->localMemory->addValues(type, size);
}

void setCurrentFuncType(int type) {
    currentFuncType = type;
}

int getCurrentFuncType() {
    return currentFuncType;
}

void setCurrentFunc(string name) {
    currentFunc = funcDir->find(name);
}

void setFunctionReturn() {
    currentFunc->resultAddress = lastResult;
}

void generateAccess() {
    ArrayNode *node = arrayAccesses.top()->currArrNode;
    if (node->next) {
        int resultAddress = declareTemp(INT_);
        generateQuad(MULTI_, operands.top(), declareCte(INT_, node->mOrK), resultAddress);
        operands.pop(); types.pop();
        pushOperandOfType(resultAddress, INT_);
    }
    if (node->prev) {
        int resultAddress = declareTemp(INT_);
        int index = operands.top(); operands.pop(); types.pop();
        generateQuad(ADD_, operands.top(), index, resultAddress);
        operands.pop(); types.pop();
        pushOperandOfType(resultAddress, INT_);
    }
    if (!node->next) {
        int baseAddress = declareCte(INT_, arrayAccesses.top()->address);
        int resultAddress = declareTemp(INT_);
        int pointerAddress = declareTemp(INT_);
        generateQuad(ADD_, operands.top(), declareCte(INT_, node->mOrK), resultAddress); // TODO: opcional porque siempre es 0
        operands.pop(); types.pop();
        generateQuad(ADD_, resultAddress, baseAddress, pointerAddress);
        pushOperandOfType(-pointerAddress, arrayAccesses.top()->type);
        arrayAccesses.pop();
    } else {
        arrayAccesses.top()->nextNode();
    }
}

void verifyReturnType(int functionType) {
    if (semanticCube(EQUALS_, functionType, lastResultType) == -1) {
        raiseError("Function type and return value are not compatible.");
    }
}

void verifyReturnType(int functionType, int returnType) {
    if (semanticCube(EQUALS_, functionType, returnType) == -1) {
        raiseError("Function type and return value are not compatible.");
    }
}

void popOperator(int oper) {
    if (operators.size() && operators.top() == oper) {
        operators.pop();
    }
}

void pushOperandResult(string name) {
    int functionType = funcDir->find(name)->type;
    if (semanticCube(EQUALS_, currentCall->type, functionType) == -1) {
        raiseError("Function type and return value are not compatible.");
    }
    int callAddress = declareTemp(functionType);
    generateQuad(EQUALS_, -1, currentCall->resultAddress, callAddress);
    pushOperandOfType(callAddress, functionType);
}

int declareCte(int type, int value) {
    if (value == -1)
        return GLOBAL_CTE_INT;
    if (value == 0)
        return GLOBAL_CTE_INT + 1;
    if (value == 1)
        return GLOBAL_CTE_INT + 2;
    return funcDir->main->cteMemory->addValue(type, value);
}

int declareCte(int type, string value) {
    return funcDir->main->cteMemory->addValue(type, value);
}

int declareCte(int type, float value) {
    return funcDir->main->cteMemory->addValue(type, value);
}

void doOperation() {
    if (operands.size() >= 1 && !operators.empty()) {
        int rightOperand = operands.top(); operands.pop();
        int rightType = types.top(); types.pop();
        int leftOperand;
        int leftType;
        int oper = operators.top(); operators.pop();

        if (oper == PRINT_ | oper == RETURN_ || oper == NOT_) {
            leftOperand = -1;
            leftType = rightType;
        }  else if (operands.size() == 1 && oper != EQUALS_ && operators.size() > 0 && operators.top() == EQUALS_) {
            leftOperand = declareCte(INT_, 0);
            leftType = INT_;
        } else {
            leftOperand = operands.top(); operands.pop();
            leftType = types.top(); types.pop();
        }

        int resultType = semanticCube(oper, leftType, rightType);
        if (resultType > -1) {
            int result;
            if (oper == EQUALS_) {
                result = leftOperand;
                leftOperand = -1;
                lastAssignmentType = resultType;
                lastAssignment = result;
            } else if (oper == PRINT_) {
                result = -1;
            } else if (oper == RETURN_) {
                result = returnAddresses.top();
                if (result == -1) {
                    raiseError("Trying to return to a void function!");
                }
                lastResult = result;
                lastResultType = rightType;
            } else {
                result = declareTemp(resultType);
            }
            generateQuad(oper, leftOperand, rightOperand, result);
            if (oper != EQUALS_ && oper != PRINT_ && oper != RETURN_) // TODO: if there were, a = b = c then this is wrong
                pushOperandOfType(result, resultType);
        } else {
            raiseError("Type mismatch.");
        }
    } else {
        cout << "ERROR (Internal): Operations handling error." << endl;
        exit(-1);
    }
}

void checkIfShouldDoOperation(vector<int> myOperators) {
    if (operators.size() == 0) {
        return;
    }
    if (operators.top() == FAKEBOT_) {
        return;
    }
    if (operators.top() == RIGHTPAR_) {
        operators.pop();
        operators.pop();
    }
    if (operators.top() == LEFTPAR_) {
        return;
    }
    bool shouldDoOperation = false;
    for (int oper : myOperators) {
        if (operators.top() == oper) {
            shouldDoOperation = true;
            break;
        }
    }
    if (shouldDoOperation) {
        doOperation();
    }
}

void pushOperandByID(string name) {
    FunctionEntry *function = funcDir->currentFunction();
    operands.push(function->findAddress(name));
    types.push(function->findType(name));
}

void pushOperandOfType(int address, int type) {
    operands.push(address);
    types.push(type);
}

VariableEntry *declareVariable(string name, int type, ArrayNode *arrayNodes, int lineas) {
    VariableTable *table = funcDir->currentVariableTable();
    if (table->has(name)) {
        raiseError("Redefinition of var " + name + " on line " + to_string(lineas) + ".");
    }
    int size = arrayNodes ? arrayNodes->getFullSize() : 1;
    VariableEntry *entry = new VariableEntry(name, type, declareLocal(type, size), arrayNodes);
    table->insert(entry);
    return entry;
}

VariableEntry *declareParameter(string name, int type, int lineas, int address) {
    VariableTable *table = funcDir->currentParameterTable();
    if (table->has(name)) {
        raiseError("Redefinition of parameter " + name + " on line " + to_string(lineas) + ".");
    }
    VariableEntry *entry = new VariableEntry(name, type);
    entry->address = address;
    table->insert(entry);
    return entry;
}

void declareVariables(IDNode *variable, int type, ArrayNode *arrayNodes, int lineas) {
    do {
        declareVariable(variable->name, type, arrayNodes, lineas);
        variable = variable->next;
    }
    while (variable);
}

void declareFunction(string name, int type, int lineas) {
    VariableTable *table = new VariableTable();
    table->parent = funcDir->findMain()->variableTable;

    FunctionEntry *entry = new FunctionEntry(name, type, table);

    if (funcDir->has(name)) {
        raiseError("Redefinition of function " + entry->name + " on line "  + to_string(lineas) + ".");
    } else {
        funcDir->insert(entry);
    }
}

void declareMainFunction(string name, int lineas, FunctionDirectory *directory) {
    VariableTable *table = new VariableTable();
    table->parent = NULL;

    FunctionEntry *entry = new FunctionEntry(name, 4, table, true);

    funcDir = directory;
    funcDir->main = entry;
    for (int i = -1; i < 2; i++) {
        funcDir->main->cteMemory->addValue(INT_, i);
    }

    generateQuad(GOTO_, -1, -1, -1);
}

void createReturnAddress() {
    if (currentFunc->type == VOID_) {
        returnAddresses.push(-1);
    } else {
        int address = declareGlobalTemp(currentFunc->type);
        returnAddresses.push(address);
    }
}

void popReturnAddress() {
    returnAddresses.pop();
}

void generateNewline() {
    generateQuad(PRINT_, -1, -1, -1);
}

void performImageCall(string id, int call, ParamNode *node) {
    int imageAddress = funcDir->currentFunction()->findAddress(id);
    queue<int> params;
    if (node) {
        node->getParams(&params);
    }
    while (!params.empty()) {
        int param = params.front();
        generateQuad(IPARAM_, -1, -1, param);
        params.pop();
    }
    generateQuad(call, -1, -1, imageAddress);
}

int popOperand() {
    int temp = operands.top(); operands.pop();
    types.pop();
    return temp;
}

int topOperandType() {
    return types.top();
}

void generateInput(int type) {
    int address = declareTemp(type);
    generateQuad(INPUT_, -1, -1, address);
    pushOperandOfType(address, type);
}

bool getCurrentFactorWasNegated() {
    return currentFactorWasNegated;
}

void setCurrentFactorWasNegated(bool wasNegated) {
    currentFactorWasNegated = wasNegated;
}