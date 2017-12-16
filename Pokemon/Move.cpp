#include "Move.h"

                /// CONSTRUCTORS ///

PKMN::Move::Move()
{
    m_InternalName = "";
}

PKMN::Move::Move(std::string InternalName)
{
    PKMN::Table table(FILE_PKMN_MOVES);
    m_InternalName = InternalName;
    m_ID = PKMN::string_to_int(table(InternalName,"IDnumber"));
    m_Name = table(InternalName,"Name");
    m_FunctionCode = table(InternalName,"FunctionCode");
    m_BasePower = PKMN::string_to_int(table(InternalName,"BasePower"));
    m_Type = PKMN::Type(table(InternalName,"Type"));
    m_DamageCategory = table(InternalName,"DamageCategory");
    m_Accuracy = PKMN::string_to_int(table(InternalName,"Accuracy"));
    m_TotalPP = PKMN::string_to_int(table(InternalName,"TotalPP"));
    m_AdditionalEffectChance = PKMN::string_to_int(table(InternalName,"AdditionalEffectChance"));
    m_Target = table(InternalName,"Target");
    m_Priority = PKMN::string_to_int(table(InternalName,"Priority"));
    m_Flags = table(InternalName,"Flags");
    m_Description = table(InternalName,"Description");
}


PKMN::Move::Move(PKMN::Move const& other):
    m_Type(other.m_Type),
    m_DamageCategory(other.m_DamageCategory)
{
    m_InternalName = other.m_InternalName;
    m_ID = other.m_ID;
    m_Name = other.m_Name;
    m_FunctionCode = other.m_FunctionCode;
    m_BasePower = other.m_BasePower;
    //m_Type = other.m_Type;
    //m_DamageCategory = other.m_DamageCategory;
    m_Accuracy = other.m_Accuracy;
    m_TotalPP = other.m_TotalPP;
    m_AdditionalEffectChance = other.m_AdditionalEffectChance;
    m_Target = other.m_Target;
    m_Priority = other.m_Priority;
    m_Flags = other.m_Flags;
    m_Description = other.m_Description;
}


PKMN::Move& PKMN::Move::operator=(PKMN::Move const& other)
{
    m_InternalName = other.m_InternalName;
    m_ID = other.m_ID;
    m_Name = other.m_Name;
    m_FunctionCode = other.m_FunctionCode;
    m_BasePower = other.m_BasePower;
    m_Type = other.m_Type;
    m_DamageCategory = other.m_DamageCategory;
    m_Accuracy = other.m_Accuracy;
    m_TotalPP = other.m_TotalPP;
    m_AdditionalEffectChance = other.m_AdditionalEffectChance;
    m_Target = other.m_Target;
    m_Priority = other.m_Priority;
    m_Flags = other.m_Flags;
    m_Description = other.m_Description;
    return *this;
}

/// ///////////////////////////////////////// ///

                /// DESTRUCTOR ///

PKMN::Move::~Move()
{

}

/// ///////////////////////////////////////// ///

                /// GETTERS ///

std::string PKMN::Move::getInternalName() const
{
    return m_InternalName;
}


bool PKMN::Move::isPhysicalCategory() const
{
    return m_DamageCategory.isPhysicalCategory();
}

bool PKMN::Move::isStatusCategory() const
{
    return m_DamageCategory.isStatusCategory();
}

bool PKMN::Move::isSpecialCategory() const
{
    return m_DamageCategory.isSpecialCategory();
}

unsigned int PKMN::Move::getBasePower() const
{
    return m_BasePower;
}

PKMN::Type PKMN::Move::getType() const
{
    return m_Type;
}

std::string PKMN::Move::getName() const
{
    return m_Name;
}

/// ///////////////////////////////////////// ///

                /// METHODS ///
void PKMN::Move::print() const
{
    std::cout   << "Move "  << m_InternalName   << std::endl
                << "\t" << "ID = " << m_ID << std::endl
                << "\t" << "Name = " << m_Name << std::endl
                << "\t" << "FunctionCode = " << m_FunctionCode << std::endl
                << "\t" << "BasePower = " << m_BasePower << std::endl
                << "\t" << "Type = " << m_Type.getInternalName() << std::endl
                << "\t" << "DamageCategory = " << m_DamageCategory.getName() << std::endl
                << "\t" << "Accuracy = " << m_Accuracy << std::endl
                << "\t" << "TotalPP = " << m_TotalPP << std::endl
                << "\t" << "AdditionalEffectChance = " << m_AdditionalEffectChance << std::endl
                << "\t" << "Target = " << m_Target << std::endl
                << "\t" << "Priority = " << m_Priority << std::endl
                << "\t" << "Flags = " << m_Flags << std::endl
                << "\t" << "Description = " << m_Description << std::endl << std::endl
                << "DESCRIPTION PARAMETERS :" << std::endl;
    m_Type.print();
}

/// ///////////////////////////////////////// ///

                /// OTHERS ///

namespace PKMN
{
std::vector<Move> read_move(std::string moves)
{
    std::vector<std::string> L = PKMN::string_split(moves, ',');
    std::vector<Move> M;
    const unsigned int length = L.size();
    for(unsigned int i=0; i < length; i++)
    {
        M.push_back(Move(L[i]));
    }
    return M;
}
}
