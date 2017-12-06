#ifndef PKMN_EXPANDLEVEL_H_INCLUDED
#define PKMN_EXPANDLEVEL_H_INCLUDED

#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>

#define PKMN_EXPANDLEVEL_SLOW "SLOW"
#define PKMN_EXPANDLEVEL_MEDIUMSLOW "MEDIUMSLOW"
#define PKMN_EXPANDLEVEL_MEDIUMFAST "MEDIUMFAST"
#define PKMN_EXPANDLEVEL_FAST "FAST"
#define PKMN_EXPANDLEVEL_ERRATIC "ERRATIC"
#define PKMN_EXPANDLEVEL_FLUCTUATING "FLUCTUATING"

class PKMN_ExpAndLevel
{
public:

    PKMN_ExpAndLevel();
    PKMN_ExpAndLevel(std::string name,
                        unsigned int exp,
                        unsigned int level);
    PKMN_ExpAndLevel(std::string name,
                    unsigned int level);
    PKMN_ExpAndLevel(std::string name,
                    std::pair<unsigned int, unsigned int> level_range);
    PKMN_ExpAndLevel(std::string name);
    void addExperience(unsigned int exp);
    unsigned int getExperience() const;
    unsigned int getLevel() const;
    void addLevel();

private:

    unsigned int expToNextLevel();
    unsigned int expLevel(unsigned int level);

    std::string m_Name;
    unsigned int m_Exp;
    unsigned int m_Level;
    unsigned int m_ExpToNextLevel;

};

#endif // LEVELINGRATE_H
