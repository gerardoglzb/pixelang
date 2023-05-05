#include <utility>
#include "compiler.h"

void generateQuad(int oper, int leftOperand, int rightOperand, int result) {
    Quadruple quad = Quadruple(oper, leftOperand, rightOperand, result);
    quads.push(quad);
}

void printQuad(Quadruple *quad) {
    printf("%i\t%i\t%i\t%i\n", quad->oper, quad->leftOperand, quad->rightOperand, quad->result);
}

void printQuads() {
    cout << "QUADS: " << endl;
    while (!quads.empty()) {
        printQuad(&quads.front());
        quads.pop();
    }
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

int declareLocal(int type) {
    return funcDir->currentFunction()->localMemory->addValue(type);
}

void doOperation() {
    if (operands.size() >= 1 && !operators.empty()) {
        int rightOperand = operands.top(); operands.pop();
        int rightType = types.top(); types.pop();
        int leftOperand;
        int leftType;
        int oper = operators.top(); operators.pop();
        
        if (operands.size() == 1 && oper != 0) {
            leftOperand = declareCte(0);
            leftType = 0;
        } else {
            leftOperand = operands.top(); operands.pop();
            leftType = types.top(); types.pop();
        }

        printf("oper: %i %i %i\n", oper, leftOperand, rightOperand);

        int resultType = semanticCube(oper, leftType, rightType);
        if (resultType > -1) {
            int result;
            if (oper == 0) {
                result = leftOperand;
                leftOperand = -1;
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
    if (operators.top() == 12) {
        operators.pop();
        operators.pop();
        return;
    }
    if (operators.top() == 11) {
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
    cout << "PUSHING by id " << name << " " << function->findAddress(name) << endl;
    operands.push(function->findAddress(name));
    types.push(function->findType(name));
}

void pushOperandOfType(int address, int type) {
    operands.push(address);
    types.push(type);
}

VariableEntry *declareVariable(string name, int type, int lineas) {
    VariableTable *table = funcDir->currentTable();
    if (table->has(name)) {
        cout << "Error: Redefinition of var " << name << " on line "  << lineas << ".\n";
        exit(-1);
    }
    VariableEntry *entry = new VariableEntry(name, type);
    entry->address = declareLocal(type);
    table->insert(entry);
    return entry;
}

void declareArray(string name, int type, int size, int lineas) {
    if (size <= 0) {
        cout << "Error: Array " << name << " on line "  << lineas << " cannot be of size 0.\n";
        exit(-1);
    }
    VariableEntry *entry = declareVariable(name, (type == 0) ? 5 : 6, lineas);
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
    table->parent = funcDir->findMain()->table;

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
}

// 0 equal, 1 add, 2 sub, 3 multi, 4 div
// 0 int, 1 float, 2 string -1 err
int semanticCube(int oper, int type1, int type2) {
    int cube[5][2][2] = {
        {
            {1, -1,},
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

    if (oper > 4 || type1 > 1 || type2 > 1) {
        cout << "Error in semantic cube." << endl;
    }

    return cube[oper][type1][type2];
}