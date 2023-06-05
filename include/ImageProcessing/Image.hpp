#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <cstdio>
#include <stdint.h>
#include "stb_image.h"
#include "stb_image_write.h"
#include "./ImageType.hpp"

/*
The Image struct is the data type for images. It contains the width and height of the image, the amount of channels it has, the size
and the value of each pixel, basically all the relevant data of an image.

It has a bunch of functions that manipulate this data to alter the image, as well as read (open) or write (save) images.
*/
struct Image {
    uint8_t *data = NULL; // Image data (value of each pixel)
    size_t size = 0; // Size of data
    int w; // Width of image
    int h; // Height of image
    int channels; // Number of channels in image

    // Gets data from image file
    Image(string _filename) {
        const char *filename = _filename.c_str();
        if (!read(filename)) {
            cout << "ERROR: Failed to open " << filename << "." << endl;
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

    // Sets each pixel to the average of its three color channels to make it a grayscale image
    Image& grayscale() {
        if (channels >= 3) {
            for (int i = 0; i < size; i += channels) {
                int gray = (data[i] + data[i+1] + data[i+2]) / 3;
                memset(data + i, gray, 3);
            }
        }
        return *this;
    }

    // Sets each pixel to either black or white by comparing its rgb average to a threshold
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

    // Crops the image by creating a new array of data and filling it with only the piece of data indicaated by the parameters.
    Image &crop(uint16_t left, uint16_t bottom, uint16_t width, uint16_t height) {
        size = width * height * channels;
        uint8_t *cropped = new uint8_t[size];
        memset(cropped, 0, size);
        for (uint16_t i = 0; i < height; i++) {
            if (i + bottom >= h) {
                break;
            }
            for (uint16_t j = 0; j < width; j++) {
                if (j + left >= w) {
                    break;
                }
                memcpy(&cropped[(j + i * width) * channels], &data[(j + left + (i + bottom) * w) * channels], channels);
            }
        }
        w = width;
        h = height;
        size = w * h * channels;
        delete[] data;
        data = cropped;
        cropped = nullptr;
        return *this;
    }

    // Flips the image horizontally by placing each pixel in its mirrored horizontal position
    Image &hFlip() {
        uint8_t temp[4];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w / 2; j++) {
                uint8_t *pixel1 = &data[(j + i * w) * channels];
                uint8_t *pixel2 = &data[((w - 1 - j) + i * w) * channels];

                memcpy(temp, pixel1, channels);
                memcpy(pixel1, pixel2, channels);
                memcpy(pixel2, temp, channels);
            }
        }
        return *this;
    }

    // Flips the image horizontally by placing each pixel in its mirrored vertical position
    Image &vFlip() {
        uint8_t temp[4];
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h / 2; j++) {
                uint8_t *pixel1 = &data[(i + j * w) * channels];
                uint8_t *pixel2 = &data[(i + (h - 1 - j) * w) * channels];

                memcpy(temp, pixel1, channels);
                memcpy(pixel1, pixel2, channels);
                memcpy(pixel2, temp, channels);
            }
        }
        return *this;
    }

    // Applies a color obtained from rgb parameters to an image by multiplying each pixel by the corresponding intensity.
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

    // Applies a color obtained from a hex value to an image by multiplying each pixel by the corresponding intensity.
    Image& changeColor(const string hexValue) {
        if (hexValue.size() != 7 || hexValue[0] != '#') {
            return *this;
        }

        int intValue = stoi(hexValue.substr(1), nullptr, 16);

        if (channels >= 3) {
            int r = (intValue >> 16) & 0xFF;
            int g = (intValue >> 8) & 0xFF;
            int b = intValue & 0xFF;

            for (int i = 0; i < size; i += channels) {
                data[i] *= r;
                data[i+1] *= g;
                data[i+2] *= b;
            }
        }
        return *this;
    }

    // Reads the pixel data from an image
    bool read(string _filename) {
        const char *filename = _filename.c_str();
        this->data = stbi_load(filename, &w, &h, &channels, 0);
        return this->data != NULL;
    }

    // Writes the pixel data to an image
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

    // Gets the image type
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