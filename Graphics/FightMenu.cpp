#include "Battle.h"

int Battle_FightMenu(SDL_Surface* screen,
                     PKMN::Pokemon* Ally,
                     PKMN::Pokemon* Foe,
                     const PKMN::Place& place)
{
    int attackNumber = -1; /// -1 = doing nothing
    SET_BATTLE_FONT_AND_COLOR
    SET_BATTLE_BACKGROUND
    SET_BATTLE_MENU("./Pictures/Battle/FightMenu.png")

    SET_BATTLE_BATTLERS
    SET_BATTLE_DATABOX

    /// Text and images for move description
    std::array<std::pair<unsigned int, PKMN::Move>, NB_OF_MOVE_PER_PKMN>* listMove = Ally->getListMove();
    std::array<SDL_Surface*, NB_OF_MOVE_PER_PKMN> textMove;
    SDL_Surface* textMovePP = NULL;
    SDL_Surface* moveType = NULL;
    for(unsigned int i = 0; i < NB_OF_MOVE_PER_PKMN; i++)
    {
        textMove[i] = NULL;

    }
    std::array<SDL_Rect, NB_OF_MOVE_PER_PKMN> textMovepos;
    SDL_Rect textMovePPpos, moveTypepos;
    for(unsigned int i = 0; i < NB_OF_MOVE_PER_PKMN; i++)
    {
        textMovepos[i].x = 40 + 130 * (i % 2);
        textMovepos[i].y = 320 + 30 * (i >= 2);
        textMove[i] = TTF_RenderText_Blended(fontSmall, listMove->operator[](i).second.getName().c_str(), textColor);
    }
    textMovePPpos.x = 349 + 60;
    textMovePPpos.y = 299 + 50;
    moveTypepos.x = 349 + 50;
    moveTypepos.y = 299 + 15;

    /// Cursor
    SDL_Surface* cursor = NULL;
    SDL_Rect cursorpos;
    cursorpos.x = 25;
    cursorpos.y = 315;
    int i_cur = 0;
    cursor = IMG_Load("./Pictures/Battle/selarrow.png");

    textMovePP = TTF_RenderText_Blended(fontSmall,
                                        (PKMN::int_to_string(listMove->operator[](i_cur).first)
                                         + "/"
                                         + PKMN::int_to_string(listMove->operator[](i_cur).second.getTotalPP()) ).c_str(),
                                        textColor);
    moveType = IMG_Load(listMove->operator[](i_cur).second.getType().getPathImage().c_str());

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
                    cursorpos.x = 25 + 130 * (cursorpos.x == 25);
                }
                else if(event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_DOWN)
                {
                    cursorpos.y = 315 + 30 *(cursorpos.y == 315);
                }
                else if(event.key.keysym.sym == SDLK_RETURN)
                {
                    attackNumber = i_cur;
                    stop = true;
                }
                else if(event.key.keysym.sym == SDLK_BACKSPACE)
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
        if(i_cur != 2 * (cursorpos.y != 315) + (cursorpos.x != 25))
        {
            i_cur = 2 * (cursorpos.y != 315) + (cursorpos.x != 25);
            SDL_FreeSurface(textMovePP);
            SDL_FreeSurface(moveType);
            textMovePP = TTF_RenderText_Blended(fontSmall,
                                                (PKMN::int_to_string(listMove->operator[](i_cur).first)
                                                 + "/"
                                                 + PKMN::int_to_string(listMove->operator[](i_cur).second.getTotalPP()) ).c_str(),
                                                textColor);
            moveType = IMG_Load(listMove->operator[](i_cur).second.getType().getPathImage().c_str());
        }
        BLIT_BATTLE_BACKGROUND
        BLIT_BATTLE_BATTLERS
        BLIT_BATTLE_DATABOX
        BLIT_BATTLE_MENU
        for(unsigned int i = 0; i < NB_OF_MOVE_PER_PKMN; i++)
        {
            SDL_BlitSurface(textMove[i], NULL, screen, &textMovepos[i]);
        }
        SDL_BlitSurface(textMovePP, NULL, screen, &textMovePPpos);
        SDL_BlitSurface(moveType, NULL, screen, &moveTypepos);
        SDL_BlitSurface(cursor, NULL, screen, &cursorpos);
        SDL_Flip(screen);
        SDL_Delay(50);
    }

    /// Free memory :
    FREE_BATTLE_BACKGROUND
    FREE_BATTLE_BATTLERS
    FREE_BATTLE_DATABOX
    FREE_BATTLE_MENU
    for(unsigned int i = 0; i < NB_OF_MOVE_PER_PKMN; i++)
    {
        SDL_FreeSurface(textMove[i]);
    }
    SDL_FreeSurface(textMovePP);
    SDL_FreeSurface(moveType);
    SDL_FreeSurface(cursor);
    FREE_BATTLE_FONT;
    return attackNumber;
}
