#ifndef PKMN_BATTLE_H_INCLUDED
#define PKMN_BATTLE_H_INCLUDED

#include "../Pokemon/Pokemon.h"
#include "../Field/Weather.h"
#include "../Field/Place.h"
#include "../Battle/Player.h"

#include "../FilePath.h"

#include <string>
#include <iostream>
#include <cmath>
#include "../Tools/Random.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#define SET_BATTLE_FONT_AND_COLOR \
    TTF_Font *font = NULL, *fontSmall = NULL; \
    font = TTF_OpenFont("./Fonts/pkmndp.ttf", 26); \
    fontSmall = TTF_OpenFont("./Fonts/pkmndp.ttf", 20); \
    SDL_Color textColor = {50, 50, 50}; \

#define SET_BATTLE_BACKGROUND \
    SDL_Surface *battleBackgroud = NULL, *battleAllyBase = NULL, *battleFoeBase = NULL;\
    SDL_Rect battleBackgroudpos, battleAllyBasepos, battleAllyBaseposcopy, battleFoeBasepos; \
    battleBackgroudpos.x = 0; \
    battleBackgroudpos.y = 0; \
    battleAllyBasepos.x = -120; \
    battleAllyBasepos.y = 240; \
    battleAllyBaseposcopy.x = battleAllyBasepos.x; \
    battleAllyBaseposcopy.y = battleAllyBasepos.y; \
    battleFoeBasepos.x = 260; \
    battleFoeBasepos.y = 110; \
    battleBackgroud = IMG_Load("./Pictures/Battle/Background/battleBGchampion.png"); \
    battleFoeBase = IMG_Load("./Pictures/Battle/Enemy base/enemybaseChampion.png"); \
    battleAllyBase = IMG_Load("./Pictures/Battle/Player base/playerbaseChampion.png");

#define SET_BATTLE_MENU(A) \
    SDL_Surface *battleCommandBackgroud = NULL; \
    SDL_Rect battleCommandBackgroudpos; \
    battleCommandBackgroudpos.x = 0; \
    battleCommandBackgroudpos.y = 12 * 32 - 92; \
    battleCommandBackgroud = IMG_Load(A); ///"./Pictures/Battle/choice 1.png"

#define SET_BATTLE_BATTLERS \
    SDL_Surface *pkmnAlly = NULL, *pkmnFoe = NULL; \
    SDL_Rect pkmnAllypos, pkmnFoepos; \
    pkmnAllypos.x = 60; \
    pkmnAllypos.y = 130; \
    pkmnFoepos.x = 310; \
    pkmnFoepos.y = 40; \
    pkmnAlly = IMG_Load(Ally->getBattleImage(false).c_str()); \
    pkmnFoe = IMG_Load(Foe->getBattleImage(true).c_str()); \

