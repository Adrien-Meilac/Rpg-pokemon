#include <iostream>
#include <vector>
#include <string>
#include "Tools/PKMN_Table.h"

using namespace std;

int main()
{
    PKMN_Table Type("TypeChart.txt");
    cout << Type("Fire", "Steel");
    //cout << Type;
}
