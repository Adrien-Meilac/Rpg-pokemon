#include "Battle.h"

void Battle_ScreenMessage(SDL_Surface* screen,
                          PKMN::Pokemon* Ally,
                          PKMN::Pokemon* Foe,
                          const PKMN::Place& place,
                          std::string message,
                          bool isAllyAlreadyLauched,
                          bool isFoeAlreadyLauched)
{
    SET_BATTLE_FONT_AND_COLOR
    SET_BATTLE_BACKGROUND
    SET_BATTLE_MENU("./Pictures/Battle/choice 1.png")
    SET_BATTLE_BATTLERS
    SET_BATTLE_DATABOX

    /// Text surface for large text message
    SDL_Surface *textMessage = NULL;
    SDL_Rect textMessagepos;
    textMessagepos.x = 25;
    textMessagepos.y = 310;
    textMessage = TTF_RenderText_Blended(font, message.c_str(), textColor);

    /// Cursor
    std::array<SDL_Surface*, 4> cursor;
    for(unsigned int i = 0; i < 4; i++)
    {
        cursor[i] = NULL;
    }
    SDL_Rect cursorpos;
    cursorpos.x = 16 * 32 - 50;
    cursorpos.y = 340;
    for(unsigned int i = 0; i < 4; i++)
    {
        cursor[i] = IMG_Load(("./Pictures/Battle/Arrow"+ PKMN::int_to_string(i + 1) + ".png").c_str());
    }

    int i = 0, j = 0;
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
        if(isAllyAlreadyLauched)
        {
            SDL_BlitSurface(pkmnAlly, NULL, screen, &pkmnAllypos);
        }
        if(isFoeAlreadyLauched)
        {
            SDL_BlitSurface(pkmnFoe, NULL, screen, &pkmnFoepos);
        }
        BLIT_BATTLE_DATABOX
        BLIT_BATTLE_MENU
        SDL_BlitSurface(textMessage, NULL, screen, &textMessagepos);
        SDL_BlitSurface(cursor[i], NULL, screen, &cursorpos);
        SDL_Flip(screen);
        SDL_Delay(50);
        j = (j + 1) % 7;
        if(j <= 3)
        {
            i = j;
        }
        else
        {
            i = 3 - (j - 3);
        }
    }

    /// Free memory :
    FREE_BATTLE_BACKGROUND
    FREE_BATTLE_BATTLERS
    FREE_BATTLE_DATABOX
    FREE_BATTLE_MENU
    SDL_FreeSurface(textMessage);
    for(unsigned int i = 0; i < 4; i++)
    {
        SDL_FreeSurface(cursor[i]);
    }
    FREE_BATTLE_FONT
}
