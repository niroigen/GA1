#include "individual.h"

Individual::Individual(float x1, float x2) {
    this->_x1 = x1;
    this->_x2 = x2;
    this->_fitness = Helper::functionOutput(x1, x2);
}

float Individual::getFitness() {
    return _fitness;
}

float Individual::getX1() {
    return _x1;
}

float Individual::getX2() {
    return _x2;
}

void Individual::setX1(float x1) {
    this->_x1 = x1;
}

void Individual::setX2(float x2) {
    this->_x2 = x2;
    this->_fitness = Helper::functionOutput(_x1, _x2);
}

void Individual::setProbabilityOfChoosingIndividual(float percentage) {
    this->_percentOfBeingChosen = percentage;
}

float Individual::getProbabilityOfChoosingIndividual() {
    return _percentOfBeingChosen;
}
