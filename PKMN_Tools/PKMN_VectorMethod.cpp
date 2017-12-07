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
    if(line[line.size() - 1] == delim)
    {
        L.push_back("");
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
    L2.push_back(str);
    for(unsigned int i = pos; i < length;i++)
    {
        L2.push_back(L[i]);
    }
    return L2;
}

void vector_print(std::vector<std::string> v)
{
    const unsigned int length = v.size();
    std::cout << "(";
    for(unsigned int i = 0; i < length - 1; i++)
    {
        std::cout << v[i] << ", ";
    }
    std::cout << v[length - 1] << ")";
}
