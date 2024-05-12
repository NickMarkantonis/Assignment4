#ifndef PIXEL_H
#define PIXEL_H

#include <vec3.h>

using namespace std;

// class pixel, represents a pixel in the final image
class Pixel {
public:
    Pixel() : posX(0), posY(0), colour(vec3(0,0,0)) {}
    // setter
    Pixel(int _posY, int _posX, vec3 _colour);

    // returning the adequate values from the image
    int getPosX() const { return posX; }
    int getPosY() const { return posY; }
    vec3 getColour() const { return colour; }
private:
    int posX;
    int posY;
    vec3 colour;
};

// setter
Pixel::Pixel(int _posY, int _posX, vec3 _colour) {
    posX=_posX;
    posY=_posY;
    colour=_colour;
}

#endif
