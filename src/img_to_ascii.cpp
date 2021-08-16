//
// Created by frank on 15/08/21.
//

#include <memory>
#include <Magick++.h>
#include <string>
#include "util.h"

void init(char **args)
{
    Magick::InitializeMagick(*args);
}

std::unique_ptr<Magick::Image> loadImage(const std::string &path)
{
    return std::make_unique<Magick::Image>(path);
}

void ImagetoGrayscale(Magick::Image &image)
{
    image.type(Magick::GrayscaleType);
}

unsigned int getAverage(const Magick::Image &image, unsigned int columnNumber, unsigned int rowNumber,
                  size_t cellsWidth, size_t cellsHeight)
{
    int total{};
    int count{};
    for (size_t y{0}; y < cellsHeight; y++)
    {
        for (ssize_t x{0}; x < cellsWidth; x++)
        {
            Magick::ColorGray color{image.pixelColor(ssize_t(columnNumber * cellsWidth + x),
                                                 ssize_t(rowNumber * cellsHeight + y))};

            total += util::percentageToRGB(color.shade());
            count++;
        }
    }

    return static_cast<int>(std::round(total / count));
}

std::string convertImageToASCII(const Magick::Image &image, unsigned int columns, unsigned int rows,
                         size_t cellsWidth, size_t cellsHeight)
{
    using util::characters;

    std::string ascii;
    for (unsigned int n{0}; n < rows; n++)
    {
        for (unsigned int i{0}; i < columns; i++)
        {
            unsigned int average{getAverage(image, i, n, cellsWidth, cellsHeight)};

            unsigned int characterIndex = (average * (characters.length())) / 255;
            ascii += characters.at(characterIndex - 1);
        }
        ascii += "\n";
    }

    return ascii;
}