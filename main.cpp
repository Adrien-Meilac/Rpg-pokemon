#include "./PKMN_Tools/PKMN_StatSet.h"
#include "./PKMN_Tools/PKMN_Conversion.h"
#include "./PKMN_Tools/PKMN_VectorMethod.h"
#include "./PKMN_Tools/PKMN_MapMethod.h"
#include "./PKMN_Tools/PKMN_TableCoordinates.h"
#include "./PKMN_Tools/PKMN_TableMap.h"
#include "./PKMN_Tools/PKMN_Table.h"
#include "./PKMN_Pokemon/PKMN_Type.h"

#include <iostream>
#include <cstdlib> // for rand()
#include <ctime> // for rand()

using namespace std;

int main()
{
    srand(time(NULL)); /// For rand()
    std::cout << rand() % 32;
    PKMN_StatSet Base(45,49,49,65,65,45);
    PKMN_StatSet IV;
    PKMN_StatSet EV(0,0,0,0,0,0);
    cout << NormalStatistics(Base, IV, EV, 100, "");
    PKMN_Table table("./PKMN_Data/Moves.txt");
    std::cout << table;
    PKMN_Type type("FIRE");
    PKMN_Type type2("WATER");
    std::cout << std::endl << type.effectiveness(type2);
    return 0;
}
