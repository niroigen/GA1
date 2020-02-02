#include <iostream>
#include "ea.h"

static const unsigned int SEED = 17;

int main() {
    srand(time(NULL));
    EA ea;

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
