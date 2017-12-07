#include "PKMN_Moves.h"

                /// CONSTRUCTORS ///

PKMN_Moves::PKMN_Moves():
    m_InternalName(),
    m_ID(),
    m_DisplayName(),
    m_FunctionCode(), // Hexadecimal number
    m_BasePower(),
    m_Type(),
    m_DamageCategory(),
    m_Accuracy(),
    m_TotalPP(),
    m_AdditionalEffectChance(),
    m_Target(),
    m_Priority(),
    m_Flags(),
    m_Description()
{

}

PKMN_Moves::PKMN_Moves(std::string InternalName)
{
    PKMN_Table table(PATH_TO_MOVES_FILE);
    m_InternalName = InternalName;
    m_ID = string_to_int(table(InternalName,"IDnumber"));
    m_DisplayName = table(InternalName,"DisplayName");
    m_FunctionCode  =  table(InternalName,"FunctionCode");
    m_BasePower  = string_to_int(table(InternalName,"BasePower"));
    m_Type = PKMN_Type(table(InternalName,"Type"));
    m_DamageCategory  = table(InternalName,"DamageCategory");
    m_Accuracy  = string_to_int(table(InternalName,"Accuracy"));
    m_TotalPP = string_to_int(table(InternalName,"TotalPP"));
    m_AdditionalEffectChance = string_to_int(table(InternalName,"AdditionalEffectChance"));
    m_Target = table(InternalName,"Target");
    m_Priority = string_to_int(table(InternalName,"Priority"));
    m_Flags = table(InternalName,"Flags");
    m_Description = table(InternalName,"Description");
}

/// ///////////////////////////////////////// ///

                /// DESTRUCTOR ///

PKMN_Moves::~PKMN_Moves()
{
    delete &m_ID;
    delete &m_DisplayName;
    delete &m_FunctionCode; // Hexadecimal number
    delete &m_BasePower;
    delete &m_Type;
    delete &m_DamageCategory;
    delete &m_Accuracy;
    delete &m_TotalPP;
    delete &m_AdditionalEffectChance;
    delete &m_Target;
    delete &m_Priority;
    delete &m_Flags;
    delete &m_Description;
}

//void PKMN_Moves::print() const
//{
//    std::cout << m_ID << std::endl;
//    std::cout << m_DisplayName << std::endl;
//    std::cout << m_FunctionCode << std::endl;
//    std::cout << m_BasePower << std::endl;
//    std::cout << typeName(m_Type) << std::endl;
//    std::cout << m_DamageCategory << std::endl;
//    std::cout << m_Accuracy << std::endl;
//    std::cout << m_TotalPP << std::endl;
//    std::cout << m_AdditionalEffectChance << std::endl;
//    std::cout << m_Target << std::endl;
//    std::cout << m_Priority << std::endl;
//    std::cout << m_Flags << std::endl;
//    std::cout << m_Description << std::endl;
//}
