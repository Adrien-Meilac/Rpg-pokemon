#ifndef PKMN_TYPE_H_INCLUDED
#define PKMN_TYPE_H_INCLUDED

#include "../Tools/Table.h"
#include "../FilePath.h"
#include "../Tools/Conversion.h"
#include "../Tools/VectorMethod.h"

#include <string>
#include <iostream>

#define TYPE_INEFFECTIVE             0
#define TYPE_NOT_VERY_EFFECTIVE      0.5
#define TYPE_NORMAL_EFFECTIVENESS    1
#define TYPE_SUPER_EFFECTIVE         2

namespace PKMN
{
    class Type;
}


class PKMN::Type
/// Class that code the type of a pokemon of a move
{
public:

/// CONSTRUCTORS :

    Type();
        /** \brief void constructor
         *
         */

    Type(std::string IntName);
        /** \brief Construct a type with only it InternalName by searching it in a file
         *
         * \param IntName std::string : internal name
         *
         */

    Type& operator=(Type const& other);
        /** \brief = asigment for simplify code
         *
         * \param other Type const& : other type to copy
         * \return Type& : *this value
         *
         */


    Type(Type const& other);
        /** \brief Copy constructor for function (no reference)
         *
         * \param other Type const& : other type to copy
         *
         */

/// DESTRUCTOR :

    ~Type();
        /** \brief Non virtual destructor
         *
         */

/// GETTERS :

    std::string getName() const;
        /** \brief Return the name of the type
         *
         * \return m_Name
         *
         */

    std::string getInternalName() const;
        /** \brief Return the internal name of the type
         *
         * \return m_InternalName
         *
         */

/// METHODS :

    double effectiveness(Type const Type_att) const;
        /** \brief Give the type coefficient effectiveness
         * (for example Water Type Move on a Fire Type Pokemon will
         * be given a type advantage)
         *
         * \param Type_att PKMN_Type const : Type of the attack
         * \return double : the coefficient is a float number
         * is the pokemon is resistant to the attack type
         *
         */

     void print() const;
        /** \brief Print type characteristics
         *
         */

private:

    std::string m_InternalName; /// Unique ID
    std::string m_Name; /// Name that is displayed in the game
    std::vector<std::string> m_Weaknesses; /// InternalName of weaknesses of a type
    std::vector<std::string> m_Immunities; /// InternalName of immunities of a type
    std::vector<std::string> m_Resistances; /// InternalName of resistance of a type
    bool m_IsSpecialType; /// Is the type special ?

};

namespace PKMN
{

double Type_effectiveness(Type Type_def,
                          Type Type_att);
    /** \brief Give the effectiveness coefficient
     *
     * \param Type_def PKMN_Type : Type of the receiver of an attack
     * \param Type_att PKMN_Type : Type of the attack
     * \return double : coefficient of effectiveness
     *
     */

double Type_effectiveness(std::pair<Type, Type> Type_def, Type Type_att);
    /** \brief Give the effectiveness coefficient
     *
     * \param Type_def std::pair<PKMN_Type, PKMN_Type> : Type of the receiver of an attack (2 type pokemon)
     * \param Type_att PKMN_Type : Type of the attack
     * \return double : coefficient of effectiveness
     *
     */

std::string Type_message(double typeMultiplicativeFactor);
    /** \brief Give a message that will be displayed when the attack happened
     *
     * \param typeMultiplicativeFactor double : coefficient of effectiveness
     * \return std::string : message
     *
     */

}


#endif // PKMN_TYPE_H_INCLUDED
