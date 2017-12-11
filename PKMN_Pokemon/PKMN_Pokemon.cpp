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
    PKMN_StatSet tempCurStat(table(Position, "CurrentStat"));
    m_pokemon_cur_HP = tempCurStat.getHP();
    m_pokemon_cur_Att = tempCurStat.getAtt();
    m_pokemon_cur_Def = tempCurStat.getDef();
    m_pokemon_cur_SpAtt = tempCurStat.getSpAtt();
    m_pokemon_cur_SpDef = tempCurStat.getSpDef();
    m_pokemon_cur_Speed = tempCurStat.getSpeed();
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

//
//bool PKMN_Pokemon::addOrSubstractStage(std::string statChange, int difference)
//{
//    if(statChange == "Att")
//    {
//        m_Pokemon_StageSet[0] += difference;
//    }
//    else if(statChange == "Def")
//    {
//        m_Pokemon_StageSet[1] += difference;
//    }
//    else if(statChange == "SpAtt")
//    {
//        m_Pokemon_StageSet[2] += difference;
//    }
//    else if(statChange == "SpDef")
//    {
//        m_Pokemon_StageSet[3] += difference;
//    }
//    else if(statChange == "Speed")
//    {
//        m_Pokemon_StageSet[4] += difference;
//    }
//    else if(statChange == "Accuracy")
//    {
//        m_Pokemon_StageSet[5] += difference;
//    }
//    else if(statChange == "Evasiveness")
//    {
//        m_Pokemon_StageSet[6] += difference;
//    }
//}


void PKMN_Pokemon::outBattle()
{
    m_pokemon_cur_HP = m_Pokemon_NormalStat.getHP();
    m_pokemon_cur_Att = m_Pokemon_NormalStat.getAtt();
    m_pokemon_cur_Def = m_Pokemon_NormalStat.getDef();
    m_pokemon_cur_SpAtt = m_Pokemon_NormalStat.getSpAtt();
    m_pokemon_cur_SpDef = m_Pokemon_NormalStat.getSpDef();
    m_pokemon_cur_Speed = m_Pokemon_NormalStat.getSpeed();
    m_pokemon_cur_Accuracy = 100;
    m_pokemon_cur_Evasiveness = 100;
}

bool PKMN_Pokemon::isAlive()
{
    return m_pokemon_cur_HP > 0;
}

//PKMN_Moves PKMN_Pokemon::chooseAnAttack() const
//{
//
//}

void PKMN_Pokemon::attack(PKMN_Pokemon Other, unsigned int i)
{
    PKMN_Moves moveUsed = m_Pokemon_Moves[i];
    unsigned int lvl = m_Pokemon_ExpAndLevel.getLevel();
    unsigned int power = moveUsed.getBasePower();
    unsigned int damagePoint = 0;
    double CM = PKMN_Type_effectiveness(Other.m_Type, moveUsed.getType());
    std::string DamageCategory = moveUsed.getDamageCategory();
    if(DamageCategory == PKMN_DAMAGE_CATEGORY_PHYSICAL)
    {
        damagePoint = ((lvl * 0.4 + 2) * m_pokemon_cur_Att * power)/(Other.m_pokemon_cur_Def * 50) + 2 * CM;
    }
    else if(DamageCategory == PKMN_DAMAGE_CATEGORY_SPECIAL)
    {
        damagePoint = ((lvl * 0.4 + 2) * m_pokemon_cur_SpAtt * power)/(Other.m_pokemon_cur_SpDef * 50) + 2 * CM;
    }
    std::cout << damagePoint;
    Other.m_pokemon_cur_HP -= damagePoint;
}
