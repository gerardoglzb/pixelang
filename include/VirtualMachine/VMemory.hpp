#include <iostream>
#include "./VMemoryFrame.hpp"
using namespace std;

struct VMemory {
    VMemoryFrame<int> *memoryInt;
    VMemoryFrame<float> *memoryFloat;
    VMemoryFrame<string> *memoryString;

    VMemory(int intSize, int floatSize, int stringSize, int totalOffset, int intOffset, int floatOffset, int stringOffset) {
        this->memoryInt = new VMemoryFrame<int>(intSize, totalOffset + intOffset, INT_);
        this->memoryFloat = new VMemoryFrame<float>(floatSize, totalOffset + floatOffset, FLOAT_);
        this->memoryString = new VMemoryFrame<string>(stringSize, totalOffset + stringOffset, STRING_);
    }

    int getType(int address) {
        int intType = memoryInt->getType(address);
        intType = (intType == -1) ? memoryFloat->getType(address) : intType;
        intType = (intType == -1) ? memoryString->getType(address) : intType;
        return intType;
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

    int getValueInt(int idx) {
        return this->memoryInt->getValue(idx);
    }

    float getValueFloat(int idx) {
        return this->memoryFloat->getValue(idx);
    }

    string getValueString(int idx) {
        return this->memoryString->getValue(idx);
    }
};