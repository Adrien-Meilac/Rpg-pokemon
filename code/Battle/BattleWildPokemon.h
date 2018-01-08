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
    BattleWildPokemon(SDL_Surface* screen, Player player, Place place);
    ~BattleWildPokemon();

    void start();
        /** \brief launch the battle
         *
         * \return void
         *
         */

    Player getBackPlayer();
    /** \brief return the player once the battle is finished
     *
     * \return Player
     *
     */


private:

    void mainMenu();
        /** \brief launch printMainMenu and handle flag
         *
         * \return bool
         *
         */

    bool runAway();
        /** \brief launch the run away menu
         *
         * \return bool
         *
         */

    bool fightMenu();
        /** \brief launch printFightMenu and handle flag
         *
         * \return bool
         *
         */

    void launchTurn(unsigned int moveNumber);
        /** \brief launch foe and ally attack once they have been selected (handle priority)
         *
         * \param moveNumber unsigned int : number of the move selected for ally
         * \return void
         *
         */

    bool swapPokemonMenu(bool isNecessary);
        /** \brief lauch the swap menu
         *
         * \param isNecessary bool : is it necessary to change of pokemon
         * \return bool
         *
         */

    void throwNewPokemon();
        /** \brief throw a new ally pokemon
         *
         * \return void
         *
         */

    void foePokemonDie();
        /** \brief Make the ally pokemon die
         *
         * \return void
         *
         */

    void allyPokemonDie();
        /** \brief Make the ally pokemon die
         *
         * \return void
         *
         */

    std::pair<int,std::string> attack(PKMN::Pokemon* Att, PKMN::Pokemon* Def, PKMN::Move* moveUsed);
        /** \brief Use a move and deal damages
         *
         * \param moveNumber unsigned int : pos of the selected move
         * \return std::pair<int,std::string> : (damage, message of effectiveness)
         *
         */

    void foeAttack(unsigned int moveNumberFoe);
        /** \brief Use a move and deal damages
         *
         * \param moveNumberFoe unsigned int : pos of the selected move
         * \return void
         *
         */

    void allyAttack(unsigned int moveNumber);
        /** \brief Use a move and deal damages
         *
         * \param moveNumber unsigned int : pos of the selected move
         * \return void
         *
         */

    std::pair<int,std::string> calculateDamage(PKMN::Pokemon* Att, PKMN::Pokemon* Def, PKMN::Move* moveUsed); /// NO PRINT
        /** \brief Calculate damage (formula)
         *
         * \param Att PKMN::Pokemon* : Pokemon attacking
         * \param Def PKMN::Pokemon* : Pokemon receiving attack
         * \param moveUsed PKMN::Move* : attack object
         * \return std::pair<int,std::string> : damage , message of effectiveness
         *
         */

    int calculateRealDamage(Pokemon* pkmn, unsigned int damagePoint); /// NO PRINT
        /** \brief Calculate real damage (bound the damage)
         *
         *
         */


    std::string weatherMessage(); /// NO PRINT
        /** \brief Calculate the weather message to print
         *
         * \return std::string : string to print
         *
         */

    void playerRunAway();
        /** \brief Launch the run away action
         *
         * \return bool
         *
         */

    bool battleCanContinue();
        /** \brief Can the battle continue ?
         *
         * \return bool
         *
         */

    bool playerCannotContinue();
        /** \brief Is the player not able to continue ?
         *
         * \return bool
         *
         */

    bool playerCanContinue();
        /** \brief Can the player continue ?
         *
         * \return bool
         *
         */

    bool foeCannotContinue();
        /** \brief Can the Wild pokemon continue ?
         *
         * \return bool
         *
         */

    bool foeCanContinue();
        /** \brief Is the player not able to continue ?
         *
         * \return bool
         *
         */

    bool allyCanContinue();
        /** \brief Can the ally pokemon continue ?
         *
         * \return bool
         *
         */

    bool allyCannotContinue();
        /** \brief Is the ally cannot able to continue ?
         *
         * \return bool
         *
         */

    void print(std::string message, bool isAllyAlreadyLauched, bool isFoeAlreadyLauched);
        /** \brief use Graphics function, print a message in the battle screen
         *
         * \param message std::string
         * \param isAllyAlreadyLauched bool
         * \param isFoeAlreadyLauched bool
         *
         */
    void printFadeToBlack();
        /** \brief use Graphics function, print a fade to black effect to launch battle
         *
         *
         */

    void printDeathAllyPokemon(bool isFoeAlreadyLauched);
        /** \brief use Graphics function, print the death of an ally pokemon
         *
         * \param isFoeAlreadyLauched bool : to know if we have to show the foe picture
         *
         */

    void printDeathFoePokemon(bool isAllyAlreadyLauched);
        /** \brief use Graphics function, print the death of a foe pokemon
         *
         * \param isAllyAlreadyLauched bool  : to know if we have to show the ally picture
         *
         */
    void printHPAllyDecrease(int damagePoint);
        /** \brief use Graphics function, print the decrease of HP
         *
         * \param damagePoint bool : damage to substract (already real damage)
         *
         */

    void printHPFoeDecrease(int damagePoint);
        /** \brief use Graphics function, print the decrease of HP
         *
         * \param damagePoint int : damage to substract (already real damage)
         *
         */

    void printLauchAllyPokemon(bool isFoeAlreadyLauched);
        /** \brief use Graphics function, effect when launching a pokemon
         *
         * \param isFoeAlreadyLauched bool : to know if we have to show the ally picture
         *
         */

    void printLauchFoePokemon(bool isAllyAlreadyLauched);
        /** \brief use Graphics function, effect when launching a pokemon
         *
         * \param isAllyAlreadyLauched bool : to know if we have to show the ally picture
         *
         */

    void gameOver();
        /** \brief print the Game Over
         *
         *
         */

    int printSwapMenu(bool aNewPokemonMustBeSelected);
        /** \brief use Graphics function, print the swap menu
         *
         * \param aNewPokemonMustBeSelected bool : does one have to select a pokemon ?
         * \return int
         *
         */

    int printFightMenu();
        /** \brief use Graphics function, print the fight menu
         *
         * \return int : flag to call the next action, this int is the position of the selected move
         *
         */

    std::string printMainMenu();
        /** \brief use Graphics function, print the main menu
         *
         * \return std::string : flag to call the next action
         *
         */

    SDL_Surface* m_screen; /// screen where to print informations

    Player m_Player;
    Pokemon* m_WildPkmn; /// Wild pokemon
    Pokemon* m_AllyPkmn; /// Always equal to m_Player.getPokemon(0)

    Place m_Place;
    Weather m_Weather;
    int m_WeatherCount;  /// Place / background

    bool m_PlayerRunAway;
};

#endif // BATTLEWILDPOKEMON_H_INCLUDED
