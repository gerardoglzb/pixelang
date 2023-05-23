#include <iostream>
using namespace std;

template<typename T>
struct MemoryFrame {
    int size;
    int index;
    int offset;
    vector<int> values;

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

    int addValue(T val) {
        values.push_back(val);
        return this->addValue();
    }
};