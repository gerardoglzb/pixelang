#include <iostream>

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
        cout << "calculating K moko " << getM0() << endl;
        int m = prev ? prev->mOrK / size : getM0() / size;
        this->mOrK = next ? m : -offset;
        cout << "mork for size" << size << " r " << r << " IS " << mOrK << endl;
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
        cout << "old r for size" << size << " r " << r << " IS " << r << endl;
        this->r = prev ? r * prev->getRs() : r;
        cout << "r for size" << size << " r " << r << " IS " << r << endl;
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