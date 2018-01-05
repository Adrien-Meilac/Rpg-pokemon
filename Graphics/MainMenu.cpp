#include "Battle.h"

std::string Battle_MainMenu(SDL_Surface* screen,
                            PKMN::Pokemon* Ally,
                            PKMN::Pokemon* Foe,
                            const PKMN::Place& place)
{
    std::string choice = "";
    SET_BATTLE_FONT_AND_COLOR
    SET_BATTLE_BACKGROUND
    SET_BATTLE_MENU("./Pictures/Battle/MainMenu.png")
    SET_BATTLE_BATTLERS
    SET_BATTLE_DATABOX

    /// Text message
    SDL_Surface *textMessage = NULL;
    SDL_Rect textMessagepos;
    textMessagepos.x = 25;
    textMessagepos.y = 330;
    textMessage = TTF_RenderText_Blended(fontSmall, ("What will " + Ally->getName() + " do ?").c_str(), textColor);

    /// Cursor
    SDL_Surface* cursor = NULL;
    SDL_Rect cursorpos;
    cursorpos.x = 250;
    cursorpos.y = 290;
    cursor = IMG_Load("./Pictures/Battle/choiceCursor.png");

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
                if(event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT)
                {
                    cursorpos.x = 250 + 130 * (cursorpos.x == 250);
                }
                else if(event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_DOWN)
                {
                    cursorpos.y = 290 + 48 *(cursorpos.y == 290);
                }
                else if(event.key.keysym.sym == SDLK_RETURN)
                {
                    if(cursorpos.x == 250 && cursorpos.y == 290)
                    {
                        choice = "FIGHT";
                    }
                    else if(cursorpos.x != 250 && cursorpos.y == 290)
                    {
                        choice = "BAG";
                    }
                    else if(cursorpos.x == 250 && cursorpos.y != 290)
                    {
                        choice = "POKEMON";
                    }
                    else
                    {
                        choice = "RUN";
                    }
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
        BLIT_BATTLE_BATTLERS
        BLIT_BATTLE_DATABOX
        BLIT_BATTLE_MENU
        SDL_BlitSurface(textMessage, NULL, screen, &textMessagepos);
        SDL_BlitSurface(cursor, NULL, screen, &cursorpos);
        SDL_Flip(screen);
        SDL_Delay(50);
    }

    /// Free memory :
    FREE_BATTLE_BACKGROUND
    FREE_BATTLE_BATTLERS
    FREE_BATTLE_DATABOX
    FREE_BATTLE_MENU
    FREE_BATTLE_FONT
    SDL_FreeSurface(textMessage);
    SDL_FreeSurface(cursor);
    return choice;
}
