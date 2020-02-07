#include <iostream>
#include <fstream>
#include <cstdio>
#include "ea.h"

int main() {
    for (int i = 0; i < 15; i++) {
        std::string average = "average_" + std::to_string(i) + ".txt";
        std::string max = "max_" + std::to_string(i) + ".txt";
        std::string location = "location_" + std::to_string(i) + ".txt";

        std::remove(average.c_str());
        std::remove(max.c_str());
        std::remove(location.c_str());

        std::cout << i << std::endl;
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
