#include "Battle.h"

int Battle_SwapMenu(SDL_Surface* screen,
                    PKMN::Player* player,
                    bool aNewPokemonMustBeSelected)
{
    SET_BATTLE_FONT_AND_COLOR
    SDL_Surface *swapMenuBackgroud = NULL;
    SDL_Rect swapMenuBackgroudpos;
    swapMenuBackgroudpos.x = 0;
    swapMenuBackgroudpos.y = 0;
    swapMenuBackgroud = IMG_Load("./Pictures/Characters/Trainer/Party/bg.png");

    std::array<SDL_Surface*, NB_OF_PKMN_PER_TRAINOR> PkmnSlot, PkmnIcon, PkmnName, PkmnLvl,
                                                    PkmnHP, PkmnLifeBarBG, PkmnLifeBar;
    std::array<SDL_Rect, NB_OF_PKMN_PER_TRAINOR> PkmnSlotpos, PkmnIconpos, PkmnNamepos, PkmnLvlpos,
                                                PkmnHPpos,PkmnLifeBarBGpos, PkmnLifeBarpos;
    for(unsigned int i = 0; i < NB_OF_PKMN_PER_TRAINOR; i ++)
    {
        PkmnSlotpos[i].x = 1 + 257 * (i % 2);
        PkmnSlotpos[i].y = 15 * (i % 2) + 95 * (i >= 4) + 95 * (i >= 2) + 5;
        PkmnIconpos[i].x = PkmnSlotpos[i].x + 9;
        PkmnIconpos[i].y = PkmnSlotpos[i].y + 25;
        PkmnNamepos[i].x = PkmnSlotpos[i].x + 60;
        PkmnNamepos[i].y = PkmnSlotpos[i].y + 20;
        PkmnLvlpos[i].x = PkmnSlotpos[i].x + 160;
        PkmnLvlpos[i].y = PkmnSlotpos[i].y + 20;
        PkmnHPpos[i].x = PkmnSlotpos[i].x + 140;
        PkmnHPpos[i].y = PkmnSlotpos[i].y + 68;
        PkmnLifeBarBGpos[i].x = PkmnSlotpos[i].x + 90;
        PkmnLifeBarBGpos[i].y = PkmnSlotpos[i].y + 50;
        PkmnLifeBarpos[i].x = PkmnLifeBarBGpos[i].x + 30;
        PkmnLifeBarpos[i].y = PkmnLifeBarBGpos[i].y + 2;
    }
    unsigned int lifeBarLength;
    for(unsigned int i = 0; i < NB_OF_PKMN_PER_TRAINOR; i ++)
    {
        if(player->getPokemon(i)->isAlive())
        {
            PkmnSlot[i] = IMG_Load("./Pictures/Characters/Trainer/Party/panel_rect.png");
        }
        else
        {
            PkmnSlot[i] = IMG_Load("./Pictures/Characters/Trainer/Party/panel_rect_faint.png");
        }
        PkmnIcon[i] = IMG_Load(player->getPokemon(i)->getIcon().c_str());
        PkmnName[i] = TTF_RenderText_Blended(fontSmall, player->getPokemon(i)->getName().c_str(), textColor);
        PkmnLvl[i] = TTF_RenderText_Blended(fontSmall, ("Lvl." + PKMN::int_to_string(player->getPokemon(i)->getLevel())).c_str(), textColor);
        PkmnHP[i] = TTF_RenderText_Blended(fontSmall,
                                            (PKMN::int_to_string(player->getPokemon(i)->getCurHP())
                                            + "/"
                                            + PKMN::int_to_string(player->getPokemon(i)->getNormalHP())).c_str()
                                            , textColor);
        PkmnLifeBarBG[i] = IMG_Load("./Pictures/Characters/Trainer/Party/overlay_hp_back.png");
        lifeBarLength = static_cast<int>(100.0 * static_cast<double>(player->getPokemon(i)->getCurHP())/static_cast<double>(player->getPokemon(i)->getNormalHP()));
        PkmnLifeBar[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, lifeBarLength, 6, 32, 0, 0, 0, 0);
        if(player->getPokemon(i)->getCurHP() < 0.2 * player->getPokemon(i)->getNormalHP())
        {
            SDL_FillRect(PkmnLifeBar[i], NULL, SDL_MapRGB(PkmnLifeBar[i]->format, 206, 0, 0));
        }
        else if(player->getPokemon(i)->getCurHP() < 0.5 * player->getPokemon(i)->getNormalHP())
        {
            SDL_FillRect(PkmnLifeBar[i], NULL, SDL_MapRGB(PkmnLifeBar[i]->format, 206, 206, 0));
        }
        else
        {
            SDL_FillRect(PkmnLifeBar[i], NULL, SDL_MapRGB(PkmnLifeBar[i]->format, 0, 206, 0));
        }
    }

    unsigned int selected = 0, current = 0;
    SDL_FreeSurface(PkmnSlot[selected]);
    PkmnSlot[selected] = IMG_Load("./Pictures/Characters/Trainer/Party/panel_rect_sel.png");

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
                case SDLK_LEFT:
                    {
                        if(current % 2 == 0)
                        {
                            current += 1;
                        }
                        else
                        {
                            current -= 1;
                        }
                        break;
                    }
                case SDLK_RIGHT:
                    {
                        if(current % 2 == 0)
                        {
                            current += 1;
                        }
                        else
                        {
                            current -= 1;
                        }
                        break;
                    }
                case SDLK_DOWN:
                    {
                        current = (current + 2) % 6;
                        break;
                    }
                case SDLK_UP:
                    {
                        current = (current - 2) % 6;
                        break;
                    }
                case SDLK_RETURN:
                    {
                        if(selected!= 0 && player->getPokemon(selected)->isAlive())
                        {
                            stop = true;
                        }
                        break;
                    }
                case SDLK_BACKSPACE:
                    {
                        if(!aNewPokemonMustBeSelected)
                        {
                            selected = -1;
                            stop = true;
                        }
                        break;
                    }
                }
            }
            }
            for(unsigned int i = 0; i < NB_OF_PKMN_PER_TRAINOR; i ++)
            {

            }
            if(selected != -1 && current != selected)
            {
                SDL_FreeSurface(PkmnSlot[selected]);
                SDL_FreeSurface(PkmnSlot[current]);
                PkmnSlot[selected] = IMG_Load("./Pictures/Characters/Trainer/Party/panel_rect.png");
                PkmnSlot[current] = IMG_Load("./Pictures/Characters/Trainer/Party/panel_rect_sel.png");
                selected = current;
            }
            SDL_BlitSurface(swapMenuBackgroud, NULL, screen, &swapMenuBackgroudpos);
            for(unsigned int i = 0; i < NB_OF_PKMN_PER_TRAINOR; i ++)
            {
                SDL_BlitSurface(PkmnSlot[i], NULL, screen, &PkmnSlotpos[i]);
                SDL_BlitSurface(PkmnIcon[i], NULL, screen, &PkmnIconpos[i]);
                SDL_BlitSurface(PkmnName[i], NULL, screen, &PkmnNamepos[i]);
                SDL_BlitSurface(PkmnLvl[i], NULL, screen, &PkmnLvlpos[i]);
                SDL_BlitSurface(PkmnHP[i], NULL, screen, &PkmnHPpos[i]);
                SDL_BlitSurface(PkmnLifeBarBG[i], NULL, screen, &PkmnLifeBarBGpos[i]);
                SDL_BlitSurface(PkmnLifeBar[i], NULL, screen, &PkmnLifeBarpos[i]);
            }
            SDL_Flip(screen);
            SDL_Delay(50);
        }
    }
    SDL_FreeSurface(swapMenuBackgroud);
    for(unsigned int i = 0; i < NB_OF_PKMN_PER_TRAINOR; i ++)
    {
        SDL_FreeSurface(PkmnSlot[i]);
        SDL_FreeSurface(PkmnIcon[i]);
        SDL_FreeSurface(PkmnName[i]);
        SDL_FreeSurface(PkmnLvl[i]);
        SDL_FreeSurface(PkmnHP[i]);
        SDL_FreeSurface(PkmnLifeBarBG[i]);
        SDL_FreeSurface(PkmnLifeBar[i]);
    }
    FREE_BATTLE_FONT
    return selected;
}
