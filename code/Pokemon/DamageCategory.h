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
/** Damage category influence the damage calculus
    it is an attribute of Move **/
{
public:

/// CONSTRUCTORS :

    DamageCategory();

    DamageCategory(std::string Name);
        /** \brief Construct the damage category given it Name
         *
         * \param Name std::string : Name of the damage category
         *
         */

    DamageCategory(DamageCategory const& other);

    DamageCategory& operator=(DamageCategory const& other);

/// DESTRUCTOR :

    ~DamageCategory();

/// GETTERS :

    std::string getName() const;
        /** \brief get the name of the damage category
         *
         * \return void
         *
         */

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

    std::string m_Name; /// Name of the damage category

};

#endif // PKMN_DAMAGECATEGORY_H_INCLUDED
