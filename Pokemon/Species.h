#ifndef PKMN_SPECIES_H_INCLUDED
#define PKMN_SPECIES_H_INCLUDED

#include "Type.h"
#include "ExpAndLevel.h"

#include "../FilePath.h"

#include "../Tools/StatSet.h"
#include "../Tools/Table.h"

#include <string>
#include <vector>
#include <iostream>

namespace PKMN
{
    class Species;
}

class PKMN::Species
/** Species contains standarts information about a pokemon.
    They are always the same for each species of pokemon.
    It is a virtual class ??? */
{
public:

/// CONSTRUCTORS :

    Species();
        /** \brief
         *
         *
         */

    Species(std::string InternalName);
        /** \brief
         *
         * \param InternalName std::string
         *
         */

    Species(Species const& other);


    virtual Species& operator=(Species const& other);

/// DESTRUCTOR :

    virtual ~Species();
        /** \brief
         *
         *
         */

/// GETTERS :

    StatSet getBaseStats() const; /// necessary ???
        /** \brief
         *
         * \return StatSet
         *
         */

    std::string getSpeciesName() const;

protected:

    std::string m_InternalName;
    unsigned int m_ID;
    std::string m_Name;
    std::string m_FormName;
    std::pair<Type, Type> m_Type;
    StatSet m_BaseStats;
    double m_GenderRate;
    std::string m_GrowthRate;
    unsigned int m_BaseExp;
    StatSet m_EffortPoints;
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
