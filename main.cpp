#include "./Tools/PKMN_Table.h"
#include "./BattleMode/PKMN_Type.h"
#include "./Tools/PKMN_Conversion.h"

using namespace std;

int main()
{
    PKMN_Table table("TypeChart.txt");
    PKMN_Type t("Fire", table.getLineValues("Fire"));
    int a = string_to_int("1234");
    cout << a;
}
