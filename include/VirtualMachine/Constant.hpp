#include <iostream>

template<typename T>
struct Constant {
    int address;
    T value;

    Constant(T value, int address) {
        this->value = value;
        this->address = address;
    }
};