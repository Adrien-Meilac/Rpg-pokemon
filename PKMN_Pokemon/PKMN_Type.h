#ifndef PKMN_TYPE_H_INCLUDED
#define PKMN_TYPE_H_INCLUDED

#include "../PKMN_Tools/PKMN_Table.h"
#include "../PKMN_FilePath.h"
#include "../PKMN_Tools/PKMN_Conversion.h"
#include <string>
#include <iostream>

#define INEFFECTIVE 0
#define NOT_VERY_EFFECTIVE 0.5
#define NORMAL_EFFECTIVENESS 1
#define SUPER_EFFECTIVE 2

class PKMN_Type
{
public:

    PKMN_Type();

    PKMN_Type(std::string InternalName);
    /** \brief Construct a type with only it InternalName by searching it in a file
     *
     * \param InternalName std::string : internal name
     *
     */

    // constructor for tests :

    PKMN_Type& operator=(PKMN_Type const& other);

    double effectiveness(PKMN_Type const Type_att) const;
    /** \brief Give the type coefficient effectiveness
    (for example Water Type Move on a Fire Type Pokemon will be given a type advantage)
     *
     * \param Type_att PKMN_Type const : Type of the attack
     * \return double : the coefficient is a float number is the pokemon is resistant to the attack type
     *
     */

    // getters :
    std::string getName() const;
    std::string getInternalName() const;
    std::vector<std::string> getWeaknesses() const;
    std::vector<std::string> getImmunities() const;
    std::vector<std::string> getResistances() const;

    // destructor :
    virtual ~PKMN_Type();

private:

    std::string m_InternalName; // Unique ID
    std::string m_Name; // Name that is displayed in the game
    std::vector<std::string> m_Weaknesses; // InternalName of weaknesses of a type
    std::vector<std::string> m_Immunities; // InternalName of immunities of a type
    std::vector<std::string> m_Resistances; // InternalName of resistance of a type
    bool m_IsSpecialType; // Is the type special ?

};


double PKMN_Type_effectiveness(PKMN_Type Type_def, PKMN_Type Type_att);
/** \brief Give the effectiveness coefficient
 *
 * \param Type_def PKMN_Type : Type of the receiver of an attack
 * \param Type_att PKMN_Type : Type of the attack
 * \return double : coefficient of effectiveness
 *
 */

double PKMN_Type_effectiveness(PKMN_Type Type_def, std::pair<PKMN_Type, PKMN_Type> Type_att);
/** \brief Give the type coefficient effectiveness in the case it is a 2 type attack
(for example Water Type Move on a Fire Type Pokemon will be given a type advantage)
 *
 * \param Type_att std::pair<PKMN_Type, PKMN_Type> : types of the pokemon
 * \return double : the coefficient is a float number is the pokemon is resistant to the attack type
 *
 */

double PKMN_Type_effectiveness(std::pair<PKMN_Type, PKMN_Type> Type_def, PKMN_Type Type_att);
/** \brief Give the effectiveness coefficient
 *
 * \param Type_def std::pair<PKMN_Type, PKMN_Type> : Type of the receiver of an attack (2 type pokemon)
 * \param Type_att PKMN_Type : Type of the attack
 * \return double : coefficient of effectiveness
 *
 */

std::string PKMN_Type_message(double typeMultiplicativeFactor);
/** \brief Give a message that will be displayed when the attack happened
 *
 * \param typeMultiplicativeFactor double : coefficient of effectiveness
 * \return std::string : message
 *
 */


#endif // PKMN_TYPE_H_INCLUDED
