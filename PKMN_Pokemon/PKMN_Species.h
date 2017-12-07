//#ifndef PKMN_SPECIES_H_INCLUDED
//#define PKMN_SPECIES_H_INCLUDED
//
//#include "PKMN_Type.h"
//#include "PKMN_ExpAndLevel.h"
//#include "PKMN_Moves.h"
//#include "../PKMN_Tools/PKMN_StatSet.h"
//
//#define PATH_TO_SPECIES_FILE "./PKMN_Data/Pokemon.txt"
//
//class PKMN_Species
//{
//public:
//    PKMN_Species();
//    PKMN_Species(std::string m_InternalName);
//    //void print() const;
//
//    virtual ~PKMN_Species();
//
//private:
//
//    std::string m_InternalName;
//    unsigned int m_ID;
//    std::string m_Name;
//    std::string m_FormName;
//    std::pair<PKMN_Type, PKMN_Type> m_Type;
//    PKMN_StatSet m_BaseStats;
//    double m_GenderRate;
//    PKMN_ExpAndLevel m_GrowthRate;
//    unsigned int m_BaseEXP;
//    PKMN_StatSet m_EffortPoints;
//    unsigned int m_Rareness;
//    unsigned int m_Happiness;
//    std::string m_Abilities; // A recoder en classe
//    std::string m_HiddenAbility;
//    std::vector<std::pair<unsigned int, PKMN_Moves> > m_ListMoves;//(level , move)
//    std::vector<PKMN_Moves> m_EggMoves;
//    std::string m_Compatibility; // =Monster,Grass -> a recoder
//    unsigned int m_StepsToHatch;
//    double m_Height;
//    double m_Weight;
//    std::string m_Color;
//    unsigned int m_Shape;
//    std::string m_Habitat;
//    std::string m_Kind;
//    std::string m_Pokedex;
//    unsigned int m_BattlerPlayerY;
//    unsigned int m_BattlerEnemyY;
//    unsigned int m_BattlerAltitude;
//    std::string m_Evolutions; //=IVYSAUR,Level,16 à recoder
//
//};
//
//#endif // PKMN_SPECIES_H_INCLUDED
