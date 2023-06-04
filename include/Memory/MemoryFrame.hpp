#include <iostream>
#include "./MemoryAddresses.hpp"
using namespace std;

/*
This struct acts as a memory space for a specific type of value, whether it be integer, float, string, Boolean or Image.
It has a vector to store all the constant values, except for the ones of the Image, which can't be constant.
It doesn't store any other values.

Its most important method is "addValue", which returns the current index and increases it by one.
This index will ultimately represent the real size of this memory frame.

The struct also contains the offset of the frame, so it can be accessed properly and the size of it so it won't go into the next frame.
*/
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
            cout << "ERROR: Segmentation fault." << endl;
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
            cout << "ERROR: Memory frame inconsistent!"  << endl;
            exit(-1);
        }
        verifyEnoughSize();
        values.push_back(val);
        return this->addValue();
    }
};