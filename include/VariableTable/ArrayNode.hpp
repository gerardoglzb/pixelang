#include <iostream>

/*
Node used by parser to keep track of all the dimensions of an array that is being declared.
It also contains all the methods necessary to calculate all the key values that allow for array indexing: size, r, offset and
MOrK, which contains the value of K if this node is the last dimension of the array or the corresponding M if not.

It contains a pointer to the next node since it works as part of a linked list.
*/
struct ArrayNode {
    int size;
    int mOrK;
    int r;
    int offset;
    ArrayNode *prev;
    ArrayNode *next;

    int getFullSize() {
        return next ? this->size * next->getFullSize() : this->size;
    }

    int getM0() {
        return next ? next->getM0() : r;
    }

    void calculateK() {
        int m = prev ? prev->mOrK / size : getM0() / size;
        this->mOrK = next ? m : -offset;
        if (next)
            next->calculateK();
    }
    
    void calculateRs() {
        if (next) {
            next->calculateRs();
        } else {
            getRs();
        }
    }

    int getRs() {
        this->r = prev ? r * prev->getRs() : r;
        return this->r;
    }

    ArrayNode(int size, ArrayNode *next) {
        this->size = size;
        this->mOrK = -1;
        this->next = next;
        this->r = size;
        this->offset = 0;
        if (next) {
            next->prev = this;
        }
    };

    ArrayNode(int size) {
        this->size = size;
        this->mOrK = -1;
        this->next = nullptr;
        this->r = size;
        this->offset = 0;
    };
};