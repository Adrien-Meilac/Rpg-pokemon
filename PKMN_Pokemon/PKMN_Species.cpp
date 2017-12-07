//#include "PKMN_Species.h"
//
//PKMN_Species::PKMN_Species():
//    m_InternalName(),
//    m_ID(),
//    m_Name(),
//    m_Type(),
//    m_BaseStats(),
//    m_GenderRate(),
//    m_GrowthRate(),
//    m_BaseEXP(),
//    m_EffortPoints(),
//    m_Rareness(),
//    m_Happiness(),
//    m_Abilities(),
//    m_HiddenAbility(),
//    m_ListMoves(),
//    m_EggMoves(),
//    m_Compatibility(),
//    m_StepsToHatch(),
//    m_Height(),
//    m_Weight(),
//    m_Color(),
//    m_Shape(),
//    m_Habitat(),
//    m_Kind(),
//    m_Pokedex(),
//    m_BattlerPlayerY(),
//    m_BattlerEnemyY(),
//    m_BattlerAltitude(),
//    m_Evolutions()
//{
//
//}
//
//PKMN_Species::PKMN_Species(std::string InternalName)
//{
//    PKMN_Table table(PATH_TO_SPECIES_FILE);
//    std::vector<std::string> Line = table.getLineValues(InternalName);
//    std::string FormName = Line[0];
//    unsigned int BattlerEnemyY = string_to_int(Line[1]);
//    std::vector<std::string> temp = string_split(Line[2], ',');
//    unsigned int tempsize = temp.size();
//    std::vector<PKMN_Moves> EggMoves;
//    for(unsigned int i=0; i < tempsize; i++)
//    {
//        EggMoves.push_back(PKMN_Moves(tempsize[i]));
//    }
//    unsigned int ID = string_to_int(Line[3]);
//    std::string Name = Line[4];
//    PKMN_ExpAndLevel GrowthRate(Line[5]);
//    unsigned int Rareness = string_to_int(Line[6]);
//    std::string HiddenAbility = Line[7];
//    std::vector<std::string> temp2 = string_split(Line[8], ',');
//    PKMN_StatSet EffortPoints(string_to_int(temp2[0]),
//                              string_to_int(temp2[1]),
//                              string_to_int(temp2[2]),
//                              string_to_int(temp2[3]),
//                              string_to_int(temp2[4]),
//                              string_to_int(temp2[5]));
//    std::string WildItemUncommon = Line[10];
//    std::string Compatibility = Line[11];
//    std::string Kind = Line[12];
//    unsigned int BattlerAltitude = string_to_int(Line[13]);
//    unsigned int StepsToHatch = string_to_int(Line[14]);
//    unsigned int BattlerPlayerY = string_to_int(Line[15]);
//    std::string Incense = Line[16];
//    double GenderRate = string_to_int(Line[17]); // A recoder
//    std::string Evolution = Line[18];// A recoder
//    std::string Pokedex = Line[19];
//    unsigned int BaseEXP = string_to_int(Line[20]);
//    std::string WildItemCommon = Line[21];
//    std::string Abilities = Line[22];
//    std::string Habitat = Line[23];
//    double Weight = string_to_int(Line[24]);
//    std::string Color = Line[25];
//    PKMN_StatSet BaseStats = Line[26];
//    double Height = string_to_int(Line[27]);
//    unsigned int Shape = string_to_int(Line[28]);
//    std::vector<std::pair<unsigned int, PKMN_Moves> > ListMoves; /// Doute !!
//    std::vector<std::string> temp3 = string_split(Line[29], ',');
//    unsigned int temp3size = temp3.size();
//    for(unsigned int i = 0; i < temp3size; i+= 2)
//    {
//        ListMoves.push_back(std::pair<unsigned int, PKMN_Moves>(temp3[i],PKMN_Moves(temp3[i+1])));
//    }
//    std::pair<PKMN_Type, PKMN_Type> Type;
//    Type.first = PKMN_Type(Line[30]);
//    std::string WildItemRare = Line[31];
//    unsigned int m_Happiness = string_to_int(Line[32]);
//    Type.second = PKMN_Type(Line[33]);
//    m_InternalName = InternalName;
//    m_FormName = FormName;
//    m_ID(),
//    m_Name(),
//    m_Type(),
//    m_BaseStats(),
//    m_GenderRate(),
//    m_GrowthRate(),
//    m_BaseEXP(),
//    m_EffortPoints(),
//    m_Rareness(),
//    m_Happiness(),
//    m_Abilities(),
//    m_HiddenAbility(),
//    m_ListMoves(),
//    m_EggMoves(),
//    m_Compatibility(),
//    m_StepsToHatch(),
//    m_Height(),
//    m_Weight(),
//    m_Color(),
//    m_Shape(),
//    m_Habitat(),
//    m_Kind(),
//    m_Pokedex(),
//    m_BattlerPlayerY(),
//    m_BattlerEnemyY(),
//    m_BattlerAltitude(),
//    m_Evolutions()
//}
//
//PKMN_Species::~PKMN_Species()
//{
//    delete &m_InternalName;
//    delete &m_ID;
//    delete &m_Name;
//    delete &m_Type;
//    delete &m_BaseStats;
//    delete &m_GenderRate;
//    delete &m_GrowthRate;
//    delete &m_BaseEXP;
//    delete &m_EffortPoints;
//    delete &m_Rareness;
//    delete &m_Happiness;
//    delete &m_Abilities;
//    delete &m_HiddenAbility;
//    delete &m_ListMoves;
//    delete &m_EggMoves;
//    delete &m_Compatibility;
//    delete &m_StepsToHatch;
//    delete &m_Height;
//    delete &m_Weight;
//    delete &m_Color;
//    delete &m_Shape;
//    delete &m_Habitat;
//    delete &m_Kind;
//    delete &m_Pokedex;
//    delete &m_BattlerPlayerY;
//    delete &m_BattlerEnemyY;
//    delete &m_BattlerAltitude;
//    delete &m_Evolutions;
//}
//
