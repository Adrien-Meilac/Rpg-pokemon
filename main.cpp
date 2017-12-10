#include <iostream>
#include "PKMN_Tools/PKMN_Conversion.h"
#include "PKMN_Tools/PKMN_StatSet.h"
#include "PKMN_Tools/PKMN_VectorMethod.h"
#include "PKMN_Tools/PKMN_Table.h"
#include "PKMN_Pokemon/PKMN_Type.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    PKMN_Type t("FIRE");
    PKMN_Type t2("WATER");
    cout << t.effectiveness(t2) << endl;
    cout << t.getName() << endl;
    cout << t2.effectiveness(t) << endl;
    return 0;
}
