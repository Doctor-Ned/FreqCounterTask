#include "ppm.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

ppm::ppm(const char* fileName)
{
    std::ifstream ifs(fileName);
    if (!ifs.is_open())
    {
        throw std::exception("Unable to open the file");
    }
    bool checkedType = false;
    int maxValue = 0;
    std::string line;
    int colorPos = 0;
    while (std::getline(ifs, line))
    {
        if (!line.empty() && line[0] != '#')
        {
            if (checkedType)
            {
                std::stringstream ss(line);
                if (!width || !height || !maxValue)
                {
                    do
                    {
                        int read;
                        ss >> read;
                        if (!width)
                        {
                            width = read;
                        } else if (!height)
                        {
                            height = read;
                            colors = new color[width * height];
                        } else if (!maxValue)
                        {
                            maxValue = read;
                        }
                    } while (!ss.eof());
                } else
                {
                    do
                    {
                        int r, g, b;
                        ss >> r >> g >> b;
                        colors[colorPos] = color{
                            static_cast<unsigned char>(r),
                            static_cast<unsigned char>(g),
                            static_cast<unsigned char>(b)
                        };
                        ++colorPos;
                    } while (ss.rdbuf()->in_avail() > 1);
                }
            } else
            {
                checkedType = true;
                if (line != "P3")
                {
                    throw std::exception("Invalid PPM format");
                }
            }
        }
    }
}

ppm::~ppm()
{
    delete[] colors;
}

int ppm::getWidth()
{
    return width;
}

int ppm::getHeight()
{
    return height;
}

color* ppm::getColors()
{
    return colors;
}