#include "StatSetExtended.h"

               /// CONSTRUCTORS ///

PKMN::StatSetExtended::StatSetExtended():
    PKMN::StatSet::StatSet(),
    m_Accuracy(100),
    m_Evasiveness(100),
    m_stage_Att(0),
    m_stage_Def(0),
    m_stage_SpAtt(0),
    m_stage_SpDef(0),
    m_stage_Speed(0),
    m_stage_Accuracy(0),
    m_stage_Evasiveness(0)
{

}

PKMN::StatSetExtended::StatSetExtended(int HP,
                                       int Att,
                                       int Def,
                                       int SpAtt,
                                       int SpDef,
                                       int Speed,
                                       int Accuracy,
                                       int Evasiveness):
    PKMN::StatSet::StatSet(HP,
                           Att,
                           Def,
                           SpAtt,
                           SpDef,
                           Speed)
{
    m_Accuracy = static_cast<double>(Accuracy);
    m_Evasiveness = static_cast<double>(Evasiveness);
    m_stage_Att = 0;
    m_stage_Def = 0;
    m_stage_SpAtt = 0;
    m_stage_SpDef = 0;
    m_stage_Speed = 0;
    m_stage_Accuracy = 0;
    m_stage_Evasiveness = 0;
}
PKMN::StatSetExtended::StatSetExtended(double HP,
                                       double Att,
                                       double Def,
                                       double SpAtt,
                                       double SpDef,
                                       double Speed,
                                       double Accuracy,
                                       double Evasiveness):
    PKMN::StatSet::StatSet(HP,
                           Att,
                           Def,
                           SpAtt,
                           SpDef,
                           Speed)
{
    m_Accuracy = Accuracy;
    m_Evasiveness = Evasiveness;
    m_stage_Att = 0;
    m_stage_Def = 0;
    m_stage_SpAtt = 0;
    m_stage_SpDef = 0;
    m_stage_Speed = 0;
    m_stage_Accuracy = 0;
    m_stage_Evasiveness = 0;
}

PKMN::StatSetExtended::StatSetExtended(std::string Stat)
{
    std::vector<std::string> L = PKMN::string_split(Stat, ',');
    if(L.size() == 6)
    {
        m_HP = PKMN::string_to_int(L[0]);
        m_Att = PKMN::string_to_int(L[1]);
        m_Def = PKMN::string_to_int(L[2]);
        m_SpAtt = PKMN::string_to_int(L[3]);
        m_SpDef = PKMN::string_to_int(L[4]);
        m_Speed = PKMN::string_to_int(L[5]);
    }
    m_Accuracy = 100;
    m_Evasiveness = 100;
    m_stage_Att = 0;
    m_stage_Def = 0;
    m_stage_SpAtt = 0;
    m_stage_SpDef = 0;
    m_stage_Speed = 0;
    m_stage_Accuracy = 0;
    m_stage_Evasiveness = 0;
}

PKMN::StatSetExtended::StatSetExtended(PKMN::StatSetExtended const& Other)
{
    m_HP = Other.m_HP;
    m_Att = Other.m_Att;
    m_Def = Other.m_Def;
    m_SpAtt = Other.m_SpAtt;
    m_SpDef = Other.m_SpDef;
    m_Speed = Other.m_Speed;
    m_Accuracy = Other.m_Accuracy;
    m_Evasiveness = Other.m_Evasiveness;
    m_stage_Att = 0;
    m_stage_Def = 0;
    m_stage_SpAtt = 0;
    m_stage_SpDef = 0;
    m_stage_Speed = 0;
    m_stage_Accuracy = 0;
    m_stage_Evasiveness = 0;
}

/// ///////////////////////////////////////// ///

                /// DESTRUCTOR ///

PKMN::StatSetExtended::~StatSetExtended()
{

}

/// ///////////////////////////////////////// ///

                /// GETTERS ///

int PKMN::StatSetExtended::getAccuracy() const
{
    return static_cast<int>(ceil(m_Accuracy));
}

int PKMN::StatSetExtended::getEvasiveness() const
{
    return static_cast<int>(ceil(m_Evasiveness));
}

/// ///////////////////////////////////////// ///

                /// METHODS ///

void PKMN::StatSetExtended::heal(const PKMN::StatSet& NormalStat)
{
    this->StatSet::operator=(NormalStat);
    m_Accuracy = 0;
    m_Evasiveness = 0;
    m_stage_Att = 0;
    m_stage_Def = 0;
    m_stage_SpAtt = 0;
    m_stage_SpDef = 0;
    m_stage_Speed = 0;
    m_stage_Accuracy = 0;
    m_stage_Evasiveness = 0;
}

void PKMN::StatSetExtended::outBattle()
{
    m_stage_Att = 0;
    m_stage_Def = 0;
    m_stage_SpAtt = 0;
    m_stage_SpDef = 0;
    m_stage_Speed = 0;
    m_stage_Accuracy = 0;
    m_stage_Evasiveness = 0;
}

void PKMN::StatSetExtended::decrementHP()
{
    m_HP -= 1;
}

/// ///////////////////////////////////////// ///

                /// FRIEND METHODS ///

namespace PKMN
{
std::ostream& operator<<(std::ostream &flux, StatSetExtended const& Stat)
{
    flux << "(";
    flux << Stat.m_HP << "; ";
    flux << Stat.m_Att << "; ";
    flux << Stat.m_Def << "; ";
    flux << Stat.m_SpAtt << "; ";
    flux << Stat.m_SpDef << "; ";
    flux << Stat.m_Speed << "; ";
    flux << Stat.m_Accuracy << "; ";
    flux << Stat.m_Evasiveness << ")";
    return flux;
}
}
