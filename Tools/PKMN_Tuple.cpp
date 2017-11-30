#include "PKMN_Tuple.h"

PKMN_Tuple::PKMN_Tuple():
    m_x(),
    m_y()
{

}

PKMN_Tuple::PKMN_Tuple(std::string x, std::string y):
    m_x(x),
    m_y(y)
{

}

PKMN_Tuple::PKMN_Tuple(PKMN_Tuple const& Tuple)
{
    m_x = Tuple.m_x;
    m_y = Tuple.m_y;
}

PKMN_Tuple& PKMN_Tuple::operator=(PKMN_Tuple const& Tuple)
{
    m_x = Tuple.m_x;
    m_y = Tuple.m_y;
    return *this;
}

PKMN_Tuple::~PKMN_Tuple()
{
    delete &m_x;
    delete &m_y;
}

std::string PKMN_Tuple::getx() const
{
    return m_x;
}

std::string PKMN_Tuple::gety() const
{
    return m_y;
}

bool operator==(PKMN_Tuple const& Tuple1, PKMN_Tuple const& Tuple2)
{
    return (Tuple1.getx() == Tuple2.getx()) && (Tuple1.gety() == Tuple2.gety());
}

bool operator<(PKMN_Tuple const& Tuple1, PKMN_Tuple const& Tuple2)
{
    return ((Tuple1.getx() < Tuple2.getx()) || ((Tuple1.getx() == Tuple2.getx()) && (Tuple1.gety() < Tuple2.gety())));
}

bool operator>(PKMN_Tuple const& Tuple1, PKMN_Tuple const& Tuple2)
{
    return ((Tuple1.getx() > Tuple2.getx()) || ((Tuple1.getx() == Tuple2.getx()) && (Tuple1.gety() > Tuple2.gety())));
}

bool operator<=(PKMN_Tuple const& Tuple1, PKMN_Tuple const& Tuple2)
{
    return !(Tuple1 > Tuple2);
}

bool operator>=(PKMN_Tuple const& Tuple1, PKMN_Tuple const& Tuple2)
{
    return !(Tuple1 < Tuple2);
}

bool operator!=(PKMN_Tuple const& Tuple1, PKMN_Tuple const& Tuple2)
{
    return !(Tuple1 == Tuple2);
}

