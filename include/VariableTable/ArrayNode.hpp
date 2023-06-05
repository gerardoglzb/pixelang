#include <iostream>

/*
Node used by parser to keep track of all the dimensions of an array that is being declared.
It also contains all the methods necessary to calculate all the key values that allow for array indexing: size, r, offset and
MOrK, which contains the value of K if this node is the last dimension of the array or the corresponding M if not.

It contains a pointer to the next node since it works as part of a linked list.
*/
struct ArrayNode {
    int size; // Size of array dimension
    int mOrK; // Mn or K, depending of dimension
    int r;
    int offset;
    ArrayNode *prev; // Previous node in linked list
    ArrayNode *next; // Nextnode in linked list

    // Returns full size of linked list
    int getFullSize() {
        return next ? this->size * next->getFullSize() : this->size;
    }

    // Gets the next node's M0 if there is one. Otherwise, this is the last dimension and thus, M0 is r.
    int getM0() {
        return next ? next->getM0() : r;
    }

    // Calculates K for final node.
    void calculateK() {
        int m = prev ? prev->mOrK / size : getM0() / size;
        this->mOrK = next ? m : -offset;
        if (next)
            next->calculateK();
    }
    
    // Calculates Rs for all nodes.
    void calculateRs() {
        if (next) {
            next->calculateRs();
        } else {
            getRs();
        }
    }

    // Returns r and sets it for all previous nodes.
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