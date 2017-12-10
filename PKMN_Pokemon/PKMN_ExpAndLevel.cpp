#include "PKMN_ExpAndLevel.h"

                /// CONSTRUCTORS ///

PKMN_ExpAndLevel::PKMN_ExpAndLevel()
{

}

PKMN_ExpAndLevel::~PKMN_ExpAndLevel()
{
    std::cout << m_Name << " : PKMN_ExpAndLevel destructed" << std::endl;
}

PKMN_ExpAndLevel::PKMN_ExpAndLevel(std::string name,
                                    unsigned int level,
                                    unsigned int exp)
{
    m_Name = name;
    m_Exp = exp;
    m_Level = level;
    m_ExpToNextLevel = this->expToNextLevel();
}

//PKMN_ExpAndLevel::PKMN_ExpAndLevel(std::string name,
//                                    unsigned int level)
//{
//    m_Name = name;
//    m_Level = level;
//    m_Exp = 0;
//    m_ExpToNextLevel = this->expToNextLevel();
//}
//
//PKMN_ExpAndLevel::PKMN_ExpAndLevel(std::string name)
//{
//    m_Name = name;
//    m_Exp = 0;
//    m_Level = 1;
//    m_ExpToNextLevel = this->expToNextLevel();
//}

PKMN_ExpAndLevel::PKMN_ExpAndLevel(std::string name,
                                std::pair<unsigned int, unsigned int> level_range)
{
    m_Name = name;
    m_Exp = 0;
    m_Level = rand() % (level_range.second - level_range.first) + level_range.first;
    m_ExpToNextLevel = this->expToNextLevel();
}

unsigned int PKMN_ExpAndLevel::expToNextLevel() const
{
    return this->expLevel(m_Level + 1) - this->expLevel(m_Level);
}


unsigned int PKMN_ExpAndLevel::expLevel(unsigned int level) const
{
	double n = static_cast<double>(level);
	if(m_Name == PKMN_EXPANDLEVEL_FAST)
    {
        return static_cast<int>(ceil(4 * pow(n, 3) / 5));
    }
	else if(m_Name == PKMN_EXPANDLEVEL_MEDIUMFAST)
    {
        return static_cast<int>(pow(n, 3));
    }
	else if(m_Name == PKMN_EXPANDLEVEL_MEDIUMSLOW)
    {
		return static_cast<int>(ceil(6 * pow(n, 3) / 5 - 15 * pow(n, 2) + 100 * n - 140));
    }
	else if(m_Name == PKMN_EXPANDLEVEL_SLOW)
    {
        return static_cast<int>(ceil(5 * pow(n, 3) / 4));
    }
	else if(m_Name == PKMN_EXPANDLEVEL_ERRATIC)
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
    else if(m_Name == PKMN_EXPANDLEVEL_FLUCTUATING)
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

unsigned int PKMN_ExpAndLevel::getExp() const
{
    return m_Exp;
}

unsigned int PKMN_ExpAndLevel::getLevel() const
{
    return m_Level;
}


void PKMN_ExpAndLevel::addLevel()
{
    m_Exp = 0;
    if(m_Level < 100)
    {
        m_Level += 1;
        m_ExpToNextLevel = this->expToNextLevel();
    }
    else
    {
        m_ExpToNextLevel = 0;
    }

}

unsigned int PKMN_ExpAndLevel::getExpToNextLevel() const
{
    return m_ExpToNextLevel;
}

unsigned int PKMN_ExpAndLevel::getTotalExp() const
{
    return this->expLevel(m_Level) + m_Exp;
}

void PKMN_ExpAndLevel::print() const
{
    std::cout << "PKMN_ExpAndLevel " << m_Name << std::endl;
    std::cout << "\t" << "Exp = " << m_Exp << std::endl;
    std::cout << "\t" << "Level = " << m_Level << std::endl;
    std::cout << "\t" << "ExpToNextLevel = " << m_ExpToNextLevel << std::endl;
    std::cout << "\t" << "ExpToNextLevel = " << m_ExpToNextLevel << std::endl;
}

