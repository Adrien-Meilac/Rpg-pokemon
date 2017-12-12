#include "PKMN_StatSet.h"

PKMN_StatSet::PKMN_StatSet() // for IV generation
{
    m_HP = rand() % 32;
    m_Att = rand() % 32;
    m_Def = rand() % 32;
    m_SpAtt = rand() % 32;
    m_SpDef = rand() % 32;
    m_Speed = rand() % 32;
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

PKMN_StatSet::PKMN_StatSet(std::string Stat)
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
//    std::cout << "Statstruct deleted" << std::endl;
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

PKMN_StatSet NormalStatistics(PKMN_StatSet const Base,
                                          PKMN_StatSet const IV,
                                          PKMN_StatSet const EV,
                                          unsigned int level,
                                          std::string Nature)
{
    double HP = floor((2 * Base.m_HP + IV.m_HP + floor(EV.m_HP / 4)) * level / 100) + level + 10;
    double Att = floor(((2 * Base.m_Att + IV.m_Att + floor(EV.m_Att / 4)) * level / 100) + 5) * 1; // NatureEffect normalement
    double Def = floor(((2 * Base.m_Def + IV.m_Def + floor(EV.m_Def / 4)) * level / 100) + 5) * 1; // NatureEffect normalement
    double SpAtt = floor(((2 * Base.m_SpAtt + IV.m_SpAtt + floor(EV.m_SpAtt / 4)) * level / 100) + 5) * 1; // NatureEffect normalement
    double SpDef = floor(((2 * Base.m_SpDef + IV.m_SpDef + floor(EV.m_SpDef / 4)) * level / 100) + 5) * 1; // NatureEffect normalement
    double Speed = floor(((2 * Base.m_Speed + IV.m_Speed + floor(EV.m_Speed / 4)) * level / 100) + 5) * 1; // NatureEffect normalement
    return PKMN_StatSet(HP, Att, Def, SpAtt, SpDef, Speed);
}

std::ostream& operator<<(std::ostream &flux, PKMN_StatSet const& Stat)
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

//int PKMN_StatSet::getStat(std::string name) const
//{
//    if(name == PKMN_STATSET_HP)
//    {
//        return getHP();
//    }
//    else if(name == PKMN_STATSET_ATT)
//    {
//        return getAtt();
//    }
//    else if(name == PKMN_STATSET_DEF)
//    {
//        return getDef();
//    }
//        else if(name == PKMN_STATSET_SPATT)
//    {
//        return getSpAtt();
//    }
//    else if(name == PKMN_STATSET_SPDEF)
//    {
//        return getSpDef();
//    }
//        else if(name == PKMN_STATSET_SPEED)
//    {
//        return getSpeed();
//    }
//    return 0;
//}
//
//void PKMN_StatSet::statSwap(std::string name1, std::string name2)
//{
//    if((name1 == PKMN_STATSET_HP && name2 == PKMN_STATSET_ATT)||(name2 == PKMN_STATSET_HP && name1 == PKMN_STATSET_ATT))
//    {
//        statSwapHPAtt();
//    }
//    else if((name1 == PKMN_STATSET_HP && name2 == PKMN_STATSET_DEF)||(name2 == PKMN_STATSET_HP && name1 == PKMN_STATSET_DEF))
//    {
//        statSwapHPDef();
//    }
//    else if((name1 == PKMN_STATSET_HP && name2 == PKMN_STATSET_SPATT)||(name2 == PKMN_STATSET_HP && name1 == PKMN_STATSET_SPATT))
//    {
//        statSwapHPSpAtt();
//    }
//    else if((name1 == PKMN_STATSET_HP && name2 == PKMN_STATSET_SPDEF)||(name2 == PKMN_STATSET_HP && name1 == PKMN_STATSET_SPDEF))
//    {
//        statSwapHPSpDef();
//    }
//    else if((name1 == PKMN_STATSET_HP && name2 == PKMN_STATSET_SPEED)||(name2 == PKMN_STATSET_HP && name1 == PKMN_STATSET_SPEED))
//    {
//        statSwapHPSpeed();
//    }
//    else if((name1 == PKMN_STATSET_ATT && name2 == PKMN_STATSET_DEF)||(name2 == PKMN_STATSET_ATT && name1 == PKMN_STATSET_DEF))
//    {
//        statSwapAttDef();
//    }
//    else if((name1 == PKMN_STATSET_ATT && name2 == PKMN_STATSET_SPATT)||(name2 == PKMN_STATSET_ATT && name1 == PKMN_STATSET_SPATT))
//    {
//        statSwapAttSpAtt();
//    }
//    else if((name1 == PKMN_STATSET_ATT && name2 == PKMN_STATSET_SPDEF)||(name2 == PKMN_STATSET_ATT && name1 == PKMN_STATSET_SPDEF))
//    {
//        statSwapAttSpDef();
//    }
//    else if((name1 == PKMN_STATSET_ATT && name2 == PKMN_STATSET_SPEED)||(name2 == PKMN_STATSET_ATT && name1 == PKMN_STATSET_SPEED))
//    {
//        statSwapAttSpeed();
//    }
//    else if((name1 == PKMN_STATSET_DEF && name2 == PKMN_STATSET_SPATT)||(name2 == PKMN_STATSET_DEF && name1 == PKMN_STATSET_SPATT))
//    {
//        statSwapDefSpAtt();
//    }
//    else if((name1 == PKMN_STATSET_DEF && name2 == PKMN_STATSET_SPDEF)||(name2 == PKMN_STATSET_DEF && name1 == PKMN_STATSET_SPDEF))
//    {
//        statSwapDefSpDef();
//    }
//    else if((name1 == PKMN_STATSET_DEF && name2 == PKMN_STATSET_SPATT)||(name2 == PKMN_STATSET_DEF && name1 == PKMN_STATSET_SPATT))
//    {
//        statSwapDefSpeed();
//    }
//    else if((name1 == PKMN_STATSET_SPATT && name2 == PKMN_STATSET_SPDEF)||(name2 == PKMN_STATSET_SPATT && name1 == PKMN_STATSET_SPDEF))
//    {
//        statSwapSpAttSpDef();
//    }
//    else if((name1 == PKMN_STATSET_SPATT && name2 == PKMN_STATSET_SPEED)||(name2 == PKMN_STATSET_SPATT && name1 == PKMN_STATSET_SPEED))
//    {
//        statSwapSpAttSpeed();
//    }
//    else if((name1 == PKMN_STATSET_SPDEF && name2 == PKMN_STATSET_SPEED)||(name2 == PKMN_STATSET_SPDEF && name1 == PKMN_STATSET_SPEED))
//    {
//        statSwapSpDefSpeed();
//    }
//}
//
//void PKMN_StatSet::statSwapHPAtt()
//{
//    double c;
//    c = m_HP;
//    m_HP = m_Att;
//    m_Att = c;
//}
//
//void PKMN_StatSet::statSwapHPDef()
//{
//    double c;
//    c = m_HP;
//    m_HP = m_Def;
//    m_Def = c;
//}
//
//void PKMN_StatSet::statSwapHPSpAtt()
//{
//    double c;
//    c = m_HP;
//    m_HP = m_SpAtt;
//    m_SpAtt = c;
//}
//
//void PKMN_StatSet::statSwapHPSpDef()
//{
//    double c;
//    c = m_HP;
//    m_HP = m_SpDef;
//    m_SpDef = c;
//}
//
//void PKMN_StatSet::statSwapHPSpeed()
//{
//    double c;
//    c = m_HP;
//    m_HP = m_Speed;
//    m_Speed = c;
//}
//
//void PKMN_StatSet::statSwapAttDef()
//{
//    double c;
//    c = m_Att;
//    m_Att = m_Def;
//    m_Def = c;
//}
//
//void PKMN_StatSet::statSwapAttSpAtt()
//{
//    double c;
//    c = m_Att;
//    m_Att = m_SpAtt;
//    m_SpAtt = c;
//}
//
//void PKMN_StatSet::statSwapAttSpDef()
//{
//    double c;
//    c = m_Att;
//    m_Att = m_SpDef;
//    m_SpDef = c;
//}
//
//void PKMN_StatSet::statSwapAttSpeed()
//{
//    double c;
//    c = m_Att;
//    m_Att = m_Speed;
//    m_Speed = c;
//}
//
//void PKMN_StatSet::statSwapDefSpAtt()
//{
//    double c;
//    c = m_Def;
//    m_Def = m_SpAtt;
//    m_SpAtt = c;
//}
//
//void PKMN_StatSet::statSwapDefSpDef()
//{
//    double c;
//    c = m_Def;
//    m_Def = m_SpDef;
//    m_SpDef = c;
//}
//
//void PKMN_StatSet::statSwapDefSpeed()
//{
//    double c;
//    c = m_Def;
//    m_Def = m_Speed;
//    m_Speed = c;
//}
//
//void PKMN_StatSet::statSwapSpAttSpDef()
//{
//    double c;
//    c = m_SpAtt;
//    m_SpAtt = m_SpDef;
//    m_SpDef = c;
//}
//
//void PKMN_StatSet::statSwapSpAttSpeed()
//{
//    double c;
//    c = m_SpAtt;
//    m_SpAtt = m_Speed;
//    m_Speed = c;
//}
//
//void PKMN_StatSet::statSwapSpDefSpeed()
//{
//    double c;
//    c = m_SpDef;
//    m_SpDef = m_Speed;
//    m_Speed = c;
//}

