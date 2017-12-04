#include "./Tools/PKMN_Table.h"
#include "./BattleMode/PKMN_Type.h"
#include "./Tools/PKMN_Conversion.h"

using namespace std;

int main()
{
    PKMN_Table table("TypeChart.txt");
    PKMN_Table table2("TypeChart.txt");
    PKMN_Type t(table.getLineValuesWithLineName("Fire"));
    PKMN_Type t2(table.getLineValuesWithLineName("Water"));
    cout << PKMN_Type_message(t2.effectiveness(t));
}
