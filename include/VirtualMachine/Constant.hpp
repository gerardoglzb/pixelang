#include <iostream>

/*
Used to store the type, address and value of constants after they're read from the object file.
*/
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