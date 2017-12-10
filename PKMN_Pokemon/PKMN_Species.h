#ifndef PKMN_SPECIES_H_INCLUDED
#define PKMN_SPECIES_H_INCLUDED

#include "PKMN_Type.h"
#include "PKMN_ExpAndLevel.h"
#include "PKMN_Moves.h"
#include "../PKMN_Tools/PKMN_StatSet.h"
#include <string>
#include <vector>
#include <iostream>

class PKMN_Species
{
public:
    PKMN_Species();
    PKMN_Species(std::string m_InternalName);

    virtual ~PKMN_Species();

protected:

    std::string m_InternalName;
    unsigned int m_ID;
    std::string m_Name;
    std::string m_FormName;
    std::pair<PKMN_Type, PKMN_Type> m_Type;
    PKMN_StatSet m_BaseStats;
    double m_GenderRate;
    std::string m_GrowthRate;
    unsigned int m_BaseExp;
    PKMN_StatSet m_EffortPoints;
    unsigned int m_Rareness;
    unsigned int m_Happiness;
    std::string m_Abilities; // A recoder en classe
    std::string m_HiddenAbility;
    std::vector<std::pair<unsigned int, std::string> > m_ListMoves;//(level , move)
    std::vector<std::string> m_EggMoves;
    std::string m_Compatibility; // =Monster,Grass -> a recoder
    unsigned int m_StepsToHatch;
    double m_Height;
    double m_Weight;
    std::string m_Color;
    unsigned int m_Shape;
    std::string m_Habitat;
    std::string m_Kind;
    std::string m_Pokedex;
    unsigned int m_BattlerPlayerY;
    unsigned int m_BattlerEnemyY;
    unsigned int m_BattlerAltitude;
    std::string m_Evolutions; //=IVYSAUR,Level,16 à recoder
    std::string m_WildItemUncommon;
    std::string m_RegionalNumbers;
    std::string m_Incense;
    std::string m_WildItemCommon;
    std::string m_WildItemRare;

};

#endif // PKMN_SPECIES_H_INCLUDED
