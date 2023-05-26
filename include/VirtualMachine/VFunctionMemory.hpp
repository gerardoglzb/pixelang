#include <iostream>
#include "./Function.hpp"
#include "./VMemory.hpp"
using namespace std;

struct VFunctionMemory {
    VMemory *localMemory;
    VMemory *tempMemory;
    VMemory *cteMemory;
    VFunctionMemory *globalMemory;
    string name;

    VFunctionMemory(Function *function, int intSize, int floatSize, int stringSize, VFunctionMemory *globalMemory, string name) {
        this->localMemory = new VMemory(function->localVals[0], function->localVals[1], function->localVals[2], function->memoryOffset, 0, intSize, intSize * 2);
        this->tempMemory = new VMemory(function->tempVals[0], function->tempVals[1], function->tempVals[2], function->memoryOffset + intSize * 3, 0, floatSize, floatSize * 2);
        this->cteMemory = new VMemory(function->cteVals[0], function->cteVals[1], function->cteVals[2], function->memoryOffset + intSize * 3 + floatSize * 3, 0, stringSize, stringSize * 2);
        this->globalMemory = globalMemory;
        this->name = name;
    }

    int getType(int address) {
        if (address == -1)
            return -1;
        int intType = localMemory->getType(address);
        intType = (intType == -1) ? tempMemory->getType(address) : intType;
        intType = (intType == -1) ? cteMemory->getType(address) : intType;
        intType = (intType == -1) ? globalMemory->localMemory->getType(address) : intType;
        intType = (intType == -1) ? globalMemory->tempMemory->getType(address) : intType;
        intType = (intType == -1) ? globalMemory->cteMemory->getType(address) : intType;
        return intType;
    }

    template<typename T>
    void setValue(int address, T value) {
        getVMemory(address)->setValue(address, value);
    }

    VMemory *getVMemory(int address) {
        if (address < 24000) {
            if (globalMemory)
                return globalMemory->getVMemory(address);
            if (address < 6000)
                return localMemory;
            if (address < 18000)
                return tempMemory;
            if (address < 24000)
                return cteMemory;
        }
        if (address < 27000)
            return localMemory;
        if (address < 36000)
            return tempMemory;
        if (address < 39000)
            return cteMemory;
        cout << "Memory error " << endl;
        exit(-1); // TODO: mejorar error messages
        return nullptr;
    }
};