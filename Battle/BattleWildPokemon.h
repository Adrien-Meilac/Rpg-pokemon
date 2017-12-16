#ifndef PKMN_BATTLEWILDPOKEMON_H_INCLUDED
#define PKMN_BATTLEWILDPOKEMON_H_INCLUDED

#include "../Pokemon/Pokemon.h"
#include "../Field/Weather.h"
#include "../Field/Place.h"
#include "Player.h"


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

    void start();
    void stop();

private:

    Player m_Player;
    Pokemon m_WildPkmn;
    Place m_Place;
    Weather m_Weather;
    /// Place / background
};

#endif // BATTLEWILDPOKEMON_H_INCLUDED
