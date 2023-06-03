#include <iostream>
#include "../Semantics/Type.hpp"
using namespace std;

/*
This struct represents a memory frame of a specific type T. It contains the offset and size of the frame to make sure the address of
the value exists in this specific frame. It can also return the type of it.

Finally, it contains a pointer to "frame", which is initialized with the real size of the frame so that instead of having a frame that's
the full size, it only has to be the minimum size necessary for the program to work.
*/
template<typename T>
struct VMemoryFrame {
    int offset;
    int size;
    T *frame;
    int type;

    VMemoryFrame(int size, int offset, int type) {
        this->offset = offset;
        this->size = size;
        this->type = type;
        this->frame = new T[size];
    }

    int setValue(int idx, T value) {
        if (offset > idx || (idx - offset) >= size)
            return -1;
        frame[idx - offset] = value;
        return (idx - offset);
    }

    T getValue(int idx) {
        return frame[idx - offset];
    }

    int getType(int address) {
        if (address >= offset && address < offset + size) {
            return type;
        }
        return -1;
    }
};