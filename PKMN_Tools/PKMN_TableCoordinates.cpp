#include "PKMN_TableCoordinates.h"

PKMN_TableCoordinates::PKMN_TableCoordinates():
    m_pair("", "")
{

}

PKMN_TableCoordinates::PKMN_TableCoordinates(std::string x,
                                             std::string y):
    m_pair(x, y)
{

}

PKMN_TableCoordinates::PKMN_TableCoordinates(PKMN_TableCoordinates const& tc)
{
    m_pair = tc.m_pair;
}

PKMN_TableCoordinates& PKMN_TableCoordinates::operator=(PKMN_TableCoordinates const& tc)
{
    m_pair = tc.m_pair;
    return *this;
}

PKMN_TableCoordinates::~PKMN_TableCoordinates()
{
    delete &m_pair;
}

std::string PKMN_TableCoordinates::getLineName() const
{
    return m_pair.first;
}

std::string PKMN_TableCoordinates::getColumnName() const
{
    return m_pair.second;
}

bool operator==(PKMN_TableCoordinates const& tc1,
                PKMN_TableCoordinates const& tc2)
{
    return tc1.m_pair == tc2.m_pair;
}

bool operator<(PKMN_TableCoordinates const& tc1,
               PKMN_TableCoordinates const& tc2)
{
    return tc1.m_pair < tc2.m_pair;
}

bool operator>(PKMN_TableCoordinates const& tc1,
               PKMN_TableCoordinates const& tc2)
{
    return tc1.m_pair > tc2.m_pair;
}

bool operator<=(PKMN_TableCoordinates const& tc1,
                PKMN_TableCoordinates const& tc2)
{
    return !(tc1 > tc2);
}

bool operator>=(PKMN_TableCoordinates const& tc1,
                PKMN_TableCoordinates const& tc2)
{
    return !(tc1 < tc2);
}

bool operator!=(PKMN_TableCoordinates const& tc1,
                PKMN_TableCoordinates const& tc2)
{
    return !(tc1 == tc2);
}

std::ostream& operator<<(std::ostream& flux,
                         PKMN_TableCoordinates const& tc)
{
    flux << '(';
    flux << tc.m_pair.first;
    flux << ", ";
    flux << tc.m_pair.second;
    flux << ')';
    return flux;
}
