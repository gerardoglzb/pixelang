#include <iostream>
#include "./FunctionEntry.hpp"

/*
This struct contains all of the FunctionEntry instances that have been created (each representing a function of the program).
"head" points to the head of the linked list that contains all these instances, with the head having just some dummy data.
The main function exists on its own and can be accessed through the "main" pointer.
*/
struct FunctionDirectory {
    FunctionEntry *head;
    FunctionEntry *main;
    FunctionEntry *currentFunc;

    FunctionEntry *findMain() {
        return main;
    }

    void printFunctions(ofstream &file) {
        FunctionEntry *entry = head->next;
        main->printFunction(file);
        while (entry) {
            entry->printFunction(file);
            entry = entry->next;
        }
    }

    int getFunctionID(string name) {
        FunctionEntry *entry = head->next;
        int counter = 0;
        while (entry) {
            if (entry->name == name) {
                return counter;
            }
            entry = entry->next;
            counter++;
        }
        return -1;
    }

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

    FunctionEntry *currentFunction() {
        return currentFunc ? currentFunc : main;
    }

    void removeVariableTable(string name) {
        FunctionEntry *entry = head;
        FunctionEntry *prev = NULL;
        currentFunc = nullptr;
        while (entry) {
            if (entry->name == name) {
                break;
            }
            prev = entry;
            entry = entry->next;
        }
        if (entry) {
            entry->removeVariableTable();
        }
    }

    void insert(FunctionEntry *newEntry) {
        FunctionEntry *entry = head;
        while (entry->next) {
            entry = entry->next;
        }
        entry->next = newEntry;
        currentFunc = entry->next;
    }

    bool has(string name) {
        return find(name) != NULL;
    }

    VariableTable *currentVariableTable() {
        return this->currentFunction()->variableTable;
    }

    VariableTable *currentParameterTable() {
        return this->currentFunction()->parameterTable;
    }

    FunctionDirectory() {
        this->head = new FunctionEntry();
        this->main = nullptr;
        this->currentFunc = nullptr;
    };

};