#include "PKMN_ExpAndLevel.h"

PKMN_ExpAndLevel::PKMN_ExpAndLevel():
    m_Name(),
    m_Exp(),
    m_Level(),
    m_ExpToNextLevel()
{

}

PKMN_ExpAndLevel::PKMN_ExpAndLevel(std::string name,
                        unsigned int exp,
                        unsigned int level)
{
    m_Name = name;
    m_Exp = exp;
    m_Level = level;
    m_ExpToNextLevel = expToNextLevel();
}

PKMN_ExpAndLevel::PKMN_ExpAndLevel(std::string name,
                                    unsigned int level)
{
    m_Name = name;
    m_Exp = 0;
    m_Level = level;
    m_ExpToNextLevel = expToNextLevel();
}

PKMN_ExpAndLevel::PKMN_ExpAndLevel(std::string name,
                                std::pair<unsigned int, unsigned int> level_range)
{
    m_Name = name;
    m_Exp = 0;
    m_Level = rand() % (level_range.second - level_range.first) + level_range.first;
    m_ExpToNextLevel = expToNextLevel();
}

unsigned int PKMN_ExpAndLevel::expToNextLevel()
{
    return expLevel(m_Level + 1) - expLevel(m_Level);
}


unsigned int PKMN_ExpAndLevel::expLevel(unsigned int level)
{
	double n = static_cast<double>(level);
	if(m_Name == FAST)
    {
        return static_cast<int>(ceil(4 * pow(n, 3) / 5));
    }
	else if(m_Name == MEDIUMFAST)
    {
        return static_cast<int>(pow(n, 3));
    }
	else if(m_Name == MEDIUMSLOW)
    {
		return static_cast<int>(ceil(6 * pow(n, 3) / 5 - 15 * pow(n, 2) + 100 * n - 140));
    }
	else if(m_Name == SLOW)
    {
        return static_cast<int>(ceil(5 * pow(n, 3) / 4));
    }
	else if(m_Name == ERRATIC)
    {
        if(level <= 50)
        {
            return static_cast<int>(ceil(pow(n,3) * (100 - n) / 50));
        }
        else if(level <= 68)
        {
            return static_cast<int>(ceil(pow(n, 3) * (150 - n) / 100));
        }
        else if(level <= 98)
        {
            return static_cast<int>(ceil(pow(n, 3) * ceil((1911 - 10 * n) / 3) / 500));
        }
        else
        {
            return static_cast<int>(ceil(pow(n, 3) * (160 - n) / 100));
        }
    }
    else if(m_Name == FLUCTUATING)
    {
        if(level <= 15)
        {
            return static_cast<int>(ceil(pow(n,3) * (ceil((n + 1) / 3) + 24) / 50));
        }
        else if(level <= 36)
        {
            return static_cast<int>(ceil(pow(n,3) * (n + 14) / 50));
        }
        else
        {
            return static_cast<int>(ceil(pow(n,3) * (ceil(n / 2) + 24) / 50));
        }
    }
    return 0;
}

unsigned int PKMN_ExpAndLevel::getExperience() const
{
    return m_Exp;
}

unsigned int PKMN_ExpAndLevel::getLevel() const
{
    return m_Level;
}

void PKMN_ExpAndLevel::addExperience(unsigned int exp)
{
    m_Exp += exp;
    while(m_ExpToNextLevel < m_Exp)
    {
        addLevel();
        m_Exp = m_Exp - m_ExpToNextLevel;
        m_ExpToNextLevel = expToNextLevel();
    }
    if(m_Level ==100)
    {
        m_Exp = 0;
    }
}


void PKMN_ExpAndLevel::addLevel()
{
    if(m_Level < 100)
    {
        m_Level += 1;
    }
}
