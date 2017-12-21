#ifndef PKMN_POKEMON_H_INCLUDED
#define PKMN_POKEMON_H_INCLUDED

#include "Species.h"
#include "Move.h"
#include "ExpAndLevel.h"

#include "../FilePath.h"

#include "../Tools/StatSet.h"
#include "../Tools/StatSetExtended.h"
#include "../Tools/Table.h"

#include "../Field/Place.h"

#include <string>
#include <vector>

namespace PKMN
{
    class Pokemon;
}


class PKMN::Pokemon : public PKMN::Species
{
public:

    Pokemon();
    Pokemon(std::string Position);
//    Pokemon(Place place);

    ~Pokemon();

    std::string getName() const;
    std::vector<std::pair<unsigned int,Move> > getListMove();
    void outBattle();
    void heal();
    bool isAlive() const;
    void deathMessage() const;
    void messageGetExp(unsigned int expPoint) const;
    void lowerHP(unsigned int damagePoint);
    void printStat() const;
    unsigned int expGained(Pokemon& PkmnDead) const;
    void attack(Pokemon& Other, unsigned int i);

private:

    std::string m_Pokemon_Name;
    StatSet m_Pokemon_IV;
    StatSet m_Pokemon_EV;
    StatSet m_Pokemon_NormalStat;
    StatSetExtended m_Pokemon_CurrentStat;
    std::vector<std::pair<unsigned int,Move> > m_Pokemon_Moves;
    ExpAndLevel m_Pokemon_ExpAndLevel;
    std::string m_Pokemon_gender;
    bool m_IsShiney;
    // Status //
};


#endif // PKMN_POKEMON_H_INCLUDED
