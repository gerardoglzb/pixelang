#include <iostream>

/*
Node used by parser to keep track of all the variables that are being declared in a single row.

It contains a pointer to the next node since it works as part of a linked list.
*/
struct IDNode {
    string name;
    IDNode *next;

    IDNode() {
        this->name = "";
        this->next = nullptr;
    };

    IDNode(string name) {
        this->name = name;
        this->next = nullptr;
    };

    IDNode(string name, IDNode *next) {
        this->name = name;
        this->next = next;
    };
};