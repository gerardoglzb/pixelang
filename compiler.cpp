#include <utility>
#include "compiler.h"

VariableEntry *declareVariable(string name, char type, VariableTable *table, int lineas) {
    VariableEntry *entry = new VariableEntry(name, type);
    if (table->has(name)) {
        cout << "Error: Redefinition of var " << entry->name << " on line "  << lineas << ".\n";
        exit(-1);
    } else {
        table->insert(entry);
        cout << entry->name << "(" << entry->type << ") " << endl;
    }
    return entry;
}

void declareArray(string name, char type, int size, VariableTable *table, int lineas) {
    if (size <= 0) {
        cout << "Error: Array " << name << " on line "  << lineas << " cannot be of size 0.\n";
        exit(-1);
    }
    VariableEntry *entry = declareVariable(name, (type == 'i') ? 'j' : 'g', table, lineas);
    ArrItem *curr = entry->array;
    for (int i = 0; i < size; i++) {
        ArrItem *item = new ArrItem();
        if (type == 'i') {
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

void declareVariables(IDNode *variable, char type, FunctionDirectory *funcDir, int lineas) {
    FunctionEntry *entry = funcDir->find(funcDir->currentFunctions->top());
    VariableTable *table = entry->table;
    cout << "Declarando ";
    do {
        declareVariable(variable->name, type, table, lineas);
        variable = variable->next;
    }
    while (variable);
}

void declareFunction(string name, char type, FunctionDirectory *funcDir, int lineas) {
    VariableTable *table = new VariableTable();
    if (type == 'p') {
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
        cout << entry->name << "(" << entry->type << ") " << endl;
    }
}
