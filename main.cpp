#include <iostream>
#include "ea.h"

static const unsigned int SEED = 100;

int main() {
    EA ea(SEED);

    ea.initialize_population();
    ea.evaluate_population();

    do{
        ea.parent_selection();
        ea.recombination();
        ea.mutation();
        ea.next_generation_selection();
        ea.evaluate_population();
    } while(!EA::should_terminate());

    return 0;
}
