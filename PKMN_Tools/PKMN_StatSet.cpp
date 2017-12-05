#include "PKMN_StatSet.h"

PKMN_StatSet::PKMN_StatSet(): // iv Génération algorithm
    m_HP(rand()%32),
    m_Att(rand()%32),
    m_Def(rand()%32),
    m_SpAtt(rand()%32),
    m_SpDef(rand()%32),
    m_Speed(rand()%32)
{

}

PKMN_StatSet::PKMN_StatSet(int HP, int Att, int Def, int SpAtt, int SpDef, int Speed)
{
    m_HP = static_cast<double>(HP);
    m_Att = static_cast<double>(Att);
    m_Def = static_cast<double>(Def);
    m_SpAtt = static_cast<double>(SpAtt);
    m_SpDef = static_cast<double>(SpDef);
    m_Speed = static_cast<double>(Speed);
}

PKMN_StatSet::PKMN_StatSet(double HP, double Att, double Def, double SpAtt, double SpDef, double Speed)
{
    m_HP = HP;
    m_Att = Att;
    m_Def = Def;
    m_SpAtt = SpAtt;
    m_SpDef = SpDef;
    m_Speed = Speed;
}

PKMN_StatSet::PKMN_StatSet(PKMN_StatSet const& Other)
{
    m_HP = Other.m_HP;
    m_Att = Other.m_Att;
    m_Def = Other.m_Def;
    m_SpAtt = Other.m_SpAtt;
    m_SpDef = Other.m_SpDef;
    m_Speed = Other.m_Speed;
}

PKMN_StatSet::~PKMN_StatSet()
{
    delete &m_HP;
    delete &m_Att;
    delete &m_Def;
    delete &m_SpAtt;
    delete &m_SpDef;
    delete &m_Speed;
}

int PKMN_StatSet::getHP() const
{
    return static_cast<int>(ceil(m_HP));
}

int PKMN_StatSet::getAtt() const
{
    return static_cast<int>(ceil(m_Att));
}

int PKMN_StatSet::getDef() const
{
    return static_cast<int>(ceil(m_Def));
}

int PKMN_StatSet::getSpAtt() const
{
    return static_cast<int>(ceil(m_SpAtt));
}

int PKMN_StatSet::getSpDef() const
{
    return static_cast<int>(ceil(m_SpDef));
}

int PKMN_StatSet::getSpeed() const
{
    return static_cast<int>(ceil(m_Speed));
}

PKMN_StatSet NormalStatistics(PKMN_StatSet const& Base,
                                          PKMN_StatSet const& IV,
                                          PKMN_StatSet const& EV,
                                          unsigned int level,
                                          std::string Nature)
{
    double HP = ceil((2 * Base.m_HP + IV.m_HP + ceil(EV.m_HP / 4)) * level / 100) + level + 10;
    double Att = ceil(((2 * Base.m_Att + IV.m_Att + ceil(EV.m_Att / 4)) * level / 100) + 5) * 1; // NatureEffect normalement
    double Def = ceil(((2 * Base.m_Def + IV.m_Def + ceil(EV.m_Def / 4)) * level / 100) + 5) * 1; // NatureEffect normalement
    double SpAtt = ceil(((2 * Base.m_SpAtt + IV.m_SpAtt + ceil(EV.m_SpAtt / 4)) * level / 100) + 5) * 1; // NatureEffect normalement
    double SpDef = ceil(((2 * Base.m_SpDef + IV.m_SpDef + ceil(EV.m_SpDef / 4)) * level / 100) + 5) * 1; // NatureEffect normalement
    double Speed = ceil(((2 * Base.m_Speed + IV.m_Speed + ceil(EV.m_Speed / 4)) * level / 100) + 5) * 1; // NatureEffect normalement
    return PKMN_StatSet(HP, Att, Def, SpAtt, SpDef, Speed);
}

std::ostream& operator<<(std::ostream &flux, PKMN_StatSet const& Stat)
{
    flux << "(";
    flux << Stat.m_HP << ", ";
    flux << Stat.m_Att << ", ";
    flux << Stat.m_Def << ", ";
    flux << Stat.m_SpAtt << ", ";
    flux << Stat.m_SpDef << ", ";
    flux << Stat.m_Speed << ")";
    return flux;
}
