#ifndef PKMN_BATTLEWILDPOKEMON_H_INCLUDED
#define PKMN_BATTLEWILDPOKEMON_H_INCLUDED

#include "../Pokemon/Pokemon.h"
#include "../Field/Weather.h"
#include "../Field/Place.h"
#include "Player.h"

#include "../FilePath.h"

#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include "../Tools/Random.h"

#include "../Graphics/Battle.h"

namespace PKMN
{
    class BattleWildPokemon;
}

class PKMN::BattleWildPokemon
{
public :

    BattleWildPokemon(); /// Place aleatoire pkmn
    BattleWildPokemon(SDL_Surface* screen, Player& player, Place place, Pokemon* wildPkmn);
    ~BattleWildPokemon();

    void start();


private:

    void mainMenu();
    bool runAway();
    bool fightMenu();
    void launchTurn(unsigned int moveNumber);
    bool swapPokemonMenu(bool isNecessary);

    void throwNewPokemon();

    void foePokemonDie();
    void allyPokemonDie();

    std::pair<int,std::string> attack(PKMN::Pokemon* Att, PKMN::Pokemon* Def, PKMN::Move* moveUsed);
    void foeAttack(unsigned int moveNumberFoe);
    void allyAttack(unsigned int moveNumber);

    std::pair<int,std::string> calculateDamage(PKMN::Pokemon* Att, PKMN::Pokemon* Def, PKMN::Move* moveUsed); /// NO PRINT
    int calculateRealDamage(Pokemon* pkmn, unsigned int damagePoint); /// NO PRINT
    std::string weatherMessage(); /// NO PRINT

    void playerRunAway();

    bool battleCanContinue();
    bool playerCannotContinue();
    bool playerCanContinue();
    bool foeCannotContinue();
    bool foeCanContinue();
    bool allyCanContinue();
    bool allyCannotContinue();

    void print(std::string message, bool isAllyAlreadyLauched, bool isFoeAlreadyLauched);
    void printFadeToBlack();
    void printDeathAllyPokemon(bool isFoeAlreadyLauched);
    void printDeathFoePokemon(bool isAllyAlreadyLauched);
    void printHPAllyDecrease(int damagePoint);
    void printHPFoeDecrease(int damagePoint);
    void printLauchAllyPokemon(bool isFoeAlreadyLauched);
    void printLauchFoePokemon(bool isAllyAlreadyLauched);

    void gameOver();

    int printSwapMenu(bool aNewPokemonMustBeSelected);
    int printFightMenu();
    std::string printMainMenu();


    SDL_Surface* m_screen;

    Player m_Player;
    Pokemon* m_WildPkmn;
    Pokemon* m_AllyPkmn; /// Always equal to m_Player.getPokemon(0)

    Place m_Place;
    Weather m_Weather;
    int m_WeatherCount;  /// Place / background

    bool m_PlayerRunAway;
};

#endif // BATTLEWILDPOKEMON_H_INCLUDED
