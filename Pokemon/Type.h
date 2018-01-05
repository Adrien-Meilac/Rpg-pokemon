#ifndef PKMN_TYPE_H_INCLUDED
#define PKMN_TYPE_H_INCLUDED

#include "../FilePath.h"

#include "../Tools/Table.h"
#include "../Tools/Conversion.h"
#include "../Tools/VectorMethod.h"

#include <string>
#include <iostream>
#include <array>

#define NB_OF_TYPES 18

#define TYPE_INEFFECTIVE             0
#define TYPE_NOT_VERY_EFFECTIVE      0.5
#define TYPE_NORMAL_EFFECTIVENESS    1
#define TYPE_SUPER_EFFECTIVE         2

namespace PKMN
{
    class Type;
}


class PKMN::Type
/** Class that code the type of a Pokemon of a move **/
{
public:

/// CONSTRUCTORS :

    Type();

    Type(std::string IntName);
        /** \brief Construct a type with only it InternalName by searching it in a file
         *
         * \param IntName std::string : internal name
         *
         */

    Type& operator=(Type const& other);

    Type(Type const& other);

/// DESTRUCTOR :

    ~Type();

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

    std::string getPathImage() const;

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

double Type_effectiveness(std::pair<Type, Type> Type_def,
                          Type Type_att);
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

bool operator==(Type type1, Type type2);
bool operator==(Type type1, std::string typeInternalName);

}


#endif // PKMN_TYPE_H_INCLUDED
