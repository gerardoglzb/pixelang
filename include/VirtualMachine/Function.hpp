#include <iostream>
using namespace std;

struct Function {
    int type;
    int resultAddress;
    int memoryOffset;
    int startQuad;
    int localVals[4];
    int tempVals[4];
    int cteVals[4];
    int imageVals=3;

    Function(int type, int resultAddress, int memoryOffset, int startQuad, int localInts, int localFloats, int localStrings, int tempInts, int tempFloats, int tempStrings, int cteInts, int cteFloats, int cteStrings) {
        this->type = type;
        this->resultAddress = resultAddress;
        this->memoryOffset = memoryOffset;
        this->startQuad = startQuad;
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
        this->startQuad = stoi(item[3]);
        this->localVals[0] = stoi(item[4]);
        this->localVals[1] = stoi(item[5]);
        this->localVals[2] = stoi(item[6]); 
        this->localVals[3] = stoi(item[7]);
        this->tempVals[0] = stoi(item[8]);
        this->tempVals[1] = stoi(item[9]);
        this->tempVals[2] = stoi(item[10]); 
        this->tempVals[3] = stoi(item[11]);
        this->cteVals[0] = stoi(item[12]);
        this->cteVals[1] = stoi(item[13]);
        this->cteVals[2] = stoi(item[14]);
        this->cteVals[3] = stoi(item[15]);
    }
};