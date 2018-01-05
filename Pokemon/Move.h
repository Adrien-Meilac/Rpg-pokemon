#ifndef PKMN_MOVE_H_INCLUDED
#define PKMN_MOVE_H_INCLUDED

#include "Type.h"
#include "DamageCategory.h"
#include "Flag.h"

#include "../FilePath.h"

#include "../Tools/Table.h"

#include <iostream> // to use ostream flux
#include <string> // to stock string values


namespace PKMN
{
    class Move;
}

class PKMN::Move
{
public:

/// CONSTRUCTORS :

    Move();

    Move(std::string InternalName);
        /** \brief Construct a move with the internal name by searching it in a table
         *
         * \param InternalName std::string : name of the move
         *
         */

    Move(Move const& other);

    Move& operator=(Move const& other);

/// DESTRUCTOR :

    ~Move();

/// GETTERS :

    std::string getName() const;
        /** \brief send back the name of a move
         *
         * \return std::string : m_Name
         *
         */

    std::string getInternalName() const;
        /** \brief send back the internal name of a move
         *
         * \return std::string : m_InternalName
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

    DamageCategory getDamageCategory() const;
        /** \brief get the damage category
         *
         * \return std::string : m_Description
         *
         */

    Flag getFlags() const;
        /** \brief get the flag list
         *
         * \return std::string : m_Description
         *
         */

    unsigned int getPriority() const;

    bool isPhysicalCategory() const;
        /** \brief does a move belong to the physical category ?
         *
         * \return bool
         *
         */

    bool isStatusCategory() const;
        /** \brief does a move belong to the status category ?
         *
         * \return bool
         *
         */

    bool isSpecialCategory() const;
        /** \brief does a move belong to the special category ?
         *
         * \return bool
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
    DamageCategory m_DamageCategory; /// Will change the damage calculus
    unsigned int m_Accuracy; /// Accuracy of the move
    unsigned int m_TotalPP; /// Max Power Point of a move (how much time we could use an attack)
    unsigned int m_AdditionalEffectChance; /// Bonus of accuracy
    std::string m_Target; /// Useful in 2 pokemon against 2 pokemon battles
    int m_Priority; /// Will change the natural order of attack determined by speed
    Flag m_Flags; /// each letter of the string represent a special effect of the move
    std::string m_Description; /// Description of the move

};

namespace PKMN
{

std::vector<std::pair<unsigned int, Move> > read_move(std::string moves);
    /** \brief Split a string into move names and create associated objects
     *
     * \param moves std::string : for example "Move1,Move2,Move3,Move4, ..."
     * \return std::vector<Move> : vector of move objects
     *
     */

bool operator==(Move move1, Move move2);
bool operator==(Move move1, std::string moveInternalName);

}


#endif // PKMN_MOVES_H_INCLUDED
