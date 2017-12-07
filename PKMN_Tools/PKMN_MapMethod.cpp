#include "PKMN_MapMethod.h"

std::vector<PKMN_TableCoordinates> map_keys(std::map<PKMN_TableCoordinates, std::string> dictionary)
{
    std::vector<PKMN_TableCoordinates> keys;
    for(std::map<PKMN_TableCoordinates, std::string>::iterator i(dictionary.begin()); i != dictionary.end(); i++)
    {
        keys.push_back(i->first);
    }
    return keys;
}

void map_print(std::map<PKMN_TableCoordinates, std::string> dictionnary)
{
    for(std::map<PKMN_TableCoordinates, std::string>::iterator i(dictionnary.begin()); i != dictionnary.end(); i++)
    {
        std::cout << i->first << " : " << i->second << std::endl;
    }
}

void map_print(std::map<std::string, std::string> dictionnary)
{
    for(std::map<std::string, std::string>::iterator i(dictionnary.begin()); i != dictionnary.end(); i++)
    {
        std::cout << i->first << " : " << i->second << std::endl;
    }
}
