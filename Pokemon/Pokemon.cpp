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
    std::vector<std::pair<unsigned int, Move> > L = read_move(table(Position, "Moves"));
    for(unsigned int i = 0; i < NB_OF_MOVE_PER_PKMN; i++)
    {
        m_Pokemon_Moves[i] = L[i];
    }
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

std::array<std::pair<unsigned int, PKMN::Move>, NB_OF_MOVE_PER_PKMN>* PKMN::Pokemon::getListMove()
{
    return &m_Pokemon_Moves;
}

void PKMN::Pokemon::decrementHP()
{
    m_Pokemon_CurrentStat.decrementHP();
}

void PKMN::Pokemon::incrementHP()
{
    m_Pokemon_CurrentStat.incrementHP();
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

unsigned int PKMN::Pokemon::getPPMove(unsigned int pos)
{
    return m_Pokemon_Moves[pos].first;
}

PKMN::Move* PKMN::Pokemon::getMove(unsigned int pos)
{
    return &m_Pokemon_Moves[pos].second;
}

void PKMN::Pokemon::decrementPPMove(unsigned int pos)
{
    m_Pokemon_Moves[pos].first -= 1;
}

bool PKMN::Pokemon::hasPPMove(unsigned int pos)
{
    return getPPMove(pos) > 0;
}

double PKMN::Pokemon::STABmultiplicator(const PKMN::Move& mv) const
{
    if(mv.getType() == m_Type.first || mv.getType() == m_Type.second)
    {
        return 1.5;
    }
    return 1;
}

bool PKMN::isPkmn1attackingBeforePkmn2(const PKMN::Pokemon* pkmn1,
                                       const PKMN::Move* move1,
                                       const PKMN::Pokemon* pkmn2,
                                       const PKMN::Move* move2)
{
    if(move1->getPriority() > move2->getPriority())
    {
        return true;
    }
    else if(move1->getPriority() == move2->getPriority() && pkmn1->getCurSpeed() >= pkmn2->getCurSpeed())
    {
        return true;
    }
    return false;
}

std::string PKMN::Pokemon::getBattleImage(bool isFoe) const
{
    std::string path = "./Pictures/Pokemon/Battle/";
    if(m_ID.size() == 2)
    {
        path += "0";
    }
    else if(m_ID.size() == 1)
    {
        path += "00";
    }
    path += m_ID;
    if(m_IsShiney)
    {
        path += "s";
    }
    if(!isFoe)
    {
        path += "b";
    }
    return path + ".png";
}

std::string PKMN::Pokemon::getIcon() const
{
    std::string path = "./Pictures/Pokemon/Icon/icon";
    if(m_ID.size() == 2)
    {
        path += "0";
    }
    else if(m_ID.size() == 1)
    {
        path += "00";
    }
    return path + m_ID + ".png";
}
