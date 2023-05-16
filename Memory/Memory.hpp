#include <iostream>
#include "./MemoryFrame.hpp"

struct Memory {
    MemoryFrame<int> *memoryInt;
    MemoryFrame<float> *memoryFloat;
    MemoryFrame<string> *memoryString;

    Memory(int size, int offset) {
        this->memoryInt = new MemoryFrame<int>(size, offset);
        this->memoryFloat = new MemoryFrame<float>(size, offset + size);
        this->memoryString = new MemoryFrame<string>(size, offset + size * 2);
    }

    int addValue(int type) {
        if (type == INT_) {
            return memoryInt->addValue();
        }
        if (type == FLOAT_) {
            return memoryFloat->addValue();
        }
        if (type == STRING_) {
            return memoryFloat->addValue();
        }
        return -1;
    }
};