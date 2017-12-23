#ifndef PKMN_BATTLEWILDPOKEMON_H_INCLUDED
#define PKMN_BATTLEWILDPOKEMON_H_INCLUDED

#include "../Pokemon/Pokemon.h"
#include "../Field/Weather.h"
#include "../Field/Place.h"
#include "Player.h"

#include "../FilePath.h"

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>


namespace PKMN
{
    class BattleWildPokemon;
}

class PKMN::BattleWildPokemon
{
public :

    BattleWildPokemon(); /// Place aleatoire pkmn
    BattleWildPokemon(Player& player, Place place, Pokemon wildPkmn);
    ~BattleWildPokemon();

    void throwNewPokemon(unsigned int i = 0);
    void foeIsDead();
    void choiceMove();
    void attack(Pokemon &Att, Pokemon &Def, Move &moveUsed);
    unsigned int dealDamage(Pokemon &pkmn, unsigned int damagePoint);
    void launch();
    void printPokemon(const Pokemon &pkmn) const;

private:

    Player m_Player;
    Place m_Place;
    Pokemon m_WildPkmn;

    Pokemon m_AllyPkmn;
    unsigned int m_i_ActivePkmn;
    Weather m_Weather;
    /// Place / background
};

#endif // BATTLEWILDPOKEMON_H_INCLUDED
