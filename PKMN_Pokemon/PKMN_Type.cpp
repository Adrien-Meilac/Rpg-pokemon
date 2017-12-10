#include "PKMN_Type.h"

                /// CONSTRUCTORS ///

PKMN_Type::PKMN_Type()
{

}

PKMN_Type::PKMN_Type(std::string InternalName)
{
    PKMN_Table table(FILE_POKEMON_TYPE);
    m_InternalName = InternalName;
    m_Name = table(InternalName, "Name");
    m_Weaknesses = string_split(table(InternalName,"Weaknesses"), ',');
    m_Resistances = string_split(table(InternalName,"Resistances"), ',');
    m_Immunities = string_split(table(InternalName,"Immunities"), ',');
    m_IsSpecialType = string_to_bool(table(InternalName,"IsSpecialType"));
}

/// ///////////////////////////////////////// ///

                /// DESTRUCTOR ///

PKMN_Type::~PKMN_Type()
{
    std::cout << m_Name <<" : Type is deleted" << std::endl;
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
//std::vector<std::string> PKMN_Type::getWeaknesses() const
//{
//    return m_Weaknesses;
//}
//
//std::vector<std::string> PKMN_Type::getImmunities() const
//{
//    return m_Immunities;
//}
//
//std::vector<std::string> PKMN_Type::getResistances() const
//{
//    return m_Resistances;
//}

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

void PKMN_Type::print() const
{
    std::cout << "PKMN_Type " << m_InternalName << std::endl;
    std::cout << "\t" << "Name = " << m_Name << std::endl;
    std::cout << "\t" << "Weaknesses = " << vector_join(m_Weaknesses) << std::endl;
    std::cout << "\t" << "Immunities = " << vector_join(m_Immunities) << std::endl;
    std::cout << "\t" << "Resistances = " << vector_join(m_Resistances) << std::endl;
    std::cout << "\t" << "IsSpecialType = " << m_IsSpecialType << std::endl;
}

/// ///////////////////////////////////////// ///

double PKMN_Type_effectiveness(PKMN_Type Type_def, PKMN_Type Type_att)
{
    return Type_def.effectiveness(Type_att);
}

double PKMN_Type_effectiveness(PKMN_Type Type_def, std::pair<PKMN_Type, PKMN_Type> Type_att)
{
    return PKMN_Type_effectiveness(Type_def, Type_att.first) * PKMN_Type_effectiveness(Type_def, Type_att.second);
}

double PKMN_Type_effectiveness(std::pair<PKMN_Type, PKMN_Type> Type_def, PKMN_Type Type_att)
{
    return PKMN_Type_effectiveness(Type_def.first, Type_att) * PKMN_Type_effectiveness(Type_def.second, Type_att);
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
