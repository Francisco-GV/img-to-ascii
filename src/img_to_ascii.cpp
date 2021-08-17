//
// Created by frank on 15/08/21.
//

#include <iostream>
#include <memory>
#include <Magick++.h>
#include <string>
#include <iomanip>
#include "util.h"

void prepareImage(Magick::Image &);
std::unique_ptr<Magick::Image> loadImage(const std::string &);
std::string parsePixelsToASCII(const Magick::Image &, unsigned int, unsigned int, size_t, size_t);
unsigned int getAverage(const Magick::Image &, unsigned int, unsigned int, size_t, size_t);

std::string convertImageToASCII(char **argv, const std::string &file, unsigned int columns, double scale, bool debug)
{
    using std::cout;
    using std::endl;

    unsigned int rows;

    Magick::InitializeMagick(*argv);

    std::unique_ptr<Magick::Image> image = loadImage(file);
    size_t width{image->columns()};
    size_t height{image->rows()};

    prepareImage(*image);

    size_t cellWidth{width / columns};
    size_t cellHeight{static_cast<size_t>(cellWidth / scale)};
    //height / rows; // <- warning: this doesn't keep aspect ratio in console/file output

    rows = height / cellHeight;
    //util::calculateNewHeight(height, width, columns); // <- warning: calculate number of rows using cellHeight{height / rows}

    if (debug)
    {
        using std::left, std::setw;
        int n{22};
        cout << setw(n) << left << "file: " << image->fileName() << endl;
        cout << setw(n) << left << "image size: " << width << "x" << height << " pixels" << endl;
        cout << setw(n) << left << "Height scale factor: " << scale << endl;
        cout << setw(n) << left << "Cell size: " << cellWidth << "x" << cellHeight << " pixels" << endl;
        cout << setw(n) << left << "ASCII size: " << columns << "x" << rows << " characters" << endl;
    }

    return parsePixelsToASCII(*image, columns, rows, cellWidth, cellHeight);
}

std::unique_ptr<Magick::Image> loadImage(const std::string &path)
{
    return std::make_unique<Magick::Image>(path);
}

void prepareImage(Magick::Image &image)
{
    image.backgroundColor(Magick::Color("#fff"));
    image.alphaChannel(Magick::RemoveAlphaChannel);
    image.alphaChannel(Magick::OffAlphaChannel);
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

std::string parsePixelsToASCII(const Magick::Image &image, unsigned int columns, unsigned int rows,
                               size_t cellsWidth, size_t cellsHeight)
{
    using util::characters;

    std::string ascii;
    for (unsigned int n{0}; n < rows; n++)
    {
        for (unsigned int i{0}; i < columns; i++)
        {
            unsigned int average{getAverage(image, i, n, cellsWidth, cellsHeight)};

            unsigned int characterIndex = (average * (characters.length() - 1)) / 255;
            ascii += characters.at(characterIndex);
        }
        ascii += "\n";
    }

    return ascii;
}