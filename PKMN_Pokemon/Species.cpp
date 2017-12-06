#include "Species.h"
#include "StatStruct.h"
#include "LevelingRate.h"

Species::Species()
{
}

Species::Species(unsigned int IDpokedex, std::string speciesName,
                 int baseHP, int baseAtt, int baseDef, int baseSpAtt, int baseSpDef, int baseSpeed,
                 LevelingRate levelingRate) //int genderRatio
{
    m_IDpokedex = IDpokedex;
    m_speciesName = speciesName;
    m_basicStat(baseHP, baseAtt, baseDef, baseSpAtt, baseSpDef, baseSpeed);
//    std::vector<std::string> gender;
//    gender.push_back("Male");
//    gender.push_back("Female");
//    std::vector<int> P;
//    P.push_back(genderRatio);
//    P.push_back(100 - genderRatio);
//    RandomVector m_genderRatio(gender, P);
    LevelingRate m_levelingRate = levelingRate;
}

Species::~Species()
{
    delete &m_IDpokedex;
    delete &m_speciesName;
    delete &m_basicStat;
    //delete &m_genderRatio;
    delete &m_levelingRate;
}

Species::Species(const Species& other)
{
    m_IDpokedex = other.m_IDpokedex;
    m_speciesName = other.m_speciesName;
    m_basicStat= other.m_basicStat;
    //m_genderRatio = other.m_genderRatio;
    m_levelingRate = other.m_levelingRate;
}

void Species::print() const
{
    std::cout << "pokemon n" << m_IDpokedex << " : " << m_speciesName;
    void afficher(StatStruct);
}



