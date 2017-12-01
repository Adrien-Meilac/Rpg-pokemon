#include <iostream>
#include <vector>
#include <string>
#include "Tools/PKMN_Tuple.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <valarray>
//#include "Tools/PKMN_Table.h"

using namespace std;

std::vector<std::string> split(const std::string& line, const char delim = ';')
{
    std::stringstream ss(line);
    std::string item;
    std::vector<std::string> L;
    while (getline(ss, item, delim))
    {
        L.push_back(item);
    }
    return L;
}

int main()
{
    std::vector<std::string> m_headerColumn; /* Name of column, directly accessible without searching them in keys */
    std::vector<std::string> m_headerLine; /* Give name of line, directly accessible without searching them */
    std::map<PKMN_Tuple, std::string>  m_table;
    std::ifstream flux("TypeChart.txt");
    std::string line;
    std::vector<std::string> L;
    bool firstLine(true);
    unsigned int length;
    while(getline(flux, line))
    {
        cout << line << endl;
        L = split(line);
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
            for(unsigned int i = 1; i < length; i++)
            {
                cout << i << " "<< m_headerColumn.size() << endl;
                cout << PKMN_Tuple(key, m_headerColumn[i-1]) << endl;
                cout << i << " "<< L.size() << endl;
                //m_table.insert(std::pair<PKMN_Tuple, std::string>(PKMN_Tuple(key, m_headerColumn[i]), L[i]));
            }
        }
    }
}
