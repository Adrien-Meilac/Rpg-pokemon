#ifndef PKMN_DAMAGECATEGORY_H_INCLUDED
#define PKMN_DAMAGECATEGORY_H_INCLUDED

#include <iostream>
#include <string>

#define DAMAGECATEGORY_PHYSICAL   "Physical"
#define DAMAGECATEGORY_SPECIAL    "Special"
#define DAMAGECATEGORY_STATUS     "Status"


namespace PKMN
{
    class DamageCategory;
}

class PKMN::DamageCategory
/** Damage category influence the damage calculus */
{
public:

/// CONSTRUCTORS :

    DamageCategory();
    /** \brief
     *
     *
     */

    DamageCategory(std::string Name);
    /** \brief
     *
     * \param Name std::string
     *
     */

    DamageCategory(DamageCategory const& other);
        /** \brief Copy constructor
         *
         * \param other DamageCategory const& : other DamageCategory to copy
         *
         */

    DamageCategory& operator=(DamageCategory const& other);
        /** \brief to simplify assignment of DamageCategory objects
         *
         * \param other DamageCategory const& : other DamageCategory to copy
         * \return DamageCategory& : *this
         *
         */

/// DESTRUCTOR :

    ~DamageCategory();
    /** \brief
     *
     *
     */

/// GETTERS :

    std::string getName() const;
    /** \brief
     *
     * \return void
     *
     */

    bool isPhysicalCategory() const;
    /** \brief
     *
     * \return bool
     *
     */

    bool isStatusCategory() const;
    /** \brief
     *
     * \return bool
     *
     */

    bool isSpecialCategory() const;
    /** \brief
     *
     * \return bool
     *
     */

private:

/// MEMBER VARIABLES :

    std::string m_Name; /// Name of the damage category

};

#endif // PKMN_DAMAGECATEGORY_H_INCLUDED
