#include <iostream>
#include "./MemoryFrame.hpp"

struct Memory {
    MemoryFrame *memoryInt;
    MemoryFrame *memoryFloat;
    MemoryFrame *memoryString;

    Memory(int size, int offset) {
        this->memoryInt = new MemoryFrame(size, offset);
        this->memoryFloat = new MemoryFrame(size, offset + size);
        this->memoryString = new MemoryFrame(size, offset + size * 2);
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