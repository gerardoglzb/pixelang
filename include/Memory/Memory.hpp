#include <iostream>
#include "./MemoryFrame.hpp"

/*
This struct represents a memory space that contains pointers to MemoryFrame instances of all types: int, float, string, bool and image.
Image has a boolean type because there is no need to actually store any images on the compiler because Images can't be constants.

The most relevant method of this struct is "addValue", which "adds" a value of whatever type is indicated to the corresponding
MemoryFrame. In reality, it's increasing the index of the frame and returning the address for this value. This method can optionally
received a real value, in which case it'll  be stored properly. This is designed for constant values.
*/
struct Memory {
    MemoryFrame<int> *memoryInt; // Memory frame for integers
    MemoryFrame<float> *memoryFloat; // Memory frame for floats
    MemoryFrame<string> *memoryString; // Memory frame for strings
    MemoryFrame<bool> *memoryBool; // Memory frame for Booleans
    MemoryFrame<bool> *memoryImage; // Memory frame for images

    // Returns current size of integer memory frame
    int getSizeInt() {
        return memoryInt->index;
    }

    // Returns current size of float memory frame
    int getSizeFloat() {
        return memoryFloat->index;
    }

    // Returns current size of string memory frame
    int getSizeString() {
        return memoryString->index;
    }

    // Returns current size of Boolean memory frame
    int getSizeBool() {
        return memoryBool->index;
    }

    // Returns current size of image memory frame
    int getSizeImage() {
        return memoryImage->index;
    }

    Memory(int offset) {
        this->memoryInt = new MemoryFrame<int>(offset, getMemorySize(offset));
        this->memoryFloat = new MemoryFrame<float>(offset + getMemorySize(offset), getMemorySize(offset));
        this->memoryString = new MemoryFrame<string>(offset + getMemorySize(offset) * 2, getMemorySize(offset));
        this->memoryBool = new MemoryFrame<bool>(offset + getMemorySize(offset) * 3, getMemorySize(offset));
        this->memoryImage = new MemoryFrame<bool>(offset == GLOBAL_INT ? GLOBAL_IMAGE : LOCAL_IMAGE, getMemorySize(offset == GLOBAL_INT ? GLOBAL_IMAGE : LOCAL_IMAGE));
    }

    // Used to reserve addresses for arrays
    int addValues(int type, int amount) {
        int address = addValue(type);
        for (int i = 1; i < amount; i++) {
            addValue(type);
        }
        return address;
    }

    // Reserves and returns an address in the correct memory space for a certain type
    int addValue(int type) {
        if (type == INT_) {
            return memoryInt->addValue();
        }
        if (type == FLOAT_) {
            return memoryFloat->addValue();
        }
        if (type == STRING_) {
            return memoryString->addValue();
        }
        if (type == BOOL_) {
            return memoryBool->addValue();
        }
        if (type == IMAGE_) {
            return memoryImage->addValue();
        }
        cout << "ERROR (Internal): Memory assignment error!" << endl;
        exit(-1);
        return -1;
    }

    // Stores a value in and returns an address in the correct memory space for an integer, used only for constants
    int addValue(int type, int value) {
        if (type == INT_)
            return memoryInt->addValue(value);
        return memoryBool->addValue(value);
    }

    // Stores a value in and returns an address in the correct memory space for a float, used only for constants
    int addValue(int type, float value) {
        return memoryFloat->addValue(value);
    }

    // Stores a value in and returns an address in the correct memory space for a string, used only for constants
    int addValue(int type, string value) {
        return memoryString->addValue(value);
    }

    // Returns size of a specific memory frame
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
            return GLOBAL_IMAGE - GLOBAL_CTE_BOOL;
        if (frame == GLOBAL_IMAGE)
            return LOCAL_INT - GLOBAL_IMAGE;


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
            return LOCAL_IMAGE - LOCAL_CTE_BOOL;
        if (frame == LOCAL_IMAGE)
            return END_MEMORY - LOCAL_IMAGE;
        cout << "ERROR (Internal): Memory address error for frame " << frame << endl;
        exit(-1);
        return -1;
    }
};