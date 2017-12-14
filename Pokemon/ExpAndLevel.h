#ifndef PKMN_EXPANDLEVEL_H_INCLUDED
#define PKMN_EXPANDLEVEL_H_INCLUDED

#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define PKMN_EXPANDLEVEL_SLOW "Slow"
#define PKMN_EXPANDLEVEL_MEDIUMSLOW "Parabolic"
#define PKMN_EXPANDLEVEL_MEDIUMFAST "Medium"
#define PKMN_EXPANDLEVEL_FAST "Fast"
#define PKMN_EXPANDLEVEL_ERRATIC "Erratic"
#define PKMN_EXPANDLEVEL_FLUCTUATING "Fluctuating"

class PKMN_ExpAndLevel
{
public:

    PKMN_ExpAndLevel();
    PKMN_ExpAndLevel(std::string name,
                        unsigned int level = 1,
                        unsigned int exp = 0); // When read save file
//    PKMN_ExpAndLevel(std::string name,
//                    unsigned int level); // When create a dressor pokemon
    PKMN_ExpAndLevel(std::string name,
                    std::pair<unsigned int, unsigned int> level_range); // when create a wild pokemon
    //PKMN_ExpAndLevel(std::string name); // when create a pokemon from an egg

    void addLevel();

    unsigned int getExp() const;
    unsigned int getExpToNextLevel() const;
    unsigned int getTotalExp() const;
    unsigned int getLevel() const;
    void print() const;

    ~PKMN_ExpAndLevel();

private:

    unsigned int expToNextLevel() const;
    unsigned int expLevel(unsigned int level) const;

    std::string m_Name;
    unsigned int m_Exp;
    unsigned int m_Level;
    unsigned int m_ExpToNextLevel;

};

#endif // PKMN_EXPANDLEVEL_H_INCLUDED
