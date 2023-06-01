#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <cstdio>
#include <stdint.h>
#include "stb_image.h"
#include "stb_image_write.h"
#include "./ImageType.hpp"

struct Image {
    uint8_t *data = NULL;
    size_t size = 0;
    int w;
    int h;
    int channels;

    Image(string _filename) {
        const char *filename = _filename.c_str();
        if (!read(filename)) {
            cout << "Failed to open " << filename << endl;
            exit(-1);
        }
        this->size = w * h * channels;
    }

    Image(int w, int h, int channels) {
        this->w = w;
        this->h = h;
        this->channels = channels;
        this->size = w * h * channels;
        this->data = new uint8_t[this->size];
    }

    Image& grayscale() {
        if (channels >= 3) {
            for (int i = 0; i < size; i += channels) {
                int gray = (data[i] + data[i+1] + data[i+2]) / 3;
                memset(data + i, gray, 3);
            }
        }
        return *this;
    }

    Image& blackAndWhite() {
        if (channels >= 3) {
            for (int i = 0; i < size; i += channels) {
                int avg = (data[i] + data[i+1] + data[i+2]) / 3;
                int blackOrWhite = (avg < 128) ? 0 : 255;
                memset(data + i, blackOrWhite, 3);
            }
        }
        return *this;
    }

    Image &changeColor(float r, float g, float b) {
        if (channels >= 3) {
            for (int i = 0; i < size; i += channels) {
                data[i] *= r;
                data[i+1] *= g;
                data[i+2] *= b;
            }
        }
        return *this;
    }

    bool read(string _filename) {
        const char *filename = _filename.c_str();
        this->data = stbi_load(filename, &w, &h, &channels, 0);
        return this->data != NULL;
    }

    bool write(string _filename) {
        const char *filename = _filename.c_str();
        ImageType type = getImageType(filename);
        int response;
        switch(type) {
            case PNG_:
                response = stbi_write_png(filename, w, h, channels, data, w * channels);
                break;
            case JPG_:
                response = stbi_write_jpg(filename, w, h, channels, data, 100);
        }
        return response != 0;
    }

    ImageType getImageType(const char *filename) {
        const char *ext = strrchr(filename, '.');
        if (ext != nullptr) {
            if (strcmp(ext, ".jpg") == 0)
                return JPG_;
        }
        return PNG_;
    }

    ~Image() {
        stbi_image_free(data);
    }
};