#pragma once

#include "obraz.h"

#include <vector>

class ppm : public obraz
{
public:
    ppm(const char* fileName);
    ~ppm();
    int getWidth() override;
    int getHeight() override;
    color* getColors() override;
private:
    int width = 0, height = 0;
    color* colors = nullptr;
};
