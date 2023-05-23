#include <iostream>
#include <type_traits>
#include "./VMemoryFrame.hpp"

struct VMemory {
    VMemoryFrame<int> *memoryInt;
    VMemoryFrame<float> *memoryFloat;
    VMemoryFrame<string> *memoryString;

    VMemory(int intSize, int floatSize, int stringSize, int intOffset, int floatOffset, int stringOffset) {
        this->memoryInt = new VMemoryFrame<int>(intSize, intOffset);
        this->memoryFloat = new VMemoryFrame<float>(floatSize, floatOffset);
        this->memoryString = new VMemoryFrame<string>(stringSize, stringOffset);
    }

    void setValue(int idx, int value) {
        this->memoryInt->setValue(idx, value);
    }

    void setValue(int idx, float value) {
        this->memoryFloat->setValue(idx, value);
    }

    void setValue(int idx, string value) {
        this->memoryString->setValue(idx, value);
    }

    template<typename T>
    T getValue(int idx) {
        if (std::is_same<T, int>::value) {
            return this->memoryInt->getValue(idx);
        }
        if (std::is_same<T, float>::value) {
            return this->memoryFloat->getValue(idx);
        }
        if (std::is_same<T, string>::value) {
            return this->memoryString->getValue(idx);
        }
    }
};