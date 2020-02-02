#include "individual.h"

Individual::Individual(float x1, float x2)
{
    this->x1 = x1;
    this->x2 = x2;
    this->fitness = Helper::functionOutput(x1, x2);
}

float Individual::get_fitness()
{
    return fitness;
}

float Individual::get_x1()
{
    return x1;
}

float Individual::get_x2()
{
    return x2;
}

void Individual::set_x1(float x1)
{
    this->x1 = x1;
}

void Individual::set_x2(float x2)
{
    this->x2 = x2;
    this->fitness = Helper::functionOutput(x1, x2);
}

void Individual::set_probability_of_choosing_individual(float percentage)
{
    this->percent_of_being_chosen = percentage;
}

float Individual::get_probability_of_choosing_individual()
{
    return percent_of_being_chosen;
}