#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include "DimScreen.h"
#include "Battle/Player.h"
#include "Field/Place.h"
#include "Pokemon/Pokemon.h"
#include "Battle/BattleWildPokemon.h"
#include "Pokemon/Flag.h"
#include "Tools/Random.h"
#include "Graphics/Battle.h"
#include "Graphics/Field.h"


#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>

using namespace PKMN;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    SDL_WM_SetIcon(IMG_Load("pokeball.png"), NULL);
    SDL_Surface *screen = NULL;
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Pokemon - MEILAC Adrien / LANGLOIS Romain", NULL);
    if(screen == NULL)
    {
        std::cout << "Error when loading screen" << std::endl;
        exit(EXIT_FAILURE);
    }

    Player player;
    Place place("ROAD21");
    BattleWildPokemon* battle;
    bool stop = false;
    while(!stop)
    {
        std::string flag = Field(screen);
        if(flag == "PARTY")
        {
            Battle_SwapMenu(screen,&player, false);
        }
        else if(flag == "WILDBATTLE")
        {
            battle = new BattleWildPokemon(screen, player, place);
            battle->start();
            player = battle->getBackPlayer();
            delete(battle);
            battle = NULL;
        }
        else if(flag == "STOPGAME")
        {
            stop = true;
        }
    }
    SDL_Quit();
    TTF_Quit();

    return EXIT_SUCCESS;
}

