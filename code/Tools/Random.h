#ifndef PKMN_RANDOM_H_INCLUDED
#define PKMN_RANDOM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctime>

namespace PKMN
{

double rand_uniform(double a, double b);
    /** \brief Generate a uniform law
     *
     * \param a double : lower bound
     * \param b double : upper bound
     * \return double : between a and b
     *
     */

bool binom_event(double p);
    /** \brief bernouilli law
     *
     * \param p double : probability of success
     * \return bool : is it a success or a failure ?
     *
     */

}


#endif // RANDOM_H_INCLUDED
