#include "Tools/PKMN_Tuple.h"
//#include "Tools/PKMN_Table.h"
#include <iostream>

using namespace std;

int main()
{
    PKMN_Tuple<int> t(1, 2);
    cout << t.getx() << t.gety();
    return 0;
}
