#include "Player.h"

PKMN::Player::Player()
{
    PKMN::Table table(BACKUP_PKMN_PLAYER);
    m_Name = table("Player", "Name");
    m_TypeName = table("Player", "Type name");
    m_Gender = table("Player", "Gender");
    m_PublicID = PKMN::string_to_int(table("Player", "Public ID"));
    m_SecretID = PKMN::string_to_int(table("Player", "Secret ID"));
    m_Language = PKMN::string_to_int(table("Player", "Language"));
    m_Money = PKMN::string_to_int(table("Player", "Money"));
    m_Badges = PKMN::split_string_to_bool(table("Player", "Bagdes"));
    m_Pokedex = PKMN::string_to_bool(table("Player", "Has Pokedex"));
    for(unsigned int i = 0; i < NUMBER_OF_PKMN_PER_TRAINOR; i++)
    {
        m_Party.push_back(PKMN::Pokemon(int_to_string(i)));
//        std::cout << "Creation of " << m_team[i].getName() << std::endl;
    }
}

PKMN::Player::~Player()
{

}

std::string PKMN::Player::getName() const
{
    return m_Name;
}

std::string PKMN::Player::getFullName() const
{
    return m_TypeName + " " + m_Name;
}

unsigned int PKMN::Player::getID() const
{
    return static_cast<int>(pow(2,16)) * m_PublicID + m_SecretID;
}

PKMN::Pokemon PKMN::Player::getPokemon(unsigned int pos)
{
    return m_Party[pos];
}

void PKMN::Player::setPokemon(PKMN::Pokemon pkmn,unsigned int pos)
{
    m_Party[pos] = pkmn;
}

bool PKMN::Player::hasPokemonAlive() const
{
    const unsigned int length = m_Party.size();
    for(unsigned int i = 0; i < length; i++)
    {
        if(m_Party[0].isAlive())
        {
            return true;
        }
    }
    return false;
}
