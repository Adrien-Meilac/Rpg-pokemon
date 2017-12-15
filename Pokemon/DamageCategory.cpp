#include "DamageCategory.h"

                /// CONSTRUCTORS ///

PKMN::DamageCategory::DamageCategory()
{

}

PKMN::DamageCategory::DamageCategory(std::string Name)
{
    m_Name = Name;
}

PKMN::DamageCategory::DamageCategory(DamageCategory const& other)
{
    m_Name = other.m_Name;
}

PKMN::DamageCategory& PKMN::DamageCategory::operator=(PKMN::DamageCategory const& other)
{
    m_Name = other.m_Name;
}

/// ///////////////////////////////////////// ///

                /// DESTRUCTOR ///

PKMN::DamageCategory::~DamageCategory()
{

}

/// ///////////////////////////////////////// ///

                /// GETTERS ///

std::string PKMN::DamageCategory::getName() const
{
    return m_Name;
}

bool PKMN::DamageCategory::isPhysicalCategory() const
{
    return m_Name == DAMAGECATEGORY_PHYSICAL;
}

bool PKMN::DamageCategory::isStatusCategory() const
{
    return m_Name == DAMAGECATEGORY_STATUS;
}

bool PKMN::DamageCategory::isSpecialCategory() const
{
    return m_Name == DAMAGECATEGORY_SPECIAL;
}
