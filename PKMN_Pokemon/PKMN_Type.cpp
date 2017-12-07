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

PKMN_Type::PKMN_Type(std::string InternalName)
{
    PKMN_Table table(PATH_TO_TYPE_FILE);
    m_Name = table(InternalName,"Name");
    m_Weaknesses = string_split(table(InternalName,"Weaknesses"), ',');
    m_Resistances = string_split(table(InternalName,"Resistances"), ',');
    m_Immunities = string_split(table(InternalName,"Immunities"), ',');
    m_IsSpecialType = string_to_bool(table(InternalName,"IsSpecialType"));
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
