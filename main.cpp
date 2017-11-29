#include "Tools/PKMN_Table.h"
#include <iostream>

using namespace std;

int main()
{
    PKMN_Table t("TypeChart.txt");
    cout << t.getValue("Ghost", "Weaknesses");
    return 0;
}
