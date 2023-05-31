#include <iostream>
#include "./VMemoryFrame.hpp"
using namespace std;

struct VMemory {
    VMemoryFrame<int> *memoryInt;
    VMemoryFrame<float> *memoryFloat;
    VMemoryFrame<string> *memoryString;
    VMemoryFrame<bool> *memoryBool;

    VMemory(int intSize, int floatSize, int stringSize, int boolSize, int intOffset, int floatOffset, int stringOffset, int boolOffset) {
        this->memoryInt = new VMemoryFrame<int>(intSize, intOffset, INT_);
        this->memoryFloat = new VMemoryFrame<float>(floatSize, floatOffset, FLOAT_);
        this->memoryString = new VMemoryFrame<string>(stringSize, stringOffset, STRING_);
        this->memoryBool = new VMemoryFrame<bool>(boolSize, boolOffset, BOOL_);
    }

    int getType(int address) {
        int intType = memoryInt->getType(address);
        intType = (intType == -1) ? memoryFloat->getType(address) : intType;
        intType = (intType == -1) ? memoryString->getType(address) : intType;
        intType = (intType == -1) ? memoryBool->getType(address) : intType;
        return intType;
    }

    void setValue(int idx, int value) {
        if (this->memoryInt->setValue(idx, value) == -1) {
            this->memoryBool->setValue(idx, value);
        }
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

    bool getValueBool(int idx) {
        return this->memoryBool->getValue(idx);
    }
};