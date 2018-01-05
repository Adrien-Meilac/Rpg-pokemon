#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include <iostream>
#include <vector>
#include <array>
#include "../DimScreen.h"
#include "Battle.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

extern "C"
{
    std::string f(SDL_Surface* screen);
}

#endif // FIELD_H_INCLUDED
