#include "Battle.h"

void Battle_FadeToBlack(SDL_Surface* screen,
                        const PKMN::Place& place)
{
    bool stop = false;
    SDL_Event event;
    unsigned int i = 0;
    bool increment = true;
    unsigned int j = 0;
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
            }
        }
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, i, i, i));
        SDL_Flip(screen);
        SDL_Delay(10);
        if(increment)
        {
            i += 5;
        }
        else
        {
            i -= 5;
        }
        if(i == 255)
        {
            increment = false;
        }
        if(i == 0)
        {
            increment = true;
            j += 1;
        }
        if(j == 2)
        {
            stop = true;
        }
    }

    /// Background of the battle
    SDL_Surface *battleCommandBackgroud = NULL, *blackBG = NULL;
    SDL_Rect battleCommandBackgroudpos;
    battleCommandBackgroudpos.x = 0;
    battleCommandBackgroudpos.y = 0;
    blackBG = IMG_Load("./Pictures/Battle/blackBG.png");
    battleCommandBackgroud = IMG_Load("./Pictures/Battle/battlescreen.png");

    /// Text surface for large text message
    SDL_Surface *textBox = NULL;
    SDL_Rect textBoxpos;
    textBoxpos.x = 0;
    textBoxpos.y = 12 * 32 - 92;
    textBox = IMG_Load("./Pictures/Battle/choice 1.png");

    unsigned int pkmnAllyTransparency = 0;
    stop = false;
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
            default:
            {
                break;
            }
            }
        }
        SDL_BlitSurface(blackBG, NULL, screen, &battleCommandBackgroudpos);
        SDL_SetAlpha(battleCommandBackgroud, SDL_SRCALPHA, pkmnAllyTransparency);
        SDL_BlitSurface(battleCommandBackgroud, NULL, screen, &battleCommandBackgroudpos);
        SDL_SetAlpha(textBox, SDL_SRCALPHA, pkmnAllyTransparency);
        SDL_BlitSurface(textBox, NULL, screen, &textBoxpos);
        SDL_Flip(screen);
        SDL_Delay(100);
        pkmnAllyTransparency += 1;
        if(pkmnAllyTransparency == 255)
        {
            stop = true;
        }
    }
    SDL_FreeSurface(blackBG);
    SDL_FreeSurface(battleCommandBackgroud);
    SDL_FreeSurface(textBox);

}
