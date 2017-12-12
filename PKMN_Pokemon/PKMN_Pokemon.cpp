#include "PKMN_Pokemon.h"

PKMN_Pokemon::PKMN_Pokemon(): PKMN_Species()
{

}

PKMN_Pokemon::PKMN_Pokemon(std::string Position) : PKMN_Species(PKMN_Table(BACKUP_POKEMON_HOLD).operator()(Position, "Species"))
{
    PKMN_Table table(BACKUP_POKEMON_HOLD);
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
//    std::cout << "PKMN_Pokemon deleted\n";
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

bool PKMN_Pokemon::isAlive() const
{
    return m_pokemon_cur_HP > 0;
}

//PKMN_Moves PKMN_Pokemon::chooseAnAttack() const
//{
//
//}

void PKMN_Pokemon::attack(PKMN_Pokemon& Other, unsigned int i)
{
    PKMN_Moves moveUsed = m_Pokemon_Moves[i];
    std::cout << m_Pokemon_Name << " used " << moveUsed.getName() << "." << std::endl;
    unsigned int lvl = m_Pokemon_ExpAndLevel.getLevel();
    unsigned int power = moveUsed.getBasePower();
    double damagePoint = 0;
    double typeEffect = PKMN_Type_effectiveness(Other.m_Type, moveUsed.getType());
    double CM = typeEffect;
    std::string DamageCategory = moveUsed.getDamageCategory();
    if(DamageCategory == PKMN_DAMAGE_CATEGORY_PHYSICAL)
    {
        damagePoint = ((lvl * 0.4 + 2) * m_pokemon_cur_Att * power)/(Other.m_pokemon_cur_Def * 50) + 2 * CM;
    }
    else if(DamageCategory == PKMN_DAMAGE_CATEGORY_SPECIAL)
    {
        damagePoint = ((lvl * 0.4 + 2) * m_pokemon_cur_SpAtt * power)/(Other.m_pokemon_cur_SpDef * 50) + 2 * CM;
    }
    Other.lowerHP(static_cast<int>(ceil(damagePoint)));
    std::cout << PKMN_Type_message(typeEffect);
}


void PKMN_Pokemon::lowerHP(unsigned int damagePoint)
{
    int c = m_pokemon_cur_HP;
    for(unsigned int i = 0; i < damagePoint; i++)
    {
        if(isAlive())
        {
            m_pokemon_cur_HP -= 1;
        }
        else
        {
            std::cout << m_Name << " lost " << c << " HP !" << std::endl;
            deathMessage();
            return;
        }
    }
    std::cout << m_Name << " lost " << damagePoint << " HP !" << std::endl;
}

void PKMN_Pokemon::printStat() const
{
    std::cout << "Pokemon " << m_Pokemon_Name << "("; //<< std::endl;
    std::cout << "HP = " << m_pokemon_cur_HP << "/" <<  m_Pokemon_NormalStat.getHP() << ")" << std::endl;
//    std::cout << "Att = " << m_pokemon_cur_Att << "/" <<  m_Pokemon_NormalStat.getAtt() << std::endl;
//    std::cout << "Def = " << m_pokemon_cur_Def << "/" <<  m_Pokemon_NormalStat.getDef() << std::endl;
//    std::cout << "SpAtt = " << m_pokemon_cur_SpAtt << "/" <<  m_Pokemon_NormalStat.getSpAtt() << std::endl;
//    std::cout << "SpDef = " << m_pokemon_cur_SpDef << "/" <<  m_Pokemon_NormalStat.getSpDef() << std::endl;
//    std::cout << "Speed = " << m_pokemon_cur_Speed << "/" <<  m_Pokemon_NormalStat.getSpeed() << std::endl;
}

void PKMN_Pokemon::deathMessage() const
{
    std::cout << "The foe's " << m_Pokemon_Name << " fainted !" << std::endl;
}

unsigned int PKMN_Pokemon::expGained(PKMN_Pokemon& PkmnDead) const
{
    double a = 1;
    unsigned int b = PkmnDead.m_BaseExp;
    unsigned int N = PkmnDead.m_Pokemon_ExpAndLevel.getLevel();
    return static_cast<int>(floor(a * b * N / 7));;
}

void PKMN_Pokemon::messageGetExp(unsigned int expPoint) const
{
    std::cout << m_Name << " gained " << expPoint << "EXP. Point !" << std::endl;
}



