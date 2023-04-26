#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

struct VariableEntry {
    string name = "";
    string type;
    VariableEntry *next = NULL;
};

struct VariableTable {
    VariableEntry *head;
    VariableTable *parent = NULL;

    VariableEntry *find(string name) {
        VariableEntry *entry = head;
        while (entry) {
            if (entry->name == name) {
                return entry;
            }
            entry = entry->next;
        }
        return NULL;
    }

    void insert(VariableEntry *newEntry) {
        VariableEntry *entry = head;
        if (entry == NULL) {
            entry = newEntry;
            return;
        }
        while (entry->next) {
            entry = entry->next;
        }
        entry->next = newEntry;
    }

    bool has(string name) {
        return find(name) != NULL;
    }
};

struct IDNode {
    string name;
    IDNode *next;
};

struct FunctionEntry {
    string name = "";
    VariableTable *table;
    char type;
    FunctionEntry *next = NULL;

    void removeTable() {
        delete table;
        table = NULL;
    }
};

struct FunctionDirectory {
    FunctionEntry *head = new FunctionEntry();
    stack<string> *currentFunctions = new stack<string>();
    string global; // Si se quiere agregar nesting, se cambia esto.

    FunctionEntry *find(string name) {
        FunctionEntry *entry = head;
        while (entry) {
            if (entry->name == name) {
                return entry;
            }
            entry = entry->next;
        }
        return NULL;
    }

    void remove(string name) {
        FunctionEntry *entry = head;
        FunctionEntry *prev = NULL;
        while (entry) {
            if (entry->name == name) {
                break;
            }
            prev = entry;
            entry = entry->next;
        }
        prev->next = entry->next;
        delete entry;
    }

    void removeTable(string name) {
        FunctionEntry *entry = head;
        while (entry) {
            if (entry->name == name) {
                break;
            }
            entry->removeTable();
        }
    }

    void insert(FunctionEntry *newEntry) {
        FunctionEntry *entry = head;
        while (entry->next) {
            entry = entry->next;
        }
        entry->next = newEntry;
    }

    bool has(string name) {
        return find(name) != NULL;
    }

    FunctionEntry *currentFunction() {
        return find(currentFunctions->top());
    }

};

void declareVariable(string name, char type, VariableTable *table, int lineas);

void declareVariables(IDNode *variable, char type, FunctionDirectory *funcDir, int lineas);

void declareFunction(string name, char type, FunctionDirectory *funcDir, int lineas);
