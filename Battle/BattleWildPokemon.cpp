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
    m_WeatherCount = -1;
}

PKMN::BattleWildPokemon::~BattleWildPokemon()
{

}

void PKMN::BattleWildPokemon::throwNewPokemon()
{
    std::cout << "Go ! " << m_Player.getPokemon(0)->getName() << " !" << std::endl;
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
        this->weatherMessage();
        std::cout << "What will " << m_Player.getPokemon(0)->getName() << " do ?" << std::endl;
        std::cout << "FIGHT BAG POKEMON RUN" << std::endl;
        std::cin >> userCommand;
        if(userCommand == "FIGHT")
        {
            this->printPokemon(m_Player.getPokemon(0));
            this->printPokemon(&m_WildPkmn);
            this->choiceMove(m_Player.getPokemon(0));
            std::cin >> moveNumber;
            moveUsed = PKMN::Move(m_Player.getPokemon(0)->getListMove()[moveNumber].second);
            moveUsedFoe = PKMN::Move(m_WildPkmn.getListMove()[rand() % 4].second);
            if(moveUsed.getPriority() > moveUsedFoe.getPriority()
               || (moveUsed.getPriority() > moveUsedFoe.getPriority()
                        && m_Player.getPokemon(0)->getCurSpeed() >= m_WildPkmn.getCurSpeed()))
            {
                this->attack(m_Player.getPokemon(0), &m_WildPkmn, &moveUsed);
                if(!m_WildPkmn.isAlive())
                {
                    break;
                }
                else
                {
                    this->attack(&m_WildPkmn, m_Player.getPokemon(0), &moveUsedFoe);
                    if(!m_Player.getPokemon(0)->isAlive())
                    {
                        std::cout << m_Player.getPokemon(0) << " fainted !" << std::endl;
                        if(m_Player.hasPokemonAlive())
                        {
                            swapPokemonMenu();
                        }
                    }
                }
            }
            else
            {
                this->attack(&m_WildPkmn, m_Player.getPokemon(0), &moveUsedFoe);
                if(!m_Player.getPokemon(0)->isAlive())
                {
                    std::cout << m_Player.getPokemon(0)->getName() << " fainted !" << std::endl;
                    if(m_Player.hasPokemonAlive())
                    {
                        swapPokemonMenu();
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    this->attack(m_Player.getPokemon(0), &m_WildPkmn, &moveUsed);
                }
            }
        }
        else if(userCommand == "POKEMON")
        {
            swapPokemonMenu();
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
    std::cout << m_Player.getPokemon(0)->getName() << " gained " << expPoint << " EXP. Point !" << std::endl;
}

void PKMN::BattleWildPokemon::choiceMove(PKMN::Pokemon* pkmn)
{
    std::array<std::pair<unsigned int, Move>, NB_OF_MOVE_PER_PKMN> listMove = pkmn->getListMove();
    for(unsigned int i = 0; i < NB_OF_MOVE_PER_PKMN; i++)
    {
        std::cout   << listMove[i].second.getName()
                    << "(PP:" << listMove[i].first << "/"
                    << listMove[i].second.getTotalPP() << ", "
                    << "Type:" << listMove[i].second.getType().getName()
                    << ")" << std::endl;
    }
}

void PKMN::BattleWildPokemon::attack(PKMN::Pokemon* Att, PKMN::Pokemon* Def, PKMN::Move* moveUsed)
{
    std::cout << Att->getName() << " used " << moveUsed->getName() << "." << std::endl;
    std::string weatherMessage = m_Weather.startMessage(moveUsed);
    if(weatherMessage.size() > 0)
    {
        m_WeatherCount = 5;
        std::cout << weatherMessage << std::endl;
    }
    else
    {
        unsigned int lvl = Att->getLevel();
        unsigned int power = moveUsed->getBasePower();
        double damagePoint = 0;
        double typeEffect = Type_effectiveness(Def->getTypes(), moveUsed->getType());
        double CM = typeEffect;
        if(moveUsed->getType().getInternalName() == Att->getTypes().first.getInternalName()
           || moveUsed->getType().getInternalName() == Att->getTypes().second.getInternalName())///STAB
        {
            CM *= 1.5;
        }
        DamageCategory damCategory = moveUsed->getDamageCategory();
        if(damCategory.isPhysicalCategory())
        {
            damagePoint = ((lvl * 0.4 + 2) * Att->getCurAtt() * power)/(Def->getCurDef() * 50) + 2 * CM;
        }
        else if(damCategory.isSpecialCategory())
        {
            damagePoint = ((lvl * 0.4 + 2) * Att->getCurSpAtt() * power)/(Def->getCurSpDef() * 50) + 2 * CM;
        }
        std::cout << Type_message(typeEffect) << std::endl;
        unsigned int realDamage = dealDamage(Def, static_cast<unsigned int>(ceil(damagePoint)));
        std::cout << Def->getName() << " lost " << realDamage << " HP !" << std::endl;
    }
}

unsigned int PKMN::BattleWildPokemon::dealDamage(Pokemon* pkmn, unsigned int damagePoint)
{
    const unsigned int c = pkmn->getCurHP();
    for(unsigned int i = 0; i < damagePoint && pkmn->isAlive(); i++)
    {
        pkmn->decrementHP();
    }
    return std::min(damagePoint, c);
}

void PKMN::BattleWildPokemon::printPokemon(const PKMN::Pokemon* pkmn) const
{
    std::cout   << pkmn->getName()
                << " Lv." << pkmn->getLevel() << "(";
    std::cout   << "HP = " << pkmn->getCurHP() << "/"
                <<  pkmn->getNormalHP() << ")" << std::endl;

}

void PKMN::BattleWildPokemon::swapPokemonMenu(bool isNecessary)
{
    unsigned int swapNumber = 0;
    if(isNecessary)
    {
        do
        {
            for(unsigned int i=0; i < NB_OF_PKMN_PER_TRAINOR; i++)
            {
                printPokemon(m_Player.getPokemon(i));
            }
            std::cout   << "Do you want to swap "
                        << m_Player.getPokemon(0)->getName()
                        << " with another Pokemon ?" << std::endl;
            std::cin >> swapNumber;
        }while(!m_Player.getPokemon(swapNumber)->isAlive());
        m_Player.swapPokemon(swapNumber, 0);
    }
}

void PKMN::BattleWildPokemon::weatherMessage()
{
    std::string weatherMessage;
    if(m_WeatherCount > 0)
    {
        weatherMessage = m_Weather.turnMessage();
    }
    else if(m_WeatherCount == 0)
    {
        weatherMessage = m_Weather.endMessage();
        m_Weather = m_Place.getWeather();
    }
    else
    {
        weatherMessage = m_Weather.turnMessage();
    }
    if(m_WeatherCount >= 0)
    {
        m_WeatherCount -= 1;
    }
    if(weatherMessage.size() > 0)
    {
        std::cout << weatherMessage << std::endl;
    }
}
