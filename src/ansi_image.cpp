//
// Created by frank on 15/08/21.
//

#include <Magick++.h>
#include "util.h"

[[maybe_unused]] int imageToANSIColor(const Magick::Image &image)
{
    size_t width{image->columns()};
    size_t height{image->rows()};

    for (ssize_t y{0}; y < height; y++)
    {
        for (ssize_t x{0}; x < width; x++)
        {
            Magick::ColorRGB rgb(image->pixelColor(x, y));

            std::string color = util::ansiRGB(rgb.red(), rgb.green(), rgb.blue());
            cout << color << "   ";
        }
        cout << util::RESET << "\n";
    }
    cout << util::RESET << endl;
}