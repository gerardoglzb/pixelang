#include <iostream>

struct VariableEntry {
    string name;
    int type;
    int address;
    int length;
    VariableEntry *next;

    VariableEntry() {
        this->name = "";
        this->type = 7;
        this->next = nullptr;
        this->length = 1;
    };

    VariableEntry(string name, int type) {
        this->name = name;
        this->type = type;
        this->address = -1;
        this->next = nullptr;
        this->length = 1;
    };

    VariableEntry(string name, int type, int length) {
        this->name = name;
        this->type = type;
        this->address = -1;
        this->next = nullptr;
        this->length = length;
    };
};