#include "PKMN_VectorMethod.h"

bool vector_in(const std::vector<std::string>& L, const std::string& word)
{
    const unsigned int length = L.size();
    for(unsigned int i = 0; i < length; i++)
    {
        if(L[i] == word)
        {
            return true;
        }
    }
    return false;
}

std::vector<std::string> string_split(const std::string& line, const char& delim)
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

std::vector<std::string> vector_insert(std::vector<std::string> L, const std::string& str, const unsigned int& pos)
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

void vector_print(const std::vector<std::string>& L)
{
    const unsigned int length = L.size();
    std::cout << "(";
    for(unsigned int i = 0; i < length - 1; i++)
    {
        std::cout << L[i] << "; ";
    }
    std::cout << L[length - 1] << ")";
}

std::string vector_join(const std::vector<std::string>& L, const char& delim)
{
    const unsigned int length = L.size();
    std::string joinedText = "";
    if(length != 0)
    {
        for(unsigned int i = 0; i < length - 1; i++)
        {
            joinedText += L[i] + delim;
        }
        joinedText += L[length - 1];
    }
    return joinedText;
}
