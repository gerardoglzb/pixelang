#include <iostream>
#include "./VariableEntry.hpp"

/*
This struct contains all of the VariableEntry instances that have been created (each representing a variable in the current scope).
"head" points to the head of the linked list that contains all these instances, with the head having just some dummy data.
The parent pointer always points to the variable table of the main function, except when the table in question is already the one for
the main function.

Some relevant methods this struct are methods for finding a variable in the table in either just the current scope or the global scope
too, finding the address or type of a variable, and inserting a new VariableEntry into the list.
*/
struct VariableTable {
    VariableEntry *head;
    VariableTable *parent;

    void clean() {
        VariableEntry *entry = head;
        while (entry) {
            VariableEntry *next = entry->next;
            entry->next = nullptr;
            // delete entry;
            entry = next;
        }
    }

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

    VariableEntry *fullFind(string name) {
        VariableEntry *result = find(name);
        if (!result && parent) { // TODO: make sure there's a parent bf trying something funnny
            result = parent->find(name);
        }
        if (!result) {
            cout << "Error: Variable " << name << " is not defined." << endl;
            exit(-1);
        }
        return result;
    }

    int findAddress(string name) {
        return fullFind(name)->address;
    }

    int findType(string name) {
        return fullFind(name)->type;
    }

    void insert(VariableEntry *newEntry) {
        VariableEntry *entry = head;
        while (entry->next) {
            entry = entry->next;
        }
        entry->next = newEntry;
    }

    bool has(string name) {
        return find(name) != NULL;
    }

    bool fullHas(string name) {
        return fullFind(name) != NULL;
    }

    VariableTable() {
        this->head = new VariableEntry();
        this->parent = nullptr;
    };

    VariableTable(VariableTable *parent) {
        this->head = new VariableEntry();
        this->parent = parent;
    };
};