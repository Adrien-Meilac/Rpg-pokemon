#include <iostream>
#include <vector>
#include <string>
#include "PKMN_Pokemon/PKMN_Type.h"
#include "PKMN_Pokemon/PKMN_Moves.h"
#include "PKMN_Pokemon/PKMN_ExpAndLevel.h"
#include "PKMN_Pokemon/PKMN_Species.h"
#include "PKMN_Pokemon/PKMN_Pokemon.h"


using namespace std;

int main()
{
    PKMN_Pokemon a("1");
    PKMN_Pokemon b("2");
    a.attack(b, 1);
    return 0;
}
