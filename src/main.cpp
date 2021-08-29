//
// Created by frank on 14/08/21.
//
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>      // for strtol and strtod
#include <unistd.h>     // for getopt
#include <exception>
#include "util.h"

using std::cout;
using std::cerr;
using std::endl;

std::string convertImageToASCII(char **argv, const std::string &file,
                                unsigned int columns, double scale,
                                bool moreCharacters, bool debug);

int main(int argc, char **argv)
{
    bool debug{false};
    bool outputInFile{false};
    bool viewInStandardOutput{false};
    bool moreCharacters{false};

    unsigned int columns{80};
    double scale{0.43};

    std::string path;

    int opt;
    while ((opt = getopt(argc, argv, ":dvmc:s:o:")) != -1)
    {
        switch (opt)
        {
            case 'c':
            {
                char *endptr;
                long value{std::strtol(optarg, &endptr, 10)};

                if (!endptr || value < 0)
                    util::exitProgram("-c (columns) must be an positive "
                                      "integer number");
                else columns = value;
            } break;

            case 's':
            {
                char *endptr;
                double value{std::strtod(optarg, &endptr)};

                if (!endptr || value < 0)
                    util::exitProgram("-s (height scale) must be an positive "
                                      "floating point number");
                else scale = value;
            } break;

            case '?':
                cerr << "invalid option: " << optopt << endl;
                break;

            case ':':
                if (optopt == 'o')
                    cout << "Argument missing for 'o'" << endl;
                break;

            case 'd':   debug = true;                       break;
            case 'v':   viewInStandardOutput = true;        break;
            case 'm':   moreCharacters = true;              break;
            case 'o':   outputInFile = true; path = optarg; break;
            default :   break;
        }
    }

    std::string file;

    if (optind < argc)
        file = argv[optind];

    try
    {
        std::string ascii = convertImageToASCII(argv, file, columns, scale,
                                                moreCharacters, debug);
        if (debug)
        {
            if (outputInFile)
                cout << std::setw(22) << std::left << "output to: " << path << endl;
            cout << endl;
        }

        if (outputInFile)
        {
            std::ofstream outputFile;
            outputFile.open(path, std::ios::out);
            outputFile << ascii;
            outputFile.close();
        }

        if (!outputInFile || viewInStandardOutput)
            cout << ascii << endl;
    }
    catch (std::exception &error)
    {
        cerr << "Something went wrong:\n\t" << error.what() << endl;
    }
}