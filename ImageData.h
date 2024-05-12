/* ImageData, saves the image data */

#ifndef IMAGEDATA_H
#define IMAGEDATA_H

#include <vector>
#include "vec3.h"
#include "Pixel.h"

using namespace std;

class ImageData {
public:
    // setter
    ImageData(int &width1, int &height1);

    // ads a pixel with the colour value given in the position given
    void AddPixel(int _posX, int _posY, vec3 colour);

    //returning the width and height of the image
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    // returns the vector with the image data
    vec3 getPixelColor(int _posY, int _posX);

    void printImage(Simple_window &win);
private:
    // pixel data
    vector<vector<Pixel>> imageData;

    // width and height
    int width;
    int height;
};

// setter
ImageData::ImageData(int &width1, int &height1) {
    width=width1;
    height=height1;
    imageData.resize(height);
    for (int i=0;i<height;i++) imageData[i].resize(width);
}

void ImageData::AddPixel(int _posX, int _posY, vec3 colour) {
    imageData[_posY][_posX] = Pixel(_posX, _posY, colour);
}

void ImageData::printImage(Simple_window &win) {
    const int rectSize = 20; // Size of each rectangle

    for (size_t i = 0; i < imageData.size(); ++i) {
        for (size_t j = 0; j < imageData[i].size(); ++j) {
            const int x = j * rectSize; // Calculate x position
            const int y = i * rectSize; // Calculate y position

            Rectangle *pixel = new Rectangle(Point(x, y), rectSize, rectSize);
            vec3 colour = imageData[i][j].getColour();
            Fl_Color pixCol = fl_rgb_color(colour.x(), colour.y(), colour.z());
            pixel->set_color(pixCol);
            pixel->set_fill_color(pixCol);
            win.attach(*pixel);
        }
    }
}



#endif