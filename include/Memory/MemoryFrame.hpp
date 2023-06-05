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
    int size; // Limit size of frame
    int index; // Real current size of frame
    int offset; // Offset of frame for addresses
    vector<T> values; // For constant memory spaces, holds the constant values of addresses

    MemoryFrame(int offset, int size) {
        this->size = size;
        this->index = 0;
        this->offset = offset;
    }

    // Verify that the real size hasn't surpassed the limit
    void verifyEnoughSize() {
        if (index >= size) {
            cout << "ERROR: Segmentation fault." << endl;
            exit(-1);
        }
    }

    // Increases real size by 1 and returns the address
    int addValue() {
        verifyEnoughSize();
        int temp = index;
        index++;
        return temp + offset;
    }

    // Increases real size by 1, stores the value and returns the address
    int addValue(T val) {
        if (index != values.size()) {
            cout << "ERROR (Internal): Memory frame inconsistent!"  << endl;
            exit(-1);
        }
        verifyEnoughSize();
        values.push_back(val);
        return this->addValue();
    }
};