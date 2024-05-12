/** Reads the data from a given image and returns the values it read 
 * errNo==1: unable to open file
 * errNo==2: file is not a P3 file
 * errNo==3: unable to read from a line in file
*/

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "ImageData.h"

using namespace std;
ImageData* ReadImage(string name) {
    ifstream file(name);
    if (!file) {
        cout << "Unable to open file " << name << endl;
        exit(1);
    }
    int colour[3], width, height;
    string str;
    int posX, posY;
    // making sure the .ppm image is in P3 form:
    file >> str;
    if (str != "P3") exit(2);
    file >> width >> height;
    ImageData* img = new ImageData(width, height); // Allocate memory dynamically
    file >> str; // tmp reading the value 255
    for (posY = 0; posY < height; posY++) {
        for (posX = 0; posX < width; posX++) {
            if (!(file >> colour[0] >> colour[1] >> colour[2])) {
                cout << "File seems to be corrupted, unable to get data from line: " << posY * width + posX + 3 << endl;
                exit(3);
            }
            img->AddPixel(posX, posY, vec3(colour[0], colour[1], colour[2]));
        }
    }
    file.close();
    return img;
}
