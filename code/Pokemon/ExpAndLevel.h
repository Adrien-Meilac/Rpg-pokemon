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

    ExpAndLevel(std::string name, unsigned int level = 1, unsigned int exp = 0); // When read save file
        /** \brief construct a growth structure with the type of growth
         *
         * \param name std::string : Type of growth
         * \param unsigned int level = 1 : level of the pokemon
         * \param unsigned int exp = 0 : exp of the pokemon
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

/// GETTERS :

    unsigned int getExp() const;
        /** \brief get the current exp of the pokemon
         *
         * \return unsigned int
         *
         */

    unsigned int getExpToNextLevel() const;
        /** \brief get the necessary exp to level up
         *
         * \return unsigned int
         *
         */

    unsigned int getTotalExp() const;
        /** \brief get the total exp of a pokemon
         *
         * \return unsigned int
         *
         */

    unsigned int getLevel() const;
        /** \brief get the level of a pokemon
         *
         * \return unsigned int
         *
         */

/// METHODS :

    void print() const;
        /** \brief print a ExpAndLevel Structure
         *
         * \return void
         *
         */

    void addLevel();
        /** \brief Add one level to the pokemon
         *
         * \return void
         *
         */

private:

    unsigned int expToNextLevel() const;
        /** \brief calculate the exp to the next level
         *
         * \return unsigned int
         *
         */

    unsigned int expLevel(unsigned int level) const;
        /** \brief Calculate the exp at a precise level
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
