//
// Created by frank on 14/08/21.
//
#include <iostream>
#include <string>
#include <Magick++.h>
#include "util.h"

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **args)
{
    try
    {
        Magick::InitializeMagick(*args);
        Magick::Image image("/home/frank/Pictures/image24x24.png");

        size_t width{image.columns()};
        size_t height{image.rows()};

        for (ssize_t y{0}; y < height; y++)
        {
            for (ssize_t x{0}; x < width; x++)
            {
                Magick::ColorRGB rgb(image.pixelColor(x, y));

                std::string color = util::ansiRGB(rgb.red(), rgb.green(), rgb.blue());
                cout << color << " ";
            }
            cout << util::RESET << "\n";
        }
        cout << util::RESET << endl;
    }
    catch (Magick::Exception &error)
    {
        cerr << "Caught Magick++ exception: " << error.what() << endl;
    }
}