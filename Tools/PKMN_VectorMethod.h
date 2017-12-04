#ifndef PKMN_VECTORANDMAP_H_INCLUDED
#define PKMN_VECTORANDMAP_H_INCLUDED

#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> string_split(const std::string& line, const char delim = ';');
bool vector_in(std::vector<std::string> L, std::string mot);
std::vector<std::string> vector_insert(std::vector<std::string> L, const std::string& str, unsigned int pos);

#endif // PKMN_VECTORANDMAP_H_INCLUDED
