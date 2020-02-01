#ifndef HELPER_H
#define HELPER_H

#include <cmath>
#include <stdlib.h>
#include <iostream>

const float X1_MIN = -12;
const float X1_MAX = 12;
const float X2_MIN = -6;
const float X2_MAX = 6;

class Helper
{
    public:
    static float function_output(float x1, float x2);
    static float random_x1();
    static float random_x2();
};

#endif