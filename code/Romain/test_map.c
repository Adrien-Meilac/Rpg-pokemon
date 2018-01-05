#define largeur 16
#define hauteur 12
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>



int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *base = NULL, *trainer = NULL; // Le pointeur qui va stocker la surface de l'écran

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(512, 384, 32, SDL_HWSURFACE); // On tente d'ouvrir une fenêtre
    if (ecran == NULL) // Si l'ouverture a échoué, on le note et on arrête
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_WM_SetCaption("Map du jeu", NULL);
    int i = 0;
    int j = 0;
    int continuer = 1;
    SDL_Rect positionBase;
    SDL_Rect positionTrainer;
    positionTrainer.x = 0;
    positionTrainer.y = 0;
    base = IMG_Load("I:/Autotilessplit/Gravel/0_2.png");

    //Chargement des différents trainers
    int trainer[4, 4]
    int jambe = 0; //0 immobile 1 gauche levée 2 immobile 3 droite levée
    int orientation=0; //0 bas 1 gauche 2 droite 3 haut
    for(jambe=0; jambe<4; jambe++)
    {
        for(orientation=0; orientation<4; orientation++)
        {
            char chemin[]="I:/Trainerssplit/trchar000/";
            strcat(chemin, str(jambe));
            strcat(chemin, '_');
            strcat(chemin, str(orientation));
            strcat(chemin, ".png");
            trainer[jambe, orientation] = IMG_Load(chemin);
        }
    }
    //Création de l'image de fond
    for (i=0; i<16; i++)
    {
        for(j=0; j<12; j++)
        {
            positionBase.x = 32*i;
            positionBase.y = 32*j;
            SDL_BlitSurface(base, NULL, ecran, &positionBase);
        }
    }

    //Gestion du déplacement
    SDL_EnableKeyRepeat(10, 10); /* Activation de la répétition des touches */
    while (continuer)
    {
        positionBase = positionTrainer;
        jambe = (jambe+1)%4;
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_UP:
                orientation = 3;
                positionTrainer.y--;
                break;
            case SDLK_DOWN:
                orientation = 0;
                positionTrainer.y++;
                break;
            case SDLK_RIGHT:
                orientation = 2;
                positionTrainer.x++;
                break;
            case SDLK_LEFT:
                orientation = 1;
                positionTrainer.x--;
                break;
            }
            break;
        }

        /* On reremplit l'écran*/
        SDL_BlitSurface(trainer[jambe, orientation], NULL, ecran, &positionTrainer);
        SDL_BlitSurface(base, NULL, ecran, &positionBase);
        /* On met à jour l'affichage */
        SDL_Flip(ecran);
    }

    SDL_FreeSurface(ecran);
    SDL_FreeSurface(base);
    SDL_FreeSurface(trainer);
    SDL_Quit();

    return EXIT_SUCCESS;
}
