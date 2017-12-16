#include "Place.h"

PKMN::Place::Place()
{
    m_InternalName = "";
}

PKMN::Place::Place(std::string InternalName)
{
    PKMN::Table table(FILE_PKMN_PLACE);
    m_InternalName = InternalName;
    m_Name = table(InternalName, "Name");
    m_Weather = PKMN::Weather(table(InternalName, "Weather"));
}

PKMN::Place::Place(PKMN::Place const& other)
{

}

PKMN::Place& PKMN::Place::operator=(PKMN::Place const& other)
{
    m_InternalName = other.m_InternalName;
    m_Name = other.m_Name;
    m_Weather = other.m_Weather;
    return *this;
}

PKMN::Place::~Place()
{

}

PKMN::Weather PKMN::Place::getWeather() const
{
    return m_Weather;
}

std::string PKMN::Place::getName() const
{
    return m_Name;
}

std::string PKMN::Place::getInternalName() const
{
    return m_InternalName;
}
