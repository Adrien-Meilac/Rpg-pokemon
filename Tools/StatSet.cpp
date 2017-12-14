#include "StatSet.h"

               /// CONSTRUCTORS ///

PKMN::StatSet::StatSet(): // for IV generation
    m_HP(0),
    m_Att(0),
    m_Def(0),
    m_SpAtt(0),
    m_SpDef(0),
    m_Speed(0)
{

}


PKMN::StatSet::StatSet(int HP,
                       int Att,
                       int Def,
                       int SpAtt,
                       int SpDef,
                       int Speed)
{
    m_HP = static_cast<double>(HP);
    m_Att = static_cast<double>(Att);
    m_Def = static_cast<double>(Def);
    m_SpAtt = static_cast<double>(SpAtt);
    m_SpDef = static_cast<double>(SpDef);
    m_Speed = static_cast<double>(Speed);
}

PKMN::StatSet::StatSet(double HP,
                       double Att,
                       double Def,
                       double SpAtt,
                       double SpDef,
                       double Speed)
{
    m_HP = HP;
    m_Att = Att;
    m_Def = Def;
    m_SpAtt = SpAtt;
    m_SpDef = SpDef;
    m_Speed = Speed;
}

PKMN::StatSet::StatSet(std::string Stat)
{
    std::vector<std::string> L = string_split(Stat, ',');
    if(L.size() == 6)
    {
        m_HP = string_to_int(L[0]);
        m_Att = string_to_int(L[1]);
        m_Def = string_to_int(L[2]);
        m_SpAtt = string_to_int(L[3]);
        m_SpDef = string_to_int(L[4]);
        m_Speed = string_to_int(L[5]);
    }
}

PKMN::StatSet::StatSet(PKMN::StatSet const& Other)
{
    m_HP = Other.m_HP;
    m_Att = Other.m_Att;
    m_Def = Other.m_Def;
    m_SpAtt = Other.m_SpAtt;
    m_SpDef = Other.m_SpDef;
    m_Speed = Other.m_Speed;
}

/// ///////////////////////////////////////// ///

                /// DESTRUCTOR ///

PKMN::StatSet::~StatSet()
{

}

/// ///////////////////////////////////////// ///

                /// GETTERS ///

int PKMN::StatSet::getHP() const
{
    return static_cast<int>(ceil(m_HP));
}

int PKMN::StatSet::getAtt() const
{
    return static_cast<int>(ceil(m_Att));
}

int PKMN::StatSet::getDef() const
{
    return static_cast<int>(ceil(m_Def));
}

int PKMN::StatSet::getSpAtt() const
{
    return static_cast<int>(ceil(m_SpAtt));
}

int PKMN::StatSet::getSpDef() const
{
    return static_cast<int>(ceil(m_SpDef));
}

int PKMN::StatSet::getSpeed() const
{
    return static_cast<int>(ceil(m_Speed));
}

/// ///////////////////////////////////////// ///

                /// METHODS ///

void PKMN::StatSet::zeros()
{
    m_HP = 0;
    m_Att = 0;
    m_Def = 0;
    m_SpAtt = 0;
    m_SpDef = 0;
    m_Speed = 0;
}

void PKMN::StatSet::random(unsigned int mod)
{
    m_HP = rand() % mod;
    m_Att = rand() % mod;
    m_Def = rand() % mod;
    m_SpAtt = rand() % mod;
    m_SpDef = rand() % mod;
    m_Speed = rand() % mod;
}

namespace PKMN
{
StatSet NormalStatistics(StatSet const Base,
                         StatSet const IV,
                         StatSet const EV,
                         unsigned int level,
                         std::string Nature)
{
    double HP = floor((2 * Base.m_HP + IV.m_HP + floor(EV.m_HP / 4)) * level / 100) + level + 10;
    double Att = floor(((2 * Base.m_Att + IV.m_Att + floor(EV.m_Att / 4)) * level / 100) + 5) * 1; // NatureEffect normalement
    double Def = floor(((2 * Base.m_Def + IV.m_Def + floor(EV.m_Def / 4)) * level / 100) + 5) * 1; // NatureEffect normalement
    double SpAtt = floor(((2 * Base.m_SpAtt + IV.m_SpAtt + floor(EV.m_SpAtt / 4)) * level / 100) + 5) * 1; // NatureEffect normalement
    double SpDef = floor(((2 * Base.m_SpDef + IV.m_SpDef + floor(EV.m_SpDef / 4)) * level / 100) + 5) * 1; // NatureEffect normalement
    double Speed = floor(((2 * Base.m_Speed + IV.m_Speed + floor(EV.m_Speed / 4)) * level / 100) + 5) * 1; // NatureEffect normalement
    return StatSet(HP, Att, Def, SpAtt, SpDef, Speed);
}
}

namespace PKMN
{
std::ostream& operator<<(std::ostream &flux, StatSet const& Stat)
{
    flux << "(";
    flux << Stat.m_HP << "; ";
    flux << Stat.m_Att << "; ";
    flux << Stat.m_Def << "; ";
    flux << Stat.m_SpAtt << "; ";
    flux << Stat.m_SpDef << "; ";
    flux << Stat.m_Speed << ")";
    return flux;
}
}
