#include "BattleWildPokemon.h"

PKMN::BattleWildPokemon::BattleWildPokemon():
    m_screen(NULL),
    m_WildPkmn(NULL),
    m_AllyPkmn(NULL)
{

}

PKMN::BattleWildPokemon::BattleWildPokemon(SDL_Surface* screen,
                                           Player& player,
                                           Place place,
                                           Pokemon* wildPkmn):
    m_screen(screen),
    m_Player(player),
    m_WildPkmn(wildPkmn),
    m_AllyPkmn(m_Player.getPokemon(0)),
    m_Place(place)

{
    m_Weather = m_Place.getWeather();
    m_WeatherCount = -1;
    m_PlayerRunAway = false;
}

PKMN::BattleWildPokemon::~BattleWildPokemon()
{

}

/// PRINT METHODS :

void PKMN::BattleWildPokemon::print(std::string message, bool isAllyAlreadyLauched, bool isFoeAlreadyLauched)
{
    if(message.size() > 0)
    {
        Battle_ScreenMessage(m_screen, m_AllyPkmn, m_WildPkmn, m_Place, message, isAllyAlreadyLauched, isFoeAlreadyLauched);
    }
}

void PKMN::BattleWildPokemon::printFadeToBlack()
{
    Battle_FadeToBlack(m_screen, m_Place);
}
void PKMN::BattleWildPokemon::printDeathAllyPokemon(bool isFoeAlreadyLauched)
{
    Battle_DeathAllyPokemon(m_screen, m_AllyPkmn, m_WildPkmn, m_Place, isFoeAlreadyLauched);
}

void PKMN::BattleWildPokemon::printDeathFoePokemon(bool isAllyAlreadyLauched)
{
    Battle_DeathFoePokemon(m_screen, m_AllyPkmn, m_WildPkmn, m_Place, isAllyAlreadyLauched);
}

int PKMN::BattleWildPokemon::printSwapMenu(bool aNewPokemonMustBeSelected)
{
    return Battle_SwapMenu(m_screen, &m_Player, aNewPokemonMustBeSelected);
}

int PKMN::BattleWildPokemon::printFightMenu()
{
    return Battle_FightMenu(m_screen, m_AllyPkmn, m_WildPkmn, m_Place);
}

std::string PKMN::BattleWildPokemon::printMainMenu()
{
    return Battle_MainMenu(m_screen, m_AllyPkmn, m_WildPkmn, m_Place);
}

void PKMN::BattleWildPokemon::printHPAllyDecrease(int damagePoint)
{
    Battle_HPAllyDecrease(m_screen, m_AllyPkmn, m_WildPkmn, m_Place, damagePoint);
}

void PKMN::BattleWildPokemon::printHPFoeDecrease(int damagePoint)
{
    Battle_HPFoeDecrease(m_screen, m_AllyPkmn, m_WildPkmn, m_Place, damagePoint);
}

void PKMN::BattleWildPokemon::printLauchAllyPokemon(bool isFoeAlreadyLauched)
{
    Battle_LauchAllyPokemon(m_screen, m_AllyPkmn, m_WildPkmn, m_Place, isFoeAlreadyLauched);
}

void PKMN::BattleWildPokemon::printLauchFoePokemon(bool isAllyAlreadyLauched)
{
    Battle_LauchFoePokemon(m_screen, m_AllyPkmn, m_WildPkmn, m_Place, isAllyAlreadyLauched);
}


/// BATTLE METHODS :

void PKMN::BattleWildPokemon::throwNewPokemon()
{
    m_AllyPkmn = m_Player.getPokemon(0);
    printLauchAllyPokemon(true);
    print("Go ! " + m_AllyPkmn->getName() + " !", true, true);
}

void PKMN::BattleWildPokemon::foePokemonDie()
{
    printDeathFoePokemon(true);
    print("The foe's " + m_WildPkmn->getName() + " fainted !",true,false);
    double a = 1;
    unsigned int b = m_WildPkmn->getBaseExp();
    unsigned int N = m_WildPkmn->getLevel();
    unsigned int expPoint = static_cast<unsigned int>(floor(a * b * N / 7));
    print(m_Player.getPokemon(0)->getName() + " gained " + PKMN::int_to_string(expPoint) + " EXP. Point !",true,false);
}

