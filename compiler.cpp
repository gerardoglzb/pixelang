#include <utility>
#include "compiler.h"

void doOperation(FunctionEntry *function) {
    int rightOperand = operands.top(); operands.top();
    int rightType = types.top(); types.pop();
    int leftOperand = operands.top(); types.pop();
    int leftType = types.top(); types.pop();
    int oper = operators.top(); operators.pop();

    int resultType = semanticCube(oper, leftType, rightType);
    if (resultType > -1) {
        // generate quad
        int result = function->declareTemp(resultType);
    } else {
        cout << "Type mismatch." << endl;;
        exit(-1);
    }
}

void pushOperandByID(string name, FunctionEntry *function) {
    operands.push(function->findAddress(name));
    types.push(function->findType(name));
}

void pushOperandOfType(int address, int type) {
    operands.push(address);
    types.push(type);
}

VariableEntry *declareVariable(string name, int type, VariableTable *table, int lineas) {
    VariableEntry *entry = new VariableEntry(name, type);
    if (table->has(name)) {
        cout << "Error: Redefinition of var " << entry->name << " on line "  << lineas << ".\n";
        exit(-1);
    } else {
        table->insert(entry);
        cout << entry->name << "(" << entry->type << ") ";
    }
    return entry;
}

void declareArray(string name, int type, int size, VariableTable *table, int lineas) {
    if (size <= 0) {
        cout << "Error: Array " << name << " on line "  << lineas << " cannot be of size 0.\n";
        exit(-1);
    }
    VariableEntry *entry = declareVariable(name, (type == 0) ? 5 : 6, table, lineas);
    ArrItem *curr = entry->arrHead;
    for (int i = 0; i < size; i++) {
        ArrItem *item = new ArrItem();
        if (type == 0) {
            int temp = 0;
            item->val = &temp;
        } else {
            float temp = 0.0;
            item->val = &temp;
        }
        curr->next = item;
        curr = curr->next;
    }
}

void declareArrays(IDNode* variable, int type, int size, VariableTable *table, int lineas) {
    cout << "Declarando ";
    do {
        declareArray(variable->name, type, size, table, lineas);
        variable = variable->next;
    }
    while (variable);
    cout << endl;
}

void declareVariables(IDNode *variable, int type, VariableTable *table, int lineas) {
    cout << "Declarando ";
    do {
        declareVariable(variable->name, type, table, lineas);
        variable = variable->next;
    }
    while (variable);
    cout << endl;
}

void declareFunction(string name, int type, FunctionDirectory *funcDir, int lineas) {
    cout << "Declarando ";
    VariableTable *table = new VariableTable();
    if (type == 6) {
        funcDir->global = name;
        table->parent = NULL;
    } else {
        table->parent = funcDir->find(funcDir->global)->table;
    }

    FunctionEntry *entry = new FunctionEntry(name, type, table);

    if (funcDir->has(name)) {
        cout << "Error: Redefinition of function " << entry->name << " on line "  << lineas << ".\n";
        exit(-1);
    } else {
        funcDir->insert(entry);
        funcDir->currentFunctions->push(name);
        cout << entry->name << "(" << entry->type << ") ";
    }
    cout << endl;
}

void declareFunction(string name, int type, FunctionDirectory *funcDir, int lineas, int localSize, int tempSize, int cteSize) {
    cout << "Declarando ";
    VariableTable *table = new VariableTable();
    if (type == 6) {
        funcDir->global = name;
        table->parent = NULL;
    } else {
        table->parent = funcDir->find(funcDir->global)->table;
    }

    FunctionEntry *entry = new FunctionEntry(name, type, table, localSize, tempSize, cteSize);

    if (funcDir->has(name)) {
        cout << "Error: Redefinition of function " << entry->name << " on line "  << lineas << ".\n";
        exit(-1);
    } else {
        funcDir->insert(entry);
        funcDir->currentFunctions->push(name);
        cout << entry->name << "(" << entry->type << ") ";
    }
    cout << endl;
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