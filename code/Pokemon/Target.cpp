#include "Target.h"

PKMN::Target::Target()
{

}

PKMN::Target::Target(std::string target)
{
    m_Target = target;
}

PKMN::Target::Target(PKMN::Target const& other)
{
    m_Target = other.m_Target;
}

PKMN::Target& PKMN::Target::operator=(PKMN::Target const& other)
{
    m_Target = other.m_Target;
    return *this;
}

PKMN::Target::~Target()
{

}

bool PKMN::Target::isCode(const std::string& code) const
{
    return m_Target == code;
}

bool PKMN::Target::isSiglePokemonExceptUser() const
{
    return this->isCode("00");
}

bool PKMN::Target::isNone() const
{
    return this->isCode("01");
}

bool PKMN::Target::isRandomFoe() const
{
    return this->isCode("02");
}

bool PKMN::Target::isAllFoe() const
{
    return this->isCode("04");
}

bool PKMN::Target::isAllExceptUser() const
{
    return this->isCode("08");
}

bool PKMN::Target::isUser() const
{
    return this->isCode("10");
}

bool PKMN::Target::isAllFighters() const
{
    return this->isCode("20");
}

bool PKMN::Target::isUserSide() const
{
    return this->isCode("40");
}

bool PKMN::Target::isFoeSide() const
{
    return this->isCode("80");
}

bool PKMN::Target::isPartner() const
{
    return this->isCode("100");
}

bool PKMN::Target::isUserSideOnePartner() const
{
    return this->isCode("200");
}

bool PKMN::Target::isOneofFoe() const
{
    return this->isCode("400");
}

bool PKMN::Target::isFoeSameSide() const
{
    return this->isCode("800");
}

