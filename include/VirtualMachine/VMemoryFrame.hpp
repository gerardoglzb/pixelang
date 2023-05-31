#include <iostream>
#include "../Semantics/Type.hpp"
using namespace std;

template<typename T>
struct VMemoryFrame {
    int offset;
    int size;
    T *frame;
    int type;

    VMemoryFrame(int size, int offset, int type) {
        this->offset = offset;
        this->size = size;
        this->type = type;
        this->frame = new T[size];
    }

    int setValue(int idx, T value) {
        if (offset > idx || (idx - offset) >= size)
            return -1;
        frame[idx - offset] = value;
        return (idx - offset);
    }

    T getValue(int idx) {
        return frame[idx - offset];
    }

    int getType(int address) {
        if (address >= offset && address < offset + size) {
            return type;
        }
        return -1;
    }
};