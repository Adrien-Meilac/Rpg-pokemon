#include "Battle.h"

void Battle_DeathAllyPokemon(SDL_Surface* screen,
                             PKMN::Pokemon* Ally,
                             PKMN::Pokemon* Foe,
                             const PKMN::Place& place,
                             bool isFoeAlreadyLauched)
{
    SET_BATTLE_FONT_AND_COLOR
    SET_BATTLE_BACKGROUND
    SET_BATTLE_MENU("./Pictures/Battle/choice 1.png")
    SET_BATTLE_BATTLERS
    SDL_Rect pkmnAllyposcopy;
    pkmnAllyposcopy.x = pkmnAllypos.x;
    pkmnAllyposcopy.y = pkmnAllypos.y;
    SET_BATTLE_DATABOX

    unsigned int pkmnAllyTransparency = 0;
    bool increment = true;
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
                switch(event.key.keysym.sym)
                {
                case SDLK_RETURN:
                    {
                        stop = true;
                        break;
                    }
                }
                break;
            }
            }
        }
        BLIT_BATTLE_BACKGROUND
        SDL_BlitSurface(pkmnAlly, NULL, screen, &pkmnAllypos);
        pkmnAllypos.x = pkmnAllyposcopy.x;
        pkmnAllypos.y = pkmnAllyposcopy.y;
        if(isFoeAlreadyLauched)
        {
        SDL_BlitSurface(pkmnFoe, NULL, screen, &pkmnFoepos);
        }
        pkmnAllypos.x = pkmnAllyposcopy.x;
        pkmnAllypos.y = pkmnAllyposcopy.y;
        BLIT_BATTLE_DATABOX
        BLIT_BATTLE_MENU
        SDL_Flip(screen);
        if(pkmnAllyposcopy.y > 712)
        {
            stop = true;
        }
        else
        {
            pkmnAllyposcopy.y += 10;
        }
    }

    /// Free memory :
    FREE_BATTLE_BACKGROUND
    FREE_BATTLE_BATTLERS
    FREE_BATTLE_DATABOX
    FREE_BATTLE_MENU
    FREE_BATTLE_FONT
}

