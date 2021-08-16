//
// Created by frank on 14/08/21.
//

#include <iostream>
#include <string>
#include <Magick++.h>
#include <cmath>
#include "util.h"

std::ostream &operator<<(std::ostream &out, const Magick::ColorRGB &color)
{
    out << "rgb(" << color.red() << ", "
        << color.green() << ", "
        << color.blue() << ")";
    return out;
}

namespace util
{
    // 70 levels of gray
    inline const std::string characters1{R"($@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~i!lI;:,"^`". )"};
    // 10 levels of gray
    inline const std::string characters2{"@%#*+=-:. "};
    inline const std::string RESET{"\033[m"};

    int percentageToRGB(double value)
    {   // If 1.0 is 255 then x = y * 255 / 1
        return static_cast<int>(std::round(value * 255));
    }

    std::string ansiRGB(double red, double green, double blue)
    {
        int r{percentageToRGB(red)};
        int g{percentageToRGB(green)};
        int b{percentageToRGB(blue)};
        return ansiRGB(r, g, b);
    }

    std::string ansiRGB(int red, int green, int blue)
    {
        return "\033[48;2;" + std::to_string(red) + ";"
               + std::to_string(green) + ";"
               + std::to_string(blue) + "m";
    }

    unsigned int calculateNewHeight(unsigned int originalHeight, unsigned int originalWidth, unsigned int newWidth)
    {
        return static_cast<unsigned int>(std::round(originalHeight / originalWidth)) * newWidth;
    }
}