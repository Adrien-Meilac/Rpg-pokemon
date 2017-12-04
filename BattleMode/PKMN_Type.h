#ifndef TYPE_H
#define TYPE_H

#include "../Tools/PKMN_Table.h"
#include "../Tools/PKMN_Conversion.h"
#include "../Tools/PKMN_VectorMethod.h"
#include <string>
#include <vector>

#define INEFFECTIVE 0
#define NOT_VERY_EFFECTIVE 0.5
#define NORMAL_EFFECTIVENESS 1
#define SUPER_EFFECTIVE 2


class PKMN_Type
{
public:

    PKMN_Type();
    PKMN_Type(std::string Name,
              std::string InternalName,
              std::string Weaknesses,
              std::string Immunities,
              std::string Resistances,
              std::string IsSpecialType);
    PKMN_Type(std::vector<std::string> Line);
    double effectiveness(PKMN_Type const Type_att) const;
    double effectiveness(std::pair<PKMN_Type, PKMN_Type> PairType_att) const;
    std::string getName() const;
    std::string getInternalName() const;
    std::vector<std::string> getWeaknesses() const;
    std::vector<std::string> getImmunities() const;
    std::vector<std::string> getResistances() const;

private:

    std::string m_Name;
    std::string m_InternalName;
    std::vector<std::string> m_Weaknesses;
    std::vector<std::string> m_Immunities;
    std::vector<std::string> m_Resistances;
    bool m_IsSpecialType;

};

std::string PKMN_Type_message(double typeMultiplicativeFactor);

#endif // TYPE_H
