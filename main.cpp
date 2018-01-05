#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include "Battle/Player.h"
#include "Field/Place.h"
#include "Pokemon/Pokemon.h"
#include "Battle/BattleWildPokemon.h"
#include "Pokemon/Flag.h"
#include "Tools/Random.h"

#define BLOCK_SIZE 32 /// Heigh = Width
#define SCREEN_WIDTH 16 * BLOCK_SIZE
#define SCREEN_HEIGHT 12 * BLOCK_SIZE

#include "Graphics/Battle.h"

using namespace PKMN;

//extern "C" {
//unsigned int printScreen()
//{
//    std::string choiceMode = "";
//    TTF_Init();
//    TTF_Font *font = NULL, *fontSmall = NULL;
//    font = TTF_OpenFont("./Fonts/pkmnrs.ttf", 26);
//    fontSmall = TTF_OpenFont("./Fonts/pkmndp.ttf", 20);
//    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
//    SDL_WM_SetIcon(IMG_Load("pokeball.png"), NULL);
//    SDL_Surface *screen = NULL, *battleCommandBackgroud = NULL,
//                *pkmnAlly = NULL, *pkmnFoe = NULL,
//                *databoxAlly = NULL, *databoxFoe = NULL, *textCommand = NULL,
//                *textPkmnAllyName = NULL, *textPkmnFoeName = NULL, *textHPAlly = NULL,
//                *choiceCursor = NULL, *textMove1 = NULL, *textMove2 = NULL,
//                *textMove3 = NULL, *textMove4 = NULL, *partyBG = NULL,
//                *partySlot1 = NULL, *partySlot2 = NULL, *partySlot3 = NULL,
//                *partySlot4 = NULL, *partySlot5 = NULL, *partySlot6 = NULL,
//                *partyPKMN1 = NULL, *partyPKMNHP1 = NULL,
//                *textCommandLarger = NULL;
//    SDL_Rect battleCommandBackgroudpos, pkmnAllypos, pkmnFoepos,
//            databoxAllypos, databoxFoepos, textCommandpos,
//            textPkmnAllyNamepos, textPkmnFoeNamepos,
//            textHPAllypos, choiceCursorpos,
//            textMove1pos, textMove2pos,
//            textMove3pos, textMove4pos, partyBGpos,
//            partySlot1pos, partySlot2pos, partySlot3pos,
//            partySlot4pos, partySlot5pos, partySlot6pos,
//            partyPKMN1pos, partyPKMNHP1pos, textCommandLargerpos;
//    battleCommandBackgroudpos.x = 0;
//    battleCommandBackgroudpos.y = 0;
//    pkmnAllypos.x = 60;
//    pkmnAllypos.y = 130;
//    pkmnFoepos.x = 310;
//    pkmnFoepos.y = 60;
//    databoxAllypos.x = SCREEN_WIDTH - 260;
//    databoxAllypos.y = 200;
//    databoxFoepos.x = 0;
//    databoxFoepos.y = 60;
//    textCommandpos.x = 25;
//    textCommandpos.y = 310;
//    textPkmnAllyNamepos.x = SCREEN_WIDTH - 260 + 40;
//    textPkmnAllyNamepos.y = 210;
//    textPkmnFoeNamepos.x = 7;
//    textPkmnFoeNamepos.y = 70;
//    textHPAllypos.x = SCREEN_WIDTH - 110;
//    textHPAllypos.y = 253;
//    choiceCursorpos.x = 250;
//    choiceCursorpos.y = 290;
//    textMove1pos.x = 35;
//    textMove1pos.y = 310;
//    textMove2pos.x = 135;
//    textMove2pos.y = 310;
//    textMove3pos.x = 35;
//    textMove3pos.y = 340;
//    textMove4pos.x = 135;
//    textMove4pos.y = 340;
//    partyBGpos.x = 0;
//    partyBGpos.y = 0;
//    partySlot1pos.x = 1;
//    partySlot1pos.y = 5;
//    partyPKMN1pos.x = 10;
//    partyPKMN1pos.y = 20;
//    partyPKMNHP1pos.x = 20;
//    partyPKMNHP1pos.x = 30;
//    partySlot2pos.x = 258;
//    partySlot2pos.y = 20;
//    partySlot3pos.x = 1;
//    partySlot3pos.y = 100;
//    partySlot4pos.x = 258;
//    partySlot4pos.y = 115;
//    partySlot5pos.x = 1;
//    partySlot5pos.y = 195;
//    partySlot6pos.x = 258;
//    partySlot6pos.y = 210;
//    textCommandLargerpos.x = 0;
//    textCommandLargerpos.y = SCREEN_HEIGHT - 92;
//    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
//    SDL_WM_SetCaption("Pokemon - MEILAC Adrien", NULL);
//    if(screen == NULL)
//    {
//        exit(EXIT_FAILURE);
//    }
//    battleCommandBackgroud = IMG_Load("./Pictures/Battle/battlescreen.png");
//    databoxAlly = IMG_Load("./Pictures/Battle/Databox/databox_normal.png");
//    databoxFoe = IMG_Load("./Pictures/Battle/Databox/databox_normal_foe.png");
//    pkmnAlly = IMG_Load("./Pictures/Pokemon/Battle/023b.png");
//    pkmnFoe = IMG_Load("./Pictures/Pokemon/Battle/045.png");
//    choiceCursor = IMG_Load("./Pictures/Battle/choiceCursor.png");
//    partyBG = IMG_Load("./Pictures/Characters/Trainer/Party/bg.png");
//    partySlot1 = IMG_Load("./Pictures/Characters/Trainer/Party/panel_round.png");
//    partySlot2 = IMG_Load("./Pictures/Characters/Trainer/Party/panel_rect.png");
//    partySlot3 = IMG_Load("./Pictures/Characters/Trainer/Party/panel_rect.png");
//    partySlot4 = IMG_Load("./Pictures/Characters/Trainer/Party/panel_rect.png");
//    partySlot5 = IMG_Load("./Pictures/Characters/Trainer/Party/panel_rect.png");
//    partySlot6 = IMG_Load("./Pictures/Characters/Trainer/Party/panel_blank.png");
//    partyPKMN1 = IMG_Load("./Pictures/Pokemon/Icon/icon001.png");
//    partyPKMNHP1 = IMG_Load("./Pictures/Characters/Trainer/Party/overlay_hp_back.png");
//    textCommandLarger = IMG_Load("./Pictures/Battle/choice 1.png");
//    //SDL_SetColorKey(choiceCursor, SDL_SRCCOLORKEY, SDL_MapRGB(screen->format, 0, 0, 0));//255, 255, 255));
//    SDL_Color textColor = {50, 50, 50};
//    textCommand = TTF_RenderText_Blended(font, "What will .. do ?", textColor);
//    textPkmnAllyName = TTF_RenderText_Blended(font, "Rafflesia", textColor);
//    textPkmnFoeName = TTF_RenderText_Blended(font, "Hitler", textColor);
//    textHPAlly = TTF_RenderText_Blended(fontSmall, "129/129", textColor);
//    textMove1 = TTF_RenderText_Blended(font, "Move 1", textColor);
//    textMove2 = TTF_RenderText_Blended(font, "Move 2", textColor);
//    textMove3 = TTF_RenderText_Blended(font, "Move 3", textColor);
//    textMove4 = TTF_RenderText_Blended(font, "Move 4", textColor);
//    bool stop = false;
//    SDL_Event event;
//    while (!stop)
//    {
//        SDL_WaitEvent(&event);
//        switch(event.type)
//        {
//            case SDL_QUIT:
//                {
//                    stop = true;
//                    break;
//                }
//            case SDL_KEYDOWN:
//                {
//                    switch(event.key.keysym.sym)
//                    {
//                    case SDLK_LEFT:
//                        {
//                            if(choiceMode == "FIGHT")
//                            {
//                                if(choiceCursorpos.x == 15)
//                                {
//                                    choiceCursorpos.x += 100;
//                                }
//                                else
//                                {
//                                    choiceCursorpos.x = 15;
//                                }
//                            }
//                            else
//                            {
//                                if(choiceCursorpos.x == 250)
//                                {
//                                    choiceCursorpos.x += 130;
//                                }
//                                else
//                                {
//                                    choiceCursorpos.x = 250;
//                                }
//                            }
//                            break;
//                        }
//                    case SDLK_RIGHT:
//                        {
//                            if(choiceMode == "FIGHT")
//                            {
//                                if(choiceCursorpos.x == 15)
//                                {
//                                    choiceCursorpos.x += 100;
//                                }
//                                else
//                                {
//                                    choiceCursorpos.x = 15;
//                                }
//                            }
//                            else
//                            {
//                                if(choiceCursorpos.x == 250)
//                                {
//                                    choiceCursorpos.x += 130;
//                                }
//                                else
//                                {
//                                    choiceCursorpos.x = 250;
//                                }
//                            }
//                            break;
//                        }
//                    case SDLK_UP:
//                        {
//                            if(choiceMode == "FIGHT")
//                            {
//                                if(choiceCursorpos.y == 310)
//                                {
//                                    choiceCursorpos.y += 30;
//                                }
//                                else
//                                {
//                                    choiceCursorpos.y = 310;
//                                }
//                            }
//                            else
//                            {
//                                if(choiceCursorpos.y == 290)
//                                {
//                                    choiceCursorpos.y += 48;
//                                }
//                                else
//                                {
//                                    choiceCursorpos.y = 290;
//                                }
//                            }
//                            break;
//                        }
//                    case SDLK_DOWN:
//                        {
//                            if(choiceMode == "FIGHT")
//                            {
//                                if(choiceCursorpos.y == 310)
//                                {
//                                    choiceCursorpos.y += 30;
//                                }
//                                else
//                                {
//                                    choiceCursorpos.y = 310;
//                                }
//                            }
//                            else
//                            {
//                                if(choiceCursorpos.y == 290)
//                                {
//                                    choiceCursorpos.y += 48;
//                                }
//                                else
//                                {
//                                    choiceCursorpos.y = 290;
//                                }
//                            }
//                            break;
//                        }
//                    case SDLK_RETURN:
//                        {
//                            if(choiceMode == "")
//                            {
//                                if(choiceCursorpos.x == 250 && choiceCursorpos.y == 290)
//                                {
//                                    choiceMode = "FIGHT";
//                                    choiceCursor = IMG_Load("./Pictures/Battle/selarrow.png");
//                                    choiceCursorpos.x = 15;
//                                    choiceCursorpos.y = 310;
//                                }
//                                else if(choiceCursorpos.x != 250 && choiceCursorpos.y == 290)
//                                {
//                                    choiceMode = "BAG";
//                                }
//                                else if(choiceCursorpos.x == 250 && choiceCursorpos.y != 290)
//                                {
//                                    choiceMode = "POKEMON";
//                                }
//                                else
//                                {
//                                    choiceMode = "RUN";
//                                }
//                            }
//                            break;
//                        }
//                    case SDLK_BACKSPACE:
//                        {
//                            choiceMode = "";
//                            choiceCursorpos.x = 250;
//                            choiceCursorpos.y = 290;
//                            choiceCursor = IMG_Load("./Pictures/Battle/choiceCursor.png");
//                            break;
//                        }
//                    }
//                }
//        }
//        if(choiceMode == "POKEMON")
//        {
//            SDL_BlitSurface(partyBG, NULL, screen, &partyBGpos);
//            SDL_BlitSurface(partySlot1, NULL, screen, &partySlot1pos);
//            SDL_BlitSurface(partySlot2, NULL, screen, &partySlot2pos);
//            SDL_BlitSurface(partySlot3, NULL, screen, &partySlot3pos);
//            SDL_BlitSurface(partySlot4, NULL, screen, &partySlot4pos);
//            SDL_BlitSurface(partySlot5, NULL, screen, &partySlot5pos);
//            SDL_BlitSurface(partySlot6, NULL, screen, &partySlot6pos);
//            SDL_BlitSurface(partyPKMN1, NULL, screen, &partyPKMN1pos);
//            SDL_BlitSurface(partyPKMNHP1, NULL, screen, &partyPKMNHP1pos);
//        }
//        else
//        {
//            SDL_BlitSurface(battleCommandBackgroud, NULL, screen, &battleCommandBackgroudpos);
//            SDL_BlitSurface(databoxAlly, NULL, screen, &databoxAllypos);
//            SDL_BlitSurface(databoxFoe, NULL, screen, &databoxFoepos);
//            SDL_BlitSurface(pkmnAlly, NULL, screen, &pkmnAllypos);
//            SDL_BlitSurface(pkmnFoe, NULL, screen, &pkmnFoepos);
//            if(choiceMode == "FIGHT")
//            {
//                SDL_BlitSurface(textMove1, NULL, screen, &textMove1pos);
//                SDL_BlitSurface(textMove2, NULL, screen, &textMove2pos);
//                SDL_BlitSurface(textMove3, NULL, screen, &textMove3pos);
//                SDL_BlitSurface(textMove4, NULL, screen, &textMove4pos);
//            }
//            else
//            {
//                SDL_BlitSurface(textCommand, NULL, screen, &textCommandpos);
//            }
//            SDL_BlitSurface(textCommandLarger, NULL, screen, &textCommandLargerpos);
//            SDL_BlitSurface(textPkmnAllyName, NULL, screen, &textPkmnAllyNamepos);
//            SDL_BlitSurface(textPkmnFoeName, NULL, screen, &textPkmnFoeNamepos);
//            SDL_BlitSurface(textHPAlly, NULL, screen, &textHPAllypos);
//            SDL_BlitSurface(choiceCursor, NULL, screen, &choiceCursorpos);
//        }
//        SDL_Flip(screen);
//        SDL_Delay(10);
//    }
//    SDL_FreeSurface(battleCommandBackgroud);
//    SDL_FreeSurface(pkmnAlly);
//    SDL_FreeSurface(pkmnFoe);
//    SDL_FreeSurface(databoxAlly);
//    SDL_FreeSurface(databoxFoe);
//    SDL_FreeSurface(textCommand);
//    SDL_FreeSurface(textPkmnAllyName);
//    SDL_FreeSurface(textPkmnFoeName);
//    SDL_FreeSurface(textHPAlly);
//    SDL_FreeSurface(choiceCursor);
//    SDL_FreeSurface(textMove1);
//    SDL_FreeSurface(textMove2);
//    SDL_FreeSurface(textMove3);
//    SDL_FreeSurface(textMove4);
//    SDL_FreeSurface(partyBG);
//    SDL_FreeSurface(partySlot1);
//    SDL_FreeSurface(partySlot2);
//    SDL_FreeSurface(partySlot3);
//    SDL_FreeSurface(partySlot4);
//    SDL_FreeSurface(partySlot5);
//    SDL_FreeSurface(partySlot6);
//    SDL_Quit();
//    TTF_CloseFont(font);
//    TTF_Quit();
//    return EXIT_SUCCESS;
//}
//}


int main(int argc, char* argv[])
{
    seed();
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    SDL_WM_SetIcon(IMG_Load("pokeball.png"), NULL);
    SDL_Surface *screen = NULL;
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Pokemon - MEILAC Adrien", NULL);
    if(screen == NULL)
    {
        std::cout << "Error when loading screen" << std::endl;
        exit(EXIT_FAILURE);
    }
    Place place("ROAD21");
    Player player;
    Pokemon* pkmn = player.getPokemon(4);
    BattleWildPokemon battle(screen, player, place, pkmn);
    battle.start();
    SDL_Quit();
    TTF_Quit();


    return EXIT_SUCCESS;
}

