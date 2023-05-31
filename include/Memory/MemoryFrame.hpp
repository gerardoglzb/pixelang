#include <iostream>
#include "./MemoryAddresses.hpp"
using namespace std;

template<typename T>
struct MemoryFrame {
    int size;
    int index;
    int offset;
    vector<T> values;

    MemoryFrame(int offset, int size) {
        this->size = size;
        this->index = 0;
        this->offset = offset;
    }

    void verifyEnoughSize() {
        if (index >= size) {
            cout << "Segmentation fault." << endl;
            exit(-1);
        }
    }

    int addValue() {
        verifyEnoughSize();
        int temp = index;
        index++;
        return temp + offset;
    }

    int addValue(T val) {
        if (index != values.size()) {
            cout << "Memory frame inconsistent."  << endl;
            exit(-1);
        }
        verifyEnoughSize();
        values.push_back(val);
        return this->addValue();
    }
};