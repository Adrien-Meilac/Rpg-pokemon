#include "PKMN_Pokemon.h"

PKMN_Pokemon::PKMN_Pokemon()
{

}

PKMN_Pokemon::PKMN_Pokemon(std::string Position)
{
    PKMN_Table table(BACKUP_POKEMON_HOLD);
    PKMN_Species(table(Position, "Species"));
    m_Pokemon_Name = table(Position, "Name");
    m_Pokemon_IV = PKMN_StatSet(table(Position, "IV"));
    m_Pokemon_EV = PKMN_StatSet(table(Position, "EV"));
    m_Pokemon_CurStat = PKMN_StatSet(table(Position, "CurrentStat"));
    m_Pokemon_ExpAndLevel = PKMN_ExpAndLevel(m_GrowthRate, string_to_int(table(Position, "Level")), string_to_int(table(Position, "Experience")));
    m_Pokemon_Moves = read_moves(table(Position, "Moves"));
    m_Pokemon_gender = table(Position, "Gender");
    m_Pokemon_NormalStat = NormalStatistics(m_BaseStats,
                                            m_Pokemon_IV,
                                            m_Pokemon_EV,
                                            m_Pokemon_ExpAndLevel.getLevel(),
                                            ""); // nature forgotten
}

PKMN_Pokemon::~PKMN_Pokemon()
{
    std::cout << "PKMN_Pokemon deleted\n";
}
