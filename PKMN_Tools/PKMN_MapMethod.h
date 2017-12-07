#ifndef PKMN_MAPMETHOD_H_INCLUDED
#define PKMN_MAPMETHOD_H_INCLUDED

#include "PKMN_TableCoordinates.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

std::vector<PKMN_TableCoordinates> map_keys(std::map<PKMN_TableCoordinates, std::string> dictionary);
void map_print(std::map<PKMN_TableCoordinates, std::string> dictionary);
void map_print(std::map<std::string, std::string> dictionary);

#endif // PKMN_VECTORANDMAP_H_INCLUDED
