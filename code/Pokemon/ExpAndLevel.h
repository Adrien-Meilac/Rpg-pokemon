#ifndef PKMN_EXPANDLEVEL_H_INCLUDED
#define PKMN_EXPANDLEVEL_H_INCLUDED

#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define EXPANDLEVEL_SLOW           "Slow"
#define EXPANDLEVEL_MEDIUMSLOW     "Parabolic"
#define EXPANDLEVEL_MEDIUMFAST     "Medium"
#define EXPANDLEVEL_FAST           "Fast"
#define EXPANDLEVEL_ERRATIC        "Erratic"
#define EXPANDLEVEL_FLUCTUATING    "Fluctuating"


namespace PKMN
{
    class ExpAndLevel;
}


class PKMN::ExpAndLevel
{
public:

/// CONSTRUCTORS :

    ExpAndLevel();
    /** \brief
     *
     *
     */

    ExpAndLevel(std::string name, unsigned int level = 1, unsigned int exp = 0); // When read save file
        /** \brief
         *
         * \param name std::string :
         * \param unsigned int level = 1 :
         * \param unsigned int exp = 0 :
         *
         */

    ExpAndLevel(std::string name,
                std::pair<unsigned int, unsigned int> level_range);
        /** \brief To create a wild pokemon
         *
         * \param name std::string :
         * \param level_range std::pair<unsigned, unsigned int> :
         *
         */

/// DESTRUCTOR :

    ~ExpAndLevel();
        /** \brief
         *
         *
         */

/// GETTERS :

    unsigned int getExp() const;
        /** \brief
         *
         * \return unsigned int
         *
         */

    unsigned int getExpToNextLevel() const;
        /** \brief
         *
         * \return unsigned int
         *
         */

    unsigned int getTotalExp() const;
        /** \brief
         *
         * \return unsigned int
         *
         */

    unsigned int getLevel() const;
        /** \brief
         *
         * \return unsigned int
         *
         */

/// METHODS :

    void print() const;
        /** \brief
         *
         * \return void
         *
         */

    void addLevel();
        /** \brief
         *
         * \return void
         *
         */

private:

    unsigned int expToNextLevel() const;
        /** \brief
         *
         * \return unsigned int
         *
         */

    unsigned int expLevel(unsigned int level) const;
        /** \brief
         *
         * \param level unsigned int
         * \return unsigned int
         *
         */

/// MEMBER VARIABLES :

    std::string m_Name; /// Name of the growth
    unsigned int m_Exp; /// exp of a pokemon
    unsigned int m_Level; /// level of a pokemon
    unsigned int m_ExpToNextLevel; /// exp needed to level up, saved to avoid multiple calculus

};

#endif // PKMN_EXPANDLEVEL_H_INCLUDED
