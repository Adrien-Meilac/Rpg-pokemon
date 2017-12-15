#include "Type.h"

                /// CONSTRUCTORS ///

PKMN::Type::Type()
{
    m_InternalName = "";
}

PKMN::Type::Type(std::string IntName)
{
    PKMN::Table table(FILE_PKMN_TYPE);
    m_InternalName = IntName;
    m_Name = table(IntName, "Name");
    m_Weaknesses = PKMN::string_split(table(IntName,"Weaknesses"), ',');
    m_Resistances = PKMN::string_split(table(IntName,"Resistances"), ',');
    m_Immunities = PKMN::string_split(table(IntName,"Immunities"), ',');
    m_IsSpecialType = PKMN::string_to_bool(table(IntName,"IsSpecialType"));
}

PKMN::Type::Type(PKMN::Type const& other)
{
    m_InternalName = other.m_InternalName;
    m_Name = other.m_Name;
    m_Weaknesses = other.m_Weaknesses;
    m_Immunities = other.m_Immunities;
    m_Resistances = other.m_Resistances;
    m_IsSpecialType = other.m_IsSpecialType;
}

PKMN::Type& PKMN::Type::operator=(PKMN::Type const& other)
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

                /// DESTRUCTOR ///

PKMN::Type::~Type()
{

}

/// ///////////////////////////////////////// ///

                /// GETTERS ///

std::string PKMN::Type::getName() const
{
    return m_Name;
}

std::string PKMN::Type::getInternalName() const
{
    return m_InternalName;
}

/// ///////////////////////////////////////// ///

                /// METHODS ///

double PKMN::Type::effectiveness(PKMN::Type const Type_att) const
{
    double typeMultiplicativeFactor = TYPE_NORMAL_EFFECTIVENESS;
    if(vector_in(m_Immunities, Type_att.m_InternalName))
    {
        typeMultiplicativeFactor = TYPE_INEFFECTIVE;
    }
    else if(vector_in(m_Weaknesses, Type_att.m_InternalName))
    {
        typeMultiplicativeFactor = TYPE_SUPER_EFFECTIVE;
    }
    else if(vector_in(m_Resistances, Type_att.m_InternalName))
    {
        typeMultiplicativeFactor = TYPE_NOT_VERY_EFFECTIVE;
    }

    return typeMultiplicativeFactor;
}

void PKMN::Type::print() const
{
    std::cout   << "PKMN_Type " << m_InternalName << std::endl
                << "\t" << "Name = " << m_Name << std::endl
                << "\t" << "Weaknesses = " << vector_join(m_Weaknesses) << std::endl
                << "\t" << "Immunities = " << vector_join(m_Immunities) << std::endl
                << "\t" << "Resistances = " << vector_join(m_Resistances) << std::endl
                << "\t" << "IsSpecialType = " << m_IsSpecialType << std::endl;
}

/// ///////////////////////////////////////// ///

double PKMN::Type_effectiveness(PKMN::Type Type_def,
                                PKMN::Type Type_att)
{
    return Type_def.effectiveness(Type_att);
}

double PKMN::Type_effectiveness(std::pair<PKMN::Type, PKMN::Type> Type_def,
                                PKMN::Type Type_att)
{
    return PKMN::Type_effectiveness(Type_def.first, Type_att)
            * PKMN::Type_effectiveness(Type_def.second, Type_att);
}


std::string PKMN::Type_message(double typeMultiplicativeFactor)
{
    std::string message("");
    if(typeMultiplicativeFactor == TYPE_INEFFECTIVE)
    {
        message = "It's totally ineffective !";
    }
    else if(typeMultiplicativeFactor < TYPE_NORMAL_EFFECTIVENESS)
    {
        message = "It's not very effective !";
    }
    else if(typeMultiplicativeFactor > TYPE_NORMAL_EFFECTIVENESS)
    {
        message = "It's super effective !";
    }
    return message;
}
