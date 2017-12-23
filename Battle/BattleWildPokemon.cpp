#include "BattleWildPokemon.h"

PKMN::BattleWildPokemon::BattleWildPokemon()
{

}

PKMN::BattleWildPokemon::BattleWildPokemon(Player& player,
                                           Place place,
                                           Pokemon wildPkmn):
    m_Player(player),
    m_Place(place),
    m_WildPkmn(wildPkmn)
{
    m_Weather = m_Place.getWeather();
}

PKMN::BattleWildPokemon::~BattleWildPokemon()
{

}

void PKMN::BattleWildPokemon::throwNewPokemon(unsigned int i)
{
    m_i_ActivePkmn = i;
    m_AllyPkmn = m_Player.getPokemon(m_i_ActivePkmn);
    std::cout << "Go ! " << m_AllyPkmn.getName() << " !" << std::endl;
}


void PKMN::BattleWildPokemon::launch()
{
    std::cout << "Wild " << m_WildPkmn.getName() << " appeared !" << std::endl;
    this->throwNewPokemon(); ///Lv100
    std::string userCommand;
    unsigned int moveNumber;
    Move moveUsed, moveUsedFoe;
    while(m_WildPkmn.isAlive() && m_Player.hasPokemonAlive())
    {
        std::cout << "What will " << m_AllyPkmn.getName() << " do ?" << std::endl;
        std::cout << "FIGHT BAG POKEMON RUN" << std::endl;
        std::cin >> userCommand;
        if(userCommand == "FIGHT")
        {
            this->printPokemon(m_AllyPkmn);
            this->printPokemon(m_WildPkmn);
            this->choiceMove();
            std::cin >> moveNumber;
            moveUsed = Move(m_AllyPkmn.getListMove()[moveNumber].second);
            moveUsedFoe = Move(m_WildPkmn.getListMove()[rand() % 4].second);
            if(moveUsed.getPriority() > moveUsedFoe.getPriority()
               || (moveUsed.getPriority() > moveUsedFoe.getPriority()
                        && m_AllyPkmn.getCurSpeed() >= m_WildPkmn.getCurSpeed()))
            {
                this->attack(m_AllyPkmn, m_WildPkmn, moveUsed);
                this->attack(m_WildPkmn, m_AllyPkmn, moveUsedFoe);
            }
            else
            {
                this->attack(m_WildPkmn, m_AllyPkmn, moveUsedFoe);
                this->attack(m_AllyPkmn, m_WildPkmn, moveUsed);
            }
        }
    }
    if(!m_WildPkmn.isAlive())
    {
        this->foeIsDead();
    }
    else
    {
        std::cout << "GAME OVER ... ! ";
    }
}

void PKMN::BattleWildPokemon::foeIsDead()
{
    std::cout << "The foe's " << m_WildPkmn.getName() << " fainted !" << std::endl;
    double a = 1;
    unsigned int b = m_WildPkmn.getBaseExp();
    unsigned int N = m_WildPkmn.getLevel();
    unsigned int expPoint = static_cast<unsigned int>(floor(a * b * N / 7));
    std::cout << m_AllyPkmn.getName() << " gained " << expPoint << " EXP. Point !" << std::endl;
}

void PKMN::BattleWildPokemon::choiceMove()
{
    std::vector<std::pair<unsigned int, Move> > listMove = m_AllyPkmn.getListMove();
    const unsigned int length = listMove.size();
    for(unsigned int i = 0; i < length; i++)
    {
        std::cout   << listMove[i].second.getName()
                    << "(PP:" << listMove[i].first << "/"
                    << listMove[i].second.getTotalPP() << ", "
                    << "Type:" << listMove[i].second.getType().getName()
                    << ")" << std::endl;
    }
}

void PKMN::BattleWildPokemon::attack(PKMN::Pokemon &Att, PKMN::Pokemon &Def, PKMN::Move &moveUsed)
{
    std::cout << Att.getName() << " used " << moveUsed.getName() << "." << std::endl;
    unsigned int lvl = Att.getLevel();
    unsigned int power = moveUsed.getBasePower();
    double damagePoint = 0;
    double typeEffect = Type_effectiveness(Def.getTypes(), moveUsed.getType());
    double CM = typeEffect;
    DamageCategory damCategory = moveUsed.getDamageCategory();
    if(damCategory.isPhysicalCategory())
    {
        damagePoint = ((lvl * 0.4 + 2) * Att.getCurAtt() * power)/(Def.getCurDef() * 50) + 2 * CM;
    }
    else if(damCategory.isSpecialCategory())
    {
        damagePoint = ((lvl * 0.4 + 2) * Att.getCurSpAtt() * power)/(Def.getCurSpDef() * 50) + 2 * CM;
    }
    std::cout << Type_message(typeEffect);
    unsigned int realDamage = dealDamage(Def, static_cast<unsigned int>(ceil(damagePoint)));
    std::cout << Def.getName() << " lost " << realDamage << " HP !" << std::endl;
}

unsigned int PKMN::BattleWildPokemon::dealDamage(Pokemon &pkmn, unsigned int damagePoint)
{
    const unsigned int c = pkmn.getCurHP();
    for(unsigned int i = 0; i < damagePoint && pkmn.isAlive(); i++)
    {
        pkmn.decrementHP();
    }
    return std::min(damagePoint, c);
}

void PKMN::BattleWildPokemon::printPokemon(const PKMN::Pokemon &pkmn) const
{
    std::cout << "Pokemon " << pkmn.getName() << " Lv." << pkmn.getLevel() << "(";
    std::cout << "HP = " << pkmn.getCurHP() << "/" <<  pkmn.getNormalHP() << ")" << std::endl;

}
