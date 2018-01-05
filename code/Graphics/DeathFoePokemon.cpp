#include "Battle.h"

void Battle_DeathFoePokemon(SDL_Surface* screen,
                            PKMN::Pokemon* Ally,
                            PKMN::Pokemon* Foe,
                            const PKMN::Place& place,
                            bool isAllyAlreadyLauched)
{
    SET_BATTLE_FONT_AND_COLOR
    SET_BATTLE_BACKGROUND
    SET_BATTLE_MENU("./Pictures/Battle/choice 1.png")
    SET_BATTLE_BATTLERS
    SDL_Rect pkmnFoeposcopy;
    pkmnFoeposcopy.x = pkmnFoepos.x;
    pkmnFoeposcopy.y = pkmnFoepos.y;
    SET_BATTLE_DATABOX

    bool stop = false;
    SDL_Event event;
    while (!stop)
    {
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
                if(event.key.keysym.sym == SDLK_RETURN)
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
        SDL_BlitSurface(pkmnFoe, NULL, screen, &pkmnFoepos);
        pkmnFoepos.x = pkmnFoeposcopy.x;
        pkmnFoepos.y = pkmnFoeposcopy.y;
        BLIT_BATTLE_DATABOX
        BLIT_BATTLE_MENU
        SDL_Flip(screen);
        if(pkmnFoeposcopy.y > 712)
        {
            stop = true;
        }
        else
        {
            pkmnFoeposcopy.y += 10;
        }
    }

    /// Free memory :
    FREE_BATTLE_BACKGROUND
    FREE_BATTLE_BATTLERS
    FREE_BATTLE_DATABOX
    FREE_BATTLE_MENU
    FREE_BATTLE_FONT
}

