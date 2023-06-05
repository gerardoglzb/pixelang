#include <iostream>
#include "./FunctionEntry.hpp"

/*
This struct contains all of the FunctionEntry instances that have been created (each representing a function of the program).
"head" points to the head of the linked list that contains all these instances, with the head having just some dummy data.
The main function exists on its own and can be accessed through the "main" pointer.
*/
struct FunctionDirectory {
    FunctionEntry *head; // Dummy head for FunctionEntry linked list.
    FunctionEntry *main; // Main function.
    FunctionEntry *currentFunc; // Current function.

    // Returns the main function of the directory.
    FunctionEntry *findMain() {
        return main;
    }

    // Prints all the functions' relevant data to the object file.
    void printFunctions(ofstream &file) {
        FunctionEntry *entry = head->next;
        main->printFunction(file);
        while (entry) {
            entry->printFunction(file);
            entry = entry->next;
        }
    }

    // Gets the ID of a function by traversing the linked list.
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

    // Finds a function in the current scope by traversing the linked list.
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

    // Returns currentFunc or defaults to main if currentFunc is nullptr.
    FunctionEntry *currentFunction() {
        return currentFunc ? currentFunc : main;
    }

    // Removes variable table from function.
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

    // Inserts function at the end of the linked list.
    void insert(FunctionEntry *newEntry) {
        FunctionEntry *entry = head;
        while (entry->next) {
            entry = entry->next;
        }
        entry->next = newEntry;
        currentFunc = entry->next;
    }

    // Checks if a function ID exists in the directory by seeing if it can be found.
    bool has(string name) {
        return find(name) != NULL;
    }

    // Returns current function's variable table.
    VariableTable *currentVariableTable() {
        return this->currentFunction()->variableTable;
    }

    // Returns current function's parameter table.
    VariableTable *currentParameterTable() {
        return this->currentFunction()->parameterTable;
    }

    FunctionDirectory() {
        this->head = new FunctionEntry();
        this->main = nullptr;
        this->currentFunc = nullptr;
    };

};