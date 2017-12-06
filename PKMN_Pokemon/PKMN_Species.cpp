#include "PKMN_Species.h"

PKMN_Species::PKMN_Species():
    m_InternalName(),
    m_ID(),
    m_Name(),
    m_Type(),
    m_BaseStats(),
    m_GenderRate(),
    m_GrowthRate(),
    m_BaseEXP(),
    m_EffortPoints(),
    m_Rareness(),
    m_Happiness(),
    m_Abilities(),
    m_HiddenAbility(),
    m_ListMoves(),
    m_EggMoves(),
    m_Compatibility(),
    m_StepsToHatch(),
    m_Height(),
    m_Weight(),
    m_Color(),
    m_Shape(),
    m_Habitat(),
    m_Kind(),
    m_Pokedex(),
    m_BattlerPlayerY(),
    m_BattlerEnemyY(),
    m_BattlerAltitude(),
    m_Evolutions()
{

}

PKMN_Species::PKMN_Species(std::string InternalName)
{

}

PKMN_Species::~PKMN_Species()
{
    delete &m_InternalName;
    delete &m_ID;
    delete &m_Name;
    delete &m_Type;
    delete &m_BaseStats;
    delete &m_GenderRate;
    delete &m_GrowthRate;
    delete &m_BaseEXP;
    delete &m_EffortPoints;
    delete &m_Rareness;
    delete &m_Happiness;
    delete &m_Abilities;
    delete &m_HiddenAbility;
    delete &m_ListMoves;
    delete &m_EggMoves;
    delete &m_Compatibility;
    delete &m_StepsToHatch;
    delete &m_Height;
    delete &m_Weight;
    delete &m_Color;
    delete &m_Shape;
    delete &m_Habitat;
    delete &m_Kind;
    delete &m_Pokedex;
    delete &m_BattlerPlayerY;
    delete &m_BattlerEnemyY;
    delete &m_BattlerAltitude;
    delete &m_Evolutions;
}

