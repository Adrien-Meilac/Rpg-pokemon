#include <iostream>
#include <vector>
#include <string>
#include "PKMN_Pokemon/PKMN_Type.h"
#include "PKMN_Pokemon/PKMN_Moves.h"
#include "PKMN_Pokemon/PKMN_ExpAndLevel.h"


using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    PKMN_Type t("FIRE");
    PKMN_Type t2("DARK");
    t2.print();
    cout << t.effectiveness(t2) << endl;
    cout << t.getName() << endl;
    cout << t2.effectiveness(t) << endl;
    PKMN_Moves t3("BEATUP");
    PKMN_ExpAndLevel lvl("Parabolic", 43);
    lvl.print();
    return 0;
}
