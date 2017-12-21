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

void throwNewPokemon(unsigned int i)
{
    m_iactivePkmn = i;
    std::cout << "Go ! " << m_Player.getPkmnName(m_iactivePkmn) << " !" << std::endl;
}


void PKMN::BattleWildPokemon::launch()
{
    std::cout << "Wild " << m_WildPkmn.getName() << " appeared !" << std::endl;
    this->throwNewPokemon(); ///Lv100
    std::cout << "What will Bulbasaur do ?" << std::endl;
    std::cout << "FIGHT BAG POKEMON RUN" << std::endl;
    std::vector<std::pair<unsigned int,Move> > PKMN::Pokemon::getListMove()
    std::cout <<
    Tackle Growl // Normal PP : 40/40
    The wild Rattata used Bite !
    Bulbisaur flinched and could'nt move !
    std::cout << "The foe's " << m_Pokemon_Name << " fainted !" << std::endl;
    std::cout << m_Name << " gained " << expPoint << "EXP. Point !" << std::endl;
}
