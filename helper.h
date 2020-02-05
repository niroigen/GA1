#ifndef HELPER_H
#define HELPER_H

#include <cmath>
#include <stdlib.h>
#include <iostream>

class Helper {
public:
    constexpr static float X1_MIN = -12;
    constexpr static float X1_MAX = 12;
    constexpr static float X2_MIN = -6;
    constexpr static float X2_MAX = 6;

    static float functionOutput(float x1, float x2);

    static float randomX1();

    static float randomX2();
};

#endif