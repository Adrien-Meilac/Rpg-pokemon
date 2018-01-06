#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include "DimScreen.h"
#include "Battle/Player.h"
#include "Field/Place.h"
#include "Pokemon/Pokemon.h"
#include "Battle/BattleWildPokemon.h"
#include "Pokemon/Flag.h"
#include "Tools/Random.h"
#include "Graphics/Battle.h"
#include "Graphics/Field.h"

using namespace PKMN;

int main(int argc, char* argv[])
{
    seed();
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    SDL_WM_SetIcon(IMG_Load("pokeball.png"), NULL);
    SDL_Surface *screen = NULL;
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Pokemon - MEILAC Adrien", NULL);
    if(screen == NULL)
    {
        std::cout << "Error when loading screen" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string flag = f(screen);
    SDL_SaveBMP(screen, "test.bmp");
    if(flag == "PARTY")
    {
        Player player;
        Battle_SwapMenu(screen,&player, false);
    }
//    Place place("ROAD21");
//    Pokemon* pkmn = player.getPokemon(4);
//    BattleWildPokemon battle(screen, player, place, pkmn);
//    battle.start();
    SDL_Quit();
    TTF_Quit();

    return EXIT_SUCCESS;
}

