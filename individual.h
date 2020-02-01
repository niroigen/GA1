#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "helper.h"

class Individual
{
private:
    float x1; // -12.0 to 12.0
    float x2; // -6.0 to 6.0
    float percent_of_being_chosen;
    float fitness; // a value between 0 to 1

public:
    Individual() {};
    Individual(float x1, float x2);
    float get_fitness();
    float get_x1();
    float get_x2();
    void set_x1(float x1);
    void set_x2(float x2);
    void set_probability_of_choosing_individual(float percentage);
    float get_probability_of_choosing_individual();
};

#endif