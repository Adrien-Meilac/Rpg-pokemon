#include "PKMN_Species.h"

PKMN_Species::PKMN_Species()
{

}

PKMN_Species::PKMN_Species(std::string InternalName)
{
    PKMN_Table table(FILE_POKEMON_SPECIES);
    m_InternalName = InternalName;
    m_ID = string_to_int(table(InternalName, "id"));
    m_Name = table(InternalName, "Name");
    m_FormName = table(InternalName, "FormName");
    m_Type.first = PKMN_Type(table(InternalName, "Type1"));
    if(table(InternalName, "Type2").size() > 0)
    {
        m_Type.second = PKMN_Type(table(InternalName, "Type2"));
    }
    m_BaseStats = PKMN_StatSet(table(InternalName, "BaseStats"));
    m_GenderRate = string_to_double(table(InternalName, "GenderRate"));
    m_GrowthRate = table(InternalName, "GrowthRate");
    m_BaseExp = string_to_int(table(InternalName, "BaseEXP"));
    m_EffortPoints = PKMN_StatSet(table(InternalName, "EffortPoints"));
    m_Rareness = string_to_int(table(InternalName, "Rareness"));
    m_Happiness = string_to_int(table(InternalName, "Happiness"));
    m_Abilities = table(InternalName, "Abilities");
    m_HiddenAbility = table(InternalName, "HiddenAbility");
    std::vector<std::string> L = string_split(table(InternalName, "Moves"), ',');
    const unsigned int length = L.size();
    for(unsigned int i = 0; 2 * i < length; i+= 2)
    {
        m_ListMoves.push_back(std::pair<unsigned int, std::string>(string_to_int(L[i]), L[i+1]));
    }
    m_EggMoves = string_split(table(InternalName, "EggMoves"), ',');
    m_Compatibility = table(InternalName, "Compatibility");
    m_StepsToHatch = string_to_int(table(InternalName, "StepsToHatch"));
    m_Height = string_to_double(table(InternalName, "Height"));
    m_Weight = string_to_double(table(InternalName, "Weight"));
    m_Color = table(InternalName, "Color");
    m_Shape = string_to_int(table(InternalName, "Shape"));
    m_Habitat = table(InternalName, "Habitat");
    m_Kind = table(InternalName, "Kind");
    m_Pokedex = table(InternalName, "Pokedex");
    m_BattlerPlayerY = string_to_int(table(InternalName, "BattlerPlayerY"));
    m_BattlerEnemyY = string_to_int(table(InternalName, "BattlerEnemyY"));
    m_BattlerAltitude = string_to_int(table(InternalName, "BattlerAltitude"));
    m_Evolutions = table(InternalName, "Evolutions");
    m_WildItemUncommon = table(InternalName, "WildItemUncommon");
    m_RegionalNumbers = table(InternalName, "RegionalNumbers");
    m_Incense = table(InternalName, "Incense");
    m_WildItemCommon = table(InternalName, "WildItemCommon");
    m_WildItemRare = table(InternalName, "WildItemRare");
}

PKMN_Species::~PKMN_Species()
{
//    std::cout << m_InternalName << " : PKMN_Species deleted\n";
}

PKMN_StatSet PKMN_Species::getBaseStats() const
{
    return m_BaseStats;
}
