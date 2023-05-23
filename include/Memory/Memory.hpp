#include <iostream>
#include "./MemoryFrame.hpp"

struct Memory {
    MemoryFrame<int> *memoryInt;
    MemoryFrame<float> *memoryFloat;
    MemoryFrame<string> *memoryString;

    int getSizeInt() {
        return memoryInt->size;
    }

    int getSizeFloat() {
        return memoryFloat->size;
    }

    int getSizeString() {
        return memoryString->size;
    }

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

    int addValue(int type, int value) {
        return memoryInt->addValue(value);
    }

    int addValue(int type, float value) {
        return memoryFloat->addValue(value);
    }

    int addValue(int type, string value) {
        return memoryString->addValue(value);
    }
};