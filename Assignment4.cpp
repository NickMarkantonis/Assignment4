
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

// The NOGDI below is needed to prevent Windows from including wingdi.h which has a duplicate
// declaration of 'Polygon' and throws ambiguous error.
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define NOGDI
#endif

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
#include "ReadImage.h"


int main() {
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib
    
    // reading which file to choose
    cout << "Give image name, please make sure that is in the folder build/Degub! (No need to add the .ppm extension)" << endl;
    string name;
    cin >> name;
    name+=".ppm";

    // reading from the file
    ImageData *img=ReadImage(name);

    // creating the window
    Point t1(100,100);
    
    int width=img->getWidth();
    int height=img->getHeight();
    Simple_window win(t1,width*20+70,height*20,name);
    // adding the pixels to the window
    img->printImage(win);

    win.wait_for_button();
}
