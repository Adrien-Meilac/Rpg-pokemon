#ifndef STATSET_H
#define STATSET_H

#include <cmath>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

class PKMN_StatSet
{
public:

    PKMN_StatSet();
    PKMN_StatSet(int HP, int Att, int Def, int SpAtt, int SpDef, int Speed);
    PKMN_StatSet(double HP, double Att, double Def, double SpAtt, double SpDef, double Speed);
    PKMN_StatSet(PKMN_StatSet const& Other);
    virtual ~PKMN_StatSet();

    int getHP() const;
    int getAtt() const;
    int getDef() const;
    int getSpAtt() const;
    int getSpDef() const;
    int getSpeed() const;

private:

    friend std::ostream& operator<<(std::ostream &flux, PKMN_StatSet const& Stat);
    friend PKMN_StatSet NormalStatistics(PKMN_StatSet const& Base,
                              PKMN_StatSet const& IV,
                              PKMN_StatSet const& EV,
                              unsigned int level,
                              std::string Nature);

    double m_HP;
    double m_Att;
    double m_Def;
    double m_SpAtt;
    double m_SpDef;
    double m_Speed;

};


#endif // STATSET_H
