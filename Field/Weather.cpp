#include "Weather.h"

PKMN::Weather::Weather()
{
    m_InternalName = "";
}

PKMN::Weather::Weather(std::string weather)
{
    m_InternalName = weather;
}

PKMN::Weather::Weather(Weather const& other)
{
    m_InternalName = other.m_InternalName;
}

PKMN::Weather& PKMN::Weather::operator=(PKMN::Weather const& other)
{
    m_InternalName = other.m_InternalName;
    return *this;
}

PKMN::Weather::~Weather()
{

}

void PKMN::Weather::setWeather(std::string weather)
{
    m_InternalName = weather;
}
