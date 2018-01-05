#include "Species.h"

                /// CONSTRUCTORS ///

PKMN::Species::Species()
{
    m_InternalName = "";
}

PKMN::Species::Species(std::string InternalName)
{
    PKMN::Table table(FILE_PKMN_SPECIES);
    m_InternalName = InternalName;
    m_ID = table(InternalName, "id");
    m_Name = table(InternalName, "Name");
    m_FormName = table(InternalName, "FormName");
    m_Type.first = PKMN::Type(table(InternalName, "Type1"));
    if(table(InternalName, "Type2").size() > 0)
    {
        m_Type.second = PKMN::Type(table(InternalName, "Type2"));
    }
    m_BaseStats = PKMN::StatSet(table(InternalName, "BaseStats"));
    m_GenderRate = PKMN::string_to_double(table(InternalName, "GenderRate"));
    m_GrowthRate = table(InternalName, "GrowthRate");
    m_BaseExp = PKMN::string_to_int(table(InternalName, "BaseEXP"));
    m_EffortPoints = PKMN::StatSet(table(InternalName, "EffortPoints"));
    m_Rareness = PKMN::string_to_int(table(InternalName, "Rareness"));
    m_Happiness = PKMN::string_to_int(table(InternalName, "Happiness"));
    m_Abilities = table(InternalName, "Abilities");
    m_HiddenAbility = table(InternalName, "HiddenAbility");
    std::vector<std::string> L = PKMN::string_split(table(InternalName, "Moves"), ',');
    const unsigned int length = L.size();
    for(unsigned int i = 0; 2 * i < length; i+= 2)
    {
        m_ListMoves.push_back(std::pair<unsigned int, std::string>(string_to_int(L[i]), L[i+1]));
    }
    m_EggMoves = PKMN::string_split(table(InternalName, "EggMoves"), ',');
    m_Compatibility = table(InternalName, "Compatibility");
    m_StepsToHatch = PKMN::string_to_int(table(InternalName, "StepsToHatch"));
    m_Height = PKMN::string_to_double(table(InternalName, "Height"));
    m_Weight = PKMN::string_to_double(table(InternalName, "Weight"));
    m_Color = table(InternalName, "Color");
    m_Shape = PKMN::string_to_int(table(InternalName, "Shape"));
    m_Habitat = table(InternalName, "Habitat");
    m_Kind = table(InternalName, "Kind");
    m_Pokedex = table(InternalName, "Pokedex");
    m_BattlerPlayerY = PKMN::string_to_int(table(InternalName, "BattlerPlayerY"));
    m_BattlerEnemyY = PKMN::string_to_int(table(InternalName, "BattlerEnemyY"));
    m_BattlerAltitude = string_to_int(table(InternalName, "BattlerAltitude"));
    m_Evolutions = table(InternalName, "Evolutions");
    m_WildItemUncommon = table(InternalName, "WildItemUncommon");
    m_RegionalNumbers = table(InternalName, "RegionalNumbers");
    m_Incense = table(InternalName, "Incense");
    m_WildItemCommon = table(InternalName, "WildItemCommon");
    m_WildItemRare = table(InternalName, "WildItemRare");
}

PKMN::Species::Species(Species const& other):
    m_InternalName(other.m_InternalName),
    m_ID(other.m_ID),
    m_Name(other.m_Name),
    m_FormName(other.m_FormName),
    m_Type(other.m_Type),
    m_BaseStats(other.m_BaseStats),
    m_GenderRate(other.m_GenderRate),
    m_GrowthRate(other.m_GrowthRate),
    m_BaseExp(other.m_BaseExp),
    m_EffortPoints(other.m_EffortPoints),
    m_Rareness(other.m_Rareness),
    m_Happiness(other.m_Happiness),
    m_Abilities(other.m_Abilities), // A recoder en classe
    m_HiddenAbility(other.m_HiddenAbility),
    m_ListMoves(other.m_ListMoves),//(level , move)
    m_EggMoves(other.m_EggMoves),
    m_Compatibility(other.m_Compatibility), // =Monster,Grass -> a recoder
    m_StepsToHatch(other.m_StepsToHatch),
    m_Height(other.m_Height),
    m_Weight(other.m_Weight),
    m_Color(other.m_Color),
    m_Shape(other.m_Shape),
    m_Habitat(other.m_Habitat),
    m_Kind(other.m_Kind),
    m_Pokedex(other.m_Pokedex),
    m_BattlerPlayerY(other.m_BattlerPlayerY),
    m_BattlerEnemyY(other.m_BattlerEnemyY),
    m_BattlerAltitude(other.m_BattlerAltitude),
    m_Evolutions(other.m_Evolutions), //=IVYSAUR,Level,16 à recoder
    m_WildItemUncommon(other.m_WildItemUncommon),
    m_RegionalNumbers(other.m_RegionalNumbers),
    m_Incense(other.m_Incense),
    m_WildItemCommon(other.m_WildItemCommon),
    m_WildItemRare(other.m_WildItemRare)
{

}

PKMN::Species& PKMN::Species::operator=(Species const& other)
{
    m_InternalName = other.m_InternalName;
    m_ID = other.m_ID;
    m_Name = other.m_Name;
    m_FormName = other.m_FormName;
    m_Type.first = other.m_Type.first;
    m_Type.second = other.m_Type.second;
    m_BaseStats = other.m_BaseStats;
    m_GenderRate = other.m_GenderRate;
    m_GrowthRate = other.m_GrowthRate;
    m_BaseExp = other.m_BaseExp;
    m_EffortPoints = other.m_EffortPoints;
    m_Rareness = other.m_Rareness;
    m_Happiness = other.m_Happiness;
    m_Abilities = other.m_Abilities; // A recoder en classe
    m_HiddenAbility = other.m_HiddenAbility;
    m_ListMoves = other.m_ListMoves;//(level , move)
    m_EggMoves = other.m_EggMoves;
    m_Compatibility = other.m_Compatibility; // =Monster,Grass -> a recoder
    m_StepsToHatch = other.m_StepsToHatch;
    m_Height = other.m_Height;
    m_Weight = other.m_Weight;
    m_Color = other.m_Color;
    m_Shape = other.m_Shape;
    m_Habitat = other.m_Habitat;
    m_Kind = other.m_Kind;
    m_Pokedex = other.m_Pokedex;
    m_BattlerPlayerY = other.m_BattlerPlayerY;
    m_BattlerEnemyY = other.m_BattlerEnemyY;
    m_BattlerAltitude = other.m_BattlerAltitude;
    m_Evolutions = other.m_Evolutions; //=IVYSAUR,Level,16 à recoder
    m_WildItemUncommon = other.m_WildItemUncommon;
    m_RegionalNumbers = other.m_RegionalNumbers;
    m_Incense = other.m_Incense;
    m_WildItemCommon = other.m_WildItemCommon;
    m_WildItemRare = other.m_WildItemRare;
    return *this;
}

/// ///////////////////////////////////////// ///

                /// DESTRUCTOR ///

PKMN::Species::~Species()
{

}

/// ///////////////////////////////////////// ///

                /// GETTERS ///

PKMN::StatSet PKMN::Species::getBaseStats() const
{
    return m_BaseStats;
}

std::string PKMN::Species::getSpeciesName() const
{
    return m_InternalName;
}

unsigned int PKMN::Species::getBaseExp() const
{
    return m_BaseExp;
}

std::pair<PKMN::Type, PKMN::Type> PKMN::Species::getTypes() const
{
    return m_Type;
}
