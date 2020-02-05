#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "helper.h"

class Individual {
private:
    float _x1 = 0; // -12.0 to 12.0
    float _x2 = 0; // -6.0 to 6.0
    float _percentOfBeingChosen = 0;
    float _fitness = 0; // a value between 0 to 1
    float _parent1X1 = 0;
    float _parent2X1 = 0;
    float _parent1X2 = 0;
    float _parent2X2 = 0;

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

    float getParent1X1() {return _parent1X1;}

    float getParent1X2() {return _parent1X2;}

    float getParent2X1() {return _parent2X1;}

    float getParent2X2() {return _parent2X2;}

    void setParents(float parent1X1, float parent1X2, float parent2X1, float parent2X2) {
        _parent1X1 = parent1X1;
        _parent1X2 = parent1X2;
        _parent2X1 = parent2X1;
        _parent2X2 = parent2X2;
    }
};

#endif