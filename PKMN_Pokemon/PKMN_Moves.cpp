#include "PKMN_Moves.h"

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

PKMN_Moves::PKMN_Moves(std::string InternalName,
                        unsigned int ID,
                        std::string DisplayName,
                        std::string FunctionCode, // Hexadecimal number
                        unsigned int BasePower,
                        std::string Type_InternalName,
                        std::string DamageCategory,
                        unsigned int Accuracy,
                        unsigned int TotalPP,
                        unsigned int AdditionalEffectChance,
                        std::string Target,
                        int Priority,
                        std::string Flags,
                        std::string Description):
    m_InternalName(InternalName),
    m_ID(ID),
    m_DisplayName(DisplayName),
    m_FunctionCode(FunctionCode), // Hexadecimal number
    m_BasePower(BasePower),
    m_Type(Type_InternalName),
    m_DamageCategory(DamageCategory),
    m_Accuracy(Accuracy),
    m_TotalPP(TotalPP),
    m_AdditionalEffectChance(AdditionalEffectChance),
    m_Target(Target),
    m_Priority(Priority),
    m_Flags(Flags),
    m_Description(Description)
{

}

PKMN_Moves::PKMN_Moves(std::string InternalName)
{
    PKMN_Table table(PATH_TO_MOVES_FILE);
    std::vector<std::string> Line = table.getLineValues(InternalName);
    vector_print(Line);
    std::cout << std::endl;
    unsigned int ID = string_to_int(Line[0]);
    std::string DisplayName = Line[1];
    std::string Description = Line[2];
    unsigned int TotalPP = string_to_int(Line[3]);
    unsigned int BasePower = string_to_int(Line[4]);
    int Priority = string_to_int(Line[5]);
    std::string DamageCategory = Line[6];
    std::string FunctionCode = Line[7];
    std::string Flags = Line[8];
    unsigned int Accuracy = string_to_int(Line[9]);
    std::string Type_InternalName = Line[10];
    unsigned int AdditionalEffectChance = string_to_int(Line[11]);
    std::string Target = Line[12];
    m_InternalName = InternalName;
    m_ID = ID;
    m_DisplayName = DisplayName;
    m_FunctionCode  =  FunctionCode;
    m_BasePower  = BasePower;
    m_Type = PKMN_Type(Type_InternalName);
    m_DamageCategory  = DamageCategory;
    m_Accuracy  = Accuracy;
    m_TotalPP = TotalPP;
    m_AdditionalEffectChance = AdditionalEffectChance;
    m_Target = Target;
    m_Priority = Priority;
    m_Flags = Flags;
    m_Description = Description;
}


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
