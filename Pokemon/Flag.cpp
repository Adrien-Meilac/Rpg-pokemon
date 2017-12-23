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

bool PKMN::Flag::isFlag_a() const
{
    return isFlag('a');
}

bool PKMN::Flag::isFlag_b() const
{
    return isFlag('b');
}

bool PKMN::Flag::isFlag_c() const
{
    return isFlag('c');
}

bool PKMN::Flag::isFlag_d() const
{
    return isFlag('d');
}

bool PKMN::Flag::isFlag_e() const
{
    return isFlag('e');
}

bool PKMN::Flag::isFlag_f() const
{
    return isFlag('f');
}

bool PKMN::Flag::isFlag_g() const
{
    return isFlag('g');
}

bool PKMN::Flag::isFlag_h() const
{
    return isFlag('h');
}

bool PKMN::Flag::isFlag_i() const
{
    return isFlag('i');
}

bool PKMN::Flag::isFlag_j() const
{
    return isFlag('j');
}

bool PKMN::Flag::isFlag_k() const
{
    return isFlag('k');
}

bool PKMN::Flag::isFlag_l() const
{
    return isFlag('l');
}

bool PKMN::Flag::isFlag_m() const
{
    return isFlag('m');
}

bool PKMN::Flag::isFlag_n() const
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
