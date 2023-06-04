#include <iostream>
#include "./ArrayNode.hpp"

/*
This struct represents a variable and contains all of its relevant data: type and address.
The name of the variable works as an ID of sorts to access it through a variable table and make sure the name is not repeated inside
the corresponding scope.

It also contains pointers to the next entry, since it works as a linked list, as well as an ArrayNode instance that represents the head
of a possible linked list with the details of each dimension if this variable is an array. If it's not an array, then this pointer will
point to null.
*/
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
            cout << "ERROR: Array doesn't have enough dimensions for indexing!" << endl;
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