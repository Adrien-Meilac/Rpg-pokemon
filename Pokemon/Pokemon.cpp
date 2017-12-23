#include "Pokemon.h"

PKMN::Pokemon::Pokemon(): Species()
{

}

namespace PKMN
{
Pokemon::Pokemon(std::string Position):
    Species(Table(BACKUP_PKMN_PLAYER_POKEMON).operator()(Position, "Species"))
{
    Table table(BACKUP_PKMN_PLAYER_POKEMON);
    m_Pokemon_Name = table(Position, "Name");
    m_Pokemon_IV = StatSet(table(Position, "IV"));
    m_Pokemon_EV = StatSet(table(Position, "EV"));
    m_Pokemon_CurrentStat = StatSetExtended(table(Position, "CurrentStat"));
    m_Pokemon_ExpAndLevel = ExpAndLevel(m_GrowthRate,
                                              string_to_int(table(Position, "Level")),
                                              string_to_int(table(Position, "Experience")));
    m_Pokemon_Moves = read_move(table(Position, "Moves"));
    m_Pokemon_gender = table(Position, "Gender");
    m_Pokemon_NormalStat = NormalStatistics(m_BaseStats,
                                            m_Pokemon_IV,
                                            m_Pokemon_EV,
                                            m_Pokemon_ExpAndLevel.getLevel(),
                                            ""); // nature forgotten
    m_IsShiney = string_to_bool(table(Position, "Is Shiney"));
}
}

PKMN::Pokemon::~Pokemon()
{

}

void PKMN::Pokemon::outBattle()
{
    m_Pokemon_CurrentStat.outBattle();
}

void PKMN::Pokemon::heal()
{
    m_Pokemon_CurrentStat.heal(m_Pokemon_NormalStat);
}

bool PKMN::Pokemon::isAlive() const
{
    return m_Pokemon_CurrentStat.getHP() > 0;
}

void PKMN::Pokemon::attack(Pokemon& Other, unsigned int i)
{
    Move moveUsed = m_Pokemon_Moves[i].second;
    std::cout << m_Pokemon_Name << " used " << moveUsed.getName() << "." << std::endl;
    unsigned int lvl = m_Pokemon_ExpAndLevel.getLevel();
    unsigned int power = moveUsed.getBasePower();
    double damagePoint = 0;
    double typeEffect = Type_effectiveness(Other.m_Type, moveUsed.getType());
    double CM = typeEffect;
    DamageCategory damCategory = moveUsed.getDamageCategory();
    if(damCategory.isPhysicalCategory())
    {
        damagePoint = ((lvl * 0.4 + 2) * m_Pokemon_CurrentStat.getAtt() * power)/(m_Pokemon_CurrentStat.getDef() * 50) + 2 * CM;
    }
    else if(damCategory.isSpecialCategory())
    {
        damagePoint = ((lvl * 0.4 + 2) * m_Pokemon_CurrentStat.getSpAtt() * power)/(m_Pokemon_CurrentStat.getSpDef() * 50) + 2 * CM;
    }
    Other.lowerHP(static_cast<int>(ceil(damagePoint)));
    std::cout << Type_message(typeEffect);
}


void PKMN::Pokemon::lowerHP(unsigned int damagePoint)
{
    int c = m_Pokemon_CurrentStat.getHP();
    for(unsigned int i = 0; i < damagePoint; i++)
    {
        if(this->isAlive())
        {
            m_Pokemon_CurrentStat.decrementHP();
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

void PKMN::Pokemon::printStat() const
{
    std::cout << "Pokemon " << m_Pokemon_Name << "("; //<< std::endl;
    std::cout << "HP = " << m_Pokemon_CurrentStat.getHP() << "/" <<  m_Pokemon_NormalStat.getHP() << ")" << std::endl;
//    std::cout << "Att = " << m_pokemon_cur_Att << "/" <<  m_Pokemon_NormalStat.getAtt() << std::endl;
//    std::cout << "Def = " << m_pokemon_cur_Def << "/" <<  m_Pokemon_NormalStat.getDef() << std::endl;
//    std::cout << "SpAtt = " << m_pokemon_cur_SpAtt << "/" <<  m_Pokemon_NormalStat.getSpAtt() << std::endl;
//    std::cout << "SpDef = " << m_pokemon_cur_SpDef << "/" <<  m_Pokemon_NormalStat.getSpDef() << std::endl;
//    std::cout << "Speed = " << m_pokemon_cur_Speed << "/" <<  m_Pokemon_NormalStat.getSpeed() << std::endl;
}

void PKMN::Pokemon::deathMessage() const
{
    std::cout << "The foe's " << m_Pokemon_Name << " fainted !" << std::endl;
}

unsigned int PKMN::Pokemon::expGained(PKMN::Pokemon& PkmnDead) const
{
    double a = 1;
    unsigned int b = PkmnDead.m_BaseExp;
    unsigned int N = PkmnDead.m_Pokemon_ExpAndLevel.getLevel();
    return static_cast<int>(floor(a * b * N / 7));;
}

void PKMN::Pokemon::messageGetExp(unsigned int expPoint) const
{
    std::cout << m_Name << " gained " << expPoint << "EXP. Point !" << std::endl;
}

std::string PKMN::Pokemon::getName() const
{
    return m_Pokemon_Name;
}

std::vector<std::pair<unsigned int,PKMN::Move> > PKMN::Pokemon::getListMove()
{
    return m_Pokemon_Moves;
}
