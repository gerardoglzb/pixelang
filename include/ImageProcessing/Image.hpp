#include <iostream>
using namespace std;

struct Image {
    uint8_t *data = NULL;
    size_t size = 0;
    int w;
    int h;
    int channels;

    // Image(string filename) {
    // }

    Image(int w, int h, int channels) {
        this->w = w;
        this->h = h;
        this->channels = channels;

    }

    // bool read(string filename) {

    // }

    // bool write(string filename) {

    // }
};