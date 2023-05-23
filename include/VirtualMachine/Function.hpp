#include <iostream>

struct Function {
    int type;
    int resultAddress;
    int memoryOffset;
    int localVals[3];
    int tempVals[3];
    int cteVals[3];

    Function(int type, int resultAddress, int memoryOffset, int localInts, int localFloats, int localStrings, int tempInts, int tempFloats, int tempStrings, int cteInts, int cteFloats, int cteStrings) {
        this->type = type;
        this->resultAddress = resultAddress;
        this->memoryOffset = memoryOffset;
        this->localVals[0] = localInts;
        this->localVals[1] = localFloats;
        this->localVals[2] = localStrings;
        this->tempVals[0] = tempInts;
        this->tempVals[1] = tempFloats;
        this->tempVals[2] = tempStrings;
        this->cteVals[0] = cteInts;
        this->cteVals[1] = cteFloats;
        this->cteVals[2] = cteStrings;
    }

    Function(string item[12]) {
        this->type = stoi(item[0]);
        this->resultAddress = stoi(item[1]);
        this->memoryOffset = stoi(item[2]);
        this->localVals[0] = stoi(item[3]);
        this->localVals[1] = stoi(item[4]);
        this->localVals[2] = stoi(item[5]);
        this->tempVals[0] = stoi(item[6]);
        this->tempVals[1] = stoi(item[7]);
        this->tempVals[2] = stoi(item[8]);
        this->cteVals[0] = stoi(item[9]);
        this->cteVals[1] = stoi(item[10]);
        this->cteVals[2] = stoi(item[11]);
    }
};