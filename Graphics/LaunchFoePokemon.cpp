#include "Battle.h"

void Battle_LauchFoePokemon(SDL_Surface* screen,
                            PKMN::Pokemon* Ally,
                            PKMN::Pokemon* Foe,
                            const PKMN::Place& place,
                            bool isAllyAlreadyLauched)
{
    SET_BATTLE_FONT_AND_COLOR
    SET_BATTLE_BACKGROUND
    SET_BATTLE_MENU("./Pictures/Battle/choice 1.png")
    SET_BATTLE_BATTLERS
    SET_BATTLE_DATABOX

    unsigned int pkmnAllyTransparency = 0;
    bool stop = false;
    SDL_Event event;
    while (!stop)
    {
        //SDL_WaitEvent(&event);
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
            {
                exit(EXIT_SUCCESS);
                break;
            }
            case SDL_KEYDOWN:
            {
                switch(event.key.keysym.sym == SDLK_RETURN)
                {
                    stop = true;
                }
                break;
            }
            default:
            {
                break;
            }
            }
        }
        BLIT_BATTLE_BACKGROUND
        if(isAllyAlreadyLauched)
        {
            SDL_BlitSurface(pkmnAlly, NULL, screen, &pkmnAllypos);
        }
        SDL_SetAlpha(pkmnFoe, SDL_SRCALPHA, pkmnAllyTransparency);
        SDL_BlitSurface(pkmnFoe, NULL, screen, &pkmnFoepos);
        BLIT_BATTLE_DATABOX
        BLIT_BATTLE_MENU
        SDL_Flip(screen);
        SDL_Delay(20);
        if(pkmnAllyTransparency == 255)
        {
            stop = true;
        }
        else
        {
            pkmnAllyTransparency += 15;
        }
    }

    /// Free memory :
    FREE_BATTLE_BACKGROUND
    FREE_BATTLE_MENU
    FREE_BATTLE_BATTLERS
    FREE_BATTLE_DATABOX
    FREE_BATTLE_FONT
}
