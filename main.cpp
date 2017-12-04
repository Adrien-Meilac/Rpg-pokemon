#include "./Tools/PKMN_TableCoordinates.h"
#include "./Tools/PKMN_Table.h"

using namespace std;

int main()
{
    PKMN_TableCoordinates t("alhe", "alge");
    PKMN_TableCoordinates t2("alhe", "alhe");
    std::cout << t;
    std::map<PKMN_TableCoordinates, std::string> dictionnary;
    dictionnary[t] = "rien";
    dictionnary[t2] = "test";
    map_print(dictionnary);
    std::vector<std::string> v = string_split("je suis un chat", ' ');
    std::vector<std::string> m_headerColumn; /* Name of column, directly accessible without searching them in keys */
    std::vector<std::string> m_headerLine; /* Give name of line, directly accessible without searching them */
    std::map<PKMN_TableCoordinates, std::string>  m_table;
    std::ifstream flux("TypeChart.txt");
    std::string line;
    std::vector<std::string> L;
    bool firstLine(true);
    unsigned int length;
    while(getline(flux, line))
    {
        cout << line << endl;
        L = string_split(line);
        length = L.size();
        if(firstLine)
        {
            for(unsigned int i = 1; i < length; i++)
            {
                 m_headerColumn.push_back(L[i]);
            }
            firstLine = false;
        }
        else
        {
            std::string key(L[0]);
            m_headerLine.push_back(key);
            PKMN_TableCoordinates* ptr = 0;
            for(unsigned int i = 1; i < length; i++)
            {
                ptr = new PKMN_TableCoordinates(key, m_headerColumn[i-1]);
                m_table[*ptr] = L[i];
                cout << key << "\t" << m_headerColumn[i-1] << "\t" << L[i] << endl;
            }

        }
    }

}
