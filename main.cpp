#include <iostream>
#include <vector>
#include <string>
#include "Battle/Player.h"
#include "Tools/Conversion.h"
#include "Field/Place.h"
#include "Pokemon/Pokemon.h"
#include "Battle/BattleWildPokemon.h"

using namespace PKMN;

int main()
{
    Place place("ROAD21");
    Player player;
    Pokemon pkmn("RAICHU");
    BattleWildPokemon battle(player, place, pkmn);
    battle.start();
    battle.stop();
    return 0;
}
