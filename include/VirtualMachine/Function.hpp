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

    Function(string item[9]) {
        this->type = stoi(item[0]);
        this->resultAddress = stoi(item[1]);
        this->memoryOffset = stoi(item[2]);
        this->localInts = stoi(item[3]);
        this->localFloats = stoi(item[4]);
        this->localStrings = stoi(item[5]);
        this->tempInts = stoi(item[6]);
        this->tempFloats = stoi(item[7]);
        this->tempStrings = stoi(item[8]);
    }
};