#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */

void pause();

int main(int argc, char *argv[])
{
    SDL_Surface *screen = NULL, *backgroundPicture = NULL, *baseEnemy = BULL, *basePlayer = NULL;
    SDL_Rect positionBackground, positionEnemy, positionPLayer;

    positionFond.x = 0;
    positionFond.y = 0;
    positionEnemy.x = 550;
    positionEnemy.y = 100;
    positionPlayer.x = 150;
    positionPlayer.y = 450;

    SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Cave battleground", NULL);

    imageDeFond = IMG_Load("battlebgcave.png");
    SDL_BlitSurface(backgroundPicture, NULL, screen, &positionFond);

    /* Chargement d'un PNG avec IMG_Load
    Celui-ci est automatiquement rendu transparent car les informations de
    transparence sont codées à l'intérieur du fichier PNG */
    baseEnemy = IMG_Load("enemybasecave.png");
    basePlayer = IMG_Load("playerbasecave.png");
    SDL_BlitSurface(baseEnemy, NULL, screen, &positionEnemy);
    SDL_BlitSurface(basePlayer, NULL, screen, &positionPlayer);

    SDL_Flip(ecran);
    pause();

    SDL_FreeSurface(backgroundImage);
    SDL_FreeSurface(baseEnemy);
    SDL_FreeSurface(basePlayer);
    SDL_Quit();

    return EXIT_SUCCESS;
}

void pause()
{
    int goOn = 1;
    SDL_Event event;

    while (goOn)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                goOn = 0;
        }
    }
}
