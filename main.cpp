#include "PKMN_Type.h"
#include "PKMN_LevelingRate.h"
#include "PKMN_Moves.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "L'effet est de " << typeEffectiveness(FIRE, GRASS) << ", ";
    cout  << typeEffectivenessMessage(typeEffectiveness(FIRE, GRASS));
    cout << endl << endl;
    for(unsigned int i=1; i <= 100; i++)
    {
        cout << "L'exp necessaire au niveau " << i << " est " << expLevel(SLOW, i) << endl;
    }

    PKMN_Moves MEGAHORN(1, "Megahorn", "000", 120, BUG, "Physical", 85, 10, 0, "00", 0, "abef",
                        "Using its tough and impressive horn,the user rams into the target with no letup.");
    MEGAHORN.print();
    return 0;
}
