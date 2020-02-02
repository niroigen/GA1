#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "helper.h"

class Individual {
private:
    float x1; // -12.0 to 12.0
    float x2; // -6.0 to 6.0
    float percentOfBeingChosen;
    float fitness; // a value between 0 to 1

public:
    Individual() {};

    Individual(float x1, float x2);

    float getFitness();

    float getX1();

    float getX2();

    void setX1(float x1);

    void setX2(float x2);

    void setProbabilityOfChoosingIndividual(float percentage);

    float getProbabilityOfChoosingIndividual();
};

#endif