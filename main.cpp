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
    a.printStat();
    PKMN_Pokemon b("2");
    b.printStat();
    a.attack(b, 3);
    a.printStat();
    b.printStat();
    a.attack(b, 2);
    a.printStat();
    b.printStat();
    a.messageGetExp(a.expGained(b));
    return 0;
}
