#include <utility>
#include "compiler.h"

void declareVariable(string name, char type, VariableTable *table, int lineas) {
    VariableEntry entry;
    entry.name = name;
    entry.type = type;
    if (table->has(name)) {
        cout << "Error: Redefinition of var " << entry.name << " on line "  << lineas << ".\n";
        exit(-1);
    } else {
        table->insert(&entry);
        cout << entry.name << "(" << entry.type << ") " << endl;
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

    FunctionEntry entry;
    entry.name = name;
    entry.type = type;
    entry.table = table;

    if (funcDir->has(name)) {
        cout << "Error: Redefinition of function " << entry.name << " on line "  << lineas << ".\n";
        exit(-1);
    } else {
        funcDir->insert(&entry);
        funcDir->currentFunctions->push(name);
        cout << entry.name << "(" << entry.type << ") " << endl;
    }
}
