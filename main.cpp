#include <iostream>
#include "ea.h"

static const unsigned int SEED = 17;

int main() {
    for (int i = 0; i < 15; i++) {
        std::cout << "HI" << std::endl;
        srand(i);
        EA ea(i);

        ea.InitializePopulation();
        ea.EvaluatePopulation();

        do {
            ea.ParentSelection();
            ea.Recombination();
            ea.Mutation();
            ea.NextGenerationSelection();
            ea.EvaluatePopulation();
        } while (!ea.ShouldTerminate());
    }

    return 0;
}
