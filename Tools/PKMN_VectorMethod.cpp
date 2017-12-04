#include "PKMN_VectorMethod.h"

bool vector_in(std::vector<std::string> L, std::string mot)
{
    const unsigned int length = L.size();
    for(unsigned int i = 0; i < length; i++)
    {
        if(L[i] == mot)
        {
            return true;
        }
    }
    return false;
}

std::vector<std::string> string_split(const std::string& line, const char delim)
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

std::vector<std::string> vector_insert(std::vector<std::string> L, const std::string& str, unsigned int pos)
{
    const unsigned int length = L.size();
    std::vector<std::string> L2;
    for(unsigned int i = 0; i < pos;i++)
    {
        L2.push_back(L[i]);
    }
    L2.push_back(L[pos]);
    for(unsigned int i = pos; i < length;i++)
    {
        L2.push_back(L[i]);
    }
    return L2;
}
