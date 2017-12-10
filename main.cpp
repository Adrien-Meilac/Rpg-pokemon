#include <iostream>
#include "PKMN_Tools/PKMN_Conversion.h"
#include "PKMN_Tools/PKMN_StatSet.h"
#include "PKMN_Tools/PKMN_VectorMethod.h"
#include "PKMN_Tools/PKMN_Table.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    PKMN_Table t(FILE_POKEMON_MOVES);
    cout << t;
    return 0;
}
