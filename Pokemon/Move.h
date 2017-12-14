#ifndef PKMN_MOVE_H_INCLUDED
#define PKMN_MOVE_H_INCLUDED

#include "../Tools/Table.h"
#include "Type.h"
#include "../FilePath.h"

#include <iostream> // to use ostream flux
#include <string> // to stock string values

#define MOVE_DAMAGE_CATEGORY_PHYSICAL   "Physical"
#define MOVE_DAMAGE_CATEGORY_SPECIAL    "Special"
#define MOVE_DAMAGE_CATEGORY_STATUS     "Status"

namespace PKMN
{
    class Move;
}

class PKMN::Move
{
public:

/// CONSTRUCTORS :

    Move();
        /** \brief void constructor
         *
         */

    Move(std::string InternalName);
        /** \brief Construct a move with the internal name by searching it in a table
         *
         * \param InternalName std::string : name of the move
         *
         */

    Move(Move const& other);
        /** \brief Copy constructor
         *
         * \param other Move const& : other Move to copy
         *
         */

    Move& operator=(Move const& other);
        /** \brief to simplify assignment of Move objects
         *
         * \param other Moves const& : other Move to copy
         * \return Move& : *this
         *
         */

/// DESTRUCTOR :

    ~Move();
        /** \brief non virtual destructor
         *
         */

/// GETTERS :

    std::string getDamageCategory() const;
        /** \brief send back the damage category
         *
         * \return std::string : m_DamageCategory
         *
         */

    std::string getName() const;
        /** \brief send back the name of a move
         *
         * \return std::string : m_name
         *
         */

    unsigned int getBasePower() const;
        /** \brief get the base power of the move (useful for damage calculus)
         *
         * \return unsigned int : m_BasePower
         *
         */

    Type getType() const;
        /** \brief get the type of a move (useful for damage calculus)
         *
         * \return Type : m_Type
         *
         */

    unsigned int getTotalPP() const;
        /** \brief get the number of PP of a move
         *
         * \return unsigned int
         *
         */

    std::string getDescription() const;
        /** \brief get the description of a move
         *
         * \return std::string : m_Description
         *
         */

/// METHODS :

    void print() const;
        /** \brief print the move
         *
         * \return void
         *
         */

private:

/// MEMBER VARIABLES :

    std::string m_InternalName; /// Internal name of the move
    unsigned int m_ID; /// ID number
    std::string m_Name; /// Name
    std::string m_FunctionCode; /// Hexadecimal number that code the effects
    unsigned int m_BasePower; /// power of the attack
    Type m_Type; /// Type of a move
    std::string m_DamageCategory; /// Will change the damage calculus
    unsigned int m_Accuracy; /// Accuracy of the move
    unsigned int m_TotalPP; /// Max Power Point of a move (how much time we could use an attack)
    unsigned int m_AdditionalEffectChance; /// Bonus of accuracy
    std::string m_Target; /// Useful in 2 pokemon against 2 pokemon battles
    int m_Priority; /// Will change the natural order of attack determined by speed
    std::string m_Flags; /// each letter of the string represent a special effect of the move
    std::string m_Description; /// Description of the move

};

namespace PKMN
{

std::vector<Move> read_move(std::string moves);
    /** \brief Split a string into move names and create associated objects
     *
     * \param moves std::string : for example "Move1,Move2,Move3,Move4, ..."
     * \return std::vector<Move> : vector of move objects
     *
     */

}


#endif // PKMN_MOVES_H_INCLUDED
