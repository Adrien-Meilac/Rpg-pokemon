#ifndef PKMN_EVOLUTION_H_INCLUDED
#define PKMN_EVOLUTION_H_INCLUDED

#include <string>

class PKMN_Evolution
{
public:
    PKMN_Evolution();
    PKMN_Evolution(std::string EvolutionInternalName,
                    std::string EvolutionMethod,
                    std::string EvolutionCondition);
    virtual ~PKMN_Evolution();

private:

    std::string m_EvolutionInternalName;
    std::string m_EvolutionMethod;
    std::string m_EvolutionCondition;

};

#endif // PKMN_EVOLUTION_H_INCLUDED
