#include "Random.h"

double PKMN::rand_uniform(double a, double b)
{
    unsigned int accuracy = 5000;
    return a + (static_cast<double>(rand() % accuracy) / static_cast<double>(accuracy)) * (b - a);
}

bool PKMN::binom_event(double p)
{
    unsigned int accuracy = 5000;
    unsigned int r = static_cast<double>(rand() % accuracy);
    return r < p * static_cast<double>(accuracy);
}
