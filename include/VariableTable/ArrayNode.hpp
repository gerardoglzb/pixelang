#include <iostream>

struct ArrayNode {
    int size;
    int mOrK;
    ArrayNode *next;

    ArrayNode(int size) {
        this->size = size;
        this->mOrK = -1;
        this->next = nullptr;
    };
};