int PKMN::BattleWildPokemon::calculateRealDamage(Pokemon* pkmn, unsigned int damagePoint)
{
    if(damagePoint >= 0)
    {
        return std::min(damagePoint, pkmn->getCurHP());
    }
    return std::max(damagePoint, pkmn->getCurHP() - pkmn->getNormalHP());
}

std::string PKMN::BattleWildPokemon::weatherMessage()
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
    return weatherMessage;
}

std::pair<int, std::string> PKMN::BattleWildPokemon::calculateDamage(PKMN::Pokemon* Att, PKMN::Pokemon* Def, PKMN::Move* moveUsed)
{
    unsigned int lvl = Att->getLevel();
    unsigned int power = moveUsed->getBasePower();
    double damagePoint = 0;
    double CM = 1;
    double typeEffect = Type_effectiveness(Def->getTypes(), moveUsed->getType());
    CM *= typeEffect; /// Type Effect
    CM *= PKMN::rand_uniform(0.85, 1); /// Random Effect
    CM *= Att->STABmultiplicator(*moveUsed); /// STAB Effect
    CM *= m_Weather.weatherEffect(moveUsed->getType()); /// Weather Effect
    if(moveUsed->isPhysicalCategory())
    {
        damagePoint = ((lvl * 0.4 + 2) * Att->getCurAtt() * power)/(Def->getCurDef() * 50) + 2 * CM;
    }
    else if(moveUsed->isSpecialCategory())
    {
        damagePoint = ((lvl * 0.4 + 2) * Att->getCurSpAtt() * power)/(Def->getCurSpDef() * 50) + 2 * CM;
    }
    return std::pair<int, std::string>(calculateRealDamage(Def, static_cast<unsigned int>(floor(damagePoint))),Type_message(typeEffect));
}

bool PKMN::BattleWildPokemon::swapPokemonMenu(bool isNecessary)
{
    int swapNumber = printSwapMenu(isNecessary);
    if(swapNumber > 0)
    {
        if(m_AllyPkmn->isAlive())
        {
           print("Come back " + m_AllyPkmn->getName() + " !", true, true);
        }
        m_Player.swapPokemon(0, swapNumber);
        throwNewPokemon();
        return true;
    }
    return false;
}

void PKMN::BattleWildPokemon::foeAttack(unsigned int moveNumberFoe)
{
    PKMN::Move* moveUsedFoe(NULL);
    moveUsedFoe = m_WildPkmn->getMove(moveNumberFoe);
    std::pair<int,std::string> result = attack(m_WildPkmn, m_AllyPkmn, moveUsedFoe);
    if(result.first != 0)
    {
        printHPAllyDecrease(result.first);
        print(m_AllyPkmn->getName()  + " lost "  + PKMN::int_to_string(result.first) + " HP !", true, true);
        print(result.second,true,true);
    }
    m_WildPkmn->decrementPPMove(moveNumberFoe);
}

void PKMN::BattleWildPokemon::allyAttack(unsigned int moveNumber)
{
    PKMN::Move* moveUsed(NULL);
    moveUsed = m_AllyPkmn->getMove(moveNumber);
    std::pair<int,std::string> result = attack(m_AllyPkmn, m_WildPkmn, moveUsed);
    if(result.first != 0)
    {
        printHPFoeDecrease(result.first);
        print(m_WildPkmn->getName()  + " lost "  + PKMN::int_to_string(result.first) + " HP !", true, true);
        print(result.second,true,true);
    }
    m_AllyPkmn->decrementPPMove(moveNumber);
}

std::pair<int,std::string> PKMN::BattleWildPokemon::attack(PKMN::Pokemon* Att, PKMN::Pokemon* Def, PKMN::Move* moveUsed)
{
    print(Att->getName() + " used " + moveUsed->getName() + " !",true,true);
    std::string weatherMessage = m_Weather.startMessage(*moveUsed);
    if(weatherMessage.size() > 0)
    {
        m_WeatherCount = 5;
        print(weatherMessage,true,true);
    }
    return calculateDamage(Att, Def, moveUsed);
}

