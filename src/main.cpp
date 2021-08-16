//
// Created by frank on 14/08/21.
//
#include <iostream>
#include <string>
#include <Magick++.h>
#include <memory>
#include "util.h"

using std::cout;
using std::cerr;
using std::endl;

void init(char**);
std::unique_ptr<Magick::Image> loadImage(const std::string &path);
void ImagetoGrayscale(Magick::Image &image);
std::string convertImageToASCII(const Magick::Image &image, unsigned int columns, unsigned int rows,
                                size_t cellsWidth, size_t cellsHeight);

int main(int argc, char **args)
{
    // Number of tiles in the output
    unsigned int columns{30};
    unsigned int rows{};

    try
    {
        init(args);

        std::unique_ptr<Magick::Image> image = loadImage(args[1]);
        size_t width{image->columns()};
        size_t height{image->rows()};

        cout << "Image: " << image->fileName() << endl;
        cout << "image original size:" << width << "x" << height << endl;

        ImagetoGrayscale(*image);
        rows = util::calculateNewHeight(height, width, columns);

        cout << "Columns: " << columns << endl;
        cout << "Rows: " << rows << endl;

        size_t cellsWidth{width / columns};
        size_t cellsHeight{height / rows};

        cout << "Tile width: " << cellsWidth << endl;
        cout << "Tile height: " << cellsHeight << endl;

        std::string ascii = convertImageToASCII(*image, columns, rows, cellsWidth, cellsHeight);

        cout << ascii << endl;
    }
    catch (Magick::Exception &error)
    {
        cerr << "Caught Magick++ exception: " << error.what() << endl;
    }
}