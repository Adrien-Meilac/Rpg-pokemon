#include "PKMN_Moves.h"

                /// CONSTRUCTORS ///

PKMN_Moves::PKMN_Moves()
{
    m_InternalName = "";
}

PKMN_Moves::PKMN_Moves(std::string InternalName)
{
    PKMN_Table table(FILE_POKEMON_MOVES);
    m_InternalName = InternalName;
    m_ID = string_to_int(table(InternalName,"IDnumber"));
    m_Name = table(InternalName,"Name");
    m_FunctionCode = table(InternalName,"FunctionCode");
    m_BasePower = string_to_int(table(InternalName,"BasePower"));
    m_Type = PKMN_Type(table(InternalName,"Type"));
    m_DamageCategory = table(InternalName,"DamageCategory");
    m_Accuracy = string_to_int(table(InternalName,"Accuracy"));
    m_TotalPP = string_to_int(table(InternalName,"TotalPP"));
    m_AdditionalEffectChance = string_to_int(table(InternalName,"AdditionalEffectChance"));
    m_Target = table(InternalName,"Target");
    m_Priority = string_to_int(table(InternalName,"Priority"));
    m_Flags = table(InternalName,"Flags");
    m_Description = table(InternalName,"Description");
}

PKMN_Moves& PKMN_Moves::operator=(PKMN_Moves const& other)
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

PKMN_Moves::~PKMN_Moves()
{
    std::cout << m_InternalName << " : PKMN_Moves deleted" << std::endl;
}

void PKMN_Moves::print() const
{
    std::cout << "PKMN_Moves " << m_InternalName << std::endl;
    std::cout << "\t" << "ID = " << m_ID << std::endl;
    std::cout << "\t" << "Name = " << m_Name << std::endl;
    std::cout << "\t" << "FunctionCode = " << m_FunctionCode << std::endl;
    std::cout << "\t" << "BasePower = " << m_BasePower << std::endl;
    std::cout << "\t" << "Type = " << m_Type.getInternalName() << std::endl;
    std::cout << "\t" << "DamageCategory = " << m_DamageCategory << std::endl;
    std::cout << "\t" << "Accuracy = " << m_Accuracy << std::endl;
    std::cout << "\t" << "TotalPP = " << m_TotalPP << std::endl;
    std::cout << "\t" << "AdditionalEffectChance = " << m_AdditionalEffectChance << std::endl;
    std::cout << "\t" << "Target = " << m_Target << std::endl;
    std::cout << "\t" << "Priority = " << m_Priority << std::endl;
    std::cout << "\t" << "Flags = " << m_Flags << std::endl;
    std::cout << "\t" << "Description = " << m_Description << std::endl << std::endl;
    std::cout << "DESCRIPTION PARAMETERS :" << std::endl;
    m_Type.print();
}

std::vector<PKMN_Moves> read_moves(std::string moves)
{
    std::vector<std::string> L = string_split(moves, ',');
    std::vector<PKMN_Moves> M;
    const unsigned int length = L.size();
    for(unsigned int i=0; i < length; i++)
    {
        M.push_back(PKMN_Moves(L[i]));
    }
    return M;
}

std::string PKMN_Moves::getDamageCategory() const
{
    return m_DamageCategory;
}

unsigned int PKMN_Moves::getBasePower() const
{
    return m_BasePower;
}

PKMN_Type PKMN_Moves::getType() const
{
    return m_Type;
}
