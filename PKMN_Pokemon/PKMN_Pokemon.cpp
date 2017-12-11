#include "PKMN_Pokemon.h"

PKMN_Pokemon::PKMN_Pokemon()
{

}

PKMN_Pokemon::PKMN_Pokemon(std::string Position)
{
    PKMN_Table table(BACKUP_POKEMON_HOLD);
    PKMN_Species(table(Position, "Species"));
    m_Pokemon_Name = table(Position, "Name");
    m_Pokemon_IV = PKMN_StatSet(table(Position, "IV"));
    m_Pokemon_EV = PKMN_StatSet(table(Position, "EV"));
    m_Pokemon_CurStat = PKMN_StatSet(table(Position, "CurrentStat"));
    m_Pokemon_ExpAndLevel = PKMN_ExpAndLevel(m_GrowthRate, string_to_int(table(Position, "Level")), string_to_int(table(Position, "Experience")));
    m_Pokemon_Moves = read_moves(table(Position, "Moves"));
    m_Pokemon_gender = table(Position, "Gender");
    m_Pokemon_NormalStat = NormalStatistics(m_BaseStats,
                                            m_Pokemon_IV,
                                            m_Pokemon_EV,
                                            m_Pokemon_ExpAndLevel.getLevel(),
                                            ""); // nature forgotten
    for(unsigned int i=0; i < 6; i++)
    {
        m_Pokemon_StageSet.push_back(0);
    }
}

PKMN_Pokemon::~PKMN_Pokemon()
{
    std::cout << "PKMN_Pokemon deleted\n";
}


bool PKMN_Pokemon::addOrSubstractStage(std::string statChange, int difference)
{
    if(statChange == "Att")
    {
        m_Pokemon_StageSet[0] += difference;
    }
    else if(statChange == "Def")
    {
        m_Pokemon_StageSet[1] += difference;
    }
    else if(statChange == "SpAtt")
    {
        m_Pokemon_StageSet[2] += difference;
    }
    else if(statChange == "SpDef")
    {
        m_Pokemon_StageSet[3] += difference;
    }
    else if(statChange == "Speed")
    {
        m_Pokemon_StageSet[4] += difference;
    }
    else if(statChange == "Accuracy")
    {
        m_Pokemon_StageSet[5] += difference;
    }
    else if(statChange == "Evasiveness")
    {
        m_Pokemon_StageSet[6] += difference;
    }
}

bool PKMN_Pokemon::statSwap(std::string stat1, std::string stat2)
{
    m_Pokemon_CurStat.statSwap(stat1, stat2);
    return true;
}

