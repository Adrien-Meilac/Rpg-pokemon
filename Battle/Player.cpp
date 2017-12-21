#include "Player.h"

PKMN::Player::Player()
{
    PKMN::Table table(BACKUP_PKMN_PLAYER);
    m_name = table("Player", "Name");
    m_typeName = table("Player", "Type name");
    m_gender = table("Player", "Gender");
    m_publicID = PKMN::string_to_int(table("Player", "Public ID"));
    m_secretID = PKMN::string_to_int(table("Player", "Secret ID"));
    m_language = PKMN::string_to_int(table("Player", "Language"));
    m_money = PKMN::string_to_int(table("Player", "Money"));
    m_badges = PKMN::split_string_to_bool(table("Player", "Bagdes"));
    m_pokedex = PKMN::string_to_bool(table("Player", "Has Pokedex"));
    for(unsigned int i = 0; i < NUMBER_OF_PKMN_PER_TRAINOR; i++)
    {
        m_team.push_back(PKMN::Pokemon(int_to_string(i)));
//        std::cout << "Creation of " << m_team[i].getName() << std::endl;
    }
}

PKMN::Player::~Player()
{

}

std::string PKMN::Player::getName() const
{
    return m_name;
}

std::string PKMN::Player::getFullName() const
{
    return m_typeName + " " + m_name;
}

unsigned int PKMN::Player::getID() const
{
    return static_cast<int>(pow(2,16)) * m_publicID + m_secretID;
}

std::string PKMN::Player::getPkmn(unsigned int i = 0) const;
{
    return m_Party[i];
}
