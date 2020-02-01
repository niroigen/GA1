#ifndef EA_H
#define EA_H

#include "individual.h"
#include "helper.h"
#include <cstdlib>
#include <algorithm>
#include <random>
#include <algorithm>
#include <array>

static const int POPULATION_SIZE = 1000;
static const int MAX_PARENT_SIZE = 200;
static const int MAX_OFFSPRING_SIZE = 400;
static int COUNTER = 0;
static const int MAX_GENERATIONS = 10000;

class EA
{
private:
    std::array<Individual,POPULATION_SIZE> population;
    std::array<Individual,MAX_PARENT_SIZE> parents;
    std::array<Individual,MAX_OFFSPRING_SIZE> offsprings;
    unsigned int seed;
    std::array<float, MAX_GENERATIONS + 1> average;
    std::array<float, MAX_GENERATIONS + 1> max_fitness;
    float current_max_fitness = 0;
    void merge(int l, int m, int r);

public:
    EA(unsigned int seed) : seed(seed) {srand(seed);}
    void initialize_population();
    void evaluate_population();
    void parent_selection();
    void recombination();
    void mutation();
    void next_generation_selection();
    static bool should_terminate();
    void shuffle_array();
    void mergeSort(int l, int r);
};

#endif