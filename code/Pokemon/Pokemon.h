#ifndef PKMN_POKEMON_H_INCLUDED
#define PKMN_POKEMON_H_INCLUDED

#include "Species.h"
#include "Move.h"
#include "ExpAndLevel.h"
#include "Flag.h"
#include "DamageCategory.h"

#include "../FilePath.h"

#include "../Tools/StatSet.h"
#include "../Tools/StatSetExtended.h"
#include "../Tools/Table.h"

#include "../Field/Place.h"

#include <string>
#include <vector>
#include <array>

#define NB_OF_MOVE_PER_PKMN 4

namespace PKMN
{
    class Pokemon;
}


class PKMN::Pokemon : public PKMN::Species
{
public:

    Pokemon();
    Pokemon(std::string Position);
//    Pokemon(Place place);

    ~Pokemon();

    std::string getName() const;
    unsigned int getLevel() const;

    unsigned int getNormalHP() const;
    unsigned int getNormalAtt() const;
    unsigned int getNormalDef() const;
    unsigned int getNormalSpAtt() const;
    unsigned int getNormalSpDef() const;
    unsigned int getNormalSpeed() const;

    unsigned int getCurHP() const;
    unsigned int getCurAtt() const;
    unsigned int getCurDef() const;
    unsigned int getCurSpAtt() const;
    unsigned int getCurSpDef() const;
    unsigned int getCurSpeed() const;

    std::array<std::pair<unsigned int, Move>, NB_OF_MOVE_PER_PKMN>* getListMove();
    unsigned int getPPMove(unsigned int pos);
    void decrementPPMove(unsigned int pos);
    bool hasPPMove(unsigned int pos);
    Move* getMove(unsigned int pos);
    void outBattle();
    void heal();
    bool isAlive() const;
    void decrementHP();
    void incrementHP();
    double STABmultiplicator(const Move& mv) const;

    std::string getBattleImage(bool isFoe) const;
    std::string getIcon() const;

private:

    std::string m_Pokemon_Name;
    StatSet m_Pokemon_IV;
    StatSet m_Pokemon_EV;
    StatSet m_Pokemon_NormalStat;
    StatSetExtended m_Pokemon_CurrentStat;
    std::array<std::pair<unsigned int, Move>, NB_OF_MOVE_PER_PKMN> m_Pokemon_Moves;
    ExpAndLevel m_Pokemon_ExpAndLevel;
    std::string m_Pokemon_gender;
    bool m_IsShiney;
    // Status //
};

namespace PKMN
{

bool isPkmn1attackingBeforePkmn2(const Pokemon* pkmn1, const Move* move1, const Pokemon* pkmn2, const Move* move2);

}

#endif // PKMN_POKEMON_H_INCLUDED
