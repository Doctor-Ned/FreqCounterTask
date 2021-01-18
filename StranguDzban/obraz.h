#pragma once
#include <ostream>

struct color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    bool operator==(const color& other) const
    {
        return r == other.r && g == other.g && b == other.b;
    }
    bool operator!=(const color& other) const
    {
        return r != other.r || g != other.g || b != other.b;
    }
    bool operator>(const color& other) const
    {
        if (r != other.r)
        {
            return r > other.r;
        }
        if (g != other.g)
        {
            return g > other.g;
        }
        if (b != other.b)
        {
            return b > other.b;
        }
        return false;
    }
    bool operator<(const color& other) const
    {
        if (r != other.r)
        {
            return r < other.r;
        }
        if (g != other.g)
        {
            return g < other.g;
        }
        if (b != other.b)
        {
            return b < other.b;
        }
        return false;
    }
    friend std::ostream& operator<<(std::ostream& os, const color& color)
    {
        os << +color.r << ',' << +color.g << ',' << +color.b;
        return os;
    }
};

class obraz
{
public:
    virtual ~obraz() = default;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
    virtual color* getColors() = 0;
};