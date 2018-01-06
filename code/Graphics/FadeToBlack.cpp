#include "Battle.h"

void Battle_FadeToBlack(SDL_Surface* screen,
                        const PKMN::Place& place)
{
//    SDL_SaveBMP(screen, "temp.bmp");
    SDL_Surface* fieldBackgroud = NULL;
    SDL_Rect fieldBackgroudpos;
    fieldBackgroudpos.x = 0;
    fieldBackgroudpos.y = 0;
    fieldBackgroud = IMG_Load("temp.bmp");

    std::array<std::array<SDL_Surface*,SCREEN_WIDTH>,SCREEN_HEIGHT> transition;
    SDL_Rect transitionpos;
    for(unsigned int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for(unsigned int j = 0; j < SCREEN_WIDTH; j++)
        {
            transition[i][j] = NULL;
            transition[i][j] = SDL_CreateRGBSurface(SDL_HWSURFACE, 1, 1, 32, 0, 0, 0, 0);
            SDL_FillRect(transition[i][j], NULL, SDL_MapRGB(transition[i][j]->format, 255, 255, 255));
        }
    }

    bool stop = false;
    SDL_Event event;
    int r = static_cast<int>(ceil(sqrt(pow(SCREEN_HEIGHT/2,2)+pow(SCREEN_WIDTH/2,2))));

    SDL_BlitSurface(fieldBackgroud, NULL, screen, &fieldBackgroudpos);
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
        for(int i = 0; i < SCREEN_HEIGHT; i++)
        {
            for(int j = 0; j < SCREEN_WIDTH; j++)
            {
                if(pow(r,2) < pow(i - SCREEN_HEIGHT/2,2) + pow(j - SCREEN_WIDTH/2,2))
                {
                    transitionpos.x = j;
                    transitionpos.y = i;
                    SDL_FillRect(transition[i][j], NULL, SDL_MapRGB(transition[i][j]->format, std::max(0, 255 - r), std::max(0, 255 - r), std::max(0, 255 - r)));
                    SDL_BlitSurface(transition[i][j], NULL, screen, &transitionpos);
                }
            }
        }
        SDL_Flip(screen);
        r -= 7;
        SDL_Delay(10);
        if(r <= 0)
        {
            stop = true;
        }
    }
    SET_BATTLE_BACKGROUND
    SET_BATTLE_MENU("./Pictures/Battle/choice 1.png")
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
            }
        }
        BLIT_BATTLE_BACKGROUND
        BLIT_BATTLE_MENU
        for(int i = 0; i < SCREEN_HEIGHT; i++)
        {
            for(int j = 0; j < SCREEN_WIDTH; j++)
            {
                if(pow(r,2) < pow(i - SCREEN_HEIGHT/2,2) + pow(j - SCREEN_WIDTH/2,2))
                {
                    transitionpos.x = j;
                    transitionpos.y = i;
                    SDL_FillRect(transition[i][j], NULL, SDL_MapRGB(transition[i][j]->format, std::max(0, 255 - r), std::max(0, 255 - r), std::max(0, 255 - r)));
                    SDL_BlitSurface(transition[i][j], NULL, screen, &transitionpos);
                }
            }
        }
        SDL_Flip(screen);
        r += 7;
        SDL_Delay(10);
        if(r >= static_cast<int>(ceil(sqrt(pow(SCREEN_HEIGHT/2,2)+pow(SCREEN_WIDTH/2,2)))))
        {
            stop = true;
        }
    }
    FREE_BATTLE_BACKGROUND
    FREE_BATTLE_MENU
    SDL_FreeSurface(fieldBackgroud);
    for(unsigned int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for(unsigned int j = 0; j < SCREEN_WIDTH; j++)
        {
            SDL_FreeSurface(transition[i][j]);
        }
    }

}
