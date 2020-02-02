#include "helper.h"

float Helper::functionOutput(float x1, float x2)
{
    return 21.5 + x1 * sin(4*M_PI*x1) + x2 * sin(20*M_PI*x2);
}

float Helper::randomX1()
{
    return (X1_MAX - X1_MIN) * ( (float)rand() / (float) RAND_MAX) + X1_MIN;
}

float Helper::randomX2()
{
    return (X2_MAX - X2_MIN) * ( (float)rand() / (float) RAND_MAX) + X2_MIN;
}