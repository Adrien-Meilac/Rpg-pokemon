#include "./Tools/PKMN_Table.h"
#include "./Pokemon/PKMN_Type.h"
#include "./Tools/PKMN_Conversion.h"
#include "./Tools/PKMN_StatSet.h"

using namespace std;

int main()
{
    srand(time(NULL));
    PKMN_Table table("TypeChart.txt");
    //cout << table;
    PKMN_Table table2("TypeChart.txt");
//    PKMN_Type t(table.getLineValuesWithLineName("Fire"));
//    PKMN_Type t2(table.getLineValuesWithLineName("Water"));
//    cout << PKMN_Type_message(t2.effectiveness(t));
    PKMN_StatSet Base(45,49,49,65,65,45);
    PKMN_StatSet IV;
    PKMN_StatSet EV(0,0,0,0,0,0);
    cout << NormalStatistics(Base, IV, EV, 100, "");
//    PKMN_Table table3("PokedexBaseStat.txt");
//    cout << table3;
//    cout << endl << endl;
//    vector_print(table3.getColumnValuesWithColumnName("Def"));
//    cout << table3("37", "Species");
}
