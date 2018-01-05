#include "Field.h"

void f(SDL_Surface* screen)
{
    std::array<std::array<SDL_Surface*, NB_OF_CASE_WIDTH>, NB_OF_CASE_HEIGHT> background;
    std::array<std::array<SDL_Rect, NB_OF_CASE_WIDTH>, NB_OF_CASE_HEIGHT> backgroundpos;
    for(unsigned int i = 0; i < NB_OF_CASE_HEIGHT; i++)
    {
        for(unsigned int j = 0; j < NB_OF_CASE_WIDTH; j++)
        {
            if(((i < 3) || (i > 8)) && ((j < 3) || (j > 10)))
            {
                background[i][j] = IMG_Load("./Pictures/Field/Texture/Light_grass/2_1.png");
            }
            else
            {
                background[i][j] = IMG_Load("./Pictures/Field/Texture/Sand_shore/2_4.png");
            }
            backgroundpos[i][j].x = BLOCK_SIZE * j;
            backgroundpos[i][j].y = BLOCK_SIZE * i;
        }
    }

    SDL_Surface* player;
    SDL_Rect playerpos, playerPartpos, playerMovepos;
    player = IMG_Load("./Pictures/Characters/Trainer/Field/trchar020.png");
    playerpos.x = SCREEN_WIDTH/2;///Where he is on screen.
    playerpos.y = SCREEN_HEIGHT/2;
    playerPartpos.x = 0; ///Where it's taken on trainer image.
    playerPartpos.y = 0;
    playerPartpos.h = 48;
    playerPartpos.w = 32;
    playerMovepos.x = 0;
    playerMovepos.y = 0;

    bool stop = false;
    SDL_Event event;
    SDL_EnableKeyRepeat(10, 10);
    while (!stop)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                {
                    stop = true;
                break;
                }
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_DOWN)
                {
                    playerPartpos.y = 0 * 48;
                    if(playerMovepos.x == 0)
                    {
                        playerMovepos.y = 1;
                    }
                }
                if(event.key.keysym.sym == SDLK_UP)
                {
                    playerPartpos.y = 3 * 48;
                    if(playerMovepos.x == 0)
                    {
                        playerMovepos.y = -1;
                    }
                }
                else if(event.key.keysym.sym == SDLK_LEFT)
                {
                    playerPartpos.y = 1 * 48;
                    if(playerMovepos.y == 0)
                    {
                        playerMovepos.x = -1;
                    }
                }
                else if(event.key.keysym.sym == SDLK_RIGHT)
                {
                    playerPartpos.y = 2 * 48;
                    if(playerMovepos.y == 0)
                    {
                        playerMovepos.x = 1;
                    }
                }
                break;
            }
        }
        if(playerMovepos.x != 0 || playerMovepos.y !=0)
        {
            for(unsigned int k = 0; k < 2; k++)
            {
                playerPartpos.x = (playerPartpos.x + 32)% 128;
                playerpos.x = playerpos.x + playerMovepos.x * BLOCK_SIZE/2;
                playerpos.y = playerpos.y + playerMovepos.y * BLOCK_SIZE/2;
                playerMovepos.x = 0;
                playerMovepos.y = 0;
                for(unsigned int i = 0; i < NB_OF_CASE_HEIGHT; i++)
                {
                    for(unsigned int j = 0; j < NB_OF_CASE_WIDTH; j++)
                    {
                        SDL_BlitSurface(background[i][j], NULL, screen, &backgroundpos[i][j]);
                    }
                }
                SDL_BlitSurface(player, &playerPartpos, screen, &playerpos);
                SDL_Flip(screen);
                SDL_Delay(10);
            }
        }
        else
        {
            for(unsigned int i = 0; i < NB_OF_CASE_HEIGHT; i++)
            {
                for(unsigned int j = 0; j< NB_OF_CASE_WIDTH; j++)
                {
                    SDL_BlitSurface(background[i][j], NULL, screen, &backgroundpos[i][j]);
                }
            }
            SDL_BlitSurface(player, &playerPartpos, screen, &playerpos);
            SDL_Flip(screen);
            SDL_Delay(100);
        }

    }
    for (unsigned int i = 0; i < NB_OF_CASE_HEIGHT; i++)
    {
        for(unsigned int j = 0; j< NB_OF_CASE_WIDTH; j++)
        {
            SDL_FreeSurface(background[i][j]);
        }
    }
    SDL_FreeSurface(player);
}

