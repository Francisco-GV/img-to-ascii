//
// Created by frank on 15/08/21.
//

#include <memory>
#include <Magick++.h>
#include <string>

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

double getAverage(const Magick::Image &image, const MagickCore::Quantum &quantum)
{
    image.channels();
}