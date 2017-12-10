#include "PKMN_Moves.h"

                /// CONSTRUCTORS ///

PKMN_Moves::PKMN_Moves()
{

}

PKMN_Moves::PKMN_Moves(std::string InternalName)
{
    PKMN_Table table(FILE_POKEMON_MOVES);
    m_InternalName = InternalName;
    m_ID = string_to_int(table(InternalName,"IDnumber"));
    m_Name = table(InternalName,"Name");
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
    std::cout << m_InternalName << ": PKMN_Moves deleted" << std::endl;
}

void PKMN_Moves::print() const
{
    std::cout << "PKMN_Moves " << m_InternalName << std::endl;
    std::cout << "\t" << "ID = " << m_ID << std::endl;
    std::cout << "\t" << "Name = " << m_Name << std::endl;
    std::cout << "\t" << "FunctionCode = " << m_FunctionCode << std::endl;
    std::cout << "\t" << "BasePower = " << m_BasePower << std::endl;
    std::cout << "\t" << "Type = " << m_Type.getName() << std::endl;
    std::cout << "\t" << "DamageCategory = " << m_DamageCategory << std::endl;
    std::cout << "\t" << "Accuracy = " << m_Accuracy << std::endl;
    std::cout << "\t" << "TotalPP = " << m_TotalPP << std::endl;
    std::cout << "\t" << "AdditionalEffectChance = " << m_AdditionalEffectChance << std::endl;
    std::cout << "\t" << "Target = " << m_Target << std::endl;
    std::cout << "\t" << "Priority = " << m_Priority << std::endl;
    std::cout << "\t" << "Flags = " << m_Flags << std::endl;
    std::cout << "\t" << "Description = " << m_Description << std::endl;
}
