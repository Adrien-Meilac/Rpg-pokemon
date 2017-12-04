#include "./Tools/PKMN_Table.h"

using namespace std;

int main()
{
    PKMN_Table table("TypeChart.txt");
    std::vector<std::string> L(table.getLineValues("Fire"));
    for(unsigned int i = 0; i < L.size(); i++)
    {
        std::cout << L[i] << "\t";
    }
}
