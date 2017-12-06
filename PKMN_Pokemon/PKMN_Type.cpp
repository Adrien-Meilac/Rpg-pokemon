#include "PKMN_Type.h"

                /// CONSTRUCTORS ///

PKMN_Type::PKMN_Type():
    m_InternalName(),
    m_Name(),
    m_Weaknesses(),
    m_Immunities(),
    m_Resistances(),
    m_IsSpecialType()
{

}

PKMN_Type::PKMN_Type(std::string InternalName,
                    std::string Name,
                    std::string Weaknesses,
                    std::string Immunities,
                    std::string Resistances,
                    std::string IsSpecialType)
{
    m_InternalName = InternalName;
    m_Name = Name;
    m_Weaknesses = string_split(Weaknesses, ',');
    m_Immunities = string_split(Immunities, ',');
    m_Resistances = string_split(Resistances, ',');
    m_IsSpecialType = string_to_bool(IsSpecialType);
}

PKMN_Type::PKMN_Type(std::string InternalName)
{
    PKMN_Table table(PATH_TO_TYPE_FILE);
    std::vector<std::string> Line = table.getLineValues(InternalName);
    std::string Name = Line[0];
    std::string Weaknesses = Line[1];
    std::string Immunities = Line[2];
    std::string Resistances = Line[3];
    std::string IsSpecialType = Line[4];
    m_InternalName = InternalName;
    m_Name = Name;
    m_Weaknesses = string_split(Weaknesses, ',');
    m_Immunities = string_split(Immunities, ',');
    m_Resistances = string_split(Resistances, ',');
    m_IsSpecialType = string_to_bool(IsSpecialType);
}

PKMN_Type::PKMN_Type(std::vector<std::string> Line)
{
    std::string InternalName = Line[0];
    std::string Name = Line[1];
    std::string Weaknesses = Line[2];
    std::string Immunities = Line[3];
    std::string Resistances = Line[4];
    std::string IsSpecialType = Line[5];
    m_InternalName = InternalName;
    m_Name = Name;
    m_Weaknesses = string_split(Weaknesses, ',');
    m_Immunities = string_split(Immunities, ',');
    m_Resistances = string_split(Resistances, ',');
    m_IsSpecialType = string_to_bool(IsSpecialType);
}

/// ///////////////////////////////////////// ///

                /// DESTRUCTOR ///

PKMN_Type::~PKMN_Type()
{
    delete &m_InternalName;
    delete &m_Name;
    delete &m_Weaknesses;
    delete &m_Immunities;
    delete &m_Resistances;
    delete &m_IsSpecialType;
}

/// ///////////////////////////////////////// ///

                /// GETTERS ///

std::string PKMN_Type::getName() const
{
    return m_Name;
}

std::string PKMN_Type::getInternalName() const
{
    return m_InternalName;
}
std::vector<std::string> PKMN_Type::getWeaknesses() const
{
    return m_Weaknesses;
}

std::vector<std::string> PKMN_Type::getImmunities() const
{
    return m_Immunities;
}

std::vector<std::string> PKMN_Type::getResistances() const
{
    return m_Resistances;
}

/// ///////////////////////////////////////// ///

                /// METHODS ///

double PKMN_Type::effectiveness(PKMN_Type const Type_att) const
{
    double typeMultiplicativeFactor = NORMAL_EFFECTIVENESS;
    if(vector_in(m_Immunities, Type_att.m_InternalName))
    {
        typeMultiplicativeFactor = INEFFECTIVE;
    }
    else if(vector_in(m_Weaknesses, Type_att.m_InternalName))
    {
        typeMultiplicativeFactor = SUPER_EFFECTIVE;
    }
    else if(vector_in(m_Resistances, Type_att.m_InternalName))
    {
        typeMultiplicativeFactor = NOT_VERY_EFFECTIVE;
    }

    return typeMultiplicativeFactor;
}

PKMN_Type& PKMN_Type::operator=(PKMN_Type const& other)
{
    m_InternalName = other.m_InternalName;
    m_Name = other.m_Name;
    m_Weaknesses = other.m_Weaknesses;
    m_Immunities = other.m_Immunities;
    m_Resistances = other.m_Resistances;
    m_IsSpecialType = other.m_IsSpecialType;
    return *this;
}

/// ///////////////////////////////////////// ///

double typeEffectiveness(PKMN_Type Type_def, PKMN_Type Type_att)
{
    return Type_def.effectiveness(Type_att);
}

double typeEffectiveness(PKMN_Type Type_def, std::pair<PKMN_Type, PKMN_Type> Type_att)
{
    return typeEffectiveness(Type_def, Type_att.first) * typeEffectiveness(Type_def, Type_att.second);
}

double typeEffectiveness(std::pair<PKMN_Type, PKMN_Type> Type_def, PKMN_Type Type_att)
{
    return typeEffectiveness(Type_def.first, Type_att) * typeEffectiveness(Type_def.second, Type_att);
}


std::string PKMN_Type_message(double typeMultiplicativeFactor)
{
    std::string message("");
    if(typeMultiplicativeFactor == INEFFECTIVE)
    {
        message = "It's totally ineffective !";
    }
    else if(typeMultiplicativeFactor < NORMAL_EFFECTIVENESS)
    {
        message = "It's not very effective !";
    }
    else if(typeMultiplicativeFactor > NORMAL_EFFECTIVENESS)
    {
        message = "It's super effective !";
    }
    return message;
}
