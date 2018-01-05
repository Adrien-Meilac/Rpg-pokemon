#include "Battle.h"

void Battle_HPAllyDecrease(SDL_Surface* screen,
                           PKMN::Pokemon* Ally,
                           PKMN::Pokemon* Foe,
                           const PKMN::Place& place,
                           int damagePoint) /// Damage point are under current HP
{
    SET_BATTLE_FONT_AND_COLOR
    SET_BATTLE_BACKGROUND
    SET_BATTLE_MENU("./Pictures/Battle/choice 1.png");
    SET_BATTLE_BATTLERS
    SET_BATTLE_DATABOX

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
            default:
            {
                break;
            }
            }
        }
        BLIT_BATTLE_BACKGROUND
        BLIT_BATTLE_BATTLERS
        BLIT_BATTLE_DATABOX
        BLIT_BATTLE_MENU
        SDL_Flip(screen);
        SDL_Delay(14);
        if(damagePoint != 0)
        {
            if(damagePoint > 0)
            {
                Ally->decrementHP();
                damagePoint -= 1;
            }
            else
            {
                Ally->incrementHP();
                damagePoint += 1;
            }
            lifeBarAllyLength = static_cast<int>(96.0 * static_cast<double>(Ally->getCurHP())/static_cast<double>(Ally->getNormalHP()));
            lifeBarAlly = SDL_CreateRGBSurface(SDL_HWSURFACE, lifeBarAllyLength, 6, 32, 0, 0, 0, 0);
            if(Ally->getCurHP() < 0.2 * Ally->getNormalHP())
            {
                SDL_FillRect(lifeBarAlly, NULL, SDL_MapRGB(lifeBarAlly->format, 206, 0, 0));
            }
            else if(Ally->getCurHP() < 0.5 * Ally->getNormalHP())
            {
                SDL_FillRect(lifeBarAlly, NULL, SDL_MapRGB(lifeBarAlly->format, 206, 206, 0));
            }
            else
            {
                SDL_FillRect(lifeBarAlly, NULL, SDL_MapRGB(lifeBarAlly->format, 0, 206, 0));
            }
            textHPAlly = TTF_RenderText_Blended(fontSmall,
                                                (PKMN::int_to_string(Ally->getCurHP())
                                                 + "/"
                                                 + PKMN::int_to_string(Ally->getNormalHP())).c_str()
                                                , textColor);
        }
        else
        {
            stop = true;
        }
    }

    /// Free memory :
    FREE_BATTLE_BACKGROUND
    FREE_BATTLE_BATTLERS
    FREE_BATTLE_DATABOX
    FREE_BATTLE_MENU
    FREE_BATTLE_FONT
}
