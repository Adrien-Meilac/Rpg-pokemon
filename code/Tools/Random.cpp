#include "Random.h"

void PKMN::seed()
{
    srand(time(0));
}

double PKMN::rand_uniform(double a, double b)
{
    unsigned int accuracy = 5000;
    return a + static_cast<double>(rand() % accuracy) / static_cast<double>(accuracy) * (b - a);
}

bool PKMN::binom_event(double p)
{
    return PKMN::rand_uniform(0, 1) < p;
}
