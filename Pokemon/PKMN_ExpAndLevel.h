#ifndef LEVELINGRATE_H
#define LEVELINGRATE_H

#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>

#define SLOW "SLOW"
#define MEDIUMSLOW "MEDIUMSLOW"
#define MEDIUMFAST "MEDIUMFAST"
#define FAST "FAST"
#define ERRATIC "ERRATIC"
#define FLUCTUATING "FLUCTUATING"

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
    void addExperience(unsigned int exp);
    unsigned int getExperience() const;
    unsigned int getLevel() const;

private:

    void addLevel();
    unsigned int expToNextLevel();
    unsigned int expLevel(unsigned int level);

    std::string m_Name;
    unsigned int m_Exp;
    unsigned int m_Level;
    unsigned int m_ExpToNextLevel;

};

#endif // LEVELINGRATE_H