bool PKMN::BattleWildPokemon::battleCanContinue()
{
    return m_WildPkmn->isAlive() && m_Player.hasPokemonAlive() && (!m_PlayerRunAway);
}

bool PKMN::BattleWildPokemon::playerCannotContinue()
{
    return !m_Player.hasPokemonAlive();
}

bool PKMN::BattleWildPokemon::foeCannotContinue()
{
    return !m_WildPkmn->isAlive();
}

bool PKMN::BattleWildPokemon::playerCanContinue()
{
    return !playerCannotContinue();
}

bool PKMN::BattleWildPokemon::foeCanContinue()
{
    return !foeCannotContinue();
}

bool PKMN::BattleWildPokemon::allyCanContinue()
{
    return !allyCannotContinue();
}

bool PKMN::BattleWildPokemon::allyCannotContinue()
{
    return !m_AllyPkmn->isAlive();
}

void PKMN::BattleWildPokemon::allyPokemonDie()
{
    printDeathAllyPokemon(true);
    print(m_AllyPkmn->getName() + " fainted !",false,true);
    if(m_Player.hasPokemonAlive())
    {
        swapPokemonMenu(true);
    }
}

void PKMN::BattleWildPokemon::gameOver()
{
    print("GAME OVER !",false,true);
}

void PKMN::BattleWildPokemon::playerRunAway()
{
    print(m_AllyPkmn->getName()  + " run away !", true, true);
}

void PKMN::BattleWildPokemon::start()
{
    //printFadeToBlack();
    printLauchFoePokemon(false);
    print("Wild " + m_WildPkmn->getName() + " appeared !", false, true);
    this->throwNewPokemon();
    do
    {
        print(this->weatherMessage(), true, true);
        mainMenu();
    }while(battleCanContinue());
    if(playerCannotContinue())
    {
        gameOver();
    }
    else if(m_PlayerRunAway)
    {
        playerRunAway();
    }
}

bool PKMN::BattleWildPokemon::runAway()
{
    m_PlayerRunAway = true;
    return true;
}

void PKMN::BattleWildPokemon::mainMenu()
{
    std::string userCommand;
    bool hasSelectedSubOption = false;
    while(!hasSelectedSubOption)
    {
        userCommand = printMainMenu();
        if(userCommand == "FIGHT")
        {
            hasSelectedSubOption = fightMenu();
        }
        else if(userCommand == "POKEMON")
        {
            hasSelectedSubOption = swapPokemonMenu(false);
        }
        else if(userCommand == "RUN")
        {
            hasSelectedSubOption = runAway();
        }
    }
}

bool PKMN::BattleWildPokemon::fightMenu()
{
    int moveNumber = -1;
    do /// Hyp : there is a move that still has PP
    {
        moveNumber = printFightMenu();
    }while(moveNumber >= 0 && !m_AllyPkmn->hasPPMove(moveNumber));
    if(moveNumber < 0)
    {
        return false; /// No sub option selected -> come back to main menu
    }
    this->launchTurn(moveNumber);
    return true;
}

void PKMN::BattleWildPokemon::launchTurn(unsigned int moveNumber)
{
    PKMN::Move* moveUsed(NULL);
    PKMN::Move* moveUsedFoe(NULL);
    moveUsed = m_AllyPkmn->getMove(moveNumber);
    unsigned int moveNumberFoe = rand() % 4;
    moveUsedFoe = m_WildPkmn->getMove(moveNumberFoe);
    if(PKMN::isPkmn1attackingBeforePkmn2(m_AllyPkmn, moveUsed, m_WildPkmn, moveUsedFoe))
    {
        allyAttack(moveNumber);
        if(foeCanContinue())
        {
            foeAttack(moveNumberFoe);
            if(allyCannotContinue())
            {
                allyPokemonDie();
            }
        }
        else
        {
            foePokemonDie();
        }
    }
    else
    {
        foeAttack(moveNumberFoe);
        if(allyCanContinue())
        {
            allyAttack(moveNumber);
            if(foeCannotContinue())
            {
                foePokemonDie();
            }
        }
        else
        {
            allyPokemonDie();
        }
    }
}
