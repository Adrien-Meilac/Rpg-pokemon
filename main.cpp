#include <iostream>
#include <vector>
#include <string>
#include "Tools/PKMN_Tuple.h"
//#include "Tools/PKMN_Table.h"

using namespace std;

int main()
{
    //PKMN_Table Type("TypeChart.txt");
    vector<string> v(2);
    v[0] = "rien";
    v[1] = "tout";
    vector<string> u = v;
    v[0] = "nul";
    cout << u[0] ;
    //cout << Type("Fire", "Steel");
    //cout << Type;
}
