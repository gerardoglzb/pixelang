#include <iostream>

struct ArrayNode {
    int size;
    int mOrK;
    int r;
    int offset;
    ArrayNode *prev;
    ArrayNode *next;

    int getM0() {
        return next ? next->getM0 ? r;
    }

    void calculateK() {
        int m = prev ? prev->mOrK next->getM0(): 
        this->mOrK = next ? m : offset;
    }

    ArrayNode(int size, ArrayNode *prev) {
        this->size = size;
        this->mOrK = -1;
        this->prev = prev;
        this->next = nullptr;
        this->r = size + 1;
        if (prev) {
            this->r *= prev->r;
            prev->next = this;
        }
        this->offset = 0;
    };

    ArrayNode(int size) {
        this->size = size;
        this->mOrK = -1;
        this->prev = nullptr;
        this->r = size + 1;
        this->offset = 0;
    };
};