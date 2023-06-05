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
    VariableEntry *head; // Dummy head for linked list
    VariableTable *parent; // Global variable table

    // Cleans svariable table after it's no longer needed
    void clean() {
        VariableEntry *entry = head;
        while (entry) {
            VariableEntry *next = entry->next;
            entry->next = nullptr;
            entry = next;
        }
    }

    // Finds variable in table by traversing linked list
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

    // Finds variable in table or parent table by traversing both lists
    VariableEntry *fullFind(string name) {
        VariableEntry *result = find(name);
        if (!result && parent) {
            result = parent->find(name);
        }
        if (!result) {
            cout << "ERROR: Variable " << name << " is not defined." << endl;
            exit(-1);
        }
        return result;
    }

    // Finds address of variable by name
    int findAddress(string name) {
        return fullFind(name)->address;
    }

    // Finds type of variable by name
    int findType(string name) {
        return fullFind(name)->type;
    }

    // Inserts new variable into table by appending it at the end of the linked list
    void insert(VariableEntry *newEntry) {
        VariableEntry *entry = head;
        while (entry->next) {
            entry = entry->next;
        }
        entry->next = newEntry;
    }

    // Checks if table has a certain variable by seeing if it can be found
    bool has(string name) {
        return find(name) != NULL;
    }

    // Checks if table has a certain variable by seeing if it can be found in its table or the global one
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