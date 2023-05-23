#include <iostream>
using namespace std;

template<typename T>
struct MemoryFrame {
    int size;
    int index;
    int offset;
    vector<T> values;

    MemoryFrame(int size, int offset) {
        this->size = size;
        this->index = 0;
        this->offset = offset;
    }

    int addValue() {
        int temp = index;
        index++;
        return temp + offset;
    }

    int addValue(T val) {
        if (index != values.size()) {
            cout << "Memory frame inconsistent."  << endl;
            exit(-1);
        }
        printf("frame adn\n");
        values.push_back(val);
        return this->addValue();
    }
};