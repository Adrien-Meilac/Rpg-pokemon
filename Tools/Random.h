#ifndef PKMN_RANDOM_H_INCLUDED
#define PKMN_RANDOM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

namespace PKMN
{

void seed();

double rand_uniform(double a, double b);

bool binom_event(double p);
}


#endif // RANDOM_H_INCLUDED
