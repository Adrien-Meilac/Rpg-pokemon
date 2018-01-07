#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>

#include <vector>
#include <array>
#include "../DimScreen.h"
#include "Battle.h"
#include "../Tools/Random.h"
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctime>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <random>

#define PROBA_ENCOUNTER 0.5

extern "C"
{
    std::string Field(SDL_Surface* screen);
}

#endif // FIELD_H_INCLUDED
