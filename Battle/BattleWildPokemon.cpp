#include "BattleWildPokemon.h"

PKMN::BattleWildPokemon::BattleWildPokemon()
{

}

PKMN::BattleWildPokemon::BattleWildPokemon(Player& player,
                                           Place place,
                                           Pokemon wildPkmn):
    m_Player(player),
    m_WildPkmn(wildPkmn),
    m_Place(place)
{
    m_Weather = m_Place.getWeather();
}

PKMN::BattleWildPokemon::~BattleWildPokemon()
{

}

void PKMN::BattleWildPokemon::start()
{
    std::cout << "start";
}

void PKMN::BattleWildPokemon::stop()
{
    std::cout << "end";
}
