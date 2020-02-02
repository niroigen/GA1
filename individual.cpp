#include "individual.h"

Individual::Individual(float x1, float x2)
{
    this->x1 = x1;
    this->x2 = x2;
    this->fitness = Helper::functionOutput(x1, x2);
}

float Individual::getFitness()
{
    return fitness;
}

float Individual::getX1()
{
    return x1;
}

float Individual::getX2()
{
    return x2;
}

void Individual::setX1(float x1)
{
    this->x1 = x1;
}

void Individual::setX2(float x2)
{
    this->x2 = x2;
    this->fitness = Helper::functionOutput(x1, x2);
}

void Individual::setProbabilityOfChoosingIndividual(float percentage)
{
    this->percent_of_being_chosen = percentage;
}

float Individual::getProbabilityOfChoosingIndividual()
{
    return percent_of_being_chosen;
}