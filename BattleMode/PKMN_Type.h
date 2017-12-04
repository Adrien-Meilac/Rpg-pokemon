#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <vector>
#include "../Tools/PKMN_Table.h"

#define INEFFECTIVE 0
#define NOT_VERY_EFFECTIVE 0.5
#define NORMAL_EFFECTIVENESS 1
#define SUPER_EFFECTIVE 2

class PKMN_Type
{
public:
    PKMN_Type();
    PKMN_Type(std::string Name,
              std::string Weaknesses,
              std::string Immunities,
              std::string Resistances,
              std::string IsSpecialType);
    double effectiveness(PKMN_Type const Type_att) const;
    double effectiveness(std::pair<PKMN_Type, PKMN_Type> PairType_att);


private:

    friend std::string effectivenessMessage(PKMN_Type const Type_att);
    friend std::string effectivenessMessage(std::pair<PKMN_Type, PKMN_Type> PairType_att);

    std::string m_Name;
    std::vector<std::string> m_Weaknesses;
    std::vector<std::string> m_Immunities;
    std::vector<std::string> m_Resistances;
    bool m_IsSpecialType;
};

#endif // TYPE_H
