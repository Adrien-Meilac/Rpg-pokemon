#include "PKMN_Evolution.h"

PKMN_Evolution::PKMN_Evolution():
    m_EvolutionInternalName(),
    m_EvolutionMethod(),
    m_EvolutionCondition()
{

}

PKMN_Evolution::PKMN_Evolution(std::string EvolutionInternalName,
                                std::string EvolutionMethod,
                                std::string EvolutionCondition):
    m_EvolutionInternalName(EvolutionInternalName),
    m_EvolutionMethod(EvolutionMethod),
    m_EvolutionCondition(EvolutionCondition)
{

}

PKMN_Evolution::~PKMN_Evolution()
{

}
