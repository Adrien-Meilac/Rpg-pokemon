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
    m_Pokemon_IV = PKMN::StatSet(table(Position, "IV"));
    m_Pokemon_EV = PKMN::StatSet(table(Position, "EV"));
    m_Pokemon_CurrentStat = PKMN::StatSetExtended(table(Position, "CurrentStat"));
    m_Pokemon_ExpAndLevel = PKMN::ExpAndLevel(m_GrowthRate,
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

std::string PKMN::Pokemon::getName() const
{
    return m_Pokemon_Name;
}

unsigned int PKMN::Pokemon::getLevel() const
{
    return m_Pokemon_ExpAndLevel.getLevel();
}

std::vector<std::pair<unsigned int, PKMN::Move> > PKMN::Pokemon::getListMove()
{
    return m_Pokemon_Moves;
}

void PKMN::Pokemon::decrementHP()
{
    m_Pokemon_CurrentStat.decrementHP();
}

unsigned int PKMN::Pokemon::getCurHP() const
{
    return m_Pokemon_CurrentStat.getHP();
}

unsigned int PKMN::Pokemon::getCurAtt() const
{
    return m_Pokemon_CurrentStat.getAtt();
}

unsigned int PKMN::Pokemon::getCurDef() const
{
    return m_Pokemon_CurrentStat.getDef();
}

unsigned int PKMN::Pokemon::getCurSpAtt() const
{
    return m_Pokemon_CurrentStat.getSpAtt();
}

unsigned int PKMN::Pokemon::getCurSpDef() const
{
    return m_Pokemon_CurrentStat.getSpDef();
}

unsigned int PKMN::Pokemon::getCurSpeed() const
{
    return m_Pokemon_CurrentStat.getSpeed();
}

unsigned int PKMN::Pokemon::getNormalHP() const
{
    return m_Pokemon_NormalStat.getHP();
}

unsigned int PKMN::Pokemon::getNormalAtt() const
{
    return m_Pokemon_NormalStat.getAtt();
}

unsigned int PKMN::Pokemon::getNormalDef() const
{
    return m_Pokemon_NormalStat.getDef();
}

unsigned int PKMN::Pokemon::getNormalSpAtt() const
{
    return m_Pokemon_NormalStat.getSpAtt();
}

unsigned int PKMN::Pokemon::getNormalSpDef() const
{
    return m_Pokemon_NormalStat.getSpDef();
}

unsigned int PKMN::Pokemon::getNormalSpeed() const
{
    return m_Pokemon_NormalStat.getSpeed();
}
