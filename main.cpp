#include <iostream>
#include "PKMN_Tools/PKMN_Conversion.h"
#include "PKMN_Tools/PKMN_StatSet.h"
#include "PKMN_Tools/PKMN_VectorMethod.h"
#include "PKMN_Tools/PKMN_Table.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    //int a = string_to_int("1232");
    //cout << a;
    PKMN_StatSet A;
    cout << A;
    vector<string> a(3);
    a[0] = "rien";
    a[1] = "test";
    a[2] = "je suis";
    vector<string> b = vector_insert(a, "aml", 1);
    vector_print(a);
    vector_print(b);
    PKMN_Table t("./PKMN_Data/PKMN_Type.txt");
    cout << t;
    return 0;
}
