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
    bool hasPokemonAlive() const;
    Pokemon getPokemon(unsigned int pos = 0);
    void setPokemon(Pokemon pkmn,unsigned int pos);
    std::string getFullName() const;

private:

    unsigned int getID() const;// ID = 4 first figure secret, 4 last public

    std::string m_Name;
    std::string m_TypeName; // ex : PkMn Trainer
    std::string m_Gender;
    unsigned int m_PublicID; // between 0 -> 2^16 - 1
    unsigned int m_SecretID; // between 0 -> 2^16 - 1
    //unsigned int m_outfit; // linked to the image ?
    std::string m_Language; //language used by the computer
    unsigned int m_Money;
    std::vector<bool> m_Badges;
    //m_numbadges; number of badges
    bool m_Pokedex; // has a pokedex
    std::vector<Pokemon> m_Party;
};

#endif // PKMN_PLAYER_H_INCLUDED
