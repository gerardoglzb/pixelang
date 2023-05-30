#include <iostream>
#include "./ArrayNode.hpp"

struct VariableEntry {
    string name;
    int type;
    int address;
    ArrayNode *arrNode;
    ArrayNode *currArrNode;
    VariableEntry *next;

    void resetArrayNode() {
        currArrNode = arrNode;
    }

    void nextNode() {
        if (!currArrNode) {
            cout << "Array doesn't have enough dimensions for indexing." << endl;
            exit(-1);
        }
        this->currArrNode = currArrNode->next;
    }

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
        if (arrNode)
            this->arrNode->calculateK();
    };
};