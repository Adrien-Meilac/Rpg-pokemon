#ifndef PKMN_TARGET_H_INCLUDED
#define PKMN_TARGET_H_INCLUDED

#include <string>

namespace PKMN
{
    class Target;
}

class PKMN::Target
/** Target object are give boolean method to know which pokemon is
    aimed by a move :
    00 - Single Pokemon other than the user
    01 - No target (i.e. Counter, Metal Burst, Mirror Coat, Curse)
    02 - Single opposing Pokemon selected at random (i.e. Outrage, Petal Dance, Thrash, Uproar)
    04 - All opposing Pokemon
    08 - All Pokemon other than the user
    10 - User
    20 - Both sides (e.g. Sunny Day, Trick Room)
    40 - User's side (e.g. Light Screen, Mist)
    80 - Opposing side (i.e. Spikes, Toxic Spikes, Stealth Rocks)
    100 - User's partner (i.e. Helping Hand)
    200 - Single Pokemon on user's side (i.e. Acupressure)
    400 - Single opposing Pokemon (i.e. Me First)
    800 - Single opposing Pokemon directly opposite of user **/
{
public:

/// CONSTRUCTORS :

    Target();

    Target(std::string target);
    /** \brief Construct a target object
     *
     * \param target std::string : target object in string
     *
     */

    Target(Target const& other);

    Target& operator=(Target const& other);

/// DESTRUCTOR :

    ~Target();

/// GETTERS :

    bool isSiglePokemonExceptUser() const;
        /** \brief Single Pokemon other than the user (00)
         *
         * \return bool
         *
         */

    bool isNone() const;
        /** \brief 01 - No target (i.e. Counter, Metal Burst, Mirror Coat, Curse)
         *
         * \return bool
         *
         */

    bool isRandomFoe() const;
        /** \brief 02 - Single opposing Pokemon selected at random
            (i.e. Outrage, Petal Dance, Thrash, Uproar)
         *
         * \return bool
         *
         */

    bool isAllFoe() const;
        /** \brief 04 - All opposing Pokemon
         *
         * \return bool
         *
         */

    bool isAllExceptUser() const;
        /** \brief 08 - All Pokemon other than the user
         *
         * \return bool
         *
         */

    bool isUser() const;
        /** \brief 10 - User
         *
         * \return bool
         *
         */

    bool isAllFighters() const;
        /** \brief 20 - Both sides (e.g. Sunny Day, Trick Room)
         *
         * \return bool
         *
         */

    bool isUserSide() const;
        /** \brief 40 - User's side (e.g. Light Screen, Mist)
         *
         * \return bool
         *
         */

    bool isFoeSide() const;
        /** \brief 80 - Opposing side (i.e. Spikes, Toxic Spikes, Stealth Rocks)
         *
         * \return bool
         *
         */

    bool isPartner() const;
        /** \brief  100 - User's partner (i.e. Helping Hand)
         *
         * \return bool
         *
         */

    bool isUserSideOnePartner() const;
        /** \brief  200 - Single Pokemon on user's side (i.e. Acupressure)
         *
         * \return bool
         *
         */

    bool isOneofFoe() const;
        /** \brief 400 - Single opposing Pokemon (i.e. Me First)
         *
         * \return bool
         *
         */

    bool isFoeSameSide() const;
        /** \brief 800 - Single opposing Pokemon directly opposite of user
         *
         * \return bool
         *
         */


private:

    bool isCode(const std::string& code) const;
        /** \brief General test
         *
         * \return bool
         *
         */

    std::string m_Target;

};

#endif // TARGET_H_INCLUDED
