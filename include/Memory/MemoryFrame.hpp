#include <iostream>
using namespace std;

template<typename T>
struct MemoryFrame {
    int size;
    int index;
    int offset;

    MemoryFrame(int size, int offset) {
        this->size = size;
        this->index = 0;
        this->offset = offset;
    }

    int addValue() {
        int temp = index;
        index++;
        return temp + offset;
    }
};