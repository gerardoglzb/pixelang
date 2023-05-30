#include <iostream>
#include "./ArrayNode.hpp"

struct VariableEntry {
    string name;
    int type;
    int address;
    ArrayNode *arrNode;
    VariableEntry *next;

    VariableEntry() {
        this->name = "";
        this->type = 7;
        this->next = nullptr;
        this->arrNode = nullptr;
    };

    VariableEntry(string name, int type) {
        this->name = name;
        this->type = type;
        this->address = -1;
        this->next = nullptr;
        this->arrNode = nullptr;
    };

    VariableEntry(string name, int type, int address, ArrayNode *arrNode) {
        this->name = name;
        this->type = type;
        this->address = address;
        this->next = nullptr;
        this->arrNode = arrNode;
        this->arrNode->calculateK();
    };
};