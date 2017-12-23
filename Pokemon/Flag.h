#ifndef PKMN_FLAG_H_INCLUDED
#define PKMN_FLAG_H_INCLUDED

#include <string>

namespace PKMN
{
    class Flag;
}

class PKMN::Flag
/** Flag code for more effect that are not taken for the damage calculus
    a - The move makes physical contact with the target.
    b - The target can use Protect or Detect to protect itself from the move.
    c - The target can use Magic Coat to redirect the effect of the move.
        Use this flag if the move deals no damage but causes a negative effect
        on the target. (Flags c and d are mutually exclusive.)
    d - The target can use Snatch to steal the effect of the move.
        Use this flag for most moves that target the user.
        (Flags c and d are mutually exclusive.)
    e - The move can be copied by Mirror Move.
    f - The move has a 10% chance of making the opponent flinch if
        the user is holding a King's Rock/Razor Fang. Use this flag
        for all damaging moves that don't already have a flinching effect.
    g - If the user is frozen, the move will thaw it out before it is used.
    h - The move has a high critical hit rate.
    i - The move is a biting move (powered up by the ability Strong Jaw).
    j - The move is a punching move (powered up by the ability Iron Fist).
    k - The move is a sound-based move.
    l - The move is a powder-based move (Grass-type Pokemon are immune to them).
    m - The move is a pulse-based move (powered up by the ability Mega Launcher).
    n - The move is a bomb-based move (resisted by the ability Bulletproof). */
{
public:

/// CONSTRUCTORS :

    Flag();

    Flag(std::string flagList);
        /** \brief Create a flag object given all the name of flags in a string object
         *
         * \param flagList std::string : string object that contains all the flags
         *          (each flag is a letter of the string)
         *
         */

    Flag(Flag const& other);

    Flag& operator=(Flag const& other);

/// DESTRUCTOR :

    ~Flag();

/// GETTERS :

    std::string getAll() const;
        /** \brief Return all the flags into a string list
         *
         * \return std::string : lit of the flags
         *
         */

    bool isPhysicalContactMove() const;
        /** \brief a - The move makes physical contact with the target.
         *
         * \return bool
         *
         */

    bool canBeStoped() const;
        /** \brief b - The target can use Protect or Detect to protect itself from the move.
         *
         * \return bool
         *
         */

    bool canBeRedirected() const;
        /** \brief  c - The target can use Magic Coat to redirect the effect of the move.
         *          Use this flag if the move deals no damage but causes a negative effect
         *          on the target. (Flags c and d are mutually exclusive.)

         *
         * \return bool
         *
         */

    bool effectCanBeStolen() const;
        /** \brief d - The target can use Snatch to steal the effect of the move.
         *         Use this flag for most moves that target the user.
         *         (Flags c and d are mutually exclusive.)
         *
         * \return bool
         *
         */

    bool canBeCopied() const;
        /** \brief e - The move can be copied by Mirror Move.
         *
         * \return bool
         *
         */

    bool canFlinched() const;
        /** \brief     f - The move has a 10% chance of making the opponent flinch if
         *             the user is holding a King's Rock/Razor Fang. Use this flag
         *             for all damaging moves that don't already have a flinching effect.
         *
         * \return bool
         *
         */

    bool thawFrozenTarget() const;
        /** \brief g - If the user is frozen, the move will thaw it out before it is used.
         *
         * \return bool
         *
         */

    bool hasHighCriticalRateMove() const;
        /** \brief h - The move has a high critical hit rate.
         *
         * \return bool
         *
         */

    bool isABittingMove() const;
        /** \brief i - The move is a biting move (powered up by the ability Strong Jaw).
         *
         * \return bool
         *
         */

    bool isPunchingMove() const;
        /** \brief j - The move is a punching move (powered up by the ability Iron Fist).
         *
         * \return bool
         *
         */

    bool isSoundMove() const;
        /** \brief k - The move is a sound-based move.
         *
         * \return bool
         *
         */

    bool isPowderBaseMove() const;
        /** \brief l - The move is a powder-based move (Grass-type Pokemon are immune to them).
         *
         * \return bool
         *
         */

    bool isPulseBasedMove() const;
        /** \brief m - The move is a pulse-based move (powered up by the ability Mega Launcher).
         *
         * \return bool
         *
         */

    bool isBombBasedMove() const;
        /** \brief n - The move is a bomb-based move (resisted by the ability Bulletproof).
         *
         * \return bool
         *
         */


private:

    bool isFlag(const char& letter) const;

/// MEMBER VARIABLES :

    std::string m_flagList;

};

#endif // FLAG_H_INCLUDED
