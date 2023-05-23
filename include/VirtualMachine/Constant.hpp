#include <iostream>

struct Constant {
    int address;
    string value;

    Constant(string value, int address) {
        this->value = value;
        this->address = address;
    }
};