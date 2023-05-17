#include <utility>
#include "../include/compiler.hpp"

void verifyFunctionExists(string name, int lineas) {
    if (!funcDir->has(name)) {
        cout << "Function " << name << "doesn't exist in line " << lineas << endl;
        exit(-1);
    }
}

void verifyParameters(string name) {
    if (funcDir->find(name)->nextCurrentParameter()) {
        printf("Too few parameters %s.\n", name.c_str());
        exit(-1);
    }
}

void generateQuad(int oper, int leftOperand, int rightOperand, int result) {
    Quadruple quad = Quadruple(oper, leftOperand, rightOperand, result);
    quads.push_back(quad);
}

void generateGosub(string name) {
    generateQuad(GOSUB_, -1, -1, funcDir->getFunctionID(name));
}

VariableEntry *nextParameter(FunctionEntry *function) {
    VariableEntry *param = function->nextCurrentParameter();
    if (!param) {
        printf("Too many parameters.\n");
        exit(-1);
    }
    return param;
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
    if (!currentCall)
        exit(-1);
    VariableEntry *param = nextParameter(currentCall);

    if (type != param->type) {
        cout << "Parameter is not the same " << type << " " << param->type << endl;
        exit(-1);
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
            oper = "EQUAL";
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
            oper = "RIGHT";
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
    }
    return oper;
}

void printQuad(Quadruple *quad, int idx) {
    printf("%i\t%s\t%i\t%i\t%i\n", idx, operatorName(quad->oper).c_str(), quad->leftOperand, quad->rightOperand, quad->result);
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
    funcDir->currentFunction()->currQuad = quads.size();
}

void printQuads() {
    cout << "QUADS: " << endl;
    int idx = 1;
    while (!quads.empty()) {
        printQuad(&quads.front(), idx++);
        quads.erase(quads.begin());
    }
}

void generateWhile() {
    int type = types.top(); types.pop();
    if (type != INT_) {
        cout << "Error: Expression in cycle not a boolean." << endl;
        exit(-1);
    }
    int result = operands.top(); operands.pop();
    generateQuad(GOTOF_, result, -1, -1);
    jumps.push(quads.size() - 1);
}

void validateLastOperand(int type) {
    if (types.top() != type) {
        printf("Type validation error!");
        exit(-1);
    }
}

void pushLastAssignment() {
    operands.push(lastAssignment);
    types.push(lastAssignmentType);
}

void validateLastAssignment(int type) {
    if (lastAssignmentType != type) {
        printf("Type validation error (assignment)!\n");
        cout << type << " " << lastAssignmentType << endl;
        exit(-1);
    }
}

void validateID(string name, int type) {
    if (funcDir->currentFunction()->findType(name) != type) {
        printf("Type validation error (ID)!");
        exit(-1);
    }
}

void generateFor() {
    int type = types.top(); types.pop();
    if (type != INT_) {
        cout << "Error: Expression in cycle not a boolean." << endl;
        exit(-1);
    }
    int result = operands.top(); operands.pop();
    generateQuad(GOTOF_, result, -1, -1);
    jumps.push(quads.size() - 1);
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
    generateQuad(GOTO_, -1, -1, ret + 1);
    quads[end].result = quads.size() + 1;
}

void pushJumpCurrent() {
    jumps.push(quads.size() + 1);
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
        cout << "Error: Expression in conditional not a boolean." << endl;
        exit(-1);
    }
    int result = operands.top(); operands.pop();
    generateQuad(GOTOF_, result, -1, -1);
    jumps.push(quads.size() - 1);
}

void pushOperator(int oper) {
    operators.push(oper);
}

int declareCte(int type) {
    return funcDir->currentFunction()->cteMemory->addValue(type);
}

int declareTemp(int type) {
    return funcDir->currentFunction()->tempMemory->addValue(type);
}

int declareGlobalTemp(int type) {
    return funcDir->main->tempMemory->addValue(type);
}