#define SET_BATTLE_DATABOX \
    /** Life bars **/\
    SDL_Surface*databoxAlly = NULL, *databoxFoe = NULL, *lifeBarAlly = NULL, *lifeBarFoe = NULL; \
    SDL_Rect databoxAllypos, databoxFoepos, lifeBarAllypos, lifeBarFoepos; \
    databoxAllypos.x = 16 * 32 - 260; \
    databoxAllypos.y = 200; \
    databoxFoepos.x = 0; \
    databoxFoepos.y = 60; \
    lifeBarAllypos.x = databoxAllypos.x + 136; \
    lifeBarAllypos.y = databoxAllypos.y + 40; \
    lifeBarFoepos.x = databoxFoepos.x + 118; \
    lifeBarFoepos.y = databoxFoepos.y + 40; \
    databoxAlly = IMG_Load("./Pictures/Battle/Databox/databox_normal.png"); \
    databoxFoe = IMG_Load("./Pictures/Battle/Databox/databox_normal_foe.png"); \
    int lifeBarAllyLength = static_cast<int>(96.0 * static_cast<double>(Ally->getCurHP())/static_cast<double>(Ally->getNormalHP())); \
    lifeBarAlly = SDL_CreateRGBSurface(SDL_HWSURFACE, lifeBarAllyLength, 6, 32, 0, 0, 0, 0); \
    if(Ally->getCurHP() < 0.2 * Ally->getNormalHP()) \
    { \
        SDL_FillRect(lifeBarAlly, NULL, SDL_MapRGB(lifeBarAlly->format, 206, 0, 0)); \
    } \
    else if(Ally->getCurHP() < 0.5 * Ally->getNormalHP()) \
    { \
        SDL_FillRect(lifeBarAlly, NULL, SDL_MapRGB(lifeBarAlly->format, 206, 206, 0)); \
    } \
    else \
    { \
        SDL_FillRect(lifeBarAlly, NULL, SDL_MapRGB(lifeBarAlly->format, 0, 206, 0)); \
    } \
    int lifeBarFoeLength = static_cast<int>(96.0 * static_cast<double>(Foe->getCurHP())/static_cast<double>(Foe->getNormalHP())); \
    lifeBarFoe = SDL_CreateRGBSurface(SDL_HWSURFACE, lifeBarFoeLength, 6, 32, 0, 0, 0, 0); \
    if(Foe->getCurHP() < 0.2 * Foe->getNormalHP()) \
    { \
        SDL_FillRect(lifeBarFoe, NULL, SDL_MapRGB(lifeBarFoe->format, 206, 0, 0)); \
    } \
    else if(Foe->getCurHP() < 0.5 * Foe->getNormalHP()) \
    { \
        SDL_FillRect(lifeBarFoe, NULL, SDL_MapRGB(lifeBarFoe->format, 206, 206, 0)); \
    } \
    else \
    { \
        SDL_FillRect(lifeBarFoe, NULL, SDL_MapRGB(lifeBarFoe->format, 0, 206, 0)); \
    } \
    /** Text about battlers **/\
    SDL_Surface *textPkmnAllyName = NULL, *textPkmnFoeName = NULL, *textHPAlly = NULL, \
                *textPkmnAllyLvl = NULL, *textPkmnFoeLvl = NULL; \
    SDL_Rect textPkmnAllyNamepos, textPkmnFoeNamepos, textHPAllypos, textPkmnAllyLvlpos, textPkmnFoeLvlpos; \
    textPkmnAllyNamepos.x = 16 * 32 - 260 + 40; \
    textPkmnAllyNamepos.y = 210; \
    textPkmnFoeNamepos.x = 7; \
    textPkmnFoeNamepos.y = 70; \
    textHPAllypos.x = 16 * 32 - 110; \
    textHPAllypos.y = 253; \
    textPkmnAllyLvlpos.x = 16 * 32 - 260 + 40 + 140; \
    textPkmnAllyLvlpos.y = 210; \
    textPkmnFoeLvlpos.x = 7 + 140; \
    textPkmnFoeLvlpos.y = 70; \
    textPkmnAllyName = TTF_RenderText_Blended(font, Ally->getName().c_str(), textColor); \
    textPkmnFoeName = TTF_RenderText_Blended(font, Foe->getName().c_str(), textColor); \
    textHPAlly = TTF_RenderText_Blended(fontSmall, \
                                        (PKMN::int_to_string(Ally->getCurHP()) \
                                        + "/" \
                                        + PKMN::int_to_string(Ally->getNormalHP())).c_str() \
                                        , textColor); \
    textPkmnAllyLvl = TTF_RenderText_Blended(font, ("Lvl." + PKMN::int_to_string(Ally->getLevel())).c_str(), textColor); \
    textPkmnFoeLvl = TTF_RenderText_Blended(font, ("Lvl." + PKMN::int_to_string(Foe->getLevel())).c_str(), textColor); \

#define BLIT_BATTLE_BACKGROUND \
    SDL_BlitSurface(battleBackgroud, NULL, screen, &battleBackgroudpos); \
    SDL_BlitSurface(battleAllyBase, NULL, screen, &battleAllyBaseposcopy); \
    battleAllyBaseposcopy.x = battleAllyBasepos.x; \
    battleAllyBaseposcopy.y = battleAllyBasepos.y; \
    SDL_BlitSurface(battleFoeBase, NULL, screen, &battleFoeBasepos);

#define BLIT_BATTLE_MENU \
    SDL_BlitSurface(battleCommandBackgroud, NULL, screen, &battleCommandBackgroudpos);

#define BLIT_BATTLE_BATTLERS \
    SDL_BlitSurface(pkmnAlly, NULL, screen, &pkmnAllypos); \
    SDL_BlitSurface(pkmnFoe, NULL, screen, &pkmnFoepos);

#define BLIT_BATTLE_DATABOX \
    SDL_BlitSurface(databoxAlly, NULL, screen, &databoxAllypos); \
    SDL_BlitSurface(databoxFoe, NULL, screen, &databoxFoepos); \
    SDL_BlitSurface(lifeBarAlly, NULL, screen, &lifeBarAllypos); \
    SDL_BlitSurface(lifeBarFoe, NULL, screen, &lifeBarFoepos); \
    SDL_BlitSurface(textPkmnAllyName, NULL, screen, &textPkmnAllyNamepos); \
    SDL_BlitSurface(textPkmnFoeName, NULL, screen, &textPkmnFoeNamepos); \
    SDL_BlitSurface(textHPAlly, NULL, screen, &textHPAllypos); \
    SDL_BlitSurface(textPkmnAllyLvl, NULL, screen, &textPkmnAllyLvlpos); \
    SDL_BlitSurface(textPkmnFoeLvl, NULL, screen, &textPkmnFoeLvlpos);

