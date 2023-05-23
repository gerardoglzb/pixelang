#include <iostream>
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

    void setInt(int idx, int value) {
        this->memoryInt->setValue(idx, value);
    }

    int getInt(int idx) {
        return this->memoryInt->getValue(idx);
    }

    void setFloat(int idx, float value) {
        this->memoryFloat->setValue(idx, value);
    }

    float getFloat(int idx) {
        return this->memoryFloat->getValue(idx);
    }

    void setString(int idx, string value) {
        this->memoryString->setValue(idx, value);
    }

    string getString(int idx) {
        return this->memoryString->getValue(idx);
    }
};