#include <iostream>
#include "./VariableEntry.hpp"

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
        if (!result) {
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

    string getID(int address) {
        VariableEntry *entry = head;
        while (entry) {
            if (entry->address == address) {
                return entry->name;
            }
            entry = entry->next;
        }
        return "";
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

    VariableTable() {
        this->head = new VariableEntry();
        this->parent = nullptr;
    };

    VariableTable(VariableTable *parent) {
        this->head = new VariableEntry();
        this->parent = parent;
    };
};