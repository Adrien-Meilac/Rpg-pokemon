#ifndef PKMN_FILEPATH_H_INCLUDED
#define PKMN_FILEPATH_H_INCLUDED

#define FILE_PKMN_TYPE      "./Data/Type.txt"
#define FILE_PKMN_SPECIES   "./Data/Species.txt"
#define FILE_PKMN_MOVES     "./Data/Moves.txt"
#define FILE_PKMN_PLACE     "./Data/Place.txt"

#define BACKUP_PKMN_PLAYER_POKEMON      "./BackUp/Player_Pokemon.txt"
#define BACKUP_PKMN_PLAYER              "./BackUp/Player.txt"


#include <string>
#include <iostream>
#include <fstream>

namespace PKMN
{
bool inline is_file_exist(std::string fileName)
{
    std::ifstream infile(fileName.c_str());
    return infile.good();
}

}

#endif // PKMN_FILEPATH_H_INCLUDED
