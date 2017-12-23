#include <iostream>
#include <vector>
#include <string>
#include "Battle/Player.h"
#include "Field/Place.h"
#include "Pokemon/Pokemon.h"
#include "Battle/BattleWildPokemon.h"
#include "Pokemon/Flag.h"

using namespace PKMN;

int main()
{
    Place place("ROAD21");
    Player player;
    Pokemon pkmn("4");
    BattleWildPokemon battle(player, place, pkmn);
    battle.launch();
    return 0;
}
