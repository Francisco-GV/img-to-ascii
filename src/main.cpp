//
// Created by frank on 14/08/21.
//
#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <Magick++.h>
#include "util.h"

using std::cout;
using std::cerr;
using std::endl;

std::string convertImageToASCII(char **argv, const std::string &file, unsigned int columns, double scale, bool debug);

int main(int argc, char **argv)
{
    bool debug{false};
    // Number of tiles in the output
    unsigned int columns{80};
    unsigned int rows{};

    double scale{0.43};

    int opt;
    while ((opt = getopt(argc, argv, ":dc:s:")) != -1)
    {
        switch (opt)
        {
            case 'd': debug = true; break;
            case 'c':
            {
                char *endptr;
                long value{std::strtol(optarg, &endptr, 10)};

                if (!endptr || value < 0)
                    util::exitProgram("-c (columns) must be an positive integer number");
                else columns = value;
            } break;
            case 's':
            {
                char *endptr;
                double value{std::strtod(optarg, &endptr)};

                if (!endptr || value < 0)
                    util::exitProgram("-s (height scale) must be an positive floating point number");
                else scale = value;
            } break;

            case '?': cerr << "invalid option: " << optopt << endl; break;
            case ':': default: break;
        }
    }

    std::string file;

    if (optind < argc)
    {
        file = argv[optind];
    }

    try
    {
        std::string ascii = convertImageToASCII(argv, file, columns, scale, debug);
        if (debug) cout << "showing output..." << endl;
        cout << ascii << endl;
    }
    catch (Magick::Exception &error)
    {
        cerr << "Caught Magick++ exception:\n\t" << error.what() << endl;
    }
}