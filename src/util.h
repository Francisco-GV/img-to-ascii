//
// Created by frank on 14/08/21.
//

#ifndef IMG_TO_ASCII_UTIL_H
#define IMG_TO_ASCII_UTIL_H

#include <Magick++.h>
#include <iostream>
#include <string>

std::ostream &operator<<(std::ostream &out, const Magick::ColorRGB &color);

namespace util
{
    extern const std::string characters1;
    extern const std::string characters2;
    extern const std::string RESET;
    void exitProgram(const std::string& reason);
    int percentageToRGB(double);
    std::string ansiRGB(int red, int green, int blue);
    std::string ansiRGB(double red, double green, double blue);
    unsigned int calculateNewHeight(unsigned int originalHeight, unsigned int originalWidth, unsigned int newWidth);
}

#endif