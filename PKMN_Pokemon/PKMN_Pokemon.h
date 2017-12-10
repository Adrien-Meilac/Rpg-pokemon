#ifndef PKMN_POKEMON_H_INCLUDED
#define PKMN_POKEMON_H_INCLUDED

#include "../PKMN_Tools/PKMN_StatSet.h"
#include "../PKMN_FilePath.h"

#include "PKMN_Species.h"
#include "PKMN_Moves.h"
#include "PKMN_ExpAndLevel.h"

class PKMN_Pokemon : public PKMN_Species
{
public:

    PKMN_Pokemon();
    PKMN_Pokemon(std::string Position);
    ~PKMN_Pokemon();

private:

    std::string m_Pokemon_Name;
    PKMN_StatSet m_Pokemon_IV;
    PKMN_StatSet m_Pokemon_EV;
    PKMN_StatSet m_Pokemon_NormalStat;
    PKMN_StatSet m_Pokemon_CurStat;
    std::vector<PKMN_Moves> m_Pokemon_Moves;
    PKMN_ExpAndLevel m_Pokemon_ExpAndLevel;
    std::string m_Pokemon_gender;
    // Status //
};


#endif // PKMN_POKEMON_H_INCLUDED
