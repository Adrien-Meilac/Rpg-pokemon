#include <iostream>
#include "PKMN_Tools/PKMN_Conversion.h"
#include "PKMN_Tools/PKMN_StatSet.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int a = string_to_int("1232");
    cout << a;
    PKMN_StatSet A;
    cout << A;
    return 0;
}