int declareLocal(int type) {
    return funcDir->currentFunction()->localMemory->addValue(type);
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

void verifyReturnType(int functionType) {
    if (semanticCube(EQUALS_, lastResultType, functionType) == -1) {
        cout << "Function type and return value are not compatible." << lastResultType << " "  << functionType << endl;
        exit(-1);
    }
}

void pushOperandResult(string name) {
    int functionType = funcDir->find(name)->type;
    if (semanticCube(EQUALS_, currentCall->type, functionType) == -1) {
        cout << "Function type and return value are not compatible.2" << endl;
        exit(-1);
    }
    pushOperandOfType(currentCall->resultAddress, functionType);
}

void doOperation() {
    if (operands.size() >= 1 && !operators.empty()) {
        int rightOperand = operands.top(); operands.pop();
        int rightType = types.top(); types.pop();
        int leftOperand;
        int leftType;
        int oper = operators.top(); operators.pop();

        if (oper == PRINT_ | oper == RETURN_) {
            leftOperand = -1;
            leftType = INT_;
        }  else if (operands.size() == 1 && oper != EQUALS_) {
            leftOperand = declareCte(0);
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
                cout << " assigning " << resultType << endl;
                lastAssignmentType = resultType;
                lastAssignment = result;
            } else if (oper == PRINT_) {
                result = -1;
            } else if (oper == RETURN_) {
                result = declareGlobalTemp(rightType);
                lastResult = result;
                lastResultType = rightType;
            } else {
                result = declareTemp(resultType);
            }
            generateQuad(oper, leftOperand, rightOperand, result);
            pushOperandOfType(result, resultType);
        } else {
            cout << "Type mismatch." << endl;;
            exit(-1);
        }
    } else {
        cout << "Whoops. error for the time being. " << endl;
    }
}

void checkIfShouldDoOperation(vector<int> myOperators) {
    if (operators.size() == 0) {
        return;
    }
    if (operators.top() == RIGHTPAR_) {
        operators.pop();
        operators.pop();
        return;
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

VariableEntry *declareVariable(string name, int type, int lineas) {
    VariableTable *table = funcDir->currentVariableTable();
    if (table->has(name)) {
        cout << "Error: Redefinition of var " << name << " on line "  << lineas << ".\n";
        exit(-1);
    }
    VariableEntry *entry = new VariableEntry(name, type);
    entry->address = declareLocal(type);
    table->insert(entry);
    return entry;
}

VariableEntry *declareParameter(string name, int type, int lineas, int address) {
    VariableTable *table = funcDir->currentParameterTable();
    if (table->has(name)) {
        cout << "Error: Redefinition of parameter " << name << " on line "  << lineas << ".\n";
        exit(-1);
    }
    VariableEntry *entry = new VariableEntry(name, type);
    entry->address = address;
    table->insert(entry);
    return entry;
}

void declareArray(string name, int type, int size, int lineas) {
    if (size <= 0) {
        cout << "Error: Array " << name << " on line "  << lineas << " cannot be of size 0.\n";
        exit(-1);
    }
    VariableEntry *entry = declareVariable(name, (type == INT_) ? 5 : 6, lineas);
    entry->length = size;
}

void declareVariables(IDNode *variable, int type, int lineas) {
    do {
        declareVariable(variable->name, type, lineas);
        variable = variable->next;
    }
    while (variable);
}

void declareArrays(IDNode* variable, int type, int size, int lineas) {
    do {
        declareArray(variable->name, type, size, lineas);
        variable = variable->next;
    }
    while (variable);
}

void declareFunction(string name, int type, int lineas) {
    VariableTable *table = new VariableTable();
    table->parent = funcDir->findMain()->variableTable;

    FunctionEntry *entry = new FunctionEntry(name, type, table);

    if (funcDir->has(name)) {
        cout << "Error: Redefinition of function " << entry->name << " on line "  << lineas << ".\n";
        exit(-1);
    } else {
        funcDir->insert(entry);
    }
}

void declareMainFunction(string name, int lineas, FunctionDirectory *directory) {
    VariableTable *table = new VariableTable();
    table->parent = NULL;

    FunctionEntry *entry = new FunctionEntry(name, 4, table, 2000, 4000, 2000);

    funcDir = directory;
    funcDir->main = entry;

    generateQuad(GOTO_, -1, -1, -1);
}

int semanticCube(int oper, int type1, int type2) {
    int cube[5][2][2] = {
        {
            {0, -1,},
            {1, 1,},
        },
        {
            {0, 1,},
            {1, 1,},
        },
        {
            {0, 1,},
            {1, 1,},
        },
        {
            {0, 1,},
            {1, 1,},
        },
        {
            {1, 1,},
            {1, 1,},
        },
    };

    if (oper == PRINT_ || oper == RETURN_)
        return 0;

    if (oper > 10 || type1 > 1 || type2 > 1) {
        cout << "Error in semantic cube." << endl;
        printf("%i %i %i\n", oper, type1, type2);
        exit(-1);
    }

    return oper < 5 ? cube[oper][type1][type2] : 0;
}