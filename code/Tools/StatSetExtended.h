#ifndef PKMN_STATSETEXTENDED_H_INCLUDED
#define PKMN_STATSETEXTENDED_H_INCLUDED

#include "StatSet.h"

#include <iostream>
#include <cmath>

namespace PKMN
{
    class StatSetExtended;
}

class PKMN::StatSetExtended : public PKMN::StatSet
/** Inherit from StatSet, this class will be used to contain current life
    of the pokemon **/
{
public :

/// CONSTRUCTORS :

    StatSetExtended();
        /** \brief Construct a StatSet as a zero vector
         *
         */

    StatSetExtended(int HP,
                    int Att,
                    int Def,
                    int SpAtt,
                    int SpDef,
                    int Speed,
                    int Accuracy = 100,
                    int Evasiveness = 100);
        /** \brief Construct a StatSetExtended with int values
         *   (changing them into double)
         *
         * \param HP int : HP value for m_HP
         * \param Att int : Att value for m_Att
         * \param Def int : Def value for m_Def
         * \param SpAtt int : SpAtt value for m_SpAtt
         * \param SpDef int : SpDef value for m_SpDef
         * \param Speed int : Speed value for m_Speed
         * \param Accuracy int : Accuracy value for m_Accuracy
         * \param Evasiveness int : Evasiveness value for m_Evasiveness
         *
         */

    StatSetExtended(double HP,
                    double Att,
                    double Def,
                    double SpAtt,
                    double SpDef,
                    double Speed,
                    double Accuracy = 100,
                    double Evasiveness = 100);
        /** \brief Construct a StatSetExtended with double values
         *
         * \param HP double : HP value for m_HP
         * \param Att double : Att value for m_Att
         * \param Def double : Def value for m_Def
         * \param SpAtt double : SpAtt value for m_SpAtt
         * \param SpDef double : SpDef value for m_SpDef
         * \param Speed double : Speed value for m_Speed
         * \param Accuracy double : Accuracy value for m_Accuracy
         * \param Evasiveness double : Evasiveness value for m_Evasiveness
         *
         */

    StatSetExtended(std::string Stat);
        /** \brief Transform a list of value separated by the char delimitor ',' into StatSetExtended
         *
         * \param Stat std::string : for example "232,121,12,78,32,90,100,100" (8 values)
         * will give the StatSetExtended (232, 121, 12, 78, 32, 90,100, 100)
         *
         */

    StatSetExtended(StatSetExtended const& Other);
        /** \brief Copy constructor for function (no reference)
         *
         * \param Other StatSetExtended const& : Other StatSetExtended to copy
         *
         */

/// DESTRUCTOR :

    ~StatSetExtended();


/// GETTERS :

    int getAccuracy() const;
        /** \brief Return the Accuracy value of the StatSet
         *
         * \return int : Accuracy value
         *
         */

    int getEvasiveness() const;
        /** \brief Return the Evasiveness value of the StatSet
         *
         * \return int : Evasiveness value
         *
         */

/// METHODS :

    void heal(const StatSet& NormalStat);
        /** \brief Put Normal Stat into Current Statset
         *
         *
         */

    void outBattle();
        /** \brief Stage are reseted to 0 but stat remains current
         *
         *
         */

    void decrementHP();
        /** \brief HP are decreased from 1 point
         *
         *
         */

    void incrementHP();
        /** \brief HP are increased from 1 point
         *
         *
         */

private:

/// FRIEND FUNCTION :

    friend std::ostream& operator<<(std::ostream &flux, StatSetExtended const& Stat);
        /** \brief
         *
         * \param flux std::ostream&
         * \param Stat StatSet const&
         * \return friend std::ostream&
         *
         */

/// MEMBER VARIABLES :
    double m_Accuracy; /// Accuracy point
    double m_Evasiveness; /// Evasiveness point

    int m_stage_Att; /// Bonus / Malus in battle of Att
    int m_stage_Def; /// Bonus / Malus in battle of Def
    int m_stage_SpAtt; /// Bonus / Malus in battle of SpAtt
    int m_stage_SpDef; /// Bonus / Malus in battle of SpDef
    int m_stage_Speed; /// Bonus / Malus in battle of Speed
    int m_stage_Accuracy; /// Bonus / Malus in battle of Accuracy
    int m_stage_Evasiveness; /// Bonus / Malus in battle of Evasiveness

};

#endif // PKMN_STATSETEXTENDED_H_INCLUDED
