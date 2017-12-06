#ifndef PKMN_MOVES_H_INCLUDED
#define PKMN_MOVES_H_INCLUDED

#include "PKMN_Type.h"
#include <iostream>
#include <string>

#define PATH_TO_MOVES_FILE "./PKMN_Data/Moves.txt"

class PKMN_Moves
{
public:

    PKMN_Moves();
    PKMN_Moves(std::string InternalName);

    PKMN_Moves(std::string InternalName,
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
                std::string Description);
    virtual ~PKMN_Moves();
    //void print() const;

private:

    std::string m_InternalName;
    unsigned int m_ID;
    std::string m_DisplayName;
    std::string m_FunctionCode; // Hexadecimal number
    unsigned int m_BasePower;
    PKMN_Type m_Type;
    std::string m_DamageCategory;
    unsigned int m_Accuracy;
    unsigned int m_TotalPP;
    unsigned int m_AdditionalEffectChance;
    std::string m_Target;
    int m_Priority;
    std::string m_Flags;
    std::string m_Description;

};

#endif // PKMN_MOVES_H_INCLUDED
