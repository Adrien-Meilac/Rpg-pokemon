#include "Flag.h"

PKMN::Flag::Flag()
{

}

PKMN::Flag::Flag(std::string flagList)
{
    m_flagList = flagList;
}

PKMN::Flag::Flag(PKMN::Flag const& other)
{
    m_flagList = other.m_flagList;
}

PKMN::Flag& PKMN::Flag::operator=(PKMN::Flag const& other)
{
    m_flagList = other.m_flagList;
    return *this;
}

PKMN::Flag::~Flag()
{

}

bool PKMN::Flag::isPhysicalContactMove() const
{
    return isFlag('a');
}

bool PKMN::Flag::canBeStoped() const
{
    return isFlag('b');
}

bool PKMN::Flag::canBeRedirected() const
{
    return isFlag('c');
}

bool PKMN::Flag::effectCanBeStolen() const
{
    return isFlag('d');
}

bool PKMN::Flag::canBeCopied() const
{
    return isFlag('e');
}

bool PKMN::Flag::canFlinched() const
{
    return isFlag('f');
}

bool PKMN::Flag::thawFrozenTarget() const
{
    return isFlag('g');
}

bool PKMN::Flag::hasHighCriticalRateMove() const
{
    return isFlag('h');
}

bool PKMN::Flag::isABittingMove() const
{
    return isFlag('i');
}

bool PKMN::Flag::isPunchingMove() const
{
    return isFlag('j');
}

bool PKMN::Flag::isSoundMove() const
{
    return isFlag('k');
}

bool PKMN::Flag::isPowderBaseMove() const
{
    return isFlag('l');
}

bool PKMN::Flag::isPulseBasedMove() const
{
    return isFlag('m');
}

bool PKMN::Flag::isBombBasedMove() const
{
    return isFlag('n');
}

bool PKMN::Flag::isFlag(const char& letter) const
{
    int pos = m_flagList.find(letter);
    const int length = m_flagList.size();
    return (pos >= 0) && (pos < length);
}

std::string PKMN::Flag::getAll() const
{
    return m_flagList;
}
