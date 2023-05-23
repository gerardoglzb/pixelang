#include <iostream>
using namespace std;

template<typename T>
struct VMemoryFrame {
    int offset;
    T *frame;

    VMemoryFrame(int size, int offset) {
        this->offset = offset;
        this->frame = new T[size];
    }

    void setValue(int idx, T value) {
        frame[idx - offset] = value;
    }

    T getValue(int idx) {
        return frame[idx - offset];
    }
};