#include "ea.h"

void EA::InitializePopulation()
{
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        population[i] = Individual(Helper::randomX1(), Helper::randomX2());
    }
}

void EA::EvaluatePopulation()
{
    float total_fitness = 0;
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        total_fitness = population[i].get_fitness() + total_fitness;
    }

    std::ofstream myfile;
    myfile.open ("average.txt", std::ios::app);
    average[COUNTER] = total_fitness / POPULATION_SIZE;
    myfile << average[COUNTER] << "\n";
    myfile.close();

    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        population[i].set_probability_of_choosing_individual(population[i].get_fitness() / total_fitness);
    }
}

void EA::ParentSelection()
{
    for(int i = 0; i < MAX_PARENT_SIZE; i++)
    {
        double random_roll = (double) rand() / (RAND_MAX);
        double current_roll = 0;

        for(int j = 0; j < POPULATION_SIZE; j++)
        {
            current_roll += population[j].get_probability_of_choosing_individual();
            
            if (random_roll < current_roll)
            {
                parents[i] = population[j];
                break;
            }
        }
    }
}

void EA::Recombination()
{
    for(int i = 0; i < MAX_OFFSPRING_SIZE; i++)
    {
        int parent_1_index = rand() % MAX_PARENT_SIZE;
        int parent_2_index = rand() % MAX_PARENT_SIZE;

        Individual parent1 = parents[parent_1_index];
        Individual parent2 = parents[parent_2_index];

        float total_weight = parent1.get_fitness() + parent2.get_fitness();

        float new_x1 = parent1.get_x1() * (parent1.get_fitness() / total_weight) + parent2.get_x1() * (parent2.get_fitness() / total_weight);
        float new_x2 = parent1.get_x2() * (parent1.get_fitness() / total_weight) + parent2.get_x2() * (parent2.get_fitness() / total_weight);

        offsprings[i] = Individual(new_x1, new_x2);
    }
}

void EA::Mutation()
{
    for(int i = 0; i < MAX_OFFSPRING_SIZE; i++)
    {
        double random_roll = (double) rand() / (RAND_MAX);

        if (random_roll < 0.2)
        {
            float new_x1 = Helper::randomX1();
            float new_x2 = Helper::randomX2();

            offsprings[i].set_x1((offsprings[i].get_x1() + new_x1) / 2);
            offsprings[i].set_x2((offsprings[i].get_x2() + new_x2) / 2);
        }
    }
}

// Shuffle array
void EA::ShuffleArray()
{
    // To obtain a time-based seed
    unsigned seed = 0;

    // Shuffling our array
    shuffle(population.begin(), population.end(), std::default_random_engine(seed));
}

void EA::Merge(int l, int m, int r)
{ 
    int i, j, k; 
    int n1 = m - l + 1;
    int n2 =  r - m; 
  
    /* create temp arrays */
    Individual L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = population[l + i];
    for (j = 0; j < n2; j++) 
        R[j] = population[m + 1+ j];
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i].get_fitness() >= R[j].get_fitness()) 
        {
            population[k] = L[i];
            i++; 
        } 
        else
        {
            population[k] = R[j];
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    {
        population[k] = L[i];
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    {
        population[k] = R[j];
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void EA::MergeSort(int l, int r)
{

    if (l < r) 
    {
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        MergeSort(l, m);
        MergeSort(m + 1, r);

        Merge(l, m, r);
    } 
}

void EA::NextGenerationSelection()
{
    EA::MergeSort(0, POPULATION_SIZE - 1);
//    std::cout << "GENERATION " << COUNTER + 1<< std::endl << "BEST " << population[0].get_fitness() << std::endl << std::endl;

    if (currentMaxFitness < population[0].get_fitness())
    {
        currentMaxFitness = population[0].get_fitness();
    }

    std::ofstream myfile;
    myfile.open ("max.txt", std::ios::app);
    maxFitness[COUNTER] = currentMaxFitness;
    myfile << maxFitness[COUNTER] << "\t" << population[0].get_x1() << "\t" << population[0].get_x2() << "\n";
    myfile.close();

    int idx = 0;

    for (int i = POPULATION_SIZE - 1; idx < MAX_OFFSPRING_SIZE; i--)
    {
        population[i] = offsprings[idx++];
    }

    ShuffleArray();
}

bool EA::ShouldTerminate()
{
    return COUNTER++ == MAX_GENERATIONS;
}