#include <iostream>
#include "./Function.hpp"
#include "./VMemory.hpp"
#include "../Memory/MemoryAddresses.hpp"
using namespace std;

struct VFunctionMemory {
    VMemory *localMemory;
    VMemory *tempMemory;
    VMemory *cteMemory;
    VFunctionMemory *globalMemory;
    string name;

    VFunctionMemory(Function *function, VFunctionMemory *globalMemory) {
        this->localMemory = new VMemory(function->localVals[0], function->localVals[1], function->localVals[2], function->localVals[3], function->imageVals, LOCAL_INT, LOCAL_FLOAT, LOCAL_STRING, LOCAL_BOOL, LOCAL_IMAGE);
        this->tempMemory = new VMemory(function->tempVals[0], function->tempVals[1], function->tempVals[2], function->tempVals[3], function->imageVals, LOCAL_TEMP_INT, LOCAL_TEMP_FLOAT, LOCAL_TEMP_STRING, LOCAL_TEMP_BOOL, LOCAL_IMAGE);
        this->cteMemory = new VMemory(function->cteVals[0], function->cteVals[1], function->cteVals[2], function->cteVals[3], function->imageVals, LOCAL_CTE_INT, LOCAL_CTE_FLOAT, LOCAL_CTE_STRING, LOCAL_CTE_BOOL, LOCAL_IMAGE);
        this->globalMemory = globalMemory;
        this->name = "func";
    }

    VFunctionMemory(Function *function, VFunctionMemory *globalMemory, string name) {
        this->localMemory = new VMemory(function->localVals[0], function->localVals[1], function->localVals[2], function->localVals[3], function->imageVals, GLOBAL_INT, GLOBAL_FLOAT, GLOBAL_STRING, GLOBAL_BOOL, LOCAL_IMAGE);
        this->tempMemory = new VMemory(function->tempVals[0], function->tempVals[1], function->tempVals[2], function->tempVals[3], function->imageVals, GLOBAL_TEMP_INT, GLOBAL_TEMP_FLOAT, GLOBAL_TEMP_STRING, GLOBAL_TEMP_BOOL, LOCAL_IMAGE);
        this->cteMemory = new VMemory(function->cteVals[0], function->cteVals[1], function->cteVals[2], function->cteVals[3], function->imageVals, GLOBAL_CTE_INT, GLOBAL_CTE_FLOAT, GLOBAL_CTE_STRING, GLOBAL_CTE_BOOL, LOCAL_IMAGE);
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
        if (address < LOCAL_INT) {
            if (globalMemory)
                return globalMemory->getVMemory(address);
            if (address < GLOBAL_TEMP_INT)
                return localMemory;
            if (address < GLOBAL_CTE_INT)
                return tempMemory;
            return cteMemory;
        }
        if (address < LOCAL_TEMP_INT)
            return localMemory;
        if (address < LOCAL_CTE_INT)
            return tempMemory;
        if (address < END_MEMORY)
            return cteMemory;
        cout << "Memory error " << endl;
        exit(-1); // TODO: mejorar error messages
        return nullptr;
    }
};