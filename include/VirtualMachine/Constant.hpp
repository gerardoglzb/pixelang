#include <iostream>

struct Constant {
    int address;
    string value;
    int type;

    Constant(string value, int address, int type) {
        this->value = value;
        this->address = address;
        this->type = type;
    }
};