#ifndef PKMN_PLAYER_H_INCLUDED
#define PKMN_PLAYER_H_INCLUDED

#include "../Pokemon/Pokemon.h"

#include "../FilePath.h"

#include "../Tools/Table.h"

#include <string>
#include <vector>
#include <cmath>

#define NUMBER_OF_PKMN_PER_TRAINOR 6

namespace PKMN
{
    class Player;
}

class PKMN::Player
{
public:
    Player();
    ~Player();

    std::string getName() const;
    std::string getFullName() const;

private:

    unsigned int getID() const;// ID = 4 first figure secret, 4 last public

    std::string m_name;
    std::string m_typeName; // ex : PkMn Trainer
    std::string m_gender;
    unsigned int m_publicID; // between 0 -> 2^16 - 1
    unsigned int m_secretID; // between 0 -> 2^16 - 1
    //unsigned int m_outfit; // linked to the image ?
    std::string m_language; //language used by the computer
    unsigned int m_money;
    std::vector<bool> m_badges;
    //m_numbadges; number of badges
    bool m_pokegear; // has a pokegear
    bool m_pokedex; // has a pokedex
    std::vector<Pokemon> m_team;
};

#endif // PKMN_PLAYER_H_INCLUDED
