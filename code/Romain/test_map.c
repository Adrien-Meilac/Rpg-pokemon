#define largeur 16
#define hauteur 12
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "DimScreen.h"

void f(SDL_Surface* screen)
{
    std::array<std::array<SDL_Surface*, NB_OF_CASE_WIDTH>, NB_OF_CASE_HEIGHT> background;
    std::array<std::array<SDL_Rect, NB_OF_CASE_WIDTH>, NB_OF_CASE_HEIGHT> backgroundpos;
    for (unsigned int i=0; i<NB_OF_CASE_WIDTH; i++)
    {
        for(unsigned int j=0; j<NB_OF_CASE_HEIGHT; j++)
        {
            background[i][j] = IMG_Load("I:/Autotilessplit/Gravel/0_2.png");
            backgroundpos[i][j].x = BLOCK_SIZE * i;
            backgroundpos[i][j].y = BLOCK_SIZE * j;
        }
    }

    SDL_Surface* player;
    SDL_Rect playerpos, playerPartpos, playerMovepos;
    player = IMG_Load("I:/Field/trchar000.png");
    playerpos.x = SCREEN_WIDTH/2;///Where he is on screen.
    playerpos.y = SCREEN_HEIGHT/2;
    playerPartpos.x = 0; ///Where it's taken on trainer image.
    playerPartpos.y = 0;
    playerPartpos.h = 48;
    playerPartpos.w = 32;
    playerMovepos.x = 0;
    playerMovepos.y = 0;


    //Move handling
    SDL_EnableKeyRepeat(10, 10); /* Repeated hotkey activation */
    bool stop = false;
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
                switch(event.key.keysym.sym)
                {
                case SDLK_UP:
                    playerPartpos.y = 3*48;
                    playerMovepos.y = -1;
                    break;
                case SDLK_DOWN:
                    playerPartpos.y = 0*48;
                    playerMovepos.y = 1;
                    break;
                case SDLK_RIGHT:
                    playerPartpos.y = 2*48;
                    playerMovepos.x = 1;
                    break;
                case SDLK_LEFT:
                    playerPartpos.y = 1*48;
                    playerMovepos.x = -1;
                    break;
                }
                break;
            }
        }

        /* On reremplit l'écran*/
        for(unsigned int k = 0; k < 2; k++)
        {
            playerPartpos.x = (playerPartpos.x + 32)% 128;
            playerPartpos.h = 48+playerPartpos.y;
            playerPartpos.w = 32+playerPartpos.x;
            playerpos.x = playerpos.x + playerMovepos.x * BLOCK_SIZE/2;
            playerpos.y = playerpos.y + playerMovepos.y * BLOCK_SIZE/2;
            for (unsigned int i=0; i<NB_OF_CASE_WIDTH; i++)
            {
                for(unsigned int j=0; j<NB_OF_CASE_HEIGHT; j++)
                {
                    SDL_BlitSurface(background[i][j], NULL, screen, &backgroundpos[i][j]);
                }
            }
            SDL_BlitSurface(player, &playerPartpos, ecran, &playerpos);
            /* On met à jour l'affichage */
            SDL_Flip(ecran);
            SDL_Delay(50);
        }
        playerMovepos.x = 0;
        playerMovepos.y = 0;

    }
    for (unsigned int i=0; i<NB_OF_CASE_WIDTH; i++)
    {
        for(unsigned int j=0; j<NB_OF_CASE_HEIGHT; j++)
        {
            SDL_FreeSurface(background[i][j]);
        }
    }
    SDL_FreeSurface(player);

}

int main(int argc, char *argv[])
{
    SDL_Surface *screen = NULL, *background = NULL, *trainer = NULL; // Le pointeur qui va stocker la surface de l'écran

    SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(512, 384, 32, SDL_HWSURFACE); // On tente d'ouvrir une fenêtre
    if (screen == NULL) // Si l'ouverture a échoué, on le note et on arrête
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_WM_SetCaption("Map du jeu", NULL);
    f(screen);
    SDL_QUIT();
    return EXIT_SUCCESS;
}
