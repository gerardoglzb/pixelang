#include <iostream>
#include "./MemoryFrame.hpp"

struct Memory {
    MemoryFrame<int> *memoryInt;
    MemoryFrame<float> *memoryFloat;
    MemoryFrame<string> *memoryString;
    MemoryFrame<bool> *memoryBool;

    int getSizeInt() {
        return memoryInt->index;
    }

    int getSizeFloat() {
        return memoryFloat->index;
    }

    int getSizeString() {
        return memoryString->index;
    }

    Memory(int offset) {
        this->memoryInt = new MemoryFrame<int>(offset);
        this->memoryFloat = new MemoryFrame<float>(offset + getMemorySize(offset));
        this->memoryString = new MemoryFrame<string>(offset + getMemorySize(offset) * 2);
        this->memoryBool = new MemoryFrame<bool>(offset + getMemorySize(offset) * 3);
    }

    int addValues(int type, int amount) {
        int address = addValue(type);
        for (int i = 1; i < amount; i++) {
            addValue(type);
        }
        return address;
    }

    int addValue(int type) {
        if (type == INT_) {
            return memoryInt->addValue();
        }
        if (type == FLOAT_) {
            return memoryFloat->addValue();
        }
        if (type == STRING_) {
            return memoryFloat->addValue();
        }
        return -1;
    }

    int addValue(int type, int value) {
        return memoryInt->addValue(value);
    }

    int addValue(int type, float value) {
        return memoryFloat->addValue(value);
    }

    int addValue(int type, string value) {
        return memoryString->addValue(value);
    }

    int getMemorySize(int frame) {
        if (frame == GLOBAL_INT)
            return GLOBAL_FLOAT - GLOBAL_INT;
        if (frame == GLOBAL_FLOAT)
            return GLOBAL_STRING - GLOBAL_FLOAT;
        if (frame == GLOBAL_STRING)
            return GLOBAL_BOOL - GLOBAL_STRING;
        if (frame == GLOBAL_BOOL)
            return GLOBAL_TEMP_INT - GLOBAL_BOOL;

        if (frame == GLOBAL_TEMP_INT)
            return GLOBAL_TEMP_FLOAT - GLOBAL_TEMP_INT;
        if (frame == GLOBAL_TEMP_FLOAT)
            return GLOBAL_TEMP_STRING - GLOBAL_TEMP_FLOAT;
        if (frame == GLOBAL_TEMP_STRING)
            return GLOBAL_TEMP_BOOL - GLOBAL_TEMP_STRING;
        if (frame == GLOBAL_TEMP_BOOL)
            return GLOBAL_CTE_INT - GLOBAL_TEMP_BOOL;

        if (frame == GLOBAL_CTE_INT)
            return GLOBAL_CTE_FLOAT - GLOBAL_CTE_INT;
        if (frame == GLOBAL_CTE_FLOAT)
            return GLOBAL_CTE_STRING - GLOBAL_CTE_FLOAT;
        if (frame == GLOBAL_CTE_STRING)
            return GLOBAL_CTE_BOOL - GLOBAL_CTE_STRING;
        if (frame == GLOBAL_CTE_BOOL)
            return LOCAL_INT - GLOBAL_CTE_BOOL;


        if (frame == LOCAL_INT)
            return LOCAL_FLOAT - LOCAL_INT;
        if (frame == LOCAL_FLOAT)
            return LOCAL_STRING - LOCAL_FLOAT;
        if (frame == LOCAL_STRING)
            return LOCAL_BOOL - LOCAL_STRING;
        if (frame == LOCAL_BOOL)
            return LOCAL_TEMP_INT - LOCAL_BOOL;

        if (frame == LOCAL_TEMP_INT)
            return LOCAL_TEMP_FLOAT - LOCAL_TEMP_INT;
        if (frame == LOCAL_TEMP_FLOAT)
            return LOCAL_TEMP_STRING - LOCAL_TEMP_FLOAT;
        if (frame == LOCAL_TEMP_STRING)
            return LOCAL_TEMP_BOOL - LOCAL_TEMP_STRING;
        if (frame == LOCAL_TEMP_BOOL)
            return LOCAL_CTE_INT - LOCAL_TEMP_BOOL;

        if (frame == LOCAL_CTE_INT)
            return LOCAL_CTE_FLOAT - LOCAL_CTE_INT;
        if (frame == LOCAL_CTE_FLOAT)
            return LOCAL_CTE_STRING - LOCAL_CTE_FLOAT;
        if (frame == LOCAL_CTE_STRING)
            return LOCAL_CTE_BOOL - LOCAL_CTE_STRING;
        if (frame == LOCAL_CTE_BOOL)
            return END - LOCAL_CTE_BOOL;
        cout << "Memory address error" << endl;
        exit(-1);
        return -1;
    }
};