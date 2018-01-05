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

std::string PKMN::Weather::getInternalName() const
{
    return m_InternalName;
}

std::string PKMN::Weather::endMessage() const
{
    if(m_InternalName == WEATHER_HAIL)
    {
        return "The hail stopped.";
    }
    else if(m_InternalName == WEATHER_HARSH_SUNLIGHT)
    {
        return "The sunlight faded.";
    }
    else if(m_InternalName == WEATHER_SANDSTORM)
    {
        return "The sandstorm subsided.";
    }
    else if(m_InternalName == WEATHER_RAIN)
    {
        return "The rain stopped.";
    }
    return "";
}

std::string PKMN::Weather::turnMessage() const
{
    if(m_InternalName == WEATHER_HAIL)
    {
        return "Hail continues to fall.";
    }
    else if(m_InternalName == WEATHER_HARSH_SUNLIGHT)
    {
        return "The sunlight is strong.";
    }
    else if(m_InternalName == WEATHER_SANDSTORM)
    {
        return "The sandstorm rages.";
    }
    else if(m_InternalName == WEATHER_RAIN)
    {
        return "Rain continues to fall";
    }
    return "";
}

std::string PKMN::Weather::startMessage(const PKMN::Move& mv)
{
    if(mv.getInternalName() == "DEFOG")
    {
        m_InternalName = WEATHER_CLEAR;
        return "";
    }
    else if(mv.getInternalName() == "SUNNYDAY")
    {
        m_InternalName = WEATHER_HARSH_SUNLIGHT;
        return "The sunlight turned harsh!";
    }
    else if(mv.getInternalName() == "RAINDANCE")
    {
        m_InternalName = WEATHER_RAIN;
        return "It started to rain!";
    }
    else if(mv.getInternalName() == "SANDSTORM")
    {
        m_InternalName = WEATHER_SANDSTORM;
        return "A sandstorm kicked up!";
    }
    else if(mv.getInternalName() == "HAIL")
    {
        m_InternalName = WEATHER_HAIL;
        return "It started to hail!";
    }
    return "";
}

bool PKMN::operator==(PKMN::Weather weather1, PKMN::Weather weather2)
{
    return weather1.getInternalName() == weather2.getInternalName();
}

bool PKMN::operator==(PKMN::Weather weather1, std::string weatherInternalName)
{
    return weather1.getInternalName() == weatherInternalName;
}

double PKMN::Weather::weatherEffect(const PKMN::Type& type) const
{
    if(m_InternalName == WEATHER_RAIN)
    {
        if(type == "FIRE")
        {
            return 0.5;
        }
        else if(type == "WATER")
        {
            return 1.5;
        }
    }
    else if(m_InternalName == WEATHER_HARSH_SUNLIGHT)
    {
        if(type == "FIRE")
        {
            return 1.5;
        }
        else if(type == "WATER")
        {
            return 0.5;
        }
    }
    return 1;
}
