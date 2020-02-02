#ifndef EA_H
#define EA_H

#include "individual.h"
#include "helper.h"
#include <cstdlib>
#include <algorithm>
#include <random>
#include <algorithm>
#include <array>
#include <fstream>

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
    std::array<float, MAX_GENERATIONS + 1> maxFitness;
    float currentMaxFitness = 0;
    void Merge(int l, int m, int r);

public:
    EA(unsigned int seed) : seed(seed) {srand(seed);}
    void InitializePopulation();
    void EvaluatePopulation();
    void ParentSelection();
    void Recombination();
    void Mutation();
    void NextGenerationSelection();
    static bool ShouldTerminate();
    void ShuffleArray();
    void MergeSort(int l, int r);
};

#endif