#ifndef SPECIES_H
#define SPECIES_H

#include "RandomVector.h"
#include "StatStruct.h"
#include "LevelingRate.h"
#include <cmath>

class Species
{
public:
    Species();
    virtual ~Species();
    Species(const Species& other);
    Species(unsigned int IDpokedex, std::string speciesName,
            int baseHP, int baseAtt, int baseDef, int baseSpAtt, int baseSpDef, int baseSpeed,
            LevelingRate levelingRate); //int genderRatio
    void print() const;

private:
    unsigned int m_IDpokedex;
    std::string m_speciesName;
    StatStruct m_basicStat;
    //RandomVector m_genderRatio;
    LevelingRate m_levelingRate;
};



#endif // SPECIES_H
