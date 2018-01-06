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
        /** \brief Get the name of a pokemon
         *
         * \return std::string
         *
         */

    unsigned int getLevel() const;
        /** \brief get the level of a pokemon
         *
         * \return unsigned int
         *
         */

    unsigned int getNormalHP() const;
        /** \brief return Normal HP
         *
         * \return unsigned int
         *
         */

    unsigned int getNormalAtt() const;
        /** \brief return Normal Attack
         *
         * \return unsigned int
         *
         */

    unsigned int getNormalDef() const;
        /** \brief return Normal Defense
         *
         * \return unsigned int
         *
         */

    unsigned int getNormalSpAtt() const;
        /** \brief return Normal Att Special
         *
         * \return unsigned int
         *
         */

    unsigned int getNormalSpDef() const;
        /** \brief return Normal Spe Def
         *
         * \return unsigned int
         *
         */

    unsigned int getNormalSpeed() const;
        /** \brief return Normal Speed
         *
         * \return unsigned int
         *
         */

    unsigned int getCurHP() const;
        /** \brief return Current HP
         *
         * \return unsigned int
         *
         */

    unsigned int getCurAtt() const;
        /** \brief return Current Att
         *
         * \return unsigned int
         *
         */

    unsigned int getCurDef() const;
        /** \brief return Current Def
         *
         * \return unsigned int
         *
         */

    unsigned int getCurSpAtt() const;
        /** \brief return Current Sp Att
         *
         * \return unsigned int
         *
         */
    unsigned int getCurSpDef() const;
        /** \brief return Current Sp Def
         *
         * \return unsigned int
         *
         */

    unsigned int getCurSpeed() const;
        /** \brief return Current Speed
         *
         * \return unsigned int
         *
         */

    std::array<std::pair<unsigned int, Move>, NB_OF_MOVE_PER_PKMN>* getListMove();
        /** \brief return a list of the pokemon Move
         *
         * \return std::array<std::pair<unsigned int, Move>, NB_OF_MOVE_PER_PKMN>*
         *
         */

    unsigned int getPPMove(unsigned int pos);
        /** \brief return a move PP
         *
         * \param pos of the move
         * \return unsigned int
         *
         */

    void decrementPPMove(unsigned int pos);
        /** \brief decrease a Move from 1 PP
         *
         * \param pos of the move
         * \return void
         *
         */

    bool hasPPMove(unsigned int pos);
        /** \brief has a given Move PP left ?
         *
         * \param pos of the move
         * \return unsigned int
         *
         */

    Move* getMove(unsigned int pos);
        /** \brief return a Move given it position
         *
         * \param pos of the move
         * \return unsigned int
         *
         */

    void outBattle();
    void heal();

    bool isAlive() const;
        /** \brief Is a pokemon alive
         *
         * \return bool
         *
         */

    void decrementHP();
        /** \brief Substract 1 HP
         *
         * \return void
         *
         */

    void incrementHP();
        /** \brief Add 1 HP
         *
         * \return void
         *
         */

    double STABmultiplicator(const Move& mv) const;
        /** \brief Calculate the STAB effect of a move
         *
         * \return double : multiplicator value
         *
         */

    std::string getBattleImage(bool isFoe) const;
        /** \brief Get the battler image for the battle mode
         *
         * \return std::string path to image
         *
         */

    std::string getIcon() const;
        /** \brief Get the pokemon image for the swap menu
         *
         * \return std::string path to image
         *
         */

private:

    std::string m_Pokemon_Name; /// Name of a pokemon
    StatSet m_Pokemon_IV; /// IV value of a pokemon (for each Stat, between 0 and 31)
    StatSet m_Pokemon_EV; /// EV are given by battle (for each Stat, between 0 and 255)
    StatSet m_Pokemon_NormalStat; /// Stat when the pokemon is OK
    StatSetExtended m_Pokemon_CurrentStat; /// Current stat of the pokemon
    std::array<std::pair<unsigned int, Move>, NB_OF_MOVE_PER_PKMN> m_Pokemon_Moves; /// List  of move
    ExpAndLevel m_Pokemon_ExpAndLevel; /// Experience of the pokemon and Level
    std::string m_Pokemon_gender; /// Gender of the pokemon
    bool m_IsShiney; /// Is the pokemon Shiney ?
};

namespace PKMN
{

bool isPkmn1attackingBeforePkmn2(const Pokemon* pkmn1, const Move* move1, const Pokemon* pkmn2, const Move* move2);
    /** \brief Is the pokemon 1 attacking before the pokemon 2 ?
     *
     * \param pkmn1 const Pokemon*
     * \param move1 const Move*
     * \param pkmn2 const Pokemon*
     * \param move2 const Move*
     * \return bool
     *
     */
}

#endif // PKMN_POKEMON_H_INCLUDED
