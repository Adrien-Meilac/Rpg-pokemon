#ifndef PKMN_MOVES_H_INCLUDED
#define PKMN_MOVES_H_INCLUDED


#include "PKMN_Type.h"
#include "../PKMN_Tools/PKMN_Table.h"
#include "../PKMN_FilePath.h"
#include <iostream>
#include <string>

#define PKMN_DAMAGE_CATEGORY_PHYSICAL "Physical"
#define PKMN_DAMAGE_CATEGORY_SPECIAL "Special"
#define PKMN_DAMAGE_CATEGORY_STATUS "Status"


class PKMN_Moves
{
public:

    PKMN_Moves();
    PKMN_Moves(std::string InternalName);

    std::string getDamageCategory() const;
    unsigned int getBasePower() const;
    PKMN_Type getType() const;

    PKMN_Moves& operator=(PKMN_Moves const& other);

    ~PKMN_Moves();
    void print() const;

private:

    std::string m_InternalName;
    unsigned int m_ID;
    std::string m_Name;
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

std::vector<PKMN_Moves> read_moves(std::string moves);

#endif // PKMN_MOVES_H_INCLUDED
