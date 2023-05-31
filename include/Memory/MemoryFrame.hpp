#include <iostream>
#include "./MemoryAddresses.hpp"
using namespace std;

template<typename T>
struct MemoryFrame {
    int size;
    int index;
    int offset;
    vector<T> values;

    MemoryFrame(int offset) {
        this->size = getMemorySize(offset);
        this->index = 0;
        this->offset = offset;
    }

    void verifyEnoughSize() {
        if (index >= size) {
            cout << "Segmentation fault." << endl;
            exit(-1);
        }
    }

    int addValue() {
        verifyEnoughSize();
        int temp = index;
        index++;
        return temp + offset;
    }

    int addValue(T val) {
        if (index != values.size()) {
            cout << "Memory frame inconsistent."  << endl;
            exit(-1);
        }
        verifyEnoughSize();
        values.push_back(val);
        return this->addValue();
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
            return END_MEMORY - LOCAL_CTE_BOOL;
        cout << "Memory address error" << endl;
        exit(-1);
        return -1;
    }
};