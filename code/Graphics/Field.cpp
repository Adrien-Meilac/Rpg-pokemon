#include "Field.h"

std::string f(SDL_Surface* screen)
{
    SET_BATTLE_FONT_AND_COLOR
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

    SDL_Surface* player = NULL;
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

    SDL_Surface* menu = NULL;
    SDL_Rect menupos;
    menu = IMG_Load("./Pictures/Field/Menu.png");
    menupos.x = SCREEN_WIDTH - 166;
    menupos.y = 0;

    std::array<SDL_Surface*, 4> menuOption;
    std::array<SDL_Rect, 4> menuOptionpos;
    menuOption[0] = TTF_RenderText_Blended(fontSmall, "Party", textColor);
    menuOption[1] = TTF_RenderText_Blended(fontSmall, "Option2", textColor);
    menuOption[2] = TTF_RenderText_Blended(fontSmall, "Option3", textColor);
    menuOption[3] = TTF_RenderText_Blended(fontSmall, "Option4", textColor);
    for(unsigned int i = 0; i < menuOption.size(); i++)
    {
        menuOptionpos[i].x = menupos.x + 40;
        menuOptionpos[i].y = menupos.y + 40 * i + 20;
    }

    SDL_Surface* cursor = NULL;
    SDL_Rect cursorpos;
    int i_cur = 0;
    cursor = IMG_Load("./Pictures/Field/selarrow.png");

    bool stop = false;
    bool menuIsOpen = false;
    std::string flag = "";
    SDL_Event event;
    SDL_EnableKeyRepeat(1, 10);
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
            {
                if(event.key.keysym.sym == SDLK_SPACE)
                {
                    menuIsOpen = !menuIsOpen;
                }
                else if(event.key.keysym.sym == SDLK_DOWN)
                {
                    if(!menuIsOpen)
                    {
                        playerPartpos.y = 0 * 48;
                        if(playerMovepos.x == 0)
                        {
                            playerMovepos.y = 1;
                        }
                    }
                    else
                    {
                        i_cur = (i_cur + 1) % 4;
                    }
                }
                else if(event.key.keysym.sym == SDLK_UP)
                {
                    if(!menuIsOpen)
                    {
                        playerPartpos.y = 3 * 48;
                        if(playerMovepos.x == 0)
                        {
                            playerMovepos.y = -1;
                        }
                    }
                    else
                    {
                        i_cur = i_cur - 1;
                        if(i_cur < 0)
                        {
                            i_cur += 4;
                        }
                    }
                }
                else if(event.key.keysym.sym == SDLK_LEFT)
                {
                    if(!menuIsOpen)
                    {
                        playerPartpos.y = 1 * 48;
                        if(playerMovepos.y == 0 && !menuIsOpen)
                        {
                            playerMovepos.x = -1;
                        }
                    }
                }
                else if(event.key.keysym.sym == SDLK_RIGHT)
                {
                    if(!menuIsOpen)
                    {
                        playerPartpos.y = 2 * 48;
                        if(playerMovepos.y == 0 && !menuIsOpen)
                        {
                            playerMovepos.x = 1;
                        }
                    }
                }
                else if(event.key.keysym.sym == SDLK_RETURN)
                {
                    switch(i_cur)
                    {
                    case 0:
                        {
                            flag = "PARTY";
                        }
                    default:
                        {
                            break;
                        }
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
            cursorpos.x = menuOptionpos[i_cur].x - 20;
            cursorpos.y = menuOptionpos[i_cur].y - 10;
            for(unsigned int i = 0; i < NB_OF_CASE_HEIGHT; i++)
            {
                for(unsigned int j = 0; j< NB_OF_CASE_WIDTH; j++)
                {
                    SDL_BlitSurface(background[i][j], NULL, screen, &backgroundpos[i][j]);
                }
            }
            SDL_BlitSurface(player, &playerPartpos, screen, &playerpos);
            if(menuIsOpen)
            {
                SDL_BlitSurface(menu, NULL, screen, &menupos);
                for(unsigned int i = 0; i < menuOption.size(); i++)
                {
                    SDL_BlitSurface(menuOption[i], NULL, screen, &menuOptionpos[i]);
                }
                SDL_BlitSurface(cursor, NULL, screen, &cursorpos);
            }
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
    SDL_FreeSurface(menu);
    for(unsigned int i = 0; i < menuOption.size(); i++)
    {
        SDL_FreeSurface(menuOption[i]);
    }
    SDL_FreeSurface(cursor);
    FREE_BATTLE_FONT
    return flag;
}

