#include <iostream>
#include "./VMemoryFrame.hpp"
#include "../ImageProcessing/Image.hpp"
using namespace std;

/*
This struct contains five VMemoryFrame instances, each representing a memory space containing values of each type: integer, float,
string, Boolean or Image. Unlike the Memory instance, these ones actually always contain the real values.

This struct has methods for getting and setting values of any given address.
*/
struct VMemory {
    VMemoryFrame<int> *memoryInt; // Memory frame for integers for integers
    VMemoryFrame<float> *memoryFloat; // Memory frame for floats
    VMemoryFrame<string> *memoryString; // Memory frame for strings
    VMemoryFrame<bool> *memoryBool; // Memory frame for Booleans
    VMemoryFrame<Image*> *memoryImage; // Memory frame for Images

    VMemory(int intSize, int floatSize, int stringSize, int boolSize, int imageSize, int intOffset, int floatOffset, int stringOffset, int boolOffset, int imageOffset) {
        this->memoryInt = new VMemoryFrame<int>(intSize, intOffset, INT_);
        this->memoryFloat = new VMemoryFrame<float>(floatSize, floatOffset, FLOAT_);
        this->memoryString = new VMemoryFrame<string>(stringSize, stringOffset, STRING_);
        this->memoryBool = new VMemoryFrame<bool>(boolSize, boolOffset, BOOL_);
        this->memoryImage = new VMemoryFrame<Image*>(imageSize, imageOffset, IMAGE_);
    }

    // Gets type of address by attempting to get the type from all frames
    int getType(int address) {
        int intType = memoryInt->getType(address);
        intType = (intType == -1) ? memoryFloat->getType(address) : intType;
        intType = (intType == -1) ? memoryString->getType(address) : intType;
        intType = (intType == -1) ? memoryBool->getType(address) : intType;
        intType = (intType == -1) ? memoryImage->getType(address) : intType;
        return intType;
    }

    // Sets value of corresponding address to value of type integer
    void setValue(int idx, int value) {
        if (this->memoryInt->setValue(idx, value) == -1) {
            this->memoryBool->setValue(idx, value);
        }
    }

    // Sets value of corresponding address to value of type float
    void setValue(int idx, float value) {
        this->memoryFloat->setValue(idx, value);
    }

    // Sets value of corresponding address to value of type string
    void setValue(int idx, string value) {
        this->memoryString->setValue(idx, value);
    }

    // Sets value of corresponding address to value of type Image
    void setValue(int idx, Image *value) {
        this->memoryImage->setValue(idx, value);
    }

    // Gets value of corresponding address, which is of type integer
    int getValueInt(int idx) {
        return this->memoryInt->getValue(idx);
    }

    // Gets value of corresponding address, which is of type float
    float getValueFloat(int idx) {
        return this->memoryFloat->getValue(idx);
    }

    // Gets value of corresponding address, which is of type string
    string getValueString(int idx) {
        return this->memoryString->getValue(idx);
    }

    // Gets value of corresponding address, which is of type Boolean
    bool getValueBool(int idx) {
        return this->memoryBool->getValue(idx);
    }

    // Gets value of corresponding address, which is of type Image
    Image *getValueImage(int idx) {
        return this->memoryImage->getValue(idx);
    }
};