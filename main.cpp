#include <iostream>
#include "ea.h"

static const unsigned int SEED = 200;

int main() {
    EA ea(SEED);

    ea.InitializePopulation();
    ea.EvaluatePopulation();

    do {
        ea.ParentSelection();
        ea.Recombination();
        ea.Mutation();
        ea.NextGenerationSelection();
        ea.EvaluatePopulation();
    } while (!EA::ShouldTerminate());

    return 0;
}
