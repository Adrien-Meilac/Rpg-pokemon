#include "./Tools/PKMN_Table.h"
#include "./BattleMode/PKMN_Type.h"
#include "./Tools/PKMN_Conversion.h"
#include "./Tools/PKMN_StatSet.h"

using namespace std;

int main()
{
    srand(time(NULL));
    PKMN_Table table("TypeChart.txt");
    PKMN_Table table2("TypeChart.txt");
    PKMN_Type t(table.getLineValuesWithLineName("Fire"));
    PKMN_Type t2(table.getLineValuesWithLineName("Water"));
    cout << PKMN_Type_message(t2.effectiveness(t));
    PKMN_StatSet Base(45,49,49,65,65,45);
    PKMN_StatSet IV;
    PKMN_StatSet EV(0,0,0,0,0,0);
    cout << NormalStatistics(Base, IV, EV, 100, "");
}
