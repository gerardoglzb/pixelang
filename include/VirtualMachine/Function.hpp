#include <iostream>

struct Function {
    int type;
    int resultAddress;
    int memoryOffset;
    int localInts;
    int localFloats;
    int localStrings;
    int tempInts;
    int tempFloats;
    int tempStrings;

    Function(int type, int resultAddress, int memoryOffset, int localInts, int localFloats, int localStrings, int tempInts, int tempFloats, int tempStrings) {
        this->type = type;
        this->resultAddress = resultAddress;
        this->memoryOffset = memoryOffset;
        this->localInts = localInts;
        this->localFloats = localFloats;
        this->localStrings = localStrings;
        this->tempInts = tempInts;
        this->tempFloats = tempFloats;
        this->tempStrings = tempStrings;
    }
};