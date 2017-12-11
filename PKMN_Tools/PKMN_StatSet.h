#ifndef PKMN_STATSET_H_INCLUDED
#define PKMN_STATSET_H_INCLUDED

#include <cmath> // For pow function
#include <string> // A supprimer une fois la nature codée
#include <iostream> // For ostream flux
#include <cstdlib> // for rand()
#include <ctime> // for rand()
#include <vector> // for spliting statset
#include "PKMN_Conversion.h"
#include "PKMN_VectorMethod.h"

#define PKMN_STATSET_ATT "Att"
#define PKMN_STATSET_DEF "Def"
#define PKMN_STATSET_HP "Hp"
#define PKMN_STATSET_SPATT "SpAtt"
#define PKMN_STATSET_SPDEF "SpDef"
#define PKMN_STATSET_SPEED "Speed"

class PKMN_StatSet
/// PKMN_StatSet is a class that allow to save statistics (HP, Att, Def, SpAtt, SpDef, Speed)
/// in one object.
{
public:

    // Constructors :
    PKMN_StatSet(); // IV generator
    PKMN_StatSet(int HP, int Att, int Def, int SpAtt, int SpDef, int Speed);
    PKMN_StatSet(double HP, double Att, double Def, double SpAtt, double SpDef, double Speed);
    PKMN_StatSet(std::string Stat);
    PKMN_StatSet(PKMN_StatSet const& Other);

    // Getters :
    int getHP() const;
    int getAtt() const;
    int getDef() const;
    int getSpAtt() const;
    int getSpDef() const;
    int getSpeed() const;
//    int getStat(std::string name) const;
//
//    void statSwap(std::string name1, std::string name2);
//    void statSwapHPAtt();
//    void statSwapHPDef();
//    void statSwapHPSpAtt();
//    void statSwapHPSpDef();
//    void statSwapHPSpeed();
//    void statSwapAttDef();
//    void statSwapAttSpAtt();
//    void statSwapAttSpDef();
//    void statSwapAttSpeed();
//    void statSwapDefSpAtt();
//    void statSwapDefSpDef();
//    void statSwapDefSpeed();
//    void statSwapSpAttSpDef();
//    void statSwapSpAttSpeed();
//    void statSwapSpDefSpeed();

    // Destructor :
    virtual ~PKMN_StatSet();

private:

    // flux for cout :
    friend std::ostream& operator<<(std::ostream &flux, PKMN_StatSet const& Stat);

    friend PKMN_StatSet NormalStatistics(PKMN_StatSet const& Base,
                              PKMN_StatSet const& IV,
                              PKMN_StatSet const& EV,
                              unsigned int level,
                              std::string Nature);
    /** \brief Give the stats of a pokemon, given some information related to it species, IV and EV that are StatSet
     *
     * \param IV, EV PKMN_StatSet const& : Given for each pokemon
     * \param Base PKMN_StatSet const& : Specific to the species
     * \param level unsigned int : Level of the pokemon
     * \param Nature std::string : Nature of the pokemon
     * \return
     *
     */

    double m_HP; // Life point of the pokemon
    double m_Att; // Attack point
    double m_Def; // Defense point
    double m_SpAtt; // Special Attack point
    double m_SpDef; // Special Defense point
    double m_Speed; // Speed point

};

#endif // PKMN_STATSET_H_INCLUDED
