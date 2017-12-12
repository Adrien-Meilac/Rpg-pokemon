#ifndef PKMN_POKEMON_H_INCLUDED
#define PKMN_POKEMON_H_INCLUDED

#include "../PKMN_Tools/PKMN_StatSet.h"
#include "../PKMN_FilePath.h"

#include "PKMN_Species.h"
#include "PKMN_Moves.h"
#include "PKMN_ExpAndLevel.h"

class PKMN_Pokemon : public PKMN_Species
{
public:

    PKMN_Pokemon();
    PKMN_Pokemon(std::string Position);

    void outBattle();
    bool isAlive() const;
    void deathMessage() const;
    void messageGetExp(unsigned int expPoint) const;
    void lowerHP(unsigned int damagePoint);
    void printStat() const;
    unsigned int expGained(PKMN_Pokemon& PkmnDead) const;
//    PKMN_Moves chooseAnAttack() const;
    void attack(PKMN_Pokemon& Other, unsigned int i);

//    bool addOrSubstractStage(std::string statChange, int difference);
//    bool statSwap(std::string stat1, std::string stat2);
//    bool statSwap(PKMN_Pokemon other);

    ~PKMN_Pokemon();

private:

    std::string m_Pokemon_Name;
    PKMN_StatSet m_Pokemon_IV;
    PKMN_StatSet m_Pokemon_EV;
    PKMN_StatSet m_Pokemon_NormalStat;
    unsigned int m_pokemon_cur_HP;
    unsigned int m_pokemon_cur_Att;
    unsigned int m_pokemon_cur_Def;
    unsigned int m_pokemon_cur_SpAtt;
    unsigned int m_pokemon_cur_SpDef;
    unsigned int m_pokemon_cur_Speed;
    unsigned int m_pokemon_cur_Accuracy;
    unsigned int m_pokemon_cur_Evasiveness;
    std::vector<int> m_Pokemon_StageSet;
    std::vector<PKMN_Moves> m_Pokemon_Moves;
    PKMN_ExpAndLevel m_Pokemon_ExpAndLevel;
    std::string m_Pokemon_gender;
    // Status //
};


#endif // PKMN_POKEMON_H_INCLUDED