#define FREE_BATTLE_BACKGROUND \
    SDL_FreeSurface(battleAllyBase); \
    SDL_FreeSurface(battleFoeBase); \
    SDL_FreeSurface(battleCommandBackgroud); \

#define FREE_BATTLE_MENU \
    SDL_FreeSurface(battleCommandBackgroud);

#define FREE_BATTLE_DATABOX \
    SDL_FreeSurface(databoxAlly); \
    SDL_FreeSurface(databoxFoe); \
    SDL_FreeSurface(lifeBarAlly); \
    SDL_FreeSurface(lifeBarFoe); \
    SDL_FreeSurface(textPkmnAllyName); \
    SDL_FreeSurface(textPkmnFoeName); \
    SDL_FreeSurface(textHPAlly); \
    SDL_FreeSurface(textPkmnAllyLvl); \
    SDL_FreeSurface(textPkmnFoeLvl);

#define FREE_BATTLE_BATTLERS \
    SDL_FreeSurface(pkmnAlly); \
    SDL_FreeSurface(pkmnFoe);

#define FREE_BATTLE_FONT \
    TTF_CloseFont(font); \
    TTF_CloseFont(fontSmall);

extern "C"
{

void Battle_ScreenMessage(SDL_Surface* screen,
                          PKMN::Pokemon* Ally,
                          PKMN::Pokemon* Foe,
                          const PKMN::Place& place,
                          std::string message,
                          bool isAllyAlreadyLauched,
                          bool isFoeAlreadyLauched);
    /** \brief
     *
     * \param screen SDL_Surface*
     * \param Ally PKMN::Pokemon*
     * \param Foe PKMN::Pokemon*
     * \param place const PKMN::Place&
     * \param message std::string
     * \return extern "C" void
     *
     */

int Battle_FightMenu(SDL_Surface* screen,
                     PKMN::Pokemon* Ally,
                     PKMN::Pokemon* Foe,
                     const PKMN::Place& place);
    /** \brief
     *
     * \param screen SDL_Surface*
     * \param Ally PKMN::Pokemon*
     * \param Foe PKMN::Pokemon*
     * \param place const PKMN::Place&
     * \return int
     *
     */

std::string Battle_MainMenu(SDL_Surface* screen,
                            PKMN::Pokemon* Ally,
                            PKMN::Pokemon* Foe,
                            const PKMN::Place& place);
    /** \brief
     *
     * \param screen SDL_Surface*
     * \param Ally PKMN::Pokemon*
     * \param Foe PKMN::Pokemon*
     * \param place const PKMN::Place&
     * \return std::string
     *
     */

void Battle_HPAllyDecrease(SDL_Surface* screen,
                           PKMN::Pokemon* Ally,
                           PKMN::Pokemon* Foe,
                           const PKMN::Place& place,
                           int damagePoint);
    /** \brief
     *
     * \param screen SDL_Surface*
     * \param Ally PKMN::Pokemon*
     * \param Foe PKMN::Pokemon*
     * \param place const PKMN::Place&
     * \param damagePoint int
     *
     */

void Battle_HPFoeDecrease(SDL_Surface* screen,
                          PKMN::Pokemon* Ally,
                          PKMN::Pokemon* Foe,
                          const PKMN::Place& place,
                          int damagePoint); /// Damage point are under current HP
    /** \brief
     *
     * \param screen SDL_Surface*
     * \param Ally PKMN::Pokemon*
     * \param Foe PKMN::Pokemon*
     * \param place const PKMN::Place&
     * \param damagePoint int
     *
     */

void Battle_LauchAllyPokemon(SDL_Surface* screen,
                             PKMN::Pokemon* Ally,
                             PKMN::Pokemon* Foe,
                             const PKMN::Place& place,
                             bool isFoeAlreadyLauched);

void Battle_LauchFoePokemon(SDL_Surface* screen,
                            PKMN::Pokemon* Ally,
                            PKMN::Pokemon* Foe,
                            const PKMN::Place& place,
                            bool isAllyAlreadyLauched);

void Battle_DeathFoePokemon(SDL_Surface* screen,
                            PKMN::Pokemon* Ally,
                            PKMN::Pokemon* Foe,
                            const PKMN::Place& place,
                            bool isAllyAlreadyLauched);

void Battle_DeathAllyPokemon(SDL_Surface* screen,
                             PKMN::Pokemon* Ally,
                             PKMN::Pokemon* Foe,
                             const PKMN::Place& place,
                             bool isFoeAlreadyLauched);

void Battle_FadeToBlack(SDL_Surface* screen,
                        const PKMN::Place& place);

int Battle_SwapMenu(SDL_Surface* screen,
                    PKMN::Player* player,
                    bool aNewPokemonMustBeSelected);

}

#endif // BATTLEMODE_H_INCLUDED
