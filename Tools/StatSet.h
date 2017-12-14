#ifndef PKMN_STATSET_H_INCLUDED
#define PKMN_STATSET_H_INCLUDED

#include "Conversion.h"
#include "VectorMethod.h"

#include <cmath> // For pow function
#include <iostream> // For ostream flux
#include <cstdlib> // for rand()
#include <ctime> // for rand()
#include <vector> // for spliting statset

#include <string> // A supprimer une fois la nature codée

namespace PKMN
{
    class StatSet;
}


class PKMN::StatSet
/// StatSet is a class that allow to save statistics
///    (HP, Att, Def, SpAtt, SpDef, Speed)
/// in one object.
{
public:

/// CONSTRUCTORS :

    StatSet();
    /** \brief Construct a StatSet as a zero vector
     *
     * \param none
     * \return none
     *
     */

    StatSet(int HP,
            int Att,
            int Def,
            int SpAtt,
            int SpDef,
            int Speed);
    /** \brief Construct a StatSet with int values
     *   (changing them into double)
     *
     * \param HP int : HP value for m_HP
     * \param Att int : Att value for m_Att
     * \param Def int : Def value for m_Def
     * \param SpAtt int : SpAtt value for m_SpAtt
     * \param SpDef int : SpDef value for m_SpDef
     * \param Speed int : Speed value for m_Speed
     * \return none
     *
     */

    StatSet(double HP,
            double Att,
            double Def,
            double SpAtt,
            double SpDef,
            double Speed);
    /** \brief Construct a StatSet with double values
     *
     * \param HP double : HP value for m_HP
     * \param Att double : Att value for m_Att
     * \param Def double : Def value for m_Def
     * \param SpAtt double : SpAtt value for m_SpAtt
     * \param SpDef double : SpDef value for m_SpDef
     * \param Speed double : Speed value for m_Speed
     * \return none
     *
     */

    StatSet(std::string Stat);
    /** \brief Transform a list of value separated by the char delimitor ',' into StatSet
     *
     * \param Stat std::string : for example "232,121,12,78,32,90" (6 values)
     * will give the StatSet (232, 121, 12, 78, 32, 90)
     * \return none
     *
     */

    StatSet(StatSet const& Other);
    /** \brief Copy constructor for function (no reference)
     *
     * \param Other StatSet const& : Other StatSet to copy
     * \return none
     *
     */


/// DESTRUCTOR :

    virtual ~StatSet();
    /** \brief Virtual destructor because of CurStatSet
     *
     * \param none
     * \return none
     *
     */


/// GETTERS :

    int getHP() const;
    /** \brief Return the HP value of the StatSet
     *
     * \param none
     * \return int : HP value
     *
     */
    int getAtt() const;
    /** \brief Return the Att value of the StatSet
     *
     * \param none
     * \return int : Att value
     *
     */
    int getDef() const;
    /** \brief Return the Def value of the StatSet
     *
     * \param none
     * \return int : Def value
     *
     */
    int getSpAtt() const;
    /** \brief Return the SpAtt value of the StatSet
     *
     * \param none
     * \return int : SpAtt value
     *
     */
    int getSpDef() const;
    /** \brief Return the SpDef value of the StatSet
     *
     * \param none
     * \return int : SpDef value
     *
     */
    int getSpeed() const;
    /** \brief Return the Speed value of the StatSet
     *
     * \param none
     * \return int : Speed value
     *
     */


/// METHODS :

    void zeros();
    /** \brief Set the StatSet with zero values
     *
     * \param none
     * \return void
     *
     */

    void random(unsigned int mod = 32);
    /** \brief Set the StatSet with random values between 0 and the mod value,
     *
     *
     * \param mod unsigned int mod : modulo value, by default it is set to 32
     * because IV are numbers between 0 and 31
     * \return void
     *
     */

private:

/// FRIEND FUNCTION :
    // flux for cout :
    friend std::ostream& operator<<(std::ostream &flux,
                                    StatSet const& Stat);

    friend StatSet NormalStatistics(StatSet const Base,
                                    StatSet const IV,
                                    StatSet const EV,
                                    unsigned int level,
                                    std::string Nature);
    /** \brief Give the stats of a pokemon, given some information related
     *  to it species, IV and EV that are StatSet
     *
     * \param IV, EV PKMN_StatSet const& : Given for each pokemon
     * \param Base PKMN_StatSet const& : Specific to the species
     * \param level unsigned int : Level of the pokemon
     * \param Nature std::string : Nature of the pokemon
     * \return
     *
     */

/// MEMBER VARIABLES :
    double m_HP; /// Life point of a pokemon
    double m_Att; /// Attack point
    double m_Def; /// Defense point
    double m_SpAtt; /// Special Attack point
    double m_SpDef; /// Special Defense point
    double m_Speed; /// Speed point

};


#endif // PKMN_STATSET_H_INCLUDED
